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

#define GLOBAL 0
#define LOCAL 1

int dvar;
int niv;
int Daux;
%}

%union{
    char *ident; //NOMBRE DEL IDENTIFICADOR
    int cent;    //VALOR DE LA CTE NUMERICA ENTERA
    EXP exp;     //PARA LAS EXPRESIONES
    STR str;     //PARA LOS ELEMENTOS CON TALLA
    MAT mat;     //PARA CONSTANTE
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

%type <exp> programa listaDeclaraciones declaracion 
%type <exp> expresionOpcional 
  

%type <str> tipoSimple listaParametrosFormales parametrosFormales declaracionVariable listaParametrosActuales declaracionFuncion 
%type <str> declaracionVariableLocal cabeceraFuncion 

%type <mat> constante expresion expresionIgualdad expresionRelacional expresionAditiva expresionMultiplicativa expresionSufija
%type <mat> expresionUnaria instruccionAsignacion instruccionEntradaSalida instruccionSeleccion instruccionIteracion
%type <mat> instruccion listaInstrucciones 
%%

programa                        :{ niv = GLOBAL; dvar = 0; cargaContexto(niv); if(verTdS) mostrarTdS(); } listaDeclaraciones { if($2.t == 0) yyerror("El programa no tiene main.");}
                                ;

listaDeclaraciones              : declaracion { $1.t = $1.t; }
                                | listaDeclaraciones declaracion{
                                        if($1.t == 0)         $$.t = $2.t;
                                        else if($2.t == 0)  $$.t = $1.t;
                                             else yyerror("El programa no tiene main.");
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
                                        }
                                         mostrarTdS();
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

declaracionFuncion              : cabeceraFuncion { $<cent>$ = dvar; dvar = 0; } bloque { descargaContexto(niv); niv = GLOBAL; dvar = $<cent>2; }
                                ;

cabeceraFuncion                 : tipoSimple ID_ { niv = LOCAL; cargaContexto(niv);} APAREN_ parametrosFormales CPAREN_{ 
                                        //mostrarTdS();
                                        if(insTdS($2,FUNCION,$1.t,niv,$5.talla,-1)){
                                           $$.n = $2;
                                           $$.t = $1.t;
                                           $$.talla = $5.talla;   
                                       }
                                       else{
                                           $$.t = T_ERROR;
                                           yyerror("Ya existe variable, se ha declarado previamente");
                                       }
                                       //mostrarTdS();
                                      
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

                                }
                                | listaInstrucciones instruccion{
                                    if($1.t == $2.t){
                                        $$.t = $2.t;
                                    }else{
                                        $$.t = T_ERROR;
                                        yyerror(" Error de tipo : Tipo distinto a la lista de instrucciones");
                                    } 
                                }
                                ;

instruccion                     : ALLAVE_ listaInstrucciones CLLAVE_{
                                    $$.t = $2.t;
                                    $$.v = $2.v;
                                }
                                | instruccionAsignacion
                                {
                                    $$.t = $1.t;
                                    $$.v = $1.v;
                                    mostrarTdS();
                                }
                                | instruccionSeleccion{
                                    $$.t = $1.t;
                                    $$.v = $1.v;
                                }
                                | instruccionEntradaSalida{
                                    $$.t = $1.t;
                                }
                                | instruccionIteracion{
                                    
                                }
                                ;
//if (! (((simb.t == $3.t) && ($3.t == T_ENTERO)) && ((simb.t == $3.t) && ($3.t == T_LOGICO))))
instruccionAsignacion           : ID_ ASIG_ expresion PTOCOMA_{
                                        SIMB simb = obtTdS($1);
                                        if(simb.t == T_ERROR){
                                            $$.t = T_ERROR;
                                            yyerror("Objeto no declarado");
                                        }
                                        else if (!((simb.t == $3.t) && ($3.t == T_ENTERO || $3.t == T_LOGICO))){
                                            printf("Valor simb %d", simb.t);
                                            printf("Valor %d", $3.t);
                                            $$.t = T_ERROR;
                                            yyerror("Error de tipos en la <asignacion>");
                                        } else{
                                            $$.v = $3.v;
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
                                            yyerror("Error de tipos en la <asignacion>");
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
                                        yyerror("identificador no valido para la instruccion entrada : se esperaba identificador entero");
                                    }
                                }
                                | PRINT_ APAREN_ expresion CPAREN_ PTOCOMA_{
                                    if ($3.t != T_ERROR) { 
                                        if ($3.t != T_ENTERO) {
                                            $$.t = T_ERROR;
                                            yyerror("expresion no valida para la instruccion salida : se esperaba expresion entera");
                                        } 
                                    }
                                }
                                ;

instruccionSeleccion            : IF_ APAREN_ expresion CPAREN_ instruccion ELSE_ instruccion{
                                    if($3.t != T_ERROR){
                                        if($3.t != T_LOGICO){
                                            $$.t = T_ERROR;
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
                                    //$$.t = T_ERROR;
                                    SIMB simb = obtTdS($1);
                                    if (simb.t == T_ERROR) {
                                        $$.t = T_ERROR;
                                        yyerror("identificador no declarado : es necesario declararlo antes de utilizarlo");
                                    } 
                                    else{
                                        if ($3.t != T_ERROR) {
                                            if((simb.t != $3.t) || (simb.t == $3.t && simb.t != T_ENTERO && simb.t != T_LOGICO)) {
                                                $$.t = T_ERROR;
                                                yyerror("identificador o expresion no valida para la expresion : se esperaba un identificador y una expresion del mismo tipo");
                                            } 
                                            else {
                                                $$.t = simb.t;
                                            }
                                        }
                                    } 
                                }
                                ;

expresion                       : expresionIgualdad{
                                    printf("\tEXPRESIONIGUALDAD %d \n", $1.t);
                                    yyerror("\n");
                                    //$$.t = T_ERROR;
                                    if ($1.t != T_LOGICO) {
                                        $$.t = T_ERROR;
                                        yyerror("Error en <expresion logica>");
                                    }else{
                                        $$.t = $1.t;
                                        $$.v = $1.v;
                                    }                                        
                                
                                }
                                | expresion operadorLogico expresionIgualdad{
                                    //$$.t = T_ERROR;
                                    if ($1.t != T_ERROR && $3.t != T_ERROR) {
                                        if ($1.t != T_LOGICO) {
                                            $$.t = T_ERROR;
                                            yyerror("expresion igualdad no valida para la expresion igualdad : se esperaba una expresion igualdad de tipo logica o entera");
                                        } else if ($3.t != T_LOGICO){
                                            $$.t = T_ERROR;
                                            yyerror("Error en <expresion logica>");
                                        } if ($1.t != $3.t) {
                                            $$.t = T_ERROR;
                                            yyerror("expresion igualdad o expresion relacional no valida para la expresion igualdad : se esperaba una expresion igualdad y una expresion relacional del mismo tipo");
                                        }
                                    } 
                                    else { 
                                        if($2 == AND_)
                                            $$.v = $1.v && $3.v;
                                        if($2 == OR_)
                                            $$.v = $1.v || $3.v;

                                        $$.t = T_LOGICO;                                        
                                    }   
                                }
                                ;

expresionIgualdad               : expresionRelacional{
                                    printf("\tEXPRESIONRELACIONAL %d \n", $1.t);
                                    yyerror("\n");
                                    //$$.t = T_ERROR; 
                                    if($1.t != T_LOGICO && $1.t != T_ENTERO)
                                    {   
                                        $$.t = T_ERROR;
                                        yyerror("expresion igualdad no valida para la expresion igualdad : se esperaba una expresion igualdad de tipo logica");
                                    } 
                                    else
                                    {
                                        $$.t = $1.t;
                                        $$.v = $1.v; 
                                    }  
                                        
                                }
                                | expresionIgualdad operadorIgualdad expresionRelacional{
                                    //$$.t = T_ERROR;
                                    if ($1.t != T_ERROR && $3.t != T_ERROR) {
                                        if ($1.t != T_LOGICO && $1.t != T_ENTERO ) {
                                            $$.t = T_ERROR;
                                            yyerror("expresion igualdad no valida para la expresion igualdad : se esperaba una expresion igualdad de tipo logica o entera");
                                        } else if ($3.t != T_LOGICO && $3.t != T_ENTERO) {
                                            $$.t = T_ERROR;
                                            yyerror("expresion relacional no valida para la expresion igualdad : se esperaba una expresion relacional de tipo logica o entera");
                                        } if ($1.t != $3.t) {
                                            $$.t = T_ERROR;
                                            yyerror("expresion igualdad o expresion relacional no valida para la expresion igualdad : se esperaba una expresion igualdad y una expresion relacional del mismo tipo");
                                        }
                                    } 
                                    else { 
                                        if($2 == IGU_)
                                        {
                                            $$.v = $1.v == $3.v;
                                        }else{
                                            $$.v = $1.v != $3.v;
                                        } 
                                        
                                        $$.t = $1.t;
                                    }                                     
                                }
                                ;

expresionRelacional             : expresionAditiva {
                                    printf("\tEXPRESIONADITIVA $1.t %d\n",$1.t);
                                    yyerror("\n");
                                    $$.t = $1.t; 
                                    $$.v = $1.v;
                                }
                                | expresionRelacional operadorRelacional expresionAditiva{
                                    //$$.t = T_ERROR;
                                    if ($1.t != T_ERROR && $3.t != T_ERROR) {
                                        if ($1.t == T_ENTERO && $1.t==$3.t) {
                                              $$.t = T_ENTERO;
                                              switch($2)
                                                {
                                                    case MAYIGU_:
                                                        $$.v = $1.v >= $3.v;
                                                        break; 
                                                    case MENIGU_:
                                                        $$.v = $1.v <= $3.v;
                                                        break;
                                                    case MAY_:
                                                        $$.v = $1.v > $3.v;
                                                        break;  
                                                    case MEN_:
                                                        $$.v = $1.v < $3.v;
                                                        break;  
                                                } 

                                        } 
                                    else { 
                                        $$.t = T_ERROR;
                                        yyerror("Error en expresionRelacional : operandos nos son de tipo entero.");
                                    }                                      
                                    }
                                };

expresionAditiva                : expresionMultiplicativa   { 
                                    printf("\tEXPRESIONMULTIPLICATIVA $1.t %d\n",$1.t);
                                    yyerror("\n");
                                    $$.t = $1.t; 
                                    $$.v = $1.v;
                                }
                                | expresionAditiva operadorAditivo expresionMultiplicativa{
                                    //$$.t = T_ERROR;
                                    if ($1.t == $3.t && $3.t == T_ENTERO){
                                        printf("\testoy dentro\n");
                                        yyerror("\n");
                                        $$.t = T_ENTERO;
                                        if($2 == MAS_)
                                            $$.v = $1.v + $3.v;
                                        else
                                            $$.v = $1.v - $3.v;
                                    } 
                                    else{
                                        $$.t = T_ERROR;
                                        yyerror("Error de tipos en la expresion aditiva");
                                    }
                                }
                                ;

expresionMultiplicativa         : expresionUnaria{
                                        printf("\tALEJANDRAAAAAAAAAAAA\n");
                                        yyerror("\n");
                                        $$.t = $1.t;
                                        $$.v = $1.v;
                                }
                                | expresionMultiplicativa operadorMultiplicativo expresionUnaria{
                                    //$$.t = T_ERROR;
                                    if ($1.t != T_ERROR && $3.t != T_ERROR) {
                                        if ($1.t != T_ENTERO) {
                                            $$.t = T_ERROR;
                                            yyerror("expresion multiplicativa no valida para la expresion multiplicativa : se espera una expresion multiplicativa de tipo entera");
                                        } else if ($3.t != T_ENTERO) {
                                            $$.t = T_ERROR;
                                            yyerror("expresion unaria no valida para la expresion multiplicativa : se espera una expresion unaria de tipo entera");
                                        } else { 
                                            $$.t = $1.t;
                                            printf("\tHOLA QUE TAL %d \n",$1.t);
                                            yyerror("\n");
                                            if($2==DIV_)
                                            {
                                                $$.v = $1.v / $3.v;
                                            }else
                                            {
                                                $$.v = $1.v * $3.v;
                                            }                                           
                                        }                                      
                                    }
                                }
                                ;

expresionUnaria                 : expresionSufija{ 
                                    printf("\tSUFIJA ******************** %d\n",$1.t);
                                    yyerror("\n");
                                    $$.t = $1.t;
                                    $$.v = $1.v;
                                }
                                | operadorUnario expresionUnaria{ 
                                    //$$.t = T_ERROR;
                                    if ($2.t != T_ERROR) {
                                        if ($1 == NOT_) {
                                            if ($2.t != T_LOGICO) {
                                                $$.t = T_ERROR;
                                                yyerror("expresion unaria no valida para la expresion unaria : se espera una expresion unaria de tipo logica");
                                            } else { 
                                                $$.t = $2.t;
                                                $$.v = !$2.v;
                                            }  
                                        } 
                                        else {
                                            if ($2.t != T_ENTERO) {
                                                $$.t = T_ERROR;
                                                yyerror("expresion unaria no valida para la expresion unaria : se espera una expresion unaria de tipo entera");
                                            } else { 
                                                $$.t = $2.t;
                                                if($1 == MAS_)
                                                {
                                                    $$.v = $2.v;
                                                } else
                                                {
                                                    $$.v = -$2.v;
                                                } 
                                            } 
                                        }                                     
                                    }                                   
                                } 
                                | operadorIncremento ID_ {
                                    //$$.t = T_ERROR;
                                    SIMB simb = obtTdS($2);
                                    if (simb.t == T_ERROR) {
                                        $$.t = T_ERROR;
                                        yyerror("identificador no declarado : declarelo antes de utilizarlo");
                                    }
                                    else{
                                        $$.t = simb.t;
                                        if($1 == INC_)
                                            $$.v = $$.v + 1;
                                        else
                                            $$.v = $$.v - 1;
                                    }                                                   
                                } 
                                ;
                                

expresionSufija                 : APAREN_ expresion CPAREN_{
                                        printf("\tEXPRESION ------------ %d,\n",$2.t);
                                        yyerror("\n");
                                        $$.t = $2.t;
                                        $$.v = $2.v;
                                    }
                                | ID_ operadorIncremento{
                                        //$$.t = T_ERROR;
                                        SIMB simb = obtTdS($1);
                                        if(simb.t == T_ERROR){
                                            $$.t = T_ERROR;
                                            yyerror("identificador no declarado.");
                                        }else if(simb.t != T_ENTERO){
                                            $$.t = T_ERROR;
                                            yyerror("identificador no valido, unicamente valido con tipo int");
                                        }else{
                                            $$.t = simb.t;
                                            $$.v = $$.v +1;
                                        }
                                    }
                                | ID_ ACORCH_ expresion CCORCH_{
                                        //$$.t = T_ERROR;
                                        SIMB simb = obtTdS($1);
                                        if(simb.t == T_ERROR){
                                            $$.t = T_ERROR;
                                            yyerror("identificador no declarado.");
                                        }else if(simb.t != T_ERROR){
                                            if($3.t != T_ENTERO){
                                                $$.t = T_ERROR;
                                                yyerror("expresion no valida : se espera tipo int");
                                            }
                                            if(simb.t != T_ARRAY){
                                                $$.t = T_ERROR;
                                                yyerror("identificador no valido : se espera tipo array");
                                            }
                                            if($3.t == T_ENTERO && simb.t == T_ARRAY){
                                                    $$.t = simb.t;
                                            } 
                                        }
                                    }
                                | ID_ APAREN_ parametrosActuales CPAREN_{
                                        //$$.t = T_ERROR;
                                        SIMB simb = obtTdS($1);
                                        if(simb.t != T_ENTERO && simb.t != T_LOGICO){
                                            $$.t = T_ERROR;
                                            yyerror("inconsistencia de tipos : identificador y parametros actuales no son del mismo tipo");
                                        }else if(simb.t != $3){
                                            $$.t = T_ERROR;
                                            yyerror("identificador no valido : no corresponde con el tipo de parametros actuales");
                                        }else{
                                            $$.t = simb.t;
                                        }
                                    }
                                | ID_ {
                                        //$$.t = T_ERROR;
                                        SIMB simb = obtTdS($1);
                                        if (simb.t == T_ERROR) {
                                            $$.t = T_ERROR;
                                            yyerror("identificador no declarado : declarelo antes de utilizarlo");
                                        } 
                                        else {
                                            $$.t = simb.t;
                                        }
                                    }
                                | constante{
                                        $$.t = $1.t;
                                        $$.v = $1.v;
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
                                    $$.v = $1;
                                }
                                | TRUE_   {
                                    $$.t = T_LOGICO;
                                    $$.v = 1;
                                }
                                | FALSE_  {
                                    $$.t = T_LOGICO;
                                    $$.v = 0;
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
