%{
	#include<stdio.h>
	#include <stdlib.h>
	#include<ctype.h>
	#include<string.h>
	#include "symtab.h"
	int yylex(void);
	extern char *yytext;
	extern int yylineno;
	extern void s_update(char val[2024],char var[2024],int scope);
	int yyerror(const char *s);
	int success = 1;
	int tcnt = 1;
	int flag=0;
	extern char data[100];
	int bal_brack = 0;
	int ltop=0;
	//int temp = 0;
	int close_brack = 0;
	int f;
	int lnum=1;
	int start=1;
	char st[100][10];
	int top=0;
	int tnum=0;
	char temp[10]="t";
	void push(char s[2024]);
	int ptemp=0;
	int ttemp=0;
	int tcount=0;
	int wcount=0;
	int lcount=0;
	void codegen();
	void lab1();
	void lab2();
	void lab3();
	void lab1_if();
	void lab2_if();
	void lab3_if();
	int lnum_if=0;
	int label[20];
	FILE* F1;
	FILE* f2;
	void codegen_assign();
	int error_count;
	char var[100];
	extern char new_var[100];
	int var7;
	extern int extract_value(char var[2024],int scope);
	#define type_name(expr) \
    (_Generic((expr), \
              char: "char", unsigned char: "unsigned char", signed char: "signed char", \
              short: "short", unsigned short: "unsigned short", \
              int: "int", unsigned int: "unsigned int", \
              long: "long", unsigned long: "unsigned long", \
              long long: "long long", unsigned long long: "unsigned long long", \
              float: "float", \
              double: "double", \
              long double: "long double", \
              void*: "void*", \
              default: "?"))
%}
%union {
	int ival;
	char st[256];
	
	
}; 
%token <ival> NUM 
%token <st> true false id T_PLUS T_MOD T_DIV T_SUB T_MUL 
%token int_const char_const float_const string type_const access_specifier
%token WHILE DO IF T_ELSE ELSEIF BREAK CLASS CONTINUE RETURN STATIC MAIN PRINT EXTENDS   or_const and_const eq_const rel_const   
%token point_const param_const ELSE HEADER
%left T_PLUS T_SUB
%left T_DIV T_MUL T_MOD
%define "parse.error" "verbose"
%start program_unit 
%type <ival> E T 
%type <st>  F 

%%
program_unit			: CLASS id '{' BODY  '}'  {YYACCEPT;};	
					| access_specifier CLASS id '{' BODY   '}' {YYACCEPT;}
					| error CLASS {yyerrok;}
					;

BODY					: access_specifier STATIC type_const MAIN '(' type_const '[' ']' id ')' '{' STMT '}'
						|  error MAIN {yyerrok;}
						
							;


STMT					: E ';' {strcpy(data,"-");} STMT 
							| ASSIGNEXPR STMT
							| DECL STMT
							| JUMP_STMT STMT
							| PRNT STMT 
							| IF_CONDITION STMT
							| LOOP STMT
							| DO_WHILE STMT
							| ';' {strcpy(data,"null");} STMT 
							| error STMT {yyerrok;}
							|
							;

PRNT					: PRINT '('PRNT_STAT {ptemp=1;} ')' ';'

PRNT_STAT				: string 
					| string T_PLUS PRNT_STAT
					| id 
					| id T_PLUS PRNT_STAT
					|
					;


LOOP					: WHILE { wcount=1;lab1();} '(' COND { codegen(); tnum++;  } ')'{lab2(); 							lcount=1;}  '{' STMT  '}'{lab3();}
						;


DO_WHILE				: DO  {lab1();}'{' STMT  '}' WHILE '(' COND {codegen(); tnum++; lab2();} ')' ';'{lab3();} ;
						

IF_CONDITION 				: IF '(' COND { codegen();tnum++; lab1_if();  } ')' '{' STMT {lab2_if(); }'}' ELSE_ELIF;
ELIF					: ELSEIF '(' COND ')' '{' STMT {lab2_if(); }'}' ELSE_ELIF ;
IF_ELSE					: T_ELSE '{' STMT {lab3_if();}'}' ;

ELSE_ELIF				: ELIF 
						| IF_ELSE
						| ;



COND								: EXPR 
									| EXPR LOGOP EXPR_E
									| true {flag=1; ttemp=1; push($1);}
									| false {flag=1; push($1);}
									| error ';' {yyerrok;}
									;

EXPR_E  							: E
									| EXPR
									;

JUMP_STMT							: CONTINUE ';'
									| BREAK ';'
									| RETURN E ';'
									;

EXPR								: RELEXP

									| LOGEXP

									;

RELEXP								: E  rel_const {push(yytext); } E 
									| E eq_const {push(yytext);}  E 
									;

LOGEXP								: E LOGOP E
									;

LOGOP								: or_const
									| and_const
									;


DECL								: TYPE VARLIST ';' {strcpy(data,"-");}
 									| TYPE ASSIGNEXPR 
									;

TYPE								: type_const 
									
									;

VARLIST								: VARLIST ',' id 
									| id
									;

ASSIGNEXPR							: id '=' E ',' ASSIGNEXPR  {if(wcount==1){push($1);char y[100]; 									char str[10];strcpy(y,"t");sprintf(str, "%d", tnum);
									strcat(y,str);push("=");push (y); codegen_assign(); }
									else {char y[100];char str[10];strcpy(y,"t");
									sprintf(str, "%d", tnum);strcat(y,str);
									push($1);push("="); char x[2024]; 
									snprintf (x, sizeof(2024), "%d",$3); push(y);codegen_assign();}if(type_name($3)=="int"){char x[2024];
									snprintf (x, sizeof(2024), "%d",$3);s_update(x,$1,bal_brack);} }
									| id '='  E ';' {tcount=0;if(wcount==1){ push($1);char y[100];char str[10];strcpy(y,"t");sprintf(str, "%d", tnum);strcat(y,str);push("=");push(y);codegen_assign(); }else {char y[100];char str[10]; strcpy(y,"t");sprintf(str, "%d", tnum);strcat(y,str);push($1);push("="); char x[2024]; 
									snprintf (x, sizeof(2024), "%d",$3); push(y);codegen_assign();} if(type_name($3)=="int"){char x[2024];snprintf (x, sizeof(2024), "%d",$3);s_update(x,$1,bal_brack);} }
									;

E									: E T_PLUS T { 
										codegen();	
									  $$=($1)+($3); }
									| E T_SUB T { codegen(); $$=$1-$3;} 
									| T {$$=$1;} 
									;

T									: T T_MUL F { codegen(); $$=$1*atoi($3);}
									| T T_DIV F { codegen();  if (atoi($3)!=0){$$ = $1/atoi($3);} else {printf("Error: divide by Zero");}}
									| T T_MOD F { codegen(); if (atoi($3)!=0){$$ = $1%atoi($3);} else {printf("Error: Divided by Zero");}}
									| F {$$=atoi($1);} 

									;

F									: id { push($1); 
										int t=extract_value($1,bal_brack);
										char j[2024];
										snprintf(j, sizeof(2024), "%d",t);strcpy($$,j);s_update(j,$1,bal_brack);}
									| NUM { char j[2024];
											snprintf(j, sizeof(2024), "%d",$1);strcpy($$,j); push(j);}

									| true {push($1);strcpy($$,$1);s_update($1,new_var,bal_brack);} 
									| false {push($1);strcpy($$,$1);s_update($1,new_var,bal_brack);}
									| '(' E ')' {char j[2024];
										snprintf(j, sizeof(2024), "%d",$2);strcpy($$,j);}
									
									;




%%

void push(char s[2024])
{
	strcpy(st[++top],s);
}

void codegen()
 {	
	 char str[10];
	 strcpy(temp,"t");
	 sprintf(str, "%d", tnum);
	 strcat(temp,str);
	 if(flag==1)  
	 {
	 fprintf(F1,"%s = %s \n",temp,st[top]);
	 tcount=0;
	 strcpy(st[top],temp);
	 flag=0;
	 }
	else if(tcount>1)
	{
	 fprintf(F1,"%s = %s %s %s\n",temp,st[top-3],st[top-2],st[top-1]);
	 tcount--;
	 top-=2;
	 strcpy(st[top-1],temp);
	 tnum++;
	}
	else
	{
	 fprintf(F1,"%s = %s %s %s\n",temp,st[top-2],st[top-1],st[top]);
	 top-=2;
	 strcpy(st[top],temp);
	
	}
	
	
		

	 //top-=2;
	 //strcpy(st[top],temp);
	 
	  //printf(" \n plus:%s\n",st[top-1]);
	
	 //push(temp);
	 //printf("%d",i_[0]);
 }
void codegen_assign()
 {	
	
	 fprintf(F1,"%s = %s\n",st[top-2],st[top-3]);
	 top-=2;
	 tnum++;	
	 
	
	
	 
 }
void lab1()
{	
	start=lnum;
	fprintf(F1,"L%d: \n",lnum);
	lnum++;
	
}

void lab2()
{	
	 char str[10];
	 strcpy(temp,"t");
	 sprintf(str, "%d", tnum);
	 strcat(temp,str);
	 fprintf(F1,"%s = not %s\n",temp,st[top]);
	 fprintf(F1,"if %s goto L%d\n",temp,lnum);
	 tnum++;
 }

void lab3()
{
	
	fprintf(F1,"goto L%d \n",start);
	fprintf(F1,"L%d: \n",lnum);
}
void lab1_if()
{

	 //lnum_if++;
	 char str[10];
	 strcpy(temp,"t");
	 sprintf(str, "%d", tnum);
	 strcat(temp,str);
	 fprintf(F1,"%s = not %s\n",temp,st[top]);
	 if(lnum==1)
	 fprintf(F1,"if %s goto L%d\n",temp,lnum++);
	 else
	 fprintf(F1,"if %s goto L%d\n",temp,++lnum);
	 tnum++;
	 label[++ltop]=lnum;
}

void lab2_if()
{
	int x;
	//lnum_if++;
	x=label[ltop--];
	if(lnum!=2)
	{
	lnum++;
	fprintf(F1,"goto L%d\n",lnum);
	fprintf(F1,"L%d: \n",x);
	}
	else
	{
	fprintf(F1,"goto L%d\n",lnum++);
	fprintf(F1,"L%d: \n",--x);
	}
	label[++ltop]=lnum;
	
}

void lab3_if()
{
	int y;
	y=label[ltop--];
	if(lnum==3)
	fprintf(F1,"L%d: \n",--y);
	else
	fprintf(F1,"L%d: \n",y);
}



int main()
{
    F1= fopen("icg.txt","w");
    printf("\nAfter Removal of Multi-line and Single-line  Comments:");
    printf("\n--------------------------------------------------------------------------------------------------------\n");
    yyparse();
    FILE *ftpr= fopen("sample.txt","w");
    
    printf("\n--------------------------------------------------------------------------------------------------------\n");
    if(success)
    	printf("\n\t\t\t\t\tParsing Successful!\n\n");
    else
    	{
    	if(error_count==1)
    	printf("\n\t\t\t\t\t%d Error Generated!\n\n",error_count);
    	else
    	printf("\n\t\t\t\t\t%d Errors Generated!\n\n",error_count);
    	}
			int i = 0;
		printf("--------------------------------------------------------------------------------------------------------\n");

		printf("Semantic Errors: \n");
		int count=0;
		for(i = 0; i < tcnt; i ++)
		{
			if(symtab[i].tok_num != 0)
				{
				//printf("datatype:%s value:%s\n",symtab[i].datatype,symtab[i].cvalue);
				if(strcmp(symtab[i].datatype,"int")==0)
				{
					if(symtab[i].cvalue[0]=='\0')
					{
					//printf("null chararcter\n");
					}
					else
					for (int j =0;j<strlen(symtab[i].cvalue);j++)
					{
					//printf("%c\n",)
						if(isalpha(symtab[i].cvalue[j]))
						{
						printf("invalid datatype %s for variable %s\n",symtab[i].datatype,symtab[i].symbol);
						count++;
						break;
						}
					}
				}
				if(strcmp(symtab[i].datatype,"boolean")==0)
				{
				if(strcmp(symtab[i].cvalue,"true")!=0 && strcmp(symtab[i].cvalue,"false")!=0)
				{
				printf("invalid datatype %s for variable %s\n",symtab[i].datatype,symtab[i].symbol);
				count++;
				}
				}
				
			}
				
		}
		for(i = 0; i < tcnt; i ++)
		{
			if(strcmp(symtab[i].datatype,"-")==0)
			{
			printf("undeclared variable : %s\n",symtab[i].symbol);
			count++;
			}		
		}	
		if(count==0)
		{
		printf("0 semantic errors\n");
		}

		printf("--------------------------------------------------------------------------------------------------------;\n");

		printf("\n\t\t\t\t\tSYMBOL TABLE\n\n");
		printf("--------------------------------------------------------------------------------------------------------;\n");
		printf("  Scope_Num\t|\tDatatype\t|\tSymbol\t\t|\tLine Number\t|\tValue\t|\n");
		int c=0;
		printf("--------------------------------------------------------------------------------------------------------|\n");
		for(i = 0; i < tcnt; i ++)
		{
			if(symtab[i].tok_num != 0)
				{
				if(symtab[i].scope_num==0 || symtab[i].scope_num==1)
				{
				continue;
				}
			
					printf("%5d\t\t|\t%5s\t\t|\t%4s\t\t|\t%5d\t\t|\t%4s\t|\n",symtab[i].scope_num,symtab[i].datatype,symtab[i].symbol,symtab[i].lineno,symtab[i].cvalue);
			}
				
		}
		

		printf("--------------------------------------------------------------------------------------------------------;\n");
		printf("\nTotal number of tokens : %d\n",tcnt);
		printf("\n--------------------------------------------------------------------------------------------------------\n");

    return 0;
}

int yyerror(const char *msg)
{
	extern int yylineno;
	printf("Parsing Failed\nLine Number: %d %s\n",yylineno,msg);
	success = 0;
	error_count++;
	return 0;
}
