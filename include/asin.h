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
    INT_ = 258,                    /* INT_  */
    ID_ = 259,                     /* ID_  */
    CTE_ = 260,                    /* CTE_  */
    BOOL_ = 261,                   /* BOOL_  */
    WHILE_ = 262,                  /* WHILE_  */
    FOR_ = 263,                    /* FOR_  */
    IF_ = 264,                     /* IF_  */
    ELSE_ = 265,                   /* ELSE_  */
    TRUE_ = 266,                   /* TRUE_  */
    FALSE_ = 267,                  /* FALSE_  */
    PRINT_ = 268,                  /* PRINT_  */
    READ_ = 269,                   /* READ_  */
    RETURN_ = 270,                 /* RETURN_  */
    ALLAVE_ = 271,                 /* ALLAVE_  */
    CLLAVE_ = 272,                 /* CLLAVE_  */
    ACORCH_ = 273,                 /* ACORCH_  */
    CCORCH_ = 274,                 /* CCORCH_  */
    APAREN_ = 275,                 /* APAREN_  */
    CPAREN_ = 276,                 /* CPAREN_  */
    PTOCOMA_ = 277,                /* PTOCOMA_  */
    PTO_ = 278,                    /* PTO_  */
    CMA_ = 279,                    /* CMA_  */
    MAS_ = 280,                    /* MAS_  */
    MENOS_ = 281,                  /* MENOS_  */
    POR_ = 282,                    /* POR_  */
    DIV_ = 283,                    /* DIV_  */
    AND_ = 284,                    /* AND_  */
    OR_ = 285,                     /* OR_  */
    SUMASIG_ = 286,                /* SUMASIG_  */
    RESASIG_ = 287,                /* RESASIG_  */
    MULASIG_ = 288,                /* MULASIG_  */
    DIVASIG_ = 289,                /* DIVASIG_  */
    IGU_ = 290,                    /* IGU_  */
    NOIGU_ = 291,                  /* NOIGU_  */
    MAYIGU_ = 292,                 /* MAYIGU_  */
    MENIGU_ = 293,                 /* MENIGU_  */
    INC_ = 294,                    /* INC_  */
    DEC_ = 295,                    /* DEC_  */
    MAY_ = 296,                    /* MAY_  */
    MEN_ = 297,                    /* MEN_  */
    ASIG_ = 298,                   /* ASIG_  */
    NOT_ = 299,                    /* NOT_  */
    MOD_ = 300                     /* MOD_  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "src/asin.y"

    char *ident; //NOMBRE DEL IDENTIFICADOR
    int cent;    //VALOR DE LA CTE NUMERICA ENTERA
    EXP exp;     //TIPO PARA LAS EXPRESIONES
    

#line 116 "asin.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASIN_H_INCLUDED  */
