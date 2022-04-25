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
     NUM = 258,
     true = 259,
     false = 260,
     id = 261,
     T_PLUS = 262,
     T_MOD = 263,
     T_DIV = 264,
     T_SUB = 265,
     T_MUL = 266,
     int_const = 267,
     char_const = 268,
     float_const = 269,
     string = 270,
     type_const = 271,
     access_specifier = 272,
     WHILE = 273,
     DO = 274,
     IF = 275,
     T_ELSE = 276,
     ELSEIF = 277,
     BREAK = 278,
     CLASS = 279,
     CONTINUE = 280,
     RETURN = 281,
     STATIC = 282,
     MAIN = 283,
     PRINT = 284,
     EXTENDS = 285,
     or_const = 286,
     and_const = 287,
     eq_const = 288,
     rel_const = 289,
     point_const = 290,
     param_const = 291,
     ELSE = 292,
     HEADER = 293
   };
#endif
/* Tokens.  */
#define NUM 258
#define true 259
#define false 260
#define id 261
#define T_PLUS 262
#define T_MOD 263
#define T_DIV 264
#define T_SUB 265
#define T_MUL 266
#define int_const 267
#define char_const 268
#define float_const 269
#define string 270
#define type_const 271
#define access_specifier 272
#define WHILE 273
#define DO 274
#define IF 275
#define T_ELSE 276
#define ELSEIF 277
#define BREAK 278
#define CLASS 279
#define CONTINUE 280
#define RETURN 281
#define STATIC 282
#define MAIN 283
#define PRINT 284
#define EXTENDS 285
#define or_const 286
#define and_const 287
#define eq_const 288
#define rel_const 289
#define point_const 290
#define param_const 291
#define ELSE 292
#define HEADER 293




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 63 "project.y"
{
	int ival;
	char st[256];
	
	
}
/* Line 1529 of yacc.c.  */
#line 132 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

