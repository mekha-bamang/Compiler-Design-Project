import re

labels=[] #Storing labels
list_register=[] #List of Register assigned along with the variables
condition=" "
def register(operand,flag_print): #Checks if a register is assigned to a variable ,if not a register is assigned
	used_registers=[] 
	for i in list_register:
		used_registers.append(i[0])
	for i in list_register:  #If variable assigned to register, then it is pushed to the end of list 
		if(i[1]==operand):
			list_register.remove(i)
			list_register.append(i)
			return i[0]
	if(len(list_register)==8): #IF All registers are occupied
		reg=list_register[0][0]
		list_register.pop(0) 
		list_register.append([reg,operand]) #LRU
		if(flag_print):
			if(re.search("^[0-9]+$", operand) or operand=="true" or operand=="false"): #if operand is numeric then MOV
				print("\tMOV r"+str(reg)+" , #"+str(operand))
			else:
				print("\tLDR r"+str(reg)+" , "+str(operand)) #LDR for variables
		return reg
	else:
		for i in range(8):  #Assigning a register to a variable ,it assigns the lowest unused register
			if(i not in used_registers):
				list_register.append([i,operand])
				if(flag_print):
					if(re.search("^[0-9]+$", operand) or operand=="true" or operand=="false"): #if operand is numeric then MOV
						print("\tMOV r"+str(i)+" , #"+str(operand))
					else:
						print("\tLDR r"+str(i)+" , "+str(operand)) 
				return i
	

def begin(line): 
	line=line.split(" ")
	#print(line)

	if(len(line)==1): #labels
		if(line[0] not in labels):
			labels.append(line[0])
			print(line[0])
		global list_register
		list_register=[]  #Register gets flushed when labels are encountered
		return

	if(len(line)==3): #Assignment Operation
		# global list_register
		if(re.search("^[0-9]+$", line[2]) or line[2]=="true" or line[2]=="false" ): #checking if the right operand is number
			var2=register(line[2],1) #0 is sent to the function to not print temporary variables present in icg 
			print("\tSTR r"+str(var2)+" , "+str(line[0]))
			for i in list_register: #Assigning register to variable by replacing the value stored in list 
				if(i[0]==var2):
					i[1]=line[0]
					break
		else:  		#If right operand is variable
			var2=register(line[2],1) #assigning register for right operand
			register(line[0],0)      #assigning register for left operand
			if(re.search("^t[0-9]+", line[2])): #For temporary variable
				for i in list_register:
					if(i[1]==line[0]):
						i[0]=var2     #Updating the register value of left operand
				for i in list_register:
					if(i[1]==line[2]):
						list_register.remove(i)  #Deallocating register for a temporary variable
			print("\tSTR r"+str(var2)+" , "+str(line[0]))
		return

	if(len(line)==5):
		# global list_register
		if(line[3] in ["+","-","/","*"]): #Arithmetic Operations
			var_temp=str(register(line[0],0))
			if(re.search("^[0-9]+$", line[2]) ): #To check if operand is numeric
				first_operand="#"+line[2]
			else:
				first_operand="r"+str(register(line[2],1))
			if(re.search("^[0-9]+$", line[4]) ): #To check if operand is numeric
				second_operand="#"+line[4]
			else:
				second_operand="r"+str(register(line[4],1))
			if(line[3]=="+"):
				print("\tADD r"+var_temp+" , "+first_operand+" , "+second_operand)
			elif(line[3]=="-"):
				print("\tSUB r"+var_temp+" , "+first_operand+" , "+second_operand)
			elif(line[3]=="/"): 
				print("\tDIV r"+var_temp+" , "+first_operand+" , "+second_operand)
			else:
				print("\tMUL r"+var_temp+" , "+first_operand+" , "+second_operand)
		else:  #Conditional Operations
			global condition
			condition=line[3]
			if(re.search("^[0-9]+$", line[2]) ):
				first_operand=line[2]
			else:
				first_operand="r"+str(register(line[2],1))
			if(re.search("^[0-9]+$", line[4]) ):
				second_operand=line[4]
			else:
				second_operand="r"+str(register(line[4],1))
			print("\tCMP "+first_operand+" "+second_operand)
		return

	if(len(line)==4 and "goto" in line): #Branching for false conditions
		#global condition
		if(condition == "=="):
			print("\tBNE "+line[3])
		elif(condition == "!="):
			print("\tBE "+line[3])
		elif(condition == ">="):
			print("\tBLT "+line[3])
		elif(condition == "<="):
			print("\tBGT "+line[3])
		elif(condition == ">"):
			print("\tBLE "+line[3])
		else:
			print("\tBGE "+line[3])
		return

	if(len(line)==2 and "goto" in line): #Branching for true conditions
		print("\tB "+line[1])
		return

	

file = open("icg.txt", "r")
for line in file: #Reading the optimized code file
	line = line.rstrip("\n")
	begin(line.strip())
file.close()
 