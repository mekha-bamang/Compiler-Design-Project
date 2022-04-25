%expect 3
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include<string.h>
	#include <stdarg.h>
	#include "header.h"
	/* prototypes */
	nodeType *opr(int oper, int nops, ...);
	nodeType *id(char i[2024]);
	nodeType *bool(char i[2024]);
	nodeType *flt(float value);
	nodeType *str(char i[2024]);
	nodeType *con(int value);
	void freeNode(nodeType *p);
	int ex(nodeType *p);
	int yylex(void);
	void yyerror(char *s);
	int sym[26]; /* symbol table */
%}
%union {
	int iValue; /* integer value */
	float fValue; /* float value */
	char strIndex[2024]; /* string */
	char sIndex[2024]; /* symbol table index */
	char bIndex[2024]; /* boolean */
	nodeType *nPtr; /* node pointer */
};
%token <iValue> INTEGER 
%token <fValue> FLOAT_NUM
%token STATIC MAIN CLASS access_specifier type_const 
%token <sIndex> ID 
%token <strIndex> string
%token <bIndex> TRUE FALSE 
%token DO WHILE IF PRINT FOR INT FLOAT CHAR BOOLEAN 
%nonassoc IFX
%nonassoc ELSE
%left GE LE EQ NE '>' '<' OR AND
%left '+' '-'
%left '*' '/'
%left '%'
%nonassoc UMINUS INC DEC
%type <nPtr> stmt stmt_list type_const ASSIGNEXPR DECL IF_CONDITION E 
%type <nPtr> COND T F VARLIST RELEXP EXPR LOGEXP PRNT_STAT

%%


program					: initial CLASS ID '{' BODY '}' {exit(0);}
						| error CLASS {yyerrok;}
						;
initial					: access_specifier
					|
					;

BODY					: access_specifier STATIC type_const MAIN '(' type_const '[' ']' ID ')' '{' stmt_list '}' { ex($12); freeNode($12); }
							;


stmt					: E ';' { $$ = $1; }
							| ASSIGNEXPR
							| DECL 
							| PRINT '(' PRNT_STAT ')' ';' {$$ = opr(PRINT, 1, $3);}
							| IF_CONDITION
							| WHILE '(' COND ')' '{' stmt '}' { $$ = opr(WHILE, 2, $3, $6); }
							| DO '{' stmt '}' WHILE '(' COND ')' ';'  { $$ = opr(DO,2,$3,$7); } 
							| ';' { $$ = opr(';', 2, NULL, NULL); }

							;
stmt_list				: stmt { $$ = $1; }
					| stmt_list stmt { $$ = opr(';', 2, $1, $2); }
				
					;

PRNT_STAT			: string {$$ = str($1);}
					| string '+' PRNT_STAT {$$ = opr('+', 2, str($1), $3);}
					| ID {$$ = id($1);}
					| ID '+' PRNT_STAT {$$ = opr('+', 2, id($1), $3);}
					;

IF_CONDITION 		: IF '(' COND ')' '{' stmt '}' %prec IFX { $$ = opr(IF, 2, $3, $6); }
					| IF '(' COND ')' '{' stmt '}' ELSE '{' stmt '}' { $$ = opr(IF, 3, $3, $6, $10); }


COND								: EXPR 
									| TRUE { $$ = bool($1); }
									| FALSE {$$ = bool($1);}
									| EXPR OR EXPR { $$ = opr(OR, 2, $1, $3); }
									| EXPR AND EXPR { $$ = opr(AND, 2, $1, $3); }
									
									;

EXPR								: RELEXP
									| LOGEXP
									;

RELEXP								: E '<' E { $$ = opr('<', 2, $1, $3); }
								| E '>' E { $$ = opr('>', 2, $1, $3); }
								| E GE E { $$ = opr(GE, 2, $1, $3); }
								| E LE E { $$ = opr(LE, 2, $1, $3); }
								| E EQ E { $$ = opr(EQ, 2, $1, $3); }
								| E NE E { $$ = opr(NE, 2, $1, $3); }
									;

LOGEXP								: E OR E { $$ = opr(OR, 2, $1, $3); }
									| E AND E { $$ = opr(AND, 2, $1, $3); }
									;



DECL								:INT VARLIST ';'{$$ = opr(INT, 1,$2);}
									| CHAR VARLIST ';'{$$ = opr(CHAR, 1,$2);}
									| FLOAT VARLIST ';'{$$ = opr(FLOAT, 1,$2);}
									| BOOLEAN VARLIST ';'{$$ = opr(BOOLEAN, 1,$2);}
 									| INT ASSIGNEXPR {$$ = opr(INT, 1,$2);}
 									| CHAR ASSIGNEXPR {$$ = opr(CHAR, 1,$2);}
 									| FLOAT ASSIGNEXPR {$$ = opr(FLOAT, 1,$2);}
 									| BOOLEAN ASSIGNEXPR {$$ = opr(BOOLEAN, 1,$2);}
									;


VARLIST								: VARLIST ',' ID {$$ = id($3);}
									| ID {$$ = id($1);}
									;

ASSIGNEXPR							: ID '=' E ',' ASSIGNEXPR { $$ = opr('=', 2, id($1), $3); }
									| ID '=' E ';' { $$ = opr('=', 2, id($1), $3); }
									;

E									: E '+' T { $$ = opr('+', 2, $1, $3); }
									| E '-' T { $$ = opr('-', 2, $1, $3); }
									| T  
									;

T									: T '*' F { $$ = opr('*', 2, $1, $3); }
									| T '/' F { $$ = opr('/', 2, $1, $3); }
									| T '%' F { $$ = opr('%', 2, $1, $3); }
									| F  

									;

F									: ID { $$ = id($1); }
									| string {$$ = str($1);printf("\n %s \n",$1);}
									| INTEGER { $$ = con($1); }
									| FLOAT_NUM { $$ = flt($1); }
									| TRUE { $$ = bool($1); }
									| FALSE { $$ = bool($1); }
									| '(' E ')' { $$ = $2; }
									| '-' E %prec UMINUS { $$ = opr(UMINUS, 1, $2); }
									;

%%
#define SIZEOF_NODETYPE ((char *)&p->con - (char *)p)
//constant
nodeType *con(int value) {
	nodeType *p;
	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
	yyerror("out of memory");
	/* copy information */
	p->type = typeCon;
	p->con.value = value;
	return p;
}
nodeType *flt(float value) {
	nodeType *p;
	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
	yyerror("out of memory");
	/* copy information */
	p->type = typeFlt;
	p->flt.value = value;
	return p;
}
nodeType *id(char i[2024]) {
	nodeType *p;
	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
	yyerror("out of memory");
	/* copy information */
	p->type = typeId;
	strcpy(p->id.i,i);
	return p;
}
nodeType *bool(char i[2024]) {
	nodeType *p;
	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
	yyerror("out of memory");
	/* copy information */
	p->type = typeBool;
	strcpy(p->bool.val, i);
	return p;
}
nodeType *str(char i[2024]) {
	nodeType *p;
	/* allocate node */
	if ((p = malloc(sizeof(nodeType))) == NULL)
	yyerror("out of memory");
	/* copy information */
	p->type = typeString;
	strcpy(p->str.val, i);
	return p;
}
nodeType *opr(int oper, int nops, ...) {
	va_list ap;
	nodeType *p;
	int i;
	/* allocate node, extending op array */
	if ((p = malloc(sizeof(nodeType) +
	(nops-1) * sizeof(nodeType *))) == NULL)
	yyerror("out of memory");
	/* copy information */
	p->type = typeOpr;
	p->opr.oper = oper;
	p->opr.nops = nops;
	va_start(ap, nops);
	for (i = 0; i < nops; i++)
	p->opr.op[i] = va_arg(ap, nodeType*);
	va_end(ap);
	return p;
}
void freeNode(nodeType *p) {
	int i;
	if (!p) return;
	if (p->type == typeOpr) {
	for (i = 0; i < p->opr.nops; i++)
	freeNode(p->opr.op[i]);
	}
	free (p);
}
void yyerror(char *s) {
	fprintf(stdout, "%s\n", s);
}
int main(void) {
	yyparse();
	return 0;
}
