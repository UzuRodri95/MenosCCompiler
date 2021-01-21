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
#include "libgci.h"

#define GLOBAL 0
#define LOCAL 1

int dvar;
int niv;
int si;

%}

%union{
    char *ident; //NOMBRE DEL IDENTIFICADOR
    int cent;    //VALOR DE LA CTE NUMERICA ENTERA
    EXP exp;     //PARA LAS EXPRESIONES
    STR str;     //PARA LOS ELEMENTOS CON TALLA
    REFES refe;   // Para el "for" con 3 atributos simples    
}

%token WHILE_ FOR_ IF_ ELSE_  PRINT_ READ_ RETURN_ 
%token ALLAVE_  CLLAVE_ ACORCH_  CCORCH_ APAREN_ CPAREN_ PTOCOMA_ PTO_ CMA_
%token <cent>  MAS_ MENOS_ POR_ DIV_
%token <cent>  AND_ OR_ SUMASIG_ RESASIG_ MULASIG_ DIVASIG_ IGU_ NOIGU_ MAYIGU_ MENIGU_ INC_ DEC_  MAY_ MEN_ ASIG_ NOT_ MOD_

%token <cent> INT_ BOOL_ CTE_ TRUE_ FALSE_
 
%type <cent> operadorAditivo operadorIgualdad operadorIncremento
%type <cent> operadorLogico operadorMultiplicativo operadorRelacional operadorUnario

%token <ident> ID_ 

%type <exp> programa listaDeclaraciones 
  
%type <str> tipoSimple listaParametrosFormales parametrosFormales declaracionVariable listaParametrosActuales declaracionFuncion 
%type <str> declaracionVariableLocal cabeceraFuncion parametrosActuales

%type <str> constante expresion expresionIgualdad expresionRelacional expresionAditiva expresionMultiplicativa expresionSufija
%type <str> expresionUnaria instruccionAsignacion instruccionEntradaSalida instruccionSeleccion instruccionIteracion
%type <str> instruccion listaInstrucciones expresionOpcional declaracion 
%%

programa                        :{ niv = GLOBAL; 
                                   dvar = 0; 
                                   si=0;
                                   cargaContexto(niv); 

                                   $<refe>$.ref1 = creaLans(si);
                                   emite(INCTOP,crArgNul(),crArgNul(),crArgEnt(-1));
                                   
                                   $<refe>$.ref2 = creaLans(si);
                                   emite(GOTOS,crArgNul(),crArgNul(),crArgEnt(-1));
                                    
                                } listaDeclaraciones { 
                                    if($2.t == 0) yyerror("El programa no tiene main. 2");   

                                    completaLans($<refe>1.ref1,crArgEnt(dvar));
                                    
                                    SIMB simb =  obtTdS("main");

                                    completaLans($<refe>1.ref2,crArgEnt(simb.d));
                                }
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
                                        //if(insTdS($2,VARIABLE,$1.t,niv,dvar,-1)){
                                            $$.n = $2;
                                            $$.talla = TALLA_TIPO_SIMPLE;
                                            $$.t = $1.t;
                                        //    dvar +=  $1.talla; 
                                            
                                        /**}else{  
                                            $$.t = T_ERROR;
                                            yyerror("Identificador repetido");
                                        } **/
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

declaracionFuncion              : cabeceraFuncion { 
                                    $<cent>$ = dvar; 
                                    dvar = 0; 
                                    
                                } bloque {       
                                    if(verTdS == TRUE) mostrarTdS();
                                    descargaContexto(niv);
                                    niv = GLOBAL;
                                     dvar = $<cent>2;
                                }
                                ;

cabeceraFuncion                 : tipoSimple ID_ { niv = LOCAL; cargaContexto(niv);  } APAREN_ parametrosFormales CPAREN_{
                                        if(insTdS($2,FUNCION,$1.t, GLOBAL, si, $5.t)){
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
                                        $$.t = insTdD(-1,T_VACIO);
                                        $$.talla = 0;
                                    }
                                | listaParametrosFormales{
                                        $$.t = $1.t;
                                        $$.talla =  $$.talla - TALLA_SEGENLACES;
                                    }
                                ;

listaParametrosFormales         : tipoSimple ID_{
                                    $$.t = insTdD(-1,$1.t);
                                    $$.talla = TALLA_SEGENLACES + $1.talla;
                                    int ref = insTdD(-1,$1.t);
                                    $$.refe = ref; 
                                    insTdS($2,PARAMETRO,$1.t,niv,-$$.talla,ref);
                                }
                                | tipoSimple ID_ CMA_ listaParametrosFormales{
                                     if($1.t == $4.t && $1.t != T_ERROR){
                                         $$.t = insTdD($4.t, $1.t);
                                         $$.talla = $4.talla + $1.talla;
                                         
                                         int ref = insTdD($4.refe, $1.t);
                                         insTdS($2,PARAMETRO,$1.t,niv,-$$.talla,ref);
                                     }
                                }
                                ;

bloque                          : {
                                    /* vacio */
                                }
                                | ALLAVE_{
                                    
                                    emite(PUSHFP, crArgNul(), crArgNul(), crArgNul());
                                    emite(FPTOP, crArgNul(), crArgNul(), crArgNul());
                                        
                                    $<cent>$ = creaLans(si);
                                    emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(-1));
                                         
                                }  declaracionVariableLocal listaInstrucciones RETURN_ expresion  PTOCOMA_ CLLAVE_ {
                                   INF inf  = obtTdD(-1);

                                   int dvret = TALLA_SEGENLACES + inf.tsp +TALLA_TIPO_SIMPLE;    
                                    
                                   emite(EASIG,crArgPos(niv,$6.d),crArgNul(),crArgPos(niv,-dvret));
                                   completaLans($<cent>2,crArgEnt(dvar));
                                        

                                   emite(TOPFP, crArgNul(), crArgNul(), crArgNul());
                                   emite(FPPOP, crArgNul(), crArgNul(), crArgNul());
                                   emite(RET, crArgNul(), crArgNul(), crArgNul());
                                }
                                ;

declaracionVariableLocal        : /* vacio */ {
                               
                                }
                                | declaracionVariableLocal declaracionVariable{
                                    
                                        if(insTdS($2.n,VARIABLE,$2.t,niv,dvar,-1)){
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
                                            emite(EASIG, crArgPos(niv,$3.d), crArgNul(), crArgPos(niv,simb.d));
                                        }
                                        
                                        if($$.t == T_ERROR){
                                            yyerror("Objeto no declarado");
                                        } 
                                    }
                                | ID_ ACORCH_ expresion CCORCH_ ASIG_ expresion PTOCOMA_{
                                        SIMB simb = obtTdS($1);
                                        DIM tabla = obtTdA(simb.ref);
                                        
                                        if(simb.t == T_ERROR){
                                            $$.t = T_ERROR;
                                        }
                                        else if(! ($3.t == T_ENTERO)){
                                            $$.t = T_ERROR;
                                        } 
                                        else if (! (tabla.telem == $6.t)){
                                            $$.t = T_ERROR;
                                        }
                                        else if( ! (simb.t == T_ARRAY)){
                                            $$.t = T_ERROR;
                                        }
                                        else{
                                            $$.t = simb.t;
                                        }  

                                        if($$.t == T_ERROR){
                                            yyerror("Error instrucción asignación F");
                                        }else {
                                            emite(EASIG, crArgPos(niv, $3.d * simb.t ), crArgNul(), crArgPos(niv, $3.d));
                                            emite(EVA, crArgPos(niv,simb.d ), crArgPos(niv, $3.d), crArgPos(niv, $6.d));
                                        }   
                                            
                                    }
                                ;

instruccionEntradaSalida        : READ_ APAREN_ ID_ CPAREN_ PTOCOMA_{
                                    SIMB sim = obtTdS($3);
                                    if (sim.t != T_ENTERO) {
                                        $$.t = T_ERROR;
                                        yyerror("Identificador no valido para la instruccion entrada : se esperaba identificador entero");
                                    }
                                    else{
                                        $$.t = sim.t;
                                        emite(EREAD, crArgNul(), crArgNul(), crArgPos(niv, sim.d));
                                    }  
                                }
                                | PRINT_ APAREN_ expresion CPAREN_ PTOCOMA_{
                                    if ($3.t == T_ERROR) { 
                                       $$.t = T_ERROR;
                                    }else if ($3.t != T_ENTERO) {
                                        $$.t = T_ERROR;    
                                    }
                                    else{
                                        $$.t = $3.t;
                                        emite(EWRITE, crArgNul(), crArgNul(), crArgPos(niv,$3.d));
                                    }

                                    if($$.t == T_ERROR){
                                      
                                        yyerror("Expresion no valida para la instruccion salida(PRINT) : se esperaba expresion entera");
                                    } 
                                }
                                ;

instruccionSeleccion            : IF_ APAREN_ expresion CPAREN_ {
                                        if($3.t != T_LOGICO){
                                            yyerror("Expresion no valida para la instruccion seleccion : se esperaba una expresion logica");
                                        }

                                        //S.lf, $<cent>5
                                        $<cent>$ = creaLans(si);
                                        emite(EIGUAL, crArgPos(niv,$3.d), crArgEnt(0), crArgEtq(-1));
                                    } instruccion {
                                        //S.fin, $<cent>7
                                        $<cent>$ = creaLans(si);
                                        emite(GOTOS, crArgNul(),  crArgNul(), crArgEtq(-1)); 
                                        completaLans($<cent>5, crArgEtq(si)); //Posible error crArgEtq por crArgEnt
                                    }ELSE_ instruccion{
                                        completaLans($<cent>7, crArgEtq(si)); //Posible error crArgEtq por crArgEnt
                                    }
                                ;

instruccionIteracion            : FOR_ APAREN_ expresionOpcional PTOCOMA_ { 
                                    $<cent>$ = si; /*$5*/ 
                                    } 
                                    expresion PTOCOMA_ {
                                        if($6.t != T_LOGICO){
                                            //$$.t = T_ERROR;
                                            yyerror("Expresion no valida en el for.");
                                        }else{
                                            //$$.t = $3.t;
                                            //S.lv
                                            $<refe>$.ref1  = creaLans(si); //$8    
                                          

                                            emite(EIGUAL,crArgPos(niv,$6.d),crArgEnt(1),crArgEtq(-1));

                                            //S.lf 
                                            $<refe>$.ref2  = creaLans(si); //$8 
                                            
                                            emite(GOTOS,crArgNul(),crArgNul(),crArgEtq(-1));
                                          
                                            //S.aux = si
                                            $<refe>$.ref3 = si; //$8
                                            
                                        }    
                                    }
                                    expresionOpcional CPAREN_ {
                                      
                                        emite(GOTOS,crArgNul(),crArgNul(),crArgEtq($<cent>5)); //Posible error crArgEtq por crArgEnt
                                        completaLans($<refe>8.ref1 , crArgEtq(si)); //Posible error crArgEtq por crArgEnt
                                    }
                                    instruccion {
                                        emite(GOTOS,crArgNul(),crArgNul(),crArgEtq($<refe>8.ref3)); //Posible error crArgEtq por crArgEnt
                                        completaLans($<refe>8.ref2 , crArgEtq(si)); //Posible error crArgEtq por crArgEnt
                                         
                                    }
                                       
                                    
                                        

expresionOpcional               : /* vacı́o */{
                                    $$.t = T_VACIO;

                                }
                                | expresion{
                                    $$.t = $1.t;
                                }
                                | ID_ ASIG_ expresion{

                                    
                                   
                                    SIMB simb = obtTdS($1);

                                    //yyerror("opcional");
                                   // printf("Valor ID.t=%d, valor $3.d=%d:",simb.t,$3.t);
                                     
                                    if (simb.t == T_ERROR) {
                                        $$.t = T_ERROR;
                                    } 
                                    else{
                                        if ($3.t != T_ERROR) {
                                           
                                            if((simb.t != $3.t) || (simb.t == $3.t && simb.t != T_ENTERO && simb.t != T_LOGICO)) {
                                                $$.t = T_ERROR;
                                                       
                                            } 
                                            else {
                                         
                                                $$.t = $3.t;
                                                // Id = E
                                                emite(EASIG, crArgPos(niv,$3.d),crArgNul(), crArgPos(niv,simb.d));
                                            }
                                        }
                                    } 
                                    if($$.t == T_ERROR){
                                        yyerror("Error en expresión opcional");
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
                                      //yyerror(".");
                                      //printf("t1  : %d, t2 %d ",$1.t,$3.t);
                                    if ($1.t != T_ERROR && $3.t != T_ERROR) {
                                        if ($1.t != T_LOGICO) {
                                            $$.t = T_ERROR;
                                        } else if ($3.t != T_LOGICO){
                                            $$.t = T_ERROR;
                                        } else if ($1.t != $3.t) {
                                            $$.t = T_ERROR;
                                        }else{
                                            $$.t = T_LOGICO;
                                        } 
                                    } 
                                    else { 
                                        $$.t = T_LOGICO; 
                                        // 1º Sumar
                                        $$.d = creaVarTemp();
                                        if($2 == AND_ )
                                        {                                        
                                          emite($2, crArgPos(niv,$1.d),crArgPos(niv,$3.d),  crArgPos(niv,$$.d));      
                                        }else
                                        {
                                          emite($2, crArgPos(niv,$1.d),crArgPos(niv,$3.d),  crArgPos(niv,$$.d));                                           
                                          
                                          emite(EMENEQ, crArgPos(niv,$$.d),crArgEnt(1),  crArgEtq(si +2)); 
                                          emite(EASIG, crArgEnt(1),crArgNul(), crArgPos(niv,$$.d));
                                        } 
                                       
                                                                        
                                    }   

                                }
                                ;

expresionIgualdad               : expresionRelacional{
     
                                    if($1.t != T_LOGICO && $1.t != T_ENTERO)
                                    {   
                                        $$.t = T_ERROR;
                                       
                                                                       
                                    } 
                                    else
                                    {
                                        $$.t = $1.t;
                                    }  
                                        
                                }
                                | expresionIgualdad operadorIgualdad expresionRelacional{
                                      
                                    if ($1.t == T_ERROR && $3.t == T_ERROR) {
                                        if ($1.t != T_LOGICO && $1.t != T_ENTERO ) {
                                            $$.t = T_ERROR;
                                        } else if ($3.t != T_LOGICO && $3.t != T_ENTERO) {
                                            $$.t = T_ERROR;
                                        } else if ($1.t != $3.t) {
                                            $$.t = T_ERROR;
                                        }
                                    } 
                                    else {
                                        $$.t = T_LOGICO;
                                        $$.d = creaVarTemp();
                                     
                                        emite($2, crArgPos(niv,$1.d),crArgPos(niv,$3.d),  crArgPos(niv,$$.d));

                                    } 

                                                                      
                                }
                                ;

expresionRelacional             : expresionAditiva {
                                    $$.t = $1.t;
                                 
                                }
                                | expresionRelacional operadorRelacional expresionAditiva{
                                    if ($1.t != T_ERROR && $3.t != T_ERROR) {
                                        if ($1.t == T_ENTERO && $1.t==$3.t) {
                                              $$.t = T_LOGICO;
                                              $$.d = creaVarTemp();
                                              emite($2, crArgPos(niv,$1.d),crArgPos(niv,$3.d),  crArgPos(niv,$$.d));
                                        } 
                                        else { 
                                            $$.t = T_ERROR;
                                        }                                      
                                    }
                                   
                                };

expresionAditiva                : expresionMultiplicativa   {
                                    $$.t = $1.t;
                                       
                                }
                                | expresionAditiva operadorAditivo expresionMultiplicativa{
                                    if ($1.t == $3.t && $3.t == T_ENTERO){
                                        $$.t = T_ENTERO;
                                        $$.d = creaVarTemp();
                                        emite($2, crArgPos(niv,$1.d),crArgPos(niv,$3.d),  crArgPos(niv,$$.d));
                                    } 
                                    else{
                                        $$.t = T_ERROR;
                                        //if($3.t == T_ENTERO) yyerror("Error de tipos en la expresion multiplicativa");
                                        //else yyerror("Error de tipos en la expresion aditiva");
                                        
                                        
                                    }
                                }
                                ;

expresionMultiplicativa         : expresionUnaria{
                                        $$.t = $1.t;
                                     
                                }
                                | expresionMultiplicativa operadorMultiplicativo expresionUnaria{
                                    if ($1.t == T_ENTERO && $3.t == T_ENTERO) {
                                        $$.t = $1.t;   

                                        $$.d = creaVarTemp();
                                        emite($2, crArgPos(niv,$1.d),crArgPos(niv,$3.d),  crArgPos(niv,$$.d));


                                    }
                                    else{
                                        $$.t = T_ERROR;
                                    }                                
                                    
                                   
                                }
                                ;

expresionUnaria                 : expresionSufija{
                                    $$.t = $1.t;
                                     
                                }
                                | operadorUnario expresionUnaria {
                                    
                                    if ($2.t != T_ERROR) {

                                     //          yyerror(".");
                                    //printf("$1: %s ",NOT_);
                                      //printf("$1: %d ",$1 );
                                        if ( $1 == NOT) {
                                            if ($2.t != T_LOGICO) {
                                                $$.t = T_ERROR;
                                                
                                            } else { 
                                                $$.t = $2.t;                                                
                                        
                                                $$.d = creaVarTemp();
                                                emite(EDIF,  crArgEnt(1),crArgPos(niv,$2.d), crArgPos(niv,$$.d));
                                                
                                            }  
                                        } 
                                        else {
                                            if ($2.t != T_ENTERO) {
                                                $$.t = T_ERROR;
                                            } else { 
                                                $$.t = $2.t;
                                                $$.d = creaVarTemp();
                                                emite($1, crArgEnt(0), crArgPos(niv,$2.d), crArgPos(niv,$$.d));
                                            } 
                                        }                                     
                                    }                                
                                } 
                                | operadorIncremento ID_ {
                                    SIMB simb = obtTdS($2);
                                    if (simb.t == T_ERROR) {
                                        $$.t = T_ERROR;
                                        
                                    }
                                    else{
                                        $$.t = simb.t;

                                        $$.d = creaVarTemp();
                                        emite($1, crArgPos(niv,simb.d), crArgEnt(1), crArgPos(niv,simb.d));
                                        emite(EASIG, crArgPos(niv,simb.d), crArgNul(), crArgPos(niv,$$.d));
                                    }     
                                                                               
                                } 
                                ;
                                
expresionSufija                 : APAREN_ expresion  CPAREN_{
                                        $$.t = $2.t;                                        
                                        $$.d = $2.d;
                                        
                                    }
                                | ID_ operadorIncremento{
                                        SIMB simb = obtTdS($1);
                                        if(simb.t == T_ERROR){
                                            $$.t = T_ERROR;
                                            //yyerror("Identificador no declarado.");
                                        }else if(simb.t != T_ENTERO){
                                            $$.t = T_ERROR;
                                            //yyerror("Identificador no valido, unicamente valido con tipo int");
                                        }else{
                                            $$.t = simb.t;

                                            $$.d = creaVarTemp();
                                           
                                            emite(EASIG, crArgPos(niv,simb.d), crArgNul(), crArgPos(niv,$$.d));
                                            emite($2, crArgPos(niv,simb.d), crArgEnt(1), crArgPos(niv,simb.d));
                                         
                                        }

                                        if($$.t == T_ERROR){
                                            //yyerror("Error en expresión sufija.");
                                        }
                                    } 
                                    
                                | ID_ ACORCH_ expresion CCORCH_{
                                        SIMB simb = obtTdS($1);
                                        if(simb.t == T_ERROR){
                                            $$.t = T_ERROR;
                                        }else if(simb.t != T_ERROR){
                                            if($3.t != T_ENTERO){
                                                $$.t = T_ERROR;
                                            }
                                            if(simb.t != T_ARRAY){
                                                $$.t = T_ERROR;
                                            }
                                            if($3.t == T_ENTERO && simb.t == T_ARRAY){
                                                    DIM dim =  obtTdA(simb.ref);
                                                    $$.t = dim.telem;
                                                    
                                                    emite(EASIG, crArgPos(niv,$3.d * $3.talla), crArgNul(), crArgPos(niv,simb.d));
                                                    $$.d = creaVarTemp();
                                                   
                                                    emite(EAV, crArgPos(niv,simb.d), crArgPos(niv,$3.d), crArgPos(niv,$$.d));                                                    
                                            } 
                                        }
                                        
                                    } 
                                
                                | ID_ APAREN_{ 
                                    emite(INCTOP,crArgNul(),crArgNul(),crArgEnt(TALLA_TIPO_SIMPLE)); 
                                }  parametrosActuales CPAREN_{
                                        SIMB simb = obtTdS($1);
                                        if(simb.t == T_ERROR){
                                            $$.t = T_ERROR;
                                        }else{
                                            INF comprobar = obtTdD(simb.ref); 
                                            if(comprobar.tipo ==  T_ERROR){
                                                $$.t = T_ERROR;
                                            }
                                            else if(comprobar.tipo != $4.t){ // ¿$4?
                                                $$.t = T_ERROR;
                                               
                                            }
                                            else{
                                                $$.t = comprobar.tipo;
                                                $$.talla = comprobar.tsp;                                             
                                                
                                                //emite(EPUSH,crArgNul(),crArgNul(),crArgEnt(si+2));
                                                emite(CALL,crArgNul(),crArgNul(),crArgEtq(simb.d)); // ¿?¿?¿?¿?¿? .ref
                                                emite(DECTOP,crArgNul(),crArgNul(),crArgEnt(comprobar.tsp));

                                                $$.d = creaVarTemp();
                                                emite(EPOP,crArgNul(),crArgNul(),crArgPos(niv,$$.d));

                                               
                                            } 
                                            
                                        } 
                                    }
                                | ID_ {
                                        SIMB simb = obtTdS($1);
                                        if (simb.t == T_ERROR) {
                                            $$.t = T_ERROR;
                                            //yyerror("Identificador no declarado : declarelo antes de utilizarlo");
                                        } 
                                        else {
                                            $$.t = simb.t;
                                            $$.d = creaVarTemp();
                                            emite(EASIG,crArgPos(niv,simb.d),crArgNul(),crArgPos(niv,$$.d));
                                        }
                                    }
                                | constante{
                                        $$.t = $1.t;
                                        $$.d = creaVarTemp();
                                        emite(EASIG,crArgPos(niv,$1.d),crArgNul(),crArgPos(niv,$$.d));
                                    }
                                ;

parametrosActuales              : /* vacı́o */{
                                    $$.t = insTdD(-1, T_VACIO);
                                }
                                | listaParametrosActuales{
                                    $$.t = $1.t;
                                }
                                ;

listaParametrosActuales         : expresion{
                                    $$.t = insTdD(-1, $1.t);
                                    emite(EPUSH,crArgNul(),crArgNul(),crArgPos(niv,$1.d));
                                }
                                | expresion CMA_ { 
                                    
                                    emite(EPUSH,crArgNul(),crArgNul(),crArgPos(niv,$1.d));
                                    
                                } listaParametrosActuales{
                                    $$.t = insTdD($4.t, $1.t);
                                }
                                ;


constante                       : CTE_  {
                                    $$.t = T_ENTERO; 
                                    $$.d = creaVarTemp();
                                    emite(EASIG,crArgEnt($1),crArgNul(),crArgPos(niv,$$.d));                                   
                                }
                                | TRUE_   {
                                    $$.t = T_LOGICO;
                                    $$.d = creaVarTemp();
                                    emite(EASIG,crArgEnt(1),crArgNul(),crArgPos(niv,$$.d));
                                }
                                | FALSE_  {
                                    $$.t = T_LOGICO;
                                    $$.d = creaVarTemp();
                                    emite(EASIG,crArgEnt(0),crArgNul(),crArgPos(niv,$$.d));
                                }
                                ;

operadorLogico                  :AND_      { $$ = EMULT; } 
                                |OR_       { $$ = ESUM;  } 
                                ;

operadorIgualdad                :IGU_      { $$ = EIGUAL; } 
                                |NOIGU_    { $$ = EDIST;  } 
                                ;

operadorRelacional              : MAY_     { $$ = EMAY; } 
                                | MEN_     { $$ = EMEN; } 
                                | MAYIGU_  { $$ = EMAYEQ; } 
                                | MENIGU_  { $$ = EMENEQ; } 
                                ;

operadorAditivo                 : MAS_      { $$ = ESUM; }    
                                | MENOS_    { $$ = EDIF; } 
                                ;

operadorMultiplicativo          : POR_     { $$ = EMULT; }  
                                | DIV_     { $$ = EDIVI; } 
                                ;

operadorUnario                  : MAS_     { $$ = ESUM; } 
                                | MENOS_   { $$ = EDIF; } 
                                | NOT_     { $$ = NOT;  } 
                                ;

operadorIncremento              : INC_     { $$ = ESUM; } 
                                | DEC_     { $$ = EDIF; }
                                ;

%%
