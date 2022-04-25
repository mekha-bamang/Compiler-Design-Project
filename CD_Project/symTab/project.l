%option yylineno

%{
	#include<stdio.h>
	#include<string.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include"y.tab.h"
	#include<math.h>
	#include"symtab.h" 
	extern int tcnt;
	extern int bal_brack;
	//extern int open_brack;
	extern void push(char s[2024]);
	extern int ptemp;
	extern int temp;
	extern int ttemp;
	extern char st[100][10];
	extern int top;
	extern int tcount;
	char data[100];
	char prev[2]={'{','\0'};
	char new_var[100];
	int ifPresent(char* sym){
  		int i;
		//printf("sym = %s\n",sym);
  		for(i = 1; i < tcnt ; i ++)
   		{
			if(!strcmp(symtab[i].type,"Identifier"))
      				{
					if(!strcmp(sym,symtab[i].symbol) && symtab[i].scope_num == bal_brack)
        				return 1;
				}
			
				
    		}
		return 0;
	}
	
	void initEntry(char* sym)
	{

		if(!ifPresent(sym)){
			symtab[tcnt].tok_num = tcnt;
			symtab[tcnt].scope_num = bal_brack;
			strcpy(symtab[tcnt].symbol,sym);
			symtab[tcnt].lineno = yylineno;
			
			
		
		}
	}
	
	void s_update(char val[2024],char var[2024],int scope)
	{
		int i,j;
		

		int flag = 1;
		char tempo[2024];
		//printf("\n\nvariable:%s\tvalue:%s\tscope:%d\n\n",var,val,scope);
		for(i = 1; i < tcnt ; i ++)
   			{
			if(!strcmp(symtab[i].symbol,var) )
      			{
      				strcpy(tempo,symtab[i].cvalue);
      				if(scope==symtab[i].scope_num)
      				{
					if(!isalpha(symtab[i].cvalue[0]))
						{strcpy(symtab[i].cvalue,val);
							flag=0;
						break;
					}
					}

				}
			
				
    		}
    		if(flag==1)
    		{
    			strcpy(symtab[i].cvalue,tempo);
    		}
    	
	}
	int extract_value(char var[2024],int scope)
	{
		int i;char tempo[2024];
		strcpy(tempo,"0");
		
		for(i = 1; i < tcnt ; i ++)
   			{
			if(!strcmp(symtab[i].symbol,var))
      			{	
      				if(strcmp(symtab[i].cvalue,"")==0)
      					{//printf("\n%s\n",tempo);
      					break;
      				}
      				strcpy(tempo,symtab[i].cvalue);
      				

      			}
      		}
      	
      	return atoi(tempo);
	}

%}

%%


"void"|"char"|"int"|"long"|"float"|"double"|"signed"|"unsigned"|"String"|"boolean"							   {
														    tcnt++;
														    ECHO;
														    strcpy(data,yytext);
														    return type_const;
														}

"public"|"private"|"protected"							   {	
														    tcnt++;
														    ECHO;return access_specifier;}						

"class"														   {
														    tcnt++;
														    ECHO;return CLASS;}

"System.out.println"														   {
														    tcnt++;
														    ECHO;return PRINT;}														    

"extends"														   {
														    tcnt++;
														    ECHO;return EXTENDS;}														    
"static"													   {
														    tcnt++;
														    ECHO;return STATIC;}
"main"													    {
														    tcnt++;
														    ECHO;return MAIN;}
"while"														  {
														    
														    tcnt++;
														    ECHO;return WHILE;}
"do"														  {
														    
														    tcnt++;
														    ECHO;return DO;}
"if"														  {
														    
														    tcnt++;
														    ECHO;return IF;}

"else"														  {
														    
														    tcnt++;
														    ECHO;return T_ELSE;}

"elseif"														  {
														    
														    tcnt++;
														    ECHO;return ELSEIF;}

"continue"													{
														  
														    tcnt++;
														    ECHO;return CONTINUE;}
"break"														{
														 
														    tcnt++;
														    ECHO;return BREAK;}
"return"													{
														    
														    tcnt++;
														    ECHO;return RETURN;}

"true"														  {
												    strcpy(yylval.st,"true");
														    tcnt++;
	if(ttemp==1){
		push(yytext);
ttemp=0;
}																    ECHO;return true;}

"false"														  {
														    strcpy(yylval.st,"false");
														    tcnt++;
														    ECHO;return false;}

"||" 													      { 
														    
														    tcnt++;
														    ECHO;return or_const;}
"&&"														{
														    
														    tcnt++;
														    ECHO;return and_const;}
"=="|"!="													 {
														    
														    tcnt++;
														    ECHO;return eq_const;}
"<="|">="|"<"|">"													{
														   
														    tcnt++;
														    ECHO;return rel_const;}


";"|"="|","|"{"|"}"|"("|")"|"["|"]"|":"						{   
														    tcnt++;
														    if(strcmp(yytext,"{")==0){
															bal_brack++;
															//if(strcmp(prev,"}")==0)
															//bal_brack = temp;
															strcpy(prev,yytext);
														    }
														    else if(strcmp(yytext,"}")==0){
															if(strcmp(prev,"{")==0)
																temp = bal_brack+1;	
															strcpy(prev,yytext);
														    }
														   		
														    ECHO;return yytext[0];}
"+"															{tcnt++;strcpy(yylval.st,yytext);
														    
if(ptemp!=1)
{
		
	push(yytext);
	ptemp=0;
	tcount++;
	
	//printf(" \n text:%s\n",st[top]);
	
}


ECHO;return T_PLUS;}

"-"															{tcnt++;strcpy(yylval.st,yytext);
if(ptemp!=1)
{
	push(yytext);
	ptemp=0;
	tcount++;
}

														    ECHO;return T_SUB;}

"*"															{tcnt++;strcpy(yylval.st,yytext);
if(ptemp!=1)
{
	push(yytext);
	ptemp=0;
}

														    ECHO;return T_MUL;}

"/"															{tcnt++;strcpy(yylval.st,yytext);
if(ptemp==1)
{
	push(yytext);
	ptemp=0;
}

														    ECHO;return T_DIV;}

"%"															{tcnt++;strcpy(yylval.st,yytext);
if(ptemp==1)
{
	push(yytext);
	ptemp=0;
}

														    ECHO;return T_MOD;}
		

"*="|"+="|"-="|"/="			   					   		   		  {
														    
														    tcnt++;
														    ECHO;return yytext[0];}	
"&"|"|"|"!"												         {
														    
														    tcnt++;
														    ECHO;return yytext[0];}

[0-9]+														{
														    yylval.ival=atoi(yytext);
														    tcnt++;
														    ECHO;return NUM;}
[0-9]+"."[0-9]+													{
														 
														    tcnt++;
														    ECHO;return float_const;}
"'"."'"														 {
														    
														    tcnt++;
														    ECHO;return char_const;}
[a-zA-Z_][a-zA-Z_0-9]*			 									{initEntry(yytext);
																strcpy(symtab[tcnt].type,"Identifier");
																int c_flag=0;
																for(int i = 0; i < tcnt; i ++)
																{
																	if(strcmp(symtab[i].symbol,yytext)==0)
																	{
																		if(strcmp(symtab[i].datatype,"-")==0)
																		{
																			strcpy(symtab[tcnt].datatype,data);
																			c_flag=1;
																			break;	
																		}
																		else
																		{
																		strcpy(symtab[tcnt].datatype,symtab[i].datatype);
																		c_flag=1;
																		break;
																		}
																	}	
																}
																if(c_flag==0){
																	strcpy(symtab[tcnt].datatype,data);
																}
																strcpy(data,"-");
														  /* printf("ID = %s\n",yytext);*/
														    strcpy(yylval.st,yytext);tcnt++;
														    strcpy(new_var,yytext);
														    ECHO;return id;}
\"(\\.|[^\"])*\"												   {ECHO;return string;}
"//"(\\.|[^\n])*[\n]												   ;
[/][*]([^*]|[*]*[^*/])*[*]+[/]                                                                                     ;
[ \t\n]														   {ECHO;}
%%

int yywrap(void)
{
    return 1;
}



