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
%}

%union{
    char *ident; //NOMBRE DEL IDENTIFICADOR
    int cent;    //VALOR DE LA CTE NUMERICA ENTERA
    EXP exp;     //TIPO PARA LAS EXPRESIONES
}

%token <cent> INT_ ID_ CTE_ BOOL_ 
%type <cent> parametrosFormales parametrosActuales listaParametrosActuales

%token WHILE_ FOR_ IF_ ELSE_ TRUE_ FALSE_ PRINT_ READ_ RETURN_
%token ALLAVE_  CLLAVE_ ACORCH_  CCORCH_ APAREN_ CPAREN_ PTOCOMA_ PTO_ CMA_
%token MAS_ MENOS_ POR_ DIV_
%token AND_ OR_ SUMASIG_ RESASIG_ MULASIG_ DIVASIG_ IGU_ NOIGU_ MAYIGU_ MENIGU_ INC_ DEC_  MAY_ MEN_ ASIG_ NOT_ MOD_

%type<ident> declaracionVariable listaParametrosFormales

%type <exp> programa listaDeclaraciones declaracion instruccion expresion
%type <exp> expresionIgualdad expresionAditiva expresionRelacional expresionOpcional
%type <exp> expresionMultiplicativa expresionUnaria expresionSufija constante

%type <cent> tipoSimple operadorAditivo operadorIgualdad operadorIncremento
%type <cent> operadorLogico operadorMultiplicativo operadorRelacional operadorUnario
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
                                        if(!insTdS($1.n,1,$1.t,n,desp,-1)){
                                            yyerror("identificador ya existente : utilice otro nombre");
                                        } else{
                                            dvar += $1.talla;
                                        }
                                    }
                                | declaracionFuncion
                                ;

declaracionVariable             : tipoSimple ID_ PTOCOMA_{
                                        if(insTdS($2,VARIABLE,$1,niv,vdar,-1)){
                                            dvar += TALLA_TIPO_SIMPLE;
                                        }else{
                                            yyerror("La variable ya ha sido declarada");
                                        }
                                    }
                                | tipoSimple ID_ ACORCH_ CTE_ CCORCH_ PTOCOMA_{
                                        int numelem = $4;
                                        if($4 <= 0){
                                            yyerror("Talla no apropiada para array");
                                            numelem = 0;
                                        }
                                        int refe = insTdA($1, numelem);
                                        if(instTdS($2,VARIABLE,T_ARRAY,niv,dvar,refe)){
                                            dvar += numelem * TALLA_TIPO_SIMPLE;
                                        }else{
                                            yyerror("Identificador repetido")
                                        }
                                    }
                                ;

tipoSimple                      : INT_ {$$.t = $1.t;}
                                | BOOL_{$$.t = $1.t;}
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
                                        dvar += 0;
                                    }
                                | listaParametrosFormales{
                                        $$.t = $1.t;
                                        dvar += TALLA_SEGENLACES;
                                    }
                                ;

listaParametrosFormales         : tipoSimple ID_
                                    {
                                        $$.n = $2.n;
                                        $$.t = $2.t;
                                    }
                                | tipoSimple ID_ CMA_ listaParametrosFormales
                                    {
                                        if( obtTdS($2.n, $2.t)  && ($2.t = tvector($2.nel )) && ($4.t = tentero)){
                                            $$.t = T_ERROR;
                                            yerror("Error de tipos en la 'instruccion de lista de parametros'");
                                        }else{
                                            $$.t = $2.tel;
                                        }
                                    }
                                ;
//  listaParametrosFormales         : tipoSimple ID_
//                             {
//                               $$.t = T_ERROR;
//                               SIMB simb = obtTdS($1);
//                               if(simb.t == T_ERROR){
//                                 yyerror("identificador no declarado.");
//                               }else{
//                                 if(simb.t == INT_ ||simb.t == BOOL_){
//                                 $$.t = simb.t;
//                               }else{yyerror("Error de tipo en el identificador.");}
//                               }
//                             }
//                             | tipoSimple ID_ CMA_ listaParametrosFormales
//                             {
//                               $$.t = T_ERROR;
//                               SIMB simb = obtTdS($1);
//                               if(simb.t == T_ERROR){
//                                 yyerror("identificador no declarado.");
//                               }else{
//                                 if(simb.t == INT_ ||simb.t == BOOL_){
//                                       $$.t = simb.t;
//                               }else{yyerror("Error de tipo en el identificador.");}
//                               }
//                             };

bloque                          : {
                                    niv++;
                                    cargaContexto(niv);
                                    //D.aux = dvar; dvar = 0;
                                    }
                                | ALLAVE_ declaracionVariableLocal listaInstrucciones RETURN_ expresion PTOCOMA_ CLLAVE_{
                                    niv--;
                                    descargaContexto(niv);
                                    //dvar = D.aux;
                                }
                                ;

declaracionVariableLocal        : /* vacio */ { }
                                | declaracionVariableLocal declaracionVariable{
                                        if(insTdS($2,VARIABLE,$2,n,dvar,-1)){
                                          dvar += TALLA_TIPO_SIMPLE;
                                        }
                                    }
                                ;

listaInstrucciones              : /* vacio */
                                | listaInstrucciones instruccion
                                ;

instruccion                     : ALLAVE_ listaInstrucciones CLLAVE_
                                | instruccionAsignacion
                                | instruccionSeleccion
                                | instruccionEntradaSalida
                                | instruccionIteracion
                                ;

instruccionAsignacion           : ID_ ASIG_ expresion PTOCOMA_
                                    {
                                        SIMB simb = obtTdS($1);
                                        if(simb.t == T_ERROR)
                                            yyerror("Objeto no declarado");
                                        else if (! ((simb.t == $3.t == T_ENTERO) ||
                                                (simb.t == $3.t == T_LOGICO)))
                                            yerror("Error de tipos en la 'instruccion de asignacion'");
                                    }
                                | ID_ ACORCH_ expresion CCORCH_ ASIG_ expresion PTOCOMA_
                                    {
                                        SIMB simb = obtTdS($1);
                                        if(simb.t == T_ERROR)
                                            yyerror("Objeto no declarado");
                                        else if (! ((simb.t == $3.t == T_ENTERO) ||
                                                (simb.t == $3.t == T_LOGICO)))
                                            yerror("Error de tipos en la 'instruccion de asignacion'");
                                    }
                                ;

instruccionEntradaSalida        : READ_ APAREN_ ID_ CPAREN_ PTOCOMA_{

                                    }
                                | PRINT_ APAREN_ expresion CPAREN_ PTOCOMA_{

                                    }
                                ;

instruccionSeleccion            : IF_ APAREN_ expresion CPAREN_ instruccion ELSE_ instruccion
                                ;

// instruccionIteracion            : FOR_ APAREN_ expresionOpcional PTOCOMA_ expresion PTOCOMA_ expresionOpcional CPAREN_ instruccion
//                                     {
//                                         int numelem = $7;
//                                         if($7 <= 0){
//                                             yyerror("Talla no apropiada para array");
//                                             numelem = 0;
//                                         }
//                                         if($3.t != T_ENTERO || $5.t != T_ENTERO || $7.t != T_ENTERO){
//                                             yyerror("El iterador tiene que ser un entero");
//                                         }
//                                         $$ = $7 + 1;
//                                     }
//                                 ;

instruccionIteracion            : FOR_ APAREN_ expresionOpcional PTOCOMA_ expresion PTOCOMA_ expresionOpcional CPAREN_ instruccion
                                    {
                                        if($5.t == T_LOGICO){
                                            if(($3.t != T_ERROR || $3.t == T_VACIO ) && ($7.t != T_ERROR || $7.t == T_VACIO )){

                                            }else{
                                            yyerror("Error>Instrucción iteracción FOR : instrucción mal formada");
                                            }
                                        }else{
                                            yyerror("Error>Instrucción iteracción FOR : error en el operador lógico");
                                        }
                                    }
                      ;

expresionOpcional               : /* vacı́o */
                                | expresion
                                | ID_ ASIG_ expresion
                                ;

expresion                       : expresionIgualdad
                                | expresion operadorLogico expresionIgualdad
                                ;

expresionIgualdad               : expresionRelacional
                                | expresionIgualdad operadorIgualdad expresionRelacional
                                ;

expresionRelacional             : expresionAditiva { $$ = $1; }
                          | expresionRelacional operadorRelacional expresionAditiva
                          {
                             $$.tipo = T_ERROR;
                             if($1.t != T_ERROR && $3.t != T_ERROR){
                              if ($1.t != $3.t) {
                                  yyerror("la operación se está realizando con dos tipos de datos distintos");
                              }else
                              {
                                if ($2.t != T_LOGICO) {
                                     yyerror("expresion no valida : se espera una operación relacional");
                                }else{

                                    if ($1.t == T_ENTERO && $3.t == T_ENTERO ) {
                                        $$.t = T_ENTERO;

                                        if ($2 == MAY_ ){
                                          /* $$.v = 0;
                                          if ($1 > $2 )
                                           $$.v = 1;*/
                                        }else if ($2 == MEN_ ){
                                          /*   $$.v = 0;
                                          if ($1 < $2 )
                                           $$.v = 1;*/
                                        }else if ($2 == MAYIGU_ ){
                                          /*   $$.v = 0;
                                          if ($1 >= $2 )
                                           $$.v = 1;*/
                                        }else if ($2 == MENIGU_ ){
                                          /*   $$.v = 0;
                                          if ($1 <= $2 )
                                           $$.v = 1; */
                                        }else{
                                          $$.t = T_ERROR;
                                          yyerror("Error : El operador no se corrsponde con el operadorRelacional");
                                        }


                                    }else{
                                         yyerror("expresion no valida : se espera una operación relacional");
                                    }
                                }
                              }
                            }else {yyerror("Uno o más opeandos contiene un error de tipo");}
  };

expresionAditiva                : expresionMultiplicativa   { $$ = $1; }
                                | expresionAditiva operadorAditivo expresionMultiplicativa
                                    {
                                        $$.tipo = T ERROR;
                                        if ($1.tipo == $3.tipo == T_ENTERO) $$.tipo = T_ENTERO;
                                        else yyerror("Error de tipos en la ‘expresi´on aditiva’");
                                        $$.d = creaVarTemp();
                                        emite($2, crArgPos(niv, $1.d), crArgPos(niv, $3.d), crArgPos(niv, $$.d));
                                    }
                                ;
// expresionAditiva                : expresionMultiplicativa { $$ = $1; }
//     | expresionAditiva operadorAditivo expresionMultiplicativa
//       {
//          $$.tipo = T_ERROR;
//          if($1.t != T_ERROR && $3.t != T_ERROR){
//           if ($1.t != $3.t) {
//               yyerror("la operación se está realizando con dos tipos de datos distintos");
//           }else
//           {
//             if ($1.t != T_ENTERO) {
//                  yyerror("expresion no valida : se espera tipo int");
//             }else{
//                 $$.t =   T_ENTERO;
//
//                 if ($2 == MAS_ ){
//                   //  $$.v = $1.v + $3.v;
//                 }else if ($2 == MENOS_ ){
//                   //  $$.v = $1.v - $3.v;
//                 }else{
//                   $$.t =   T_ERROR;
//                   yyerror("Error : El operador no se corrsponde con el operadorAditivo");
//                 }
//
//
//             }
//           }
//         }else {yyerror("Uno o más opeandos contiene un error de tipo");}
// };

expresionMultiplicativa         : expresionUnaria
                                | expresionMultiplicativa operadorMultiplicativo expresionUnaria
                                ;

expresionUnaria                 : expresionSufija
                                | operadorUnario expresionUnaria
                                | operadorIncremento ID_
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
                                            if($3 != T_ENTERO){
                                                yyerror("expresion no valida : se espera tipo int");
                                            }
                                            if(simb.t != T_ARRAY){
                                                yyerror("identificador no valido : se espera tipo array");
                                            }
                                            if($3 == T_ENTERO && simb.t == T_ARRAY){
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
                                        } else {
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

listaParametrosActuales         : expresion
                                | expresion CMA_ listaParametrosActuales
                                ;


constante                       : CTE_    {$$ = $1}
                                | TRUE_   {$$ = T_LOGICO}
                                | FALSE_  {$$ = T_LOGICO}
                                ;

// operadorLogico                  :AND_{
//                                     if($1 == $2){
//                                         if($1.n == $2.n){
//                                             $$.n = TRUE_;
//                                         }else {
//                                             $$.n = FALSE_;
//                                         }
//                                     }else{
//                                         yyerror("identificador de tipos diferentes : tienen que ser del mismo tipo");
//                                     }
//                                 }
//                                 |OR_{
//                                     if( $1.t == $2.t){
//                                         if( ($1.t == T_VACIO && $2.t != T_VACIO) || ($1.t == T_VACIO && $2.t != T_VACIO) ){
//                                             $$.t = $2.t;
//                                         }
//                                         else{
//                                             if($1.t != T_VACIO && $2.t == T_VACIO){
//                                                 $$.t = $1.t;
//                                             }
//                                             else {
//                                                 $$.t = T_VACIO;
//                                             }
//                                         }
//                                     }
//                                     else{
//                                         yyerror("identificador de tipos diferentes : tienen que ser del mismo tipo");
//                                     }
//                                 }
//                                 ;

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

operadorAditivo                 : MAS_      { $$ = ESUM; }
                                | MENOS_    { $$ = EDIF; }
                                ;

operadorMultiplicativo          : POR_      { $$ = EMULT; }
                                | DIV_      { $$ = EDIVI; }
                                ;

operadorUnario                  : MAS_      { $$ = ESUM; }
                                | MENOS_    { $$ = EDIF; }
                                | NOT_
                                ;

operadorIncremento              : INC_
                                | DEC_
                                ;

%%
