/*****************************************************************************/
/*****************************************************************************/
#ifndef _HEADER_H
#define _HEADER_H
/****************************************************** Constantes simbolicas */
#define TALLA_TIPO_SIMPLE 1
#define TALLA_SEGENLACES 2
/****************************************************** Constantes generales */
#define TRUE  1
#define FALSE 0
/************************************* Variables externas definidas en el AL */
extern int yylex();
extern int yyparse();

extern FILE *yyin;
extern int   yylineno;

typedef struct exp {                        /* Estructura para las expresiones  */
    int t;     //TIPO
    int p;     //POSICION   
}   EXP;

typedef struct str {                        /* Estructura para las estructuras con talla  */
    char* n;    //NOMBRE
    int t;      //TIPO
    int talla;  //TALLA
}   STR;
typedef struct mat{                        /* Estructura para las estructuras que utilicen valores  */
    int v;      //VALOR
    int t;      //TIPO
}   MAT;

/********************************* Funciones y variables externas auxiliares */
extern int verbosidad;                   /* Flag si se desea una traza       */

extern void yyerror(const char * msg) ;      /* Tratamiento de errores       */



#endif  /* _HEADER_H */
/*****************************************************************************/
/*****************************************************************************/
