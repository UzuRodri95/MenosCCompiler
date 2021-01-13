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
#define NOT          100
/************************************* Variables externas definidas en el AL */
extern int yylex();
extern int yyparse();

extern FILE *yyin;
extern int   yylineno;

/************************************* Variables externas definidas en el Programa Principal */
extern int verTdS;

/************************************* Variables externas definidas en las librerias */
extern int dvar;
extern int niv;
extern int si; /* Desplazamiento relativo en el Segmento de C´odigo */


typedef struct exp {                        /* Estructura para las expresiones  */
    int t;     //TIPO
    int p;     //POSICION   
}   EXP;

typedef struct str {                        /* Estructura para las estructuras con talla  */
    char* n;    //NOMBRE
    int t;      //TIPO
    int talla;  //TALLA
    int refe;
    int d;      //DESPLAZAMIENTO
}   STR;
typedef struct refes // Para atributos con 2 o 3 ref.auxiliares
{
    int ref1;
    int ref2;
    int ref3;
} REFES;



/********************************* Funciones y variables externas auxiliares */
extern int verbosidad;                   /* Flag si se desea una traza       */

extern void yyerror(const char * msg) ;      /* Tratamiento de errores       */

#endif  /* _HEADER_H */
/*****************************************************************************/
/*****************************************************************************/
