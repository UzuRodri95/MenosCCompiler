/* A Bison parser, made by GNU Bison 3.7.2.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_ASIN_H_INCLUDED
# define YY_YY_ASIN_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    WHILE_ = 258,                  /* WHILE_  */
    FOR_ = 259,                    /* FOR_  */
    IF_ = 260,                     /* IF_  */
    ELSE_ = 261,                   /* ELSE_  */
    TRUE_ = 262,                   /* TRUE_  */
    FALSE_ = 263,                  /* FALSE_  */
    PRINT_ = 264,                  /* PRINT_  */
    READ_ = 265,                   /* READ_  */
    RETURN_ = 266,                 /* RETURN_  */
    ALLAVE_ = 267,                 /* ALLAVE_  */
    CLLAVE_ = 268,                 /* CLLAVE_  */
    ACORCH_ = 269,                 /* ACORCH_  */
    CCORCH_ = 270,                 /* CCORCH_  */
    APAREN_ = 271,                 /* APAREN_  */
    CPAREN_ = 272,                 /* CPAREN_  */
    PTOCOMA_ = 273,                /* PTOCOMA_  */
    PTO_ = 274,                    /* PTO_  */
    CMA_ = 275,                    /* CMA_  */
    MAS_ = 276,                    /* MAS_  */
    MENOS_ = 277,                  /* MENOS_  */
    POR_ = 278,                    /* POR_  */
    DIV_ = 279,                    /* DIV_  */
    AND_ = 280,                    /* AND_  */
    OR_ = 281,                     /* OR_  */
    SUMASIG_ = 282,                /* SUMASIG_  */
    RESASIG_ = 283,                /* RESASIG_  */
    MULASIG_ = 284,                /* MULASIG_  */
    DIVASIG_ = 285,                /* DIVASIG_  */
    IGU_ = 286,                    /* IGU_  */
    NOIGU_ = 287,                  /* NOIGU_  */
    MAYIGU_ = 288,                 /* MAYIGU_  */
    MENIGU_ = 289,                 /* MENIGU_  */
    INC_ = 290,                    /* INC_  */
    DEC_ = 291,                    /* DEC_  */
    MAY_ = 292,                    /* MAY_  */
    MEN_ = 293,                    /* MEN_  */
    ASIG_ = 294,                   /* ASIG_  */
    NOT_ = 295,                    /* NOT_  */
    MOD_ = 296,                    /* MOD_  */
    INT_ = 297,                    /* INT_  */
    BOOL_ = 298,                   /* BOOL_  */
    CTE_ = 299,                    /* CTE_  */
    ID_ = 300                      /* ID_  */
  };
  typedef enum yytokentype yytoken_kind_t;
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

#line 117 "asin.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASIN_H_INCLUDED  */
