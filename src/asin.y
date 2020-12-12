/*****************************************************************************/
/** ANALIZADOR SINTACTICO                                           GRUPO 9 **/
/** Autores: Álvaro Rodríguez Sánchez
/**          Vladyslav
/**          Lugman
/**          Miguel
/**
/*****************************************************************************/

%{
#include <stdio.h>
#include <string.h>
#include "header.h"
#include "libtds.h"

int dvar;
int niv;
int Daux;
%}

%union{
    char *ident; //NOMBRE DEL IDENTIFICADOR
    int cent;    //VALOR DE LA CTE NUMERICA ENTERA
    EXP exp;     //TIPO PARA LAS EXPRESIONES
    STR str;     //TIPO PARA LOS ELEMENTOS CON TALLA
}

%token WHILE_ FOR_ IF_ ELSE_ TRUE_ FALSE_ PRINT_ READ_ RETURN_ 
%token ALLAVE_  CLLAVE_ ACORCH_  CCORCH_ APAREN_ CPAREN_ PTOCOMA_ PTO_ CMA_
%token MAS_ MENOS_ POR_ DIV_
%token AND_ OR_ SUMASIG_ RESASIG_ MULASIG_ DIVASIG_ IGU_ NOIGU_ MAYIGU_ MENIGU_ INC_ DEC_  MAY_ MEN_ ASIG_ NOT_ MOD_

%token <cent> INT_ CTE_ BOOL_ 
%type <cent> parametrosFormales parametrosActuales listaParametrosActuales
%type <cent> operadorAditivo operadorIgualdad operadorIncremento
%type <cent> operadorLogico operadorMultiplicativo operadorRelacional operadorUnario

%type <ident> ID_

%type <exp> declaracionVariable
%type <exp> programa listaDeclaraciones declaracion instruccion expresion
%type <exp> expresionIgualdad expresionAditiva expresionRelacional expresionOpcional
%type <exp> expresionMultiplicativa expresionUnaria expresionSufija constante

%type <str> tipoSimple listaParametrosFormales parametrosFormales declaracionVariable
%%

programa                        :{
                                    dvar = 0;
                                    niv = 0;
                                    }
                                | listaDeclaraciones {
                                        /*  vacio   */
                                    }
                                ;

listaDeclaraciones              : declaracion {
                                        /*  vacio   */
                                    }
                                | listaDeclaraciones declaracion{
                                        /*  vacio   */
                                    }
                                ;

declaracion                     : declaracionVariable{
                                        dvar = dvar + $1.talla;
                                    }
                                | declaracionFuncion{
                                        dvar = dvar + $1.talla;
                                    }
                                ;

declaracionVariable             : tipoSimple ID_ PTOCOMA_{
                                        if(insTdS($2,VARIABLE,$1.t,niv,dvar,-1)){
                                            $$.n = $2;
                                            $$.talla = $$.talla + TALLA_TIPO_SIMPLE;
                                        }else{
                                            $$.t = T_ERROR;
                                            yyerror("La variable ya ha sido declarada");
                                        }
                                    }
                                | tipoSimple ID_ ACORCH_ CTE_ CCORCH_ PTOCOMA_{
                                        int numelem = $4;
                                        if(numelem <= 0){
                                            yyerror("Talla no apropiada para array");
                                            numelem = 0;
                                        }
                                        else{
                                            int refe = insTdA($1.t, numelem);
                                            if(instTdS($2,VARIABLE,T_ARRAY,niv,dvar,refe)){
                                                $$.n = $2;
                                                $$.t = $1;
                                                $$.talla = $$.talla + numelem * TALLA_TIPO_SIMPLE;
                                            }
                                            else{
                                                yyerror("Identificador repetido")
                                            }
                                        }
                                        
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

declaracionFuncion              : cabeceraFuncion bloque {
                                        /*  vacio   */
                                    }
                                ;

cabeceraFuncion                 : tipoSimple ID_ APAREN_ parametrosFormales CPAREN_{
                                       insTdS($2)
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
                                    insTdS($2,PARAMETRO,$1.t,niv,-$$.talla,-1);
                                }
                                | tipoSimple ID_ CMA_ listaParametrosFormales{
                                    if($1.t == $4.t && $1.t != T_ERROR){
                                        $$.t == $1.t;
                                        $$.talla = $4.talla + $1.talla;
                                        insTdS($2,PARAMETRO,$1.t,niv,-$$.talla,-1);
                                    }
                                }
                                ;

bloque                          : {
                                    niv++;
                                    cargaContexto(niv);
                                    Daux = dvar; 
                                    dvar = 0;
                                }
                                | ALLAVE_ declaracionVariableLocal listaInstrucciones RETURN_ expresion PTOCOMA_ CLLAVE_{
                                    niv--;
                                    descargaContexto(niv);
                                    dvar = D.aux;
                                }
                                ;

declaracionVariableLocal        : /* vacio */ {

                                }
                                | declaracionVariableLocal declaracionVariable{
                                        if(insTdS($1,VARIABLE,$2.t,niv,dvar,-1)){
                                          dvar += TALLA_TIPO_SIMPLE;
                                        }
                                    }
                                ;

listaInstrucciones              : /* vacio */{

                                }
                                | listaInstrucciones instruccion{

                                }
                                ;

instruccion                     : ALLAVE_ listaInstrucciones CLLAVE_{

                                }
                                | instruccionAsignacion{

                                }
                                | instruccionSeleccion{

                                }
                                | instruccionEntradaSalida{

                                }
                                | instruccionIteracion{

                                }
                                ;

instruccionAsignacion           : ID_ ASIG_ expresion PTOCOMA_{
                                        SIMB simb = obtTdS($1);
                                        if(simb.t == T_ERROR)
                                            yyerror("Objeto no declarado");
                                        else if (! ((simb.t == $3.t == T_ENTERO) || (simb.t == $3.t == T_LOGICO)))
                                            yerror("Error de tipos en instruccion de asignacion");
                                    }
                                | ID_ ACORCH_ expresion CCORCH_ ASIG_ expresion PTOCOMA_{
                                        SIMB simb = obtTdS($1);
                                        if(simb.t == T_ERROR)
                                            yyerror("Objeto no declarado");
                                        else if (! ((simb.t == $3.t == T_ENTERO) ||(simb.t == $3.t == T_LOGICO)))
                                            yerror("Error de tipos en instruccion de asignacion");
                                    }
                                ;

instruccionEntradaSalida        : READ_ APAREN_ ID_ CPAREN_ PTOCOMA_{
                                    SIMB sim = obtTdS($3);
                                    if (sim.t != T_ENTERO) {
                                        yyerror("identificador no valido para la instruccion entrada : se esperaba identificador entero");
                                    }
                                }
                                | PRINT_ APAREN_ expresion CPAREN_ PTOCOMA_{
                                    if ($3.tipo != T_ERROR) { 
                                        if ($3.tipo != T_ENTERO) {
                                            yyerror("expresion no valida para la instruccion salida : se esperaba expresion entera");
                                        } 
                                }
                                ;

instruccionSeleccion            : IF_ APAREN_ expresion CPAREN_ instruccion ELSE_ instruccion{
                                    if($3.t != T_ERROR){
                                        if($3.t != T_LOGICO){
                                            yyerror("expresion no valida para la instruccion seleccion : se esperaba una expresion logica");
                                        }
                                    }
                                    
                                }
                                ;

instruccionIteracion            : FOR_ APAREN_ expresionOpcional PTOCOMA_ expresion PTOCOMA_ expresionOpcional CPAREN_ instruccion{
                                        if($5.t == T_LOGICO){
                                            if(($3.t != T_ERROR || $3.t == T_VACIO ) && ($7.t != T_ERROR || $7.t == T_VACIO )){

                                            }
                                            else{
                                                yyerror("Instrucción mal formada");
                                            }
                                        }
                                        else{
                                            yyerror("Error en el operador lógico");
                                        }
                                    }
                                    ;     

expresionOpcional               : /* vacı́o */{

                                }
                                | expresion{
                                    $$.t = $1.t
                                }
                                | ID_ ASIG_ expresion{
                                    $$.t = T_ERROR;
                                    SIMB simb = obtTdS($1);
                                    if (simb.t == T_ERROR) {
                                        yyerror("identificador no declarado : es necesario declararlo antes de utilizarlo");
                                    } 
                                    else{
                                        if ($3.t != T_ERROR) {
                                            if((simb.t != $3.t) || (simb.t == $3.t && simb.t != T_ENTERO && simb.t != T_LOGICO)) {
                                                yyerror("identificador o expresion no valida para la expresion : se esperaba un identificador y una expresion del mismo tipo");
                                            } 
                                            else {
                                                $$.t = sim.t;
                                            }
                                        }
                                    } 
                                }
                                ;

expresion                       : expresionIgualdad{
                                    $$.t = $1.t;
                                }
                                | expresion operadorLogico expresionIgualdad{
                                    $$.t = T_ERROR;
                                    if ($1.t != T_ERROR && $3.t != T_ERROR) {
                                        if ($1.t != T_LOGICO && $1.t != T_ENTERO ) {
                                            yyerror("expresion igualdad no valida para la expresion igualdad : se esperaba una expresion igualdad de tipo logica o entera");
                                        } else if ($3.t != T_LOGICO && $3.t != T_ENTERO) {
                                            yyerror("expresion relacional no valida para la expresion igualdad : se esperaba una expresion relacional de tipo logica o entera");
                                        } if ($1.t != $3.t) {
                                            yyerror("expresion igualdad o expresion relacional no valida para la expresion igualdad : se esperaba una expresion igualdad y una expresion relacional del mismo tipo");
                                        }
                                    } 
                                    else { 
                                        $$.t = T_LOGICO;
                                    }   
                                }
                                ;

expresionIgualdad               : expresionRelacional{
                                    $$.t = $1.t
                                }
                                | expresionIgualdad operadorIgualdad expresionRelacional{
                                    $$.t = T_ERROR;
                                    if ($1.t != T_ERROR && $3.t != T_ERROR) {
                                        if ($1.t != T_LOGICO && $1.t != T_ENTERO ) {
                                            yyerror("expresion igualdad no valida para la expresion igualdad : se esperaba una expresion igualdad de tipo logica o entera");
                                        } else if ($3.t != T_LOGICO && $3.t != T_ENTERO) {
                                            yyerror("expresion relacional no valida para la expresion igualdad : se esperaba una expresion relacional de tipo logica o entera");
                                        } if ($1.t != $3.t) {
                                            yyerror("expresion igualdad o expresion relacional no valida para la expresion igualdad : se esperaba una expresion igualdad y una expresion relacional del mismo tipo");
                                        }
                                    } 
                                    else { 
                                        $$.t = T_LOGICO;
                                    }                                     
                                }
                                ;

expresionRelacional             : expresionAditiva {
                                    $$.t = $1.t; 
                                }
                                | expresionRelacional operadorRelacional expresionAditiva{
                                    $$.t = T_ERROR;
                                    if ($1.t != T_ERROR && $3.t != T_ERROR) {
                                        if ($1.t != T_LOGICO && $1.t != T_ENTERO ) {
                                        yyerror("expresion relacional no valida para la expresion relacional : se esperaba una expresion relacional de tipo logica o entera");
                                        } else if ($3.t != T_LOGICO && $3.t != T_ENTERO) {
                                        yyerror("expresion aditiva no valida para la expresion relacional : se espera una expresion aditiva de tipo logica o entera");
                                        } else if ($1.t != $3.t) {
                                        yyerror("expresion relacional o expresion aditiva no valida para la expresion relacional : se espera una expresion relacional y una expresion aditiva del mismo tipo");
                                    } 
                                    else { 
                                        $$.t = T_LOGICO;
                                    }                                      
                                    }
                                };

expresionAditiva                : expresionMultiplicativa   { 
                                    $$.t = $1.t; 
                                }
                                | expresionAditiva operadorAditivo expresionMultiplicativa{
                                    $$.t = T_ERROR;
                                    if ($1.t == $3.t && $3.t == T_ENTERO){
                                        $$.t = T_ENTERO;
                                    } 
                                    else{
                                        yyerror("Error de tipos en la expresion aditiva");
                                    }
                                }
                                ;

expresionMultiplicativa         : expresionUnaria{
                                    $$.t = $1.t;
                                }
                                | expresionMultiplicativa operadorMultiplicativo expresionUnaria{
                                    $$.t = T_ERROR;
                                    if ($1.t != T_ERROR && $3.t != T_ERROR) {
                                        if ($1.t != T_ENTERO) {
                                            yyerror("expresion multiplicativa no valida para la expresion multiplicativa : se espera una expresion multiplicativa de tipo entera");
                                        } else if ($3.t != T_ENTERO) {
                                            yyerror("expresion unaria no valida para la expresion multiplicativa : se espera una expresion unaria de tipo entera");
                                        } else { 
                                            $$.t = $1.t;
                                        }                                      
                                    }
                                }
                                ;

expresionUnaria                 : expresionSufija{ 
                                    $$.tipo = $1.tipo;
                                    $$.pos = $1.pos;
                                }
                                | operadorUnario expresionUnaria{   
                                    $$.tipo = T_ERROR;
                                    if ($2.t != T_ERROR) {
                                        if ($1 == NOT) {
                                            if ($2.t != T_LOGICO) {
                                                yyerror("expresion unaria no valida para la expresion unaria : se espera una expresion unaria de tipo logica");
                                            } else { 
                                                $$.t = $2.t;
                                            }  
                                        } 
                                        else {
                                            if ($2.t != T_ENTERO) {
                                                yyerror("expresion unaria no valida para la expresion unaria : se espera una expresion unaria de tipo entera");
                                            } else { 
                                                $$.t = $2.t;
                                            } 
                                        }                                     
                                    }                                   
                                } 
                                | operadorIncremento ID_ {
                                    $$.tipo = T_ERROR;
                                    SIMB simb = obtTdS($2);
                                    if (simb.t == T_ERROR) {
                                        yyerror("identificador no declarado : declarelo antes de utilizarlo");
                                    }
                                    else{
                                        $$.t = sim.t;
                                    }                                                   
                                } 
                                ;

expresionSufija                 : APAREN_ expresion CPAREN_{
                                        $$.t = $2.t;
                                    }
                                | ID_ operadorIncremento{
                                        $$.t = T_ERROR;
                                        SIMB simb = obtTdS($1)
                                        if(simb.t == T_ERROR){
                                            yyerror("identificador no declarado.");
                                        }else if(simb.t != T_ENTERO){
                                            yyerror("identificador no valido, unicamente valido con tipo int");
                                        }else{
                                            $$.t = simb.t;
                                        }
                                    }
                                | ID_ ACORCH_ expresion CCORCH_{
                                        $$.t = T_ERROR;
                                        SIMB simb = obtTdS($1)
                                        if(simb.t == T_ERROR){
                                            yyerror("identificador no declarado.");
                                        }else if(simb.t != T_ERROR){
                                            if($3.t != T_ENTERO){
                                                yyerror("expresion no valida : se espera tipo int");
                                            }
                                            if(simb.t != T_ARRAY){
                                                yyerror("identificador no valido : se espera tipo array");
                                            }
                                            if($3.t == T_ENTERO && simb.t == T_ARRAY){
                                                    $$.t = simb.t;
                                            }
                                        }
                                    }
                                | ID_ APAREN_ parametrosActuales CPAREN_{
                                        $$.t = T_ERROR;
                                        SIMB simb = obtTdS($1);
                                        if(simb.t != T_FUNCION){
                                            yyerror("inconsistencia de tipos : identificador y parametros actuales no son del mismo tipo");
                                        }else if(simb.t != $3){
                                            yyerror("identificador no valido : no corresponde con el tipo de parametros actuales");
                                        }else{
                                            $$.t = simb.t;
                                        }
                                    }
                                | ID_ {
                                        $$.t = T_ERROR;
                                        SIMB simb = obtTdS($1);
                                        if (simb.t == T_ERROR) {
                                            yyerror("identificador no declarado : declarelo antes de utilizarlo");
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
                                    $$ = $1;
                                }
                                ;

listaParametrosActuales         : expresion{

                                }
                                | expresion CMA_ listaParametrosActuales{

                                }
                                ;


constante                       : CTE_    {$$ = $1}
                                | TRUE_   {$$ = T_LOGICO}
                                | FALSE_  {$$ = T_LOGICO}
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
