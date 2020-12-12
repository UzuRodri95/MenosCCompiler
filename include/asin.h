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
    PRINT_ = 262,
    READ_ = 263,
    RETURN_ = 264,
    ALLAVE_ = 265,
    CLLAVE_ = 266,
    ACORCH_ = 267,
    CCORCH_ = 268,
    APAREN_ = 269,
    CPAREN_ = 270,
    PTOCOMA_ = 271,
    PTO_ = 272,
    CMA_ = 273,
    MAS_ = 274,
    MENOS_ = 275,
    POR_ = 276,
    DIV_ = 277,
    AND_ = 278,
    OR_ = 279,
    SUMASIG_ = 280,
    RESASIG_ = 281,
    MULASIG_ = 282,
    DIVASIG_ = 283,
    IGU_ = 284,
    NOIGU_ = 285,
    MAYIGU_ = 286,
    MENIGU_ = 287,
    INC_ = 288,
    DEC_ = 289,
    MAY_ = 290,
    MEN_ = 291,
    ASIG_ = 292,
    NOT_ = 293,
    MOD_ = 294,
    INT_ = 295,
    BOOL_ = 296,
    CTE_ = 297,
    TRUE_ = 298,
    FALSE_ = 299,
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
