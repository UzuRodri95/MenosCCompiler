/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_ASIN_H_INCLUDED
# define YY_YY_ASIN_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    WHILE_ = 258,
    FOR_ = 259,
    IF_ = 260,
    ELSE_ = 261,
    TRUE_ = 262,
    FALSE_ = 263,
    PRINT_ = 264,
    READ_ = 265,
    RETURN_ = 266,
    ALLAVE_ = 267,
    CLLAVE_ = 268,
    ACORCH_ = 269,
    CCORCH_ = 270,
    APAREN_ = 271,
    CPAREN_ = 272,
    PTOCOMA_ = 273,
    PTO_ = 274,
    CMA_ = 275,
    MAS_ = 276,
    MENOS_ = 277,
    POR_ = 278,
    DIV_ = 279,
    AND_ = 280,
    OR_ = 281,
    SUMASIG_ = 282,
    RESASIG_ = 283,
    MULASIG_ = 284,
    DIVASIG_ = 285,
    IGU_ = 286,
    NOIGU_ = 287,
    MAYIGU_ = 288,
    MENIGU_ = 289,
    INC_ = 290,
    DEC_ = 291,
    MAY_ = 292,
    MEN_ = 293,
    ASIG_ = 294,
    NOT_ = 295,
    MOD_ = 296,
    INT_ = 297,
    BOOL_ = 298,
    CTE_ = 299,
    ID_ = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "src/asin.y"

    char *ident; //NOMBRE DEL IDENTIFICADOR
    int cent;    //VALOR DE LA CTE NUMERICA ENTERA
    EXP exp;     //PARA LAS EXPRESIONES
    STR str;     //PARA LOS ELEMENTOS CON TALLA
    MAT mat;     //PARA CONSTANTE

#line 111 "asin.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASIN_H_INCLUDED  */
