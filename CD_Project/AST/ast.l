%{
	#include <stdlib.h>
	#include "header.h"
	#include "y.tab.h"
	#include<string.h>
	void yyerror(char *);
%}
%%
"int"											return INT;
"float"											return FLOAT;
"char"											return CHAR;
"boolean"										return BOOLEAN;

0 						{
						yylval.iValue = atoi(yytext);
						return INTEGER;
						}
[1-9][0-9]* 						{
						yylval.iValue = atoi(yytext);
						return INTEGER;
						}
[0-9]+"."[0-9]+			{yylval.fValue = strtof(yytext,NULL);
						return FLOAT_NUM;
						}


[-()<>=+*%/;,{}.] 			return *yytext;
"["|"]"						return yytext[0];

	
"||"						return OR;
"&&"						return AND;					
"++"						return INC;
"--"						return DEC;
">=" 						return GE;
"<=" 						return LE;
"==" 						return EQ;
"!=" 						return NE;
"true"						{strcpy(yylval.bIndex ,yytext) ; return TRUE;}
"false"						{strcpy(yylval.bIndex ,yytext) ; return FALSE;}
"while" 					return WHILE;
"do"						return DO;
"for"						return FOR;
"if" 						return IF;
"else" 						return ELSE;
"System.out.println" 		return PRINT;
[ \t\n]+					; /* ignore whitespace */
"static"					return STATIC;
"public"|"private"|"protected"				return access_specifier;
"class"						return CLASS;
"main"						return MAIN;
"void"|"char"|"int"|"long"|"float"|"double"|"signed"|"unsigned"|"String"|"boolean"	return type_const;
							
										    			
[a-zA-Z_][a-zA-Z_0-9]*				{
									strcpy(yylval.sIndex ,yytext) ;
									return ID;
								}
"//"(\\.|[^\n])*[\n]				;		/*ignoring comments */										   ;
[/][*]([^*]|[*]*[^*/])*[*]+[/]		;

\"(\\.|[^\"])*\"				{strcpy(yylval.strIndex,yytext ); 
								return string;}
%%
int yywrap(void) {
return 1;
}
