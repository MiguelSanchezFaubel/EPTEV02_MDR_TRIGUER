/*
*   File: menus_epte2.c
*   
*   Descripción: Program file del sistema de menús del equipo
*   
*   Proyecto: EPTE 2
*   Versión: 3.0
*
*   Ionclinics & Deionics SL
*/

#include "menus_epte2.h"

/*
*   Función: pantalla_seleccion
*   Descripción: Incluye los símbolos principales de los menús
*
*   Input:
*         - 
*   Output:
*         - 
*/

void pantalla_seleccion(){      


    int8 i8repBat = (int8)(((float)i8Bat/i8BateriaMaxima)*100.0); // Valor de representacion de la bateria en pantalla

    if(i8repBat>=100){            // Si haciendo ciclos de carga y descarga se supera el maximo nivel de bateria anterior
        i8repBat = 100;           // Guardamos este nivel como el nuevo maximo
    }

    if(bBateriaBaja){                                 // Si el nivel d ebateria es bajo
        if(bParpadeoBateria){                         // Indica parpadeando el valor restante de bateria
            ST7529_printf("     ",69,4,S_,i8repBat);  // Limpia el valor de bateria en pantalla
        }
        if(!bParpadeoBateria){
            sprintf(mystring,"%3u %%",i8repBat);       // Muestra el valor de bateria en pantalla
            ST7529_printf(mystring,69,4,S_,NORMAL);    // Representa en pantalla
        }   
    }else{                                             // Si no hay bateria baja
        sprintf(mystring,"%3u %%",i8repBat);              // Pone el valor de bateria restante
        ST7529_printf(mystring,69,4,S_,NORMAL);        // Muestra por pantalla
    }
    
    // Para mantener un formato de representación del nivel de bateria de forma correcta, 
    // se ajusta para cuando son uno, dos o tres digitos para mostrar
    i8PosVol=POS_VOL_UNO;                       // Muestro 1
    if(i8repBat>=10){                                  // Dos o tres digitos
        i8PosVol=POS_VOL_DOS;                   // Muestro 2
        if(i8repBat>=100){                             // Tres digitos
            i8PosVol=POS_VOL_TRES;                  // Muestro 3
        }
    }
    
    if(i16nivel_son==0){                            // Si el sonido está deshabilitado
        i8RepVal2=ICON_SON_NONE;
    }else if(i16nivel_son<50){                      // Si el sonido está configurado a un valor inferior al 50%
        i8RepVal2=ICON_SON_MED;
    }else{                                          // Si el sonido está configurado a un valor superior o igual al 50%
        i8RepVal2=ICON_SON_FULL;
    }
    ST7529_putIcon(i8RepVal2,i8PosVol,0);
    
    if(iMenuActual<100){   
        poner_flecha_der();                         // Pongo flecha derecha         
        if(iMenuActual==10){                        // Si estoy en el menú de configuración
            quitar_flecha_der();                    // Quito flecha derecha
        }

        poner_flecha_izq();                         // Pongo flecha derecha      
        if(iMenuActual==0){                        // Si estoy en el menú de configuración
            quitar_flecha_izq();                    // Quito flecha derecha
        }
    }else{                                          // Si está en un menú de tratamiento
        if((iMenuActual!=121 && iMenuActual!=123) && (iMenuActual!=131 && iMenuActual!=133)){   // Si estamos en un menú distinto a galvánica (en tratamiento o error de electrodo)
            poner_flecha_izq();                     // Ponemos la flecha izquierda en pantalla
        }
    
        if(iMenuActual!=120 && iMenuActual!=121 && iMenuActual!=123 && iMenuActual!=130 && iMenuActual!=131 && iMenuActual!=133 && iMenuActual!=140 && iMenuActual!=141 && iMenuActual!=142 && iMenuActual!=143 && iMenuActual!=180 && iMenuActual!=181 && iMenuActual!=183){   // Mientras no estemos en un menú de tratamiento de galvánica o electroestimulación
            poner_config();                         // Ponemos el símbolo de configuración
        }
        if(iMenuActual==140 || iMenuActual==141 || iMenuActual==142 || iMenuActual==143){   // Si estamos en cualquier menu de tratamiento de electroestimulación
            poner_flecha_der();                     // Ponemos la felcha derecha en el menú
        }
    }   
    
}

/*
*   Función: poner_cancelar
*   Descripción: Pone el símbolo de cancelar
*
*   Input:
*         - 
*   Output:
*         - 
*/
void poner_cancelar(){
    ST7529_putIcon(ICON_CANCEL,74,20);  // Pone en pantalla el símbolo de cancelar
}

/*
*   Función: quitar_cancelar
*   Descripción: Quita el símbolo de cancelar
*
*   Input:
*         - 
*   Output:
*         - 
*/
void quitar_cancelar(){
    ST7529_putIcon(ICON_NONE,74,20);    // Pone en pantalla el símbolo vacio
}

/*
*   Función: poner_config
*   Descripción: Pone el símbolo de configuración
*
*   Input:
*         - 
*   Output:
*         - 
*/
void poner_config(){
    ST7529_putIcon(ICON_CONFIG,74,90);     // Pone en pantalla el símbolo de configuración
}

/*
*   Función: quitar_config
*   Descripción: Quita el símbolo de configuración
*
*   Input:
*         - 
*   Output:
*         - 
*/
void quitar_config(){
    ST7529_putIcon(ICON_NONE,74,90);        // Pone en pantalla el símbolo vacio
}

/*
*   Función: poner_flecha_izq
*   Descripción: Pone la flecha izquierda
*
*   Input:
*         - 
*   Output:
*         - 
*/
void poner_flecha_izq(){
    ST7529_putIcon(ICON_LEFT,74,20);        // Pone en pantalla el símbolo de flecha izquierda
}

/*
*   Función: quitar_flecha_izq
*   Descripción: Quita la flecha izquierda
*
*   Input:
*         - 
*   Output:
*         - 
*/
void quitar_flecha_izq(){
    ST7529_putIcon(ICON_NONE,74,20);        // Pone en pantalla el símbolo vacio
}

/*
*   Función: poner_flecha_der
*   Descripción: Pone la flecha derecha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void poner_flecha_der(){
    ST7529_putIcon(ICON_RIGHT,74,90);       // Pone en pantalla el símbolo de flecha derecha
}

/*
*   Función: quitar_flecha_der
*   Descripción: Quita la flecha derecha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void quitar_flecha_der(){
    ST7529_putIcon(ICON_NONE,74,90);        // Pone en pantalla el símbolo vacio
}

/*
*   Función: poner_guardar
*   Descripción: Pone el símbolo de guardar
*
*   Input:
*         - 
*   Output:
*         - 
*/
void poner_guardar(){
    ST7529_putIcon(ICON_ALMACEN,74,90);     // Pone en pantalla el símbolo de guardar
}

/*
*   Función: quitar_guardar
*   Descripción: Quita el símbolo de guardar
*
*   Input:
*         - 
*   Output:
*         - 
*/
void quitar_guardar(){
    ST7529_putIcon(ICON_NONE,74,90);        // Pone en pantalla el símbolo vacio
}

/*
*   Función: poner_cargar
*   Descripción: Pone el símbolo de cargar
*
*   Input:
*         - 
*   Output:
*         - 
*/
void poner_cargar(){
    ST7529_putIcon(ICON_CARGAR,74,90);      // Pone en pantalla el símbolo de cargar
}

/*
*   Función: quitar_cargar
*   Descripción: Quita el símbolo de guardar
*
*   Input:
*         - 
*   Output:
*         - 
*/
void quitar_cargar(){
    ST7529_putIcon(ICON_NONE,74,90);        // Pone en pantalla el símbolo vacio
}

/*
*   Función: representacionPresets
*   Descripción: Representa por pantalla el menú de presets
* 
*   Input:
*         - 
*   Output:
*         - 
*/
void representacionPresets(){

    ST7529_printf(i8SeleccionTerapia+sSEL_PR_GALV_MICRO,COLUMNA_1+1,FILA_INIT_PRESETS,M_,giPos==0);                         // Selección de los presets por terapia

    ST7529_printf(sPreset1,COLUMNA_1+1,FILA_2_PRESETS,S_,giPos==1);                                                         // Preset 1 texto
    //ST7529_printf(i8RegistroPresets[0+6*i8SeleccionTerapia]+sPresetVacio,COLUMNA_2-1,FILA_2_PRESETS,S_,giPos==1);           // Preset 1 guardado

    ST7529_printf(sPreset2,COLUMNA_1+1,FILA_3_PRESETS,S_,giPos==2);                                                         // Preset 2 texto
    //ST7529_printf(i8RegistroPresets[1+6*i8SeleccionTerapia]+sPresetVacio,COLUMNA_2-1,FILA_3_PRESETS,S_,giPos==2);           // Preset 2 guardado

    ST7529_printf(sPreset3,COLUMNA_1+1,FILA_4_PRESETS,S_,giPos==3);                                                         // Preset 3 texto
    if (i8SeleccionTerapia!=3)
    {
        ST7529_printf(i8RegistroPresets[2+6*i8SeleccionTerapia]+sPresetVacio,COLUMNA_2-1,FILA_4_PRESETS,S_,giPos==3);           // Preset 3 guardado
    }
    ST7529_printf(sPreset4,COLUMNA_1+1,FILA_5_PRESETS,S_,giPos==4);                                                         // Preset 4 texto
    ST7529_printf(i8RegistroPresets[3+6*i8SeleccionTerapia]+sPresetVacio,COLUMNA_2-1,FILA_5_PRESETS,S_,giPos==4);           // Preset 4 guardado

    ST7529_printf(sPreset5,COLUMNA_1+1,FILA_6_PRESETS,S_,giPos==5);                                                         // Preset 5 texto
    ST7529_printf(i8RegistroPresets[4+6*i8SeleccionTerapia]+sPresetVacio,COLUMNA_2-1,FILA_6_PRESETS,S_,giPos==5);           // Preset 5 guardado

    ST7529_printf(sPreset6,COLUMNA_1+1,FILA_7_PRESETS,S_,giPos==6);                                                         // Preset 6 texto 
    ST7529_printf(i8RegistroPresets[5+6*i8SeleccionTerapia]+sPresetVacio,COLUMNA_2-1,FILA_7_PRESETS,S_,giPos==6);           // Preset 6 guardado

    switch(i8SeleccionTerapia){
        case 0:
            i8RepVal1=sPrEPTE;
            i8RepVal2=sPrEPTE_MICRO;
            break;
        case 1:
            i8RepVal1=sPrTDCS_MAIN;
            i8RepVal2=i8RegistroPresets[1+6*1]+sPresetVacio;
            
            break;
        case 2:
            i8RepVal1=sTB;
            i8RepVal2=sHIB;
            break;
        case 3:
            i8RepVal1=sPrNMP_LTP;
            i8RepVal2=sPrNMP_LTD;
            i8RepVal3=sPrNMP_SPOT;
            // i8RepVal3=" SPOT      ";
            // ST7529_printf(i8RepVal3,COLUMNA_2-1,FILA_4_PRESETS,S_,giPos==3);            // Preset 3 guardado
            break;
    }

    if(i8SeleccionTerapia==3){
        // ST7529_printf(" SPOT      ",COLUMNA_2-1,FILA_4_PRESETS,S_,giPos==3);           // Preset 2 guardado
        ST7529_printf(i8RepVal3,COLUMNA_2-1,FILA_4_PRESETS,S_,giPos==3);            // Preset 2 guardad
    }
    // if(i8SeleccionTerapia==2){
    //     ST7529_printf(" TB        ",COLUMNA_2-1,FILA_2_PRESETS,S_,giPos==1);            // Preset 1 guardado
    //     ST7529_printf(" HIB       ",COLUMNA_2-1,FILA_3_PRESETS,S_,giPos==2);           // Preset 2 guardado

    // }
    // else{
    //     ST7529_printf(i8RepVal1,COLUMNA_2-1,FILA_2_PRESETS,S_,giPos==1);           // Preset 1 guardado
    //     ST7529_printf(i8RepVal2,COLUMNA_2-1,FILA_3_PRESETS,S_,giPos==2);            // Preset 2 guardado
      
    // }
    ST7529_printf(i8RepVal1,COLUMNA_2-1,FILA_2_PRESETS,S_,giPos==1);           // Preset 1 guardado
    ST7529_printf(i8RepVal2,COLUMNA_2-1,FILA_3_PRESETS,S_,giPos==2);            // Preset 2 guardado
    

    


    /************************************DE CUANDO LOS PRESETS PREDEFINIDOS ESTABAN LOS ULTIMOS**********************************************************************/

    // ST7529_printf(i8SeleccionTerapia+sSEL_PR_GALV_MICRO,COLUMNA_1+1,FILA_INIT_PRESETS,M_,giPos==0);                         // Selección de los presets por terapia

    // ST7529_printf(sPreset1,COLUMNA_1+1,FILA_2_PRESETS,S_,giPos==1);                                                         // Preset 1 texto
    // ST7529_printf(i8RegistroPresets[0+6*i8SeleccionTerapia]+sPresetVacio,COLUMNA_2-1,FILA_2_PRESETS,S_,giPos==1);           // Preset 1 guardado

    // ST7529_printf(sPreset2,COLUMNA_1+1,FILA_3_PRESETS,S_,giPos==2);                                                         // Preset 2 texto
    // ST7529_printf(i8RegistroPresets[1+6*i8SeleccionTerapia]+sPresetVacio,COLUMNA_2-1,FILA_3_PRESETS,S_,giPos==2);           // Preset 2 guardado

    // ST7529_printf(sPreset3,COLUMNA_1+1,FILA_4_PRESETS,S_,giPos==3);                                                         // Preset 3 texto
    // ST7529_printf(i8RegistroPresets[2+6*i8SeleccionTerapia]+sPresetVacio,COLUMNA_2-1,FILA_4_PRESETS,S_,giPos==3);           // Preset 3 guardado

    // ST7529_printf(sPreset4,COLUMNA_1+1,FILA_5_PRESETS,S_,giPos==4);                                                         // Preset 4 texto
    // ST7529_printf(i8RegistroPresets[3+6*i8SeleccionTerapia]+sPresetVacio,COLUMNA_2-1,FILA_5_PRESETS,S_,giPos==4);           // Preset 4 guardado

    // ST7529_printf(sPreset5,COLUMNA_1+1,FILA_6_PRESETS,S_,giPos==5);                                                         // Preset 5 texto
    // // ST7529_printf(i8RegistroPresets[4+6*i8SeleccionTerapia]+sPresetVacio,COLUMNA_2-1,FILA_6_PRESETS,S_,giPos==5);           // Preset 5 guardado

    // ST7529_printf(sPreset6,COLUMNA_1+1,FILA_7_PRESETS,S_,giPos==6);                                                         // Preset 6 texto 
    // // ST7529_printf(i8RegistroPresets[5+6*i8SeleccionTerapia]+sPresetVacio,COLUMNA_2-1,FILA_7_PRESETS,S_,giPos==6);           // Preset 6 guardado

    // switch(i8SeleccionTerapia){
    //     case 0:
    //         i8RepVal1=sPrEPTE;
    //         i8RepVal2=sPrEPTE_MICRO;
    //         break;
    //     case 1:
    //         i8RepVal1=i8RegistroPresets[4+6*1]+sPresetVacio;
    //         i8RepVal2=sPrTDCS_MAIN;
    //         break;
    //     // case 2:
    //     //     i8RepVal1=sHIB;
    //     //     i8RepVal2=sTB;
    //     //     break;
    //     case 3:
    //         i8RepVal1=sPrNMP_LTP;
    //         i8RepVal2=sPrNMP_LTD;
    //         break;
    // }

    // if(i8SeleccionTerapia==2){
    //     ST7529_printf(" HIB       ",COLUMNA_2-1,FILA_6_PRESETS,S_,giPos==5);           // Preset 5 guardado
    //     ST7529_printf(" TB        ",COLUMNA_2-1,FILA_7_PRESETS,S_,giPos==6);            // Preset 6 guardado
    // }else{
    //     ST7529_printf(i8RepVal1,COLUMNA_2-1,FILA_6_PRESETS,S_,giPos==5);           // Preset 5 guardado
    //     ST7529_printf(i8RepVal2,COLUMNA_2-1,FILA_7_PRESETS,S_,giPos==6);            // Preset 6 guardado
    // }


    /************************************DE CUANDO LOS PRESETS PREDEFINIDOS ESTABAN LOS ULTIMOS**********************************************************************/
    
}

/*
*   Función: menu_0
*   Descripción: Menú principal
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_0(){                          

    if(bRefrescoPantalla){                              // Si debo refrescar la pantalla
        
        if(iMenuAnterior!=0 || bAlMenuPrincipal){       // Si el menú anterior no es el menú principal o me indica que tengo que ir al menú principal
            bAlMenuPrincipal=0;                         // Inicializo flag menú principal
            ST7529_clear();                             // Limpio pantalla
            ST7529_printf(sMENU_PRINCIPAL,0,0,L_,NORMAL);   // Muestra texto menú principal
            i8CanalesConfigurados=0;                    // Inicializa variable de canales configurados
            i8ConfigCanal=0;                            // Inicializa variable del canal a configurar
            bPointerSeleccionado=0;                     // Inicializa selección de pointer
            i8VariablesPreset=0;                        // Inicializo la variable que indica que debo de guardar en preset
            i8BufferIndex=0;                            // Inicializa buffer de entrada de datos
            bEvitaRebotePausa=0;                        // Inicializa flag evita rebotes tecla pausa
        }

        pantalla_seleccion();                           // Muestra iconos de selección
        
        if(giPos<=0){                                   // Si el valor de selección es menor o igual a 0
            giPos=0;                                    // Inicializo giPos
        }
        
        if(giPos>5){                                    // Si el valor de selección es mayor que 5
            giPos=5;                                    // Inicializo giPos al máximo
        }

        #ifndef SOLO_TDCS           // Versión completa
        ST7529_printf(sMENU_PRESETS,COLUMNA_1_MENU,FILA_INIT_MENU,S_,giPos==0);         // Muestro menú Presets (se pone en texto porque queda mejor que la antigua en memoria)
        ST7529_printf(sMENU_GALVMICRO,COLUMNA_1_MENU,FILA_1_MENU,S_,giPos==1);          // Muestro menú Galvánica + Micro
        ST7529_printf(sMENU_TRANSCRANEAL,COLUMNA_1_MENU,FILA_2_MENU,S_,giPos==2);       // Muestro menú Transcraneal
        ST7529_printf(sMENU_ELECTRO,COLUMNA_1_MENU,FILA_3_MENU,S_,giPos==3);            // Muestro menú Electroestimulación
        ST7529_printf(sMENU_SMP,COLUMNA_1_MENU,FILA_4_MENU,S_,giPos==4);                // Muestro menú TB
        ST7529_printf(sMENU_CONFIG,COLUMNA_1_MENU,FILA_5_MENU,S_,giPos==5);             // Muestro menú Configuración
        #else                       // Versión solo tDCS
        ST7529_printf(sMENU_PRESETS,COLUMNA_1_MENU,FILA_INIT_MENU,S_,giPos==0);         // Muestro menú Presets (se pone en texto porque queda mejor que la antigua en memoria)
        ST7529_printfg(sMENU_GALVMICRO,COLUMNA_1_MENU,FILA_1_MENU,S_,ai8EscalaGrises[1],giPos==1);          // Muestro menú Galvánica + Micro
        ST7529_printf(sMENU_TRANSCRANEAL,COLUMNA_1_MENU,FILA_2_MENU,S_,giPos==2);       // Muestro menú Transcraneal
        ST7529_printfg(sMENU_ELECTRO,COLUMNA_1_MENU,FILA_3_MENU,S_,ai8EscalaGrises[1],giPos==3);            // Muestro menú Electroestimulación
        ST7529_printfg(sMENU_SMP,COLUMNA_1_MENU,FILA_4_MENU,S_,ai8EscalaGrises[1],giPos==4);                // Muestro menú TB
        ST7529_printf(sMENU_CONFIG,COLUMNA_1_MENU,FILA_5_MENU,S_,giPos==5);             // Muestro menú Configuración
        #endif

        iMenuAnterior=iMenuActual;                      // Inicializo menú anterior
        
    }
    
    bRefrescoPantalla=0;                                // Inicializo el refresco de pantalla
    
    return 0;                                           // Retorna 0
}

/*
*   Función: menu_10
*   Descripción: Menú configuración del dispositivo
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_10(){   
    #ifndef INIT_PRESETS
    if(iMenuAnterior!=10){                              // Si venimos de un menú distinto de este
        ST7529_clear();                                 // Limpiamos pantalla
        ST7529_printf(sCONFIG,0,0,L_,NORMAL);           // Ponemos el texto de Configuracion
    } 
    
    if(bRefrescoPantalla){                              // Si debo de refrescar los valores
        pantalla_seleccion();                           // Muestro iconos de seleccion
           
        if(giPos>=3){                                   // Si la selección es mayor o igual a 5 
            giPos=3;                                    // Inicializo a 4
        }
           
        ST7529_printf(sCONFIG_ILUM,COLUMNA_1,FILA_INIT,M_,0);
        sprintf(mystring,"%3i%c ",i8nivel_ilum,37);              
        ST7529_printf(mystring,COLUMNA_2+10,FILA_INIT,M_,giPos==0);

        ST7529_printf(sCONFIG_CONT,COLUMNA_1,FILA_1,M_,0);
        sprintf(mystring,"%3i%c ",i8NivelContraste,37);          
        ST7529_printf(mystring,COLUMNA_2+10,FILA_1,M_,giPos==1);

        ST7529_printf(sCONFIG_PITO,COLUMNA_1,FILA_2,M_,0);
        sprintf(mystring,"%3lu%c ",i16nivel_son,37);          
        ST7529_printf(mystring,COLUMNA_2+10,FILA_2,M_,giPos==2);

        ST7529_printf(sCONFIG_IDIO,COLUMNA_1,FILA_3,M_,0);
        i8RepVal1=sIDIOMA_INGLES;
        if(i8SelIdioma==0){                                     // Si variable de seleccion de idioma es 0 (espanyol)
            i8RepVal1=sIDIOMA_ESPANOL;
        }
        ST7529_printf(i8RepVal1,COLUMNA_2+10,FILA_3,M_,giPos==3);         // Muestra idioma por pantalla

        // AHORRO MEMORIA
        ST7529_printf(sFW_Ver,21,98,L_,0);                     // Muestra versión del firmware
        ST7529_printf(sHW_Ver,43,98,L_,0);                     // Muestra versión del hardware

        //sprintf(mystring,"Build: %lu _ %lu _ 0x%LX",4314,2995, getChemID());          // Muestro valor por pantalla
        
        #ifndef VERSION_PIRATA
        

            sprintf(mystring,"Build: %lu - %lu - 0x%LX",gi16BuildCounter,gi16BuildCounterOrco, getChemID());        // Muestra valor de versiones por pantalla
            ST7529_printfg(mystring,15,120,S_,ai8EscalaGrises[1],0);
        
        #else
        

            sprintf(mystring,"Build: %lu _ %lu _ 0x%LX",4314,2995, getChemID());        // Muestra valor de versiones piratas por pantalla con una barra baja
            ST7529_printfg(mystring,15,120,S_,ai8EscalaGrises[1],0);
        
        #endif
        iMenuAnterior=iMenuActual;                      // Inicializo el valor del menu anterior
    }
          
    bRefrescoPantalla=0;                                // Limpio flag refresco de pantalla
    
    return 0;                                           // Return 0
}

/*
*   Función: menu_20
*   Descripción: Menú de galvánica / galvánica + microcorrientes
*
*   Input:
*         - 
*   Output:
*         - 
*/
// int8 menu_20(){
//     if(bRefrescoPantalla){                          // Si se ha cambiado algún valor
//         if(iMenuAnterior!=20){                      // Si venimos de otro menú
//             gF=1;                                   // Pongo a uno para inicializar la parte de frecuencias con la rulancha
//             ST7529_clear();                         // Limpio pantalla
//             if(bSeleccionGalvanica){                // Si se ha seleccionado galvánica y microcorrientes
//                 ST7529_printf(sGALVANICA_MICRO,0,0,L_,NORMAL);  // Muestra este titulo
//                 i8VariablesPreset=PRESET_GALVMICRO;                        // Preset Galv+Micro
//             }else{                                  // Si no
//                 ST7529_printf(sGALV,0,0,L_,NORMAL); // Muestra solo título de galvánica
//                 i8VariablesPreset=PRESET_GALV;                        // Preset Galv
//             }
//             if(iMenuAnterior!=120){                 // Si no venimos del menu de tratamiento configurado
//                 i32CGalv=calc_CargaGalv(i16IGalv[bSeleccionGalvanica]);      // Muestra el valor de carga eléctrica por pantalla con los valores que dispone
//             }
//         }
        
//         if(iMenuAnterior==120){                     // Si veniamos de configurar el tratamiento o tras finalizar/parar un tratamiento
//             bEmpiezaContadorTiempo=0;               // Inicializo contador de tiempo                                                       
//             bValorAlcanzado[GALVANICA_C]=0;         // Inicializo valor alcanzado de corriente galvánica                    
//             bDescuentaCargaRampa=0;                 // Inicializo valor de descuento de carga en rampa            
//             bTerapia=0;                             // Inicializo variable galv/micro en tratamiento
//             bTratamientoGalvanicaActivado=0;        // Inicializo tratamiento activo                        
//             bMicrocorrientesEncendido=0;            // Inicializo indicador de tratamiento                    
//             i32CargaGalvanicaRestante=0;            // Inicializo valor carga restante (NECESARIO AHORA??)           
//             i16TGalv[bSeleccionGalvanica]=calc_Tgalv(i32Cgalv,i16IGalv[bSeleccionGalvanica]);             // Inicializo variables de tiempo
//             if(i16TGalv[bSeleccionGalvanica]==0){           // Si el tiempo de tratamiento se ha definido como infinito
//                 i16TimeRaw[0]=0;                            // Indica tiempo infinito de tratamiento
//             }else{                                          // Si el tiempo de tratamiento ha sido fijado
//                 i16TimeRaw[0]=i16TGalv[bSeleccionGalvanica]+i8TrampaGalv[bSeleccionGalvanica];  // Inicializo variables de tiempo 
//             }            
//             i32CargaGalvanicaRestante=i32Cgalv+i16CRampaGalv;   // Inicializo variable de carga
//             bPausaTratamiento=0;                                // Inicializo pausa            
//             giPosRulancha=i16IGalv[bSeleccionGalvanica];        // Inicializo rulancha            
//         }
       
//         pantalla_seleccion();                       // Muestro iconos
    
//         if(!bSeleccionGalvanica){                   // Si estamos en menú de galvánica solo
    
//             if(giPos==4){                           // Descendente, si es igual a 4
//                 giPos=9;                            // Salta al 9 (Config. tratamiento)
//             }
            
//             if(giPos==8){                           // Ascendente, si es igual a 8
//                 giPos=3;                            // Salta a 3, (Config. rampa)
//             }
//         }
        
//         if(giPos>=11){                              // Si es mayor o igual que 10
//             giPos=10;                               // Inicializo a 9
//         }
//         if(giPos<=1){                               // Si es menor o igual a 1
//             giPos=1;                                // Inicializo a 1
//         }
       
//         sprintf(mystring,"Q=%6lu[C",(int32)i32CGalv+i16CRampaGalv);         // Muestra carga
//         ST7529_printfg(mystring,COLUMNA_1,(bSeleccionGalvanica) ? (FILA_INIT):(FILA_1),M_,ai8EscalaGrises[1],0);    // Por pantalla
       
//         sprintf(mystring,"I=%5lu[A",i16IGalv[bSeleccionGalvanica]*50);      // Muestra corriente seleccionada
//         ST7529_printf(mystring,COLUMNA_2,(bSeleccionGalvanica) ? (FILA_INIT):(FILA_1),M_,giPos==1);     // Por pantallla
       
//         if(bSeleccionGalvanica){                    // Si estamos en galv + micro 
//             if(i16TGalv[bSeleccionGalvanica]==0){   // Si ponemos tiempo de galv a 0 (infinito no permitido en galc + micro)
//                 i16TGalv[bSeleccionGalvanica]=1;    // Inicializa a 1
//             }
//         }
        
//         Calc_representacion_t(i16TGalv[bSeleccionGalvanica],0);         // Calculo representación de tiempo

//         if(i16TGalv[bSeleccionGalvanica]==0){                           // Si el tiempo es 0 (ilimitado)
//             ST7529_printf(sTIEMPO_ACTIVO_ILIMITADO,COLUMNA_1,(bSeleccionGalvanica) ? (FILA_1):(FILA_2),M_,giPos==2);   // Por pantalla
//         }else{                                                          // Si hay un tiempo definido
//             sprintf(mystring,"Ta=%2u:%02u s",i8Tmin,i8Tseg);            // Muestro el tiempo en pantalla
//             ST7529_printf(mystring,COLUMNA_1,(bSeleccionGalvanica) ? (FILA_1):(FILA_2),M_,giPos==2);   // Por pantalla
//         }
       
//         sprintf(mystring,"Tr=%2u s",i8TrampaGalv[bSeleccionGalvanica]); // Muestro el tiemp ode rampa
//         ST7529_printf(mystring,COLUMNA_2,(bSeleccionGalvanica) ? (FILA_1):(FILA_2),M_,giPos==3);   // Por pantalla
       
//         if(bSeleccionGalvanica){                                        // Si estamos en modo galv+micro
//             ST7529_printf(sGALV,5+ (COLUMNA_1+COLUMNA_2)/2,FILA_INIT-SALTO_FILA,S_,0);  // Muestra título galvánica
//             ST7529_printf(sMICRO_CORRIENTES,(COLUMNA_1+COLUMNA_2)/2,FILA_2,S_,0);       // Mostramos el titulo de Microcorrinetes
        
//             sprintf(mystring,"I=%4lu[A",i16Imicro*50);                  // Muestra corriente seleccionada
//             ST7529_printf(mystring,COLUMNA_1,FILA_3,M_,giPos==4);       // Por pantalla
           
//             Calc_representacion_t(i16Tmicro,0);                         // Calcula representación de tiempo
//             sprintf(mystring,"Ta=%2u:%02u s",i8Tmin,i8Tseg);            // Muestra tiempo de tratamiento de microcorrientes
//             ST7529_printf(mystring,COLUMNA_2,FILA_3,M_,giPos==5);       // Por pantalla
            
//             if(bPolaridadMicro){                                        // Si se trata de una señal bipolar
//                 i8RepVal1=sBIPOLAR;                                     // Muestro texto bipolar
//                 ST7529_printf(i8RepVal1,COLUMNA_1,FILA_4,M_,giPos==6);  // Por pantalla
//             }else{                                                      // Si se trata de una señal monopolar
//                 if(bMonopolarPosNeg){                                   // Si se trata de una señal monopolar negativa
//                     sprintf(mystring,"MONOPOLAR-");                     // Muestro texto
//                 }else{                                                  // Si se trata de una señal monopolar positiva
//                     sprintf(mystring,"MONOPOLAR+");                     // Muestro texto
//                 }
//                 ST7529_printf(mystring,COLUMNA_1,FILA_4,M_,giPos==6);   // Por pantalla
//             }
          
//             sprintf(mystring,"PW=%4lu [s",i16PWmicro);                  // Muestra ancho del pulso
//             ST7529_printf(mystring,COLUMNA_2,FILA_4,M_,giPos==7);       // Por pantalla
        
//             sprintf(mystring,"F=%4luHz",i16frecmicro);                  // Muestra frecuencia
//             ST7529_printf(mystring,COLUMNA_1,FILA_5,M_,giPos==8);       // Por pantalla
//         }
     
//         ST7529_printf(sGUARDAR_PRESET,(bSeleccionGalvanica) ? (COLUMNA_2):(COLUMNA_1),(bSeleccionGalvanica) ? (FILA_5):(FILA_3),M_,giPos==9);   // Muetsra por pantalla la corriente
        
//         ST7529_printf(sCONFIG_TRAT,COLUMNA_1,FILA_RELISTO,M_,giPos==10);    // Muestra texto de acceso al tratamiento
//         iMenuAnterior=iMenuActual;                                      // Asignamos menú actual al mmenu anterior
//     }
    
//     bRefrescoPantalla=0;                // Inicializo flag de refresco

//     return 0;                           // Return 0
// }

/*
*   Función: menu_20 Added 04/03/2022
*   Descripción: Menú de galvánica / microcorrientes / galvánica + microcorrientes
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_20(){

    int1 bCondicion=0;

    if(bRefrescoPantalla){                                                  // Si se ha cambiado algún valor
        if(iMenuAnterior!=20){                                              // Si venimos de otro menú
            gF=1;                                                           // Pongo a uno para inicializar la parte de frecuencias con la rulancha
            ST7529_clear();                                                 // Limpio pantalla
            ST7529_printf(sGALVANICA_MICRO,0,0,L_,NORMAL);                  // Muestra este titulo
            // if(bSeleccionGalvanica){                // Si se ha seleccionado galvánica y microcorrientes
            //     i8VariablesPreset=PRESET_GALVMICRO;                        // Preset Galv+Micro
            // }else{                                  // Si no
            //     i8VariablesPreset=PRESET_GALV;                        // Preset Galv
            // }
            i8SeleccionTerapia=0;
            if(iMenuAnterior!=120){                                         // Si no venimos del menu de tratamiento configurado
                i32CGalv=calc_CargaGalv(i16IGalv[bSeleccionGalvanica]);     // Muestra el valor de carga eléctrica por pantalla con los valores que dispone
            }
        }



        if(iMenuAnterior==120){                                                                 // Si veniamos de configurar el tratamiento o tras finalizar/parar un tratamiento
            bEmpiezaContadorTiempo=0;                                                           // Inicializo contador de tiempo                                                       
            bValorAlcanzado[GALVANICA_C]=0;                                                     // Inicializo valor alcanzado de corriente galvánica                    
            bDescuentaCargaRampa=0;                                                             // Inicializo valor de descuento de carga en rampa            
            bTerapia=0;
            if(i8SeleccionGalvMicro!=SEL_MICRO){
                bTerapia=1;                                                                         // Inicializo variable galv/micro en tratamiento
            }
            bTratamientoGalvanicaActivado=0;                                                    // Inicializo tratamiento activo                        
            bMicrocorrientesEncendido=0;                                                        // Inicializo indicador de tratamiento                    
            i32CargaGalvanicaRestante=0;                                                        // Inicializo valor carga restante (NECESARIO AHORA??)           
            i16TGalv[bSeleccionGalvanica]=calc_Tgalv(i32Cgalv,i16IGalv[bSeleccionGalvanica]);   // Inicializo variables de tiempo
            if(i16TGalv[bSeleccionGalvanica]==0){                                               // Si el tiempo de tratamiento se ha definido como infinito
                i16TimeRaw[0]=0;                                                                // Indica tiempo infinito de tratamiento
            }else{                                                                              // Si el tiempo de tratamiento ha sido fijado
                i16TimeRaw[0]=i16TGalv[bSeleccionGalvanica]+i8TrampaGalv[bSeleccionGalvanica];  // Inicializo variables de tiempo 
            }            
            i32CargaGalvanicaRestante=i32Cgalv+i16CRampaGalv;                                   // Inicializo variable de carga
            bPausaTratamiento=0;                                                                // Inicializo pausa            
            giPosRulancha=i8SeleccionGalvMicro;                                                 // Inicializo rulancha
        }

        if(giPos>=10){                              // Si es mayor o igual que 13
            giPos=10;                               // Inicializo a 12
        }
        if(giPos<=0){                               // Si es menor o igual a 1
            giPos=0;                                // Inicializo a 1
        }

        pantalla_seleccion();

        switch(i8SeleccionGalvMicro){                                                       // Switch-case para identificar la seleccion de terapia
            case SEL_GALVANICA:                                                             // Seleccion galvanica
                i8RepVal1=sSEL_GALV;                                          // Asigno string
                i8VariablesPreset=PRESET_GALV;                        // Preset Galv
                break;
            case SEL_MICRO:                                                                 // Seleccion microcorrientes
                i8RepVal1=sSEL_MICRO;                                          // Asigno string
                i8VariablesPreset=PRESET_MICRO;                        // Preset Micro
                break;
            case SEL_GALV_MICRO:                                                            // Seleccion galvanica+microcorrientes
                i8RepVal1=sSEL_GALV_MICRO;                                          // Asigno string
                i8VariablesPreset=PRESET_GALVMICRO;                        // Preset Galv+Micro
                break;
        }
        ST7529_printf(i8RepVal1,COLUMNA_1,18,M_,giPos==0);                                   // Muestra título de terapia


        int32 carga_aux=0;
        bCondicion=(i8SeleccionGalvMicro==SEL_MICRO);

        if(!bCondicion){
            carga_aux=(int32)i32CGalv+i16CRampaGalv;
        }
        sprintf(mystring,"Q=%6lu[C",carga_aux);                         // Muestra carga
        ST7529_printfg(mystring,COLUMNA_1,FILA_INIT,M_,ai8EscalaGrises[1],0);               // Por pantalla


        int16 corriente_galv_aux=0;

        if(!bCondicion){
            corriente_galv_aux=i16IGalv[bSeleccionGalvanica]*50;
        }

        sprintf(mystring,"Ig=%5lu[A",corriente_galv_aux);                      // Muestra corriente seleccionada
        ST7529_printfg(mystring,COLUMNA_2,FILA_INIT,M_,ai8EscalaGrises[bCondicion],giPos==1);


        Calc_representacion_t(i16TGalv[bSeleccionGalvanica],0);                             // Calculo representación de tiempo

        if(bCondicion){
            i8Tmin=0;
            i8Tseg=0;
        }

        sprintf(mystring,"  =%2u:%02u s",i8Tmin,i8Tseg);                            // Muestro el tiempo en pantalla
        ST7529_printfg(mystring,COLUMNA_1,FILA_1,M_,ai8EscalaGrises[bCondicion],giPos==2);                           // Por pantalla
        ST7529_printfg(sTa,COLUMNA_1,FILA_1,M_,ai8EscalaGrises[bCondicion],giPos==2);
        
        if(i16TGalv[bSeleccionGalvanica]==0 && !bCondicion){
            ST7529_printf(sTIEMPO_ACTIVO_ILIMITADO,COLUMNA_1,FILA_1,M_,giPos==2);           // Por pantalla
        }


        sprintf(mystring,"Tr=%2u s",i8TrampaGalv[bSeleccionGalvanica]);                     // Muestro el tiempo de rampa
        ST7529_printf(mystring,COLUMNA_2,FILA_1,M_,giPos==3);                               // Por pantalla

        bCondicion=(i8SeleccionGalvMicro==SEL_MICRO || i16TGalv[bSeleccionGalvanica]==0);
        i8RepVal1=sTfijo;

        if(bTiempoAutoGalv){    
            i8RepVal1=sTcomp;
        }

        ST7529_printfg(i8RepVal1,COLUMNA_1,FILA_2,M_,ai8EscalaGrises[bCondicion],giPos==4);


        float galvanica_aux=100;
        bCondicion=(i8SeleccionGalvMicro==SEL_GALVANICA);

        if(!bCondicion){
            galvanica_aux=calculoComponenteGalvanica((int32)i16PWmicro,(int32)i16PWmicro,i16frecmicro,bPolaridadMicro);
        }

        sprintf(mystring,"G=%3.2f%c  ",galvanica_aux,37);
        ST7529_printfg(mystring,COLUMNA_2,FILA_2,M_,ai8EscalaGrises[1],0);                  // Por pantalla


        int16 corriente_micro_aux=0;

        if(!bCondicion){
            corriente_micro_aux=i16Imicro*50;
        }

        sprintf(mystring,"Im=%5lu[A",corriente_micro_aux);                      // Muestra corriente seleccionada
        ST7529_printfg(mystring,COLUMNA_1,FILA_3,M_,ai8EscalaGrises[bCondicion],giPos==5);


        Calc_representacion_t(i16Tmicro,0);                                                 // Calcula representación de tiempo

        if(bCondicion){
            i8Tmin=0;
            i8Tseg=0;
        }

        sprintf(mystring,"  =%2u:%02u s",i8Tmin,i8Tseg);                            // Muestra tiempo de tratamiento de microcorrientes
        ST7529_printfg(mystring,COLUMNA_2,FILA_3,M_,ai8EscalaGrises[bCondicion],giPos==6); 
        ST7529_printfg(sTa,COLUMNA_2,FILA_3,M_,ai8EscalaGrises[bCondicion],giPos==6);


        i8RepVal1=sBIPOLAR;                                                         // Muestro texto bipolar

        if(!bPolaridadMicro){
            i8RepVal1=sMonopolarNegativo;   
            if(!bMonopolarPosNeg){
                i8RepVal1=sMonopolarPositivo;
            }
        }

        ST7529_printfg(i8RepVal1,COLUMNA_1,FILA_4,M_,(ai8EscalaGrises[bCondicion]),giPos==7);     // Muestra por pantalla texto gris


        int16 pw_micro_aux=0;

        if(!bCondicion){
            pw_micro_aux=i16PWmicro;
        }

        sprintf(mystring,"PW=%4lu [s",pw_micro_aux);                        // Muestra ancho del pulso
        ST7529_printfg(mystring,COLUMNA_2,FILA_4,M_,ai8EscalaGrises[bCondicion],giPos==8);                                                                        // Por pantalla


        int16 frec_micro_aux=0;

        if(!bCondicion){
            frec_micro_aux=i16frecmicro;
        }

        sprintf(mystring,"F=%4luHz",frec_micro_aux);                      // Muestra frecuencia
        ST7529_printfg(mystring,COLUMNA_1,FILA_5,M_,ai8EscalaGrises[bCondicion],giPos==9);                                                                        // Por pantalla


        ST7529_printf(sGUARDAR_PRESET,COLUMNA_1,FILA_RELISTO,M_,giPos==10);                    // Muestra texto de acceso al tratamiento

        iMenuAnterior=iMenuActual;
    }

    bRefrescoPantalla=0;                                                                // Inicializo flag de refresco

    return 0;                                                                           // Return 0
}

/*
*   Función: menu_30
*   Descripción: Menú de transcraneal
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_30(){
    int1 bCondicion=0;
    if(bRefrescoPantalla){                                          // Si se ha cambiado algún valor
        if(iMenuAnterior!=30){                                      // Si venimos de otro menú
            ST7529_clear();                                         // Limpio pantalla
            ST7529_printf(sTRANS,0,0,L_,NORMAL);                    // Muestra este titulo
            if(iMenuAnterior!=130){                                 // Si no venimos del menú de tratamiento configurado
                i32CTrans=calc_CargaTrans(i16Itrans);               // Muestra el valor de carga eléctrica por pantalla con los valores que dispone
            }
            i8VariablesPreset=PRESET_TRANSCRANEAL;                  // Preset Trans
            i8SeleccionTerapia=1;
        }
        pantalla_seleccion();                                       // Muestro iconos
        
        if(iMenuAnterior==130){                                     // Si veniamos de configurar el tratamiento o tras finalizar/parar un tratamiento
            bEmpiezaContadorTiempo=0;                               // Inicializo contador de tiempo                                                       
            bValorAlcanzado[GALVANICA_C]=0;                         // Inicializo valor alcanzado de corriente galvánica                    
            bDescuentaCargaRampa=0;                                 // Inicializo valor de descuento de carga en rampa            
            bTratamientoTranscranealActivado=0;                     // Inicializo tratamiento activo                        
            bMicrocorrientesEncendido=0;                            // Inicializo indicador de tratamiento                    
            if(i16Ttrans==0){                                       // Si el tiempo de tratamiento en transcraneal es infinito
                i16TimeRaw[0]=0;                                    // Lo pone a infiinito
            }else{                                                  // Si es  un tiempo finito
                i16TimeRaw[0]=i16Ttrans+i8TrampaTrans;              // Inicializo variables de tiempo 
            }                           
            bPausaTratamiento=0;                                    // Inicializo pausa            
            giPosRulancha=i16ITrans;                                // Inicializo rulancha            
        }
            
        pantalla_seleccion();                                       // Muestro iconos
        
        if(giPos>=7){                                              // Si es mayor o igual que 10
            giPos=7;                                                // Inicializo a 9
        }               
        if(giPos<=1){                                               // Si es menor o igual a 1
            giPos=1;                                                // Inicializo a 1
        }

        bCondicion=(i16Ttrans==0);
        
        sprintf(mystring,"Q=%7lu [C",(int32)i32CTrans+(int32)i16CRampaTrans);              // Muestra carga
        ST7529_printfg(mystring,COLUMNA_1,FILA_INIT,M_,ai8EscalaGrises[1],0);       // Por pantalla
        

        sprintf(mystring,"I=%5lu [A",i16ITrans*50);                                 // Muestra corriente seleccionada
        ST7529_printf(mystring,COLUMNA_2,FILA_INIT,M_,giPos==1);                    // Por pantallla
        

        i8RepVal1=sTfijo;

        if(bTiempoAutoTrans){
            i8RepVal1=sTcomp;
        }

        ST7529_printfg(i8RepVal1,COLUMNA_1,FILA_1,M_,ai8EscalaGrises[bCondicion],giPos==2);                    // Por pantalla


        Calc_representacion_t(i16Ttrans,0);                                         // Calculo representación de tiempo

        sprintf(mystring,"Ta=%2u:%02u s",i8Tmin,i8Tseg);                        // Muestro el tiempo en pantalla
        ST7529_printf(mystring,COLUMNA_2,FILA_1,M_,giPos==3);                   // Por pantalla

        if(i16Ttrans==0){                                                           // Si el tiempo es 0 (ilimitado)
            ST7529_printf(sTIEMPO_ACTIVO_ILIMITADO,COLUMNA_2,FILA_1,M_,giPos==3);   // Por pantalla
        }

        
        sprintf(mystring,"Tre=%5lu s",i8TrampaTrans);                               // Muestro el tiemp ode rampa
        ST7529_printf(mystring,COLUMNA_1,FILA_2,M_,giPos==4);                       // Por pantalla


        sprintf(mystring,"Trs=%2u s",i8TrampaTransBajada);                          // Muestro el tiemp ode rampa
        ST7529_printf(mystring,COLUMNA_2,FILA_2,M_,giPos==5);                       // Por pantalla
        
        
        sprintf(mystring,"S=%3.1f",fSuperficieElectrodo);                        // Muestra tamaño electrodo
        sprintf(mystring2,"       cm]");                                            // Muestra tamaño electrodo
        ST7529_printf(mystring2,COLUMNA_2,FILA_3,M_,giPos==6);                       // Por pantalla
        ST7529_printf(mystring,COLUMNA_2,FILA_3,M_,giPos==6);                       // Por pantalla
        

        i32DensidadCorriente=(i16ITrans*50)/fSuperficieElectrodo;                  // Se obtiene la densidad  de corriente
        
        sprintf(mystring,"j=%3lu [A/cm]",i32DensidadCorriente);                     // Muestro densidad de carga
        ST7529_printfg(mystring,COLUMNA_1,FILA_3,M_,ai8EscalaGrises[1],0);          // Por pantalla


        ST7529_printf(sGUARDAR_PRESET,COLUMNA_1,FILA_RELISTO,M_,giPos==7);             // Muestra el texto de guardar preset 
        
        iMenuAnterior=iMenuActual;                                                  // Asigna el menú actual al menú anterior
    }
        
    bRefrescoPantalla=0;                                                        // Inicializo flag de refresco
    
    return 0;                                                                   // Return 0
}

/*
*   Función: menu_40
*   Descripción: Menú de electroestimulación
*
*   Input:
*         - 
*   Output:
*         - 
*/
// int8 menu_40(){

//     if(bRefrescoPantalla){                                                  // Si ha cambiado algún valor
                       
//         int1 bCondicion=0;                                                  // Variable utilizada conmo condicional de escala de grises en texto
                            
//         if((iMenuAnterior!=40)||(bborrado==1)){                             // Si vengo de otro menu debo borrar la basurilla
//             if(iMenuAnterior!=48){                                          // Si el menú anterior es distinto al menú de configuración de frecuencia en electroestimulación
//                 gF=1;                                                       // Pongo a uno para inicializar la parte de frecuencias con la rulancha
//             }
//             ST7529_clear();                                                 // Limpio pantalla  
//             ST7529_printf(sELECTRO_ESTIMULACION,0,0,L_,NORMAL);             // Muestro título de electroestimulación
//             i8VariablesPreset=PRESET_ELECTRO;                               // Preset Electro
//             bborrado=0;                                                     // Inicializo limpieza de pantalla 

//             Calc_representacion_t(i16TacElec[i8ConfigCanal],i16TdElec[i8ConfigCanal]);      // Calculo representación de tiempo
//             if(i8ConfigCanal==POINTER_C){  // Si estamos en el menú de config. del pointer y no venimos de los menús de frecuencia, corrinete o PW (menus de config. del pointer)
//                 i16frecElec[POINTER_C]=10;                                  // Inicializa el valor de frecuencia a 10 Hz
//             }
//             giPosRulancha=i8ConfigCanal;
//         }
        
//         if(i16IElec[i8ConfigCanal]>=MAXIMA_CORRIENTE_INICIO_ELECTRO){       // Si la corriente es superior a 20*50=1000uA 
//             i16IElec[i8ConfigCanal]=MAXIMA_CORRIENTE_INICIO_ELECTRO;        // Inicializa a 1000uA
//         }
        
//         if(iMenuAnterior==140 && bPausaTratamiento){                        // Si estabamos en el menú de tratamiento y habiamos pausado
//             bPausaTratamiento=0;                                            // Inicializo pausa
//             if(i16IElec[i8ConfigCanal]>=MAXIMA_CORRIENTE_INICIO_ELECTRO){   // Si la corriente es superior a 20*50=1000uA 
//                 i16IElec[i8ConfigCanal]=MAXIMA_CORRIENTE_INICIO_ELECTRO;    // Inicializa a 1000uA
//             }
//         }
        
//         // if(iMenuAnterior==43){                                              // Si el menú anterior era la configuración del tiempo de tratamiento
//         //     if(i8TrElec[i8ConfigCanal] > i16TacElec[i8ConfigCanal]/3){      // Si el tiempo de rampa es superior a 1/3 del tiempo de tratamiento
//         //         i8TrElec[i8ConfigCanal]=i16TacElec[i8ConfigCanal]/3;        // Asignale 1/3 de tiemp ode tratamiento al tiempo de rampa
//         //     }
//         //     if(i8TrElec[i8ConfigCanal]>=10){                                // Si el tiempo de rampa es igual o superior a 10 segundos
//         //         i8TrElec[i8ConfigCanal]=10;                                 // Inicializa a 10 segundos
//         //     }
//         // }

//         if(giPos<=1){
//             giPos=1;
//         }

//         if(giPos>=12){
//             giPos=12;
//         }
        
        
//         if(i8ConfigCanal==POINTER_C){                                       // Seleccion de los menus accesible en configuración del pointer

//             // if(!bascendente){                                               // Si estamos descendiendo en el menú    

//             //     if(giPos>1 && giPos<7){                                     // Se realizan las siguientes comprobaciones para que el selector
//             //         giPos=7;                                                // se situe sobra las opciones que nosotros deseamos, ya que el pointer
//             //     }else if(giPos>7 && giPos<10){                              // dispone de menos pntos de configuración y hemos de ir saltando 
//             //         giPos=10;                                               // las distintas opciones del menú
//             //     }else if(giPos>10 && giPos<13){
//             //         giPos=13;
//             //     }
//             // }else{                                                          // Si estamos ascendiendo en el menú
//             //     if(giPos>10 && giPos<13){                                   // Lo mismo que antes
//             //         giPos=10;
//             //     }else if(giPos>7 && giPos<10){
//             //         giPos=7;
//             //     }else if(giPos>1 && giPos<7){
//             //         giPos=1;
//             //     }
//             // }

//             if(giPos>=10){
//                 giPos=10;
//             }
//         }

//         // Added 06/04/2022 Para que salte la seleccion de modulacion si no estamos en el canal B
//         // if(i8ConfigCanal!=CHB_C){
//         //     if(bascendente && giPos==4){
//         //         giPos=3;
//         //     }
//         //     if(!bascendente && giPos==4){
//         //         giPos=5;
//         //     }
//         // }
        
//         pantalla_seleccion();                       // Colocamos los emoticonos
       
//         switch(i8ConfigCanal){                      // Dependiendo del canal que estemos configurando
//             case CHA_C:                             // Canal A
//                 // i8RepVal1=sCANAL_A;                 // Muestra el texto del canal A   
//                 mystring="CANAL A";
//                 break;
//             case CHB_C:                             // Canal B
//                 // i8RepVal1=sCANAL_B;                 // Muestra el texto del canal B
//                 mystring="CANAL B";
//                 break;
//             case CHC_C:                             // Canal C
//                 // i8RepVal1=sCANAL_C;                 // Muestra el texto del canal C
//                 mystring="CANAL C";
//                 break;
//             case POINTER_C:                         // Pointer
//                 // i8RepVal1=sCANAL_POINTER;           // Muestra el texto del pointer
//                 mystring="POINTER";
//                 break;
//         }
        
//         // if(bascendente){                // Si vamos hacia arriba
//         //     if(giPos==1){               // Si llegamos a la opción de simetria entre canales
//         //         giPos=0;                // Debemos de saltar esa opción
//         //     }
//         // }
//         // Added 05/04/2022 Espacio para actualizar el texto, ya que no hace falta entrar a configurar parámetro
//         if(giPos==1){
//             ST7529_printf("       ",COLUMNA_1,18,M_,giPos==1);                   // Borro lo la terapia que había antes
//         }
//         ST7529_printf(mystring,COLUMNA_1,18,M_,(giPos==1));                        // Muestra por pantalla los títulos

//         Calc_representacion_t(i16TacElec[i8ConfigCanal],i16TdElec[i8ConfigCanal]);  // Calcula la representación de tiempos
//         comprobacionLimitesFrecuencia();            // Comprueba los límites de frecuencia entre canales ((fA o fP)<=fB<=fC)
        
//         if(POINTER_C!=i8ConfigCanal){             // Si no estamos en el menu de configuración del pointer, se configuran los saltos de menú
            
//             if(!bPolaridadElec[i8ConfigCanal]){     // Si la señal es monopolar
                
//                 if(!bascendente){                   // Si estamos descendiendo en el menú
//                     if(giPos==11){                  // Si estamos en la configuración del preset
//                         giPos=12;                   // Salto a relisto...las siguientes condiciones e slo mismo dependiendo de su polaridad y simetria
//                     }
//                     if(giPos==9){
//                         giPos=10;
//                     }
//                 }else{                              // Si estamos ascendiendo en el menú
//                     if(giPos==11){                  // Lo mismo que antes
//                         giPos=10;                          
//                     }
//                     if(giPos==9){
//                         giPos=8;
//                     }
//                 }
            
//             }else{                                  // Si la señal es bipolar
//                 if(!bascendente){                   // Si estamos descendiendo en el menú
//                     if(bSimetriaElec[i8ConfigCanal]){   // Lo mismo que antes
//                         if(giPos==11){          
//                             giPos=12;           
//                         }
//                     }
//                 }else{                              // Si estamos ascendiendo en el menú
//                     if(bSimetriaElec[i8ConfigCanal]){   // Lo mismo que antes
//                         if(giPos==11){          
//                             giPos=10;           
//                         }
//                     }
//                 }
//             }


//             sprintf(mystring,"Ta=%2u:%02u s",i8Tmin,i8Tseg);                // Muestra tiempo Activo
//             ST7529_printfg(mystring,COLUMNA_1,FILA_INIT,M_,ai8EscalaGrises[0],(giPos==2));      // Por pantalla    
            
//             sprintf(mystring,"Td=%2u:%02u s",i8T1min,i8T1seg);              // Muestra tiempo Descanso/Reposo
//             ST7529_printfg(mystring,COLUMNA_2,FILA_INIT,M_,ai8EscalaGrises[0],(giPos==3));      // Por pantallla
            
//             bCondicion=(i16TdElec[i8ConfigCanal]==0);       // Si se cumple la condicion de que no hay tiempo de descanso definido
//             if(bCondicion){                                 // Si no hay tiempo de descanso
//                 i8Nrep[i8ConfigCanal]=1;                    // Fijamos el número de repeticiones a uno
//                 if(!bascendente){                           // Si estamos descendiendo en el menú
//                     if(giPos==5){                           // Si estamos en repeticiones
//                         giPos=6;                            // Saltamos ese campo ya que no podemos modificarlo
//                     }               
//                 }else{                                      // Si estamos ascendiendo en el menú
//                     if(giPos==5){                           // Si estamos en repeticiones
//                         giPos=4;                            // Saltamos ese campo ya que no podemos modificarlo
//                     }
//                 }
//             }

//             // Added 06/04/2022
//             if(i8ConfigCanal==CHB_C){
//                 switch(i8SeleccionMod){
//                     case MOD_NOT:
//                         i8RepVal1=sMOD_OFF;
//                         break;
//                     case MOD_FM:
//                         i8RepVal1=sMOD_FM;
//                         break;
//                     case MOD_AM:
//                         i8RepVal1=sMOD_AM;
//                         break;
//                     case MOD_FM_AM:
//                         i8RepVal1=sMOD_FM_AM;
//                         break;
//                     case MOD_PWM:
//                         i8RepVal1=sMOD_PWM;
//                         break;
//                     case MOD_FM_PWM:
//                         i8RepVal1=sMOD_FM_PWM;
//                         break;
//                 }
//                 ST7529_printfg(i8RepVal1,COLUMNA_2,18,M_,ai8EscalaGrises[0],(giPos==4));         // Por pantalla
//             }else{ 
//                 ST7529_printfg(sMOD_OFF,COLUMNA_2,18,M_,ai8EscalaGrises[1],(giPos==4));         // Por pantalla
//                 i8SeleccionMod=0;
//             }
            
//             sprintf(mystring,"N=%2u      ",i8Nrep[i8ConfigCanal]);              // Número de repeticiones
//             ST7529_printfg(mystring,COLUMNA_2,FILA_1,M_,ai8EscalaGrises[bCondicion],(giPos==5));    // Por pantalla    // Pongo bCondicion|bGristPointer, apra que sea un OR, es decir, el bit que primero s eponga a 1, manda
            
//             sprintf(mystring,"I=%5lu[A  ",i16IElec[i8ConfigCanal]*50);      // Muestra la corriente configurada para cada canal
//             ST7529_printfg(mystring,COLUMNA_1,FILA_2,M_,ai8EscalaGrises[0],giPos==6);           // Muetsra por pantalla la corriente

//             if(i8SeleccionMod==MOD_FM || i8SeleccionMod==MOD_FM_AM || i8SeleccionMod==MOD_FM_PWM){
//                 bCondicion=1;
//                 sprintf(mystring1,"F=%3lu-%3luHz",i16FrecInicialMod,i16FrecFinalMod);     // Muestra la frecuencia configurada para cada canal
//             }else{
//                 bCondicion=0;
//                 sprintf(mystring1,"F=%4luHz  ",i16frecElec[i8ConfigCanal]);     // Muestra la frecuencia configurada para cada canal
//             }
//             ST7529_printfg(mystring1,COLUMNA_2,FILA_2,M_,ai8EscalaGrises[bCondicion],giPos==7);          // Muestra por pantalla la frecuencia en negrita 
            
//             if(bPolaridadElec[i8ConfigCanal]){              // Si se trata de una señal bipolar
//                 i8RepVal1=sBIPOLAR;                         // Indico bipolar   
//                 if(i16PW_minusElec[i8ConfigCanal]==0){      // Si el ancho de pulso positivo es igual a cero
//                     i16PW_minusElec[i8ConfigCanal]=100;     // Inicializamos a 100 (mínimo)
//                 }
//             }else{                                          // Si se trata de una señal monopolar
//                 i8RepVal1=sMONOPOLAR;                       // Indico monopolar
//                 bSimetriaElec[i8ConfigCanal]=0;             // Indico señal asimétrica
//                 i16PW_minusElec[i8ConfigCanal]=0;           // Pongo ancho de pulso negativo a 0
//             }
            
//             bCondicion=(i8SimetriaCanales==1 && i8ConfigCanal==CHB_C);                              // Creamos esta condicion
//             bCondicion|=(i8SimetriaCanales==2 && (i8ConfigCanal==CHB_C||i8ConfigCanal==CHC_C));     // de dos lineas
            
//             ST7529_printfg(i8RepVal1,COLUMNA_1,FILA_3,M_,ai8EscalaGrises[bCondicion],giPos==8);     // Muestra por pantalla la polaridad en negrita (modificable) o en gris (no modificable)

//             if(bSimetriaElec[i8ConfigCanal] || i8SeleccionMod!=MOD_NOT){                                   // Si la señal es simétrica
//                 i8RepVal1=sSIMETRICA;                                           // Indico simetría 
//                 i16PW_minusElec[i8ConfigCanal]=i16PW_plusElec[i8ConfigCanal];   // Copio valores del PW+ en PW-
//             }else{                                                              // Si la señal es asimétrica
//                 i8RepVal1=sASIMETRICA;                                          // Indico asimetría
//             }
//             if(i8SeleccionMod!=MOD_NOT){
//                 bCondicion=1;
//             }else{
//                 bCondicion=(i8SimetriaCanales==1 && i8ConfigCanal==CHB_C);                          // Se crea
//                 bCondicion|=(i8SimetriaCanales==2 && (i8ConfigCanal==CHB_C||i8ConfigCanal==CHC_C)); // esta condición
//                 bCondicion|=!(bPolaridadElec[i8ConfigCanal]);     
//             }
//             ST7529_printfg(i8RepVal1,COLUMNA_2,FILA_3,M_,ai8EscalaGrises[bCondicion],giPos==9); // Muestra por pantalla la simetría en negrita (modificable) o en gris (no modificable)

//             // Bloque de calculo del PW positivo y negativo
//             if(i8SeleccionMod!=MOD_PWM && i8SeleccionMod!=MOD_FM_PWM){
//                 int32 max_pw;

//                 if(i8SeleccionMod==MOD_FM || i8SeleccionMod==MOD_FM_AM){
//                     max_pw=(1.0/i16FrecFinalMod)*(1000000*0.9);
//                 }else{
//                     max_pw=(1.0/i16frecElec[i8ConfigCanal])*(1000000*0.9);
//                 }
//                 if(bPolaridadElec[i8ConfigCanal]){
//                     max_pw/=2;
//                 }

//                 if(max_pw>10000){
//                     max_pw=(int32)((max_pw/5000.0)+0.5)*5000;
//                 }

//                 if(max_pw>1000 && max_pw<=10000){
//                     max_pw=(int32)((max_pw/1000.0)+0.5)*1000;
//                 }

//                 if(i16PW_plusElec[i8ConfigCanal]>=max_pw){
//                     i16PW_plusElec[i8ConfigCanal]=max_pw;
//                 }

//                 if(i16PW_minusElec[i8ConfigCanal]>=max_pw){
//                     i16PW_minusElec[i8ConfigCanal]=max_pw;
//                 }

//                 maxBW=max_pw/25;
//             }
//             // Fin bloque de calculo del PW positivo y negativo

//             bCondicion=(i8SimetriaCanales==1 && i8ConfigCanal==CHB_C);                          // Se crea esta condición
//             bCondicion|=(i8SimetriaCanales==2 && (i8ConfigCanal==CHB_C||i8ConfigCanal==CHC_C)); // de dos lineas

//             if(i8SeleccionMod==MOD_PWM || i8SeleccionMod==MOD_FM_PWM){
//                 sprintf(mystring,"PWmin %3lu%cs",conversionPW(i32PWInicialMod),cAux);
//                 sprintf(mystring1,"PWmax %3lu%cs",conversionPW(i32PWFinalMod),cAux);
//                 bCondicion|=1;
//             }else{
//                 sprintf(mystring,"PW+=%4lu%cs",conversionPW(i16PW_plusElec[i8ConfigCanal]),cAux);
//                 sprintf(mystring1,"PW-=%4lu%cs",conversionPW(i16PW_minusElec[i8ConfigCanal]),cAux);
//                 // bCondicion|=0;
//             }

//             ST7529_printfg(mystring,COLUMNA_1,FILA_4,M_,ai8EscalaGrises[bCondicion],giPos==10);
//             ST7529_printfg(mystring1,COLUMNA_2,FILA_4,M_,ai8EscalaGrises[bCondicion],giPos==11);
//         }else{                                                                      // Si estamos configurando el pointer
//             ST7529_printfg(sTa_0,COLUMNA_1,FILA_INIT,M_,ai8EscalaGrises[1],(giPos==2));      // Por pantalla
//             ST7529_printfg(sTd_0,COLUMNA_2,FILA_INIT,M_,ai8EscalaGrises[1],(giPos==3));
//             ST7529_printfg(sMOD_OFF,COLUMNA_1,FILA_1,M_,ai8EscalaGrises[1],(giPos==4));
//             ST7529_printfg(sN_0,COLUMNA_2,FILA_1,M_,ai8EscalaGrises[1],(giPos==5));    // Por pantalla
//             ST7529_printfg(sI_min,COLUMNA_1,FILA_2,M_,ai8EscalaGrises[1],giPos==6);           // Muetsra por pantalla la corriente
//             ST7529_printfg("MONOPOLAR",COLUMNA_1,FILA_3,M_,ai8EscalaGrises[1],giPos==8);     // Muestra por pantalla la polaridad en negrita (modificable) o en gris (no modificable)
//             ST7529_printfg(sSIMETRICA,COLUMNA_2,FILA_3,M_,ai8EscalaGrises[1],giPos==9); // Muestra por pantalla la simetría en negrita (modificable) o en gris (no modificable)
//             ST7529_printfg(sPW_neg_0,COLUMNA_2,FILA_4,M_,ai8EscalaGrises[1],giPos==11); // por pantalla en negrita (modificable) o en gris (no modificable) 

//             i16IElec[i8ConfigCanal]=2*MINIMA_CORRIENTE_ELECTROESTIMULACION;         // Init a 200 uA
//             if(iMenuAnterior==140){                                                 // Si venimos del menú de tratamiento
//                 i16frecElec[i8ConfigCanal]=10;                                      // Inicializa el valor de frecuencia
//             }
//             sprintf(mystring1,"F=%4luHz  ",i16frecElec[i8ConfigCanal]);             // Muestra la frecuencia configurada para el pointer
//             ST7529_printf(mystring1,COLUMNA_2,FILA_2,M_,giPos==7);                  // Muestra por pantalla la frecuencia
                
//             if(i16PW_plusElec[i8ConfigCanal]<1000){    
//                 sprintf(mystring,"PW =%4lu[s",i16PW_plusElec[i8ConfigCanal]);            // Muestra el texto del PW
//             }else{
//                 sprintf(mystring,"PW =%4lums",i16PW_plusElec[i8ConfigCanal]/1000);            // Muestra el texto del PW
//             }
//             ST7529_printf(mystring,COLUMNA_1,FILA_4,M_,giPos==10);                  // Muestra el texto por pantalla
                    
//             i16PW_minusElec[i8ConfigCanal]=i16PW_plusElec[i8ConfigCanal];           // Asignamos el ancho de pulso positivo al negativo (Pointer es bipolar simétrico)
//             bPolaridadElec[i8ConfigCanal]=1;                                        // Inicializo flag de polaridad (Bipolar)
//             bSimetriaElec[i8ConfigCanal]=1;                                         // Inicializo flag de simetria (Simétrica)
//         }
        
//         // ST7529_printf(sCONFIG_TRAT,COLUMNA_1,FILA_RELISTO,M_,giPos==13);            // Activo botón relisto
        
//         ST7529_printf(sGUARDAR_PRESET,COLUMNA_1,FILA_RELISTO,M_,giPos==12);            // Activo botón relisto
       
//         iMenuAnterior=iMenuActual;                                                  // Copia el valor del menú actual a menú anterior
//     }
    
//     bRefrescoPantalla=0;                                                            // Inicializo flag de refresco de pantalla

//     return 0;                                                                       // Return 0
// }

/*
*   Función: menu_40 NEW
*   Descripción: Menú de electroestimulación
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_40(){

    #ifndef SOLO_TDCS                // Versión solo tDCS

    if(bRefrescoPantalla){                                                  // Si ha cambiado algún valor
                       
        int1 bCondicion=0;                                                  // Variable utilizada conmo condicional de escala de grises en texto
                     
        if((iMenuAnterior!=40)||(bborrado==1)){                             // Si vengo de otro menu debo borrar la basurilla
            if(iMenuAnterior!=48){                                          // Si el menú anterior es distinto al menú de configuración de frecuencia en electroestimulación
                gF=1;                                                       // Pongo a uno para inicializar la parte de frecuencias con la rulancha
            }
            ST7529_clear();                                                 // Limpio pantalla  
            ST7529_printf(sELECTRO_ESTIMULACION,0,0,L_,NORMAL);             // Muestro título de electroestimulación
            i8VariablesPreset=PRESET_ELECTRO;                               // Preset Electro
            i8SeleccionTerapia=3;
            bborrado=0;                                                     // Inicializo limpieza de pantalla 

            // Calc_representacion_t(i16TacElec[i8ConfigCanal],i16TdElec[i8ConfigCanal]);      // Calculo representación de tiempo
            if(i8ConfigCanal==POINTER_C){  // Si estamos en el menú de config. del pointer y no venimos de los menús de frecuencia, corrinete o PW (menus de config. del pointer)
                // i16frecElec[POINTER_C]=10;                                  // Inicializa el valor de frecuencia a 10 Hz
                // i16PW_plusElec[POINTER_C]=250;
                // i16PW_minusElec[POINTER_C]=250;
                // i16TimeRaw[POINTER_C]=60;
                
            }
            giPosRulancha=i8ConfigCanal;
        }

        // Addded 11/05/2022 Preset de modulación
        i8VariablesPreset=PRESET_MOD;                                   // Preset MOD

        if(i8SeleccionMod==MOD_NOT){
            i8VariablesPreset=PRESET_ELECTRO;                               // Preset Electro
        }
        
        if(i16IElec[i8ConfigCanal]>=MAXIMA_CORRIENTE_INICIO_ELECTRO){       // Si la corriente es superior a 20*50=1000uA 
            i16IElec[i8ConfigCanal]=MAXIMA_CORRIENTE_INICIO_ELECTRO;        // Inicializa a 1000uA
        }
        
        // if(iMenuAnterior==140 && bPausaTratamiento){                        // Si estabamos en el menú de tratamiento y habiamos pausado
        //     bPausaTratamiento=0;                                            // Inicializo pausa
        //     if(i16IElec[i8ConfigCanal]>=MAXIMA_CORRIENTE_INICIO_ELECTRO){   // Si la corriente es superior a 20*50=1000uA 
        //         i16IElec[i8ConfigCanal]=MAXIMA_CORRIENTE_INICIO_ELECTRO;    // Inicializa a 1000uA
        //     }
        // }

        if(giPos<=1){
            giPos=1;
        }

        if(giPos>=15){
            giPos=15;
        }
        
        if(i8ConfigCanal==POINTER_C){                                       // Seleccion de los menus accesible en configuración del pointer
            if(giPos>=13){
                giPos=13;
            }
        }
        
        pantalla_seleccion();                       // Colocamos los emoticonos
       
        switch(i8ConfigCanal){                      // Dependiendo del canal que estemos configurando
            case CHA_C:                             // Canal A
                i8RepVal1=sSEL_CANAL_A;                 // Muestra el texto del canal A   
                break;
            case CHB_C:                             // Canal B
                i8RepVal1=sSEL_CANAL_B;                 // Muestra el texto del canal B
                break;
            case CHC_C:                             // Canal C
                i8RepVal1=sSEL_CANAL_C;                 // Muestra el texto del canal C
                break;
            case POINTER_C:                         // Pointer
                i8RepVal1=sSEL_POINTER;           // Muestra el texto del pointer
                break;
        }

        // Added 05/04/2022 Espacio para actualizar el texto, ya que no hace falta entrar a configurar parámetro
        // if(giPos==1){
        //     ST7529_printf("          ",COLUMNA_1,18,M_,giPos==1);                   // Borro lo la terapia que había antes
        // }
        ST7529_printf(i8RepVal1,COLUMNA_1,18,M_,(giPos==1));                        // Muestra por pantalla los títulos

        Calc_representacion_t(i16TacElec[i8ConfigCanal],i16TdElec[i8ConfigCanal]);  // Calcula la representación de tiempos
        comprobacionLimitesFrecuencia();            // Comprueba los límites de frecuencia entre canales ((fA o fP)<=fB<=fC)
        
        if(POINTER_C!=i8ConfigCanal){             // Si no estamos en el menu de configuración del pointer, se configuran los saltos de menú
            
            if(i8SeleccionMod!=MOD_FM_PWM && i8SeleccionMod!=MOD_PWM){
                if(!bPolaridadElec[i8ConfigCanal]){     // Si la señal es monopolar
                    
                    if(!bascendente){                   // Si estamos descendiendo en el menú
                        if(giPos==14){                  // Si estamos en la configuración del preset
                            giPos=15;                   // Salto a relisto...las siguientes condiciones e slo mismo dependiendo de su polaridad y simetria
                        }
                        if(giPos==10){
                            giPos=11;
                        }
                    }else{                              // Si estamos ascendiendo en el menú
                        if(giPos==14){                  // Lo mismo que antes
                            giPos=13;                          
                        }
                        if(giPos==10){
                            giPos=9;
                        }
                    }
                
                }else{                                  // Si la señal es bipolar
                    if(!bascendente){                   // Si estamos descendiendo en el menú
                        if(bSimetriaElec[i8ConfigCanal]){   // Lo mismo que antes
                            if(giPos==14){          
                                giPos=15;           
                            }
                        }
                    }else{                              // Si estamos ascendiendo en el menú
                        if(bSimetriaElec[i8ConfigCanal]){   // Lo mismo que antes
                            if(giPos==14){          
                                giPos=13;           
                            }
                        }
                    }
                }
            }

            // Added 06/04/2022
            bCondicion=(i8ConfigCanal!=CHB_C);
            // bFMDesactivado=1;
            bAMDesactivado=1;
            // bPWMDesactivado=1;
            i8RepVal1=sMOD_OFF;
            if(bCondicion){
                i8SeleccionMod=MOD_NOT;
            }

            if(!bCondicion){
                if(i8SeleccionMod==MOD_FAA || i8SeleccionMod==MOD_AM || i8SeleccionMod==MOD_FM_AM){
                    bAMDesactivado=0;
                }
                switch(i8SeleccionMod){
                    case MOD_NOT:
                        break;
                    case MOD_FM:
                        i8RepVal1=sMOD_FM;
                        // bFMDesactivado=0;
                        // bAMDesactivado=1;
                        // bPWMDesactivado=1;
                        break;
                    case MOD_FAA:
                        i8RepVal1=sMOD_FAA;
                        // bFMDesactivado=0;
                        // bAMDesactivado=0;
                        // bPWMDesactivado=1;
                        break;
                    case MOD_AM:
                        i8RepVal1=sMOD_AM;
                        // bFMDesactivado=1;
                        // bAMDesactivado=0;
                        // bPWMDesactivado=1;
                        break;
                    case MOD_FM_AM:
                        i8RepVal1=sMOD_FM_AM;
                        // bFMDesactivado=0;
                        // bAMDesactivado=0;
                        // bPWMDesactivado=1;
                        break;
                    case MOD_PWM:
                        i8RepVal1=sMOD_PWM;
                        // bFMDesactivado=1;
                        // bAMDesactivado=1;
                        // bPWMDesactivado=0;
                        break;
                    case MOD_FM_PWM:
                        i8RepVal1=sMOD_FM_PWM;
                        // bFMDesactivado=0;
                        // bAMDesactivado=1;
                        // bPWMDesactivado=0;
                        break;
                }
            }

            ST7529_printfg(i8RepVal1,COLUMNA_2,18,M_,ai8EscalaGrises[bCondicion],(giPos==2));         // Por pantalla


            sprintf(mystring,"Ta=%2u:%02u s",i8Tmin,i8Tseg);                // Muestra tiempo Activo
            ST7529_printfg(mystring,COLUMNA_1,FILA_INIT,M_,ai8EscalaGrises[0],(giPos==3));      // Por pantalla    
            

            sprintf(mystring,"Td=%2u:%02u s",i8T1min,i8T1seg);              // Muestra tiempo Descanso/Reposo
            ST7529_printfg(mystring,COLUMNA_2,FILA_INIT,M_,ai8EscalaGrises[0],(giPos==4));      // Por pantallllllla

            //Inicio bloque calculo minimo Tmod y Imod en tiempo real
            if(i8SeleccionMod==MOD_FAA){
                min_Tmod=MINIMO_TMOD_ALTERNA;
                min_Imod=min_Imod;
            }else{
                min_Tmod=MINIMO_TMOD_BARRIDO;
                min_Imod=min_Imod;
            }

            if(i8Tmodulacion<=min_Tmod){
                i8Tmodulacion=min_Tmod;
            }

            if(i8ModulacionAM<=min_Imod){
                i8ModulacionAM=min_Imod;
            }
                                  

            if(i8ModulacionAM>i16IElec[i8ConfigCanal]/2){
                

                max_Imod=i16IElec[i8ConfigCanal]/2;
                i8ModulacionAM=max_Imod;
            }
            else{
                max_Imod=i16IElec[i8ConfigCanal]/2;
            }
            
 
            
            //Fin bloque calculo minimo Tmod y Imod en tiempo real

            bCondicion=(i8SeleccionMod==MOD_NOT);

            sprintf(mystring,"Tmod=%3us  ",i8Tmodulacion);              // Número de repeticiones
            ST7529_printfg(mystring,COLUMNA_1,FILA_1,M_,ai8EscalaGrises[bCondicion],(giPos==5));


            bCondicion=(i16TdElec[i8ConfigCanal]==0);       // Si se cumple la condicion de que no hay tiempo de descanso definido
            if(bCondicion){                                 // Si no hay tiempo de descanso
                i8Nrep[i8ConfigCanal]=1;                    // Fijamos el número de repeticiones a uno
                if(!bascendente){                           // Si estamos descendiendo en el menú
                    if(giPos==6){                           // Si estamos en repeticiones
                        giPos=7;                            // Saltamos ese campo ya que no podemos modificarlo
                    }               
                }else{                                      // Si estamos ascendiendo en el menú
                    if(giPos==6){                           // Si estamos en repeticiohijguukygbhnespolla
                        giPos=5;                            // Saltamos ese campo ya que no podemos modificarlo
                    }
                }
            }
            
            sprintf(mystring,"N=%2u      ",i8Nrep[i8ConfigCanal]);              // Número de repeticiones
            ST7529_printfg(mystring,COLUMNA_2,FILA_1,M_,ai8EscalaGrises[bCondicion],(giPos==6));    // Por pantalla    // Pongo bCondicion|bGristPointer, apra que sea un OR, es decir, el bit que primero s eponga a 1, manda
            

            sprintf(mystring,"I=%5lu[A  ",i16IElec[i8ConfigCanal]*50);      // Muestra la corriente configurada para cada canal
            ST7529_printfg(mystring,COLUMNA_1,FILA_2,M_,ai8EscalaGrises[0],giPos==7);           // Muetsra por pantalla la corriente


            sprintf(mystring,"Imin=%5lu[A  ",(int16)i8ModulacionAM*100);
            ST7529_printfg(mystring,COLUMNA_2,FILA_2,M_,ai8EscalaGrises[bAMDesactivado],giPos==8);
            

            if(bPolaridadElec[i8ConfigCanal]){              // Si se trata de una señal bipolar
                i8RepVal1=sBIPOLAR;                         // Indico bipolar   
                if(i16PW_minusElec[i8ConfigCanal]==0){      // Si el ancho de pulso positivo es igual a cero
                    i16PW_minusElec[i8ConfigCanal]=100;     // Inicializamos a 100 (mínimo)
                }
            }else{                                          // Si se trata de una señal monopolar
                i8RepVal1=sMONOPOLAR;                       // Indico monopolar
                bSimetriaElec[i8ConfigCanal]=0;             // Indico señal asimétrica
                i16PW_minusElec[i8ConfigCanal]=0;           // Pongo ancho de pulso negativo a 0
            }

            
            bCondicion=(i8SimetriaCanales==1 && i8ConfigCanal==CHB_C);                              // Creamos esta condicion
            bCondicion|=(i8SimetriaCanales==2 && (i8ConfigCanal==CHB_C||i8ConfigCanal==CHC_C));     // de dos lineas
            
            ST7529_printfg(i8RepVal1,COLUMNA_1,FILA_3,M_,ai8EscalaGrises[bCondicion],giPos==9);     // Muestra por pantalla la polaridad en negrita (modificable) o en gris (no modificable)


            if(bSimetriaElec[i8ConfigCanal] || i8SeleccionMod!=MOD_NOT){                                   // Si la señal es simétrica
                i8RepVal1=sSIMETRICA;                                           // Indico simetría 
                i16PW_minusElec[i8ConfigCanal]=i16PW_plusElec[i8ConfigCanal];   // Copio valores del PW+ en PW-
            }else{                                                              // Si la señal es asimétrica
                i8RepVal1=sASIMETRICA;                                          // Indico asimetría
            }

            if(i8SeleccionMod!=MOD_NOT){
                bCondicion=1;
            }else{
                bCondicion=(i8SimetriaCanales==1 && i8ConfigCanal==CHB_C);                          // Se crea
                bCondicion|=(i8SimetriaCanales==2 && (i8ConfigCanal==CHB_C||i8ConfigCanal==CHC_C)); // esta condición
                bCondicion|=!(bPolaridadElec[i8ConfigCanal]);     
            }

            ST7529_printfg(i8RepVal1,COLUMNA_2,FILA_3,M_,ai8EscalaGrises[bCondicion],giPos==10); // Muestra por pantalla la simetría en negrita (modificable) o en gris (no modificable)


            if(i8SeleccionMod==MOD_FM || i8SeleccionMod==MOD_FM_AM || i8SeleccionMod==MOD_FM_PWM || i8SeleccionMod==MOD_FAA){
                bCondicion=0;
                sprintf(mystring,"Fmin=%3luHz",i16FrecInicialMod);     // Muestra la frecuencia configurada para cada canal
                sprintf(mystring1,"Fmax=%3luHz",i16FrecFinalMod);     // Muestra la frecuencia configurada para cada canal
            }else{
                bCondicion=1;
                sprintf(mystring,"F=%4luHz  ",i16frecElec[i8ConfigCanal]);     // Muestra la frecuencia configurada para cada canal
                sprintf(mystring1,"F=%4luHz  ",i16frecElec[i8ConfigCanal]);     // Muestra la frecuencia configurada para cada canal
            }

            ST7529_printfg(mystring,COLUMNA_1,FILA_4,M_,ai8EscalaGrises[0],giPos==11);          // Muestra por pantalla la frecuencia en negrita 
            ST7529_printfg(mystring1,COLUMNA_2,FILA_4,M_,ai8EscalaGrises[bCondicion],giPos==12);          // Muestra por pantalla la frecuencia en negrita 

            // Bloque de calculo del PW positivo y negativo / maximo y mínimo
            int32 max_pw;
            if(i8SeleccionMod!=MOD_PWM && i8SeleccionMod!=MOD_FM_PWM){

                if(i8SeleccionMod==MOD_FM || i8SeleccionMod==MOD_FM_AM || i8SeleccionMod==MOD_FAA){
                    max_pw=(1.0/i16FrecFinalMod)*(1000000*0.9);
                }else{
                    max_pw=(1.0/i16frecElec[i8ConfigCanal])*(1000000*0.9);
                }
                if(bPolaridadElec[i8ConfigCanal]){
                    max_pw/=2;
                }

                if(max_pw>10000){
                    max_pw=(int32)((max_pw/5000.0)+0.5)*5000;
                }

                if(max_pw>1000 && max_pw<=10000){
                    max_pw=(int32)((max_pw/1000.0)+0.5)*1000;
                }

                if(i16PW_plusElec[i8ConfigCanal]>=max_pw){
                    i16PW_plusElec[i8ConfigCanal]=max_pw;
                }

                if(i16PW_minusElec[i8ConfigCanal]>=max_pw){
                    i16PW_minusElec[i8ConfigCanal]=max_pw;
                }

                maxBW=max_pw/25;
            }else if(i8SeleccionMod==MOD_PWM || i8SeleccionMod==MOD_FM_PWM){
                if(i8SeleccionMod==MOD_PWM){
                    max_pw=(1.0/i16frecElec[CHB_C])*(1000000*0.9);
                }

                if(i8SeleccionMod==MOD_FM_PWM){
                    max_pw=(1.0/i16FrecFinalMod)*(1000000*0.9);
                }

                if(bPolaridadElec[CHB_C]){
                    max_pw/=2;
                }

                // if(i32PWFinalMod>1000){
                //     aux_lim=1000;
                //     if(i32PWFinalMod>10000){
                //         aux_lim=5000;
                //     }
                // }

                // if(i32PWInicialMod>=i32PWFinalMod){
                //     i32PWInicialMod=i32PWFinalMod-aux_lim;
                // }

                if(max_pw>10000){
                    max_pw=(int32)((max_pw/5000.0)+0.5)*5000;
                }

                if(max_pw>1000 && max_pw<=10000){
                    max_pw=(int32)((max_pw/1000.0)+0.5)*1000;
                }

                if(i32PWFinalMod>=max_pw){
                    i32PWFinalMod=max_pw;
                }

                maxBW=max_pw/25;
            }
            // Fin bloque de calculo del PW positivo y negativo / maximo y mínimo

            bCondicion=(i8SimetriaCanales==1 && i8ConfigCanal==CHB_C);                          // Se crea esta condición
            bCondicion|=(i8SimetriaCanales==2 && (i8ConfigCanal==CHB_C||i8ConfigCanal==CHC_C)); // de dos lineas

            if(i8SeleccionMod==MOD_PWM || i8SeleccionMod==MOD_FM_PWM){
                sprintf(mystring,"PWmax %3lu%cs",conversionPW(i32PWFinalMod),cAux);
                sprintf(mystring1,"PWmin %3lu%cs",conversionPW(i32PWInicialMod),cAux);                
            }else{
                sprintf(mystring,"PW+= %4lu%cs",conversionPW(i16PW_plusElec[i8ConfigCanal]),cAux);
                sprintf(mystring1,"PW-= %4lu%cs",conversionPW(i16PW_minusElec[i8ConfigCanal]),cAux);
            }

            ST7529_printfg(mystring,COLUMNA_1,FILA_5,M_,ai8EscalaGrises[bCondicion],giPos==13);
            bCondicion|=(i8SeleccionMod!=MOD_PWM && i8SeleccionMod!=MOD_FM_PWM) && (!bpolaridadElec[i8ConfigCanal] || bsimetriaElec[i8ConfigCanal]);
            ST7529_printfg(mystring1,COLUMNA_2,FILA_5,M_,ai8EscalaGrises[bCondicion],giPos==14);

            ST7529_printf(sGUARDAR_PRESET,COLUMNA_1,FILA_RELISTO,M_,giPos==15);            // Activo botón relisto

        }else{                                                                      // Si estamos configurando el pointer
            ST7529_printfg(sMOD_OFF,COLUMNA_2,18,M_,ai8EscalaGrises[1],0);      // Por pantalla
            ST7529_printfg(sTa_0,COLUMNA_1,FILA_INIT,M_,ai8EscalaGrises[1],0);      // Por pantalla
            ST7529_printfg(sTd_0,COLUMNA_2,FILA_INIT,M_,ai8EscalaGrises[1],0);
            ST7529_printfg("Tmod=  0s",COLUMNA_1,FILA_1,M_,ai8EscalaGrises[1],0);
            ST7529_printfg(sN_0,COLUMNA_2,FILA_1,M_,ai8EscalaGrises[1],0);    // Por pantalla
            ST7529_printfg(sI_min,COLUMNA_1,FILA_2,M_,ai8EscalaGrises[1],0);           // Muetsra por pantalla la corriente
            sprintf(mystring,"Imin=%5lu[A  ",(int16)i8ModulacionAM*100);
            // ST7529_printfg(mystring,COLUMNA_2,FILA_2,M_,ai8EscalaGrises[bAMDesactivado],giPos==8);
            // sprintf(mystring,"Imod= 0%c",37);
            ST7529_printfg(mystring,COLUMNA_2,FILA_2,M_,ai8EscalaGrises[1],0);           // Muetsra por pantalla la corriente
            ST7529_printfg("BIPOLAR",COLUMNA_1,FILA_3,M_,ai8EscalaGrises[1],0);     // Muestra por pantalla la polaridad en negrita (modificable) o en gris (no modificable)
            ST7529_printfg(sSIMETRICA,COLUMNA_2,FILA_3,M_,ai8EscalaGrises[1],0); // Muestra por pantalla la simetría en negrita (modificable) o en gris (no modificable)
            sprintf(mystring1,"F=%4luHz  ",i16frecElec[i8ConfigCanal]);             // Muestra la frecuencia configurada para el pointer
            ST7529_printfg(mystring1,COLUMNA_2,FILA_4,M_,ai8EscalaGrises[1],0);                  // Muestra por pantalla la frecuencia
            // ST7529_printfg(sPW_neg_0,COLUMNA_2,FILA_5,M_,ai8EscalaGrises[1],0); // por pantalla en negrita (modificable) o en gris (no modificable) 

            i16IElec[i8ConfigCanal]=2*MINIMA_CORRIENTE_ELECTROESTIMULACION;         // Init a 200 uA
            // if(iMenuAnterior==140){                                                 // Si venimos del menú de tratamiento //YA NO SE INICIALIZA EL VALOR DE LA FRECUENCIA
            //     i16frecElec[i8ConfigCanal]=10;                                      // Inicializa el valor de frecuencia
            // }
            sprintf(mystring1,"F=%4luHz  ",i16frecElec[i8ConfigCanal]);             // Muestra la frecuencia configurada para el pointer
            ST7529_printf(mystring1,COLUMNA_1,FILA_4,M_,giPos==11);                  // Muestra por pantalla la frecuencia
                
            sprintf(mystring,"PW+= %4lu%cs",conversionPW(i16PW_plusElec[i8ConfigCanal]),cAux);
            ST7529_printf(mystring,COLUMNA_1,FILA_5,M_,giPos==13);                  // Muestra el texto por pantalla

            i16PW_minusElec[i8ConfigCanal]=i16PW_plusElec[i8ConfigCanal];           // Asignamos el ancho de pulso positivo al negativo (Pointer es bipolar simétrico)
            
            sprintf(mystring,"PW-= %4lu%cs",conversionPW(i16PW_minusElec[i8ConfigCanal]),cAux);
            ST7529_printfg(mystring,COLUMNA_2,FILA_5,M_,ai8EscalaGrises[1],0);

            bPolaridadElec[i8ConfigCanal]=1;                                        // Inicializo flag de polaridad (Bipolar)
            bSimetriaElec[i8ConfigCanal]=1;                                         // Inicializo flag de simetria (Simétrica)

            i16TimeRaw[i8ConfigCanal]=TIEMPO_POINTER;        // Tiempo fijo del pointer de 20 minutos
            ST7529_printfg(sGUARDAR_PRESET,COLUMNA_1,FILA_RELISTO,M_,ai8EscalaGrises[1],0); // En funcion de si estamos en el pointer o no, se muestra en gris.
        }
        
        
        
       
        iMenuAnterior=iMenuActual;                                                  // Copia el valor del menú actual a menú anterior
    }
    
    bRefrescoPantalla=0;                                                            // Inicializo flag de refresco de pantalla

    return 0;                                                                       // Return 0

    #endif

}

/*
*   Función: menu_80
*   Descripción: Menú del sistema ThetaBurst
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_80(){  

    if(bRefrescoPantalla){                                      // Si debo de refrecar la pantalla

        int16 i8Minimo;
        float fMin;
        int1 bCondicion=0;

        #ifdef SMP_CAPADA

            if(iMenuAnterior!=80){                                  // Si el menú anterior no es el menú principal de TB
                bPausaTratamiento=0;    
                if(iMenuAnterior!=83){                              // Si el menú anterior no es el de error de electrodo
                    gF=1;                                           // Pongo a uno para inicializar la parte de frecuencias con la rulancha
                }
                ST7529_clear();                                     // Limpia la pantalla
                ST7529_printf(sSMP,0,0,L_,NORMAL);                  // Pone el título de SMP
                i8VariablesPreset=PRESET_TB;                       // Preset TB
                i8SeleccionTerapia=2;
                if(iMenuAnterior==180){                             // Si el menú anterior era el de tratamiento con tratamiento apagado
                    giPosRulancha=i16CorrienteTB;                   // Pongo en la rulancha el valor de corriente del menú
                    giPos=8;                                                // Inicializo gipos
                }
                if(giPos==8){                                               // si giPos está sobre el bloque de bPolaridadTB en el menú de configuración
                    giPosRulancha=i16CorrienteTB;                  // Pongo en la rulancha el valor de corriente del menú
                }
            }  
            
            if (giPos>10){                                           // Si llega a la última posición del menú
                giPos=10;                                            // Mantiene el cursor ahí
            }
            
            if(giPos<=8){                                           // Si llega a la primera posición del cursor
                giPos=8;                                            // Mantiene el cursor ahí
            }
            
            pantalla_seleccion();                                     // Muestra los iconos de la interfaz
            
            // i8RepVal1=sMONOPOLAR;                                     // Indico monopolar

            // if(bPolaridadTB){                                         // Si se trata de una señal bipolar
            //     i8RepVal1=sBIPOLAR;                                   // Indico bipolar   
            // }
            
            i8RepVal1=sBIPOLAR;                                   // Indico bipolar   

            ST7529_printfg(i8RepVal1,COLUMNA_1,FILA_INIT,M_,ai8EscalaGrises[SMP_CAPADA],giPos==0);     // Muestra por pantalla la polaridad


            sprintf(mystring,"PW=%4LU [s",i16PWBurstTB);                    // Muestra ancho de pulso
            ST7529_printfg(mystring,COLUMNA_2,FILA_INIT,M_,ai8EscalaGrises[SMP_CAPADA],(giPos==1));
            
            
            sprintf(mystring,"NP=%4lu",i16NPulsosBurstTB);                    // Muestra numero de pulsos
            ST7529_printfg(mystring,COLUMNA_1,FILA_1,M_,ai8EscalaGrises[SMP_CAPADA],(giPos==2));

            // Inicio de bloque de calculo de mínima separación entre pulsos
            fMin=(i16PWBurstTB)/1000;

            if(bPolaridadTB){
                fMin=2*(i16PWBurstTB)/1000;
            }

            i8Minimo=(int16)fMin+1;

            if(fMin<MIN_SEP_PULSOS){
                i8Minimo=MIN_SEP_PULSOS;
            }

            if(i8SepPulsosTB<=i8Minimo){
                i8SepPulsosTB=i8Minimo;
            }
            // Fin de bloque de calculo de mínima separación entre pulsos

            int8 sep_pulsos_aux=0;
            bCondicion=(i16NPulsosBurstTB<=1);

            if(!bCondicion){
                sep_pulsos_aux=i8SepPulsosTB;
            }

            sprintf(mystring,"SP=%4u ms",sep_pulsos_aux);                    // Muestra separacion entre pulsos
            
            ST7529_printfg(mystring,COLUMNA_2,FILA_1,M_,ai8EscalaGrises[SMP_CAPADA],(giPos==3));   // SMP CAPADA
            //ST7529_printfg(mystring,COLUMNA_2,FILA_1,M_,ai8EscalaGrises[bCondicion],(giPos==3)); // SMP SIN CAPAR
            
            
            sprintf(mystring,"NB=%4u",i8NBurstTrenTB);                      // Muestra numero de burst
            ST7529_printfg(mystring,COLUMNA_1,FILA_2,M_,ai8EscalaGrises[SMP_CAPADA],(giPos==4));       // SMP CAPADA
            //ST7529_printf(mystring,COLUMNA_1,FILA_2,M_,(giPos==4));                                  // SMP SIN CAPAR

            // Inicio de bloque de calculo de mínima separación entre burst
            fMin=(i16NPulsosBurstTB-1)*i8SepPulsosTB+i16PWBurstTB/1000;      // ... SBmin=(NP-1)*SP+PW (condicion de minimo)

            if(bPolaridadTB){                                                           // Si la señal es bipolar ...
                fMin=(i16NPulsosBurstTB-1)*i8SepPulsosTB+2*i16PWBurstTB/1000;    // ... SBmin=(NP-1)*SP+2PW (condicion de minimo)
            }
            
            i8Minimo=MIN_SEP_BURST;

            if(fMin>=MIN_SEP_BURST){                                              // Redondeo hacia arriba
                i8Minimo=redondeo50((int16)fMin);              // ... redondeo en pasos de 50
                
                if(redondeo50((int16)fMin)<=fMin){                     // Si el valor redondeado es menor que el valor sin redondear ...
                    i8Minimo=redondeo50((int16)fMin)+50;           // ... redondeo en pasos de 50, a la decena siguiente
                }

                if(fMin<1000){
                    i8Minimo=redondeo10((int16)fMin);              // ... redondeo en pasos de 10
                    
                    if(redondeo10((int16)fMin)<=fMin){                     // Si el valor redondeado es menor que el valor sin redondear ...
                        i8Minimo=redondeo10((int16)fMin)+10;           // ... redondeo en pasos de 10, a la decena siguiente
                    }
                }
            }
            if(i16SepBurstTB<=i8Minimo){
                i16SepBurstTB=i8Minimo;
            }
            // Fin de bloque de calculo de mínima separación entre burst

            int16 sep_burst_aux=0;
            bCondicion=(i8NBurstTrenTB<=1);

            if(!bCondicion){
                sep_burst_aux=i16SepBurstTB;
            }

            sprintf(mystring,"SB=%4lu ms",sep_burst_aux);                   // Muestra separacion entre burst
            ST7529_printfg(mystring,COLUMNA_2,FILA_2,M_,ai8EscalaGrises[SMP_CAPADA],(giPos==5));
            // ST7529_printfg(mystring,COLUMNA_2,FILA_2,M_,ai8EscalaGrises[bCondicion],(giPos==5));
            

            
            sprintf(mystring,"NT=%4u",i8NTrenesTB);                         // Muestra numero de trenes

            ST7529_printfg(mystring,COLUMNA_1,FILA_3,M_,ai8EscalaGrises[SMP_CAPADA],(giPos==6));
            
            // Inicio de bloque de calculo de mínima separación entre trenes
            fMin=((i8NBurstTrenTB-1)*i16SepBurstTB+(i16NPulsosBurstTB-1)*i8SepPulsosTB+i16PWBurstTB/1000)/1000;         // ... SBmin=(NB-1)*SB+(NP-1)*SP+PW (condicion de minimo)

            if(bPolaridadTB){                                                                                               // Si la señal es bipolar ...
                fMin=((i8NBurstTrenTB-1)*i16SepBurstTB+(i16NPulsosBurstTB-1)*i8SepPulsosTB+2*i16PWBurstTB/1000)/1000;       // ... SBmin=(NB-1)*SB+(NP-1)*SP+2PW (condicion de minimo)
            }
                        
            i8Minimo=MIN_SEP_TREN;

            if(fMin>=MIN_SEP_TREN){                                              // Redondeo hacia arriba
            i8Minimo=redondeo1(fMin);              // ... redondeo en pasos de 1

            if(redondeo1(fMin)<=fMin){                     // Si el valor redondeado es menor que el valor sin redondear ...
                    i8Minimo=redondeo1(fMin)+1;            // ... redondeo en pasos de 1, a la univdad siguiente
                }
                    
            }
            if(i8SepTrenesTB<=i8Minimo){
                i8SepTrenesTB=i8Minimo;
            }
            // Fin de bloque de calculo de mínima separación entre trenes
            int8 sep_tren_aux=i8SepTrenesTB;
            bCondicion=(i8NTrenesTB<=1);

            if(bCondicion){
                sep_tren_aux=0;
                i8SepTrenesTB=i8Minimo;
            }

            sprintf(mystring,"ST=%4u s",sep_tren_aux);                   // Muestra separacion entre burst
            ST7529_printfg(mystring,COLUMNA_2,FILA_3,M_,ai8EscalaGrises[SMP_CAPADA],(giPos==7));
            //ST7529_printfg(mystring,COLUMNA_2,FILA_3,M_,ai8EscalaGrises[bCondicion],(giPos==7));
            

            sprintf(mystring,"I =%5LU [A",i16CorrienteTB*100);                 // Muestra corriente
            ST7529_printf(mystring,COLUMNA_1,FILA_4,M_,(giPos==8));
            

            // Added 21/03/2022 Tiempo activo de tratamiento SMP
            //i16TactivoSMP=(int16)i8SepTrenesTB*(int16)i8NTrenesTB+1;                // Tiempo activo SMP es la frecuencia de los trenes por el numero dce trenes, más 1 segundo de rampa fija
                    i16TactivoSMP=(int16)(((int16)i8SepTrenesTB*((int16)i8NTrenesTB)))+(int16)((((int16)i16SepBurstTB*((int16)i8NBurstTrenTB-1))+((int16)i8SepPulsosTB*((int16)i16NPulsosBurstTB-1)))/1000)+2; // Tiempo activo SMP es la frecuencia de los trenes por el numero dce trenes, más 1 segundo de rampa fija
            Calc_representacion_t(i16TactivoSMP,0);
            
            sprintf(mystring,"Ta=%2u:%02u s",i8Tmin,i8Tseg);                         // Muestra tiempo de rampa
            ST7529_printfg(mystring,COLUMNA_2,FILA_4,M_,ai8EscalaGrises[1],0);


            ST7529_printf(sGUARDAR_PRESET,COLUMNA_1,FILA_RELISTO,M_,giPos==10); // Activo botón relisto
                

            iMenuAnterior=iMenuActual;                              // Asiga el menú actual al menú anterior
        
        #else

            if(iMenuAnterior!=80){                                  // Si el menú anterior no es el menú principal de TB

                bPausaTratamiento=0;                                    // Inicializo pausa 
                if(iMenuAnterior!=83){                              // Si el menú anterior no es el de error de electrodo
                    gF=1;                                           // Pongo a uno para inicializar la parte de frecuencias con la rulancha
                }
                ST7529_clear();                                     // Limpia la pantalla
                ST7529_printf(sSMP,0,0,L_,NORMAL);                  // Pone el título de SMP
                i8VariablesPreset=PRESET_TB;                       // Preset TB
                i8SeleccionTerapia=2;
                if(iMenuAnterior==180){                             // Si el menú anterior era el de tratamiento con tratamiento apagado
                    giPosRulancha=bPolaridadTB;      // Pongo en la rulancha el valor de bPolaridadTB del menú
                    giPos=0;                                        // Inicializo gipos
                }
                if(giPos==0){                                       // si giPos está sobre el bloque de bPolaridadTB en el menú de configuración
                    giPosRulancha=bPolaridadTB;      // Pongo en la rulancha el valor de bPolaridadTB del menú
                }
            }  
            
            if (giPos>10){                                           // Si llega a la última posición del menú
                giPos=10;                                            // Mantiene el cursor ahí
            }
            
            if(giPos<=0){                                           // Si llega a la primera posición del cursor
                giPos=0;                                            // Mantiene el cursor ahí
            }
            
            pantalla_seleccion();                                     // Muestra los iconos de la interfaz
            
            i8RepVal1=sMONOPOLAR;                                     // Indico monopolar

            if(bPolaridadTB){                                         // Si se trata de una señal bipolar
                i8RepVal1=sBIPOLAR;                                   // Indico bipolar   
            }

            ST7529_printf(i8RepVal1,COLUMNA_1,FILA_INIT,M_,giPos==0);     // Muestra por pantalla la polaridad


            sprintf(mystring,"PW=%4LU [s",i16PWBurstTB);                    // Muestra ancho de pulso
            ST7529_printf(mystring,COLUMNA_2,FILA_INIT,M_,(giPos==1));
            
            
            sprintf(mystring,"NP=%4lu",i16NPulsosBurstTB);                    // Muestra numero de pulsos
            ST7529_printf(mystring,COLUMNA_1,FILA_1,M_,(giPos==2));

            // Inicio de bloque de calculo de mínima separación entre pulsos
            fMin=(i16PWBurstTB)/1000;

            if(bPolaridadTB){
                fMin=2*(i16PWBurstTB)/1000;
            }

            i8Minimo=(int16)fMin+1;

            if(fMin<MIN_SEP_PULSOS){
                i8Minimo=MIN_SEP_PULSOS;
            }

            if(i8SepPulsosTB<=i8Minimo){
                i8SepPulsosTB=i8Minimo;
            }
            // Fin de bloque de calculo de mínima separación entre pulsos

            int8 sep_pulsos_aux=0;
            bCondicion=(i16NPulsosBurstTB<=1);

            if(!bCondicion){
                sep_pulsos_aux=i8SepPulsosTB;
            }

            sprintf(mystring,"SP=%4u ms",sep_pulsos_aux);                    // Muestra separacion entre pulsos
            ST7529_printfg(mystring,COLUMNA_2,FILA_1,M_,ai8EscalaGrises[bCondicion],(giPos==3)); // SMP SIN CAPAR
            
            
            sprintf(mystring,"NB=%4u",i8NBurstTrenTB);                      // Muestra numero de burst
            ST7529_printf(mystring,COLUMNA_1,FILA_2,M_,(giPos==4));                                  // SMP SIN CAPAR

            // Inicio de bloque de calculo de mínima separación entre burst
            fMin=(i16NPulsosBurstTB-1)*i8SepPulsosTB+i16PWBurstTB/1000;      // ... SBmin=(NP-1)*SP+PW (condicion de minimo)

            if(bPolaridadTB){                                                           // Si la señal es bipolar ...
                fMin=(i16NPulsosBurstTB-1)*i8SepPulsosTB+2*i16PWBurstTB/1000;    // ... SBmin=(NP-1)*SP+2PW (condicion de minimo)
            }
            
            i8Minimo=MIN_SEP_BURST;

            if(fMin>=MIN_SEP_BURST){                                              // Redondeo hacia arriba
                i8Minimo=redondeo50((int16)fMin);              // ... redondeo en pasos de 50
                
                if(redondeo50((int16)fMin)<=fMin){                     // Si el valor redondeado es menor que el valor sin redondear ...
                    i8Minimo=redondeo50((int16)fMin)+50;           // ... redondeo en pasos de 50, a la decena siguiente
                }

                if(fMin<1000){
                    i8Minimo=redondeo10((int16)fMin);              // ... redondeo en pasos de 10
                    
                    if(redondeo10((int16)fMin)<=fMin){                     // Si el valor redondeado es menor que el valor sin redondear ...
                        i8Minimo=redondeo10((int16)fMin)+10;           // ... redondeo en pasos de 10, a la decena siguiente
                    }
                }
            }
            if(i16SepBurstTB<=i8Minimo){
                i16SepBurstTB=i8Minimo;
            }
            // Fin de bloque de calculo de mínima separación entre burst

            int16 sep_burst_aux=0;
            bCondicion=(i8NBurstTrenTB<=1);

            if(!bCondicion){
                sep_burst_aux=i16SepBurstTB;
            }

            sprintf(mystring,"SB=%4lu ms",sep_burst_aux);                   // Muestra separacion entre burst
            ST7529_printfg(mystring,COLUMNA_2,FILA_2,M_,ai8EscalaGrises[bCondicion],(giPos==5));
            
            
            sprintf(mystring,"NT=%4u",i8NTrenesTB);                         // Muestra numero de trenes
            ST7529_printf(mystring,COLUMNA_1,FILA_3,M_,(giPos==6));
            
            // Inicio de bloque de calculo de mínima separación entre trenes
            fMin=((i8NBurstTrenTB-1)*i16SepBurstTB+(i16NPulsosBurstTB-1)*i8SepPulsosTB+i16PWBurstTB/1000)/1000;         // ... SBmin=(NB-1)*SB+(NP-1)*SP+PW (condicion de minimo)

            if(bPolaridadTB){                                                                                               // Si la señal es bipolar ...
                fMin=((i8NBurstTrenTB-1)*i16SepBurstTB+(i16NPulsosBurstTB-1)*i8SepPulsosTB+2*i16PWBurstTB/1000)/1000;       // ... SBmin=(NB-1)*SB+(NP-1)*SP+2PW (condicion de minimo)
            }
                        
            i8Minimo=MIN_SEP_TREN;

            if(fMin>=MIN_SEP_TREN){                                              // Redondeo hacia arriba
            i8Minimo=redondeo1(fMin);              // ... redondeo en pasos de 1

            if(redondeo1(fMin)<=fMin){                     // Si el valor redondeado es menor que el valor sin redondear ...
                    i8Minimo=redondeo1(fMin)+1;            // ... redondeo en pasos de 1, a la univdad siguiente
                }
                    
            }
            if(i8SepTrenesTB<=i8Minimo){
                i8SepTrenesTB=i8Minimo;
            }
            // Fin de bloque de calculo de mínima separación entre trenes
            int8 sep_tren_aux=i8SepTrenesTB;
            bCondicion=(i8NTrenesTB<=1);

            if(bCondicion){
                sep_tren_aux=0;
                i8SepTrenesTB=i8Minimo;
            }

            sprintf(mystring,"ST=%4u s",sep_tren_aux);                   // Muestra separacion entre burst
            ST7529_printfg(mystring,COLUMNA_2,FILA_3,M_,ai8EscalaGrises[bCondicion],(giPos==7));
            

            sprintf(mystring,"I =%5LU [A",i16CorrienteTB*100);                 // Muestra corriente
            ST7529_printf(mystring,COLUMNA_1,FILA_4,M_,(giPos==8));
            

            // Added 21/03/2022 Tiempo activo de tratamiento SMP
            //i16TactivoSMP=(int16)i8SepTrenesTB*(int16)i8NTrenesTB+1;                // Tiempo activo SMP es la frecuencia de los trenes por el numero dce trenes, más 1 segundo de rampa fija
           i16TactivoSMP=(int16)(((int16)i8SepTrenesTB*((int16)i8NTrenesTB)))+(int16)((((int16)i16SepBurstTB*((int16)i8NBurstTrenTB-1))+((int16)i8SepPulsosTB*((int16)i16NPulsosBurstTB-1)))/1000)+2; // Tiempo activo SMP es la frecuencia de los trenes por el numero dce trenes, más 1 segundo de rampa fija
            Calc_representacion_t(i16TactivoSMP,0);
            
            sprintf(mystring,"Ta=%2u:%02u s",i8Tmin,i8Tseg);                         // Muestra tiempo de rampa
            ST7529_printfg(mystring,COLUMNA_2,FILA_4,M_,ai8EscalaGrises[1],0);


            ST7529_printf(sGUARDAR_PRESET,COLUMNA_1,FILA_RELISTO,M_,giPos==10); // Activo botón relisto
                

            iMenuAnterior=iMenuActual;                              // Asiga el menú actual al menú anterior
    
        #endif
    }
    
    bRefrescoPantalla=0;                                        // inicializa el flag de refresco de pantalla

    return 0;
}

/*
*   Función: menu_90
*   Descripción: Menú de presets
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_90(){

    

    if(bRefrescoPantalla){                                  // Si se ha cambiado algún valor
    
        if(iMenuAnterior!=90 || bIndicaSeleccion){          // Si venimos de otro menú
            bIndicaSeleccion=0;                             // inicializo flag de selección
            ST7529_clear();                                 // Limpio pantalla
            ST7529_printf(sPRESETS,0,0,L_,NORMAL);          // Muestra este titulo
        }
        
        pantalla_seleccion();                               // Muestro iconos

        poner_cargar();                                     // Pone el simbolo de cargar en pantalla
        
        #ifdef SOLO_TDCS
        i8SeleccionTerapia=1;
        if(giPos<=1){                                       // Si el valor de selección es menor o igual a 0
            giPos=1;                                        // Inicializo giPos
        }
        #else
        if(giPos<=0){                                       // Si el valor de selección es menor o igual a 0
            giPos=0;                                        // Inicializo giPos
        }
        #endif
        
        if(giPos>6){                                        // Si el valor de selección es mayor que 5
            giPos=6;                                        // Inicializo giPos al máximo
        }

        representacionPresets();                            // Representa el menú de presets
                
        iMenuAnterior=iMenuActual;                          // Asigna menu actual al menú anterior
    }
    
    bRefrescoPantalla=0;                                    // Inicializo flag de refresco

    return 0;                                               // Return 0
}

/*
*   Función: menu_11
*   Descripción: Configuración de la iluminación de pantalla
*
*   Input:
*         - 
*   Output:
*         - 
*/
// int8 menu_11(){ 
//     if(bRefrescoPantalla){                                      // Si debe refrescar pantalla
//         if ((iMenuAnterior!=11)&&(iMenuAnterior!=64)){          // Si no viene de ninguno de los menús indicados
//             ST7529_clear();                                     // Limpio la pantalla   
//             ST7529_printf(sTEST_ILUM,0,0,L_,NORMAL);            // Muestro texto 
//             giPos=i8nivel_ilum;                                 // Asigno el valor de giPos al nivel de iluminación
//         }  
//         pantalla_seleccion();                                   // Muestro iconos
        
//         if(giPos>MAX_ILUMINACION){                              // Si el valor es mayor a MAX_ILUMINACION
//             giPos=MAX_ILUMINACION;                              // Fija a MAX_ILUMINACION
//         }
        
//         if (giPos<MIN_ILUMINACION){                             // Si el valor es menor a MIN_ILUMINACION
//             giPos=MIN_ILUMINACION;                              // Fija a MIN_ILUMINACION
//         }
        
//         sprintf(mystring,"%3lu%c",giPos,37);                    // Muestro valor por pantalla
//         ST7529_printf(mystring,30,50,XL_,0);
        
//         ST7529_putIcon(ICON_ILUM,20,52);                        // Muestro icono iluminación
        
//         i8nivel_ilum=giPos;                                     // Obtiene valor de iluminación
//         set_pwm8_duty((int16)i8nivel_ilum*10);                  // Cargamos duty de trabajo [0..1000] 
        
//         writeEEPROM_8bits(EEPROM_LOC_ILUMINACION,i8nivel_ilum); // Guarda en EEPROM el valor de iluminación
        
//         ST7529_printfg(sILUM_LEYENDA,0,LEYENDA_Y1,s_,ai8EscalaGrises[1],0);             // Muestra la leyenda de iluminación
//         ST7529_printfg(sRANGO_10_100_PER_LECTURA,0,LEYENDA_Y2,s_,ai8EscalaGrises[1],0);
        
//         iMenuAnterior=iMenuActual;                              // Asigna menu actual al menú anterior
//     }

//     bRefrescoPantalla=0;                                        // Inicializo flag de refresco

//     return 0;
// }

/*
*   Función: menu_12
*   Descripción: Configuración de la señal acústica
*
*   Input:
*         - 
*   Output:
*         - 
*/
// int8 menu_12(){
//     if(bRefrescoPantalla){
//         if((iMenuAnterior!=13)&&(iMenuAnterior!=62)){                   // Si no viene de ninguno de los menús indicados
//             ST7529_clear();                                             // Limpio la pantalla                               
//             ST7529_printf(sTEST_PITO,0,0,L_,NORMAL);                    // Muestro texto                                    
//             giPos=i16nivel_son;                                         // Asigno el valor de giPos al nivel de sonido 
//         }  
//         pantalla_seleccion();                                           // Muestro iconos
        
//         if(giPos>MAX_VOLUMEN){                                          // Si el valor es mayor a MAX_VOLUMEN
//             giPos=MAX_VOLUMEN;                                          // Fija a MAX_VOLUMEN
//         }
        
//         if (giPos<=MIN_VOLUMEN){                                        // Si el valor es menor o igual a MAX_VOLUMEN
//             giPos=MIN_VOLUMEN;                                          // Fija a MAX_VOLUMEN
//         }
        
//         i16nivel_son=giPos;                                             // Asigno nivel de sonido
        
//         sprintf(mystring,"%3lu%c",giPos,37);                            // Muestro valor por pantallla
//         ST7529_printf(mystring,30,50,XL_,0);
        
//         if (giPos==0){                                                  // Si se apaga el pito...
//             ST7529_putIcon(ICON_ALTOFF,20,52);                          // Icono altavoz off
//             setup_ccp7(CCP_OFF);                                        // Apago modulador
//             output_high(PWM_PITO);                                      // Nivel alto pito
//         }else{                                                          // ...su no está apagado
//             ST7529_putIcon(ICON_ALTON,20,52);                           // Icono altavoz on
//             setup_ccp7(CCP_PWM|CCP_SHUTDOWN_AC_L|CCP_SHUTDOWN_BD_L);    // Modulador para señal acustica
//             set_pwm7_duty((int16)((i16nivel_son*4.5)));                 // Cargamos duty de trabajo [0..450]
//         }
        
//         writeEEPROM_16bits(EEPROM_LOC_SONIDO,i16nivel_son);             // Guarda en EEPROM el nivel de sonido
        
//         ST7529_printfg(sACUSTICA_LEYENDA,0,LEYENDA_Y1,s_,ai8EscalaGrises[1],0);         // Muestra leyenda del aviso acústico
//         ST7529_printfg(sRANGO_0_100_PER_LECTURA,0,LEYENDA_Y2,s_,ai8EscalaGrises[1],0);

//         iMenuAnterior=iMenuActual;      // Asigna menu actual al menú anterior
//     }
    
//     bRefrescoPantalla=0;                // Inicializo flag de refresco

//     return 0;
// }

/*
*   Función: menu_13
*   Descripción: Información firmware/hardware
*
*   Input:
*         - 
*   Output:
*         - 
*/
// int8 menu_13(){  

//     if(bRefrescoPantalla){                                      // Si hay que refrescar la pantalla
//         if(iMenuAnterior!=15){                                  // Si venía de un meú distinto
//             ST7529_clear();                                     // Limpia la pantalla
//             ST7529_printf(sCONFIG_VERS_MAYUS,0,0,L_,NORMAL);    // Muuestra el título del menú
//         }  
        
//         pantalla_seleccion();                                   // Muestra los símbolos de la interfaz
       
           
//         ST7529_printf(sFW_Ver,22,50,L_,0);                      // Muestra versión del FW
//         ST7529_printf(sHW_Ver,22,70,L_,0);                      // Muestra versión del HW
           
//         sprintf(mystring,"Build: %lu - %lu - 0x%LX",gi16BuildCounter,gi16BuildCounterOrco, getChemID());        // Muestro valor por pantalla
//         ST7529_printf(mystring,0,120,S_,0);

//         iMenuAnterior=iMenuActual;                              // Asigna menu actual al menú anterior
//     }
    
//     bRefrescoPantalla=0;                                        // Inicializo flag de refresco

//     return 0;
// }

/*
*   Función: menu_14
*   Descripción: Configuración del contraste de pantalla
*
*   Input:
*         - 
*   Output:
*         - 
*/
// int8 menu_14(){
    
//     if(bRefrescoPantalla){                                          // Si debo de refrescar la pantalla
//         if (iMenuAnterior!=12){                                     // Si no viene de ninguno de los menús indicados
//             ST7529_clear();                                         // Limpio la pantalla   
//             ST7529_printf(sCONFIG_CONT_MAYUS,0,0,L_,NORMAL);        // Muestro texto 
//             giPos=i8NivelContraste;                                 // Asigno el valor de giPos al nivel de iluminación
//         }  
//         pantalla_seleccion();                                       // Muestro iconos
        
//         if(giPos>=MAX_CONTRASTE){                                   // Si el valor es mayor a MAX_CONTRASTE
//             giPos=MAX_CONTRASTE;                                    // Fija a MAX_CONTRASTE
//         }
        
//         if (giPos<=MIN_CONTRASTE){                                  // Si el valor es menor a MIN_CONTRASTE
//             giPos=MIN_CONTRASTE;                                    // Fija a MIN_CONTRASTE
//         }
        
//         sprintf(mystring,"%3lu%c",giPos,37);                        // Muestro valor por pantalla
//         ST7529_printf(mystring,30,50,XL_,0);
        
//         ST7529_putIcon(ICON_CONTRAST,20,52);                        // Muestro icono iluminación
        
//         ST7529_printfg(sTEXTO_GRIS,7,85,M_,ai8EscalaGrises[1],0);   // Muestro texto gris
//         ST7529_printfg(sTEXTO_NEGRO,40,85,M_,ai8EscalaGrises[0],0); // Muestro ttexto negro
        
//         i8NivelContraste=giPos;                                     // Obtiene valor de iluminación
//         ST7529_send(COMMAND,VOLCTRL);                               // Ajuste contraste
//         ST7529_send(DATA,i8NivelContraste*0.63);                    // Vop=18V - DS: 7.10.2 pg. 32   1C
//         ST7529_send(DATA,0x04);                                     

//         ST7529_printfg(sCONTR_LEYENDA,0,LEYENDA_Y1,s_,ai8EscalaGrises[1],0);    // Muestra leyenda de contraste
//         ST7529_printfg(sRANGO_10_80_PER_LECTURA,0,LEYENDA_Y2,s_,ai8EscalaGrises[1],0);
        
//         writeEEPROM_8bits(EEPROM_LOC_CONTRASTE,i8NivelContraste);   // Guarda en EEPROM el valor de contraste
        
//         iMenuAnterior=iMenuActual;                                  // Asigna menu actual al menú anterior
//     }

//     bRefrescoPantalla=0;                                            // Inicializo flag de refresco
    
//     return 0;
// }

/*
*   Función: menu_15
*   Descripción: Selección de idioma
*
*   Input:
*         - 
*   Output:
*         - 
*/
// int8 menu_15(){
//     if(bRefrescoPantalla){                                      // Si ha de refrescar la pantalla
//         if (iMenuAnterior!=14){                                 // Si no viene de ninguno de los menús indicados
//             ST7529_clear();                                     // Limpio la pantalla   
//             ST7529_printf(sCONFIG_IDIO_MAYUS,0,0,L_,NORMAL);    // Muestro texto 
//             giPos=i8SelIdioma;                                  // Asigno el valor de giPos al nivel de iluminación
//         }  
//         pantalla_seleccion();                                   // Muestro iconos
        
//         giPos%=NUM_IDIOMAS;                                     // Módulo para que no pase de NUM_IDIOMAS máximo
        
//         switch(giPos){                                          // Dependiendo del idioma elegido
//             case SPANISH:                                       // Selección español
//                 i8RepVal1=sIDIOMA_ESPANOL;                      // Asigno idioma
//                 i32OffsetDireccionIdioma=OFFSET_DIR_SPANISH;    // Asigno offset memoria
//                 break;
//             case ENGLISH:                                       // Selección inglés
//                 i8RepVal1=sIDIOMA_INGLES;                       // Asigno idioma
//                 i32OffsetDireccionIdioma=OFFSET_DIR_ENGLISH;    // Asigno offset memoria
//                 break;
//         }
        
//         ST7529_printf(i8RepVal1,29,50,L_,0);                    // Muestra idioma por pantalla
    
//         if(i8SelIdioma!=giPos){                                 // Si ha habido un cambio de idioma
//             i8SelIdioma=giPos;                                  // Asigna idioma
//             iMenuAnterior=222;                                  // Dummy value para refresco de pantalla
//         }else{                                                  // Si no ha cambiado el idioma
//             iMenuAnterior=iMenuActual;                          // Asigna menu actual al menú anterior
//         } 
        
//         writeEEPROM_8bits(EEPROM_LOC_IDIOMA,i8SelIdioma);       // Guarda en EEPROM la seleccíon del idioma
        
//         ST7529_printfg(sIDIOMA_LEYENDA,0,LEYENDA_Y1,s_,ai8EscalaGrises[1],0);   // Muestra la leyennda del idioma
//     }
    
//     bRefrescoPantalla=0;                                        // Inicializo flag de refresco
    
//     return 0;
// }

/*
*   Función: menu_22
*   Descripción: Ajuste del nivel de corriente 
*
*   Input:
*         - 
*   Output:
*         - 
*//*
int8 menu_22(){                
    if(bRefrescoPantalla){                                                      // Si debo de refrescar la pantalla
        if((iMenuAnterior!=21)&&(iMenuAnterior!=24)&&(iMenuAnterior!=31)&&(iMenuAnterior!=47)&&(iMenuAnterior!=54)&&(iMenuAnterior!=90)){   // Si el menú del que venia es distinto a estos
            ST7529_clear();                                                     // Limpia la pantalla
            if(iMenuAnterior==41 || iMenuAnterior==45 || iMenuANterior==46){    // Si el menú anterior es alguno de estos
                iMenuAnterior=40;                                               // Asigna el menú anterior al de electroestimulación
            }
    
            switch (iMenuAnterior){                                             // Dependiendo del menú anterior que sea
                case 20:                                                        // Menús galvánica/galvánica+micro
                case 23:
                    
                    if (giPos==1 || iMenuActual==21){                           // Si estamos modificando la corriente el galvánica
                        i8RepVal1=sGALV;                                        // Asigno texto título
                        min=MINIMA_CORRIENTE_GALVANICA;                         // Ajusto el valor mínimo de corriente
                        if(bCableBipolarConectado){                             // Si hay accesorio bipolar conectado
                            max=MAXIMA_CORRIENTE_GALVANICA_BIPOLAR;             // Ajusta el máximo de corriente
                            i8RepVal2=sRANGO_100_5;                             // Asiigna texto leyenda
                        }else{                                                  // Si no hay cable bipolar
                            max=MAXIMA_CORRIENTE_GALVANICA;                     // Ajusta el máximo de corriente
                            i8RepVal2=sRANGO_100_10;                            // Asiigna texto leyenda
                        }   
                        
                        giPos=i16IGalv[bSeleccionGalvanica];                    // Asigna valor de corriente actual a gipos
                    }else if (giPos==4 || iMenuActual==24){                     // Si estamos modificando la corriente en microcorrientes
                        i8RepVal1=sMICRO_CORRIENTES;                            // Asigno texto título
                        min=MINIMA_CORRIENTE_MICROCORRIENTES;                   // Ajusto el valor mínimo de corriente
                        max=MAXIMA_CORRIENTE_INICIO_MICRO;                      // Ajusta el máximo de corriente

                        i8RepVal2=sRANGO_100_1;                                 // Asigna texto leyenda          
                        giPos=i16Imicro;                                        // Asigna valor de corriente actual a gipos     
                    }        
                break;
             case 30:                                                           // Menú transcraneal
                i8RepVal1=sTRANS;                                               // Asigno texto título
                min=MINIMA_CORRIENTE_TRANSCRANEAL;                              // Asigno mínima corriente
                
                max=(int16)fSuperficieElectrodo*LIMITE_DENSIDAD_CORRIENTE;     // Asigno máxima corriente dependiendo de la densidad de corriente y superifcie del electrodo
                
                if(max>=1000){                                                  // Si es superior a 1000 uA
                    max/=100;                                                   // Redondeo en pasos de cien
                    max*=100;                                                   // Solo en los casos que es superior a 1000, ya que ahi salta de 100 en 100 uA
                }
                max/=50;                                                        // Paso a saltos de 50uA
                
                if(max>=MAXIMA_CORRIENTE_TRANSCRANEAL){                         // Si la corriente máxima obtenida es superior a MAXIMA_CORRIENTE_TRANSCRANEAL
                    max=MAXIMA_CORRIENTE_TRANSCRANEAL;                          // Asigno MAXIMA_CORRIENTE_TRANSCRANEAL al máximo
                }

                if(i16Itrans>=max){                                             // Si la corriente es superior a max
                    i16Itrans=max;                                              // Asigno corriente max
                }
                
                i8RepVal2=sRANGO_100_5;                                         // Asigno texto leyenda
                giPos=i16Itrans;                                                // Asigno valor de corriente a gipos
                break;
             case 40:                                                           // Menú de electroestimulación
                i8RepVal1=sELECTRO_ESTIMULACION;                                // Asigno texto título
                i8RepVal2=sRANGO_100_1;                                         // Asigno leyenda
                max=MAXIMA_CORRIENTE_INICIO_ELECTRO;                            // Asigno máximo valor de corriente
                min=MINIMA_CORRIENTE_ELECTROESTIMULACION;                       // Asigno mínimo cvalor de corriente
                gI=50;                                                          // Asigno multiplicador
                giPos=i16IElec[i8ConfigCanal];                                  // Asigno el valor de corriente del canal seleccionado a gipos
                break;
            }
            ST7529_printf(i8RepVal1,0,0,L_,NORMAL);                             // Muestro el título por pantalla
        } 
        
        pantalla_seleccion();                                                   // Muestro símbolos del interfaz
          
        if(iMenuActual==21){                                                    // Si estamos en galvánica
            if(bCableBipolarConectado){                                         // Si hay accesorio bipolar conectado
                max=MAXIMA_CORRIENTE_GALVANICA_BIPOLAR;                         // Ajusta el máximo de corriente
                i8RepVal2=sRANGO_100_5;                                         // Asiigna texto leyenda
            }else{                                                              // Si no hay cable bipolar
                max=MAXIMA_CORRIENTE_GALVANICA;                                 // Ajusta el máximo de corriente
                i8RepVal2=sRANGO_100_10;                                        // Asiigna texto leyenda
            }
        }
        
        if(giPos>max){                                                          // Si el valor elegido es superior al máximo
            giPos=max;                                                          // Asigna el valor máximo
        }
        
        if (giPos<=min){                                                        // Si el valor elegido es inferior o igual al mínimo
            giPos=min;                                                          // Asigna el valor mínimo
        }

        ST7529_printf((int16)sCo_ELECTRICA,12,36,M_,NORMAL);                    // Muestra el texto de corriente
        sprintf(mystring,"%5lu [A",giPos*gI);                                   // Muestra el valor de corriente
        ST7529_printf(mystring,30,70,L_,0);                                             

        switch (iMenuActual){                                                   // Dependiendo del menú en el que se encuentre
            case 21:                                                            // Corriente galvánica
                i16IGalv[bSeleccionGalvanica]=giPos;                            // Asigna el valor de corriente
                i32CGalv=calc_CargaGalv(i16IGalv[bSeleccionGalvanica]);         // Calcula el valor de carga eléctrica correspondiente
                break;
            case 24:                                                            // Corriente microcorrientes
                i16Imicro=giPos;                                                // Asigna el valor de corriente
                break;
            case 31:                                                            // Corriente transcraneal
                i16ITrans=giPos;                                                // Asigna el valor de corriente
                i32CTrans=calc_CargaTrans(i16Itrans);                           // Calcula el valor de carga eléctrica correspondiente
                break;
            case 47:                                                            // Corriente electroestimulación
                i16IElec[i8ConfigCanal]=giPos;                                  // Asigna el valor de corriente
                break;
        }
        
        ST7529_printfg(sCORRIENTE_LEYENDA,0,LEYENDA_Y1,s_,ai8EscalaGrises[1],0);// Muestra leyenda
        ST7529_printfg(i8RepVal2,0,LEYENDA_Y2,s_,ai8EscalaGrises[1],0);         // Muestra leyenda
       
        giPosRulancha=giPos;                                                    // Asigna el valor a gipos
       
        iMenuAnterior=iMenuActual;                                              // Asigna menu actual al menú anterior
    }
    
    bRefrescoPantalla=0;                                                        // Inicializo flag de refresco

    return 0;
}*/

/*
*   Función: menu_23
*   Descripción: Ajuste del tiempo de rampa
*
*   Input:
*         - 
*   Output:
*         - 
*//*
int8 menu_23(){
    if(bRefrescoPantalla){                                                  // Si hay que refrescar la pantalla
        if((iMenuAnterior!=23)&&(iMenuAnterior!=33)&&(iMenuAnterior!=26)&&(iMenuAnterior!=45)){ // Si el menú anterior es distinto a estos
            ST7529_clear();                                                 // Limpia la pantalla
            if(iMenuAnterior==44){                                          // Si el menú anterior es este
                iMenuAnterior=40;                                           // Asigna el menú anterior a electroestimulación
            }

            switch (iMenuAnterior){                                         // Dependiendo del menúu que venga
                case 20:                                                    // Menús galvánica/galvánica+microcorrientes
                case 22:
                    if (giPos==3 || iMenuAnterior==22){                     // Si estamos en menú galvanica
                        i8RepVal1=sGALV;                                    // Asigna titulo galvanica
                        giPos=i8TrampaGalv[bSeleccionGalvanica];            // Asigna tiempo a giPos
                    }
                    break;
                case 30:                                                    // Menús transcraneal
                case 32:
                    i8RepVal1=sTRANS;                                       // Asigna título transcraneal
                    giPos=i8TrampaTrans;                                    // Asigna tiempo a giPos
                    break;
                case 40:                                                    // Menú electroestimulación
                    i8RepVal1=sELECTRO_ESTIMULACION;                        // Asigna título electroestimulación
                    giPos=i8TrElec[i8ConfigCanal];                          // Asigna tiempo a giPos
                    break;
            }
          
            ST7529_printf(i8RepVal1,0,0,L_,NORMAL);                         // Muestra título por pantalla
        }
           
        pantalla_seleccion();                                               // Muestra los símbolos e la interfaz
       
        if(giPos>MAXIMO_TIEMPO_RAMPA){                                      // Si el tiempo elegido es superior a MAXIMO_TIEMPO_RAMPA
            giPos=MAXIMO_TIEMPO_RAMPA;                                      // Asigno MAXIMO_TIEMPO_RAMPA
        }
       
        if (giPos<=MINIMO_TIEMPO_RAMPA){                                    // Si el tiempo elegido es inferior a MINIMO_TIEMPO_RAMPA
            giPos=MINIMO_TIEMPO_RAMPA;                                      // Asigno MINIMO_TIEMPO_RAMPA
        }
       
        if(iMenuActual==23){                                                // Si estamos en tiempo de rampa de galvánica
            if(i16TGalv[bSeleccionGalvanica]!=0){                           // Si el tiempo de tratamiento es distinto de 0 (infinito)
                if((float)giPos>=(i16TGalv[bSeleccionGalvanica]/3.0)){      // Si la selección de tiempo de rampa es superior a un 1/3 del tiempo de tratamiento
                    giPos=(i16TGalv[bSeleccionGalvanica]/3);                // Asigna como máximo 1/3 del tiempo de tratamiento
                }
            }
        }
        
        if(iMenuActual==33){                                                // Si estamos en tiempo de rampa en transcraneal
            if(i16Ttrans!=0){                                               // Si el ltiempo de tratamiento es distinto de 0 (infinito)
                if((float)giPos>=(i16Ttrans/3.0)){                          // Si la selección de tiempo de rampa es superior a un 1/3 del tiempo de tratamiento
                    giPos=(i16Ttrans/3);                                    // Asigna como máximo 1/3 del tiempo de tratamiento
                }
            }
        }
       
        if(iMenuActual==45){                                                // Si estamos en tiempo de rampa en electroestimulación
            if((float)giPos>=(i16TacElec[i8ConfigCanal]/3.0)){              // Si la selección de tiempo de rampa es superior a un 1/3 del tiempo de tratamiento
                giPos=(i16TacElec[i8ConfigCanal]/3);                        // Asigna como máximo 1/3 del tiempo de tratamiento
            }
        }
       
        if (giPos<=MINIMO_TIEMPO_RAMPA){                                    // Si el tiempo de rampa es inferior a MINIMO_TIEMPO_RAMPA
            giPos=MINIMO_TIEMPO_RAMPA;                                      // Asigna MINIMO_TIEMPO_RAMPA
        }
        
        ST7529_printf(sTIEMPO_RAMPA,17,36,M_,NORMAL);                       // Muestra título tiempo de rampa
        sprintf(mystring,"%2lu s",giPos);                                   // Muestra tiemp ode rampa
        ST7529_printf(mystring,30,70,L_,0);

        switch (iMenuActual){                                               // Dependiendo del menñu en el que se encuentre
            case 23:                                                        // Menú galvánica
                i8TrampaGalv[bSeleccionGalvanica]=giPos;                    // Asigna tiempo de rampa
                break;
            case 33:                                                        // Menú transcraneal
                i8TrampaTrans=giPos;                                        // Asigna tiempo de rampa
                break;
            case 45:                                                        // Menú electroestimulación
                i8TrElec[i8ConfigCanal]=giPos;                              // Asigna tiempo de rampa
                break;
        }
       
        ST7529_printfg(sTIEMPO_RAMPA_LEYENDA,0,LEYENDA_Y1,s_,ai8EscalaGrises[1],0);     // Muestra leyenda
       
        giPosRulancha=giPos;                                                // Asigna el valor a la rulancha
       
        iMenuAnterior=iMenuActual;                                          // Asigna menu actual al menú anterior
    }
        
    bRefrescoPantalla=0;                                                    // Inicializo flag de refresco

    return 0;
}*/

/*
*   Función: menu_27
*   Descripción: Ajuste del ancho de pulso positivo y negativo
*
*   Input:
*         - 
*   Output:
*         - 
*//*
int8 menu_27(){
    if(bRefrescoPantalla){                                          // Si debe de refrescar la pantalla
        if(((iMenuAnterior!=27)&&(iMenuAnterior!=35)&&(iMenuAnterior!=36)&&(iMenuAnterior!=51)&&(iMenuAnterior!=52)&&(iMenuAnterior!=58)&&(iMenuAnterior!=59)&&(iMenuAnterior!=84)&&(iMenuAnterior!=94)&&(iMenuAnterior!=95)) || (iMenuAnterior==51 && iMenuActual==52)){ // Si se cumple el churro este
            ST7529_clear();                                         // Limpia la pantallla
            if(iMenuAnterior==48 || iMenuAnterior==49 || iMenuAnterior==50 || iMenuAnterior==51){   // Si el menú anterior es alguno de estos
                iMenuAnterior=40;                                   // Asigna el menú de electroestimulación
            }
          
            if(iMenuAnterior==83){                                  // Si el menú anterior es este
                iMenuAnterior=80;                                   // Asigna el menú de TB
            }

            switch (iMenuAnterior){                                 // Dependiendo del menú anterior
                case 20:                                            // Menú galvánica+microcorrientes
                case 26:
                    i8RepVal1=sMICRO_CORRIENTES;                    // Asigna título de microcorrientes
                    giPos=i16PWmicro/25;                            // Asigna PW a gipos
                    maxBW=MAXIMO_ANCHO_PULSO_MICRO;                 // Asigna máximo PW
                    break;
                case 40:                                            // Menú electroestimulación
                    i8RepVal1=sELECTRO_ESTIMULACION;                // Asigna título electroestimulación
                    if(i8ConfigCanal==POINTER_C){                   // Si se está configurando el pointer
                        maxBW=MAXIMO_ANCHO_PULSO_ELECTROESTIMULACION;                                   // Asigna máximo PW
                    }else{                                          // Si se esta configurando electroestimulación
                        maxBW=MAXIMO_ANCHO_PULSO_ELECTROESTIMULACION;                                   // Asigna máximo PW
                    }
                
                    if(iMenuActual==51){                            // Si se trata del PW+
                       giPos=i16PW_plusElec[i8ConfigCanal]/25;      // Asigna PW+ a giPos
                       maxBW=((900000.0/i16FrecElec[i8ConfigCanal])-(i16PW_minusElec[i8ConfigCanal]))/25;   // Obtiene maximo PW
                    }else if (iMenuActual==52){                     // Si se trata del PW-
                       giPos=i16PW_minusElec[i8ConfigCanal]/25;     // Asigna PW- a giPos
                       maxBW=((900000.0/i16FrecElec[i8ConfigCanal])-(i16PW_plusElec[i8ConfigCanal]))/25;    // Obtiene maximo PW
                    }
                    if(maxBW>=MAXIMO_ANCHO_PULSO_ELECTROESTIMULACION){                                  // Si el máximo PW de 40
                        maxBW=MAXIMO_ANCHO_PULSO_ELECTROESTIMULACION;                                   // Asigna máximo
                    }
                    break;
                case 80:                                            // Menú sistema ThetaBurst
                    i8RepVal1=sTB;                                 // Asigna titulo TB
                
                    giPos=i16PWBurstTB/25;                              // Asigna PW a giPos
                   
                    maxBW=MAX_PW_BURST;                                       // Asigna máximo PW
                    break;
            }
         
            ST7529_printf(i8RepVal1,0,0,L_,NORMAL);                 // Muestra titulo por pantalla
        }
       
        if(iMenuActual==51){                                        // Si está en PW+ en electroestimulación
            ST7529_printf(sPW_POS,17,36,M_,NORMAL);                 // Muestra título
        }else if(iMenuActual==52){                                  // Si está en PW- en electroestimulación
            ST7529_printf(sPW_NEG,17,36,M_,NORMAL);                 // Muestra título
        }else{                                                      // SI se trata de una señal simétrica
            ST7529_printf(sPW_GEN,17,36,M_,NORMAL);                 // Muestra título genérico
        }

        pantalla_seleccion();                                       // Muestra simbolos de la interfaz
      
        if(giPos>=maxBW){                                           // Si se ha llegado al valor máximo de PW
            giPos=maxBW;                                            // Asigna el valor máximo
        }
       
        if (giPos<5){                                               // Si se ha llegado al valor mínimo de PW 
            giPos=5;                                                // Asigna el valor máximo
        }
    
        switch (iMenuActual){                                       // Dependiendo del menú actual
            case 27:                                                // Menú microcorrientes
                i16PWmicro=giPos*25;                                // Asigna valor
                i8RepVal2=sPW_LEYENDA;                              // Asigno texto leyenda
                break; 
            case 51:                                                // Menú PW+ Electroestimulación
                i16PW_plusElec[i8ConfigCanal]=giPos*25;             // Asigno PW+

                if(i8SimetriaCanales!=0){                           // DEPRECATED
                    copiarDatosSimetria(0);                         // DEPRECATED
                }

                if(i8ConfigCanal==POINTER_C){                       // Si estamos configurando el pointer
                    i16PW_minusElec[i8ConfigCanal]=i16PW_plusElec[i8ConfigCanal];   // Asigna a PW- el mismo valor (simetría)
                    i8RepVal2=sPW_LEYENDA;                          // Asigan texto leyenda
                }else{                                              // Si estamos configurando electroestimulación
                    i8RepVal2=sPWP_LEYENDA;                         // Asigna texto leyenda
                }

                break;
            case 52:                                                // Menú PW- Electroestimulación
                i16PW_minusElec[i8ConfigCanal]=giPos*25;            // Asigno PW-

                if(i8SimetriaCanales!=0){                           // DEPRECATED
                    copiarDatosSimetria(0);                         // DEPRECATED
                }

                i8RepVal2=sPWN_LEYENDA;                             // Asigno texto leyenda
                break;
            case 84:                                                // Menú TB
                i16PWBurstTB=giPos*25;                                  // Asigna PW
                if((i16PWBurstTB*2+BANDA_GUARDA*2) >= (i32TDesfaseTB-BANDA_GUARDA*2)){     // Si la suma de los anchos de pulso + banda de guarda es mayor que el tiempo de desfase menos las bandas de guarda
                    giPos=(i32TDesfaseTB-BANDA_GUARDA*2)/2;                            // Asigno a giPos el valor máximo de giPos y lo escalo
                    giPos/=50;                                                          // Redondeo a 50
                    giPos*=2;                                                           // Vuelvo a escalar
                    i16PWBurstTB=giPos*25;                                                  // Asigno PW
                }
                maxBW=MAXIMO_ANCHO_PULSO_TB;                                                               // Asigno máximo PW
                i8RepVal2=sPW_LEYENDA;                                                  // Asigno texto leyenda
                break;
        }
       
        giPosRulancha=giPos;                                        // Asigno valor a rulancha
        
        sprintf(mystring,"%4lu [s",giPos*25);                       // Muestro valor de PW en pantalla
        ST7529_printf(mystring,26,70,L_,0);
        
        ST7529_printfg(i8RepVal2,0,LEYENDA_Y1,s_,ai8EscalaGrises[1],0);     // Muestro leyenda
        iMenuAnterior=iMenuActual;                                  // Asigna menu actual al menú anterior
    }
    
    bRefrescoPantalla=0;                                            // Inicializo flag de refresco

    return 0;
}*/

/*
*   Función: menu_28
*   Descripción: Ajuste de la frecuencia de tratamiento
*
*   Input:
*         - 
*   Output:
*         - 
*//*
int8 menu_28(){
    int16 aux;                          // Variable auxiliar para cálculos
    
    if(bRefrescoPantalla){              // Si debe de refrescar la pantalla
        if((iMenuAnterior!=28)&&(iMenuAnterior!=32)&&(iMenuAnterior!=48)&&(iMenuAnterior!=55)&&(iMenuAnterior!=83)&&(iMenuAnterior!=91)){   // Si se cumple esta condición
            if(iMenuAnterior==41 || iMenuAnterior==47){ // Si alguno de los menús anteriores coincide con estos
                iMenuAnterior=40;                       // Asigna menu de electroestimulación     
            }

            if(iMenuAnterior==82){                      // Si alguno de los menús anteriores coincide con estos
                iMenuAnterior=80;                       // Asigna menu de TB  
            }
            
            if(iMenuAnterior==27){                      // Si alguno de los menús anteriores coincide con estos
                iMenuAnterior=20;                       // Asigna menu de transcraneal  
            }

            ST7529_clear();                             // Limpia la pantalla
            
            switch (iMenuAnterior){                     // Dependiendo del menú anterior
                case 20:                                // Menú microcorrientes
                    i8RepVal1=sMICRO_CORRIENTES;        // Asigna título microcorrientes
                    max=MAXIMA_FRECUENCIA_MICRO;                            // Asigna máximo    
                    min=MINIMA_FRECUENCIA_MICRO;                              // Asigna mínimo
                    aux=i16frecmicro;                   // Asigna frecuenciaa variable auxiliar
                    gF=1;                               // Asigna multiplicador
                    giPos=aux/gF;                       // Obtiene frecuencia para giPos
                    break;       
                case 40:                                // Menú electroestimulación
                    i8RepVal1=sELECTRO_ESTIMULACION;    // Asigna título electroestimulación
            
                    aux=i16frecElec[i8ConfigCanal];     // Asigna frecuenciaa variable auxiliar
            
                    max=i16FrecLimSup[i8ConfigCanal];   // Asigna límite superior frecuencia
                    min=i16FrecLimInf[i8ConfigCanal];   // Asigna límite inferior frecuencia
                    break;
                case 80:                                // Menú TB
                    i8RepVal1=sTB;                     // Asigna título TB
                    max=MAXIMA_FRECUENCIA_TB;                            // Asigan máxima frecuencia
                    min=MINIMA_FRECUENCIA_TB;                              // Asigna mínima frecuencia
                    aux=i16FrecTB;                     // Asigna frecuencia a variable auxiliar
                    break;
            }

            ST7529_printf(i8RepVal1,0,0,L_,NORMAL);     // Muestra título en pantalla
        }else{                                          // Si es alguno de los menús anteriores
            aux=giPos*gF;                               // Actualiza variable auxiliar
        }

        if(iMenuActual!=28){                            // Si estamos en menú de microcorrientes
            if (aux>200 && aux<=10000){                 // Si la frecuencia es mayor de 200 Hz y menor o igual a 10 KHz
                gF=50;                                  // Asigna multiplicador 50
                giPos=aux/gF;                           // Obtiene giPos
            }else if(aux==200){                         // Si es igual a 200 Hz
                if(bascendente){                        // Si estamos incrementando la frecuencia
                    gF=50;                              // Asigno multiplicador 50
                    giPos=aux/gF;                       // Obtengo giPos
                }else{                                  // Si estoy bajando la frecuencia
                    gF=10;                              // Asigno multiplicador 10
                    giPos=aux/gF;                       // Obtengo giPos
                }
            }else if (aux>100 && aux<200){              // Si la frecuencia es mayor a 100 Hz y menor de 200
                if(giPos==3 && gF==50){                 // Si estabamos en 200 y ahora al volver atras quiere mostrar 150
                    giPos=19;                           // Le decimos que la cuenta es de 10 en 10
                    aux=190;                            // Salta a 190
                }
                gF=10;                                  // Asigno multiplicador 10
                giPos=aux/gF;                           // Obtengo giPos
            }else if(aux==100){                         // Si la frecuencia es igual a 100 Hz
                if(bascendente){                        // Si estamos incrementando la frecuencia
                    gF=10;                              // Asignamos multiplicador 10
                    giPos=aux/gF;                       // Obtengo giPos
                }else{                                  // Si estamos bajando la frecuencia
                    gF=2;                               // Asignamos multplicador 2
                    giPos=aux/gF;                       // Obtengo giPos
                } 
            }else if (aux>20 && aux<100){               // Si la frecuencia es superior a 20 Hz y menor de 100 Hz
                if(giPos==9 && gF==10){                 // Si estabamos en 100 y ahora al volver atras quiere mostrar 90
                    giPos=49;                           // Le decimos que la cuenta es de 2 en 2
                    aux=98;                             // Salta a 98
                }
                gF=2;                                   // Asignamos multiplicador 2
                giPos=aux/gF;                           // Obtengo giPos
            }else if(aux==20){                          // Si la frecuencia es igual a 20
                if(bascendente){                        // Si estamos incrementando la frecuencia
                    gF=2;                               // Asignamos multiplicador 2
                    giPos=aux/gF;                       // Obtengo giPos
                }else{                                  // Si estamos decrementrando la frecuencia
                    gF=1;                               // Asignamos multiplicador 1
                    giPos=aux/gF;                       // Obtengo giPos
                } 
            }else{                                      // Si la frecuenciaes inferior a 20
                if(giPos==9 && gF==2){                  // Si estabamos en 20 y ahora al volver atras quiere mostrar 18                
                    giPos=19;                           // Le decimos que la cuenta es de 10 en 10        
                    aux=19;                             // Salta a 19    
                }
                gF=1;                                   // Asignamos multiplicador 1
                giPos=aux;                              // Obtengo giPos
            }
        }
        
        if ((giPos*gF)>=max){                           // Si la selección es superior a la frecuencia máxima
            giPos=max/gF;                               // Fija la frecuencia máxima
        }

        if ((giPos*gF)<min){                            // Si la selección es inferior a la frecuencia mínima
            giPos=min/gF;                               // Fija la frecuencia mínima
        }

        pantalla_seleccion();                           // Muestra los símbolos de la interfaz
        
        ST7529_printf(sFRECUENCIA,24,36,M_,NORMAL);     // Muestra título frecuencia
      
        sprintf(mystring,"%5lu Hz",giPos*gF);           // Muestra frecuencia seleccionada
        ST7529_printf(mystring,29,70,L_,0);
        
        switch (iMenuActual){                           // Dependiendo del menú actual
            case 28:                                    // Menú microcorrientes
                aux=giPos*gF;                           // Obtenemos frecuencia
                i16frecmicro=giPos*gF;                  // Asignamos frecuencia a microcorrientes
                maxBW=Calc_BWmax(i16frecmicro,bpolaridadmicro);     // Obtenemos máximo ancho de pulso permitido
                break;
            case 48:                                    // Menú electroestimulación
                aux=giPos*gF;                           // Obtenemos frecuencia
                i16frecElec[i8ConfigCanal]=giPos*gF;    // Asignamos frecuencia a electroestimulación
                maxBW=Calc_BWmax(i16frecElec[i8ConfigCanal],bpolaridadElec[i8ConfigCanal]);     // Obtenemos máximo ancho de pulso permitido
                i16PW_plusElec[i8ConfigCanal]=Calc_BW(maxBW,i16PW_plusElec[i8ConfigCanal]);     // Limitamos máximo ancho de pulso positivo permitido
                i16PW_minusElec[i8ConfigCanal]=Calc_BW(maxBW,i16PW_minusElec[i8ConfigCanal]);   // Limitamos máximo ancho de pulso negativo permitido

                if(i8SimetriaCanales!=0){               // DEPRECATED
                    copiarDatosSimetria(0);             // DEPRECATED
                }
                break;
            case 83:                                    // Menú TB
                aux=giPos*gF;                                       // Obtenemos frecuencia
                i16FrecTB=giPos*gF;                                // Asignamos frecuencia a TB
                i32CalculoTB=((1000000/(int32)i16FrecTB)-100);    // Calculamos máximo tiempo de desfase
                if(i32CalculoTB<=i32TDesfaseTB){                  // Si el valor de desfase es mayor o igual al valor límite calculado
                    i32TDesfaseTB=i32CalculoTB;                   // Limitamos el tiempo de desfase al límite
                }
                maxBW=Calc_BWmax(i16FrecTB,1);                     // Obtenemos máximo ancho de pulso permitido
                i16PWBurstTB=Calc_BW(maxBW,i16PWBurstTB);                   // Limitamos máximo ancho de pulso permitido
                break; 
        }
        giPosRulancha=giPos;                                        // Asignamos valor a rulancha
        iMenuAnterior=iMenuActual;                                  // Asigna menu actual al menú anterior
        ST7529_printfg(sFRECUENCIA_LEYENDA,0,LEYENDA_Y1,s_,ai8EscalaGrises[1],0);   // Mostramos leyenda
    }

    bRefrescoPantalla=0;                                            // Inicializo flag de refresco

    return 0;
} */

/*
*   Función: menu_29
*   Descripción: Ajuste de la polaridad de la señal
*
*   Input:
*         - 
*   Output:
*         - 
*//*
int8 menu_29(){
    if(bRefrescoPantalla){                                          // Si debo de refrescar la pantalla
        if((iMenuAnterior!=26)&&(iMenuAnterior!=34)&&(iMenuAnterior!=49)&&(iMenuAnterior!=57)&&(iMenuAnterior!=93)){    // Si el menu anterior es distinto a alguno de estos
            ST7529_clear();                                         // Limpio la pantalla
            if(iMenuAnterior==48){                                  // Si estabamos en este menú
                iMenuAnterior=40;                                   // Asigno menú electroestimulación
            }
            
            switch (iMenuAnterior){                                 // Dependiendo del 
                case 20:                                            // Menú microcorrientes
                case 25:
                    i8RepVal1=sMICRO_CORRIENTES;                    // Asigna titulo microcorrientes
                    giPos=(bPolaridadMicro<<1)|(bMonopolarPosNeg);  // Asignamos polaridad a giPos
                    break;                       
                case 40:                                            // Menú electroestimulación
                    i8RepVal1=sELECTRO_ESTIMULACION;                // Asigna titulo electroestimulación
                    giPos=bpolaridadElec[i8ConfigCanal];            // Asignamos polaridad a gipos
                    break;
            }
            ST7529_printf(i8RepVal1,0,0,L_,NORMAL);                 // Mostramos titulo por pantalla
        }
        
        pantalla_seleccion();                                       // Mostramos los símbolos de la interfaz
       
        if(iMenuActual==26){                                        // Si estamos en microcorrientes
            if(giPos>=2){                                           // Si llegamos al maximo valor 
                giPos=2;                                            // Asignamos maximo valor
            }
        }else{                                                      // Si no estamos en microcorrientes
            if(giPos>=1){                                           // Si llegamos al maximo valor 
                giPos=1;                                            // Asignamos maximo valor
            }
        }
       
        if (giPos<=0){                                              // Si llegamos al minimo valor
            giPos=0;                                                // Asignamos minimo valor
        }

        ST7529_printf(sPOLARIDAD,25,36,M_,NORMAL);                  // Mostramos título de polaridad
        
        if(iMenuActual==26){                                        // Si estamos en microcorrientes
        
            switch(giPos){                                          // Dependiendo de la selección de polaridad
                case 0:                                             // Monopolar positivo
                    sprintf(mystring,"MONOPOLAR +");                // Asigno texto Monopolar positivo 
                    break;
                case 1:                                             // Monopolar negativo
                    sprintf(mystring,"MONOPOLAR -");                // Asigno texto Monopolar negativo 
                    break;
                case 2:                                             // Bipolar
                    sprintf(mystring,"BIPOLAR    ");                // Asigno texto Bipolar 
                    break;
            }
        
            ST7529_printf(mystring,25,70,L_,0);                     // Mostramos polaridad por pantalla
        }else{                                                      // Si no estamos en microcorrientes
            if(giPos==0){                                           // Si estamos en monopolar
                i8RepVal1=sMONOPOLAR;                               // Asignamos texto monopolar
            }else{                                                  // Si estamos en bipolar
                i8RepVal1=sBIPOLAR;                                 // Asignamos texto bipolar
            }
    
            ST7529_printf(i8RepVal1,25,70,L_,0);                    // Mostramos polaridad por pantalla
        }
       
        switch(iMenuActual){                                        // Dependiendo del menu actual
            case 26:                                                // Menú microcorrientes
                bPolaridadMicro=giPos>>1;                           // Asignamos valor de polaridad
                bMonopolarPosNeg=giPos&0x01;
                maxBW=Calc_BWmax(i16frecmicro,bpolaridadmicro);     // Obtenemos máximo ancho de pulso
                i16PWmicro=Calc_BW(maxBW,i16PWmicro);               // Asignamos el límite del ancho de pulso (solo si sobrepasa el limite)
                break;  
            case 49:                                                // Menú electroestimulación
                bpolaridadElec[i8ConfigCanal]=giPos;                // Asignamos valor de polaridad
                maxBW=Calc_BWmax(i16frecElec[i8ConfigCanal],bpolaridadElec[i8ConfigCanal]);     // Obtenemos máximo ancho de pulso
                i16PW_plusElec[i8ConfigCanal]=Calc_BW(maxBW,i16PW_plusElec[i8ConfigCanal]);     // Asignamos el limite del ancho de pulso positivo (solo si sobrepasa el limite)
                i16PW_minusElec[i8ConfigCanal]=Calc_BW(maxBW,i16PW_minusElec[i8ConfigCanal]);   // Asignamos el limite del ancho de pulso negativo (solo si sobrepasa el limite)
                if(i8SimetriaCanales!=0){                           // DEPRECATED
                    copiarDatosSimetria(0);                         // DEPRECATED
                }
                break;      
        }
        
        ST7529_printfg(sPOLARIDAD_LEYENDA,0,LEYENDA_Y1,s_,ai8EscalaGrises[1],0);    // Muestra leyenda

        giPosRulancha=giPos;                                        // Asignamos valor a rulancha
       
        iMenuAnterior=iMenuActual;                                  // Asigna menu actual al menú anterior
    }
    
    bRefrescoPantalla=0;                                            // Inicializo flag de refresco

    return 0;
}*/

/*
*   Función: menu_33
*   Descripción: Ajuste de la simetría de la señal
*
*   Input:
*         - 
*   Output:
*         - 
*//*
int8 menu_33(){ 
    if(bRefrescoPantalla){                                                  // Si debe de refrescar la pantalla
        if((iMenuAnterior!=33)&&(iMenuAnterior!=42)&&(iMenuAnterior!=50)&&(iMenuAnterior!=56)&&(iMenuAnterior!=92)){        // Si el menú anterior es distinto a alguno de estos
            ST7529_clear();                                                 // Limpio la pantalla
            if(iMenuAnterior==41 || iMenuAnterior==49){                     // Si estabamos en alguno de estos menus
                if(iMenuAnterior==41){                                      // DEPRECATED
                    switch(i8ConfigCanal){                                  // DEPRECATED
                        case CHA_C:                                         // DEPRECATED
                            if(i8CanalesActivados&CHA_ACT){                 // DEPRECATED
                                if(i8ReposoActivados&CHA_ACT){              // DEPRECATED
                                    iMenuActual=142;                        // DEPRECATED
                                }else{                                      // DEPRECATED
                                    iMenuActual=141;                        // DEPRECATED
                                }   
                            }else if(i8CanalesConfigurados&CHA_ACT){        // DEPRECATED
                                iMenuActual=140;                            // DEPRECATED
                            }
                            break;
                        case CHB_C:                                         // DEPRECATED
                            if(i8CanalesActivados&CHB_ACT){                 // DEPRECATED
                                if(i8ReposoActivados&CHB_ACT){              // DEPRECATED
                                    iMenuActual=142;                        // DEPRECATED
                                }else{                                      // DEPRECATED
                                    iMenuActual=141;                        // DEPRECATED
                                }                                           //
                            }else if(i8CanalesConfigurados&CHB_ACT){        // DEPRECATED
                                iMenuActual=140;                            // DEPRECATED
                            }
                            break;
                        case CHC_C:                                         // DEPRECATED
                            if(i8CanalesActivados&CHC_ACT){                 // DEPRECATED
                                if(i8ReposoActivados&CHC_ACT){              // DEPRECATED
                                    iMenuActual=142;                        // DEPRECATED
                                }else{                                      // DEPRECATED
                                    iMenuActual=141;                        // DEPRECATED
                                }
                            }else if(i8CanalesConfigurados&CHC_ACT){        // DEPRECATED
                                iMenuActual=140;                            // DEPRECATED
                            }
                            break;
                        case POINTER_C:                                     // DEPRECATED
                            if(i8CanalesActivados&POINTER_ACT){             // DEPRECATED
                                iMenuActual=141;                            // DEPRECATED
                            }else if(i8CanalesConfigurados&POINTER_ACT){    // DEPRECATED
                                iMenuActual=140;                            // DEPRECATED
                            }else{                                          // DEPRECATED
                                iMenuActual=40;                             // DEPRECATED
                            }
                            break;
                    }
                }else{                                                      // Si no estabamos seleccionando el canal de configuración        
                    iMenuAnterior=40;                                       // Asignamos menú de configuración
                }
            }

            switch (iMenuAnterior){                                         // Dependiendo del menu anterior
                case 40:                                                    // Menús de electroestimulación
                case 41:
                    if(iMenuActual==50){                                    // Si estamos configurando la simetria de la  señal
                        giPos=bsimetriaElec[i8ConfigCanal];                 // AAsigna simetria a giPos
                    }else{                                                  // DEPRECATED
                        giPos=i8SimetriaCanales;                            // DEPRECATED
                    }
                    break;
            }
            ST7529_printf(sELECTRO_ESTIMULACION,0,0,L_,NORMAL);             // Mostramos título de electroestimulación
        }

        pantalla_seleccion();                                               // Se muestran los simbolos de la interfaz
       
        if(iMenuActual==42){                                                // DEPRECATED
            if(giPos>=2){                                                   // DEPRECATED
                giPos=2;                                                    // DEPRECATED
            }
        }else{                                                              // Si estamos en el menú de simetria de señal
            if(giPos>1){                                                    // Si es superior al maximo
                giPos=1;                                                    // Asignamos maximo valor
            }
        }
        
        if (giPos<=0){                                                      // Si es inferior al minimo
            giPos=0;                                                        // Asignamos minimo valor
        }
       
        if(iMenuActual==42){                                                // DEPRECATED
            i8SimetriaCanales=giPos;                                        // DEPRECATED                                
 
            switch(i8SimetriaCanales){                                      // DEPRECATED                                
                case 0:                                                     // DEPRECATED                
                    i8RepVal1=sSimetriaCanalesNO;                           // DEPRECATED                                                
                    i8RepVal2=sSIM_CAN_N_LEYENDA;                           // DEPRECATED                                            
                    break;                                                  // DEPRECATED                    
                case 1:                                                     // DEPRECATED                
                    i8RepVal1=sSimetriaCanalesAB;                           // DEPRECATED                                                        
                    i8RepVal2=sSIM_CAN_AB_LEYENDA;                          // DEPRECATED                                            
                    break;                                                  // DEPRECATED                    
                case 2:                                                     // DEPRECATED                
                    i8RepVal1=sSimetriaCanalesABC;                          // DEPRECATED                                                    
                    i8RepVal2=sSIM_CAN_ABC_LEYENDA;                         // DEPRECATED                                            
                    break;                                                  // DEPRECATED                    
            }      
            ST7529_printf(i8RepVal1,35,70,L_,0);                            // DEPRECATED                                            
            ST7529_printfg(i8RepVal2,0,LEYENDA_Y1,S_,ai8EscalaGrises[1],0); // DEPRECATED                                                                    
    
            ST7529_printf(sSIM_CANALES,2,39,M_,NORMAL);                     // DEPRECATED                                                
                                                                                    
            copiarDatosSimetria(1);                                         // DEPRECATED                                                  
                                                                            
        }else if(iMenuActual<140){                                          // Si no estamos en el menú de tratamiento
       
            ST7529_printf(sSIMETRIA,28,36,M_,NORMAL);                       // Asignamos titulo de simetria de señal
           
            if(giPos==0){                                                   // Si seleccionamos señal asimetrica
                i8RepVal1=sASIMETRICA;                                      // Asignamos texto asimetria
                i8RepVal2=sPW_SIM;                                          // Asignamos leyenda (PW_SIM nombre mal, deberia ser PW_ASIM por lógica)
            }else{                                                          // Si seleccionamos señal simetrica
                if ((iMenuActual==49)||(iMenuActual==56)){                  // Si estamos en el menú de polaridad--REVISAR, NO TIENE SENIDO AQUI AHORA, NI LOS MENUS NI LA CONFIGURACIÓN
                    bpolaridadElec[i8ConfigCanal]=1;                        // Asignamos polaridad
                }
                i8RepVal1=sSIMETRICA;                                       // Asignamos texto simetria
                i8RepVal2=sPW_ASIM;                                         // Asignamos leyenda (PW_ASIM nombre mal, deberia ser PW_SIM por lógica)
            }
            ST7529_printf(i8RepVal1,26,70,L_,0);                            // Mostramos simetria por pantalla
            ST7529_printfg(i8RepVal2,0,LEYENDA_Y1,s_,ai8EscalaGrises[1],0); // Mostramos leyenda

            switch (iMenuActual){                                           // Dependiendo del menú actual
                case 50:                                                    // Si estamos en el menú de simetria
                    bsimetriaElec[i8ConfigCanal]=giPos;                     // Asignamos simetria
                    maxBW=Calc_BWmax(i16frecElec[i8ConfigCanal],bpolaridadElec[i8ConfigCanal]);     // Obtenemos máximo ancho de pulso permitido
                    i16PW_plusElec[i8ConfigCanal]=Calc_BW(maxBW,i16PW_plusElec[i8ConfigCanal]);     // Comprobamos que el ancho de pulso positivo no sea superior al máximo
                    i16PW_minusElec[i8ConfigCanal]=Calc_BW(maxBW,i16PW_minusElec[i8ConfigCanal]);   // Comprobamos que el ancho de pulso negativo no sea superior al máximo
                    if(i8SimetriaCanales!=0){                               // DEPRECATED
                        copiarDatosSimetria(0);                             // DEPRECATED
                    }
                    break;
            }
        }
       
        giPosRulancha=giPos;                                                // Asiganmos valor a la rulancha
       
        iMenuAnterior=iMenuActual;                                          // Asigna menu actual al menú anterior
    }
    
    bRefrescoPantalla=0;                                                    // Inicializo flag de refresco

    return 0;
}*/

/*
*   Función: menu_34
*   Descripción: Ajuste de la superficie del electrodo
*
*   Input:
*         - 
*   Output:
*         - 
*//*
int8 menu_34(){
    
    if(bRefrescoPantalla){                                      // Si debe de refrecar la pantalla
        if(iMenuAnterior!=34){                                  // Si viene de un menu distinto de este
            ST7529_clear();                                     // Limpio la pantalla
            ST7529_printf(sTRANS,0,0,L_,NORMAL);                // Muestro titulo transcraneal
            giPos=fSuperficieElectrodo;                        // Asigno superficie del electrodo a giPos
            ST7529_printfg(sSUPERFICIE_ELECTRODO_LEYENDA,5,LEYENDA_Y1,S_,ai8EscalaGrises[1],0); // Muestro leyenda
        }

        float fRawElect=(float)(i16ITrans*50)/LIMITE_DENSIDAD_CORRIENTE;    // Cálculo de la superficie del electrodo minima
    
        if((fRawElect-(int16)fRawElect) >0.5){                  // Si la superficie es superior a 0.5
            min=(int16)fRawElect +1;                            // Se incrementa en uno el mínimo obtenido
        }else{                                                  // Si no
            min=fRawElect;                                      // Se queda con el valor entero obtenido
        }
        
        if(min<MIN_TAM_ELECTRODO){                              // Si el mínimo obtenido es inferior al mínimo absoluto definido por MIN_TAM_ELECTRODO
            min=MIN_TAM_ELECTRODO;                              // Asignamos MIN_TAM_ELECTRODO a min
        }
        
        pantalla_seleccion();                                   // Muestra los símbolos de la interfaz
        
        if(giPos>MAX_TAM_ELECTRODO){                            // Si es superior al MAX_TAM_ELECTRODO
            giPos=MAX_TAM_ELECTRODO;                            // Asigna MAX_TAM_ELECTRODO
        }
       
        if (giPos<=min){                                        // Si es inferior al mínimo
            giPos=min;                                          // Asignamos minimo
        }
       
        fSuperficieElectrodo=giPos;                            // Asignamos valor a la variable de superficie de electrodo
        
        ST7529_printf(sSUPERFICIE_ELECTRODO,2,36,M_,NORMAL);    // Muestra título
        
        sprintf(mystring,"%3u cm]",fSuperficieElectrodo);      // Muestra superficie de electrodo
        ST7529_printf(mystring,30,70,L_,0);
        
        iMenuAnterior=iMenuActual;                              // Asigna menu actual al menú anterior
    }
    
    bRefrescoPantalla=0;                                        // Inicializo flag de refresco

    return 0;
}*/

/*
*   Función: menu_41
*   Descripción: Selección del canal de electroestimulación
*
*   Input:
*         - 
*   Output:
*         - 
*/
// int8 menu_41(){
//     if(bRefrescoPantalla){                                          // Si debo de refrescar la pantalla 
//         if (iMenuAnterior!=41){                                     // Si vengo de un menú distinto
//             ST7529_clear();                                         // Limpio la pantalla
//             giPos=i8ConfigCanal;                                    // Asigna selección de canla a giPos
//             ST7529_printf(sELECTRO_ESTIMULACION,0,0,L_,NORMAL);     // Muestra titulo
//             ST7529_printfg("   Seleccion del canal de electroestimulacion  ",0,LEYENDA_Y1,s_,ai8EscalaGrises[1],0);  // Muestra leyenda
//         } 

//         pantalla_seleccion();                                       // Muestra los simbolos de la interfaz
        
//         if(giPos>=3){                                               // Si se llega al maximo
//             giPos=3;                                                // Asigna maximo
//         }
        
//         if(giPos<=0){                                               // Si se llega al mínimo 
//             giPos=0;                                                // Asigna minimo
//         }
        
//         if((i8CanalesActivados&CHA_ACT) && giPos==POINTER_C){       // Si el canal A se encuentra activado y se intenta entrar al pointer
//             giPos=CHC_C;                                            // Salta al canal C
//         }
        
//         if((i8CanalesActivados&POINTER_ACT) && giPos==CHA_C){       // Si el pointer se encuentra activado y se intenta entrar al canal A
//             giPos=CHB_C;                                            // Salta al canal B
//         }
        
//         ST7529_printf("SELECCION DEL CANAL",12,36,M_,NORMAL);       // Muestra título
        
//         switch(giPos){                                              // Dependiendo del canal seleccionado
//             case 0:                                                 // Canal A
//                 i8RepVal1=sCANAL_A;                                 // Asigna texto canal
//                 bPointerSeleccionado=0;                             // Desactiva la seleccion del pointer
//                 break;
//             case 1:                                                 // Canal B  
//                 i8RepVal1=sCANAL_B;                                 // Asigna texto canal B
//                 break;
//             case 2:                                                 // Canal C
//                 i8RepVal1=sCANAL_C;                                 // Asigna texto canal C
//                 break;
//             case 3:
//                 i8RepVal1=sCANAL_POINTER;                           // Asigna texto Pointer
//                 bPointerSeleccionado=1;                             // Activa la seleccion del pointer
//                 i8SimetriaCanales=0;                                // En el caso de seleeccionar pointer, debemos de eliminar la opción de simetria entre canales por si estuviera activada, 0 == NO_SIMETRIA...DEPRECATED?
//                 break;
//         }
        
//         ST7529_printf(i8RepVal1,10,70,L_,0);                        // Muestra el canal seleccionado
        
//         i8ConfigCanal=giPos;                                        // Asigna valor del canal
//         bborrado=1;                                                 // Indica que debe borrar la pantalla
//         iMenuAnterior=iMenuActual;                                  // Asigna menu actual al menú anterior
//     }
    
//     bRefrescoPantalla=0;                                            // Inicializo flag de refresco

//     return 0;
// }

/*  DEPRECATED Se traspasa a menú de electro
*   Función: menu_49 Added 25/03/2022
*   Descripción: Selección del tipo de modulación FM/AM/PWM

*   Input:
*         - 
*   Output:
*         - 
*/
// int8 menu_49(){
//     int1 bCondicion=0;
//     if(bRefrescoPantalla){
//         if (iMenuAnterior!=49){                                     // Si vengo de un menú distinto
//             ST7529_clear();                                         // Limpio la pantalla
//             giPos=0;                                   // Asigna selección de canla a giPos
//             giPosRulancha=i8SeleccionMod;
//             ST7529_printf(sMODULACION,0,0,L_,NORMAL);     // Muestra titulo
//         }

//         if(giPos<=0){
//             giPos=0;
//         }

//         if(giPos>=6){
//             giPos=6;
//         }

//         pantalla_seleccion();                                       // Muestra los simbolos de la interfaz

//         switch(i8SeleccionMod){
//             case MOD_NOT:
//                 i8RepVal1=sOFF;
//                 bFMDesactivado=1;
//                 bAMDesactivado=1;
//                 bPWMDesactivado=1;
//                 break;
//             case MOD_FM:
//                 i8RepVal1=sFM;
//                 bFMDesactivado=0;
//                 bAMDesactivado=1;
//                 bPWMDesactivado=1;
//                 break;
//             case MOD_AM:
//                 i8RepVal1=sAM;
//                 bFMDesactivado=1;
//                 bAMDesactivado=0;
//                 bPWMDesactivado=1;
//                 break;
//             case MOD_FM_AM:
//                 i8RepVal1=sFM_AM;
//                 bFMDesactivado=0;
//                 bAMDesactivado=0;
//                 bPWMDesactivado=1;
//                 break;
//             case MOD_PWM:
//                 i8RepVal1=sPWM;
//                 bFMDesactivado=1;
//                 bAMDesactivado=1;
//                 bPWMDesactivado=0;
//                 break;
//             case MOD_FM_PWM:
//                 i8RepVal1=sFM_PWM;
//                 bFMDesactivado=0;
//                 bAMDesactivado=1;
//                 bPWMDesactivado=0;
//                 break;
//         }

//         if(giPos==0){
//             ST7529_printf(sESPACIO_LARGO,COLUMNA_1,18,M_,giPos==0);                   // Borro lo la terapia que había antes
//         }
//         ST7529_printf(i8RepVal1,COLUMNA_1,18,M_,giPos==0); // antes era fila 18


//         ST7529_printfg(sFM_CORTO,C3_COLUMNA_1,FILA_1-7,L_,ai8EscalaGrises[bFMDesactivado],0);
//         ST7529_printfg(sAM_CORTO,C3_COLUMNA_2+3,FILA_1-7,L_,ai8EscalaGrises[bAMDesactivado],0);
//         ST7529_printfg(sPWM_CORTO,C3_COLUMNA_3+3,FILA_1-7,L_,ai8EscalaGrises[bPWMDesactivado],0);


//         sprintf(mystring,"Fmin %3luHz",i16FrecInicialMod);//int16
//         ST7529_printfg(mystring,C3_COLUMNA_1-2,FILA_2,M_,ai8EscalaGrises[bFMDesactivado],giPos==1);                   // Borro lo la terapia que había antes
        
//         sprintf(mystring,"Fmax %3luHz",i16FrecFinalMod);//int16
//         ST7529_printfg(mystring,C3_COLUMNA_1-2,FILA_3,M_,ai8EscalaGrises[bFMDesactivado],giPos==2);                   // Borro lo la terapia que había ante


//         sprintf(mystring,"%2u %c",i8ModulacionAM,37);//porcentaje de modulacion (de 0% a 80%)
//         ST7529_printfg(mystring,C3_COLUMNA_2+6,FILA_2,M_,ai8EscalaGrises[bAMDesactivado],giPos==3);                   // Borro lo la terapia que había antes

//         // Bloque limitación PW
        
//         int32 max_pw;

//         if(i8SeleccionMod==MOD_PWM){
//             max_pw=(1.0/i16frecElec[CHB_C])*(1000000*0.9);
//         }

//         if(i8SeleccionMod==MOD_FM_PWM){
//             max_pw=(1.0/i16FrecFinalMod)*(1000000*0.9);
//         }

//         if(bPolaridadElec[CHB_C]){
//             max_pw/=2;
//         }

//         if(i32PWInicialMod>=i32PWFinalMod){
//             i32PWInicialMod=i32PWFinalMod-25;
//         }

//         if(max_pw>10000){
//             max_pw=(int32)((max_pw/5000.0)+0.5)*5000;
//         }

//         if(max_pw>1000 && max_pw<=10000){
//             max_pw=(int32)((max_pw/1000.0)+0.5)*1000;
//         }

//         if(i32PWFinalMod>=max_pw){
//             i32PWFinalMod=max_pw;
//         }

//         maxBW=max_pw/25;

//         // Fin de bloque limitación PW

//         sprintf(mystring,"PWmin %3lu%cs",conversionPW(i32PWInicialMod),cAux);
//         ST7529_printfg(mystring,C3_COLUMNA_3-4,FILA_2,M_,ai8EscalaGrises[bPWMDesactivado],giPos==4);

//         sprintf(mystring,"PWmax %3lu%cs",conversionPW(i32PWFinalMod),cAux);
//         ST7529_printfg(mystring,C3_COLUMNA_3-4,FILA_3,M_,ai8EscalaGrises[bPWMDesactivado],giPos==5);

//         if(i8SeleccionMod==MOD_NOT){
//             bCondicion=1;
//         }else{
//             bCondicion=0;
//         }
//         sprintf(mystring,"Tmod=%3u s",i8Tmodulacion);//int8 en segundos (mismo para las 3 mods)
//         ST7529_printfg(mystring,C3_COLUMNA_2-2,FILA_5,L_,ai8EscalaGrises[bCondicion],giPos==6); 
//         iMenuAnterior=iMenuActual;
//     }
//     bRefrescoPantalla=0;
//     return 0;
// }

/*
*   Función: menu_42
*   Descripción: Ajuste del tiempo de tratamiento
*
*   Input:
*         - 
*   Output:
*         - 
*//*
int8 menu_42(){
    
    if(bRefrescoPantalla){                                                              // Si debo refrescar la pantalla 
        int1 bIlimitado=0;                                                              // Flag que indica tiempo ilimitado
        
        if (((iMenuAnterior!=22)&&(iMenuAnterior!=25)&&(iMenuAnterior!=32)&&(iMenuAnterior!=33)&&(iMenuAnterior!=43)&&(iMenuAnterior!=44)&&(iMenuAnterior!=81)&&(iMenuAnterior!=82)) || (iMenuAnterior==43 && iMenuActual==44) || (iMenuAnterior==81 && iMenuActual==82)){  // If churro is true...
            ST7529_clear();                                                             // Limpia la pantalla
            if (iMenuAnterior==40 || iMenuAnterior==41 || iMenuAnterior==42 || iMenuAnterior==43){  // Si el emnú anterior es algún menú de tiempo de electroestimulación
                ST7529_printf(sELECTRO_ESTIMULACION,0,0,L_,NORMAL);                     // Muestra titulo electroestimulación
                switch (iMenuActual){                                                   // Dependiendo del menu en el que esté
                    case 43:                                                            // Menú tiempo activo de electroestimulación
                        giPos=i16TacElec[i8ConfigCanal]/SALTOS_TIEMPO_ELECTROESTIMULACION;  // Cargo tiempo en giPos
                        break;
                    case 44:                                                            // Menú tiempo de descanso
                        giPos=i16TdElec[i8ConfigCanal]/SALTOS_TIEMPO_DESCANSO_ELECTROESTIMULACION;  // Cargo tiempo en giPos
                        break;
                }
            }else if(iMenuAnterior==80 || iMenuAnterior==81){                           // Si estamos en el menú del sistema ThetaBurst
                ST7529_printf(sTB,0,0,L_,NORMAL);                                      // Muestra título TB
                
                if(iMenuActual==81){                                                    // Menú de tiempo activo
                    giPos=i16TacTB/SALTOS_TIEMPO_TB;                                  // Cargo tiempo en giPos
                }else{                                                                  // Menú tiempo desfase entre pulsos
                    giPos=i32TDesfaseTB/SALTOS_TIEMPO_DESFASE_TB;                     // Cargo tiempo en giPos
                }
            }else if(iMenuAnterior==20 || iMenuAnterior==21 || imenuAnterior==24){      // Si estamos en el menú de galvanica/galvanica+microcorrientes
                if(giPos==2 || iMenuAnterior==21){                                      // Si estamos en galvanica
                    ST7529_printf(sGALV,0,0,L_,NORMAL);                                 // Muestra título galvánica
                          
                    giPos=i16TGalv[bSeleccionGalvanica];                                // Cargo tiempo en giPos
                }else if (giPos==5 || iMenuAnterior==24){                               // Si estamos en microcorrientes
                    ST7529_printf(sMICRO_CORRIENTES,0,0,L_,NORMAL);                     // Muestra titulo microcorrientes
                          
                    giPos=i16Tmicro/SALTOS_TIEMPO_MICRO;                                // Cargo tiempo en giPos
                }
            }else if(iMenuAnterior==30 || iMenuAnterior==31){                           // Si estamos en transcraneal
                ST7529_printf(sTRANS,0,0,L_,NORMAL);                                    // Muestra titulo transcraneal

                giPos=i16Ttrans/SALTOS_TIEMPO_TRANSCRANEAL;                             // Cargo tiempo en gipos
                }
        }
    
        pantalla_seleccion();                                                           // Muestra simbolos de la interfaz
    
        if(iMenuActual==81){                                                            // Si estamos configurando tiempo activo de TB
            if(giPos>MAXIMO_TIEMPO_TB){                                                // Si el tiempo es superior a MAXIMO_TIEMPO_TB
                giPos=MAXIMO_TIEMPO_TB;                                                // Asigna MAXIMO_TIEMPO_TB
            }
            if (giPos<=MINIMO_TIEMPO_TB){                                              // Si el tiempor es inferior a MINIMO_TIEMPO_TB
                giPos=MINIMO_TIEMPO_TB;                                                // Asigna MINIMO_TIEMPO_TB
            }
        }else if(iMenuActual==82){                                                      // Si estamos configurando el desfase entre pulsos de TB
            i32CalculoTB=((1000000/(int32)i16FrecTB)-100)/100;                        // Obtiene el máximo tiempo de desfase entre pulsos
            
            if(giPos>=i32CalculoTB){                                                   // Si el valor a asignar es superior al límite
                giPos=i32CalculoTB;                                                    // Le asigna el límite
            }else{                                                                      // Si no es superior al límite
                if(giPos>MAXIMO_TIEMPO_DESFASE_TB){                                    // Si el tiempo es superior a MAXIMO_TIEMPO_DESFASE_TB
                    giPos=MAXIMO_TIEMPO_DESFASE_TB;                                    // Asigno MAXIMO_TIEMPO_DESFASE_TB
                }
            }
            
            if (giPos<=MINIMO_TIEMPO_DESFASE_TB){                                      // Si el tiempo es inferior a MINIMO_TIEMPO_DESFASE_TB
                giPos=MINIMO_TIEMPO_DESFASE_TB;                                        // Asigno MINIMO_TIEMPO_DESFASE_TB
            }
        }else if(iMenuActual==43){                                                      // Si estamos configurando tiempo activo en electroestimulación
            if(giPos>MAXIMO_TIEMPO_ELECTROESTIMULACION){                                // Si el tiempo es superior a MAXIMO_TIEMPO_ELECTROESTIMULACION
                giPos=MAXIMO_TIEMPO_ELECTROESTIMULACION;                                // Asigno MAXIMO_TIEMPO_ELECTROESTIMULACION
            }
            if (giPos<=MINIMO_TIEMPO_ELECTROESTIMULACION){                              // Si el tiempo es inferior a MINIMO_TIEMPO_ELECTROESTIMULACION
                giPos=MINIMO_TIEMPO_ELECTROESTIMULACION;                                // Asigno MINIMO_TIEMPO_ELECTROESTIMULACION
            }
        }else if(iMenuActual==44){                                                      // Si estamos configurando el tiempo descanso en electroestimulación
            if(giPos>MAXIMO_TIEMPO_DESCANSO_ELECTROESTIMULACION){                       // Si el tiempo es superior a MAXIMO_TIEMPO_DESCANSO_ELECTROESTIMULACION
                giPos=MAXIMO_TIEMPO_DESCANSO_ELECTROESTIMULACION;                       // Asigno MAXIMO_TIEMPO_DESCANSO_ELECTROESTIMULACION
            }
            if (giPos<=MINIMO_TIEMPO_DESCANSO_ELECTROESTIMULACION){                     // Si el tiempo es inferior a MINIMO_TIEMPO_DESCANSO_ELECTROESTIMULACION
                giPos=MINIMO_TIEMPO_DESCANSO_ELECTROESTIMULACION;                       // Asigno MINIMO_TIEMPO_DESCANSO_ELECTROESTIMULACION
            }
        }else if(iMenuActual==22){                                                      // Si estamos configurando el tiempo activo de galvánica/galvánica+microcorrientes
            if(giPos>MAXIMO_TIEMPO_GALVANICA){                                          // Si el tiempo es superior a MAXIMO_TIEMPO_GALVANICA          
                giPos=MAXIMO_TIEMPO_GALVANICA;                                          // Asigno MAXIMO_TIEMPO_GALVANICA
            }
            if(bSeleccionGalvanica){                                                    // Si estamos en galvánica+microcorrientes
                if (giPos<=MINIMO_TIEMPO_GALVAMICRO){                                   // Si el tiempo es inferior a MINIMO_TIEMPO_GALVAMICRO           
                    giPos=MINIMO_TIEMPO_GALVAMICRO;                                     // Asigno MINIMO_TIEMPO_GALVAMICRO
                }
            }else{                                                                      // Si estamos en galvánica
                if (giPos<=MINIMO_TIEMPO_GALVANICA){                                    // Si el tiempo es inferior a MINIMO_TIEMPO_GALVANICA   
                    giPos=MINIMO_TIEMPO_GALVANICA;                                      // Asigno MINIMO_TIEMPO_GALVANICA
                }
            }
        }else if(iMenuActual==25){                                                           // Si estamos configurando el tiempo de tratamiento de microcorrientes
            if(giPos>MAXIMO_TIEMPO_MICRO){                                              // Si el tiempo es superior a MAXIMO_TIEMPO_MICRO   
                giPos=MAXIMO_TIEMPO_MICRO;                                              // Asigno MAXIMO_TIEMPO_MICRO
            }
            if (giPos<=MINIMO_TIEMPO_MICRO){                                            // Si el tiempo es inferior a MINIMO_TIEMPO_MICRO   
                giPos=MINIMO_TIEMPO_MICRO;                                              // Asigno MINIMO_TIEMPO_MICRO
            }
        }else if(iMenuActual==32){                                                      // Si estamos configurando el tiempo de tratamiento de transcraneal
            if(giPos>MAXIMO_TIEMPO_TRANSCRANEAL){                                       // Si el tiempo es superior a MAXIMO_TIEMPO_TRANSCRANEAL          
                giPos=MAXIMO_TIEMPO_TRANSCRANEAL;                                       // Asigno MAXIMO_TIEMPO_TRANSCRANEAL
            }

            if (giPos<=MINIMO_TIEMPO_TRANSCRANEAL){                                     // Si el tiempo es inferior a MINIMO_TIEMPO_TRANSCRANEAL     
                giPos=MINIMO_TIEMPO_TRANSCRANEAL;                                       // Asigno MINIMO_TIEMPO_TRANSCRANEAL
            }
        }else{                                                                          // Default - NOT USED
            if(giPos>1000){                                                             // Si es superior a 1000
                giPos=1000;                                                             // Fija 1000
            }
            if (giPos<=0){                                                              // Si es inferior a 0
                giPos=0;                                                                // Fija 0
            }
        }
    
        switch (iMenuActual){                                                           // Dependiendo del menu actual
            case 43:                                                                    // Menú tiempo activo electroestimulación
                i16TacElec[i8ConfigCanal]=giPos*SALTOS_TIEMPO_ELECTROESTIMULACION;      // Asigna tiempo
                Calc_representacion_t(i16TacElec[i8ConfigCanal],0);                     // Obtiene representación en mm:ss
                i8RepVal1=sTIEMPO_ACT;                                                  // Asigna texto titulo
                sprintf(mystring1,"Ta=%2u:%02u s",i8Tmin,i8Tseg);                       // Asigna tiempo para pantalla
                i8RepVal2=sTIEMPO_ACT_LEYENDA;                                          // Asigna leyenda
                break;
            case 44:                                                                    // Menú tiempo descanso electroestimulación
                i16TdElec[i8ConfigCanal]=giPos*SALTOS_TIEMPO_DESCANSO_ELECTROESTIMULACION;  // Asigna tiempo
                Calc_representacion_t(i16TdElec[i8ConfigCanal],0);                      // Obtiene representación en mm:ss
                i8RepVal1=sTIEMPO_REP;                                                  // Asigna texto titulo
                sprintf(mystring1,"Td=%2u:%02u s",i8Tmin,i8Tseg);                       // Asigna tiempo para pantalla
                i8RepVal2=sTIEMPO_REP_LEYENDA;                                          // Asigna leyenda
                break;
            case 81:                                                                    // Menú tiempo activo TB
                i16TacTB=giPos*SALTOS_TIEMPO_TB;                                      // Asigna tiempo
                Calc_representacion_t(i16TacTB,0);                                     // Obtiene representación en mm:ss
                i8RepVal1=sTIEMPO_ACT;                                                  // Asigna texto titulo
                sprintf(mystring1,"Ta=%2u:%02u s",i8Tmin,i8Tseg);                       // Asigna tiempo para pantalla
                i8RepVal2=sTIEMPO_ACT_LEYENDA;                                          // Asigna leyenda
                break;
            case 82:                                                                    // Menú tiempo desfase entre pulsos TB
                i32TDesfaseTB=giPos*SALTOS_TIEMPO_DESFASE_TB;                         // Asigna tiempo
                i8RepVal1=sTIEMPO_DESF;                                                 // Asigna texto titulo
                sprintf(mystring1,"Tp=%6lu [s",i32TDesfaseTB);                         // Asigna tiempo para pantalla
                i8RepVal2=sDESF_PULSOS_LEYENDA;                                         // Asigna leyenda
                break;
            case 22:                                                                    // Menú tiempo activo galvánica/galvanica+microcorrientes
                i16TGalv[bSeleccionGalvanica]=giPos;                                    // Asigna tiempo
                Calc_representacion_t(i16TGalv[bSeleccionGalvanica],0);                 // Obtiene representación en mm:ss
                i8RepVal1=sTIEMPO_ACT;                                                  // Asigna texto titulo
                if(i16TGalv[bSeleccionGalvanica]!=0){                                   // Si se ha configurado tiempo
                    sprintf(mystring1,"Ta=%2u:%02u s",i8Tmin,i8Tseg);                   // Asigna tiempo para pantalla
                }else{                                                                  // Si se ha definido tiempo ilimitado
                    ST7529_printf(sILIMITADO,25,70,L_,0);                               // Muestro texto "Ilimitado"
                    bIlimitado=1;                                                       // Activo flag de ilimitado
                }
                i8RepVal2=sTIEMPO_ACT_LEYENDA;                                          // Asigna leyenda
                break;
            case 25:                                                                    // Menú tiempo activo microcorrientes
                i16Tmicro=giPos*SALTOS_TIEMPO_MICRO;                                    // Asigna tiempo
                Calc_representacion_t(i16Tmicro,0);                                     // Obtiene representación en mm:ss
                i8RepVal1=sTIEMPO_ACT;                                                  // Asigna texto titulo
                sprintf(mystring1,"Ta=%2u:%02u s",i8Tmin,i8Tseg);                       // Asigna tiempo para pantalla
                i8RepVal2=sTIEMPO_ACT_LEYENDA;                                          // Asigna leyenda
                break;
            case 32:                                                                    // Menú tiempo activo transcraneal
                i16Ttrans=giPos*SALTOS_TIEMPO_TRANSCRANEAL;                             // Asigna tiempo
                Calc_representacion_t(i16Ttrans,0);                                     // Obtiene representación en mm:ss
                i8RepVal1=sTIEMPO_ACT;                                                  // Asigna texto titulo
                if(i16Ttrans!=0){                                                       // Si se ha configurado tiempo
                    sprintf(mystring1,"Ta=%2u:%02u s",i8Tmin,i8Tseg);                   // Asigna tiempo para pantalla
                }else{                                                                  // Si se ha definido tiempo ilimitado
                    ST7529_printf(sILIMITADO,25,70,L_,0);                               // Muestro texto "Ilimitado"
                    bIlimitado=1;                                                       // Activo flag de ilimitado
                }
                i8RepVal2=sTIEMPO_ACT_LEYENDA;                                          // Asigna leyenda
                break;
        }
        
        ST7529_printf(i8RepVal1,12,36,M_,NORMAL);                                       // Muestra título
        ST7529_printf(i8RepVal2,0,LEYENDA_Y1,S_,NORMAL);                                /// Muestra leyenda
        
        if(!bIlimitado){                                                                // Si el tiempo no es infinito
            ST7529_printf(mystring1,25,70,L_,0);                                        // Muestro texto del vallor de tiempo
        }   
        
        giPosRulancha=giPos;                                                            // Asigna valor a rulancha
       
        iMenuAnterior=iMenuActual;                                                      // Asigna menu actual al menú anterior
    }
    
    bRefrescoPantalla=0;                                                                // Inicializo flag de refresco

    return 0;
}*/

/*
*   Función: menu_43
*   Descripción: Ajuste del número de repeticiones en electroestimulación
*
*   Input:
*         - 
*   Output:
*         - 
*//*
int8 menu_43(){
    if(bRefrescoPantalla){                                      // Si debe de refrescar la pantalla
        if (iMenuAnterior!=46){                                 // Si viene de otro menú
            ST7529_clear();                                     // Limpia la pantalla
            ST7529_printf(sELECTRO_ESTIMULACION,0,0,L_,NORMAL); // Muestra título electroestimulación
            giPos=i8Nrep[i8ConfigCanal];                        // Asigna número de repeticiones a giPos
        } 

        pantalla_seleccion();                                   // Muestra símbolos de la interfaz
        
        if(giPos>100){                                          // Si es superior al maximo
            giPos=100;                                          // Asigna máximo
        }

        if (giPos<1){                                           // Si es inferio al mínimo
            giPos=1;                                            // Asigna minimo
        }
        
        sprintf(mystring1,"N=%3lu",giPos);                      // Preparo texto número de repeticiones
        
        i8Nrep[i8ConfigCanal]=giPos;                            // Asigno número de repeticiones
        
        ST7529_printf(mystring1,30,70,L_,0);                    // Muestra texto número de repeticiones    
        ST7529_printf(sNUM_REPS,12,36,M_,NORMAL);               // Muestra título
        
        giPosRulancha=giPos;                                    // Asigna variable

        ST7529_printfg(sREPS_LEYENDA,0,LEYENDA_Y1,S_,ai8EscalaGrises[1],0); // Muestra leyenda

        iMenuAnterior=iMenuActual;                              // Asigna menu actual al menú anterior
    }
    
    bRefrescoPantalla=0;                                        // Inicializo flag de refresco

    return 0;
}*/

/*
*   Función: menu_91
*   Descripción: Menú de selección del canal de electroestimulación
*                   a cargar en el menú de presets
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_91(){                                                  // Menú de selección del canal de electroestimulación a cargar en el menú de presets             
    if(bRefrescoPantalla){                                       // Si se ha cambiado algún valor
        if(iMenuAnterior!=91){                                   // Si venimos de otro menú
            ST7529_clear();                                      // Limpio pantalla
            ST7529_printf(sPRESETS,0,0,L_,NORMAL);               // Muestra este titulo
            ST7529_printf(sSELEC_TITULO,10,36,L_,NORMAL);        // Muestra este titulo
            giPos=0;                                             // Inicializo giPos
        }       

        pantalla_seleccion();                                    // Muestro iconos
        poner_cargar();                                          // Pone el icono de cargar en la interfaz

        if(giPos<=SEL_CANAL_A){                                  // Si el valor de selección es menor o igual a SEL_CANAL_A
            giPos=SEL_CANAL_A;                                   // Inicializo giPos
        }       

        if(giPos>SEL_CANAL_ABC){                                 // Si el valor de selección es mayor que SEL_CANAL_ABC
            giPos=SEL_CANAL_ABC;                                 // Inicializo giPos al máximo
        }
        
        ST7529_printf(sSELEC_CANAL_A+giPos,12,70,M_,NORMAL);     // Muestra los canales a configurar

        iMenuAnterior=iMenuActual;                               // Asigna menu actual al menú anterior
    }           

    bRefrescoPantalla=0;                                         // Inicializo flag de refresco

    return 0;                       
}

/*
*   Función: menu_92
*   Descripción: Menú de guardado de presets
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_92(){                                     // Menú de guardado de presets
    if(bRefrescoPantalla){                          // Si se ha cambiado algún valor
        if(iMenuAnterior!=92){                      // Si venimos de otro menú
            ST7529_clear();                         // Limpio pantalla
            ST7529_printf(sPRESETS,0,0,L_,NORMAL);  // Muestra este titulo
            // giPos=1;                                // Inicializo giPos

            switch(i8SeleccionTerapia){
                case 0:
                    giPos=3;                           // Inicializo giPos Galv
                    break;     
                case 1:
                    giPos=2;                           // Inicializo giPos tDCS
                    break;
                case 2:
                    giPos=3;                           // Inicializo giPos Trans
                    break;
                case 3:
                    giPos=4;                           // Inicializo giPos Electro
                    break;
            }
        }
        
        pantalla_seleccion();                       // Muestro iconos

        poner_guardar();                            // Pone el icion de guardar en la interfaz
        
        switch(i8SeleccionTerapia){
            case 0:
                if(giPos<=3){                               // Si el valor de selección es menor o igual a 0
                    giPos=3;                                // Inicializo giPos
                }
                break;     
            case 1:
                if(giPos<=2){                               // Si el valor de selección es menor o igual a 0
                    giPos=2;                                // Inicializo giPos
                }
                break;
            case 2:
                if(giPos<=3){                               // Si el valor de selección es menor o igual a 0
                    giPos=3;                                // Inicializo giPos
                }
                break;
            case 3:
                if(giPos<=4){                               // Si el valor de selección es menor o igual a 0
                    giPos=4;                                // Inicializo giPos
                }
                break;
        }
        
        // if(giPos<=1){                               // Si el valor de selección es menor o igual a 0
        //     giPos=1;                                // Inicializo giPos
        // }
        
        if(giPos>6){                                // Si el valor de selección es mayor que 5
            giPos=6;                                // Inicializo giPos al máximo
        }

        // if(i8SeleccionTerapia==1){
        //     if(giPos>5){                                // Si el valor de selección es mayor que 5
        //         giPos=5;                                // Inicializo giPos al máximo
        //     }
        // }else{
        //     if(giPos>4){                                // Si el valor de selección es mayor que 5
        //         giPos=4;                                // Inicializo giPos al máximo
        //     }
        // }

        representacionPresets();                    // Muestra todos los presets por pantalla
    
        iMenuAnterior=iMenuActual;                  // Asigna menu actual al menú anterior
    }
    
    bRefrescoPantalla=0;                            // Inicializo flag de refresco

    return 0;   
}

/*
*   Función: menu_120
*   Descripción: Menú de tratamiento galvánica / galvánica+microcorrientes
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_120(){
    if(bRefrescoPantalla){
        int8 i8Time_min, i8Time_seg;                    // Variables utilizadas para la asignación de tiempo
        
        if(iMenuAnterior==120 && iMenuActual==121){     // Si estaba dando tratamiento y se para
            initMedidasGal();                           // Inicializa las medidas del tratamiento
        }

        gI=50;                                          // Asigna multiplicador/factor de corriente
        
        if(iMenuAnterior==20){                          // Si viene del menú de configuración debe de inicializar algunas variables{
            bTerapia=0;                                 // Indica terapia galvánica
            if(i8SeleccionGalvMicro==SEL_MICRO){
                bTerapia=1;                                 // Indica terapia microcorrientes
            }
            bVeniaDePausa=0;
        }
        
        if(iMenuAnterior==123 && (bTerapia || bCableBipolarConectado)){             // Si venia de un error de electrodo y estamos en tratamiento microcorrientes o cable bipolar
            controlSonido(0);                           // Desactiva el pitido
        }
        
        if(!bTerapia){                                  // Si estamos en galvánica
            if(iMenuAnterior==123 && !bCableBipolarConectado){                     // Si el menú anterior es el de error de electrodo
                ST7529_clear();                         // Limpia la pantalla
                
                // Solo en el caso de galvánica quiero que vuelva a recargar los valores de tiempo configurados
                if(!bTerapia){                                                                          // Si estabamos en galvánica
                    if(i16TGalv[bSeleccionGalvanica]==0){                                               // Si el tiempo de tratamiento es igual a cero (infinito)
                        i16TimeRaw[0]=i16TGalv[bSeleccionGalvanica];                                    // Inicializa variable de tiempo auxiliar
                    }else{                                                                              // Si hay un tiempo definido
                        i16TimeRaw[0]=i16TGalv[bSeleccionGalvanica]+i8TrampaGalv[bSeleccionGalvanica];  // Pone el tiempo activo+tiempo de rampa en variable de tiempo auxiliar
                    }
                    Calc_representacion_t(i16TimeRaw[0],0);                                             // Calucla representación mm:ss

                    sprintf(mystring2,"%7lu",0);                                                        // Variable para la carga electrica - Se inicializa a 0
                    
                    giPos=i16IGalv[bSeleccionGalvanica];                                                // Carga la corriente de tratamiento en giPos
                }else{                                                                                  // Si estamos en microcorrientes
                    giPos=i16Imicro;                                                                    // Carga la corriente de tratamiento en giPos
                    i16TimeRaw[0]=i16Tmicro+i8Trampamicro;                                              // Added 16/02/2022
                    Calc_representacion_t(i16TimeRaw[0],0);                                             // Added 16/02/2022 Da formato de tiempo mm:ss
                    
                }

                i16IMedGalv=0;                                                  // Inicializa variable medida corriente
                i16VMedGalv=0;                                                  // Inicializa variable medida tensión
                i16ResGalv=0;                                                   // Inicializa variable medida resistencia
                
                if(!bPausatratamiento){
                    i32JuliosGalv=0;
                    bVeniaDePausa=0;
                }
                
                structMedidasGalvanica.si16IMedGalv=i16IMedGalv;                // Inicializa variable envio medida corriente
                structMedidasGalvanica.si16ResGalv=i16ResGalv;                  // Inicializa variable envio medida tensión
                structMedidasGalvanica.si16VMedGalv=i16VMedGalv;                // Inicializa variable envio medida resistencia
            }
        }
 
        if((iMenuAnterior==123 || iMenuAnterior==121) && iMenuActual==120){     // Si viene de un error de elctrodo o de un tratamiento activo
            ST7529_clear();                                                     // Limpia la pantalla
        }

        if(bRefrescoPantalla){                                                  // Si debo limpiar la pantalla
            pantalla_seleccion();                                               // Muestra los simbolos de la interfaz
        }
        
        if(iMenuActual!=123){                                                   // Si no hay error de electrodo
            
            if(iMenuActual==120){                                               // Si estamos en el menú de tratamiento
                i16IMedGalv=0;                                                  // Inicializa variable medida corriente
                i16VMedGalv=0;                                                  // Inicializa variable medida tensión
                i16ResGalv=0;                                                   // Inicializa variable medida resistencia
                   
                if(!bPausaTratamiento){
                    i32JuliosGalv=0;
                    bVeniaDePausa=0;
                }
                   
                structMedidasGalvanica.si16IMedGalv=i16IMedGalv;                // Inicializa variable envio medida corriente
                structMedidasGalvanica.si16ResGalv=i16ResGalv;                  // Inicializa variable envio medida tensión
                structMedidasGalvanica.si16VMedGalv=i16VMedGalv;                // Inicializa variable envio medida resistencia
                
                if(!bPausaTratamiento){                                         // Si no pausa tratamiento
                    i32CargaGalvanicaRestante=i32CGalv+i16CRampaGalv;           // Inicializa la carga electrica restante con la carga de tratamiento y la de rampa
                }

                i16DecrementoCargaGalvanica=i16IGalv[bSeleccionGalvanica]*50;   // inicializa los pasos de los decremmentos de carga
            }
            
            if(iMenuAnterior!=120 && iMenuAnterior!=121){                       // Si es la primera vez que entramos en el menú o volvemos de un error de electrodo
                ST7529_clear();                                                 // Limpia la pantalla
                
                // Solo en el caso de galvánica quiero que vuelva a recargar los valores de tiempo configurados
                if(!bTerapia){                                                  // Si estamos en terapia galvanica
                    if(bCableBipolarConectado && iMenuAnterior==123){
                        giPos=i16IGalv[bSeleccionGalvanica];                        // Asigna el valor de correinte galvanica a giPos
                    }else{
                        if(i16TGalv[bSeleccionGalvanica]==0){                       // Si se ha configurado tiempo infiinito
                            i16TimeRaw[0]=i16TGalv[bSeleccionGalvanica];            // Inicializa e¡la variable de tiempo auxiliar
                        }else{                                                      // Si se ha configuradoo un tiempo de tratamiento
                            i16TimeRaw[0]=i16TGalv[bSeleccionGalvanica]+i8TrampaGalv[bSeleccionGalvanica];  // Asigna la suma del tiempo de tratamiento y tiempo de rampa a la variable de tiempo auxiliar
                        }
                        Calc_representacion_t(i16TimeRaw[0],0);                     // Da formato de tiempo mm:ss
       
                        sprintf(mystring2,"%7lu",0);                                // Muestra el valor de carga, lo pone a cero (ahora es acumulativa)
                        
                        giPos=i16IGalv[bSeleccionGalvanica];                        // Asigna el valor de correinte galvanica a giPos
                    }
                }else{                                                          // Si estamos en tratamiento de microcorrientes
                    giPos=i16Imicro;                                            // Asigna el valor de microcorrintes a giPos
                    i16TimeRaw[0]=i16Tmicro+i8Trampamicro;                      // Added 16/02/2022
                    Calc_representacion_t(i16TimeRaw[0],0);                     // Added 16/02/2022 Da formato de tiempo mm:ss      
                }
           
                pantalla_seleccion();
                
                // Si habia ocurrido un error de electrodo en galvanica, el tratamiento se para 
                // pero debe de dibujar todo de nuevo y cargar los valores por defecto
                if((iMenuAnterior!=120 && iMenuAnterior!=121 && iMenuAnterior!=123)){  // Si viene del menú de configuracion (menu_20)
                    // Envia los datos de configuración a Orco
                    // Set configuración del tratamiento - Galvánica
                    structTratamientoGalvanica.si32CGalv=i32CGalv+i16CRampaGalv;                // Carga electrica
                    structTratamientoGalvanica.si16IGalv=i16IGalv[bSeleccionGalvanica];         // Corriente de tratamiento
                    structTratamientoGalvanica.si8TrampaGalv=i8TrampaGalv[bSeleccionGalvanica]; // Tiempo de rampa de tratamiento
                    
                    // Set configuración del tratamiento - Microcorrientes
                    structTratamientoGalvanica.si16Imicro=i16Imicro;                        // Corriente de tratamiento
                    structTratamientoGalvanica.si16PWmicro=i16PWmicro;                      // Ancho de pulso
                    structTratamientoGalvanica.si8Trampamicro=i8Trampamicro;                // Tiempo de rampa
                    structTratamientoGalvanica.si16frecmicro=i16frecmicro;                  // Frecuencia de tratamiento
                    structTratamientoGalvanica.sbPolaridadMicro=bPolaridadMicro;            // Polaridad de la señal
                    structTratamientoGalvanica.sbMonopolarPosNeg=bMonopolarPosNeg;          // Polaridad monopolar
                    structTratamientoGalvanica.si8SeleccionGalvMicro=i8SeleccionGalvMicro;  // Seleccion terapia
                    
                    bSeleccionTranscraneal=0;                                       // Indico tratamiento galv?ica
                    structTratamientoGalvanica.sbSeleccionTranscraneal=bSeleccionTranscraneal;      // Indico tratamiento galv?ica
                    
                    // Carga de datos para el autocalculado del tiempo de tratamiento
                    i32CargaGalvanicaRestante=i32CGalv+i16CRampaGalv;               // Carga electrica restante
                    i16DecrementoCargaGalvanica=i16IGalv[bSeleccionGalvanica]*50;   // Pasos decrementos carga

                    i8ErrorCom=0;                                       // Inicializa el valor del contador de errores
                    
                    configuraDatos(MODO_TRAT_GALV);                     // Envia comando de configuración

                    i8TratamientoSeleccionado=TRATAMIENTO_GALVANICA;    // Indica el tratamiento seleccionado
                    if(i8SeleccionGalvMicro==SEL_MICRO){
                        i8TratamientoSeleccionado=TRATAMIENTO_MICROCORRIENTES;    // Indica el tratamiento seleccionado
                    }
                    
                    structTratamientoGalvanicaActivo.si16IGalv=0;       // Inicializa variable struct de corriente
                    
                    // Inicializamos algunos valores
                    i16IMedGalv=0;                                      // Inicializa variable medida corriente
                    i16VMedGalv=0;                                      // Inicializa variable medida tensión
                    i16ResGalv=0;                                       // Inicializa variable medida resistencia
                    
                    if(!bPausaTratamiento){
                        i32JuliosGalv=0;
                    }
                    
                    structMedidasGalvanica.si16IMedGalv=i16IMedGalv;    // Inicializa variable envio medida corriente
                    structMedidasGalvanica.si16ResGalv=i16ResGalv;      // Inicializa variable envio medida tensión
                    structMedidasGalvanica.si16VMedGalv=i16VMedGalv;    // Inicializa variable envio medida resistencia
                }
            }
            
            // DEPRECATED ya que no hay menu de parametro
            // if(iMenuAnterior==22){                                      // Si el menú anterior es el de tiempo de tratamiento activo...ESTO ES PA ALGO?? AQUI NO PINTA NADA!
            //     if(i16TGalv[bSeleccionGalvanica]!=0){                   // Si no se trata de tiempo infinito
            //         if((float)i8TrampaGalv[bSeleccionGalvanica]>=(i16TGalv[bSeleccionGalvanica]/3.0)){  // Si el tiempo de rampa es mayor que 1/3 del tiempo de tratamiento
            //             i8TrampaGalv[bSeleccionGalvanica]=(i16TGalv[bSeleccionGalvanica]/3);            // Asigna el valor de 1/3
            //         }
            //     }

            //     if(i8TrampaGalv[bSeleccionGalvanica]>=10){              // Si el tiemp ode rampa es superior al máximo
            //         i8TrampaGalv[bSeleccionGalvanica]=10;               // Asigna valor máximo
            //     }
            // }
            
            if(iMenuAnterior==121 && iMenuActual==120){     // Si paramos un tartamiento activo
                if(bPausaTratamiento){                      // Si lo hemos pausado
                    if(bTerapia){                           // Si estamos en microcorrientes
                        giPos=i16Imicro;                    // Cargamos el valor de corriente en giPos
                    }else{                                  // Si estamos en galvánica
                        giPos=i16IGalv[bSeleccionGalvanica];// Cargamos el valor de corriente en giPos
                    }
                }else{                                      // Si paramos el tratamiento
                    if(bTerapia){                           // Si estamos en microcorrientes
                        giPos=i16Imicro;                    // Cargamos el valor de corriente en giPos
                    }else{                                  // Si estamos en galvánica
                        giPos=i16IGalv[bSeleccionGalvanica];// Cargamos el valor de corriente en giPos
                    }
                }
            }
            
            if((iMenuAnterior==120 && iMenuActual==121) || (iMenuAnterior==123 && iMenuActual==121)){   // Si inicio el tratamiento o me recupero de un error de electrodo en microcorrientes
                quitar_cancelar();              // Quito icono cancelar
                quitar_config();                // Quito icono configuración
            }

            // Added 03/02/2022 Modificados titulos en funcion de te la terapia seleccionada
            if(i8SeleccionGalvMicro==SEL_GALVANICA){                                      // Si estamos en galvánica
                // ST7529_printf(sGALV,0,0,L_,NORMAL);             // Muestra titulo galvánica
                i8RepVal1=sGALV;
            }else if(i8SeleccionGalvMicro==SEL_MICRO){                                              // Si estamos en microcorrientes
                // ST7529_printf(sMICRO_CORRIENTES,0,0,L_,NORMAL); // Muestra titulo galv+microcorrientes
                i8RepVal1=sMICRO_CORRIENTES;
            }else{
                // ST7529_printf(sGALVANICA_MICRO,0,0,L_,NORMAL); // Muestra titulo galv+microcorrientes
                i8RepVal1=sGALVANICA_MICRO;
            }
            ST7529_printf(i8RepVal1,0,0,L_,NORMAL); // Muestra titulo galv+microcorrientes

            // if(!bTerapia){                                      // Si estamos en galvánica
            //     ST7529_printf(sGALV,0,0,L_,NORMAL);             // Muestra titulo galvánica
            // }else{                                              // Si estamos en microcorrientes
            //     ST7529_printf(sMICRO_CORRIENTES,0,0,L_,NORMAL); // Muestra titulo microcorrientes
            // }
                
            bTerapiaLeida=structMedidasGalvanica.sbTerapiaLeida;    // Lee el flag que indica que el microcontrolador secundario ha leido el dato de cambio de terapia galvanica a microcorrientes

            if(bTerapia!=bTerapiaLeida){                            // Si se ha detectado cambio de terapia
                initMedidasGal();                                   // Inicializo variables de medidas
            }
            
            sprintf(mystring1,"%5lu",redondeoI_50(i16IMedGalv));    // Asigna el texto de corriente medida redondeada
            ST7529_printf(mystring1,0,40,XL_,0);                    // Muestra corriente por pantalla
            ST7529_printf(sINTENSIDAD,2,26,S_,0);                   // Muestra texto corriente
            ST7529_printf("[A",36,55,S_,0);                         // Muestra unidades corriente

            if(!bTerapia && i8SeleccionGalvMicro!=SEL_MICRO){                                          // Si estamos en galvánica
                // sprintf(mystring2,"           ");                   // Bloque vacio (limpia)
                // ST7529_printf(mystring2,41,26,M_,0);                // Bloque vacio (limpia) 
                ST7529_printf("           ",41,26,M_,0);
                // sprintf(mystring2,"           ");                   // Bloque vacio (limpia)
                // ST7529_printf(mystring2,41,44,M_,0);                // Bloque vacio (limpia)
                ST7529_printf("           ",41,44,M_,0);
                ST7529_printf(sCARGA,41,26,S_,0);                   // Muestra texto carga  electrica
                sprintf(mystring2,"%7lu",(i16CRampaGalv+i32Cgalv)-i32CargaGalvanicaRestante);   // Asigna texto carga electrica
                ST7529_printf("[C",68,55,S_,0);                     // Muestra unidades carga electrica
                ST7529_printf(mystring2,45,44,L_,0);                // Muestra carga electrica
            }else{
                ST7529_printf("     ",41,26,S_,0);                  // Bloque vacio (limpia)
                // sprintf(mystring2,"       ");                       // Bloque vacio (limpia)
                // ST7529_printf(mystring2,45,44,L_,0);                // Bloque vacio (limpia)
                ST7529_printf("       ",45,44,L_,0);
                ST7529_printf("  ",68,55,S_,0);                     // Bloque vacio (limpia)
                sprintf(mystring2,"PW: %4lu [S",i16PWmicro);        // Asigna texto ancho de pulso
                ST7529_printf(mystring2,41,26,M_,0);                // Muestra ancho de pulso
                sprintf(mystring2,"F: %5lu Hz",i16frecmicro);       // Asigna texto frecuencia
                ST7529_printf(mystring2,41,44,M_,0);                // Muestra frecuencia
            }
            
            Calc_representacion_t(i16TimeRaw[0],0);                 // Muestra el tiempo en formato mm:ss
            
            ST7529_printf(sTIEMPO,2,80,S_,0);                       // Muestra texto tiempo
            sprintf(mystring,"%2u:%02u",i8Tmin,i8Tseg);             // Asigna representación tiempo
            ST7529_printf(mystring,0,94,XL_,0);                     // Muestra tiempo de tratamiento
            
            i16IMedGalv=structMedidasGalvanica.si16IMedGalv;        // Inicializa variables medida corriente
            i16VMedGalv=structMedidasGalvanica.si16VMedGalv;        // Inicializa variables medida tensión
            i16ResGalv=structMedidasGalvanica.si16ResGalv;          // Inicializa variables medida resistencia
            
            if(bTerapia){                                           // Si estamos en microcorrientes
                switch((bPolaridadMicro<<1)|bMonopolarPosNeg){      // Dependiendo de la polaridad en microcorrientes
                    case 0:                                         // Si estamos en MONOPOLAR + 
                        // ST7529_printf(sMonopolarPositivoLargo,44,75,S_,0);                 // Mostramos polaridad por pantalla
                        i8RepVal1=sMonopolarPositivoLargo;
                        break;
                    case 1:                                         // Si estamos en MONOPOLAR - 
                        // ST7529_printf(sMonopolarNegativoLargo,44,75,S_,0);                 // Mostramos polaridad por pantalla
                        i8RepVal1=sMonopolarNegativoLargo;
                        break;
                    case 2:                                         // Si estamos en BIPOLAR      
                        // ST7529_printf(sBipolarLargo,44,75,S_,0);                 // Mostramos polaridad por pantalla
                        i8RepVal1=sBipolarLargo;
                        break;
                }
                ST7529_printf(i8RepVal1,44,75,S_,0);                 // Mostramos polaridad por pantalla
            
            }
            
            ST7529_printf(sISET,44,85,S_,0);                        // Muestro texto corriente
            sprintf(mystring,"%5LU [A",giPos*gI);                   // Asigno texto valor corriente    
            ST7529_printf(mystring,57,85,S_,0);                     // Muestro texto valor corriente
            ST7529_printf(sVMED,44,95,S_,0);                        // Muestro texto tensión
            sprintf(mystring,"%5LU mV",i16VMedGalv);                // Asigno texto valor tensión        
            ST7529_printf(mystring,57,95,S_,0);                     // Muestro texto valor tensión
            ST7529_printf(sRMED,44,105,S_,0);                       // Muestro texto resistencia
            sprintf(mystring,"%5LU ohm",i16ResGalv);                // Asigno texto valor resistencia       
            ST7529_printf(mystring,57,105,S_,0);                    // Muestro texto valor resistencia
            if(!bTerapia && i8SeleccionGalvMicro!=SEL_MICRO){ 
                // ST7529_printf(sJ,44,115,S_,0);                       // Muestro texto resistencia
                i8RepVal1=sJ;
                sprintf(mystring,"%5LU mJ",i32JuliosGalv);                // Asigno texto valor resistencia       
                // ST7529_printf(mystring,57,115,S_,0);                    // Muestro texto valor resistencia
            }else{
                // ST7529_printf(sG,44,115,S_,0);                       // Muestro texto resistencia
                i8RepVal1=sG;
                sprintf(mystring,"%3.2f  %c ",calculoComponenteGalvanica(i16PWmicro,i16PWmicro,i16frecmicro,bPolaridadMicro),37);                // Asigno texto valor resistencia       
                // ST7529_printf(mystring,57,115,S_,0);                    // Muestro texto valor resistencia
            }
            ST7529_printf(i8RepVal1,44,115,S_,0);                       // Muestro texto resistencia
            ST7529_printf(mystring,57,115,S_,0);                    // Muestro texto valor resistencia
            
            if(i16VMedGalv>=10000){                                 // Si la tensión de salida es superior a 10 voltios (HV)
                // ST7529_printf(sHIGH_VOLTAGE,70,63,L_,0);            // Muestra mensaje de super alta tensión
                i8RepVal1=sHIGH_VOLTAGE;
            }else{                                                  // Si la tensión es inferior a 10 V
                // ST7529_printf(sHIGH_VOLTAGE_VACIO,70,63,L_,0);      // Quita mensaje HV
                i8RepVal1=sHIGH_VOLTAGE_VACIO;
            }
            ST7529_printf(i8RepVal1,70,63,L_,0);      // Quita mensaje HV

            iMenuAnterior=iMenuActual;                              // Asigna menu actual al menú anterior
            
            bRefrescoPantalla=0;                                    // Limpia flag refresco de pantalla
        }else{                                                      // Si hay error de electrodo, debe de para el tratamiento
        
            if (iMenuAnterior!=123){                                // Si acaba de entrar al error de electrodo
                ST7529_clear();                                     // Limpio la pantalla
            }
            
            Calc_representacion_t(i16TimeRaw[0],0);                 // Cálcula la representación del tiempo
            
            i8Time_min=i8Tmin;                                      // Recarga las variables de tiempo (minutos)
            i8Time_seg=i8Tseg;                                      // Recarga las variables de tiempo (segundos)
             
            if(!bTerapia && i8SeleccionGalvMicro!=SEL_MICRO){                                          // Si estamos en galvánica
                // ST7529_printf(sGALV,0,0,L_,NORMAL);                 // Muestra texto galvánica
                i8RepVal1=sGALV;
                if(bCableBipolarConectado){
                    pitidoErrorElectrodoIndefinido();                   // Activa pitido error electrodo
                }else{
                    pitidoErrorElectrodo();                             // Activa pitido de error de electrodo
                }
            }else{                                                  // Si estamos en microcorrientes
                // ST7529_printf(sMICRO_CORRIENTES,0,0,L_,NORMAL);     // Muestra texto microcorrientes
                i8RepVal1=sMICRO_CORRIENTES;
                pitidoErrorElectrodoIndefinido();                   // Activa pitido error electrodo
            }
            ST7529_printf(i8RepVal1,0,0,L_,NORMAL);     // Muestra texto microcorrientes
            
            ST7529_printf(sERROR_ELECTRODO,10,50,L_,NORMAL);        // Muestra título error de electrodo

            if(!bTerapia && !bCableBipolarConectado){                                          // Si estamos en galvánica
                bErrorElectrodoGalvanicaActivado=1;                 // Activo flag de error electrodo galvánica activado
                control_rele(0,rele_GALV);                          // Apagado rele galvanica
                pausa_ms(700);                                      // Pequeña pausa de espera (NECESARIO? DOUBT IT)
                apagadoGalvanica();                                 // Procedemos al apagado del tratamiento

                iMenuActual=120;                                    // Muestra el menú de tratamiento

                ST7529_clear();                                     // Limpia la pantalla
                
                bRefrescoPantalla=1;                                // Indico refresco de pantalla
                
                bErrorElectrodoGalvanicaActivado=0;                 // Inicializa flag de error electrodo galvánica activado
            }else{                                                  // Si estamos en tratamiento de microcorrientes
                ST7529_printf(sTACTIVO,29,85,S_,0);                 // Muestro texto tiempo activo

                sprintf(mystring,"%2u:%02u",i8Time_min,i8Time_seg); // Asigno tiempo restante de tratamiento (se encuentra parado)
                ST7529_printf(mystring,30,95,L_,0);                 // Muestro tiempo
                
                bRefrescoPantalla=0;                                // Inicializo flag de refresco
            }
            
            iMenuAnterior=iMenuActual;                              // Asigna menu actual al menú anterior
        }
    }

    return 0;
}

/*
*   Función: menu_130
*   Descripción: Menú de tratamiento transcraneal
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_130(){
    if(bRefrescoPantalla){                                          // Si debe de refrescar la pantalla
        
        
        if(iMenuAnterior==130 && iMenuActual==131){                 // Si acaba de iniciar un tratamiento
            initMedidasTrans();                                     // Inicializo medidas del tratamiento
        }
        
        gI=50;                                                      // Aisgno multiplicador/factor de corriente
        
        if(iMenuAnterior==30){                                      // Si viene del menú de configuración
            bTerapia=0;                                             // Inicializa variable galvánica
            i8SeleccionGalvMicro=SEL_GALVANICA;
        }
    
        if(iMenuAnterior==133){                                     // Si el menú anterior es el de error de electrodo
            ST7529_clear();                                         // Limpia la pantalla
            
            if(i16Ttrans==0){                                       // Si hemos configurado tiempo de tratamiento infinito
                i16TimeRaw[0]=i16Ttrans;                            // Inicializamos variable tiempo auxiliar
            }else{                                                  // Si hay un tiempo de tratamiento fijado
                i16TimeRaw[0]=i16Ttrans+i8TrampaTrans+i8TrampaTransBajada;              // Asignamos variable de tiempo activo + tiempo de rampa a la variable auxiliar de tiempo
            }

            Calc_representacion_t(i16TimeRaw[0],0);                 // Realizamos representación tiempo mm:ss

            sprintf(mystring2,"%7lu",0);                            // Se muestra la inicialización de la carga
            
            giPos=i16Itrans;                                        // Asignamos el valor de corriente a giPos

            i16IMedTrans=0;                                         // Inicializa variable medida corriente
            i16VMedTrans=0;                                         // Inicializa variable medida tensión
            i16ResTrans=0;                                          // Inicializa variable medida resistencia
            
            structMedidasGalvanica.si16IMedGalv=i16IMedTrans;       // Inicializa variable struct medida corriente
            structMedidasGalvanica.si16ResGalv=i16ResTrans;         // Inicializa variable struct medida tensión
            structMedidasGalvanica.si16VMedGalv=i16VMedTrans;       // Inicializa variable struct medida resistencia
        }

        if((iMenuAnterior==133 || iMenuAnterior==131) && iMenuActual==130){ // Si paramos un tratamiento o hay error de electrodo
            ST7529_clear();                                         // Limpia la pantalla
        }
        
        if(bRefrescoPantalla){                                      // Si debe de refrescar la pantalla
            pantalla_seleccion();                                   // Muestra símbolos de la interfaz
        }
        
        if(iMenuActual==130){                                       // Si está en menú de tratamiento
            poner_flecha_izq();                                     // Pongo la flecha izquierda en pantalla
        }else if(iMenuActual==131){                                 // Si está en menú de tratamiento activo
            quitar_flecha_izq();                                    // Quita la flecha izquierda en pantalla
        }
        
        if(iMenuActual!=133){                                       // Si no hay error de electrodo
            
            if(iMenuActual==130){                                   // Si estamos en el menñu de tratamiento configurado
                i16IMedTrans=0;                                     // Inicializa variable medida corriente
                i16VMedTrans=0;                                     // Inicializa variable medida tensión
                i16ResTrans=0;                                      // Inicializa variable medida resistencia
                
                structMedidasGalvanica.si16IMedGalv=i16IMedTrans;   // Inicializa variable struct medida corriente
                structMedidasGalvanica.si16ResGalv=i16ResTrans;     // Inicializa variable struct medida tensión
                structMedidasGalvanica.si16VMedGalv=i16VMedTrans;   // Inicializa variable struct medida resistencia
                
                if(!bPausaTratamiento){                             // Si no ha pausado el tratamiento
                    i32CargaTranscranealRestante=i32CTrans+i16CRampaTrans;  // Inicializa el valor de carga restante
                }

                i16DecrementoCargaTranscraneal=i16ITrans*50;        // Asigna los pasos de los decrementos de carga
            }
            
            if(iMenuAnterior!=130 && iMenuAnterior!=131){           // Si es la primera vez que entramos en el menú de tratamiento volvemos de un error de electrodo
                ST7529_clear();                                     // Limpia la pantalla

                if(i16TTrans==0){                           // Si se ha configurado tiempo infinito
                    i16TimeRaw[0]=i16TTrans;                // Asignamos tiempo infinito a la variable de tiempo auxiliar
                }else{                                      // Si se ha configurado un tiempo finito
                    i16TimeRaw[0]=i16TTrans+i8TrampaTrans+i8TrampaTransBajada;  // Asignamos la suma del tiempo de rampa + tiempo de tratamiento a la variable de tiempo auxiliar
                }

                Calc_representacion_t(i16TimeRaw[0],0);     // Realizamos representación tiempo mm:ss

                sprintf(mystring2,"%7lu",0);                // Muestra el valor de carga, lo pone a cero (ahora es acumulativa)
                
                giPos=i16ITrans;                            // Se muestra la inicialización de la carga

                pantalla_seleccion();                       // Muestra símbolos de la interfaz
                
                if((iMenuAnterior!=130 && iMenuAnterior!=131 && iMenuAnterior!=133)){  // Si viene del menú de configuración
                    // Envia los datos de configuración a Orco
                    // Set configuración del tratamiento - Galvánica
                    structTratamientoGalvanica.si32CGalv=i32CTrans+i16CRampaTrans;  // Carga electrica
                    structTratamientoGalvanica.si16IGalv=i16ITrans;                 // Corriente de tratamiento
                    structTratamientoGalvanica.si8TrampaGalv=i8TrampaTrans;         // Tiempo de rampa subida
                    structTratamientoGalvanica.si8TrampaTransBajada=i8TrampaTransBajada;         // Tiempo de rampa bajada
                    // Set configuración del tratamiento - Microcorrientes
                    structTratamientoGalvanica.si16Imicro=0;                        // Corriente de tratamiento
                    structTratamientoGalvanica.si16PWmicro=0;                       // Ancho de pulso
                    structTratamientoGalvanica.si8Trampamicro=0;                    // Tiempo de rampa
                    structTratamientoGalvanica.si16frecmicro=0;                     // Frecuencia
                    structTratamientoGalvanica.sbPolaridadMicro=0;                  // Polaridad
                    
                    structTratamientoGalvanica.si8SeleccionGalvMicro=i8SeleccionGalvMicro;  // Seleccion terapia

                    bSeleccionTranscraneal=1;                                       // Indico tratamiento transcraneal
                    structTratamientoGalvanica.sbSeleccionTranscraneal=bSeleccionTranscraneal;      // Indico tratamiento transcraneal
                    
                    // Carga de datos para el autocalculado del tiempo de tratamiento
                    i32CargaTranscranealRestante=i32CTrans+i16CRampaTrans;          // Carga electrica restante
                    i16DecrementoCargaTranscraneal=i16ITrans*50;                    // Pasos corriente

                    i8ErrorCom=0;                                                   // Inicializa el valor del contador de errores
                    
                    configuraDatos(MODO_TRAT_GALV);                                 // Envia comando de tratamiento

                    i8TratamientoSeleccionado=TRATAMIENTO_TRANSCRANEAL;             // Selecciono tratamiento transcraneal
                    
                    structTratamientoGalvanicaActivo.si16IGalv=0;                   // Inicializa variable struct corriente
                    
                    // Inicializamos algunos valores
                    i16IMedTrans=0;                                                 // Inicializa variable medida corriente
                    i16VMedTrans=0;                                                 // Inicializa variable medida tensión
                    i16ResTrans=0;                                                  // Inicializa variable medida resistencia
                    
                    structMedidasGalvanica.si16IMedGalv=i16IMedTrans;               // Inicializa variable struct medida corriente
                    structMedidasGalvanica.si16ResGalv=i16ResTrans;                 // Inicializa variable struct medida tensión
                    structMedidasGalvanica.si16VMedGalv=i16VMedTrans;               // Inicializa variable struct medida resistencia
                }
            }

            // if(iMenuAnterior==22){                              // Si el menú anterior es el de tiempo de tratamiento activo...ESTO ES PA ALGO?? AQUI NO PINTA NADA!
            //     if(i16TTrans!=0){                               // Si no se trata de tiempo infinito
            //         // if((float)i8TrampaTrans>=(i16TTrans/3.0)){  // Si el tiempo de rampa es mayor que 1/3 del tiempo de tratamiento
            //         //     i8TrampaTrans=(i16TTrans/3);            // Asigna el valor de 1/3
            //         // }
            //     }

            //     // if(i8TrampaTrans>=10){                          // Si el tiempo de rampa es superior al máximo
            //     //     i8TrampaTrans=10;                           // Asigna valor máximo
            //     // }
            // }
            
            if(iMenuAnterior==131 && iMenuActual==130){         // Si paramos un tratamiento
                giPos=i16ITrans;                                // Asignamos corriente a giPos
            }

            if((iMenuAnterior==130 && iMenuActual==131) || (iMenuAnterior==133 && iMenuActual==131)){   // Si inicio el tratamiento o me recupero de un error de electrodo en microcorrinetes
                quitar_cancelar();                              // Quita el icono de cancelar
                quitar_config();                                // Quita el icono de configuración
            }
            
            ST7529_printf(sTRANS,0,0,L_,NORMAL);                    // Muesta título transcraneal

            sprintf(mystring1,"%5lu",redondeoI_50(i16IMedTrans));   // Asigna valor corriente redondeada
            ST7529_printf(mystring1,0,40,XL_,0);                    // Muestra valor corriente
            ST7529_printf(sINTENSIDAD,2,26,S_,0);                   // Muestra texto corriente
            ST7529_printf("[A",36,55,S_,0);                         // Muestra unidades corriente
            
            // sprintf(mystring2,"           ");                       // Mostrar vacio (limpia)
            // ST7529_printf(mystring2,41,26,M_,0);                    // Mostrar vacio (limpia)
            ST7529_printf("           ",41,26,M_,0);
            // sprintf(mystring2,"           ");                       // Mostrar vacio (limpia)
            // ST7529_printf(mystring2,41,44,M_,0);                    // Mostrar vacio (limpia)
            ST7529_printf("           ",41,44,M_,0);
            ST7529_printf(sCARGA,41,26,S_,0);                       // Mostrar texto carga electrica
            sprintf(mystring2,"%7lu",(i16CRampaTrans+i32CTrans)-i32CargaTranscranealRestante);  // Asigna texto valor de carga electrica
            ST7529_printf("[C",68,55,S_,0);                         // Muestra unidades carga electrica
            ST7529_printf(mystring2,45,44,L_,0);                    // Muestra valor de carga electrica
            
            Calc_representacion_t(i16TimeRaw[0],0);                 // Realiza la representación del tiempo mm:ss
            
            ST7529_printf(sTIEMPO,2,80,S_,0);                       // Muestra exto tiempo
            if(i8Tmin>=100){
                sprintf(mystring,"%3u:%02u",i8Tmin,i8Tseg);             // Asigna texto tiempo
            }else{
                sprintf(mystring,"%2u:%02u ",i8Tmin,i8Tseg);             // Asigna texto tiempo
            }
            ST7529_printf(mystring,0,94,XL_,0);                     // Muestra texto tiempo
            
            i16IMedTrans=structMedidasGalvanica.si16IMedGalv;       // Inicializa variable struct medida corriente
            i16VMedTrans=structMedidasGalvanica.si16VMedGalv;       // Inicializa variable struct medida tensión
            i16ResTrans=structMedidasGalvanica.si16ResGalv;         // Inicializa variable struct medida resistencia

            i32DensidadCorriente=redondeoI_50(i16IMedTrans)/fSuperficieElectrodo;  // Obtiene el valor de densidad de corriente
            
            ST7529_printf(sISET,42,85,S_,0);                            // Muestro texto corriente     
            sprintf(mystring,"%5LU [A",giPos*gI);                       // Asigno texto valor corriente            
            ST7529_printf(mystring,55,85,S_,0);                         // Muestro texto valor corriente     
            ST7529_printf(sVMED,42,95,S_,0);                            // Muestro texto tensión     
            sprintf(mystring,"%5LU mV",i16VMedTrans);                   // Asigno texto valor tensión                  
            ST7529_printf(mystring,55,95,S_,0);                         // Muestro texto valor tensión     
            ST7529_printf(sRMED,42,105,S_,0);                           // Muestro texto resistencia     
            sprintf(mystring,"%5LU ohm",i16ResTrans);                   // Asigno texto valor resistencia              
            ST7529_printf(mystring,55,105,S_,0);                        // Muestro texto valor resistencia
            sprintf(mystring,"j = %3lu [A/cm]",i32DensidadCorriente);   // Asigna texto densidad de corriente              
            ST7529_printf(mystring,42,115,S_,0);                        // Muestra texto densidad de corriente  
            
            if(i16VMedTrans>=10000){                                    // Si la tensión de salida es superior a 10 voltios (HV)
                // ST7529_printf(sHIGH_VOLTAGE,70,63,L_,0);                // Muestra mensaje de super alta tensión
                i8RepVal1=sHIGH_VOLTAGE;
            }else{                                                      // Si la tensión es inferior a 10 V
                // ST7529_printf(sHIGH_VOLTAGE_VACIO,70,63,L_,0);          // Quita mensaje HV
                i8RepVal1=sHIGH_VOLTAGE_VACIO;
            }
            ST7529_printf(i8RepVal1,70,63,L_,0);          // Quita mensaje HV
            
            iMenuAnterior=iMenuActual;                                  // Asigna menu actual al menú anterior
            bRefrescoPantalla=0;                                        // Inicializo flag de refresco
        }else{                                                          // Si hay error de electrodo, debe de para el tratamiento
        
            if (iMenuAnterior!=133){                                    // Si acaba de entrar a erorr de electrodo
                ST7529_clear();                                         // Limpia la pantalla
            }

            bErrorElectrodoGalvanicaActivado=1;                         // Activa flag de error de electrodo en tratamiento
            pitidoErrorElectrodo();                                     // Activa pitido de error
            
            ST7529_printf(sTRANS,0,0,L_,NORMAL);                        // Muestra título transcraneal
            
            ST7529_printf(sERROR_ELECTRODO,10,50,L_,NORMAL);            // Muestra texto error de electrodo

            control_rele(0,rele_GALV);                                  // Apagado rele galvanica
            pausa_ms(1500);                                             // Pausa para lectura del mensaje en pantalla

            iMenuActual=130;                                            // Inidica menú de tratamiento transcraneal

            apagadoTranscraneal();                                      // Empieza el proceso de apagado del canal de transcraneal

            ST7529_clear();                                             // Limpia la pantalla

            bErrorElectrodoGalvanicaActivado=0;                         // Limpia flag de error de electrodo en tratamiento
            
            iMenuAnterior=iMenuActual;                                  // Asigna menu actual al menú anterior
            
            bRefrescoPantalla=1;                                        // Inicializo flag de refresco
        }
    }

    return 0;
}

/*
*   Función: menu_140
*   Descripción: Menú de tratamiento de electroestimulación
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_140(){                                                    // Menú de tratamiento de electroestimulación
    if(bRefrescoPantalla){                                          // Si debo de refrescar la pantalla
        int8 i8Time_min, i8Time_seg, i8Time1_min, i8Time1_seg;      // Variables utilizadas para la asignación de tiempo
        
        pantalla_seleccion();                                       // Muestra los símbolos en la interfaz

        if(iMenuAnterior==140 && iMenuActual==141){                 // Si acaba de iniciar el tratamiento
            switch(i8ConfigCanal){                                  // Dependiendo del canal de tratamiento
                case CHA_C:                                         // Canal A
                    initMedidasCHA();                               // Inicializa medidas
                    break;
                case CHB_C:                                         // Canal B
                    initMedidasCHB();                               // Inicializa medidas            
                    break;
                case CHC_C:                                         // Canal C    
                    initMedidasCHC();                               // Inicializa medidas
                    break;
                case POINTER_C:                                     // Pointer
                    initMedidasPoi();                               // Inicializa medidas
                    break;
            }
        }

        if(iMenuActual!=143){                                       // Si no hay error de electrodo
        
            if(iMenuAnterior==143){                                 // Si venia de un error de electrodo
                controlSonido(0);                                   // Apaga el pitido
            }

            gI=50;                                                  // Variable de escalado de la corriente

            if(iMenuAnterior==41){                                  // Si venia del menú de seleccion del canal a usar
                ST7529_clear();                                     // Limpia la pantalla
                ST7529_printf(sELECTRO_ESTIMULACION,0,0,L_,NORMAL); // Pongo el título del menú
                pantalla_seleccion();                               // Muestra los símbolos en la interfaz
            }
            
            if(iMenuAnterior!=140 && iMenuAnterior!=141 && iMenuAnterior!=142 && iMenuAnterior!=41){    // Si es la primera vez que entra al menu de terapia o viene de la selección de canales
                ST7529_clear();                                                                         // Limpio la pantalla
                ST7529_printf(sELECTRO_ESTIMULACION,0,0,L_,NORMAL);                                     // Pongo el título del menú

                if (iMenuAnterior!=143){                                                                // Si vengo de error electrodo no reinicio variables de tiempo
                    if(!(iMenuAnterior==40 && (iMenuActual==141 || iMenuActual==142))){                 // Si vengo del menú de configuración y paso a uno que está en tratamiento o reposo
                        if(i8ConfigCanal!=POINTER_C){
                            i16TimeRaw[i8ConfigCanal]=i16TacElec[i8ConfigCanal]+TIEMPO_RAMPA_ELECTRO;    // Asignacion tiempo activo a variable que se puede modificar sin machacar
                            i16TimeRepRaw[i8ConfigCanal]=i16TdElec[i8ConfigCanal];                          // Asignacion tiempo reposo a variable que se puede modificar sin machacar
                            i8NrepRaw[i8ConfigCanal]=i8Nrep[i8ConfigCanal];                                 // Asignacion repeticiones a variable que se puede modificar sin machacar
                        }else{
                            i16TimeRaw[i8ConfigCanal]=TIEMPO_POINTER;
                        }
                    }
                }

                pantalla_seleccion();                                                                   // Muestra los símbolos en la interfaz
                
                if (iMenuAnterior!=143){                                                                // Si no viene de un error de electrodo
                    if(!(iMenuAnterior==40 && (iMenuActual==141 || iMenuActual==142))){                 // Si vengo del menú de configuración y paso a uno que está en tratamiento o reposo
                        // Envio de los datos
                        // Una vez ha pintado todo el menú, procedemos a enviar el paquete con los datos configurados en el menú 40
                        // Preparo paquete de datos
                        structTratamientoElectro.si8CanalesConfigurados=i8CanalesConfigurados;          // Canales configurados                   
                        structTratamientoElectro.si8ConfigCanal=i8ConfigCanal;                          // Canal a configurar
                        structTratamientoElectro.sbSimetriaElec=bSimetriaElec[i8ConfigCanal];           // Simetria de la señal
                        structTratamientoElectro.sbPolaridadElec=bPolaridadElec[i8ConfigCanal];         // Polaridad de la señal
                        structTratamientoElectro.si16TacElec=i16TacElec[i8ConfigCanal];                 // Tiempo activo
                        structTratamientoElectro.si16TdElec=i16TdElec[i8ConfigCanal];                   // Tiempo descanso
                        // structTratamientoElectro.si8TrElec=i8TrElec[i8ConfigCanal];                     // Tiempo rampa
                        structTratamientoElectro.si8Nrep=i8Nrep[i8ConfigCanal];                         // Número de repeticiones
                        structTratamientoElectro.si16IElec=i16IElec[i8ConfigCanal];                     // Corriente
                        structTratamientoElectro.si16FrecElec=i16FrecElec[i8ConfigCanal];               // Frecuencia
                        structTratamientoElectro.si16PW_plusElec=i16PW_plusElec[i8ConfigCanal];         // Ancho de pulso positivo
                        structTratamientoElectro.si16PW_minusElec=i16PW_minusElec[i8ConfigCanal];       // Ancho de pulso negativo
                        structTratamientoElectro.si16FrecInicialMod=i16FrecInicialMod;
                        structTratamientoElectro.si16FrecFinalMod=i16FrecFinalMod;
                        structTratamientoElectro.si8ModulacionAM=i8ModulacionAM;
                        structTratamientoElectro.si32PWInicialMod=i32PWInicialMod;
                        structTratamientoElectro.si32PWFinalMod=i32PWFinalMod;
                        structTratamientoElectro.si8Tmodulacion=i8Tmodulacion;
                        structTratamientoElectro.si8SeleccionMod=i8SeleccionMod;
                        // structTratamientoElectro.sbFMDesactivado=bFMDesactivado;
                        // structTratamientoElectro.sbAMDesactivado=bAMDesactivado;
                        // structTratamientoElectro.sbPWMDesactivado=bPWMDesactivado;
                        structTratamientoElectro.si8Checksum=0;           
               
                        i8ErrorCom=0;                                                                   // Inicializa el valor del contador de errores
                        
                        configuraDatos(MODO_TRAT_ELECT);                                                // Envia comando
            
                        i8TratamientoSeleccionado=TRATAMIENTO_ELECTRO;                                  // Asigna tratamiento seleccionado
                        
                        // Inicializacion de los valores de tratamiento activo
                        // Estos valores no hayque enviarlos, simplemente es para inicializar esas variables
                        structTratamientoElectroActivo.si16IElec=i16IElec[i8ConfigCanal];               // Nivel de corriente
                        
                        structMedidasElectro.sbMAX[i8ConfigCanal]=0;                                    // Flag MAX Value
                        structMedidasElectro.sbCC[i8ConfigCanal]=0;                                     // Flag CC
                        
                        giPos=i16IElec[i8ConfigCanal];                                                  // Asigna valor de corriente a giPos
                    }
                }
            }                                                                                           // Cierre if primera vez en el menú
           
            Calc_representacion_t(i16TimeRaw[i8ConfigCanal],i16TimeRepRaw[i8ConfigCanal]);              // Calcula representación tiempo mm:ss
            
            if(!bPointerSeleccionado){                                      // Si no se encuentra el pointer configurado
                // ST7529_printf(sA,3,FILA_INIT-8,L_,i8ConfigCanal==0);        // Muestra la letra A en pantalla
                i8RepVal1=sA;
            }else{                                                          // Si se encuentra el pointer configurado
                // ST7529_printf(sP,3,FILA_INIT-8,L_,i8ConfigCanal==3);        // Muestra la letra P en pantalla
                i8RepVal1=sP;
            }
            ST7529_printf(i8RepVal1,3,FILA_INIT-8,L_,(i8ConfigCanal==0 || i8ConfigCanal==3));        // Muestra la letra P en pantalla
            ST7529_printf(sB,29,FILA_INIT-8,L_,i8ConfigCanal==1);           // Muestra la letra B en pantalla
            ST7529_printf(sC,53,FILA_INIT-8,L_,i8ConfigCanal==2);           // Muestra la letra C en pantalla

            if(i8SeleccionMod!=MOD_FM || i8SeleccionMod!=MOD_FM_AM || i8SeleccionMod!=MOD_FM_PWM || i8SeleccionMod!=MOD_FAA){
                sprintf(mystring,"       F   %3LUHz",i16frecElec[i8ConfigCanal]);      // Asigna el texto del valor de la frecuencia
            }
            if(i8SeleccionMod==MOD_FM || i8SeleccionMod==MOD_FM_AM || i8SeleccionMod==MOD_FM_PWM || i8SeleccionMod==MOD_FAA){
                sprintf(mystring,"Fmin  %3luHz Fmax  %3luHz",i16FrecInicialMod,i16FrecFinalMod);      // Asigna el texto del valor de la frecuencia
            }
            ST7529_printf(mystring,17,40,S_,0);                             // Muestra el texto de la frecuencia
            
            if(i8ConfigCanal!=POINTER_C){
                if(i8SeleccionMod!=MOD_FM_PWM || i8SeleccionMod!=MOD_PWM){
                    sprintf(mystring,"PW+ %3LU%cs",conversionPW(i16PW_plusElec[i8ConfigCanal]),cAux);
                    sprintf(mystring1,"PW- %3LU%cs",conversionPW(i16PW_minusElec[i8ConfigCanal]),cAux);
                }
                if(i8SeleccionMod==MOD_FM_PWM || i8SeleccionMod==MOD_PWM){
                    sprintf(mystring1,"PWmin %3LU%cs",conversionPW(i32PWInicialMod),cAux);
                    sprintf(mystring,"PWmax %3LU%cs",conversionPW(i32PWFinalMod),cAux);
                }
                ST7529_printf(mystring,17,50,S_,0);
                ST7529_printf(mystring1,41,50,S_,0);
            }
            
            i16IMedElec=redondeoI_100(structMedidasElectro.si16IMedElec[i8ConfigCanal][PULSO_POS]); // Redondea el valor de la corriente medida en pasos de 100 microamperios
            
            if(i8CanalesActivados&(1<<i8ConfigCanal)){                          // Si el canal que tenemos en pantalla ahora mismo esá activado
                if(i16IMedElec!=(i16IElec[i8ConfigCanal]*50)){                  // Si la corriente medida es distinta a la corriente fijada
                    ST7529_printfg(sIMED,18,60,M_,ai8EscalaGrises[1],0);        // Mostramos en gris el texto de corriente medida
                    sprintf(mystring,"%5lu[A",i16IMedElec);                    // Asignamos el texto del valor de corriente medida
                    ST7529_printfg(mystring,33,60,M_,ai8EscalaGrises[1],0);     // Mostramos en gris la corriente medida
                    
                    ST7529_printfg(sISET,18,70,M_,ai8EscalaGrises[0],0);        // Mostramos el texto de corriente set
                    sprintf(mystring,"%5lu[A",i16IElec[i8ConfigCanal]*50);     // Asignamos el texto del valor de corriente set
                    ST7529_printfg(mystring,33,70,M_,ai8EscalaGrises[0],0);     // Mostramos la corriente set
                }else{                                                          // Si la corriente medida es igual a la corriente fijada
                    ST7529_printfg(sIMED,18,60,M_,ai8EscalaGrises[0],0);        // Mostramos el texto de corriente set            
                    sprintf(mystring,"%5lu[A",i16IMedElec);                    // Asignamos el texto del valor de corriente set
                    ST7529_printfg(mystring,33,60,M_,ai8EscalaGrises[0],0);     // Mostramos la corriente set            
                    
                    // sprintf(mystring,"              ");                         // Limpia el hueco (vacio)
                    // ST7529_printfg(mystring,18,70,M_,ai8EscalaGrises[0],0);     // Limpia el hueco (vacio)
                    ST7529_printfg("              ",18,70,M_,ai8EscalaGrises[0],0);
                }
            }else{                                                              // Si el canal que tenemos en pantalla no está activado
                ST7529_printfg(sIMED,18,60,M_,ai8EscalaGrises[0],0);            // Mostramos el texto de corriente set                                    
                sprintf(mystring,"%5lu[A",0);                                  // Asignamos el texto del valor de corriente set
                ST7529_printfg(mystring,33,60,M_,ai8EscalaGrises[0],0);         // Mostramos la corriente set   

                // sprintf(mystring,"              ");                             // Limpia el hueco (vacio)
                // ST7529_printfg(mystring,18,70,M_,ai8EscalaGrises[0],0);         // Limpia el hueco (vacio)       
                ST7529_printfg("              ",18,70,M_,ai8EscalaGrises[0],0);             
            }

            float galvanica_aux=0;

            if(i8ConfigCanal!=POINTER_C){
                if(i8SeleccionMod==MOD_NOT || i8SeleccionMod==MOD_AM){
                    galvanica_aux=calculoComponenteGalvanica(i16PW_plusElec[i8ConfigCanal],i16PW_minusElec[i8ConfigCanal],i16FrecElec[i8ConfigCanal],bPolaridadElec[i8ConfigCanal]);
                }else{
                    if(i8SeleccionMod==MOD_FM || i8SeleccionMod==MOD_FM_AM || i8SeleccionMod==MOD_FAA){
                        galvanica_aux=calculoComponenteGalvanica(i16PW_plusElec[i8ConfigCanal],i16PW_minusElec[i8ConfigCanal],i16FrecFinalMod,bPolaridadElec[i8ConfigCanal]);
                    }else if(i8SeleccionMod==MOD_FM_PWM){
                        galvanica_aux=calculoComponenteGalvanica(i32PWFinalMod,0,i16FrecFinalMod,bPolaridadElec[i8ConfigCanal]);
                    }else if(i8SeleccionMod==MOD_PWM){
                        galvanica_aux=calculoComponenteGalvanica(i32PWFinalMod,0,i16FrecElec[i8ConfigCanal],bPolaridadElec[i8ConfigCanal]);
                    }
                }
                sprintf(mystring,"G %3.1f%c",galvanica_aux,37);
                ST7529_printf(mystring,44,96,S_,0);     // Mostramos en gris la corriente medida
            }
           
            i16ResElec[CHA_C]=((int32)structMedidasElectro.si16VMedElec[CHA_C][PULSO_POS]*1000)/structMedidasElectro.si16IMedElec[CHA_C][PULSO_POS];                // Obtiene el valor de resistencia del canal A               
            i16ResElec[CHB_C]=((int32)structMedidasElectro.si16VMedElec[CHB_C][PULSO_POS]*1000)/structMedidasElectro.si16IMedElec[CHB_C][PULSO_POS];                // Obtiene el valor de resistencia del canal B
            i16ResElec[CHC_C]=((int32)structMedidasElectro.si16VMedElec[CHC_C][PULSO_POS]*1000)/structMedidasElectro.si16IMedElec[CHC_C][PULSO_POS];                // Obtiene el valor de resistencia del canal C
            i16ResElec[POINTER_C]=((int32)structMedidasElectro.si16VMedElec[POINTER_C][PULSO_POS]*1000)/structMedidasElectro.si16IMedElec[POINTER_C][PULSO_POS];    // Obtiene el valor de resistencia del pointer           
            
            // He quitado un if que había aquí que era inútil
            if(!(i8CanalesActivados&(1<<i8ConfigCanal))){                          // Si el canal en pantalla se encuentra apagado
                i16ResElec[i8ConfigCanal]=0;                                    // Inicializo el valor de resistencia
                structMedidasElectro.si16VMedElec[i8ConfigCanal][PULSO_POS]=0;  // Inicializa el valor de tensión
            }
            
            ST7529_printf(sRMED,2,85,S_,0);                                     // Muestra texto de resistencia
            sprintf(mystring,"%5LU ohm",i16ResElec[i8ConfigCanal]);             // Asigna el texto del valor de resistencia
            ST7529_printf(mystring,17,85,S_,0);                                 // Muestra valor resistencia
            
            ST7529_printf(sVMED,43,85,S_,0);                                                            // Muestra texto de resistencia
            sprintf(mystring,"%5LU mV",structMedidasElectro.si16VMedElec[i8ConfigCanal][PULSO_POS]);    // Asigna el texto del valor de resistencia                                                        
            ST7529_printf(mystring,57,85,S_,0);                                                         // Muestra valor resistencia
            
            if(structMedidasElectro.si16VMedElec[i8ConfigCanal][PULSO_POS]>=10000){ // Si la tensión de salida es superior a 10 voltios (HV)                                                                    
                i8RepVal1=sHIGH_VOLTAGE;
                // ST7529_printf(sHIGH_VOLTAGE,70,45,L_,0);                            // Muestra mensaje de super alta tensión                                        
            }else{                                                                  // Si la tensión es inferior a 10 V
                i8RepVal1=sHIGH_VOLTAGE_VACIO;
                // ST7529_printf(sHIGH_VOLTAGE_VACIO,70,45,L_,0);                      // Quita mensaje HV                                            
            }
            ST7529_printf(i8RepVal1,70,45,L_,0);                      // Quita mensaje HV 
            
            sprintf(mystring,"Ta %2u:%02u",i8Tmin,i8Tseg);                    // Asigno texto tiempo activo, ahora también hay en pointer, ya que obliga normativa

            if(i8ConfigCanal!=POINTER_C){                                           // Si no estamos en un tratamiento de pointer
                // sprintf(mystring,"Ta %2u:%02u",i8Tmin,i8Tseg);                    // Asigno texto tiempo activo
                // ST7529_printf(mystring,4,96,S_,0);                                  // Muestro texto tiempo activo
               
                sprintf(mystring1,"Td %2u:%02u",i8T1min,i8T1seg);                  // Asigno texto tiempo descanso                
                // ST7529_printf(mystring1,24,96,S_,0);                                 // Muestro texto tiempo descanso
               
                sprintf(mystring2,"   N %2u",i8NrepRaw[i8ConfigCanal]);               // Asigno texto número de repeticiones                    
                // ST7529_printf(mystring2,56,96,S_,0);                                 // Muestro texto número de repeticiones
            }else{                                                                  // Si nos encontramos en tratamiento pointer
                // sprintf(mystring,"              ");                                 // Asigno texto vacio     
                // ST7529_printf(mystring,4,96,S_,0);                                  // Muestro texto vacio
               
                sprintf(mystring1,"PW = %lu [s",i16PW_plusElec[POINTER_C]);          // Asigno texto ancho de pulso                        
                // ST7529_printf(mystring1,28,96,S_,0);                                 // Muestro texto ancho de pulso
               
                sprintf(mystring2,"        ");                                       // Asigno texto vacio
                // ST7529_printf(mystring2,56,96,S_,0);                                 // Muestro texto vacio    
            }     
            ST7529_printf(mystring,4,96,S_,0);                                  // Muestro texto tiempo activo
            ST7529_printf(mystring1,24,96,S_,0);                                 // Muestro texto tiempo descanso
            ST7529_printf(mystring2,56,96,S_,0);                                 // Muestro texto número de repeticiones

        }else{                                                                      // Si hay error de electrodo
        
            if (iMenuAnterior!=143){                                                // Si acaba de detectar error de electrodo
                ST7529_clear();                                                     // Limpia la pantalla
                pitidoErrorElectrodoIndefinido();                                   // Activa el pitido
            }
            
            int8 i8CanalErrorElectrodo;                                             // creo variable auxiliar de error de electrodo
            
            if(bErrorElectrodo[CHA_C]){                                             // Si está el error activado en el canal A
                i8CanalErrorElectrodo=CHA_C;                                        // Asigno error electrodo al canal A
            }else if(bErrorElectrodo[CHB_C]){                                       // Si está el error activado en el canal B
                i8CanalErrorElectrodo=CHB_C;                                        // Asigno error electrodo al canal B
            }else if(bErrorElectrodo[CHC_C]){                                       // Si está el error activado en el canal C
                i8CanalErrorElectrodo=CHC_C;                                        // Asigno error electrodo al canal C
            }
            
            Calc_representacion_t(i16TimeRaw[i8CanalErrorElectrodo],i16TimeRepRaw[i8CanalErrorElectrodo]);  // Calcula la representación del tiempo en mm:ss
            i8Time_min=i8Tmin;                                                      // Recarga las variables para usarlas de nuevo al salir de error de electrodo
            i8Time_seg=i8Tseg;                                                      // Recarga las variables para usarlas de nuevo al salir de error de electrodo         
            i8Time1_min=i8T1min;                                                    // Recarga las variables para usarlas de nuevo al salir de error de electrodo
            i8Time1_seg=i8T1seg;                                                    // Recarga las variables para usarlas de nuevo al salir de error de electrodo
        
            ST7529_printf(sTACTIVO,6,85,S_,0);                                      // Muestra texto tiempo activo 
            ST7529_printf(sTREPOSO,38,85,S_,0);                                     // Muestra texto tiempo reposo      
          
            ST7529_printf(sELECTRO_ESTIMULACION,0,0,L_,NORMAL);                     // Muestra título electroestimulación
            ST7529_printf(sERROR_ELECTRODO,10,50,L_,NORMAL);                        // Muestra título error electrodo
            
            if(bErrorElectrodo[CHA_C]){                                             // Si hay un error de electrodo en el canal A
                i8RepVal1=sCHA_EE;
                // ST7529_printf(sCHA_EE,10,64,L_,NORMAL);                             // Muestra texto error de electrodo canal A
            }else if(bErrorElectrodo[CHB_C]){                                             // Si hay un error de electrodo en el canal B
                i8RepVal1=sCHB_EE;
                // ST7529_printf(sCHB_EE,10,64,L_,NORMAL);                             // Muestra texto error de electrodo canal B
            }else if(bErrorElectrodo[CHC_C]){                                             // Si hay un error de electrodo en el canal C
                i8RepVal1=sCHC_EE;
                // ST7529_printf(sCHC_EE,10,64,L_,NORMAL);                             // Muestra texto error de electrodo canal C
            }
            ST7529_printf(i8RepVal1,10,64,L_,NORMAL);                             // Muestra texto error de electrodo canal A

            sprintf(mystring,"%2u:%02u",i8Time_min,i8Time_seg);                     // Asigna formato texto al tiempo activo
            ST7529_printf(mystring,12,95,L_,0);                                     // Muestra tiempo activo

            sprintf(mystring,"%2u:%02u",i8Time1_min,i8Time1_seg);                   // Asigna formato texto al tiempo activo                        
            ST7529_printf(mystring,37,95,L_,0);                                     // Muestra tiempo activo    
        }                                                                           // Cierre if error de electrodo

        // Representación corrientes en tratamiento - Recuadro inferior de la pantalla
        ST7529_printf(sLINEA_SEPARACION,0,107,S_,0);                                // Muestra línea de separación
        
        if(!bPointerSeleccionado){                                                                                              // Si no hay pointer configurado
            if(i8CanalesActivados&CHA_ACT){                                                                                     // Si hay tratamiento activo del canal A
                sprintf(mystring,"Ia=%5lu [A",redondeoI_50(structMedidasElectro.si16IMedElec[CHA_C][PULSO_POS]));               // Asigna texto corriente canal A
            }else{                                                                                                              // Si no hay tratamiento activo del canal A
                sprintf(mystring,"           ");                                                                                // Limpia texto
                structMedidasElectro.si16VMedElec[CHA_C][PULSO_POS]=0;                                                          // Inicializa variable de tensión medida
                structMedidasElectro.si16IMedElec[CHA_C][PULSO_POS]=0;                                                          // Inicializa variable de corriente medida
                i16ResElec[CHA_C]=0;                                                                                            // Inicializa variable de resistencia medida
            }   
            ST7529_printf(mystring,COLUMNA_IA,FILA_CORRIENTE,S_,(i8CanalesActivados&CHA_ACT) && (i8ConfigCanal==CHA_C));        // Muestra texto por pantalla
        }else{                                                                                                                  // Si hay pointer configurado
            if(i8CanalesActivados&POINTER_ACT){                                                                                 // Si se encuentra el pointer configurado
                sprintf(mystring,"Ip=%5lu [A",redondeoI_50(structMedidasElectro.si16IMedElec[POINTER_C][PULSO_POS]));           // Asigna texto corriente pointer
            }else{                                                                                                              // Si no hay tratamiento activo del pointer
                sprintf(mystring,"           ");                                                                                // Limpia texto        
                structMedidasElectro.si16VMedElec[POINTER_C][PULSO_POS]=0;                                                      // Inicializa variable de tensión medida                                
                structMedidasElectro.si16IMedElec[POINTER_C][PULSO_POS]=0;                                                      // Inicializa variable de corriente medida                                
                i16ResElec[POINTER_C]=0;                                                                                        // Inicializa variable de resistencia medida
            }
            ST7529_printf(mystring,COLUMNA_IA,FILA_CORRIENTE,S_,(i8CanalesActivados&POINTER_ACT) && (i8ConfigCanal==POINTER_C));// Muestra texto por pantalla
        }
        
        if(i8CanalesActivados&CHB_ACT){                                                                                         // Si hay tratamiento activo del canal B                            
            sprintf(mystring,"Ib=%5lu [A",redondeoI_50(structMedidasElectro.si16IMedElec[CHB_C][PULSO_POS]));                   // Asigna texto corriente canal B                                                                                                    
        }else{                                                                                                                  // Si no hay tratamiento activo del canal B    
            sprintf(mystring,"           ");                                                                                    // Limpia texto                                    
            structMedidasElectro.si16VMedElec[CHB_C][PULSO_POS]=0;                                                              // Inicializa variable de tensión medida                                                        
            structMedidasElectro.si16IMedElec[CHB_C][PULSO_POS]=0;                                                              // Inicializa variable de corriente medida                                                        
            i16ResElec[CHB_C]=0;                                                                                                // Inicializa variable de resistencia medida                        
        }                                                                                                                       
        ST7529_printf(mystring,COLUMNA_IB,FILA_CORRIENTE,S_,(i8CanalesActivados&CHB_ACT) && (i8ConfigCanal==CHB_C));            // Muestra texto por pantalla                                                                                                               
        
        if(i8CanalesActivados&CHC_ACT){                                                                                         // Si hay tratamiento activo del canal C                       
            sprintf(mystring,"Ic=%5lu [A",redondeoI_50(structMedidasElectro.si16IMedElec[CHC_C][PULSO_POS]));                   // Asigna texto corriente canal C                                                                                               
        }else{                                                                                                                  // Si no hay tratamiento activo del canal C
            sprintf(mystring,"           ");                                                                                    // Limpia texto                               
            structMedidasElectro.si16VMedElec[CHC_C][PULSO_POS]=0;                                                              // Inicializa variable de tensión medida                                                   
            structMedidasElectro.si16IMedElec[CHC_C][PULSO_POS]=0;                                                              // Inicializa variable de corriente medida                                                   
            i16ResElec[CHC_C]=0;                                                                                                // Inicializa variable de resistencia medida                   
        }
        ST7529_printf(mystring,COLUMNA_IC,FILA_CORRIENTE,S_,(i8CanalesActivados&CHC_ACT) && (i8ConfigCanal==CHC_C));            // Muestra texto por pantalla
        
        iMenuAnterior=iMenuActual;                                                                                              // Asigna menu actual al menú anterior
    }
    
    bRefrescoPantalla=0;                                                                                                        // Inicializo flag de refresco
    
    return 0;
}

/*
*   Función: menu_180
*   Descripción: Menú de tratamiento del sistema ThetaBurst
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_180(){
    if(bRefrescoPantalla){                                              // Si debo de refrescar la pantalla
        int8 i8Time_min, i8Time_seg;                                    // Variables utilizadas para la asignación de tiempo
        
        if(iMenuAnterior==180 && iMenuActual==181){                     // Si acaba de iniciar tratamiento
            //initMedidasTB();                                          // Inicializa las medidas del TB
            bPausaTratamiento=0;    
            i16IMedTB=0;
            
        }

        if(iMenuActual!=183){                                           // Si no hay error de electrodo
            if(iMenuAnterior==183){                                     // Si viene de un error de electrodo
                controlSonido(0);                                       // Apaga el pitido
            }
            
            if(iMenuAnterior!=180 && iMenuAnterior!=181){               // Si viene de un menú distinto de tratamiento o tratamiento activo
                ST7529_clear();                                         // Limpio la pantalla
                ST7529_printf(sSMP,0,0,L_,NORMAL);                      // Pongo el título del menú
                
                if(iMenuAnterior!=183){                                 // Si no viene de un error de electrodo
                    // giPos=1;                                            // Inicializa giPos
                    giPos=i16CorrienteTB;
                    initMedidasTB();                                   // Inicializa medidas tratamiento
                }
               
                i16TimeRaw[0]=i16TactivoSMP;                            // Added 21/03/2022 Tiempo de tratamiento

                pantalla_seleccion();                                   // Muestra los símbolos en la interfaz
            }    
            
            if(iMenuActual==180){                                       // Si estamos en el menú de tratamiento
                initMedidasTB();                                       // Inicializa medidas TB

            }
            
            if(iMenuActual==180){                                       // Si estamos en el menú de tratamiento
                // quitar_config();                                     // Quita el icono de configuración
                poner_flecha_izq();                                     // Pone el icono de flecha izquierda
            }else if(iMenuActual==181){                                 // Si estamos en el menú de tratamiento activo

                // poner_config();                                      // Pone el icono de configuración
                quitar_flecha_izq();                                    // Quita el icono de flecha izquierda
            }
            
            Calc_representacion_t(i16TimeRaw[0],0);                     // Obtiene representación tiempo mm:ss

            // ST7529_printf(sINTENSIDAD,30,26,S_,0);                      // Muestra el texto de corriente
            ST7529_printf(sINTENSIDAD,2,26,S_,0);                      // Added 21/03/2022 Muestra el texto de corriente
            // ST7529_printf("[A",59,53,S_,0);                             // Muestra unidades corriente
            ST7529_printf("[A",36,55,S_,0);                             // Muestra unidades corriente
                                
                  
            i16IMedTB=structMedidasThetaBurst.si16IMedTB;            // Inicializa variable struct medida corriente   
            i16ResTB=structMedidasThetaBurst.si16ResTB;              // Inicializa variable struct medida resistencia
            i16VMedTB=structMedidasThetaBurst.si16VmedTB;            // Inicializa variable struct medida tensión
            i16NPulsosBurstRestanteTB=structMedidasThetaBurst.si16NPulsosBurstRestanteTB;
            i8NBurstTrenRestanteTB=structMedidasThetaBurst.si8NBurstTrenRestanteTB;
            i8NTrenesRestanteTB=structMedidasThetaBurst.si8NTrenesRestanteTB;

          
            
            if(i8NTrenesRestanteTB==0){
                bDeboApagarTratamientoTB=1;
            }
        
            if(((i16IMedTB/1000.0)*i16ResTB)>=10000){                 // Si la tensión de salida es superior a 10 voltios (HV)
                i8RepVal1=sHIGH_VOLTAGE;
                // ST7529_printf(sHIGH_VOLTAGE,70,45,L_,0);                // Muestra mensaje de super alta tensión                
            }else{                                                      // Si la tensión es inferior a 10 V
                i8RepVal1=sHIGH_VOLTAGE_VACIO;
                // ST7529_printf(sHIGH_VOLTAGE_VACIO,70,45,L_,0);          // Quita mensaje HV                                     
            }
            ST7529_printf(i8RepVal1,70,45,L_,0);          // Quita mensaje HV
           
            if((iMenuAnterior==80 && iMenuActual==180)){                // Si es la primera vez que entra al menú desde el menú de configuración TB

                // Envio el paquete de datos 
                // Una vez ha pintado todo el menú, procedemos a enviar el paquete con los datos configurados en el menú 80
                // Preparo paquete de datos
                
                structTratamientoThetaBurst.si16PWBurstTB=i16PWBurstTB;
                // if(iMenuAnterior==90){
                //     if(i16NPulsosBurstTB<=1 && i8NBurstTrenTB<=1){
                //         i16NPulsosBurstTB=50;
                //     }
                // }
                structTratamientoThetaBurst.si16NPulsosBurstTB=i16NPulsosBurstTB;
                ;
                // if(structTratamientoThetaBurst.si16NPulsosBurstTB==50){
               
                // }
                structTratamientoThetaBurst.si8SepPulsosTB=i8SepPulsosTB;
                structTratamientoThetaBurst.si16SepBurstTB=i16SepBurstTB;
                structTratamientoThetaBurst.si8NBurstTrenTB=i8NBurstTrenTB;
                structTratamientoThetaBurst.si8SepTrenesTB=i8SepTrenesTB;
                structTratamientoThetaBurst.si8NTrenesTB=i8NTrenesTB;
                structTratamientoThetaBurst.sbPolaridadTB=bPolaridadTB;
                structTratamientoThetaBurst.si16CorrienteTB=i16CorrienteTB;
                // structTratamientoThetaBurst.si8PulsosRampaTB=i8PulsosRampaTB;
                i32MaxCorrienteTBEntreTrenes=MAX_CORRIENTE_TB;
                
                i8ErrorCom=0;                                                           // Inicializa el valor del contador de errores

                configuraDatos(MODO_TRAT_TB);                                          // Envia comando

                i8TratamientoSeleccionado=TRATAMIENTO_TB;                              // Indica selección de tratamiento
                
                structTratamientoThetaBurstActivo.si16CorrienteTB=i16CorrienteTB;                    // Configuración corriente en el sistema ThetaBurst (activo)   
                           
            
            }
            
            #ifdef SMP_INCREMENTOS_CAPADOS{

                if((iMenuAnterior==180 && iMenuActual==181)|| (iMenuAnterior==183 && iMenuActual==181)){    // Si acaba de iniciar tratamiento o viene de un error de electrodo
                    i32MaxCorrienteTBEntreTrenes=i16CorrienteTB+MAX_INCREMENTO_CORREINTE_ENTRETRENES;
                    quitar_cancelar();                                                                      // Quita el icono de cancelar
                    bMAXRulanchaEntreTrenes=0; 
                }
                

                if(i16IMedTB!=0){
                    i32MaxCorrienteTBEntreTrenes=i16CorrienteTB+MAX_INCREMENTO_CORREINTE_ENTRETRENES;
                }

                if(i8NTrenesRestanteTB != i8NTrenesAnteriorTB){
                    
                    i8NTrenesAnteriorTB=i8NTrenesRestanteTB;
                    // i32MaxCorrienteTBEntreTrenes=i16CorrienteTB+MAX_INCREMENTO_CORREINTE_ENTRETRENES;

                    bMAXRulanchaEntreTrenes=0;
                    // f_avisos();
                } 
            }
            #else{

                if((iMenuAnterior==180 && iMenuActual==181)|| (iMenuAnterior==183 && iMenuActual==181)){    // Si acaba de iniciar tratamiento o viene de un error de electrodo
                    quitar_cancelar();                                                                      // Quita el icono de cancelar
                }
            }
            #endif
            

            sprintf(mystring,"%5lu",redondeoI_50(i16IMedTB));          // Asigna el texto del valor de corriente medida redondeada
            // ST7529_printf(mystring,1,40,XL_,0);                        
            ST7529_printf(mystring,0,40,XL_,0);                         // Added 21/03/2022 Muestra el texto del valor de corriente medida redondeada
            
            ST7529_printf(sISET,43,87,S_,0);                            // Muestra texto corriente  
            sprintf(mystring,"%5LU [A",i16CorrienteTB*100);             // Asigna texto valor corriente
            ST7529_printf(mystring,55,87,S_,0);                         // Muestra texto valor corriente

            ST7529_printf(sVMED,43,97,S_,0);                            // Muestra texto tensión
            sprintf(mystring,"%5LU mV",i16VMedTB);                      // Asigna texto valor tensión
            ST7529_printf(mystring,55,97,S_,0);                         // Muestra texto valor tensión
            
            ST7529_printf(sRMED,43,107,S_,0);                           // Muestra texto resistencia
            sprintf(mystring,"%5LU ohm",i16ResTB);                      // Asigna texto valor resistencia
            ST7529_printf(mystring,55,107,S_,0);                        // Muestra texto valor resistencia


            // ST7529_printf(sISET,44,87,S_,0);                            // Muestra texto corriente
            // sprintf(mystring,"%5LU [A",i16CorrienteTB*100);             // Asigna texto valor corriente
            // ST7529_printf(mystring,57,87,S_,0);                         // Muestra texto valor corriente

            // ST7529_printf(sVMED,44,97,S_,0);                            // Muestra texto tensión
            // sprintf(mystring,"%5LU mV",i16VMedTB);                     // Asigna texto valor tensión
            // ST7529_printf(mystring,57,97,S_,0);                         // Muestra texto valor tensión

            // ST7529_printf(sRMED,44,107,S_,0);                           // Muestra texto resistencia
            // sprintf(mystring,"%5LU ohm",i16ResTB);                     // Asigna texto valor resistencia
            // ST7529_printf(mystring,57,107,S_,0);                        // Muestra texto valor resistencia
            
            ST7529_printf("Trenes",44,26,S_,0);                      // Added 21/03/2022 Muestra el texto de corriente
            sprintf(mystring,"%3U",i8NTrenesRestanteTB);                     // Asigna texto valor TRENES RESTANTES
            ST7529_printf(mystring,40,40,XL_,0);
            
            // sprintf(mystring,"P %3LU ",i16NPulsosBurstRestanteTB);                    // Asigna texto valor corriente
            // // ST7529_printf(mystring,10,87,S_,0);                         // Muestra texto valor corriente
            // ST7529_printf(mystring,44,37,S_,0);

            // sprintf(mystring,"B %3U ",i8NBurstTrenRestanteTB);                     // Asigna texto valor tensión
            // // ST7529_printf(mystring,10,97,S_,0);                         // Muestra texto valor tensión
            // ST7529_printf(mystring,44,47,S_,0);

            // sprintf(mystring,"T %3U ",i8NTrenesRestanteTB);                     // Asigna texto valor resistencia
            // // ST7529_printf(mystring,10,107,S_,0);                        // Muestra texto valor resistencia
            // ST7529_printf(mystring,44,57,S_,0);

            // Added 21/03/2022
            Calc_representacion_t(i16TimeRaw[0],0);
            ST7529_printf(sTIEMPO,2,80,S_,0);
            //ST7529_printf(sTIEMPO,2,80,S_,0);
            sprintf(mystring,"%2u:%02u ",i8Tmin,i8Tseg);
            ST7529_printf(mystring,0,94,XL_,0);

        }else{                                                          // Si hay error de electrodo
            if (iMenuAnterior!=183){                                    // Si acaba de entrar al error de electrodo
                ST7529_clear();                                         // Limpia la pantalla
                pitidoErrorElectrodoIndefinido();                       // Activa el pitido
            }

            Calc_representacion_t(i16TimeRaw[0],0);                     // Cálcula de nuevo la representación del tiempo
            i8Time_min=i8Tmin;                                          // Recarga las variables de tiempo en el caso de error de electrodo
            i8Time_seg=i8Tseg;                                          // Recarga las variables de tiempo en el caso de error de electrodo
            
            ST7529_printf(sTACTIVO,25,85,S_,0);                         // Muestra texto tiempo activo
            ST7529_printf(sSMP,10,0,L_,NORMAL);                         // Muestra título
            ST7529_printf(sERROR_ELECTRODO,10,50,L_,NORMAL);            // Muestra texto error de electrodo
            sprintf(mystring,"%2u:%02u",i8Time_min,i8Time_seg);         // Asigna texto formateado valor tiempo 
            ST7529_printf(mystring,29,95,L_,0);                         // Muestra texto valor tiempo
        }

        iMenuAnterior=iMenuActual;                                      // Asigna menu actual al menú anterior
    }   
    
    bRefrescoPantalla=0;                                                // Inicializo flag de refresco
    
    return 0;
}

/*
*   Función: menu_200
*   Descripción: Menú de autoapagado
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_200(){
    if(iMenuAnterior!=200){                                 // Si viene de un menú diferente
        ST7529_clear();                                     // Limpia la pantalla
        iMenuReposo=iMenuAnterior;                          // GUardo menú anterior en menú de reposo
    }
   
    int32 iTiempoDesc=(600000-var_tiempo)*0.001;            // Calcula el tiempo en segundos

    sprintf(mystring,"Quedan %Lu segundos",iTiempoDesc);    // Muestra por pantalla el tiempo restante
    ST7529_printf(mystring,10,30,L_,NORMAL);                // Muestra por pantalla el tiempo restante
    ST7529_printf(sAUTOAPAG_1,10,50,L_,NORMAL);             // Muestra texto de autoapagado 1
    ST7529_printf(sAUTOAPAG_2,0,90,L_,NORMAL);              // Muestra texto de autoapagado 2
    ST7529_printf(sAUTOAPAG_3,15,110,L_,NORMAL);            // Muestra texto de autoapagado 3
    
    giPos=0;                                                // Inicialza giPos

    iMenuAnterior=iMenuActual;                              // Asigna menu actual al menú anterior

    return 0;
}

/*
*   Función: menu_201
*   Descripción: Menú de apagado del equipo
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_201(){

    if(iMenuAnterior!=201){                         // Si viene d eun menú distinto
        ST7529_clear();                             // Limpia la pantalla
    }

    ST7529_printf(sAPAGADO_EQUIPO,15,50,L_,NORMAL); // Muestra mensaje apagado del equipo

    iMenuAnterior=iMenuActual;                      // Asigna menu actual al menú anterior
   
    return 0;
}

// /*
// *   Función: DEPRECATED menu_202
// *   Descripción: DEPRECATED Menú de error de transistores
// *
// *   Input:
// *         - 
// *   Output:
// *         - 
// */
// int8 menu_202(){

//     if(iMenuAnterior!=202){                             // DEPRECATED    
//         ST7529_clear();                                 // DEPRECATED
//     }
//     ST7529_printf(sERROR_TRANSISTORES,10,50,L_,NORMAL); // DEPRECATED

//     pausa_ms(1000);                                     // DEPRECATED
//     ControlSonido(0);                                   // DEPRECATED

//     iMenuAnterior=iMenuActual;                          // DEPRECATED
    
//     return 0;
// }

// /*
// *   Función: DEPRECATED menu_203
// *   Descripción: DEPRECATED Menú de error del sistema de medida
// *
// *   Input:
// *         - 
// *   Output:
// *         - 
// */
// int8 menu_203(){

//     if(iMenuAnterior!=204){                                 // DEPRECATED    
//         ST7529_clear();                                     // DEPRECATED
//     }
//     ST7529_printf(sERROR_SISTEMA_MEDIDA,5,50,L_,NORMAL);    // DEPRECATED
   
//     pausa_ms(1000);                                         // DEPRECATED
//     ControlSonido(0);                                       // DEPRECATED    
    
//     iMenuAnterior=iMenuActual;                              // DEPRECATED
    
//     return 0;
// }

/*
*   Función: menu_204
*   Descripción: Menú de carga del dispositivo
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_204(){

    float fCalcTiempo;                                  // Variable auxiliar para cálculo de tiempo
    int8 i8BatMinutos=0;                                // Variable auxiliar para tiempo (minutos)
    int8 i8BatHoras=0;                                  // Variable auxiliar para tiempo (segundos)
    int8 i8NivelBateria=nivelBateria();                              // Variable auxiliar para el nivel de bateria

    if(iMenuAnterior!=204){                             // Si viene de un menú distinto
        ST7529_clear();                                 // Limpia la pantalla
    }
    
    if(getFC()){                                        // Si las baterias han sido cargadas al 100% (comprobado mediante el flag de FC del BQ34Z100G1)              
        i8RepVal1=sCARGA_COMPLETA;                      // Asigna texto carga completa
        output_low(LED_CHG_R);                          // Apaga LED rojo de carga
        output_high(LED_CHG_V);                         // Enciende LED verde de carga
    }else{                                              // Si todavia se encuentra en proceso de carga

        i8RepVal1=sCARGA_CURSO;                         // Asigna texto carga en curso
        fCalcTiempo=getATTF()/60.0;                     // Calcula el tiempo en horas
        i8BatHoras=fCalcTiempo;                         // Trunca tiempo a horas
        i8BatMinutos=(fCalcTiempo-i8BatHoras)*60;       // Obtiene los minutos y trunca el resultado
        ST7529_printf(sCARGA_COMPLETA_TIEMPO,9,100,S_,0);   // Muestra texto tiempo carga
        sprintf(mystring,"%2u h %2u min ",i8BatHoras,i8BatMinutos);  // Asigna texto formateado del tiempo
        ST7529_printf(mystring,46,100,S_,0);                        // Muestra tiempo en pantalla

        if(i8BatHoras>35 && getSOC()<58){           // SOL: Si quedan 35 horas de carga y el valor de la batería es superior al 62%, la carga ha sido incorrecta
            output_low(LED_CHG_R);                          // Apaga LED rojo de carga
            output_high(LED_CHG_V);                         // Enciende LED verde de carga
            ST7529_printf(sCARGA_INCORRECTA,9,100,S_,0);    // Muestra texto tiempo carga
            i8RepVal1=sCARGA_COMPLETA;                      // Asigna texto carga completa
        }
        
        if((i8BatHoras>=68 && getSOC()>58) || (i8NivelBateria >= i8BateriaMaxima) ){                             // Si ya no se carga mas pero no se ha alcanzado el 100% de bateria real
        // if(i8BatHoras>=68){                             // Si ya no se carga mas pero no se ha alcanzado el 100% de bateria real
            i16ContadorMaximaBateria++;
            if((i16ContadorMaximaBateria>1000) || (i8NivelBateria >= i8BateriaMaxima) ){             // Para evitar falsos positivos

                output_low(LED_CHG_R);                  // Apaga LED rojo de carga
                output_high(LED_CHG_V);                 // Enciende LED verde de carga
                i8BateriaMaxima = i8NivelBateria;       // Guardamos este nivel como el nuevo maximo
                i16ContadorMaximaBateria=0;
                i8RepVal1=sCARGA_COMPLETA;              // Asigna texto carga completa
            }
        }
        else{
            i16ContadorMaximaBateria=0;
            output_high(LED_CHG_R);                      // Enciende LED rojo
            output_high(LED_CHG_V);                      // Enciende LED verde
        }
    }

    if(i8NivelBateria>=i8BateriaMaxima){                 // Si haciendo ciclos de carga y descarga se supera el maximo nivel de bateria anterior
        i8BateriaMaxima = i8NivelBateria;                // Guardamos este nivel como el nuevo maximo
    }

    ST7529_printf(i8RepVal1,15,10,L_,0);                 // Muestra texto estado de la carga
   
    sprintf(mystring,"%u %%",(int8)(((float)i8NivelBateria/i8BateriaMaxima)*100.0));    // Obtiene el valor de bateria y lo asigan como texto
    ST7529_printf(mystring,25,40,XL_,0);                // Muestro texto estado carga

    sprintf(mystring,"                                ");                                // Limpia el texto (vacio)
    if(!input_state(MENU_2)){                                                   // Si presionamos esta tecla
        // sprintf(mystring,"V: %04Ld mV I: %04Ld mA",getVoltage(),getCurrent());  // Asigna el texto de tensión y corriente de carga actual
        sprintf(mystring,"V: %04Ld mV I: %04Ld mA Bat: %u %%",getVoltage(),getCurrent(),nivelBateria());  // Asigna el texto de tensión y corriente de carga actual
    }

    ST7529_printf(mystring,9,80,S_,0);         // Muestra el texto de tensión y corriente de carga actual

    iMenuAnterior=iMenuActual;                  // Asigna menu actual al menú anterior
   
    return 0;
}

/*
*   Función: menu_205
*   Descripción: Menú de error de comunicaciones
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_205(){
    
    ST7529_clear();                                             // Limpia la pantalla
    
    if(!bComprobacionInicial){                                  // Si no está comprobando las comunicaciones iniciales
        bComprobacionInicial=0;                                 // Inicializa el flag de comprobación inicial (Preciso?? -.-')
        bEmpiezaContadorTiempo=0;                               // Inicializa flag empezar contador de tiempo
        control_DC(0,EN_30);                                    // Deshabilita DC/DC 30V
        
        if(iMenuAnterior>=180){                           // Si estamos en TB 
            apagadoTB();                                       // Inicializo variables
            bTratamientoTBActivado=0;                          // Inicializo variable
        }else if(i8CanalesActivados || iMenuAnterior>=140){                                 // Si estamos en electroestimulación
            apagadoCanales();                                   // Inicializo variables
        }else if(iMenuAnterior>=130){
            apagadoTranscraneal();
        }else if(iMenuAnterior>=120){                                                  // Si estamos en galvánica y/o micro
            apagadoMicrocorrientes();                           // Inicializo variables
            bTratamientoGalvanicaActivado=0;                    // Inicializo variable
        }
        initReles();                                            // Inicializa el estado de los relés
    }
    
    encendidoLedsRojos();                                       // Enciende todos los LEDs rojos
    
    ST7529_printf(sCODIGO_ERROR,20,50,M_,NORMAL);               // Muestra texto código de error
    
    if(bErrorComunicaciones){                                   // Si hay error de comunicaciones entre el secundario y el principal
        sprintf(mystring,"%03u",REG_ERROR_COMMS_O_S);           // Asigno texto error entre el secundario y el principal
    }else{                                                      // Si hay error de comunicaciones entre el principal y el secundario
        sprintf(mystring,"%03u",REG_ERROR_COMMS_S_O);           // Asigno texto error entre el principal y el secundario
    }
    
    ST7529_printf(mystring,33,70,M_,NORMAL);                    // Muestro el texto de error
    
    pitidoLargoError();                                         // Enciendo pito
    reset_orco();                                               // Hago un reset a Orco    
    pausa_ms(3000);                                             // Delay pito + pantalla          
    i8BufferIndex=0;                                            // Inicializo índice buffer de entrada de datos
    apagadoLedsRojos();                                         // Apaga todos los LEDs rojos
    
    return 0;
}

/*
*   Función: menu_206
*   Descripción: Menú de error de calibrado
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_206(){
       
    ST7529_clear();                                         // Limpio la pantalla
    
    ST7529_printf(sCODIGO_ERROR,20,50,M_,NORMAL);           // Pongo el texto de código de error
    
    sprintf(mystring,"%03u",i8CodigoErrorRepresentacion);   // Asigna texto código error
    ST7529_printf(mystring,33,70,M_,NORMAL);                // Muestro error por pantalla
    
    if(i8CanalesActivados){                                 // Si estamos en electroestimulación
        apagadoCanales();                                   // Inicializo variables
    }else if(iMenuAnterior>=180){                           // Si estamos en TB 
        apagadoTB();                                       // Inicializo variables
        bTratamientoTBActivado=0;                          // Inicializo variable
    }else{                                                  // S iestamos en galvánica y/o micro
        apagadoMicrocorrientes();                           // Inicializo variables
        bTratamientoGalvanicaActivado=0;                    // Inicializo variable
    }
    
    encendidoLedsRojos();                                   // Enciende todos los LEDs rojos
    
    initReles();                                            // Inicialización relés
    
    pitidoLargoError();                                     // Enciendo pito
                                              
    reset_orco();                                           // Hago un reset a Orco    
    pausa_ms(3000);                                         // Delay pito + pantalla          
    
    apagadoLedsRojos();                                     // Apaga todos los LEDs rojos
    
    return 0;
}

/*
*   Función: menu_207
*   Descripción: Menú código de error genérico
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_207(){
    ST7529_clear();                                         // Limpio la pantalla
    
    ST7529_printf(sCODIGO_ERROR,20,50,M_,NORMAL);           // Pongo el texto de código de error
    
    sprintf(mystring,"%03u",i8CodigoErrorRepresentacion);   // Asigna texto código error
    ST7529_printf(mystring,33,70,M_,NORMAL);                // Muestro error por pantalla
    
    bEvitaRebotePausa=0;                                    // Inicializa flag anterebotes pausa
    
    return 0;
}

/*
*   Función: submenu_22
*   Descripción: Ajuste del nivel de corriente con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_22(){
    switch (iMenuActual){                                           // Dependiendo del menú actual
        case 20:                                                    // Menú galvánica/galvánica+microcorrientes
            if (giPos==1){                                          // Si estamos ajustando la corriente de tratamiento galvánico
                min=MINIMA_CORRIENTE_GALVANICA;                     // Asignamos valor mínimo
                if(bCableBipolarConectado){                         // Si está el accesorio bipolar conectado
                    max=MAXIMA_CORRIENTE_GALVANICA_BIPOLAR;         // Asignamos valor máximo en bipolar
                }else{                                              // Si no hay accesorio bipolar conectado
                    max=MAXIMA_CORRIENTE_GALVANICA;                 // Asignamos valor máximo
                }
            }else if (giPos==5){                                    // Si estamos ajustando la corriente de tratamiento microcorrientes
                min=MINIMA_CORRIENTE_MICROCORRIENTES;               // Asignamos valor mínimo
                max=MAXIMA_CORRIENTE_MICROCORRIENTES;               // Asignamos valor máximo
            }
            break;
        case 30:                                                    // Menú transcraneal
            min=2;                                                  // Asigno mínimo

            max=(int16)fSuperficieElectrodo*LIMITE_DENSIDAD_CORRIENTE; // Asigno máximo de corriente
                
            if(max>=1000){                                          // Si la corriente es superior a 1000 uA
                max/=100;                                           // Realizo redondeo de 100
                max*=100;                                           // Ya que en corrientes superiores a 1000uA los saltos son de 100uA
            }
            max/=50;                                                // Se divide por el factor de corriente
            
            if(max>=MAXIMA_CORRIENTE_TRANSCRANEAL){                 // Si la corriente máxima obtenida es superior al máximo permitido (MAXIMA_CORRIENTE_TRANSCRANEAL)
                max=MAXIMA_CORRIENTE_TRANSCRANEAL;                  // Asigno máximo a MAXIMA_CORRIENTE_TRANSCRANEAL
            }
            
            if(i16Itrans>=max){                                     // Si la corriente seleccionada es superior al máximo
                i16Itrans=max;                                      // Se asigna al máximo
            }
            break;
        case 40:                                                    // Menú electroestimulación
            max=MAXIMA_CORRIENTE_INICIO_ELECTRO;                    // Asignamos valor mínimo
            min=MINIMA_CORRIENTE_ELECTROESTIMULACION;               // Asignamos valor máximo
            gI=50;                                                  // Multiplicador/factor de corriente
            break;
        case 80:
            max=MAX_CORRIENTE_TB;
            min=MIN_CORRIENTE_TB;
            gI=100;
            break;
    }

    if(giPosRulancha>max){                                          // Si el valor obtenido es superior al máximo
        giPosRulancha=max;                                          // Asigna valor máximo
    }
    
    if (giPosRulancha<=min){                                        // Si el valor obtenido es inferior al mínimo
        giPosRulancha=min;                                          // Asigna valor mínimo
    }

    switch (iMenuActual){                                           // Dependiendo del menú en el que estemos
        case 20:                                                    // Menú galvánica/galvánica+microcorrientes
            if(giPos==1){                                           // Si estamos en galvánica
                i16IGalv[bSeleccionGalvanica]=giPosRulancha;        // Asigna el valor de corriente galvánica
                i32CGalv=calc_CargaGalv(i16IGalv[bSeleccionGalvanica]); // Se obtiene el valor de carga eléctrica
            }else if(giPos==5){                                     // Si estamos en microcorrientes
                i16Imicro=giPosRulancha;                            // Asigna el valor de corriente microcorrientes
            }
            break;
        case 30:                                                    // Menú transcraneal
            i16Itrans=giPosRulancha;                                // Asigna el valor de corriente
            i32CTrans=calc_CargaTrans(i16Itrans);                   // Se obtiene el valor de carga eléctrica
            break;
        case 40:                                                    // Menú electroestimulación
            i16IElec[i8ConfigCanal]=giPosRulancha;                  // Asigna el valor de corriente
            break;
        case 80:
            i16CorrienteTB=giPosRulancha;
            break;
    }
}

/*
*   Función: submenu_23
*   Descripción: Ajuste del tiempo de rampa con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_23(){
    if(iMenuActual!=30){
        if(giPosRulancha>MAXIMO_TIEMPO_RAMPA){                      // Si el tiempo de rampa es superior a MAXIMO_TIEMPO_RAMPA
            giPosRulancha=MAXIMO_TIEMPO_RAMPA;                      // Asigna MAXIMO_TIEMPO_RAMPA
        }
    }

    if (giPosRulancha<=MINIMO_TIEMPO_RAMPA){                    // Si el tiempo de rampa es inferior o igual a MINIMO_TIEMPO_RAMPA    
        giPosRulancha=MINIMO_TIEMPO_RAMPA;                      // Asigna MINIMO_TIEMPO_RAMPA
    }

    switch (iMenuActual){                                       // Dependiendo del menú actual
        case 20:                                                // Menú galvánica/galvánica++microcorrientes
            if(giPos==3){                                       // Si estamos en tratamiento galvánica
                if(i16TGalv[bSeleccionGalvanica]!=0){           // Si el tiempo de tratamiento es distinto de infinito
                    // if((float)giPosRulancha>=(i16TGalv[bSeleccionGalvanica]/3.0)){  // Si el tiempo de rampa es superior a 1/3 del tiempo de tratamiento
                    //     giPosRulancha=(i16TGalv[bSeleccionGalvanica]/3);    // Asignamos el tiempo de rampa de 1/3 de tiempo de tratamiento
                    // }
                    if (giPosRulancha<=MINIMO_TIEMPO_RAMPA){                    // Si el tiempo de rampa es inferior o igual a MINIMO_TIEMPO_RAMPA    
                        giPosRulancha=MINIMO_TIEMPO_RAMPA;                      // Asigna MINIMO_TIEMPO_RAMPA
                    }
                }
                i8TrampaGalv[bSeleccionGalvanica]=giPosRulancha;        // Asignamos el tiempo de rampa
                i8Trampamicro=i8TrampaGalv[bSeleccionGalvanica];
                i32CGalv=calc_CargaGalv(i16IGalv[bSeleccionGalvanica]); // Calculamos la carga eléctrica
            }
            break;
        case 30:                                                // Menú transcraneal
            // Added 17/03/2022 Tiempo de rampa in y out para tDCS
            if(giPos==4){                                       // Si estamos configurando el tiempo de rampa
                if(giPosRulancha>MAXIMO_TIEMPO_RAMPA_SUBIDA_TDCS){
                    giPosRulancha=MAXIMO_TIEMPO_RAMPA_SUBIDA_TDCS;
                }
                i8TrampaTrans=giPosRulancha;                    // Asignamos el tiempo de rampa  
            }else if(giPos==5){
                if(giPosRulancha>MAXIMO_TIEMPO_RAMPA_BAJADA_TDCS){
                    giPosRulancha=MAXIMO_TIEMPO_RAMPA_BAJADA_TDCS;
                }
                i8TrampaTransBajada=giPosRulancha;                    // Asignamos el tiempo de rampa
            }
            i32CTrans=calc_CargaTrans(i16ITrans);           // Calculamos la carga eléctrica  
            break;
        // case 40:
        //     i8TrElec[i8ConfigCanal]=giPosRulancha;              // Asignamos valor de rulancha al tiempo de rampa
        //     if(giPos==4){                                       // Si estamos configurando el tiempo de rampa
        //         // if((float)giPosRulancha>=(i16TacElec[i8ConfigCanal]/3.0)){  // Si el tiempo de rampa es superior a 1/3 del tiempo de tratamiento
        //         //     giPosRulancha=(i16TacElec[i8ConfigCanal]/3);    // Asignamos el tiempo de rampa de 1/3 de tiempo de tratamiento
        //         // }
        //         if(giPosRulancha<=MINIMO_TIEMPO_RAMPA){
        //             giPosRulancha=MINIMO_TIEMPO_RAMPA;
        //         }
        //         i8TrElec[i8ConfigCanal]=giPosRulancha;              // Asignamos valor de rulancha al tiempo de rampa
        //     }
        //     break;
    }
    
    if (giPosRulancha<=MINIMO_TIEMPO_RAMPA){            // Si el tiempo de rampa es inferior o igual a MINIMO_TIEMPO_RAMPA
        giPosRulancha=MINIMO_TIEMPO_RAMPA;              // Asigna MINIMO_TIEMPO_RAMPA
    }
}

/*
*   Función: submenu_27
*   Descripción: Ajuste del ancho de pulso con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_27(){
    switch (iMenuActual){                   // Dependiendo del menú en el que estemos
        case 20:                            // Menú microcorrientes
            maxBW=MAXIMO_ANCHO_PULSO_MICRO;                       // Asigno máximo ancho de pulso
            break;
        case 40:                            // Menú electroestimulación
            if(i8ConfigCanal==POINTER_C){   // Si estamos en pointer
                maxBW=40;                   // Asigno máximo ancho de pulso
            }// else{                          // Si estamos en cualquier otro canal de electroestimulación
                // maxBW=MAXIMO_ANCHO_PULSO_ELECTROESTIMULACION;                   // Asigno máximo ancho de pulso
            // }
            
            // if(giPos==10){                                                                          // Si se trata del ancho de pulso positivo
            //     maxBW=((900000.0/i16FrecElec[i8ConfigCanal])-(i16PW_minusElec[i8ConfigCanal]))/25;  // Asigno máximo ancho de pulso a partir de la frecuencia y el ancho de pulso negativo
            // }else if(giPos==11){                                                                    // Si se trata del ancho de pulso positivo
            //     maxBW=((900000.0/i16FrecElec[i8ConfigCanal])-(i16PW_plusElec[i8ConfigCanal]))/25;   // Asigno máximo ancho de pulso a partir de la frecuencia y el ancho de pulso positivo
            // }
            
            if(maxBW>=MAXIMO_ANCHO_PULSO_ELECTROESTIMULACION){                  // Si el ancho de ulso obtenido es superior al límite
                maxBW=MAXIMO_ANCHO_PULSO_ELECTROESTIMULACION;                   // Asigno límte
            }
            break;
        // case 49:
        //     if(maxBW>=MAXIMO_ANCHO_PULSO_ELECTROESTIMULACION){                  // Si el ancho de ulso obtenido es superior al límite
        //         maxBW=MAXIMO_ANCHO_PULSO_ELECTROESTIMULACION;                   // Asigno límte
        //     }
        //     break;
        case 80:                            // Menú TB
            maxBW=MAX_PW_BURST;                       // Asigno máximo ancho de pulso
            break;
    }

    if(giPosRulancha>=maxBW){           // Si el valor seleccionado es superior a maxBW
        giPosRulancha=maxBW;            // Asigna maxBW
    }
    if(iMenuActual==80){ // Solo TB
        if(giPosRulancha<=MIN_PW_BURST){           // Si el valor seleccionado es inferior a min
            giPosRulancha=MIN_PW_BURST;            // Asigna min
        }
    }else if(iMenuActual==40){
        if(giPosRulancha<MINIMO_ANCHO_PULSO_ELECTROESTIMULACION){                // Si el valor seleccionado es inferior al mínimo
            giPosRulancha=MINIMO_ANCHO_PULSO_ELECTROESTIMULACION;                // Asigna mínimo
        }
        if(i8SeleccionMod==MOD_PWM || i8SeleccionMod==MOD_FM_PWM){
            if(giPos==13){
                if(giPosRulancha<3){                // Si el valor seleccionado es inferior al mínimo
                    giPosRulancha=3;                // Asigna mínimo
                }
            }
            // if(giPos==14){
            //     if(giPosRulancha>=(i32PWFinalMod/25)){                // Si el valor seleccionado es inferior al mínimo
            //         if(i32PWFinalMod>1000){
            //             giPosRulancha=i32PWFinalMod/25-40;
            //         }
            //         if(i32PWFinalMod>10000){
            //             giPosRulancha=i32PWFinalMod/25-200;
            //         }
            //     }
            // }
        }
    }else{
        if(giPosRulancha<5){                // Si el valor seleccionado es inferior al mínimo
            giPosRulancha=5;                // Asigna mínimo
        }
    }
    
    switch (iMenuActual){                   // Dependiendo del menú en el que estemos
        case 20:                            // Menú microcorrientes
            i16PWmicro=giPosRulancha*25;    // Asigna ancho de pulso
            break;
        case 40:                                                                    // Menú electroestimulación
            if(giPos==13){
                if(i8SeleccionMod==MOD_PWM || i8SeleccionMod==MOD_FM_PWM){
                    if(giPosRulancha>2){
                        min=i32PWInicialMod/25+1;
                    }
                    if(giPosRulancha>40){
                        min=i32PWInicialMod/25+40;
                    }
                    if(giPosRulancha>400){
                        min=i32PWInicialMod/25+200;
                    }
                    if(giPosRulancha<=min){                                               // Si la frecuencia elegida es superior o igual al máximo fijado
                        giPosRulancha=min;                                                   // Asigna el valor máximo
                    }
                    i32PWFinalMod=giPosRulancha*25;
                }else{
                    i16PW_plusElec[i8ConfigCanal]=giPosRulancha*25;                     // Asigna ancho de pulso
                }
                if(i8SimetriaCanales!=0){                                           // DEPRECATED
                    copiarDatosSimetria(0);                                         // DEPRECATED
                }

                if(i8ConfigCanal==POINTER_C){                                       // Si estamos en pointer
                    i16PW_minusElec[i8ConfigCanal]=i16PW_plusElec[i8ConfigCanal];   // Asigna ancho de pulso positivo al pulso negativo
                }
            }else if(giPos==14){
                if(i8SeleccionMod==MOD_PWM || i8SeleccionMod==MOD_FM_PWM){
                    // if(giPosRulancha>=(i32PWFinalMod/25)){
                    //     if(giPosRulancha>40){
                    //         giPosRulancha=i32PWFinalMod/25-40;
                    //     }
                    //     if(giPosRulancha>400){
                    //         giPosRulancha=i32PWFinalMod/25-200;
                    //     }
                    // }
                    if(giPosRulancha>2){
                        max=i32PWFinalMod/25-1;
                    }
                    if(giPosRulancha>40){
                        max=i32PWFinalMod/25-40;
                    }
                    if(giPosRulancha>400){
                        max=i32PWFinalMod/25-200;
                    }
                    if(giPosRulancha>=max){                                               // Si la frecuencia elegida es superior o igual al máximo fijado
                        giPosRulancha=max;                                                   // Asigna el valor máximo
                    }
                    i32PWInicialMod=giPosRulancha*25;
                }else{
                    i16PW_minusElec[i8ConfigCanal]=giPosRulancha*25;                     // Asigna ancho de pulso
                }
                if(i8SimetriaCanales!=0){                                           // DEPRECATED
                    copiarDatosSimetria(0);                                         // DEPRECATED
                }
            }
            break;
        // case 49:
        //     if(giPos==4){
        //         i32PWInicialMod=giPosRulancha*25;
        //     }else if(giPos==5){
        //         i32PWFinalMod=giPosRulancha*25;
        //     }
        //     break;
        case 80:                            // Menú TB
            i16PWBurstTB=giPosRulancha*25;                                              // Asigna ancho de pulso

            break;
    }
}
  
/*
*   Función: submenu_28
*   Descripción: Ajuste de la frecuencia con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_28(){

    switch (iMenuActual){                           // Dependiendo del menú en el que estemos
        case 20:                                    // Si estamos en tratamiento microcorrientes
            max=MAXIMA_FRECUENCIA_MICRO;                                // Definimos máximo valor de frecuencia
            min=MINIMA_FRECUENCIA_MICRO;                                  // Definimos mínimo valor de frecuencia    
            gF=1;                                   // Definimos factor de ganancia de frecuencia
            break;       
        case 40:                                    // Si estamos en tratamiento de electroestimulación
            max=i16FrecLimSup[i8ConfigCanal];       // Definimos máximo valor de frecuencia       
            min=i16FrecLimInf[i8ConfigCanal];       // Definimos mínimo valor de frecuencia 
            if(i8SeleccionMod==MOD_FM || i8SeleccionMod==MOD_FM_AM || i8SeleccionMod==MOD_FM_PWM || i8SeleccionMod==MOD_FAA){
                max=500;
                min=1;
            }
            break;
        // case 49:                                    // Added 07/04/2022 Modular frecuencia en FM
        //     max=500;
        //     min=1;
        //     break;
    }
    
    if(i8SeleccionMod!=MOD_FM && i8SeleccionMod!=MOD_FM_AM && i8SeleccionMod!=MOD_FM_PWM && i8SeleccionMod!=MOD_FAA){
        i16FrecuenciaAnterior=giPosRulancha*gF;         // Asignamos valor de frecuencia anterior
    }

    if(iMenuActual!=20 && (i8SeleccionMod!=MOD_FM && i8SeleccionMod!=MOD_FM_AM && i8SeleccionMod!=MOD_FM_PWM && i8SeleccionMod!=MOD_FAA)){                            // Si estamos en un menú distinto al de microcorrientes
        if (i16FrecuenciaAnterior>200 && i16FrecuenciaAnterior<=10000){         // Si la frecuencia de tratamiento es superior a 200 y menor o igual a 10000 (dummy value)
            gF=50;                                                              // Asigna factor de ganancia de frecuencia
            giPosRulancha=i16FrecuenciaAnterior/gF;                             // Obtenemos valor a asignar para la rulancha
        }else if(i16FrecuenciaAnterior==200){                                   // Si la frecuencia de tratamiento es igual a 200
            if(bascendente){                                                    // Si estamos incrementando la frecuencia
                gF=50;                                                          // Asigna factor de ganancia de frecuencia
                giPosRulancha=i16FrecuenciaAnterior/gF;                         // Obtenemos valor a asignar para la rulancha
            }else{                                                              // Si estamos decrementando la frecuencia
                gF=10;                                                          // Asigna factor de ganancia de frecuencia
                giPosRulancha=i16FrecuenciaAnterior/gF;                         // Obtenemos valor a asignar para la rulancha
            }
        }else if (i16FrecuenciaAnterior>100 && i16FrecuenciaAnterior<200){      // Si la frecuencia de tratamiento es superior a 100 e inferior a 200
            if(giPosRulancha==3 && gF==50){                                     // Si estabamos en 200 y ahora al volver atras quiere mostrar 150
                giPosRulancha=19;                                               // Le decimos que la cuenta es de 10 en 10
                i16FrecuenciaAnterior=190;                                      // Salta a 190
            }
            gF=10;                                                              // Asigna factor de ganancia de frecuencia
            giPosRulancha=i16FrecuenciaAnterior/gF;                             // Obtenemos valor a asignar para la rulancha
        }else if(i16FrecuenciaAnterior==100){                                   // Si la frecuencia de tratamiento es igual a 100
            if(bascendente){                                                    // Si estamos incrementando la frecuencia
                gF=10;                                                          // Asigna factor de ganancia de frecuencia
                giPosRulancha=i16FrecuenciaAnterior/gF;                         // Obtenemos valor a asignar para la rulancha
            }else{                                                              // Si estamos decrementando la frecuencia
                gF=2;                                                           // Asigna factor de ganancia de frecuencia
                giPosRulancha=i16FrecuenciaAnterior/gF;                         // Obtenemos valor a asignar para la rulancha
            } 
        }else if (i16FrecuenciaAnterior>20 && i16FrecuenciaAnterior<100){       // Si la frecuencia de tratamiento es superior a 20 e inferior a 100
            if(giPosRulancha==9 && gF==10){                                     // Si estabamos en 100 y ahora al volver atras quiere mostrar 90
                giPosRulancha=49;                                               // Le decimos que la cuenta es de 2 en 2
                i16FrecuenciaAnterior=98;                                       // Salta a 98
            }
            gF=2;                                                               // Asigna factor de ganancia de frecuencia
            giPosRulancha=i16FrecuenciaAnterior/gF;                             // Obtenemos valor a asignar para la rulancha
        }else if(i16FrecuenciaAnterior==20){                                    // Si la frecuencia de tratamiento es superior a 20
            if(bascendente){                                                    // Si estamos incrementando la frecuencia
                gF=2;                                                           // Asigna factor de ganancia de frecuencia
                giPosRulancha=i16FrecuenciaAnterior/gF;                         // Obtenemos valor a asignar para la rulancha
            }else{                                                              // Si estamos decrementando la frecuencia
                gF=1;                                                           // Asigna factor de ganancia de frecuencia
                giPosRulancha=i16FrecuenciaAnterior/gF;                         // Obtenemos valor a asignar para la rulancha
            } 
        }else{                                                                  // Para el resto de frecuencias
            if(giPosRulancha==9 && gF==2){                                      // Si estabamos en 20 y ahora al volver atras quiere mostrar 18                
                giPosRulancha=19;                                               // Le decimos que la cuenta es de 10 en 10        
                i16FrecuenciaAnterior=19;                                       // Salta a 19    
            }
            gF=1;                                                               // Asigna factor de ganancia de frecuencia
            giPosRulancha=i16FrecuenciaAnterior;                                // Obtenemos valor a asignar para la rulancha
        }
    }

    // if(iMenuActual==40 && (i8SeleccionMod==MOD_FM || i8SeleccionMod==MOD_FM_AM || i8SeleccionMod==MOD_FM_PWM)){
    //     if(giPos==11){
    //         max=i16FrecFinalMod-gF;
    //     }else if(giPos==12){
    //         min=i16FrecInicialMod+gF;
    //     }
    // }

    if((i8SeleccionMod!=MOD_FM && i8SeleccionMod!=MOD_FM_AM && i8SeleccionMod!=MOD_FM_PWM && i8SeleccionMod!=MOD_FAA)){
        if ((giPosRulancha*gF)>=max){                                               // Si la frecuencia elegida es superior o igual al máximo fijado
            giPosRulancha=max/gF;                                                   // Asigna el valor máximo
        }
        if ((giPosRulancha*gF)<min){                                                // Si la frecuencia elegida es inferior al mínimo fijado
            giPosRulancha=min/gF;                                                   // Asigna el valor mínimo
        }
    }else{
        if ((giPosRulancha)>=max){                                               // Si la frecuencia elegida es superior o igual al máximo fijado
            giPosRulancha=max;                                                   // Asigna el valor máximo
        }
        if ((giPosRulancha)<min){                                                // Si la frecuencia elegida es inferior al mínimo fijado
            giPosRulancha=min;                                                   // Asigna el valor mínimo
        }
    }

    switch (iMenuActual){                                                       // Dependiendo del menú actual
        case 20:                                                                // Menú microcorrientes
            i16frecmicro=giPosRulancha*gF;                                      // Asignamos valor de frecuencia a la variable de frecuencia
            maxBW=Calc_BWmax(i16frecmicro,bpolaridadmicro);                     // Calculamos y asignamos el valor de máximo ancho de pulso a partir de la frecuencia
            break;
        case 40:                                                                // Menú electroestimulación
            if(i8SeleccionMod==MOD_FM || i8SeleccionMod==MOD_FM_AM || i8SeleccionMod==MOD_FM_PWM || i8SeleccionMod==MOD_FAA){
                if(giPos==11){
                    if(giPosRulancha>1){
                        max=i16FrecFinalMod-1;
                    }
                    if(giPosRulancha>20){
                        max=i16FrecFinalMod-2;
                    }
                    if(giPosRulancha>100){
                        max=i16FrecFinalMod-10;
                    }
                    if(giPosRulancha>200){
                        max=i16FrecFinalMod-50;
                    }
                    if(giPosRulancha>=max){                                               // Si la frecuencia elegida es superior o igual al máximo fijado
                        giPosRulancha=max;                                                   // Asigna el valor máximo
                    }
                    i16FrecInicialMod=giPosRulancha;
                }else if(giPos==12){
                    if(giPosRulancha>1){
                        min=i16FrecInicialMod+1;
                    }
                    if(giPosRulancha>20){
                        min=i16FrecInicialMod+2;
                    }
                    if(giPosRulancha>100){
                        min=i16FrecInicialMod+10;
                    }
                    if(giPosRulancha>200){
                        min=i16FrecInicialMod+50;
                    }
                    if(giPosRulancha<=min){                                               // Si la frecuencia elegida es superior o igual al máximo fijado
                        giPosRulancha=min;                                                   // Asigna el valor máximo
                    }
                    i16FrecFinalMod=giPosRulancha;
                }
            }else{
                i16frecElec[i8ConfigCanal]=giPosRulancha*gF;                        // Asignamos valor de frecuencia a la variable de frecuencia
                // maxBW=Calc_BWmax(i16frecElec[i8ConfigCanal],bpolaridadElec[i8ConfigCanal]);     // Calculamos y asignamos el valor de máximo ancho de pulso a partir de la frecuencia
                // i16PW_plusElec[i8ConfigCanal]=Calc_BW(maxBW,i16PW_plusElec[i8ConfigCanal]);     // Comrpobamos si el PW máximo es inferior a los valores del PW+, si es así, fijamos el máximo
                // i16PW_minusElec[i8ConfigCanal]=Calc_BW(maxBW,i16PW_minusElec[i8ConfigCanal]);   // Comrpobamos si el PW máximo es inferior a los valores del PW-, si es así, fijamos el máximo

                if(i8SimetriaCanales!=0){                                           // DEPRECATED                        
                    copiarDatosSimetria(0);                                         // DEPRECATED                        
                }                                                         
            }
            break;
        // case 49:
        //     if(giPos==1){
        //         i16FrecInicialMod=giPosRulancha*gF;
        //     }else if(giPos==2){
        //         i16FrecFinalMod=giPosRulancha*gF;
        //     }

        //     // int TmodMax;

        //     // if(i16FrecFinalMod<i16FrecInicialMod){
        //     //     i16FrecFinalMod=i16FrecInicialMod+gF;
        //     // }
        //     // if(i16FrecFinalMod<=2){
        //     //     i16FrecFinalMod=2;
        //     // }

        //     // if(i16FrecInicialMod>i16FrecFinalMod){
        //     //     i16FrecInicialMod=i16FrecFinalMod-gF;
        //     // }

        //     // TmodMax=5*(1.0/i16FrecInicialMod+1.0/i16FrecFinalMod);

        //     // if(i8Tmodulacion<TmodMax){
        //     //     i8Tmodulacion=TmodMax;
        //     // }

        //     // Added 07/04/2022 Cálculo automático del ancho de pulso
        //     // maxBW=Calc_BWmax(i16FrecFinalMod,bpolaridadElec[CHB_C]);     // Calculamos y asignamos el valor de máximo ancho de pulso a partir de la frecuencia
        //     // i16PW_plusElec[CHB_C]=Calc_BW(maxBW,i16PW_plusElec[CHB_C]);     // Comrpobamos si el PW máximo es inferior a los valores del PW+, si es así, fijamos el máximo
        //     // i16PW_minusElec[CHB_C]=Calc_BW(maxBW,i16PW_minusElec[CHB_C]);   // Comrpobamos si el PW máximo es inferior a los valores del PW-, si es así, fijamos el máximo
        //     break;
    }
}

/*
*   Función: submenu_29
*   Descripción: Selección de polaridad de la señal con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_29(){
    
    if(iMenuActual==20){                                            // Si estamos en el menú de configuración de galvánica+microcorrientes
        if(giPosRulancha>2){                                        // Si se ha llegado al máximo valor
            giPosRulancha=2;                                        // Asigna máximo valor
        }
    }else{                                                          // Si es otro menú
        if(giPosRulancha>1){                                        // Si se ha llegado al máximo valor
            giPosRulancha=1;                                        // Asigna máximo valor
        }
    }

    if (giPosRulancha<=0){                                          // Si se ha llegado al mínimo valor
        giPosRulancha=0;                                            // Asigna mínimo valor
    }

    switch(iMenuActual){                                            // Dependiendo del menú actual
        case 20:                                                    // Menú microcorrientes
            bPolaridadMicro=giPosRulancha>>1;                       // Asigna valor de polaridad
            bMonopolarPosNeg=giPosRulancha&0x01;                    // Asigna polaridad monopolar
            maxBW=Calc_BWmax(i16frecmicro,bpolaridadmicro);         // Calcula y asigna máximo ancho de pulso permitido
            i16PWmicro=Calc_BW(maxBW,i16PWmicro);                   // Calcula y asigna si superoa el máximo ancho de pulso permitido
            break;
        case 40:                                                    // Menú electroestimulación
            bpolaridadElec[i8ConfigCanal]=giPosRulancha;            // Asigna valor de polaridad
            // maxBW=Calc_BWmax(i16frecElec[i8ConfigCanal],bpolaridadElec[i8ConfigCanal]);     // Calcula y asigna máximo ancho de pulso permitido
            // i16PW_plusElec[i8ConfigCanal]=Calc_BW(maxBW,i16PW_plusElec[i8ConfigCanal]);     // Calcula y asigna si supera el máximo ancho de pulso + permitido
            // i16PW_minusElec[i8ConfigCanal]=Calc_BW(maxBW,i16PW_minusElec[i8ConfigCanal]);   // Calcula y asigna si supera el máximo ancho de pulso - permitido

            if(i8SimetriaCanales!=0){                               // DEPRECATED
                copiarDatosSimetria(0);                             // DEPRECATED
            }
            break;      
        case 80:
            bPolaridadTB=giPosRulancha;
            break;
    }
}

/*
*   Función: submenu_33
*   Descripción: Selección de simetría de la señal con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_33(){
    if(giPosRulancha>1){                                    // Si ha llegado al valor máximo
        giPosRulancha=1;                                    // Asigna valor máximo
    }
    
    if (giPosRulancha<=0){                                  // Si ha llegado al valor mínimo
        giPosRulancha=0;                                    // Asigna valor mínimo
    }
   
    if(giPosRulancha){                                      // Si hemos configurado para que sea simétrica la señal
        bpolaridadElec[i8ConfigCanal]=1;                    // Asigna señal bipolar
    }
                 
    switch (iMenuActual){                                   // Dependiendo del menú en el que estemos
        case 40:                                            // Menú electroestimulación
            bsimetriaElec[i8ConfigCanal]=giPosRulancha;     // Asigna valor de simetría
            // maxBW=Calc_BWmax(i16frecElec[i8ConfigCanal],bpolaridadElec[i8ConfigCanal]);     // Calcula y asigna máximo ancho de pulso permitido
            // i16PW_plusElec[i8ConfigCanal]=Calc_BW(maxBW,i16PW_plusElec[i8ConfigCanal]);     // Calcula y asigna si supera el máximo ancho de pulso + permitido
            // i16PW_minusElec[i8ConfigCanal]=Calc_BW(maxBW,i16PW_minusElec[i8ConfigCanal]);   // Calcula y asigna si supera el máximo ancho de pulso - permitido
            if(i8SimetriaCanales!=0){       // DEPRECATED
                copiarDatosSimetria(0);     // DEPRECATED
            }
            break;
    }
}

/*
*   Función: submenu_34
*   Descripción: Selección de la superficie del electrodo con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_34(){
    float fRawElect=(float)(i16ITrans*50)/LIMITE_DENSIDAD_CORRIENTE;    // Selección de la superficie de electrodo mínima
    
    min=fRawElect;                                  // AAsigno mínimo obtenido  // Si no...
    if(abs(fRawElect-(int16)fRawElect) >0.5){           // Si la resta es superior a 0.5
        min=(int16)fRawElect+0.5;                       // Se asigna 0.5 más al mínimo obtenido
    }

    if(min<MIN_TAM_ELECTRODO){                          // Si el mínimo obtenido es inferior al valor mínimo permitido por MIN_TAM_ELECTRODO
        min=MIN_TAM_ELECTRODO;                          // Asigno mínimo a MIN_TAM_ELECTRODO
    }
    
    if(giPosRulancha>MAX_TAM_ELECTRODO){                // Si el valor obtenido es superior a MAX_TAM_ELECTRODO
        giPosRulancha=MAX_TAM_ELECTRODO;                // Asigna MAX_TAM_ELECTRODO
    }
   
    if (giPosRulancha<min){                             // Si el valor es inferior al valor mínimo
        giPosRulancha=min;                              // Asigna valor mínimo
    }
   
    fSuperficieElectrodo=giPosRulancha*0.5;            // Asigna valor de superficie de electrodo
    
    // if((i16ITrans*50)>=((int16)fSuperficieElectrodo*LIMITE_DENSIDAD_CORRIENTE)){
    //     i16ITrans=(int16)fSuperficieElectrodo*LIMITE_DENSIDAD_CORRIENTE;
    // }
    max=(int16)fSuperficieElectrodo*LIMITE_DENSIDAD_CORRIENTE; // Asigno máximo de corriente
                
    if(max>=1000){                                          // Si la corriente es superior a 1000 uA
        max/=100;                                           // Realizo redondeo de 100
        max*=100;                                           // Ya que en corrientes superiores a 1000uA los saltos son de 100uA
    }
    max/=50;                                                // Se divide por el factor de corriente
    
    if(max>=MAXIMA_CORRIENTE_TRANSCRANEAL){                 // Si la corriente máxima obtenida es superior al máximo permitido (MAXIMA_CORRIENTE_TRANSCRANEAL)
        max=MAXIMA_CORRIENTE_TRANSCRANEAL;                  // Asigno máximo a MAXIMA_CORRIENTE_TRANSCRANEAL
    }
    
    if(i16Itrans>=max){                                     // Si la corriente seleccionada es superior al máximo
        i16Itrans=max;                                      // Se asigna al máximo
    }


    // Added 11/05/2022 Guardo parte decimal en fDecimalesSuperficieElectrodo
    // fDecimalesSuperficieElectrodo=(float)fSuperficieElectrodo-(int)fSuperficieElectrodo;
}

/*
*   Función: submenu_42
*   Descripción: Ajuste del tiempo de tratamiento con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_42(){

    switch (iMenuActual){                                                   // Dependiendo del menú en el que se encuentre
        case 20:                                                            // Menú galvánica/galvánica+microcorrientes
            if(giPos==2){                                                   // Si estanos ajustando el tiempo de galvánica
                if(giPosRulancha>MAXIMO_TIEMPO_GALVANICA){                  // Si se elige un tiempo superior a MAXIMO_TIEMPO_GALVANICA
                    giPosRulancha=MAXIMO_TIEMPO_GALVANICA;                  // Se asigna MAXIMO_TIEMPO_GALVANICA
                }
                if(bSeleccionGalvanica){                                    // Si estamos en el menú de galvánica+microcorrientes
                    if (giPosRulancha<=MINIMO_TIEMPO_GALVAMICRO){           // Si el valor de tiempo es inferior o igual a MINIMO_TIEMPO_GALVAMICRO
                        giPosRulancha=MINIMO_TIEMPO_GALVAMICRO;             // Se asigna MINIMO_TIEMPO_GALVAMICRO
                    }
                }else{                                                      // Si estamos en el menú de galvánica
                    if (giPosRulancha<=MINIMO_TIEMPO_GALVANICA){            // Si el valor de tiempo es inferior o igual a MINIMO_TIEMPO_GALVANICA (Si es 0, tiempo ilimitado)
                        giPosRulancha=MINIMO_TIEMPO_GALVANICA;              // Se asigna MINIMO_TIEMPO_GALVANICA
                    }
                }
                i16TGalv[bSeleccionGalvanica]=giPosRulancha;                // Asignamos valor de tiempo galvánica

                if(i16TGalv[bSeleccionGalvanica]!=0){                                                   // Si el triemp ode tratamiento no es infinito
                    // if((float)i8TrampaGalv[bSeleccionGalvanica]>=(i16TGalv[bSeleccionGalvanica]/3.0)){  // Si el tiempo de de rampa es superioa a 1/3 del tiempo de tratamiento
                    //     i8TrampaGalv[bSeleccionGalvanica]=(i16TGalv[bSeleccionGalvanica]/3);            // Asigno 1/3 del tiempo de tratamiento al tiiempo de rampa
                    // }
                    if(i8TrampaGalv[bSeleccionGalvanica]<=MINIMO_TIEMPO_RAMPA){
                        i8TrampaGalv[bSeleccionGalvanica]=MINIMO_TIEMPO_RAMPA;
                    }
                }
                if(i8TrampaGalv[bSeleccionGalvanica]>=10){                  // Si el tiempo de rampa es superior o igual a 10
                    i8TrampaGalv[bSeleccionGalvanica]=10;                   // Asigno máximo 10 segundos
                }
                i32CGalv=calc_CargaGalv(i16IGalv[bSeleccionGalvanica]);     // Calculo el valor de carga electrica del tratamiento
            }else if (giPos==6){                                            // Si estamos ajustando el tiempo de microcorrientes
                if(giPosRulancha>MAXIMO_TIEMPO_MICRO){                      // Si se elige un tiempo superior a MAXIMO_TIEMPO_MICRO
                    giPosRulancha=MAXIMO_TIEMPO_MICRO;                      // Se asigna MAXIMO_TIEMPO_MICRO
                }
                if (giPosRulancha<=MINIMO_TIEMPO_MICRO){                    // Si el valor de tiempo es inferior o igual a MINIMO_TIEMPO_MICRO
                    giPosRulancha=MINIMO_TIEMPO_MICRO;                      // Se asigna MINIMO_TIEMPO_MICRO
                }
                i16Tmicro=giPosRulancha;                                    // Asignamos valor de tiempo a microcorrientes
            }
            break;
        case 30:                                                            // Menú transcraneal
            if(giPos==3){                                                   // Si estamos ajustando el tiempo de tratamiento
                if(giPosRulancha>MAXIMO_TIEMPO_TRANSCRANEAL){               // Si el tiempo elegido es superior a MAXIMO_TIEMPO_TRANSCRANEAL
                    giPosRulancha=MAXIMO_TIEMPO_TRANSCRANEAL;               // Asigna MAXIMO_TIEMPO_TRANSCRANEAL
                }

                if (giPosRulancha<=MINIMO_TIEMPO_TRANSCRANEAL){             // Si el tiempo elegido es inferior o igual a MINIMO_TIEMPO_TRANSCRANEAL
                    giPosRulancha=MINIMO_TIEMPO_TRANSCRANEAL;               // Asigna MINIMO_TIEMPO_TRANSCRANEAL
                }

                i16Ttrans=giPosRulancha*SALTOS_TIEMPO_TRANSCRANEAL;         // Asigna tiempo a variable de tiempo transcraneal

                // if(i16Ttrans!=0){                                           // Si el tiempo de tratamiento no es infinito
                //     // if((float)i8Trampatrans>=((i16Ttrans)/3.0)){            // Si el tiempo de rampa es superior a 1/3 del tiempo de tratamiento
                //     //     i8Trampatrans=((i16Ttrans)/3);                      // Asigna como máximo 1/3 del tiempo de tratamiento
                //     // }
                // }
                // if(i8Trampatrans>=10){                                      // Si el tiempo de rampa es superior al máximo 
                //     i8Trampatrans=10;                                       // Asigna valor máximo
                // }
                i32Ctrans=calc_CargaTrans(i16Itrans);                       // Calculo el valor de carga electrica del tratamiento
            }
            break;
        case 40:                                                            // Menú electroestimulación
            if(giPos==3){                                                   // Si estamos configurando el tiempo activo
                if(giPosRulancha>MAXIMO_TIEMPO_ELECTROESTIMULACION){        // Si el valor es superior a MAXIMO_TIEMPO_ELECTROESTIMULACION
                    giPosRulancha=MAXIMO_TIEMPO_ELECTROESTIMULACION;        // Asignamos MAXIMO_TIEMPO_ELECTROESTIMULACION
                }
                if (giPosRulancha<=MINIMO_TIEMPO_ELECTROESTIMULACION){      // Si el valor es inferior o igual a MINIMO_TIEMPO_ELECTROESTIMULACION
                    giPosRulancha=MINIMO_TIEMPO_ELECTROESTIMULACION;        // Asignamos MINIMO_TIEMPO_ELECTROESTIMULACION 
                }
                i16TacElec[i8ConfigCanal]=giPosRulancha;  // Asignamos tiempo de tratamiento   
            }else if(giPos==4){                                                         // Si estamos configurando el tiempo de descanso
                if(giPosRulancha>MAXIMO_TIEMPO_DESCANSO_ELECTROESTIMULACION){           // Si el valor es superior a MAXIMO_TIEMPO_DESCANSO_ELECTROESTIMULACION
                    giPosRulancha=MAXIMO_TIEMPO_DESCANSO_ELECTROESTIMULACION;           // Asignamos MAXIMO_TIEMPO_DESCANSO_ELECTROESTIMULACION 
                } 
                if (giPosRulancha<=MINIMO_TIEMPO_DESCANSO_ELECTROESTIMULACION){         // Si el valor es inferior o igual a MINIMO_TIEMPO_DESCANSO_ELECTROESTIMULACION
                    giPosRulancha=MINIMO_TIEMPO_DESCANSO_ELECTROESTIMULACION;           // Asignamos MINIMO_TIEMPO_DESCANSO_ELECTROESTIMULACION
                }
                i16TdElec[i8ConfigCanal]=giPosRulancha;  // Asignamos tiempo de descanso 
            }else if(giPos==5){
                // if(i8SeleccionMod==MOD_FAA){
                //     if(giPosRulancha<=MINIMO_TMOD_ALTERNA){
                //         giPosRulancha=MINIMO_TMOD_ALTERNA;
                //     }
                // }else{
                //     if(giPosRulancha<=MINIMO_TMOD_BARRIDO){
                //         giPosRulancha=MINIMO_TMOD_BARRIDO;
                //     }
                // }

                if(giPosRulancha<=min_Tmod){
                    giPosRulancha=min_Tmod;
                }

                if(giPosRulancha>=MAXIMO_TMOD){
                    giPosRulancha=MAXIMO_TMOD;
                }

                i8Tmodulacion=giPosRulancha;
            }
            break;
    }
}

/*
*   Función: submenu_43
*   Descripción: Ajuste del número de repeticiones con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_43(){

    if(giPosRulancha>100){                  // Si el número de repeticiones es superior a 100
        giPosRulancha=100;                  // Asigna 100
    }
    if (giPosRulancha<1){                   // Si el número de repeticiones es inferior a 1
        giPosRulancha=1;                    // Asigna 1
    }
    
    i8Nrep[i8ConfigCanal]=giPosRulancha;    // Asigna valor de repeticiones
}

/*
*   Función: submenu_81
*   Descripción: Ajuste campos SMP
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_81(){
    int16 i16MinMenu81,i16MaxMenu81;
    switch(giPos){
        case 2:                 // N�mero de pulsos TB   
            i16MinMenu81=MIN_N_PULSOS_BURST;
            i16MaxMenu81=MAX_N_PULSOS_BURST;
            break;
        case 3:                 // Separaci�n entre pulsos TB
            // Added 28/02/2022 Nueva condicion para la minima separacion entre pulsos, ya que podemos bajar a 1ms
            // if(bPolaridadTB){
            //     fMin=2*(i16PWBurstTB)/1000;
            // }else{
            //     fMin=(i16PWBurstTB)/1000;
            // }
            // if(fMin<MIN_SEP_PULSOS){
            //     i16MinMenu81=MIN_SEP_PULSOS;
            // }else{
            //     i16MinMenu81=(int16)fMin+1;
            // }
            i16MinMenu81=MIN_SEP_PULSOS;
            i16MaxMenu81=MAX_SEP_PULSOS;
            break;
        case 4:                 // Numero de burst TB
            i16MinMenu81=MIN_N_BURST_TREN;
            i16MaxMenu81=MAX_N_BURST_TREN;
            break;
        case 5:                 // Separaci�n entre burst TB
            // if(bPolaridadTB){                                                           // Si la señal es bipolar ...
            //     fMin=(i16NPulsosBurstTB-1)*i8SepPulsosTB+2*i16PWBurstTB/1000;    // ... SBmin=(NP-1)*SP+2PW (condicion de minimo)
            // }else{                                                                      // Si la señal es monoplar ...
            //     fMin=(i16NPulsosBurstTB-1)*i8SepPulsosTB+i16PWBurstTB/1000;      // ... SBmin=(NP-1)*SP+PW (condicion de minimo)
            // }
            // if(fMin<MIN_SEP_BURST){                        
            //     i16MinMenu81=MIN_SEP_BURST;
            // }else{                                              // Redondeo hacia arriba
            //     if(fMin<1000){
            //         if(redondeo10(fMin)<=fMin){                     // Si el valor redondeado es menor que el valor sin redondear ...
            //             i16MinMenu81=redondeo10(fMin)+10;           // ... redondeo en pasos de 10, a la decena siguiente
            //         }else{                                          // Si el valor redondeado es mayor o igual que el valor sin redondear ...
            //             i16MinMenu81=redondeo10(fMin);              // ... redondeo en pasos de 10
            //         }
            //     }else{
            //         if(redondeo50(fMin)<=fMin){                     // Si el valor redondeado es menor que el valor sin redondear ...
            //             i16MinMenu81=redondeo50(fMin)+50;           // ... redondeo en pasos de 50, a la decena siguiente
            //         }else{                                          // Si el valor redondeado es mayor o igual que el valor sin redondear ...
            //             i16MinMenu81=redondeo50(fMin);              // ... redondeo en pasos de 50
            //         }
            //     }
            // }
            i16MinMenu81=MIN_SEP_BURST;
            i16MaxMenu81=MAX_SEP_BURST;
            break;
        case 6:                 // N�mero de trenes TB
            i16MinMenu81=MIN_N_TRENES;
            i16MaxMenu81=MAX_N_TRENES;
            break;
        case 7:                 // Separaci�n entre trenes TB
            // if(bPolaridadTB){                                                                                               // Si la señal es bipolar ...
            //     fMin=((i8NBurstTrenTB-1)*i16SepBurstTB+(i16NPulsosBurstTB-1)*i8SepPulsosTB+2*i16PWBurstTB/1000)/1000;       // ... SBmin=(NB-1)*SB+(NP-1)*SP+2PW (condicion de minimo)
            // }else{                                                                                                          // Si la señal es monoplar ...
            //     fMin=((i8NBurstTrenTB-1)*i16SepBurstTB+(i16NPulsosBurstTB-1)*i8SepPulsosTB+i16PWBurstTB/1000)/1000;         // ... SBmin=(NB-1)*SB+(NP-1)*SP+PW (condicion de minimo)
            // }
            // if(fMin<MIN_SEP_TREN){                        
            //     i16MinMenu81=MIN_SEP_TREN;
            // }else{                                              // Redondeo hacia arriba
            //     if(redondeo1(fMin)<=fMin){                     // Si el valor redondeado es menor que el valor sin redondear ...
            //         i16MinMenu81=redondeo1(fMin)+1;            // ... redondeo en pasos de 1, a la univdad siguiente
            //     }else{                                          // Si el valor redondeado es mayor o igual que el valor sin redondear ...
            //         i16MinMenu81=redondeo1(fMin);              // ... redondeo en pasos de 1
            //     }
                    
            // }
            i16MinMenu81=MIN_SEP_TREN;
            i16MaxMenu81=MAX_SEP_TREN;
            break;
    }

    if(giPosRulancha<=i16MinMenu81){
        giPosRulancha=i16MinMenu81;
    }

    if(giPosRulancha>=i16MaxMenu81){
        giPosRulancha=i16MaxMenu81;
    }

    switch(giPos){
        case 2:                 // N�mero de pulsos TB   
            i16NPulsosBurstTB=giPosRulancha;
            break;
        case 3:                 // Separaci�n entre pulsos TB
            i8SepPulsosTB=giPosRulancha;
            break;
        case 4:                 // Numero de burst TB
            i8NBurstTrenTB=giPosRulancha;
            break;
        case 5:                 // Separaci�n entre burst TB
            i16SepBurstTB=giPosRulancha;
            break;
        case 6:                 // N�mero de trenes TB
            i8NTrenesTB=giPosRulancha;
            break;
        case 7:                 // Separaci�n entre trenes TB
            i8SepTrenesTB=giPosRulancha;
            break;
        // case 9:                 // Added 22/02/2022 Numero de pulsos de rampa TB
        //     i8PulsosRampaTB=giPosRulancha;
        //     break;
    }
}

/*
*   Función: submenu_21 Added 27/01/2022
*   Descripción: Selección de tiempo automatico con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_21(){

    if(giPosRulancha>1){                                    // Si ha llegado al valor máximo
        giPosRulancha=1;                                    // Asigna valor máximo
    }
    
    if (giPosRulancha<=0){                                  // Si ha llegado al valor mínimo
        giPosRulancha=0;                                    // Asigna valor mínimo
    }

    // Added 17/03/2022 Seleccion de tiempo auto segun el menu
    switch(iMenuActual){
        case 20:
            bTiempoAutoGalv=giPosRulancha;              // 0: Tiempo no auto, 1: Tiempo auto
            break;
        case 30:
            bTiempoAutoTrans=giPosRulancha;             // 0: Tiempo no auto, 1: Tiempo auto
            break;
    }
}

/*
*   Función: submenu_25 Added 27/01/2022
*   Descripción: Selección de tipo de tratamiento Galvanica (0), Microcorrientes (1), Galvanica + Microcorrientes (2)
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_25(){

    if(iMenuAnterior!=20){
        giPosRulancha=i8SeleccionGalvMicro;
    }

    if(giPosRulancha>=2){                             // Si ha llegado al valor máximo
        giPosRulancha=2;                             // Asigna valor máximo
    }
    
    if (giPosRulancha<=0){                           // Si ha llegado al valor mínimo
        giPosRulancha=0;                             // Asigna valor mínimo
    }

    i8SeleccionGalvMicro=giPosRulancha;              // Galvanica (0), Microcorrientes (1), Galvanica + Microcorrientes (2)

    bSeleccionGalvanica=0;
    if(i8SeleccionGalvMicro==SEL_GALV_MICRO){
        bSeleccionGalvanica=1;
    }

    // if(i8SeleccionGalvMicro==SEL_GALVANICA){                     // Galvanica
    //     // bSoloMicrocorrientes=0;
    //     // bSeleccionGalvanica=0;
    //     // i16Tmicro=0;
    //     // i16Imicro=0;
    // }else if(i8SeleccionGalvMicro==SEL_MICRO){               // Microcorrientes
    //     // bSoloMicrocorrientes=1;
    //     // bSeleccionGalvanica=1;                       
    //     // i16TGalv[bSeleccionGalvanica]=0;
    //     // i8TrampaGalv[bSeleccionGalvanica]=0;
    //     // i16IGalv[bSeleccionGalvanica]=0;
    //     // i16Tmicro=5;                                    // Added: 08/02/2022 Para que el tiempo se inicialice a 5 segundos
    //     // i16Imicro=MINIMA_CORRIENTE_MICROCORRIENTES;     // Added: 08/02/2022 Para que la corriente se inicialice a 100uA
    // }else if(i8SeleccionGalvMicro==SEL_GALV_MICRO){
    //     // bSoloMicrocorrientes=0;
    //     // bSeleccionGalvanica=1;                  // Added: 03/02/2022 Para que se actualicen los parámetros al entrar en este modo
    // }
}

/*
*   Función: submenu_41 Added 05/04/2022
*   Descripción: Selección del canal de electroestimulación
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_41(){

    if(iMenuAnterior!=40){
        giPosRulancha=i8ConfigCanal;
    }

    // if(i8CanalesActivados&CHA_ACT){
    //     if(giPosRulancha==CHA_C){
    //         giPosRulancha=CHB_C;
    //     }
    // }

    // if(i8CanalesActivados&CHB_ACT){
    //     if(giPosRulancha==CHB_C){
    //         giPosRulancha=CHC_C;
    //     }
    // }

    // if(i8CanalesActivados&CHC_ACT){
    //     if(giPosRulancha==CHC_C){
    //         giPosRulancha=CHA_C;
    //     }
    // }

    if(i8CanalesActivados&CHA_ACT){
        if(giPosRulancha==CHA_C){
            giPosRulancha=CHB_C;
        }
        if(i8CanalesActivados&CHB_ACT){
            if(giPosRulancha==CHB_C){
                giPosRulancha=CHC_C;
            }
        }
    }

    if(i8CanalesActivados&CHB_ACT){
        if(giPosRulancha==CHB_C){
            if(giPosRulancha>i8ConfigCanal){
                giPosRulancha=CHC_C;
            }
            if(giPosRulancha<i8ConfigCanal){
                giPosRulancha=CHA_C;
            }
        }
    }

    if(i8CanalesActivados&CHC_ACT){
        if(giPosRulancha==CHC_C){
            giPosRulancha=CHB_C;
        }
        if(i8CanalesActivados&CHB_ACT){
            if(giPosRulancha==CHB_C){
                giPosRulancha=CHA_C;
            }
        }
    }

    // if(giPosRulancha>POINTER_C){                             // Si ha llegado al valor máximo
    //     giPosRulancha=CHA_C;                             // Asigna valor máximo
    // }

    // if(giPosRulancha>i8ConfigCanal){
    //     if(giPosRulancha==POINTER_C){                             // Si ha llegado al valor máximo
    //         giPosRulancha=POINTER_C;                             // Asigna valor máximo
    //     }
    // }
    
    if(giPosRulancha>POINTER_C){                             // Si ha llegado al valor máximo
        giPosRulancha=POINTER_C;                             // Asigna valor máximo
    }



    // if(giPosRulancha>POINTER_C && (i8CanalesActivados&CHA_ACT || i8CanalesActivados&CHB_ACT || i8CanalesActivados&CHC_ACT)){                             // Si ha llegado al valor máximo
    //     giPosRulancha=CHA_C;                             // Asigna valor máximo
    // }else{
    //     giPosRulancha=CHC_C;
    // }
    
    // if(giPosRulancha<=0){                           // Si ha llegado al valor mínimo
    //     giPosRulancha=3;                             // Asigna valor mínimo
    // }

    // Esta condición se utiliza porque el canal A y el pointer comparten canal, entonces no pueden ejecutarse simultáneamente
    if((i8CanalesActivados&CHA_ACT) && giPosRulancha==POINTER_C){       // Si el canal A se encuentra activado y se intenta entrar al pointer
        giPosRulancha=CHC_C;                                            // Salta al canal C
    }
    
    if((i8CanalesActivados&POINTER_ACT) && giPosRulancha==CHA_C){       // Si el pointer se encuentra activado y se intenta entrar al canal A
        giPosRulancha=CHB_C;                                            // Salta al canal B
    }

    switch(giPosRulancha){                                          // Dependiendo del canal seleccionado
            case CHA_C:                                                 // Canal A
                bPointerSeleccionado=0;                             // Desactiva la seleccion del pointer
                break;
            case CHB_C:                                                 // Canal B  
                break;
            case CHC_C:                                                 // Canal C
                break;
            case POINTER_C:
                bPointerSeleccionado=1;                             // Activa la seleccion del pointer
                i8SimetriaCanales=0;                                // En el caso de seleeccionar pointer, debemos de eliminar la opción de simetria entre canales por si estuviera activada, 0 == NO_SIMETRIA...DEPRECATED?
                break;
        }

    i8ConfigCanal=giPosRulancha;              
}

/*
*   Función: submenu_49 Added 06/04/2022
*   Descripción: Selección del tipo de modulación
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_49(){

    if(giPosRulancha<=MOD_NOT){
        giPosRulancha=MOD_NOT;
    }

    if(giPosRulancha>=MOD_FM_PWM){
        giPosRulancha=MOD_FM_PWM;
    }

    if(i8CanalesActivados!=0){
        if(giPosRulancha>=MOD_NOT){
            giPosRulancha=MOD_NOT;
        }
    }

    i8SeleccionMod=giPosRulancha;
}

/*
*   Función: submenu_491 Added 07/04/2022
*   Descripción: Ajuste de porcentaje de modulación AM
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_491(){

    // if(i8SeleccionMod==MOD_FAA){
    //     if(giPosRulancha<=MINIMO_AMPLITUD_ALTERNA){
    //         giPosRulancha=MINIMO_AMPLITUD_ALTERNA;
    //     }
    // }else{
    //     if(giPosRulancha<=MINIMO_AMPLITUD_BARRIDO){
    //         giPosRulancha=MINIMO_AMPLITUD_BARRIDO;
    //     }
    // }

    if(giPosRulancha<=min_Imod){
        giPosRulancha=min_Imod;
    }

    if(giPosRulancha>=max_Imod){
        giPosRulancha=max_Imod;
    }
    if(giPosRulancha>=i16IElec[i8ConfigCanal]/2){
        giPosRulancha=i16IElec[i8ConfigCanal]/2;
    }

    i8ModulacionAM=giPosRulancha;
}

/*
*   Función: submenu_11 NEW
*   Descripción: Ajuste del nivel de iluminacion con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_11(){

    if(iMenuAnterior!=10){                                          // Si el menu anterior es distinto de configuracion
        giPosRulancha=i8nivel_ilum;                                 // Asigna el nivel de iluminacion a giPosRulancha
    }

    // min=MIN_ILUMINACION;                                            // Asigna el minimo de iluminacion a la variable min
    // max=MAX_ILUMINACION;                                            // Asigna el maximo de iluminacion a la variable max

    if(giPosRulancha>MAX_ILUMINACION){                                          // Si el valor obtenido es superior al máximo
        giPosRulancha=MAX_ILUMINACION;                                          // Asigna valor máximo
    }
    
    if (giPosRulancha<=MIN_ILUMINACION){                                        // Si el valor obtenido es inferior al mínimo
        giPosRulancha=MIN_ILUMINACION;                                          // Asigna valor mínimo
    }

    i8nivel_ilum=giPosRulancha;                                     // Asigna valor de giPosRulancha al nivel de iluminacion
    set_pwm8_duty((int16)i8nivel_ilum*10);                          // Setea el duty del PWM de iluminacion
    
    writeEEPROM_8bits(EEPROM_LOC_ILUMINACION,i8nivel_ilum);         // Guarda en EEPROM el valor de iluminacion
}

/*
*   Función: submenu_14 NEW: Added 2/01/2022
*   Descripción: Ajuste del nivel de contraste con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_14(){

    // if(iMenuAnterior!=10){                                          // Si el menu anterior es distinto de configuracion
    //     giPosRulancha=i8NivelContraste;                             // Asigna el nivel de contraste a giPosRulancha
    // }

    // min=MIN_CONTRASTE;                                              // Asigna el minimo de contraste a la variable min
    // max=MAX_CONTRASTE;                                              // Asigna el maximo de contraste a la variable max

    if(giPosRulancha>MAX_CONTRASTE){                                          // Si el valor obtenido es superior al máximo
        giPosRulancha=MAX_CONTRASTE;                                          // Asigna valor máximo
    }
    
    if (giPosRulancha<=MIN_CONTRASTE){                                        // Si el valor obtenido es inferior al mínimo
        giPosRulancha=MIN_CONTRASTE;                                          // Asigna valor mínimo
    }

    i8NivelContraste=giPosRulancha;                                 // Asigna valor de giPosRulancha al nivel de contraste
    ST7529_send(COMMAND,VOLCTRL);                                   // Ajuste contraste
    ST7529_send(DATA,i8NivelContraste*0.63);                        // Vop=18V - DS: 7.10.2 pg. 32   1C
    ST7529_send(DATA,0x04);
    
    writeEEPROM_8bits(EEPROM_LOC_CONTRASTE,i8NivelContraste);       // Guarda en EEPROM el valor de contraste
}

/*
*   Función: submenu_12 NEW: Added 2/01/2022
*   Descripción: Ajuste del nivel de senal acustica con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_12(){

    // if(iMenuAnterior!=10){                                              // Si el menu anterior es distinto de configuracion
    //     giPosRulancha=i16nivel_son;                                     // Asigna el nivel de senyal acustica a giPosRulancha
    // }

    // min=MIN_VOLUMEN;                                                    // Asigna el minimo de sonido a la variable min
    // max=MAX_VOLUMEN;                                                    // Asigna el maximo de sonido a la variable max

    if(giPosRulancha>MAX_VOLUMEN){                                              // Si el valor obtenido es superior al máximo
        giPosRulancha=MAX_VOLUMEN;                                              // Asigna valor máximo
    }
    
    if (giPosRulancha<=MIN_VOLUMEN){                                            // Si el valor obtenido es inferior al mínimo
        giPosRulancha=MIN_VOLUMEN;                                              // Asigna valor mínimo
    }

    i16nivel_son=giPosRulancha;                                         // Asigna valor de giPosRulancha al nivel de sonido
    if (giPosRulancha==0){                                              // Si se apaga el pito...
            setup_ccp7(CCP_OFF);                                        // Apaga modulador
            output_high(PWM_PITO);                                      // Nivel alto pito
        }else{                                                          // ...si no esta apagado
            setup_ccp7(CCP_PWM|CCP_SHUTDOWN_AC_L|CCP_SHUTDOWN_BD_L);    // Modulador para senyal acustica
            set_pwm7_duty((int16)((i16nivel_son*4.5)));                 // Carga duty de trabajo [0..450]
        }
        
    writeEEPROM_16bits(EEPROM_LOC_SONIDO,i16nivel_son);                 // Guarda en EEPROM el nivel de sonido
}

/*
*   Función: submenu_15 NEW: Added 2/01/2022
*   Descripción: Ajuste del idioma con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_15(){

    giPosRulancha%=NUM_IDIOMAS;                             // Modulo para que no pase de NUM_IDIOMAS máximo

    switch(giPosRulancha){                                  // Dependiendo del idioma elegido
        case SPANISH:                                       // Seleccion espanyol
            i8RepVal1=sIDIOMA_ESPANOL;                      // Asigna idioma
            i32OffsetDireccionIdioma=OFFSET_DIR_SPANISH;    // Asigna offset memoria
            break;
        case ENGLISH:                                       // Seleccion inglés
            i8RepVal1=sIDIOMA_INGLES;                       // Asigna idioma
            i32OffsetDireccionIdioma=OFFSET_DIR_ENGLISH;    // Asigna offset memoria
            break;
    }

    if(i8SelIdioma!=giPosRulancha){                         // Si ha habido un cambio de idioma
        i8SelIdioma=giPosRulancha;                          // Asigna valor de giPosRulancha al idioma
    }

    writeEEPROM_8bits(EEPROM_LOC_IDIOMA,i8SelIdioma);       // Guarda en EEPROM la seleccion del idioma
}

/*
*   Función: submenu_90 NEW: Added 12/05/2022
*   Descripción: Seleccion de terapia de presets
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_90(){
    if(iMenuAnterior!=90){                                            
        giPosRulancha=i8SeleccionTerapia;                             
    }

    if(giPosRulancha>3){                                              // Si el valor obtenido es superior al máximo
        giPosRulancha=3;                                              // Asigna valor máximo
    }
    
    if (giPosRulancha<=0){                                            // Si el valor obtenido es inferior al mínimo
        giPosRulancha=0;                                              // Asigna valor mínimo
    }

    i8SeleccionTerapia=giPosRulancha;
}
