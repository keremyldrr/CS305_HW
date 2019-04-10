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
     tOPEN = 258,
     tCOURSE = 259,
     tCLOSE = 260,
     tEND = 261,
     tCODE = 262,
     tCLASS = 263,
     tNAME = 264,
     tTYPE = 265,
     tSTRING = 266,
     tSECTION = 267,
     tINSTRUCTOR = 268,
     tCRN = 269,
     tCAPACITY = 270,
     tMEETING = 271,
     tSELF = 272,
     tDAY = 273,
     tSTART = 274,
     tTIME = 275,
     tEND_A = 276,
     tMON = 277,
     tTUE = 278,
     tWED = 279,
     tTHU = 280,
     tFRI = 281,
     tCONSTRAINT = 282,
     tITEM = 283,
     tNUM = 284
   };
#endif
/* Tokens.  */
#define tOPEN 258
#define tCOURSE 259
#define tCLOSE 260
#define tEND 261
#define tCODE 262
#define tCLASS 263
#define tNAME 264
#define tTYPE 265
#define tSTRING 266
#define tSECTION 267
#define tINSTRUCTOR 268
#define tCRN 269
#define tCAPACITY 270
#define tMEETING 271
#define tSELF 272
#define tDAY 273
#define tSTART 274
#define tTIME 275
#define tEND_A 276
#define tMON 277
#define tTUE 278
#define tWED 279
#define tTHU 280
#define tFRI 281
#define tCONSTRAINT 282
#define tITEM 283
#define tNUM 284




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 16 "hw4.y"
{

  int crn;//buralar degiscek
  TreeNode *treeptr;
  Attribute *attr;
}
/* Line 1529 of yacc.c.  */
#line 114 "hw4.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

