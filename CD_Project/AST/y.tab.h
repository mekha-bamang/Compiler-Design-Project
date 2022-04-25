/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     FLOAT_NUM = 259,
     STATIC = 260,
     MAIN = 261,
     CLASS = 262,
     access_specifier = 263,
     type_const = 264,
     ID = 265,
     string = 266,
     TRUE = 267,
     FALSE = 268,
     DO = 269,
     WHILE = 270,
     IF = 271,
     PRINT = 272,
     FOR = 273,
     INT = 274,
     FLOAT = 275,
     CHAR = 276,
     BOOLEAN = 277,
     IFX = 278,
     ELSE = 279,
     AND = 280,
     OR = 281,
     NE = 282,
     EQ = 283,
     LE = 284,
     GE = 285,
     DEC = 286,
     INC = 287,
     UMINUS = 288
   };
#endif
/* Tokens.  */
#define INTEGER 258
#define FLOAT_NUM 259
#define STATIC 260
#define MAIN 261
#define CLASS 262
#define access_specifier 263
#define type_const 264
#define ID 265
#define string 266
#define TRUE 267
#define FALSE 268
#define DO 269
#define WHILE 270
#define IF 271
#define PRINT 272
#define FOR 273
#define INT 274
#define FLOAT 275
#define CHAR 276
#define BOOLEAN 277
#define IFX 278
#define ELSE 279
#define AND 280
#define OR 281
#define NE 282
#define EQ 283
#define LE 284
#define GE 285
#define DEC 286
#define INC 287
#define UMINUS 288




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 21 "ast.y"
{
	int iValue; /* integer value */
	float fValue; /* float value */
	char strIndex[2024]; /* string */
	char sIndex[2024]; /* symbol table index */
	char bIndex[2024]; /* boolean */
	nodeType *nPtr; /* node pointer */
}
/* Line 1529 of yacc.c.  */
#line 124 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

