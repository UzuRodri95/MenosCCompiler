/*****************************************************************************/
/** ANALIZADOR SINTACTICO                                           GRUPO 9 **/
/** Autores: Álvaro Rodríguez Sánchez
/**          Vladyslav Mazurkevych
/**          Lugman Ahmad Mansilla
/**          Miguel Angel Navarro Arenas
/**
/*****************************************************************************/

%{
#include <stdio.h>
#include <string.h>
#include "header.h"
#include "libtds.h"

#define GLOBAL 0
#define LOCAL 1

int dvar;
int niv;
%}

%union{
    char *ident; //NOMBRE DEL IDENTIFICADOR
    int cent;    //VALOR DE LA CTE NUMERICA ENTERA
    EXP exp;     //PARA LAS EXPRESIONES
    STR str;     //PARA LOS ELEMENTOS CON TALLA
}

%token WHILE_ FOR_ IF_ ELSE_  PRINT_ READ_ RETURN_ 
%token ALLAVE_  CLLAVE_ ACORCH_  CCORCH_ APAREN_ CPAREN_ PTOCOMA_ PTO_ CMA_
%token <cent>  MAS_ MENOS_ POR_ DIV_
%token <cent>  AND_ OR_ SUMASIG_ RESASIG_ MULASIG_ DIVASIG_ IGU_ NOIGU_ MAYIGU_ MENIGU_ INC_ DEC_  MAY_ MEN_ ASIG_ NOT_ MOD_

%token <cent> INT_ BOOL_ CTE_ TRUE_ FALSE_
%type <cent> parametrosActuales 
%type <cent> operadorAditivo operadorIgualdad operadorIncremento
%type <cent> operadorLogico operadorMultiplicativo operadorRelacional operadorUnario

%token <ident> ID_ 

%type <exp> programa listaDeclaraciones 
  
%type <str> tipoSimple listaParametrosFormales parametrosFormales declaracionVariable listaParametrosActuales declaracionFuncion 
%type <str> declaracionVariableLocal cabeceraFuncion 

%type <str> constante expresion expresionIgualdad expresionRelacional expresionAditiva expresionMultiplicativa expresionSufija
%type <str> expresionUnaria instruccionAsignacion instruccionEntradaSalida instruccionSeleccion instruccionIteracion
%type <str> instruccion listaInstrucciones expresionOpcional declaracion 
%%

programa                        :{ niv = GLOBAL; dvar = 0; cargaContexto(niv);} listaDeclaraciones { if($2.t == 0) yyerror("El programa no tiene main. 2");}
                                ;

listaDeclaraciones              : declaracion { $$.t = $1.t; }
                                | listaDeclaraciones declaracion{
                                    if($1.t == 0 && $2.t == 0){
                                        yyerror("El programa no tiene main.");
                                    }        
                                    else{
                                        if($2.t == 0){
                                            $$.t = $1.t;
                                        }   
                                        else{
                                            $$.t = $2.t;
                                        }
                                    } 
                                  }
                                ;

declaracion                     : declaracionVariable{
                                        dvar = dvar + $1.talla;
                                        $$.t = $1.t;
                                    }
                                | declaracionFuncion{ 
                                        dvar = dvar + $1.talla;
                                        $$.t = $1.t;
                                    }
                                ;

declaracionVariable             : tipoSimple ID_ PTOCOMA_{
                                        if(insTdS($2,VARIABLE,$1.t,niv,dvar,-1)){
                                            $$.n = $2;
                                            $$.talla = $$.talla + TALLA_TIPO_SIMPLE;
                                            $$.t = $1.t;
                                        }else{
                                            $$.t = T_ERROR;
                                            yyerror("Identificador repetido");
                                        }
                                    }
                                | tipoSimple ID_ ACORCH_ CTE_ CCORCH_ PTOCOMA_{
                                        int numelem = $4;
                                        if(numelem <= 0){
                                            yyerror("Talla inapropiada del array");
                                            numelem = 0;
                                        }
                                        else{
                                            int refe = insTdA($1.t, numelem);
                                            if(insTdS($2,VARIABLE,T_ARRAY,niv,dvar,refe)){
                                                $$.n = $2;
                                                $$.t = $1.t;
                                                $$.talla = $$.talla + numelem * TALLA_TIPO_SIMPLE;
                                            }
                                            else{
                                                yyerror("Identificador repetido");
                                            }
                                        };
                                    }
                                ;

tipoSimple                      : INT_ {                                   
                                    $$.t = T_ENTERO;
                                    $$.talla = TALLA_TIPO_SIMPLE;
                                    }
                                | BOOL_{
                                    $$.t = T_LOGICO;
                                    $$.talla = TALLA_TIPO_SIMPLE;
                                    }
                                ;

declaracionFuncion              : cabeceraFuncion { $<cent>$ = dvar; dvar = 0; } bloque { if(verTdS == TRUE) mostrarTdS(); descargaContexto(niv); niv = GLOBAL; dvar = $<cent>2; }
                                ;

cabeceraFuncion                 : tipoSimple ID_ { niv = LOCAL; cargaContexto(niv);} APAREN_ parametrosFormales CPAREN_{
                                        if(insTdS($2,FUNCION,$1.t,niv,$5.talla,-1)){
                                           $$.n = $2;
                                           $$.t = $1.t;
                                           $$.talla = $5.talla;   
                                        }
                                        else{
                                           $$.t = T_ERROR;
                                           yyerror("Ya existe variable, se ha declarado previamente");
                                        }
                                      
                                    }
                                ;

parametrosFormales              : /* vacio */{
                                        $$.t = T_VACIO;
                                        $$.talla = 0;
                                    }
                                | listaParametrosFormales{
                                        $$.t = $1.t;
                                        $$.talla =  $$.talla - TALLA_SEGENLACES;
                                    }
                                ;

listaParametrosFormales         : tipoSimple ID_{
                                    $$.t = $1.t;
                                    $$.talla = TALLA_SEGENLACES + $1.talla;
                                    int ref = insTdD(-1,$1.t);
                                    $$.refe = ref; 
                                    insTdS($2,PARAMETRO,$1.t,niv,-$$.talla,ref);
                                }
                                | tipoSimple ID_ CMA_ listaParametrosFormales{
                                     if($1.t == $4.t && $1.t != T_ERROR){
                                         $$.t == $1.t;
                                         $$.talla = $4.talla + $1.talla;
                                         
                                         int ref = insTdD($4.refe, $1.t);
                                         insTdS($2,PARAMETRO,$1.t,niv,-$$.talla,ref);
                                     }
                                }
                                ;

bloque                          : {
                                    /* vacio */
                                }
                                | ALLAVE_ declaracionVariableLocal listaInstrucciones RETURN_ expresion PTOCOMA_ CLLAVE_{
                                    /* vacio */
                                }
                                ;

declaracionVariableLocal        : /* vacio */ {

                                }
                                | declaracionVariableLocal declaracionVariable{
                                        if(insTdS($1.n,VARIABLE,$2.t,niv,dvar,-1)){
                                          dvar += TALLA_TIPO_SIMPLE;
                                        }
                                    }
                                ;

listaInstrucciones              : /* vacio */{
                                    $$.t = T_VACIO;
                                }
                                | listaInstrucciones instruccion{
                                    if($1.t != T_ERROR && $2.t != T_ERROR){
                                        $$.t = $1.t;
                                    }else{
                                        $$.t = T_ERROR;
                                    } 
                                }
                                ;

instruccion                     : ALLAVE_ listaInstrucciones CLLAVE_{
                                    $$.t = $2.t;
                                }
                                | instruccionAsignacion
                                {
                                    $$.t = $1.t;
                                }
                                | instruccionSeleccion{
                                    $$.t = $1.t;
                                }
                                | instruccionEntradaSalida{
                                    $$.t = $1.t;
                                }
                                | instruccionIteracion{
                                    $$.t = $1.t;
                                }
                                ;

instruccionAsignacion           : ID_ ASIG_ expresion PTOCOMA_{
                                        SIMB simb = obtTdS($1);
                                        if(simb.t == T_ERROR){
                                            $$.t = T_ERROR;
                                        }
                                        else if (!((simb.t == $3.t) && ($3.t == T_ENTERO || $3.t == T_LOGICO))){
                                            $$.t = T_ERROR;
                                        } else{
                                            $$.t = $3.t;
                                        }
                                        
                                        if($$.t == T_ERROR){
                                            yyerror("Objeto no declarado");
                                        } 
                                    }
                                | ID_ ACORCH_ expresion CCORCH_ ASIG_ expresion PTOCOMA_{
                                        SIMB simb = obtTdS($1);
                                        if(simb.t == T_ERROR){
                                            $$.t = T_ERROR;
                                            yyerror("Objeto no declarado");
                                        }
                                        else if(! ($3.t == T_ENTERO)){
                                            $$.t = T_ERROR;
                                            yyerror("El indice del <array> debe ser entero");
                                        } 
                                        else if (! (simb.t == $6.t)){
                                            $$.t = T_ERROR;
                                        }
                                        else if( ! (simb.t == T_ARRAY)){
                                            $$.t = T_ERROR;
                                            yyerror("El identificado debe ser de tipo <array>");
                                        }
                                        else{
                                            $$.t = simb.t;
                                        }  
                                            
                                    }
                                ;

instruccionEntradaSalida        : READ_ APAREN_ ID_ CPAREN_ PTOCOMA_{
                                    SIMB sim = obtTdS($3);
                                    if (sim.t != T_ENTERO) {
                                        $$.t = T_ERROR;
                                        yyerror("Identificador no valido para la instruccion entrada : se esperaba identificador entero");
                                    }
                                }
                                | PRINT_ APAREN_ expresion CPAREN_ PTOCOMA_{
                                    if ($3.t != T_ERROR) { 
                                        if ($3.t != T_ENTERO) {
                                            $$.t = T_ERROR;
                                            yyerror("Expresion no valida para la instruccion salida : se esperaba expresion entera");
                                        } 
                                    }
                                }
                                ;

instruccionSeleccion            : IF_ APAREN_ expresion CPAREN_ instruccion ELSE_ instruccion{
                                    if($3.t != T_ERROR){
                                        if($3.t != T_LOGICO){
                                            $$.t = T_ERROR;
                                            yyerror("Expresion no valida para la instruccion seleccion : se esperaba una expresion logica");
                                        }
                                    }
                                    
                                }
                                ;

instruccionIteracion            : FOR_ APAREN_ expresionOpcional PTOCOMA_ expresion PTOCOMA_ expresionOpcional CPAREN_ instruccion{
                                        if($5.t == T_LOGICO){
                                            if(($3.t != T_ERROR || $3.t == T_VACIO ) && ($7.t != T_ERROR || $7.t == T_VACIO )){
                                                $$.t = $3.t;
                                            }
                                            else{
                                                $$.t = T_ERROR;
                                                yyerror("Instrucción mal formada");
                                            }
                                        }
                                        else{
                                            $$.t = T_ERROR;
                                            yyerror("Error en el operador lógico");
                                        }
                                    }
                                    ;     

expresionOpcional               : /* vacı́o */{

                                }
                                | expresion{
                                    $$.t = $1.t;
                                }
                                | ID_ ASIG_ expresion{
                                    SIMB simb = obtTdS($1);
                                    if (simb.t == T_ERROR) {
                                        $$.t = T_ERROR;
                                        yyerror("Identificador no declarado : es necesario declararlo antes de utilizarlo");
                                    } 
                                    else{
                                        if ($3.t != T_ERROR) {
                                            if((simb.t != $3.t) || (simb.t == $3.t && simb.t != T_ENTERO && simb.t != T_LOGICO)) {
                                                $$.t = T_ERROR;
                                                yyerror("Identificador o expresion no valida para la expresion : se esperaba un identificador y una expresion del mismo tipo");
                                            } 
                                            else {
                                                $$.t = simb.t;
                                            }
                                        }
                                    } 
                                }
                                ;

expresion                       : expresionIgualdad{
                                    if ($1.t != T_LOGICO && $1.t != T_ENTERO ) {
                                        $$.t = T_ERROR;
                                    }else{
                                        $$.t = $1.t;
                                    }                                        
                                
                                }
                                | expresion operadorLogico expresionIgualdad{
                                    if ($1.t != T_ERROR && $3.t != T_ERROR) {
                                        if ($1.t != T_LOGICO) {
                                            $$.t = T_ERROR;
                                        } else if ($3.t != T_LOGICO){
                                            $$.t = T_ERROR;
                                        } else if ($1.t != $3.t) {
                                            $$.t = T_ERROR;
                                            
                                        }
                                    } 
                                    else { 
                                        $$.t = T_LOGICO;                                        
                                    }   
                                }
                                ;

expresionIgualdad               : expresionRelacional{
                                    if($1.t != T_LOGICO && $1.t != T_ENTERO)
                                    {   
                                        $$.t = T_ERROR;
                                        yyerror("Expresion igualdad no valida para la expresion igualdad : se esperaba una expresion igualdad de tipo logica");
                                    } 
                                    else
                                    {
                                        $$.t = $1.t;
                                    }  
                                        
                                }
                                | expresionIgualdad operadorIgualdad expresionRelacional{
                                    if ($1.t != T_ERROR && $3.t != T_ERROR) {
                                        if ($1.t != T_LOGICO && $1.t != T_ENTERO ) {
                                            $$.t = T_ERROR;
                                            yyerror("Expresion igualdad no valida para la expresion igualdad : se esperaba una expresion igualdad de tipo logica o entera");
                                        } else if ($3.t != T_LOGICO && $3.t != T_ENTERO) {
                                            $$.t = T_ERROR;
                                            yyerror("Expresion relacional no valida para la expresion igualdad : se esperaba una expresion relacional de tipo logica o entera");
                                        } else if ($1.t != $3.t) {
                                            $$.t = T_ERROR;
                                            yyerror("Expresion igualdad o expresion relacional no valida para la expresion igualdad : se esperaba una expresion igualdad y una expresion relacional del mismo tipo");
                                        }
                                    } 
                                    else {
                                        $$.t = $1.t;
                                    } 

                                    if($$.t == T_ERROR){
                                        yyerror("Error en expresion igualdad no valida : tipos incompatibles");
                                    }                                     
                                }
                                ;

expresionRelacional             : expresionAditiva {
                                    $$.t = $1.t;
                                }
                                | expresionRelacional operadorRelacional expresionAditiva{
                                    if ($1.t != T_ERROR && $3.t != T_ERROR) {
                                        if ($1.t == T_ENTERO && $1.t==$3.t) {
                                              $$.t = T_ENTERO;
                                        } 
                                        else { 
                                            $$.t = T_ERROR;
                                            if($1.t == T_ERROR)
                                                yyerror("Error en expresion relacional : operandos nos son de tipo entero.");
                                        }                                      
                                    }
                                };

expresionAditiva                : expresionMultiplicativa   {
                                    $$.t = $1.t;
                                }
                                | expresionAditiva operadorAditivo expresionMultiplicativa{
                                    if ($1.t == $3.t && $3.t == T_ENTERO){
                                        $$.t = T_ENTERO;
                                    } 
                                    else{
                                        $$.t = T_ERROR;
                                        if($3.t == T_ENTERO) yyerror("Error de tipos en la expresion multiplicativa");
                                        else yyerror("Error de tipos en la expresion aditiva");
                                        
                                    }
                                }
                                ;

expresionMultiplicativa         : expresionUnaria{
                                        $$.t = $1.t;
                                }
                                | expresionMultiplicativa operadorMultiplicativo expresionUnaria{
                                    if ($1.t == T_ENTERO && $3.t == T_ENTERO) {
                                        $$.t = $1.t;                    
                                    }
                                    else{
                                        $$.t = T_ERROR;
                                    } 
                                }
                                ;

expresionUnaria                 : expresionSufija{
                                    $$.t = $1.t;
                                }
                                | operadorUnario expresionUnaria{
                                    if ($2.t != T_ERROR) {
                                        if ($1 == NOT_) {
                                            if ($2.t != T_LOGICO) {
                                                $$.t = T_ERROR;
                                            } else { 
                                                $$.t = $2.t;
                                            }  
                                        } 
                                        else {
                                            if ($2.t != T_ENTERO) {
                                                $$.t = T_ERROR;
                                            } else { 
                                                $$.t = $2.t;
                                            } 
                                        }                                     
                                    }   

                                    if($$.t == T_ERROR){
                                        yyerror("Error en expresion unaria, tipo no valido");
                                    }                                 
                                } 
                                | operadorIncremento ID_ {
                                    SIMB simb = obtTdS($2);
                                    if (simb.t == T_ERROR) {
                                        $$.t = T_ERROR;
                                        yyerror("Identificador no declarado : declarelo antes de utilizarlo");
                                    }
                                    else{
                                        $$.t = simb.t;
                                    }                                                   
                                } 
                                ;
                                

expresionSufija                 : APAREN_ expresion  CPAREN_{
                                        $$.t = $2.t;
                                    }
                                | ID_ operadorIncremento{
                                        SIMB simb = obtTdS($1);
                                        if(simb.t == T_ERROR){
                                            $$.t = T_ERROR;
                                            yyerror("Identificador no declarado.");
                                        }else if(simb.t != T_ENTERO){
                                            $$.t = T_ERROR;
                                            yyerror("Identificador no valido, unicamente valido con tipo int");
                                        }else{
                                            $$.t = simb.t;
                                        }
                                    }
                                | ID_ ACORCH_ expresion CCORCH_{
                                        SIMB simb = obtTdS($1);
                                        if(simb.t == T_ERROR){
                                            $$.t = T_ERROR;
                                            yyerror("Identificador no declarado.");
                                        }else if(simb.t != T_ERROR){
                                            if($3.t != T_ENTERO){
                                                $$.t = T_ERROR;
                                                yyerror("Expresion no valida : se espera tipo int");
                                            }
                                            if(simb.t != T_ARRAY){
                                                $$.t = T_ERROR;
                                                yyerror("Identificador no valido : se espera tipo array");
                                            }
                                            if($3.t == T_ENTERO && simb.t == T_ARRAY){
                                                    $$.t = simb.t;
                                            } 
                                        }
                                    }
                                | ID_ APAREN_ parametrosActuales CPAREN_{
                                        SIMB simb = obtTdS($1);
                                        if(simb.t != T_ENTERO && simb.t != T_LOGICO){
                                            $$.t = T_ERROR;
                                            yyerror("Inconsistencia de tipos : identificador y parametros actuales no son del mismo tipo");
                                        }else if(simb.t != $3){
                                            $$.t = T_ERROR;
                                            yyerror("Identificador no valido : no corresponde con el tipo de parametros actuales");
                                        }else{
                                            $$.t = simb.t;
                                        }
                                    }
                                | ID_ {
                                        SIMB simb = obtTdS($1);
                                        if (simb.t == T_ERROR) {
                                            $$.t = T_ERROR;
                                            yyerror("Identificador no declarado : declarelo antes de utilizarlo");
                                        } 
                                        else {
                                            $$.t = simb.t;
                                        }
                                    }
                                | constante{
                                        $$.t = $1.t;
                                    }
                                ;

parametrosActuales              : /* vacı́o */{
                                    $$ = T_VACIO;
                                }
                                | listaParametrosActuales{
                                    $$ = $1.t;
                                }
                                ;

listaParametrosActuales         : expresion{

                                }
                                | expresion CMA_ listaParametrosActuales{

                                }
                                ;


constante                       : CTE_    {
                                    $$.t = T_ENTERO;
                                }
                                | TRUE_   {
                                    $$.t = T_LOGICO;
                                }
                                | FALSE_  {
                                    $$.t = T_LOGICO;
                                }
                                ;

operadorLogico                  :AND_
                                |OR_
                                ;

operadorIgualdad                :IGU_
                                |NOIGU_   
                                ;

operadorRelacional              : MAY_
                                | MEN_
                                | MAYIGU_
                                | MENIGU_
                                ;

operadorAditivo                 : MAS_      
                                | MENOS_    
                                ;

operadorMultiplicativo          : POR_      
                                | DIV_      
                                ;

operadorUnario                  : MAS_      
                                | MENOS_    
                                | NOT_
                                ;

operadorIncremento              : INC_
                                | DEC_
                                ;

%%
