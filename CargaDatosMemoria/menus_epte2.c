/*
*   File: menus_epte2.c
*   
*   Descripci�n: Program file del sistema de men�s del equipo
*   
*   Proyecto: EPTE 2
*   Versi�n: 3.0
*
*   Ionclinics & Deionics SL
*/

#include "menus_epte2.h"

// Pantalla de seleccion 
void pantalla_seleccion(){         

    if(bBateriaBaja){                               // Si el nivel d ebateria es bajo
        if(bParpadeoBateria){                       // Indica parpadeando el valor restante de bateria
            ST7529_printf("     ",69,4,S_,NORMAL);  // Limpia el valor de bateria en pantalla
        }else{
            sprintf(mystring,"%3u %%",i8Bat);       // Muestra el valor de bateria en pantalla
            ST7529_printf(mystring,69,4,S_,NORMAL); // Representa en pantalla
        }
    }else{                                          // Si no hay bateria baja
        sprintf(mystring,"%3u %%",i8Bat);           // Pone el valor de bateria restante
        ST7529_printf(mystring,69,4,S_,NORMAL);     // Muestra por pantalla
    }
    
    // Para mantener un formato de representaci�n del nivel de bateria de forma correcta, 
    // se ajusta para cuando son uno, dos o tres digitos para mostrar
    if(i8Bat>=10){                                  // Dos o tres digitos
        if(i8Bat>=100){                             // Tres digitos
            i8PosVol=POS_VOL_TRES;                  // Muestro 3
        }else{                                      // Dos digitos
            i8PosVol=POS_VOL_DOS;                   // Muestro 2
        }
    }else{                                          // Un d�gito
        i8PosVol=POS_VOL_UNO;                       // Muestro 1
    }
    
    if(i16nivel_son==0){                            // Si el sonido est� deshabilitado
        ST7529_putIcon(ICON_SON_NONE,i8PosVol,0);   // Muestro por pantalla el altavoz sin sonido
    }else if(i16nivel_son<50){                      // Si el sonido est� configurado a un valor inferior al 50%
        ST7529_putIcon(ICON_SON_MED,i8PosVol,0);    // Muestro el altavoz a mitad de sonido
    }else{                                          // Si el sonido est� configurado a un valor superior o igual al 50%
        ST7529_putIcon(ICON_SON_FULL,i8PosVol,0);   // Muestro el altavoz a full de sonido
    }
    
    if(iMenuActual<100){                            // Si estamos en un men� de configuraci�n
        if(iMenuActual==0){                         // Si estamos en el menu principal
            quitar_flecha_izq();                     // Quito la flecha izquierda (atras)
        }else{                                      // Si no estamos en el men� principal
            poner_flecha_izq();                     // Pongo la flecha izquierda (atras) normal (habilitada)
        }
    
        if(iMenuActual==42 && i8CanalesElec==CANALES_ABC){  // Si estamos en el men� de selecci�n de simetria de canales y estan los tres activos... (REVISAR ESTO)
            poner_config();                         // Pongo el s�mbolo de configuraci�n
        }else if(iMenuActual>=11 && iMenuActual<=15){   // Si estoy en los men�s de configuraci�n
            quitar_flecha_der();                    // Quito flecha derecha
        }else{                                      // Si no...
            poner_flecha_der();                     // Pongo flecha derecha
        }             
    }else{                                          // Si est� en un men� de tratamiento
        if(iMenuActual!=121 && iMenuActual!=123){   // Si estamos en un men� distinto a galv�nica (en tratamiento o error de electrodo)
            poner_flecha_izq();                     // Ponemos la flecha izquierda en pantalla
        }
    
        if(iMenuActual!=120 && iMenuActual!=121 && iMenuActual!=123 && iMenuActual!=140 && iMenuActual!=141 && iMenuActual!=142 && iMenuActual!=143){   // Mientras no estemos en un men� de tratamiento de galv�nica o electroestimulaci�n
            poner_config();                         // Ponemos el s�mbolo de configuraci�n
        }
        if(iMenuActual==140 || iMenuActual==141 || iMenuActual==142 || iMenuActual==143){   // Si estamos en cualquier menu de tratamiento de electroestimulaci�n
            poner_flecha_der();                     // Ponemos la felcha derecha en el men�
        }
    }   
}

// Minifunciones

void poner_flecha_izq(){
    ST7529_putIcon(ICON_LEFT,74,20);
}

void quitar_flecha_izq(){
    ST7529_putIcon(ICON_NONE,74,20);
}

void poner_flecha_der(){
    ST7529_putIcon(ICON_RIGHT,74,90); 
}

void quitar_flecha_der(){
    ST7529_putIcon(ICON_NONE,74,90); 
}

void poner_cancelar(){
    ST7529_putIcon(ICON_CANCEL,74,20);
}

void quitar_cancelar(){
    ST7529_putIcon(ICON_NONE,74,20);
}

void poner_config(){
    ST7529_putIcon(ICON_CONFIG,74,90);
}

void quitar_config(){
    ST7529_putIcon(ICON_NONE,74,90);
}

void poner_guardar(){
    ST7529_putIcon(ICON_ALMACEN,74,90);
}

void quitar_guardar(){
    ST7529_putIcon(ICON_NONE,74,90);
}

void poner_cargar(){
    ST7529_putIcon(ICON_CARGAR,74,90);
}

void quitar_cargar(){
    ST7529_putIcon(ICON_NONE,74,90);
}

void representacionPresets(){
    
    ST7529_printf(sPreset1,COLUMNA_1,FILA_INIT_PRESETS,S_,giPos==0);                                // Presets
    ST7529_printf(i8RegistroPresets[0]+sPresetVacio,COLUMNA_2,FILA_INIT_PRESETS,S_,giPos==0);       // Presets

    ST7529_printf(sPreset2,COLUMNA_1,FILA_1_PRESETS,S_,giPos==1);                                   // Presets
    ST7529_printf(i8RegistroPresets[1]+sPresetVacio,COLUMNA_2,FILA_1_PRESETS,S_,giPos==1);          // Presets

    ST7529_printf(sPreset3,COLUMNA_1,FILA_2_PRESETS,S_,giPos==2);                                   // Presets
    ST7529_printf(i8RegistroPresets[2]+sPresetVacio,COLUMNA_2,FILA_2_PRESETS,S_,giPos==2);          // Presets

    ST7529_printf(sPreset4,COLUMNA_1,FILA_3_PRESETS,S_,giPos==3);                                   // Presets
    ST7529_printf(i8RegistroPresets[3]+sPresetVacio,COLUMNA_2,FILA_3_PRESETS,S_,giPos==3);          // Presets

    ST7529_printf(sPreset5,COLUMNA_1,FILA_4_PRESETS,S_,giPos==4);                                   // Presets
    ST7529_printf(i8RegistroPresets[4]+sPresetVacio,COLUMNA_2,FILA_4_PRESETS,S_,giPos==4);          // Presets

    ST7529_printf(sPreset6,COLUMNA_1,FILA_5_PRESETS,S_,giPos==5);                                   // Presets
    ST7529_printf(i8RegistroPresets[5]+sPresetVacio,COLUMNA_2,FILA_5_PRESETS,S_,giPos==5);          // Presets

    ST7529_printf(sPreset7,COLUMNA_1,FILA_6_PRESETS,S_,giPos==6);                                   // Presets
    ST7529_printf(i8RegistroPresets[6]+sPresetVacio,COLUMNA_2,FILA_6_PRESETS,S_,giPos==6);          // Presets

    ST7529_printf(sPreset8,COLUMNA_1,FILA_7_PRESETS,S_,giPos==7);                                   // Presets
    ST7529_printf(i8RegistroPresets[7]+sPresetVacio,COLUMNA_2,FILA_7_PRESETS,S_,giPos==7);          // Presets

    ST7529_printf(sPreset9,COLUMNA_1,FILA_8_PRESETS,S_,giPos==8);                                   // Presets
    ST7529_printf(i8RegistroPresets[8]+sPresetVacio,COLUMNA_2,FILA_8_PRESETS,S_,giPos==8);          // Presets

    ST7529_printf(sPreset10,COLUMNA_1,FILA_9_PRESETS,S_,giPos==9);                                  // Presets
    ST7529_printf(i8RegistroPresets[9]+sPresetVacio,COLUMNA_2,FILA_9_PRESETS,S_,giPos==9);          // Presets
}

// Menu principal
int8 menu_0(){                          

    if(bRefrescoPantalla){                              // Si debo refrescar la pantalla
        if(iMenuAnterior!=0 || bAlMenuPrincipal){       // Si el men� anterior no es el men� principal o me indica que tengo que ir al men� principal
            bAlMenuPrincipal=0;                         // Inicializo flag men� principal
            ST7529_clear();                             // Limpio pantalla
            ST7529_printf(sMENU_PRINCIPAL,0,0,L_,NORMAL);   // Muestra texto men� principal
            i8CanalesConfigurados=0;                    // Inicializa variable de canales configurados
            i8ConfigCanal=0;                            // Inicializa variable del canal a configurar
            bPointerSeleccionado=0;                     // Inicializa selecci�n de pointer
            if(iMenuAnterior==180){                     // Si el men� anterior era el de SMP
                i16ISMP=2;                              // Inicializo corriente al m�nimo 2*100 = 200u
                i8PulsosSMP=1;                          // Inicializo pulsos al m�nimo
            }
            i8VariablesPreset=0;                        // Inicializo la variable que indica que debo de guardar en preset
        }
        
        pantalla_seleccion();                           // Muestra iconos de selecci�n
        
        if(giPos<=0){                                   // Si el valor de selecci�n es menor o igual a 0
            giPos=0;                                    // Inicializo giPos
        }
        
        if(giPos>7){                                    // Si el valor de selecci�n es mayor que 5
            giPos=7;                                    // Inicializo giPos al m�ximo
        }
        
        // Saltos en men� - DBUG
        /*if(bAscendente){
            if(giPos==6){
                giPos=5;    
            }else if(giPos==3){
                giPos=2;
            }
        }else{
            if(giPos==6){
                giPos=7;    
            }else if(giPos==3){
                giPos=4;
            }
        }*/
        // END saltos men� DEBUG

        ST7529_printf(sMENU_CONFIG,COLUMNA_1,FILA_INIT_MENU,S_,giPos==0);           // Muestro men� Configuraci�n
        ST7529_printf(sMENU_GALV,COLUMNA_1,FILA_1_MENU,S_,giPos==1);                // Muestro men� Galv�nica
        ST7529_printf(sMENU_GALVMICRO,COLUMNA_1,FILA_2_MENU,S_,giPos==2);           // Muestro men� Galv�nica + Micro
        ST7529_printf(sMENU_TRANSCRANEAL,COLUMNA_1,FILA_3_MENU,S_,giPos==3); // Muestro men� Transcraneal
        ST7529_printf(sMENU_ELECTRO,COLUMNA_1,FILA_4_MENU,S_,giPos==4);             // Muestro men� Electroestimulaci�n
        ST7529_printf(sMENU_SMP,COLUMNA_1,FILA_5_MENU,S_,giPos==5);                 // Muestro men� SMP
        ST7529_printf(sMENU_PRESETS,COLUMNA_1,FILA_6_MENU,S_,giPos==6);      // Muestro men� Presets
        ST7529_printf(sMENU_TEST,COLUMNA_1+1,FILA_7_MENU,S_,giPos==7);                // Muestro men� Test
    
        iMenuAnterior=iMenuActual;                      // Inicializo men� anterior
    }
    
    bRefrescoPantalla=0;                                // Inicializo el refresco de pantalla
    
    return 0;                                           // Retorna 0
}

// Confiuraci�n dispositivo 
int8 menu_10(){   

    if(iMenuAnterior!=10){                              // Si venimos de un men� distinto de este
        ST7529_clear();                                 // Limpiamos pantalla
        ST7529_printf(sCONFIG,0,0,L_,NORMAL);           // Ponemos el texto de Configuracion
    } 
    
    if(bRefrescoPantalla){                              // Si debo de refrescar los valores
        pantalla_seleccion();                           // Muestro iconos de seleccion
           
        if(giPos>=5){                                   // Si la selecci�n es mayor o igual a 5 
            giPos=4;                                    // Inicializo a 4
        }
           
        ST7529_printf(sCONFIG_ILUM,6,FILA_INIT,S_,giPos==0);    // Muestra texto configuraci�n iluminaci�n
        ST7529_printf(sCONFIG_CONT,6,FILA_1,S_,giPos==1);       // Muestra texto configuraci�n contraste       
        ST7529_printf(sCONFIG_PITO,6,FILA_2,S_,giPos==2);       // Muestra texto configuraci�n pito
        ST7529_printf(sCONFIG_IDIO,6,FILA_3,S_,giPos==3);       // Muestra texto configuraci�n idioma
        ST7529_printf(sCONFIG_VERS,6,FILA_4,S_,giPos==4);       // Muestra texto configuraci�n versi�n HW/FW

        iMenuAnterior=iMenuActual;                      // Inicializo el valor del menu anterior
    }
            
    bRefrescoPantalla=0;                                // Limpio flag refresco de pantalla

    return 0;                                           // Return 0
}

int8 menu_20(){   // Galvanica + microcorrientes

    if(bRefrescoPantalla){                          // Si se ha cambiado alg�n valor
        if(iMenuAnterior!=20){                      // Si venimos de otro men�
            gF=1;                                   // Pongo a uno para inicializar la parte de frecuencias con la rulancha
            ST7529_clear();                         // Limpio pantalla
            if(bSeleccionGalvanica){                // Si se ha seleccionado galv�nica y microcorrientes
                ST7529_printf(sGALVANICA_MICRO,0,0,L_,NORMAL);  // Muestra este titulo
                i8VariablesPreset=PRESET_GALVMICRO;                        // Preset Galv+Micro
            }else{                                  // Si no
                ST7529_printf(sGALV,0,0,L_,NORMAL); // Muestra solo t�tulo de galv�nica
                i8VariablesPreset=PRESET_GALV;                        // Preset Galv
            }
            i32CGalv=calc_CargaGalv(i16IGalv[bSeleccionGalvanica]);      // Muestra el valor de carga el�ctrica por pantalla con los valores que dispone
        }
        
        if(iMenuAnterior==120){                     // Si veniamos de configurar el tratamiento o tras finalizar/parar un tratamiento
            bEmpiezaContadorTiempo=0;               // Inicializo contador de tiempo                                                       
            bValorAlcanzado[GALVANICA_C]=0;         // Inicializo valor alcanzado de corriente galv�nica                    
            bDescuentaCargaRampa=0;                 // Inicializo valor de descuento de carga en rampa            
            bTerapia=0;                             // Inicializo variable galv/micro en tratamiento
            bTratamientoGalvanicaActivado=0;        // Inicializo tratamiento activo                        
            bMicrocorrientesEncendido=0;            // Inicializo indicador de tratamiento                    
            i32CargaGalvanicaRestante=0;            // Inicializo valor carga restante (NECESARIO AHORA??)                    
            if(i16TGalv[bSeleccionGalvanica]==0){
                i16TimeRaw[0]=0;
            }else{
                i16TimeRaw[0]=i16TGalv[bSeleccionGalvanica]+i8TrampaGalv[bSeleccionGalvanica];                // Inicializo variables de tiempo 
            }                           
            bPausaTratamiento=0;                    // Inicializo pausa            
            giPosRulancha=i16IGalv[bSeleccionGalvanica];                 // Inicializo rulancha            
        }
       
        pantalla_seleccion();                       // Muestro iconos
    
        if(!bSeleccionGalvanica){                   // Si estamos en men� de galv�nica solo
    
            if(giPos==4){                           // Descendente, si es igual a 4
                giPos=9;                            // Salta al 9 (Config. tratamiento)
            }
            
            if(giPos==8){                           // Ascendente, si es igual a 8
                giPos=3;                            // Salta a 3, (Config. rampa)
            }
        }
        
        if(giPos>=11){                              // Si es mayor o igual que 10
            giPos=10;                                // Inicializo a 9
        }
        if(giPos<=1){                               // Si es menor o igual a 1
            giPos=1;                                // Inicializo a 1
        }
    
       
        sprintf(mystring,"Q=%6lu[C",(int32)i32CGalv+i16CRampaGalv);                 // Muestra carga
        ST7529_printfg(mystring,COLUMNA_1,FILA_INIT,M_,ai8EscalaGrises[1],0);       // Por pantalla
       
        sprintf(mystring,"I=%5lu[A",i16IGalv[bSeleccionGalvanica]*50);                                   // Muestra corriente seleccionada
        ST7529_printf(mystring,COLUMNA_2,FILA_INIT,M_,giPos==1);                    // Por pantallla
       
        if(bSeleccionGalvanica){                    // Si estamos en galv + micro 
            if(i16TGalv[bSeleccionGalvanica]==0){                        // Si ponemos tiempo de galv a 0 (infinito no permitido en galc + micro)
                i16TGalv[bSeleccionGalvanica]=1;                         // Inicializa a 1
            }
        }
        
        Calc_representacion_t(i16TGalv[bSeleccionGalvanica],0);          // Calculo representaci�n de tiempo

        if(i16TGalv[bSeleccionGalvanica]==0){                            // Si el tiempo es 0 (ilimitado)
            ST7529_printf(sTIEMPO_ACTIVO_ILIMITADO,COLUMNA_1,FILA_1,M_,giPos==2);   // Por pantalla
        }else{                                      // Si hay un tiempo definido
            sprintf(mystring,"Ta=%2u:%02u s",i8Tmin,i8Tseg);    // Muestro el tiempo en pantalla
            ST7529_printf(mystring,COLUMNA_1,FILA_1,M_,giPos==2);   // Por pantalla
        }
       
        sprintf(mystring,"Tr=%2u s",i8TrampaGalv[bSeleccionGalvanica]);              // Muestro el tiemp ode rampa
        ST7529_printf(mystring,COLUMNA_2,FILA_1,M_,giPos==3);   // Por pantalla
       
        if(bSeleccionGalvanica){                    // Si estamos en modo galv+micro
            ST7529_printf(sGALV,5+ (COLUMNA_1+COLUMNA_2)/2,FILA_INIT-SALTO_FILA,S_,0);  // Muestra t�tulo galv�nica
            ST7529_printf(sMICRO_CORRIENTES,(COLUMNA_1+COLUMNA_2)/2,FILA_2,S_,0);   // Mostramos el titulo de Microcorrinetes
        
            sprintf(mystring,"I=%4lu[A",i16Imicro*50);                      // Muestra corriente seleccionada
            ST7529_printf(mystring,COLUMNA_1,FILA_3,M_,giPos==4);           // Por pantalla
           
            Calc_representacion_t(i16Tmicro,0);                             // Calcula representaci�n de tiempo
            sprintf(mystring,"Ta=%2u:%02u s",i8Tmin,i8Tseg);                // Muestra tiempo de tratamiento de microcorrientes
            ST7529_printf(mystring,COLUMNA_2,FILA_3,M_,giPos==5);           // Por pantalla

            if(bPolaridadMicro){                        // Si es bipolar
                i8RepVal1=sBIPOLAR;                     // Muestro texto bipolar
            }else{                                      // Si es monopolar
                i8RepVal1=sMONOPOLAR;                   // Muestro ttexto monopolar
            }
           
            ST7529_printf(i8RepVal1,COLUMNA_1,FILA_4,M_,giPos==6);      // Por pantalla
          
            sprintf(mystring,"PW=%4lu [s",i16PWmicro);                  // Muestra ancho del pulso
            ST7529_printf(mystring,COLUMNA_2,FILA_4,M_,giPos==7);       // Por pantalla
        
            sprintf(mystring,"F=%4luHz",i16frecmicro);                  // Muestra frecuencia
            ST7529_printf(mystring,COLUMNA_1,FILA_5,M_,giPos==8);       // Por pantalla
            
            ST7529_printf(sGUARDAR_PRESET,COLUMNA_2,FILA_5,M_,giPos==9); 
        }else{
            ST7529_printf(sGUARDAR_PRESET,COLUMNA_1,FILA_3,M_,giPos==9);           // Muetsra por pantalla la corriente
        }
     
        ST7529_printf(sCONFIG_TRAT,COLUMNA_1,FILA_RELISTO,M_,giPos==10); // Muestra texto de acceso al tratamiento
        iMenuAnterior=iMenuActual;
    }
    
    bRefrescoPantalla=0;                // Inicializo flag de refresco

    return 0;                           // Return 0
}

// Configuraci�n Transcraneal
int8 menu_30(){
    if(bRefrescoPantalla){                          // Si se ha cambiado alg�n valor
        if(iMenuAnterior!=30){                      // Si venimos de otro men�
            ST7529_clear();                         // Limpio pantalla
            ST7529_printf(sTRANS,0,0,L_,NORMAL);  // Muestra este titulo
            //ST7529_printf("TO-DO",30,30,L_,NORMAL);  // Muestra este texto
            i32CTrans=calc_CargaGalv(i16Itrans);      // Muestra el valor de carga el�ctrica por pantalla con los valores que dispone
            i8VariablesPreset=PRESET_TRANSCRANEAL;                        // Preset Trans
        }
        pantalla_seleccion();                       // Muestro iconos
    
        if(iMenuAnterior==130){                     // Si veniamos de configurar el tratamiento o tras finalizar/parar un tratamiento
            bEmpiezaContadorTiempo=0;               // Inicializo contador de tiempo                                                       
            bValorAlcanzado[GALVANICA_C]=0;         // Inicializo valor alcanzado de corriente galv�nica                    
            bDescuentaCargaRampa=0;                 // Inicializo valor de descuento de carga en rampa            
            bTratamientoTranscranealActivado=0;     // Inicializo tratamiento activo                        
            bMicrocorrientesEncendido=0;            // Inicializo indicador de tratamiento                    
            
            if(i16Ttrans==0){                       // Necesario?
                i16TimeRaw[0]=0;
            }else{
                i16TimeRaw[0]=i16Ttrans+i8TrampaTrans;                // Inicializo variables de tiempo 
            }                           
            bPausaTratamiento=0;                    // Inicializo pausa            
            giPosRulancha=i16IGalv[bSeleccionGalvanica];                 // Inicializo rulancha            
        }
            
        pantalla_seleccion();                       // Muestro iconos
        
        
        if(giPos==6){                           // Descendente, si es igual a 6
            giPos=9;                            // Salta al 9 
        }
        
        if(giPos==8){                           // Ascendente, si es igual a 8
            giPos=5;                            // Salta a 5
        }
        
        if(giPos>=10){                              // Si es mayor o igual que 10
            giPos=9;                                // Inicializo a 9
        }
        if(giPos<=1){                               // Si es menor o igual a 1
            giPos=1;                                // Inicializo a 1
        }
        
        sprintf(mystring,"Q=%6lu [C",(int32)i32CTrans+i16CRampaTrans);                 // Muestra carga
        ST7529_printfg(mystring,COLUMNA_1,FILA_INIT,M_,ai8EscalaGrises[1],0);       // Por pantalla
        
        sprintf(mystring,"I=%5lu [A",i16ITrans*50);                                   // Muestra corriente seleccionada
        ST7529_printf(mystring,COLUMNA_2,FILA_INIT,M_,giPos==1);                    // Por pantallla
        
        Calc_representacion_t(i16Ttrans,0);          // Calculo representaci�n de tiempo
        
        if(i16Ttrans==0){                            // Si el tiempo es 0 (ilimitado)
            ST7529_printf(sTIEMPO_ACTIVO_ILIMITADO,COLUMNA_1,FILA_1,M_,giPos==2);   // Por pantalla
        }else{                                      // Si hay un tiempo definido
            sprintf(mystring,"Ta=%2u:%02u s",i8Tmin,i8Tseg);    // Muestro el tiempo en pantalla
            ST7529_printf(mystring,COLUMNA_1,FILA_1,M_,giPos==2);   // Por pantalla
        }
        
        sprintf(mystring,"Tr=%2u s",i8TrampaTrans);              // Muestro el tiemp ode rampa
        ST7529_printf(mystring,COLUMNA_2,FILA_1,M_,giPos==3);   // Por pantalla
        
        Calc_representacion_t(i16Tmicro,0);                             // Calcula representaci�n de tiempo
        
        sprintf(mystring,"S=%3u cm]",i8SuperficieElectrodo);                // Muestra tama�o electrodo
        ST7529_printf(mystring,COLUMNA_2,FILA_3,M_,giPos==4);           // Por pantalla
        
        i32DensidadCorriente=(i16ITrans*50)/i8SuperficieElectrodo;
        
        sprintf(mystring,"j=%3lu [A/cm]",i32DensidadCorriente);              // Muestro densidad de carga
        ST7529_printfg(mystring,COLUMNA_1,FILA_3,M_,ai8EscalaGrises[1],0);           // Por pantalla
       
        ST7529_printf(sGUARDAR_PRESET,COLUMNA_1,FILA_4,M_,giPos==5); 
        
        ST7529_printf(sCONFIG_TRAT,COLUMNA_1,FILA_RELISTO,M_,giPos==9); // Muestra texto de acceso al tratamiento
        
        iMenuAnterior=iMenuActual;
    }
        
    bRefrescoPantalla=0;                // Inicializo flag de refresco
    
    return 0;                           // Return 0
}

int8 menu_40(){

    if(bRefrescoPantalla){          // Si ha cambiado alg�n valor
    
        int1 bCondicion=0;          // Variable utilizada conmo condicional de escala de grises en texto
        
        if((iMenuAnterior!=40)||(bborrado==1)){         // Si vengo de otro menu debo borrar la basurilla
            if(iMenuAnterior!=48){                      // Si el men� anterior es distinto al men� de configuraci�n de frecuencia en electroestimulaci�n
                gF=1;                                   // Pongo a uno para inicializar la parte de frecuencias con la rulancha
            }
            ST7529_clear();                             // Limpio pantalla  
            ST7529_printf(sELECTRO_ESTIMULACION,0,0,L_,NORMAL); // Muestro t�tulo de electroestimulaci�n
            i8VariablesPreset=PRESET_ELECTRO;                        // Preset Electro
            bborrado=0;                                 // Inicializo limpieza de pantalla 
            
            Calc_representacion_t(i16TacElec[i8ConfigCanal],i16TdElec[i8ConfigCanal]);      // Calculo representaci�n de tiempo
            if(i8ConfigCanal==POINTER_C && (iMenuAnterior!=47 && iMenuAnterior!=48 && iMenuAnterior!=51)){  // Si estamos en el men� de config. del pointer y no venimos de los men�s de frecuencia, corrinete o PW (menus de config. del pointer)
                i16frecElec[POINTER_C]=10;              // Inicializa el valor de frecuencia a 10 Hz
            }
        }
            
        if(giPos>=14){          // Si giPos es mayor o igual a 14
            giPos=13;           // Inicializo a 13
        }
        
        if(i16IElec[i8ConfigCanal]>=20){    // Si la corriente es superior a 20*50=1000uA 
            i16IElec[i8ConfigCanal]=20;     // Inicializa a 1000uA
        }
        
        if(iMenuAnterior==140 && bPausaTratamiento){        // Si estabamos en el men� de tratamiento y habiamos pausado
            bPausaTratamiento=0;                            // Inicializo pausa
            if(i16IElec[i8ConfigCanal]>=20){                // Si la corriente es superior a 20*50=1000uA 
                i16IElec[i8ConfigCanal]=20;                 // Inicializa a 1000uA
            }
        }
        
        if(iMenuAnterior==43){                              // Si el men� anterior era la configuraci�n del tiempo de tratamiento
            if(i8TrElec[i8ConfigCanal] > i16TacElec[i8ConfigCanal]/3){  // Si el tiempo de rampa es superior a 1/3 del tiempo de tratamiento
                i8TrElec[i8ConfigCanal]=i16TacElec[i8ConfigCanal]/3;    // Asignale 1/3 de tiemp ode tratamiento al tiempo de rampa
            }
            if(i8TrElec[i8ConfigCanal]>=10){        // Si el tiempo de rampa es igual o superior a 10 segundos
                i8TrElec[i8ConfigCanal]=10;         // Inicializa a 10 segundos
            }
        }
        
        
        if(i8ConfigCanal==POINTER_C){               // Seleccion de los menus accesible en configuraci�n del pointer

            if(!bascendente){                       // Si estamos descendiendo en el men�    
                if(giPos>0 && giPos<6){             // Se realizan las siguientes comprobaciones para que el selector
                    giPos=6;                        // se situe sobra las opciones que nosotros deseamos, ya que el pointer
                }else if(giPos>7 && giPos<10){      // dispone de menos pntos de configuraci�n y hemos de ir saltando 
                    giPos=10;                       // las distintas opciones del men�
                }else if(giPos>10 && giPos<13){
                    giPos=13;
                }
            }else{                                  // Si estamos ascendiendo en el men�
                if(giPos>10 && giPos<13){           // Lo mismo que antes
                    giPos=10;
                }else if(giPos>8 && giPos<10){
                    giPos=7;
                }else if(giPos>0 && giPos<6){
                    giPos=0;
                }
            }
             /*       // DEBUG SALTOS MENU PRESET
            if(bAscendente){
                if(giPos==12){
                    giPos=11;
                }
            }else{
                if(giPos==12){
                    giPos=13;
                }
            }*/
            
       // END DEBUG SALTO MENUS PRESET
        }
        
        pantalla_seleccion();                       // Colocamos los emoticonos
       
        switch(i8ConfigCanal){                      // Dependiendo del canal que estemos configurando
            case CHA_C:                             // Canal A
                i8RepVal1=sCANAL_A;                 // Muestra el texto del canal A   
                break;
            case CHB_C:                             // Canal B
                i8RepVal1=sCANAL_B;                 // Muestra el texto del canal B
                break;
            case CHC_C:                             // Canal C
                i8RepVal1=sCANAL_C;                 // Muestra el texto del canal C
                break;
            case POINTER_C:                         // Pointer
                i8RepVal1=sCANAL_POINTER;           // Muestra el texto del pointer
                break;
        }
        ST7529_printf(i8RepVal1,23,18,M_,(giPos==0));           // Muestra por pantalla los t�tulos

        Calc_representacion_t(i16TacElec[i8ConfigCanal],i16TdElec[i8ConfigCanal]);  // Calcula la representaci�n de tiempos
        comprobacionLimitesFrecuencia();            // Comprueba los l��mites de frecuencia entre canales ((fA o fP)<=fB<=fC)
        
        if(POINTER_C != i8ConfigCanal){             // Si no estamos en el menu de configuraci�n del pointer, se configuran los saltos de men�
        
            if(!bPolaridadElec[i8ConfigCanal]){     // Si la se�al es monopolar
                if(!bascendente){                   // Si estamos descendiendo en el men�
                    if(giPos==12){                  // Si estamos en la configuraci�n del preset
                        giPos=13;                   // Salto a relisto...las siguientes condiciones e slo mismo dependiendo de su polaridad y simetria
                    }
                    if(giPos==9){
                        giPos=10;
                    }
                }else{                              // Si estamos ascendiendo en el men�
                    if(giPos==11){                         
                        giPos=10;                          
                    }
                    if(giPos==9){
                        giPos=8;
                    }
                }
            
            }else{                                  // Si la se�al es bipolar
                if(!bascendente){                   // Si estamos descendiendo en el men�
                    if(bSimetriaElec[i8ConfigCanal]){
                        if(giPos==11){          
                            giPos=12;           
                        }
                    }
                }else{                              // Si estamos ascendiendo en el men�
                    if(bSimetriaElec[i8ConfigCanal]){
                        if(giPos==11){          
                            giPos=10;           
                        }
                    }
                }
            }
            
            //if(i8ConfigCanal!=CHA_C){       // Si no estamos configurando el canal A
                if(!bascendente){           // Si estamos bajando en el men�
                    if(giPos==1){           // Si llegamos a la opcion de simetria entre canales
                        giPos=2;            // Debemos de saltar esa opci�n
                    }
                }else{                      // ... si estamos subiendo en le men�
                    if(giPos==1){           // Si llegamos a la opci�n de simetria entre canales
                        giPos=0;            // Debemos de saltar esa opci�n
                    }
                }
            //}
            /*        // DEBUG SALTOS MENU PRESET
            if(bAscendente){
                if(giPos==12){
                    giPos=11;
                }
                if(bSimetriaElec[i8ConfigCanal]){
                    if(giPos==11){          
                        giPos=10;           
                    }
                }
            }else{
                if(giPos==12){
                    giPos=13;
                }
            }
            */
       // END DEBUG SALTO MENUS PRESET
            
            
            // Saltos men� por simetria entre canales
            /*if(!bascendente){                   // Si estamos descendiendo en el men�
                switch(i8SimetriaCanales){      // Dependiendo de la simetria entre canales seleccionada
                    case 1:                     // Canales AB
                        if(CHB_C==i8ConfigCanal){   // Si estamos en el men� del canal B
                            if(giPos>=7){
                                giPos=12;
                            }
                        }
                        break;
                    case 2:                     // Canales ABC
                        if(CHB_C==i8ConfigCanal || CHC_C==i8ConfigCanal){   // Si estamos en el men� del canal B o C
                            if(giPos>=7){
                                giPos=12;
                            }
                        }
                        break;
                }
            }else{                              // Si estamos ascendiendo en el men�
                switch(i8SimetriaCanales){      // Dependiendo de la simetria entre canales seleccionada
                    case 1:                     // Canales AB
                        if(CHB_C==i8ConfigCanal){   // Si estamos en el men� del canal B
                            if(giPos>=6 && giPos<=11){
                                giPos=6;
                            }
                        }
                        break;
                    case 2:                     // Canales ABC
                        if(CHB_C==i8ConfigCanal || CHC_C==i8ConfigCanal){   // Si estamos en el men� del canal B o C
                            if(giPos>=6 && giPos<=11){
                                giPos=6;
                            }
                        }
                        break;
                }
            }
        
            if(i8ConfigCanal==CHA_C){
                switch(i8SimetriaCanales){                  // Dependiendo de la simetria entre canales seleccionada
                    case 0:                                 // Sin simetria entre canales
                        i8RepVal1=sTextoSimetriaCanalesNO;  // Texto sin simetria         
                        break;
                    case 1:                                 // Simetria entre el canal A y B
                        i8RepVal1=sTextoSimetriaCanalesAB;  // Texto con simetria entre canales A y B      
                        break;
                    case 2:                                 // Simetria entre el canal A, B y C
                        i8RepVal1=sTextoSimetriaCanalesABC; // Texto con simetria entre canales A, B y C       
                        break;
                }

                ST7529_printf(i8RepVal1,COLUMNA_1,FILA_INIT,M_,(giPos==1));     // Muestro simetria por pantalla
            }*/
            
            sprintf(mystring,"I=%5lu[A  ",i16IElec[i8ConfigCanal]*50);      // Muestra la corriente configurada para cada canal
            sprintf(mystring1,"F=%4luHz  ",i16frecElec[i8ConfigCanal]);     // Muestra la frecuencia configurada para cada canal
            ST7529_printf(mystring,COLUMNA_1,FILA_2,M_,giPos==6);           // Muetsra por pantalla la corriente
            
            bCondicion=(i8SimetriaCanales==1 && i8ConfigCanal==CHB_C);      // Si se cumple esta condici�n
            bCondicion|=(i8SimetriaCanales==2 && (i8ConfigCanal==CHB_C||i8ConfigCanal==CHC_C)); // de dos lineas
            
            ST7529_printfg(mystring1,COLUMNA_2,FILA_2,M_,ai8EscalaGrises[bCondicion],giPos==7);     // Muestra por pantalla la frecuencia en negrita (modificable) o gris (no modificable)
            
            sprintf(mystring,"Ta=%2u:%02u s",i8Tmin,i8Tseg);                // Muestra tiempo Activo
            ST7529_printf(mystring,COLUMNA_1,FILA_INIT,M_,(giPos==2));         // Por pantalla    
            sprintf(mystring,"Tr=%2u s   ",i8TrElec[i8ConfigCanal]);        // Muestra tiempo Rampa
            ST7529_printf(mystring,COLUMNA_1,FILA_1,M_,(giPos==4));         // Por pantalla
            
            sprintf(mystring,"Td=%2u:%02u s",i8T1min,i8T1seg);              // Muestra tiempo Descanso/Reposo
            ST7529_printf(mystring,COLUMNA_2,FILA_INIT,M_,(giPos==3));         // Por pantallla
            
            bCondicion=(i16TdElec[i8ConfigCanal]==0);       // Si se cumple la condicion de que no hay tiempo de descanso definido
            if(bCondicion){                                 // Si no hay tiempo de descanso
                i8Nrep[i8ConfigCanal]=1;                    // Fijamos el n�mero de repeticiones a uno
                if(!bascendente){                           // Si estamos descendiendo en el men�
                    if(giPos==5){                           // Si estamos en repeticiones
                        giPos=6;                            // Saltamos ese campo ya que no podemos modificarlo
                    }               
                }else{                                      // Si estamos ascendiendo en el men�
                    if(giPos==5){                           // Si estamos en repeticiones
                        giPos=4;                            // Saltamos ese campo ya que no podemos modificarlo
                    }
                }
            }
            sprintf(mystring,"N=%2u      ",i8Nrep[i8ConfigCanal]);              // N�mero de repeticiones
            ST7529_printfg(mystring,COLUMNA_2,FILA_1,M_,ai8EscalaGrises[bCondicion],(giPos==5));    // Por pantalla
            
            if(bPolaridadElec[i8ConfigCanal]){      // Si se trata de una se�al bipolar
                i8RepVal1=sBIPOLAR;                 // Indico bipolar   
                if(i16PW_minusElec[i8ConfigCanal]==0){  // Si el ancho de pulso positivo es igual a cero
                    i16PW_minusElec[i8ConfigCanal]=100; // Inicializamos a 100 (m�nimo)
                }
            }else{                                  // Si se trata de una se�al monopolar
                i8RepVal1=sMONOPOLAR;               // Indico monopolar
                bSimetriaElec[i8ConfigCanal]=0;     // Indico se�al asim�trica
                i16PW_minusElec[i8ConfigCanal]=0;   // Pongo ancho de pulso negativo a 0
            }
            
            bCondicion=(i8SimetriaCanales==1 && i8ConfigCanal==CHB_C);      // Creamos esta condicion
            bCondicion|=(i8SimetriaCanales==2 && (i8ConfigCanal==CHB_C||i8ConfigCanal==CHC_C)); // de dos lineas
            
            ST7529_printfg(i8RepVal1,COLUMNA_1,FILA_3,M_,ai8EscalaGrises[bCondicion],giPos==8);     // Muestra por pantalla la polaridad en negrita (modificable) o en gris (no modificable)

            if(bSimetriaElec[i8ConfigCanal]){                                   // Si la se�al es sim�trica
                i8RepVal1=sSIMETRICA;                                           // Indico simetr�a 
                i16PW_minusElec[i8ConfigCanal]=i16PW_plusElec[i8ConfigCanal];   // Copio valores del PW+ en PW-
            }else{                                                              // Si la se�al es asim�trica
                i8RepVal1=sASIMETRICA;                                          // Indico asimetr�a
            }
            bCondicion=(i8SimetriaCanales==1 && i8ConfigCanal==CHB_C);                          // Se crea
            bCondicion|=(i8SimetriaCanales==2 && (i8ConfigCanal==CHB_C||i8ConfigCanal==CHC_C)); // esta condici�n
            bCondicion|=!(bPolaridadElec[i8ConfigCanal]);                                       // de tres lineas
            ST7529_printfg(i8RepVal1,COLUMNA_2,FILA_3,M_,ai8EscalaGrises[bCondicion],giPos==9); // Muestra por pantalla la simetr�a en negrita (modificable) o en gris (no modificable)

            bCondicion=(i8SimetriaCanales==1 && i8ConfigCanal==CHB_C);                          // Se crea esta condici�n
            bCondicion|=(i8SimetriaCanales==2 && (i8ConfigCanal==CHB_C||i8ConfigCanal==CHC_C)); // de dos lineas
            sprintf(mystring,"PW+=%4lu[s",i16PW_plusElec[i8ConfigCanal]);                       // Muestra el texto del PW+
            ST7529_printfg(mystring,COLUMNA_1,FILA_4,M_,ai8EscalaGrises[bCondicion],giPos==10); // por pantalla en negrita (modificable) o en gris (no modificable)
            
            bCondicion|=(bSimetriaElec[i8ConfigCanal] || !bPolaridadElec[i8ConfigCanal]);       // de dos lineas
            sprintf(mystring,"PW-=%4lu[s",i16PW_minusElec[i8ConfigCanal]);                      // Muestra el texto del PW- 
            ST7529_printfg(mystring,COLUMNA_2,FILA_4,M_,ai8EscalaGrises[bCondicion],giPos==11); // por pantalla en negrita (modificable) o en gris (no modificable) 
            
            ST7529_printf(sGUARDAR_PRESET,COLUMNA_1,FILA_5,M_,giPos==12);           // Muetsra por pantalla la corriente
        }else{                                                              // Si estamos configurando el pointer
            sprintf(mystring,"I=%5lu[A  ",i16IElec[i8ConfigCanal]*50);      // Muestra la corriente configurada para el pointer
            if(iMenuAnterior==140){                                         /// Si venimos del men� de tratamiento
                i16frecElec[i8ConfigCanal]=10;                              // Inicializa el valor de frecuencia
            }
            sprintf(mystring1,"F=%4luHz  ",i16frecElec[i8ConfigCanal]);     // Muestra la frecuencia configurada para el pointer
            ST7529_printf(mystring,COLUMNA_1,FILA_2,M_,giPos==6);           // Muetsra por pantalla la corriente
            ST7529_printf(mystring1,COLUMNA_2,FILA_2,M_,giPos==7);          // Muestra por pantalla la frecuencia
            
            sprintf(mystring,"PW=%4lu[s",i16PW_plusElec[i8ConfigCanal]);    // Muestra el texto del PW
            ST7529_printf(mystring,COLUMNA_1,FILA_3,M_,giPos==10);          // Muestra el texto por pantalla
            
            i16PW_minusElec[i8ConfigCanal]=i16PW_plusElec[i8ConfigCanal];   // Asignamos el ancho de pulso positivo al negativo (Pointer es bipolar sim�trico)
            bPolaridadElec[i8ConfigCanal]=1;                                // Inicializo flag de polaridad (Bipolar)
            bSimetriaElec[i8ConfigCanal]=1;                                 // Inicializo flag de simetria (Sim�trica)
            
            //ST7529_printf(sGUARDAR_PRESET,COLUMNA_2,FILA_3,M_,giPos==12);           // Muetsra por pantalla la corriente
        }
        
        ST7529_printf(sCONFIG_TRAT,COLUMNA_1,FILA_RELISTO,M_,giPos==13);    // Activo bot�n relisto
       
        iMenuAnterior=iMenuActual;                                          // Copia el valor del men� actual a men� anterior
    }
    
    bRefrescoPantalla=0;                            // Inicializo flag de refresco de pantalla

    return 0;                                       // Return 0
}

int8 menu_60(){    // Test 
       
    if(bRefrescoPantalla){
        if(iMenuAnterior!=60){
            ST7529_clear();       
            ST7529_printf(sTEST,0,0,L_,NORMAL);
            write_PCA955X(0x00,0x00,0x02,PCA9554);                            // PCA9554 address=0x02 apagamos todos los leds
        }  
        pantalla_seleccion();

        if (giPos>=15){
            giPos=14;
        }

        ST7529_printf(sTEST_LEDS,COLUMNA_1,20,S_,giPos==0);
        ST7529_printf(sTEST_PITO,COLUMNA_2,20,S_,giPos==1);
        ST7529_printf(sTEST_PULS,COLUMNA_1,30,S_,giPos==2);
        ST7529_printf(sTEST_ILUM,COLUMNA_2,30,S_,giPos==3);
        ST7529_printf(sTEST_ACCE,COLUMNA_1,40,S_,giPos==4);
        ST7529_printf(sTEST_AEXT,COLUMNA_2,40,S_,giPos==5);
        ST7529_printf(sTEST_SCAR,COLUMNA_1,50,S_,giPos==6);
        ST7529_printf(sTEST_DC12,COLUMNA_2,50,S_,giPos==7);
        ST7529_printf(sTEST_DC30,COLUMNA_1,60,S_,giPos==8);
        ST7529_printf(sTEST_RELE,COLUMNA_2,60,S_,giPos==9);
        ST7529_printf(sTEST_BQ34,COLUMNA_1,70,S_,giPos==10);
        ST7529_printf(sTEST_CPIC,COLUMNA_2,70,S_,giPos==11);
        ST7529_printf(sTEST_ECHA,COLUMNA_1,80,S_,giPos==12);
        ST7529_printf(sTEST_ECHB,COLUMNA_2,80,S_,giPos==13);
        ST7529_printf(sTEST_ECHC,COLUMNA_1,90,S_,giPos==14);
       
        iMenuAnterior=iMenuActual;    
    }

    bRefrescoPantalla=0;

    return 0;
}

int8 menu_80(){    // Sistema multipulsos
    if(bRefrescoPantalla){
        if(iMenuAnterior!=80){
            if(iMenuAnterior!=83){
                gF=1;   // Pongo a uno para inicializar la parte de frecuencias con la rulancha
            }
            ST7529_clear();
            ST7529_printf(sSMP,0,0,L_,NORMAL);
            i8VariablesPreset=PRESET_SMP;                        // Preset SMP
            if(iMenuAnterior==180){
                giPosRulancha=i16TacSMP/5;
                giPos=0;
                i16ISMP=2;  // 2*100 = 200u
                i8PulsosSMP=1;
            }
        }  
        
        Calc_representacion_t(i16TacSMP,0); 
        
        pantalla_seleccion();
        
        if (giPos>5){
            giPos=5;
        }
        
        if(giPos<=0){
            giPos=0;
        }
        
        sprintf(mystring,"Ta=%2u:%02u s",i8Tmin,i8Tseg);             // Tiempo Activo
        ST7529_printf(mystring,COLUMNA_1,FILA_2,M_,(giPos==0));     
        
        sprintf(mystring,"Tp=%5lu [s",i32TDesfaseSMP);          // Tiempo Desfase pulsos
        ST7529_printf(mystring,COLUMNA_2,FILA_2,M_,(giPos==1));
        
        sprintf(mystring,"F=%3lu Hz",i16FrecSMP);             // Frecuencia
        ST7529_printf(mystring,COLUMNA_1,FILA_3,M_,(giPos==2));
        
        sprintf(mystring,"PW=%4LU [s",i16PWSMP);              // Ancho de pulso
        ST7529_printf(mystring,COLUMNA_2,FILA_3,M_,(giPos==3));

        ST7529_printf(sGUARDAR_PRESET,COLUMNA_1,FILA_4,M_,giPos==4); 
        
        ST7529_printf(sCONFIG_TRAT,COLUMNA_1,FILA_RELISTO,M_,giPos==5);         // Activo bot�n relisto
            
        
        iMenuAnterior=iMenuActual;    
    }
    
    bRefrescoPantalla=0;

    return 0;
}

// Configuraci�n presets
int8 menu_90(){
    if(bRefrescoPantalla){                          // Si se ha cambiado alg�n valor
        if(iMenuAnterior!=90){                      // Si venimos de otro men�
            ST7529_clear();                         // Limpio pantalla
            ST7529_printf(sPRESETS,0,0,L_,NORMAL);  // Muestra este titulo
        }
        
        pantalla_seleccion();                       // Muestro iconos
        //quitar_flecha_der();
        poner_cargar();
        
        if(giPos<=0){                                   // Si el valor de selecci�n es menor o igual a 0
            giPos=0;                                    // Inicializo giPos
        }
        
        if(giPos>9){                                    // Si el valor de selecci�n es mayor que 5
            giPos=9;                                    // Inicializo giPos al m�ximo
        }

        representacionPresets();
        
        iMenuAnterior=iMenuActual;
    }
    
    bRefrescoPantalla=0;                // Inicializo flag de refresco

    return 0;                           // Return 0
}


// Configuracion Ilumninacion pantalla
int8 menu_11(){ 
    if(bRefrescoPantalla){
        if ((iMenuAnterior!=11)&&(iMenuAnterior!=64)){          // Si no viene de ninguno de los men�s indicados
            ST7529_clear();                                     // Limpio la pantalla   
            ST7529_printf(sTEST_ILUM,0,0,L_,NORMAL);        // Muestro texto 
            giPos=i8nivel_ilum;                                 // Asigno el valor de giPos al nivel de iluminaci�n
        }  
        pantalla_seleccion();                                   // Muestro iconos
        
        if(giPos>MAX_ILUMINACION){                                          // Si el valor es mayor a 100
            giPos=MAX_ILUMINACION;                                          // Fija a 100
        }
        
        if (giPos<MIN_ILUMINACION){                                          // Si el valor es menor a 10
            giPos=MIN_ILUMINACION;                                           // Fija a 10
        }
        
        sprintf(mystring,"%3lu%c",giPos,37);                   // Muestro valor por pantalla
        ST7529_printf(mystring,30,50,XL_,0);
        
        ST7529_putIcon(ICON_ILUM,20,52);                        // Muestro icono iluminaci�n
        
        i8nivel_ilum=giPos;                                     // Obtiene valor de iluminaci�n
        set_pwm8_duty((int16)i8nivel_ilum*10);                  // Cargamos duty de trabajo [0..1000] 
        
        writeEEPROM_8bits(EEPROM_LOC_ILUMINACION,i8nivel_ilum);
        
        ST7529_printfg(sILUM_LEYENDA,0,LEYENDA_Y1,s_,ai8EscalaGrises[1],0);
        ST7529_printfg(sRANGO_10_100_PER_LECTURA,0,LEYENDA_Y2,s_,ai8EscalaGrises[1],0);
        
        iMenuAnterior=iMenuActual;
    }

    bRefrescoPantalla=0;

    return 0;
}

// Configuracion se�al acustico
int8 menu_12(){
    if(bRefrescoPantalla){
        if((iMenuAnterior!=13)&&(iMenuAnterior!=62)){                   // Si no viene de ninguno de los men�s indicados
            ST7529_clear();                                             // Limpio la pantalla                               
            ST7529_printf(sTEST_PITO,0,0,L_,NORMAL);             // Muestro texto                                    
            giPos=i16nivel_son;                                         // Asigno el valor de giPos al nivel de sonido 
        }  
        pantalla_seleccion();                                           // Muestro iconos
        
        if(giPos>MAX_VOLUMEN){                                                  // Si el valor es mayor a 100
            giPos=MAX_VOLUMEN;                                                  // Fija a 100
        }
        
        if (giPos<=MIN_VOLUMEN){                                                  // Si el valor es menor o igual a 0
            giPos=MIN_VOLUMEN;                                                    // Fija a 0
        }
        
        i16nivel_son=giPos;                                             // Asigno nivel de sonido
        
        sprintf(mystring,"%3lu%c",giPos,37);                           // Muestro valor por pantallla
        ST7529_printf(mystring,30,50,XL_,0);
        
        if (giPos==0){                                                  // Si se apaga el pito...
            ST7529_putIcon(ICON_ALTOFF,20,52);                          // Icono altavoz off
            setup_ccp7(CCP_OFF);                                        // Apago modulador
            output_high(PWM_PITO);                                      // Nivel alto pito
        }else{                                                          // ...su no est� apagado
            ST7529_putIcon(ICON_ALTON,20,52);                           // Icono altavoz on
            setup_ccp7(CCP_PWM|CCP_SHUTDOWN_AC_L|CCP_SHUTDOWN_BD_L);    // Modulador para se�al acustica
            set_pwm7_duty((int16)((i16nivel_son*4.5)));                   // Cargamos duty de trabajo [0..500]
        }
        
        writeEEPROM_16bits(EEPROM_LOC_SONIDO,i16nivel_son);
        
        ST7529_printfg(sACUSTICA_LEYENDA,0,LEYENDA_Y1,s_,ai8EscalaGrises[1],0);
        ST7529_printfg(sRANGO_0_100_PER_LECTURA,0,LEYENDA_Y2,s_,ai8EscalaGrises[1],0);
        iMenuAnterior=iMenuActual;
    }
    
    bRefrescoPantalla=0;

    return 0;
}

// Version SW/HW
int8 menu_13(){        
    if(bRefrescoPantalla){
        if(iMenuAnterior!=15){
            ST7529_clear();       
            ST7529_printf(sCONFIG_VERS_MAYUS,0,0,L_,NORMAL);
        }  
        pantalla_seleccion();
        ST7529_printf(sFW_Ver,22,50,L_,0);
        ST7529_printf(sHW_Ver,22,70,L_,0);
        iMenuAnterior=iMenuActual;
    }
    
    bRefrescoPantalla=0;

    return 0;
}

// Contraste
int8 menu_14(){
    //int8 i8AuxContraste;
    
    if(bRefrescoPantalla){
        if (iMenuAnterior!=12){          // Si no viene de ninguno de los men�s indicados
            ST7529_clear();                                     // Limpio la pantalla   
            ST7529_printf(sCONFIG_CONT_MAYUS,0,0,L_,NORMAL);        // Muestro texto 
            giPos=i8NivelContraste;                                 // Asigno el valor de giPos al nivel de iluminaci�n
        }  
        pantalla_seleccion();                                   // Muestro iconos
        
        if(giPos>=MAX_CONTRASTE){                                          // Si el valor es mayor a 100
            giPos=MAX_CONTRASTE;                                          // Fija a 100
        }
        
        if (giPos<=MIN_CONTRASTE){                                          // Si el valor es menor a 10
            giPos=MIN_CONTRASTE;                                           // Fija a 10
        }
        
        sprintf(mystring,"%3lu%c",giPos,37);                   // Muestro valor por pantalla
        ST7529_printf(mystring,30,50,XL_,0);
        
        ST7529_putIcon(ICON_CONTRAST,20,52);                        // Muestro icono iluminaci�n
        
        i8NivelContraste=giPos;                                     // Obtiene valor de iluminaci�n
        ST7529_send(COMMAND,VOLCTRL);      // Electronic Control
        ST7529_send(DATA,i8NivelContraste*0.63);    // Vop=18V - DS: 7.10.2 pg. 32   1C
        ST7529_send(DATA,0x04);          // 04
        ST7529_printfg(sCONTR_LEYENDA,0,LEYENDA_Y1,s_,ai8EscalaGrises[1],0);
        ST7529_printfg(sRANGO_10_80_PER_LECTURA,0,LEYENDA_Y2,s_,ai8EscalaGrises[1],0);
        
        writeEEPROM_8bits(EEPROM_LOC_CONTRASTE,i8NivelContraste);
        
        iMenuAnterior=iMenuActual;
    }

    bRefrescoPantalla=0;
    
    return 0;
}

// Idioma
int8 menu_15(){
    if(bRefrescoPantalla){
        
        if (iMenuAnterior!=14){          // Si no viene de ninguno de los men�s indicados
            ST7529_clear();                                     // Limpio la pantalla   
            ST7529_printf(sCONFIG_IDIO_MAYUS,0,0,L_,NORMAL);        // Muestro texto 
            giPos=i8SelIdioma;                                 // Asigno el valor de giPos al nivel de iluminaci�n
        }  
        pantalla_seleccion();                                   // Muestro iconos
        
        giPos%=NUM_IDIOMAS;
        
        switch(giPos){
            case SPANISH:
                i8RepVal1=sIDIOMA_ESPANOL;
                i32OffsetDireccionIdioma=OFFSET_DIR_SPANISH;
                break;
            case ENGLISH:
                i8RepVal1=sIDIOMA_INGLES;                       // Muestro valor por pantalla
                i32OffsetDireccionIdioma=OFFSET_DIR_ENGLISH;
                break;
        }
        
        ST7529_printf(i8RepVal1,20,50,L_,0);
    
        if(i8SelIdioma!=giPos){
            i8SelIdioma=giPos;
            iMenuAnterior=222;    // Dummy value
        }else{
            iMenuAnterior=iMenuActual;
        } 
        
        writeEEPROM_8bits(EEPROM_LOC_IDIOMA,i8SelIdioma);
        
        ST7529_printfg(sIDIOMA_LEYENDA,0,LEYENDA_Y1,s_,ai8EscalaGrises[1],0);
    }
    
    bRefrescoPantalla=0;
    
    return 0;
}

// Nivel de carga electrica (Galvanica + microcorrientes)
int8 menu_21(){                          // DESHABILITADO - Sin uso                                          
 
    if(bRefrescoPantalla){
        int8  min=0;
        if(iMenuAnterior==20){
            ST7529_clear();       
          
            if (iMenuActual==21){
                giPos=i32CGalv;
                max=1000;
                min=1;
                gC=100;
            }   

            ST7529_printf(sGALV,0,0,L_,NORMAL); 
        }
       
        pantalla_seleccion();
          
        if(giPos>=max){
            giPos=max;
        }
       
        if (giPos<=min){
            giPos=min;
        }
        
        // TODO - Eliminar/modificar
        ST7529_printf(sCa_ELECTRICA ,17,36,M_,NORMAL);
        sprintf(mystring,"%6LU [C",(int32)giPos*100);
        ST7529_printf(mystring,30,70,L_,0);
        if (iMenuActual==21){
            i32CGalv=giPos;
            i16TGalv[bSeleccionGalvanica]=calc_Tgalv(i32CGalv,i16IGalv[bSeleccionGalvanica]);
        }
       
        iMenuAnterior=iMenuActual;
    }
    
    bRefrescoPantalla=0;

    return 0;
}

// Nivel de corriente (Galvanica + Microcorrientes + Pointer + Electroestimulacion)
int8 menu_22(){                
    if(bRefrescoPantalla){
        if((iMenuAnterior!=21)&&(iMenuAnterior!=24)&&(iMenuAnterior!=31)&&(iMenuAnterior!=47)&&(iMenuAnterior!=54)&&(iMenuAnterior!=90)){
            ST7529_clear();
            if(iMenuAnterior==41 || iMenuAnterior==45 || iMenuANterior==46){
                iMenuAnterior=40;
            }
    
            switch (iMenuAnterior){
                case 20:
                case 23:
                    if (giPos==1 || iMenuActual==21){
                        i8RepVal1=sGALV;
                        min=2;
                        max=200;
                   
                        i8RepVal2=sRANGO_100_10;
                        giPos=i16IGalv[bSeleccionGalvanica];
                    }else if (giPos==4 || iMenuActual==24){
                        i8RepVal1=sMICRO_CORRIENTES;
                        min=2;   // 2*50=100uA 
                        max=20;  // 20*50=1000uA
                   
                        i8RepVal2=sRANGO_100_1;
                        giPos=i16Imicro; 
                    }        
                break;
             case 30:
                i8RepVal1=sTRANS;
                min=MINIMA_CORRIENTE_TRANSCRANEAL;
                
                if(limiteDensidadCorriente(LIMIT_CORRIENTE)){
                    max=i16Itrans;
                }else{
                    max=MAXIMA_CORRIENTE_TRANSCRANEAL;
                }
                
                i8RepVal2=sRANGO_100_5;
                giPos=i16Itrans;
                break;
             case 40:
                i8RepVal1=sELECTRO_ESTIMULACION;
                i8RepVal2=sRANGO_100_1;
                max=20;        // 1 mA
                min=2;
                gI=50;
                giPos=i16IElec[i8ConfigCanal];
                break;
            }
            ST7529_printf(i8RepVal1,0,0,L_,NORMAL);
        } 
        
        pantalla_seleccion();
          
        if(giPos>max){
            giPos=max;
        }
        
        if (giPos<=min){
            giPos=min;
        }
       
        ST7529_printf(sCo_ELECTRICA,12,36,M_,NORMAL);
        sprintf(mystring,"%5lu [A",giPos*gI);
        ST7529_printf(mystring,30,70,L_,0);

        switch (iMenuActual){
            case 21:
                i16IGalv[bSeleccionGalvanica]=giPos;  
                i32CGalv=calc_CargaGalv(i16IGalv[bSeleccionGalvanica]);
                break;
            case 24:
                i16Imicro=giPos;        
                break;
            case 31:
                i16ITrans=giPos;  
                i32CTrans=calc_CargaGalv(i16Itrans);
                break;
            case 47:         
                i16IElec[i8ConfigCanal]=giPos;
                break;
        }
       
        ST7529_printfg(sCORRIENTE_LEYENDA,0,LEYENDA_Y1,s_,ai8EscalaGrises[1],0);
        ST7529_printfg(i8RepVal2,0,LEYENDA_Y2,s_,ai8EscalaGrises[1],0);
       
        giPosRulancha=giPos;
       
        iMenuAnterior=iMenuActual;
    }
    
    bRefrescoPantalla=0;

    return 0;
}


// Rampa + tiempo de rampa (Galvanica + Microcorrientes + Electroestimulacion)
int8 menu_23(){
    if(bRefrescoPantalla){
        if((iMenuAnterior!=23)&&(iMenuAnterior!=33)&&(iMenuAnterior!=26)&&(iMenuAnterior!=45)){
            ST7529_clear();
            if(iMenuAnterior==44){
                iMenuAnterior=40;
            }

            switch (iMenuAnterior){
                case 20:
                case 22:
                    if (giPos==3 || iMenuAnterior==22){
                        i8RepVal1=sGALV;
                        giPos=i8TrampaGalv[bSeleccionGalvanica];
                    }else if (giPos==6){
                        i8RepVal1=sMICRO_CORRIENTES;
                        giPos=i8Trampamicro;
                    }
                    break;
                case 30:
                    i8RepVal1=sGALV;
                    giPos=i8TrampaTrans;
                    break;
                case 40:
                    i8RepVal1=sELECTRO_ESTIMULACION;
                    giPos=i8TrElec[i8ConfigCanal];
                    break;
            }
          
            ST7529_printf(i8RepVal1,0,0,L_,NORMAL);
        }
           
        pantalla_seleccion();
       
        if(giPos>10){
            giPos=10;
        }
       
        if (giPos<=0){
            giPos=0;
        }
       
        if(iMenuActual==23){
            if(i16TGalv[bSeleccionGalvanica]!=0){
                if((float)giPos>=(i16TGalv[bSeleccionGalvanica]/3.0)){
                    giPos=(i16TGalv[bSeleccionGalvanica]/3);
                }
            }
        }
        
        if(iMenuActual==33){
            if(i16Ttrans!=0){
                if((float)giPos>=(i16Ttrans/3.0)){
                    giPos=(i16Ttrans/3);
                }
            }
        }
       
        if(iMenuActual==45){
            if((float)giPos>=(i16TacElec[i8ConfigCanal]/3.0)){
                giPos=(i16TacElec[i8ConfigCanal]/3);
            }
        }
       
        ST7529_printf(sTIEMPO_RAMPA,17,36,M_,NORMAL);
        sprintf(mystring,"%2lu s",giPos);
        ST7529_printf(mystring,30,70,L_,0);

        switch (iMenuActual){
            case 23:
                i8TrampaGalv[bSeleccionGalvanica]=giPos;
                break;
            case 26:
                i8Trampamicro=giPos;
                break;
            case 33:
                i8TrampaTrans=giPos;
                break;
            case 45:
                i8TrElec[i8ConfigCanal]=giPos;
                break;
        }
       
        ST7529_printfg(sTIEMPO_RAMPA_LEYENDA,0,LEYENDA_Y1,s_,ai8EscalaGrises[1],0);
       
        giPosRulancha=giPos;
       
        iMenuAnterior=iMenuActual;
    }
    
    bRefrescoPantalla=0;

    return 0;
}

// PW pulsada (Microcorrientes + Pointer + Electroestimulacion + SMP)
int8 menu_27(){
    //float fRaw=0;

    if(bRefrescoPantalla){
        if(((iMenuAnterior!=27)&&(iMenuAnterior!=35)&&(iMenuAnterior!=36)&&(iMenuAnterior!=51)&&(iMenuAnterior!=52)&&(iMenuAnterior!=58)&&(iMenuAnterior!=59)&&(iMenuAnterior!=84)&&(iMenuAnterior!=94)&&(iMenuAnterior!=95)) || (iMenuAnterior==51 && iMenuActual==52)){
            ST7529_clear();
            if(iMenuAnterior==48 || iMenuAnterior==49 || iMenuAnterior==50 || iMenuAnterior==51){
                iMenuAnterior=40;
            }
          
            if(iMenuAnterior==83){
                iMenuAnterior=80;
            }

            switch (iMenuAnterior){
                case 20:
                case 26:
                    i8RepVal1=sMICRO_CORRIENTES;
                    giPos=i16PWmicro/25;      
                    maxBW=20;
                    break;
                case 40:
                    i8RepVal1=sELECTRO_ESTIMULACION;
                    if(i8ConfigCanal==POINTER_C){
                        maxBW=40;
                    }else{
                        maxBW=40;
                    }
                
                    if(iMenuActual==51){
                       giPos=i16PW_plusElec[i8ConfigCanal]/25;
                       maxBW=((900000.0/i16FrecElec[i8ConfigCanal])-(i16PW_minusElec[i8ConfigCanal]))/25; 
                    }else if (iMenuActual==52){
                       giPos=i16PW_minusElec[i8ConfigCanal]/25;
                       maxBW=((900000.0/i16FrecElec[i8ConfigCanal])-(i16PW_plusElec[i8ConfigCanal]))/25;
                    }
                    if(maxBW>=40){
                        maxBW=40;
                    }
                    break;
                case 80:
                    i8RepVal1=sSMP;
                
                    giPos=i16PWSMP/25;
                   
                    maxBW=20;    // 500us
                    break;
            }
         
            ST7529_printf(i8RepVal1,0,0,L_,NORMAL);
        }
       
        if(iMenuActual==51){
            ST7529_printf(sPW_POS,17,36,M_,NORMAL);
        }else if(iMenuActual==52){
            ST7529_printf(sPW_NEG,17,36,M_,NORMAL);
        }else{
            ST7529_printf(sPW_GEN,17,36,M_,NORMAL);
        }
        pantalla_seleccion();
      
        if(giPos>=maxBW){
            giPos=maxBW;
        }
       
        if (giPos<4){
            giPos=4;
        }
        sprintf(mystring,"%4lu [s",giPos*25);
        ST7529_printf(mystring,26,70,L_,0);
      
        switch (iMenuActual){
            case 27:
                i16PWmicro=giPos*25;
                i8RepVal2=sPW_LEYENDA;
                break; 
            case 51:
                i16PW_plusElec[i8ConfigCanal]=giPos*25;

                if(i8SimetriaCanales!=0){
                    copiarDatosSimetria(0);
                }
                if(i8ConfigCanal==POINTER_C){
                    i16PW_minusElec[i8ConfigCanal]=i16PW_plusElec[i8ConfigCanal];
                    i8RepVal2=sPW_LEYENDA;
                }else{
                    i8RepVal2=sPWP_LEYENDA;
                }
                break;
            case 52:
                i16PW_minusElec[i8ConfigCanal]=giPos*25;

                if(i8SimetriaCanales!=0){
                    copiarDatosSimetria(0);
                }
                i8RepVal2=sPWN_LEYENDA;
                break;
            case 84:
                i16PWSMP=giPos*25;
                if((i16PWSMP*2+BANDA_GUARDA*2) >= i32TDesfaseSMP){
                    giPos=(i32TDesfaseSMP-BANDA_GUARDA*2)/2;
                    giPos/=25;
                    i16PWSMP=giPos*25;
                }
                maxBW=20;   //500us
                i8RepVal2=sPW_LEYENDA;
                break;
        }
       
        giPosRulancha=giPos;
        ST7529_printfg(i8RepVal2,0,LEYENDA_Y1,s_,ai8EscalaGrises[1],0);
        iMenuAnterior=iMenuActual;
    }
    
    bRefrescoPantalla=0;

    return 0;
}


 
// Frecuencia (Microcorrientes + Pointer + Electroestimulacion)
int8 menu_28(){
    int16 aux;
    
    if(bRefrescoPantalla){
        if((iMenuAnterior!=28)&&(iMenuAnterior!=32)&&(iMenuAnterior!=48)&&(iMenuAnterior!=55)&&(iMenuAnterior!=83)&&(iMenuAnterior!=91)){
            if(iMenuAnterior==47){
                   iMenuAnterior=40;
            }

            if(iMenuAnterior==82){
                iMenuAnterior=80;
            }
            
            if(iMenuAnterior==27){
                iMenuAnterior=20;
            }

            ST7529_clear();
            
            switch (iMenuAnterior){
                case 20:
                    i8RepVal1=sMICRO_CORRIENTES;
                    max=100;
                    min=2;                                    
                    aux=i16frecmicro;
                    gF=1;
                    giPos=aux/gF;
                    break;       
                case 40:
                    i8RepVal1=sELECTRO_ESTIMULACION;
            
                    aux=i16frecElec[i8ConfigCanal];
            
                    max=i16FrecLimSup[i8ConfigCanal];
                    min=i16FrecLimInf[i8ConfigCanal];
                    break;
                case 80:
                    i8RepVal1=sSMP;
                    max=100;
                    min=2;
                    aux=i16FrecSMP;
                    break;
            }

            ST7529_printf(i8RepVal1,0,0,L_,NORMAL);
        }else{
            aux=giPos*gF;
        }

        if(iMenuActual!=28){
            if (aux>200 && aux<=10000){
                gF=50;
                giPos=aux/gF;
            }else if(aux==200){
                if(bascendente){
                    gF=50;
                    giPos=aux/gF;
                }else{
                    gF=10;
                    giPos=aux/gF;
                }
            }else if (aux>100 && aux<200){
                if(giPos==3 && gF==50){         // Si estabamos en 200 y ahora al volver atras quiere mostrar 150
                    giPos=19;                    // Le decimos que la cuenta es de 10 en 10
                    aux=190;                    // Salta a 190
                }
                gF=10;
                giPos=aux/gF;
            }else if(aux==100){
                if(bascendente){
                    gF=10;
                    giPos=aux/gF;
                }else{
                    gF=2;
                    giPos=aux/gF;
                } 
            }else if (aux>20 && aux<100){
                if(giPos==9 && gF==10){            // Si estabamos en 100 y ahora al volver atras quiere mostrar 90
                    giPos=49;                    // Le decimos que la cuenta es de 2 en 2
                    aux=98;                        // Salta a 98
                }
                gF=2;
                giPos=aux/gF;
            }else if(aux==20){
                if(bascendente){
                    gF=2;
                    giPos=aux/gF;
                }else{
                    gF=1;
                    giPos=aux/gF;
                } 
            }else{
                if(giPos==9 && gF==2){            // Si estabamos en 20 y ahora al volver atras quiere mostrar 18                
                    giPos=19;                    // Le decimos que la cuenta es de 10 en 10        
                    aux=19;                        // Salta a 19    
                }
                gF=1;
                giPos=aux;
            }
        }
        
        if ((giPos*gF)>=max){
            giPos=max/gF;
        }

        if ((giPos*gF)<min){
            giPos=min/gF;
        }

        pantalla_seleccion();
        
        ST7529_printf(sFRECUENCIA,24,36,M_,NORMAL);
      
        sprintf(mystring,"%5lu Hz",giPos*gF);
        ST7529_printf(mystring,29,70,L_,0);
        
        switch (iMenuActual){
            case 28:
                aux=giPos*gF;
                i16frecmicro=giPos*gF;
                maxBW=Calc_BWmax(i16frecmicro,bpolaridadmicro);
                break;
            case 48: 
                aux=giPos*gF;
                i16frecElec[i8ConfigCanal]=giPos*gF;
                maxBW=Calc_BWmax(i16frecElec[i8ConfigCanal],bpolaridadElec[i8ConfigCanal]);
                i16PW_plusElec[i8ConfigCanal]=Calc_BW(maxBW,i16PW_plusElec[i8ConfigCanal]);
                i16PW_minusElec[i8ConfigCanal]=Calc_BW(maxBW,i16PW_minusElec[i8ConfigCanal]);

                if(i8SimetriaCanales!=0){
                    copiarDatosSimetria(0);
                }
                break;
            case 83:
                aux=giPos*gF;
                i16FrecSMP=giPos*gF;
                maxBW=Calc_BWmax(i16FrecSMP,1);
                i16PWSMP=Calc_BW(maxBW,i16PWSMP);
                break;
        }
        giPosRulancha=giPos;
        iMenuAnterior=iMenuActual;
        ST7529_printfg(sFRECUENCIA_LEYENDA,0,LEYENDA_Y1,s_,ai8EscalaGrises[1],0);
    }

    bRefrescoPantalla=0;

    return 0;
} 
 


// POLARIDAD (Microcorrientes + Pointer + Electroestimulacion)

int8 menu_29(){
    if(bRefrescoPantalla){
        if((iMenuAnterior!=26)&&(iMenuAnterior!=34)&&(iMenuAnterior!=49)&&(iMenuAnterior!=57)&&(iMenuAnterior!=93)){
            ST7529_clear();
            if(iMenuAnterior==48){
                iMenuAnterior=40;
            }
            
            switch (iMenuAnterior){
                case 20:
                case 25:
                    i8RepVal1=sMICRO_CORRIENTES;
                    giPos=bPolaridadMicro;
                    break;                       
                case 40:
                    i8RepVal1=sELECTRO_ESTIMULACION;
                    giPos=bpolaridadElec[i8ConfigCanal];
                    break;
            }
            ST7529_printf(i8RepVal1,0,0,L_,NORMAL);
        }
        
        pantalla_seleccion();
       
        if(giPos>1){
            giPos=1;
        }
       
        if (giPos<=0){
            giPos=0;
        }

        ST7529_printf(sPOLARIDAD,25,36,M_,NORMAL);
       
        if(giPos==0){
            i8RepVal1=sMONOPOLAR;
        }else{
            i8RepVal1=sBIPOLAR;
        }

        ST7529_printf(i8RepVal1,25,70,L_,0);
       
        switch(iMenuActual){
            case 26:
                bPolaridadMicro=giPos;
                maxBW=Calc_BWmax(i16frecmicro,bpolaridadmicro);
                i16PWmicro=Calc_BW(maxBW,i16PWmicro);
                //i16Tmicro=calc_Tmicro(); 
                break;
            case 49:
                bpolaridadElec[i8ConfigCanal]=giPos;
                maxBW=Calc_BWmax(i16frecElec[i8ConfigCanal],bpolaridadElec[i8ConfigCanal]);
                i16PW_plusElec[i8ConfigCanal]=Calc_BW(maxBW,i16PW_plusElec[i8ConfigCanal]);
                i16PW_minusElec[i8ConfigCanal]=Calc_BW(maxBW,i16PW_minusElec[i8ConfigCanal]);
                if(i8SimetriaCanales!=0){
                    copiarDatosSimetria(0);
                }
                break;      
        }
        
        ST7529_printfg(sPOLARIDAD_LEYENDA,0,LEYENDA_Y1,s_,ai8EscalaGrises[1],0);

        giPosRulancha=giPos;
       
        iMenuAnterior=iMenuActual;
    }
    
    bRefrescoPantalla=0;

    return 0;
}



// Simetria de la se�al (Pointer + Elecroestimulacion)

int8 menu_33(){ 
    if(bRefrescoPantalla){
        if((iMenuAnterior!=33)&&(iMenuAnterior!=42)&&(iMenuAnterior!=50)&&(iMenuAnterior!=56)&&(iMenuAnterior!=92)){
            ST7529_clear();
            if(iMenuAnterior==41 || iMenuAnterior==49){
                if(iMenuAnterior==41){
                    switch(i8ConfigCanal){
                        case CHA_C:
                            if(i8CanalesActivados&CHA_ACT){
                                if(i8ReposoActivados&CHA_ACT){
                                    iMenuActual=142;
                                }else{
                                    iMenuActual=141;
                                }
                            }else if(i8CanalesConfigurados&CHA_ACT){
                                iMenuActual=140;
                            }
                            break;
                        case CHB_C:
                            if(i8CanalesActivados&CHB_ACT){
                                if(i8ReposoActivados&CHB_ACT){
                                    iMenuActual=142;
                                }else{
                                    iMenuActual=141;
                                }
                            }else if(i8CanalesConfigurados&CHB_ACT){
                                iMenuActual=140;
                            }
                            break;
                        case CHC_C:
                            if(i8CanalesActivados&CHC_ACT){
                                if(i8ReposoActivados&CHC_ACT){
                                    iMenuActual=142;
                                }else{
                                    iMenuActual=141;
                                }
                            }else if(i8CanalesConfigurados&CHC_ACT){
                                iMenuActual=140;
                            }
                            break;
                        case POINTER_C:
                            if(i8CanalesActivados&POINTER_ACT){
                                iMenuActual=141;
                            }else if(i8CanalesConfigurados&POINTER_ACT){
                                iMenuActual=140;
                            }else{
                                iMenuActual=40;
                            }
                            break;
                    }
                }else{
                    iMenuAnterior=40;
                }
            }

            switch (iMenuAnterior){
                case 40:
                case 41:
                    if(iMenuActual==50){
                        giPos=bsimetriaElec[i8ConfigCanal];
                    }else{
                        giPos=i8SimetriaCanales;
                    }
                    break;
            }
            ST7529_printf(sELECTRO_ESTIMULACION,0,0,L_,NORMAL);
        }

        pantalla_seleccion();
       
        if(iMenuActual==42){
            if(giPos>=2){ // Maximo numero de configuraciones de simetria de canales
                giPos=2;
            }
        }else{
            if(giPos>1){
                giPos=1;
            }
        }
        
        if (giPos<=0){
            giPos=0;
        }
       
        if(iMenuActual==42){
            i8SimetriaCanales=giPos;
        
            switch(i8SimetriaCanales){
                case 0:
                    i8RepVal1=sSimetriaCanalesNO;      
                    i8RepVal2=sSIM_CAN_N_LEYENDA;
                    break;
                case 1:
                    i8RepVal1=sSimetriaCanalesAB;           
                    i8RepVal2=sSIM_CAN_AB_LEYENDA; 
                    break;
                case 2:
                    i8RepVal1=sSimetriaCanalesABC;        
                    i8RepVal2=sSIM_CAN_ABC_LEYENDA;
                    break;
            }
            ST7529_printf(i8RepVal1,35,70,L_,0);
            ST7529_printfg(i8RepVal2,0,LEYENDA_Y1,S_,ai8EscalaGrises[1],0);
            
            ST7529_printf(sSIM_CANALES,2,39,M_,NORMAL);
            
            copiarDatosSimetria(1);
       
        }else if(iMenuActual<140){
       
            ST7529_printf(sSIMETRIA,28,36,M_,NORMAL);
           
            if(giPos==0){
                i8RepVal1=sASIMETRICA;
                i8RepVal2=sPW_SIM;
            }else{
                if ((iMenuActual==49)||(iMenuActual==56)){  
                    bpolaridadElec[i8ConfigCanal]=1;
                }
                i8RepVal1=sSIMETRICA;
                i8RepVal2=sPW_ASIM;
            }
            ST7529_printf(i8RepVal1,26,70,L_,0);
            ST7529_printfg(i8RepVal2,0,LEYENDA_Y1,s_,ai8EscalaGrises[1],0);

            switch (iMenuActual){
                case 50:
                    bsimetriaElec[i8ConfigCanal]=giPos;
                    maxBW=Calc_BWmax(i16frecElec[i8ConfigCanal],bpolaridadElec[i8ConfigCanal]);
                    i16PW_plusElec[i8ConfigCanal]=Calc_BW(maxBW,i16PW_plusElec[i8ConfigCanal]);
                    i16PW_minusElec[i8ConfigCanal]=Calc_BW(maxBW,i16PW_minusElec[i8ConfigCanal]);
                    if(i8SimetriaCanales!=0){
                        copiarDatosSimetria(0);
                    }
                    break;
            }
        }
       
        giPosRulancha=giPos;
       
        iMenuAnterior=iMenuActual;
    }
    
    bRefrescoPantalla=0;

    return 0;
}


// Menu de selecci�n de la superficie del electrodo
int8 menu_34(){
    
    if(bRefrescoPantalla){

        if(iMenuAnterior!=34){
            ST7529_clear();
            ST7529_printf(sTRANS,0,0,L_,NORMAL);
            giPos=i8SuperficieElectrodo;
        }
        
        if(limiteDensidadCorriente(LIMIT_SUPERFICIE)){
            min=i8SuperficieElectrodo;
        }else{
            min=MIN_TAM_ELECTRODO;
        }
        
        pantalla_seleccion();
        
        if(giPos>MAX_TAM_ELECTRODO){
            giPos=MAX_TAM_ELECTRODO;
        }
       
        if (giPos<min){
            giPos=min;
        }
       
        i8SuperficieElectrodo=giPos;
        
        ST7529_printf(sSUPERFICIE_ELECTRODO,2,36,M_,NORMAL);
        
        sprintf(mystring,"%3u cm]",i8SuperficieElectrodo);
        ST7529_printf(mystring,30,70,L_,0);
        
        iMenuAnterior=iMenuActual;
    }
    
    bRefrescoPantalla=0;

    return 0;
}



// Selecci�n canal electroestimulacion
int8 menu_41(){
    if(bRefrescoPantalla){
        if (iMenuAnterior!=41){                         // Si vengo de un men� distinto
            ST7529_clear();
            giPos=i8ConfigCanal;
            ST7529_printf(sELECTRO_ESTIMULACION,0,0,L_,NORMAL);
            ST7529_printfg(sSELECCION_CANAL,0,LEYENDA_Y1,s_,ai8EscalaGrises[1],0);
        } 
        pantalla_seleccion();
        
        
        if(giPos>=3){
            giPos=3;
        }
        
        if(giPos<=0){
            giPos=0;
        }
        
        if((i8CanalesActivados&CHA_ACT) && giPos==POINTER_C){
            giPos=CHC_C;
        }
        
        if((i8CanalesActivados&POINTER_ACT) && giPos==CHA_C){
            giPos=CHB_C;
        }
        
        ST7529_printf(sSEL_CANAL,12,36,M_,NORMAL);
        
        switch(giPos){
            case 0:
                i8RepVal1=sCANAL_A;
                bPointerSeleccionado=0;
                break;
            case 1: 
                i8RepVal1=sCANAL_B;
                break;
            case 2:
                i8RepVal1=sCANAL_C;
                break;
            case 3:
                i8RepVal1=sCANAL_POINTER;
                bPointerSeleccionado=1;
                i8SimetriaCanales=0;    // En el caso de seleeccionar pointer, debemos de eliminar la opci�n de simetria entre canales por si estuviera activada, 0 == NO_SIMETRIA 
                break;
        }
        
        ST7529_printf(i8RepVal1,25,70,L_,0);
        
        i8ConfigCanal=giPos;
        bborrado=1;
        iMenuAnterior=iMenuActual;
    }
    
    bRefrescoPantalla=0;

    return 0;
}

// Control del tiempo (Electroestimulacion)
int8 menu_42(){
    if(bRefrescoPantalla){
        int1 bIlimitado=0;
        
        if (((iMenuAnterior!=22)&&(iMenuAnterior!=25)&&(iMenuAnterior!=32)&&(iMenuAnterior!=43)&&(iMenuAnterior!=44)&&(iMenuAnterior!=81)&&(iMenuAnterior!=82)) || (iMenuAnterior==43 && iMenuActual==44) || (iMenuAnterior==81 && iMenuActual==82)){
            ST7529_clear();
            if (iMenuAnterior==40 || iMenuAnterior==41 || iMenuAnterior==42 || iMenuAnterior==43){
                ST7529_printf(sELECTRO_ESTIMULACION,0,0,L_,NORMAL);
                switch (iMenuActual){
                    case 43:
                        giPos=i16TacElec[i8ConfigCanal]/5;
                        break;
                    case 44:
                        giPos=i16TdElec[i8ConfigCanal]/5;
                        break;
                }
            }else if(iMenuAnterior==80 || iMenuAnterior==81){
                ST7529_printf(sSMP,0,0,L_,NORMAL);
                
                if(iMenuActual==81){
                    giPos=i16TacSMP/5;
                }else{
                    giPos=i32TDesfaseSMP/100;
                }
            }else if(iMenuAnterior==20 || iMenuAnterior==21 || imenuAnterior==24){
                if(giPos==2 || iMenuAnterior==21){
                    ST7529_printf(sGALV,0,0,L_,NORMAL);
                          
                    giPos=i16TGalv[bSeleccionGalvanica];
                }else if (giPos==5 || iMenuAnterior==24){
                    ST7529_printf(sMICRO_CORRIENTES,0,0,L_,NORMAL);
                          
                    giPos=i16Tmicro/5;
                }
            }else if(iMenuAnterior==30){
                ST7529_printf(sTRANS,0,0,L_,NORMAL);
                          
                giPos=i16Ttrans;
            }
        }
    
        pantalla_seleccion();
    
        if(iMenuActual==81){
            if(giPos>719){ //719*5=3595 segundos - 59 min 55 s
                giPos=719;
            }
            if (giPos<=1){
                giPos=1;
            }
        }else if(iMenuActual==82){
            if(giPos>1000){ 
                giPos=1000;
            }
            if (giPos<=5){
                giPos=5;
            }
        }else if(iMenuActual==43){      // Tiempo activo
            if(giPos>719){ //719*5=3595 segundos - 59 min 55 s
                giPos=719;
            }
            if (giPos<=1){
                giPos=1;
            }
        }else if(iMenuActual==44){      // Tiempo descanso
            if(giPos>719){ //719*5=3595 segundos - 59 min 55 s
                giPos=719;
            }
            if (giPos<=0){
                giPos=0;
            }
        }else if(iMenuActual==22){
            if(giPos>1800){         // Max 30 min 
                giPos=1800;
            }
            if(bSeleccionGalvanica){
                if (giPos<=1){          
                    giPos=1;
                }
            }else{
                if (giPos<=0){          // Si es 0, tiempo ilimitado
                    giPos=0;
                }
            }
        }if(iMenuActual==25){
            if(giPos>720){ //720*5=3600 segundos - 60 min 00 s
                giPos=720;
            }
            if (giPos<=1){
                giPos=1;
            }
        }else if(iMenuActual==32){
            if(giPos>1800){         // Max 30 min 
                giPos=1800;
            }

            if (giPos<=0){          // Si es 0, tiempo ilimitado
                giPos=0;
            }
        }else{
            if(giPos>1000){
                giPos=1000;
            }
            if (giPos<=0){
                giPos=0;
            }
        }
    
        switch (iMenuActual){
            case 43:
                i16TacElec[i8ConfigCanal]=giPos*5;          
                Calc_representacion_t(i16TacElec[i8ConfigCanal],0);     
                    
                i8RepVal1=sTIEMPO_ACT;
                sprintf(mystring1,"Ta=%2u:%02u s",i8Tmin,i8Tseg);
                i8RepVal2=sTIEMPO_ACT_LEYENDA; 
                break;
            case 44:
                i16TdElec[i8ConfigCanal]=giPos*5;
                Calc_representacion_t(i16TdElec[i8ConfigCanal],0);
                i8RepVal1=sTIEMPO_REP;
                sprintf(mystring1,"Td=%2u:%02u s",i8Tmin,i8Tseg);
                i8RepVal2=sTIEMPO_REP_LEYENDA;
                break;
            case 81:        // Tiempo SMP
                i16TacSMP=giPos*5;
                Calc_representacion_t(i16TacSMP,0);
                i8RepVal1=sTIEMPO_ACT;
                sprintf(mystring1,"Ta=%2u:%02u s",i8Tmin,i8Tseg);
                i8RepVal2=sTIEMPO_ACT_LEYENDA;
                break;
            case 82:        // Desfase SMP
                i32TDesfaseSMP=giPos*100;
                i8RepVal1=sTIEMPO_DESF;
                sprintf(mystring1,"Tp=%6lu [s",i32TDesfaseSMP);
                i8RepVal2=sDESF_PULSOS_LEYENDA;
                break;
            case 22:        // Tac galv
                i16TGalv[bSeleccionGalvanica]=giPos;
                Calc_representacion_t(i16TGalv[bSeleccionGalvanica],0);
                i8RepVal1=sTIEMPO_ACT;
                if(i16TGalv[bSeleccionGalvanica]!=0){
                    sprintf(mystring1,"Ta=%2u:%02u s",i8Tmin,i8Tseg);
                }else{
                    ST7529_printf(sILIMITADO,25,70,L_,0);
                    bIlimitado=1;
                }
                i8RepVal2=sTIEMPO_ACT_LEYENDA;
                break;
            case 25:        // Tac galv
                i16Tmicro=giPos*5;
                Calc_representacion_t(i16Tmicro,0);
                i8RepVal1=sTIEMPO_ACT;
                sprintf(mystring1,"Ta=%2u:%02u s",i8Tmin,i8Tseg);
                i8RepVal2=sTIEMPO_ACT_LEYENDA;
                break;
            case 32:
                i16Ttrans=giPos;
                Calc_representacion_t(i16Ttrans,0);
                i8RepVal1=sTIEMPO_ACT;
                if(i16Ttrans!=0){
                    sprintf(mystring1,"Ta=%2u:%02u s",i8Tmin,i8Tseg);
                }else{
                    ST7529_printf(sILIMITADO,25,70,L_,0);
                    bIlimitado=1;
                }
                i8RepVal2=sTIEMPO_ACT_LEYENDA;
                break;
        }
        
        ST7529_printf(i8RepVal1,12,36,M_,NORMAL);
        ST7529_printf(i8RepVal2,0,LEYENDA_Y1,S_,NORMAL);
        
        if(!bIlimitado){
            ST7529_printf(mystring1,25,70,L_,0);
        }
        //ST7529_printfg(mystring2,5,115,s_,0xA0,0);
        
        giPosRulancha=giPos;
       
        iMenuAnterior=iMenuActual;
    }
    
    bRefrescoPantalla=0;

    return 0;
}


// Numero de repeticiones electroestimulacion
int8 menu_43(){
    if(bRefrescoPantalla){
        if (iMenuAnterior!=46){
            ST7529_clear();
            ST7529_printf(sELECTRO_ESTIMULACION,0,0,L_,NORMAL);
            giPos=i8Nrep[i8ConfigCanal];
        } 
        pantalla_seleccion();
        
        if(giPos>100){
            giPos=100;  
        }
        if (giPos<1){
            giPos=1;
        }
        
        sprintf(mystring1,"N=%3lu",giPos);
        
        i8Nrep[i8ConfigCanal]=giPos;
        
        ST7529_printf(mystring1,30,70,L_,0);
        ST7529_printf(sNUM_REPS,12,36,M_,NORMAL);
        
        giPosRulancha=giPos;
        ST7529_printfg(sREPS_LEYENDA,0,LEYENDA_Y1,S_,ai8EscalaGrises[1],0);

        iMenuAnterior=iMenuActual;
    }
    
    bRefrescoPantalla=0;

    return 0;
}

// Test del bicolor
int8 menu_61(){
    if(bRefrescoPantalla){
        if (iMenuAnterior!=61){                         // Si es la primera vez que entramos en este men�
            ST7529_clear();                             // Limpio la pantalla
            ST7529_printf(sTEST_LEDS,0,0,L_,NORMAL);     // Imprimo por pantalla
            giPos=0;                                    // Inicializo giPos
        } 

        write_PCA955X(0x00,0x00,0x00,PCA9555);          // Envia el dato completo al expansor (apagar leds sin molestar a los rel�s)
        pantalla_seleccion();                           // Muestra los iconos de selecci�n           
        
        if (giPos>=4){                                  // Si es mayor o igual a 4
            giPos=0;                                    // Reiniciamos giPos
        }
        
        ST7529_printf(sLED_CHC,20,35,M_,giPos==0);     
        ST7529_printf(sLED_CHB,20,50,M_,giPos==1);     
        ST7529_printf(sLED_CHA,20,65,M_,giPos==2);
        ST7529_printf(sLED_GAL,20,80,M_,giPos==3);
        
        control_led(1,switch_led,giPos);                // Cambio el estado del LED seleccionado                         
        
        pausa_ms(250);                                  // Delay de muestra
        
        if (switch_led){                                // Cambio de color (1 o 0)
            switch_led=0;
        }else{
            switch_led=1;  
        }
        control_led(0,switch_led,giPos);
        
        iMenuAnterior=iMenuActual;                      // Asigno men� actual a men� anterior
    }
    
    bRefrescoPantalla=0;

    return 0;
}

// Test del pulsadores consola
int8 menu_63(){ 
    if(bRefrescoPantalla){
        if (iMenuAnterior!=63){
            ST7529_clear();
            ST7529_printf(sTEST_PULS,0,0,L_,NORMAL);
            pantalla_seleccion();   
            ST7529_printfg(sTEXTO_PULSADORES,20,115,s_,0xA0,0);
            var_puls=0;
            giPos=0;
        }
       
        switch (var_puls){                                    // Esta variable indica la tecla que se ha presionado, Es asignada en el main, while principal
            case 1:
                ST7529_putIcon2(ICON_UP,0,20,ai8EscalaGrises[1]);
                break;
            case 2:
                ST7529_putIcon2(ICON_DOWN,0,90,ai8EscalaGrises[1]);
                break;
            case 3:
                ST7529_putIcon2(ICON_RIGHT,74,90,ai8EscalaGrises[1]); 
                break;
            case 4:
                ST7529_putIcon2(ICON_LEFT,74,20,ai8EscalaGrises[1]);
                break;
        }
       
        giPosRulancha=giPos;
       
        iMenuAnterior=iMenuActual;
    }
    
    bRefrescoPantalla=0;

    return 0;
}


// Test del acelerometro 
int8 menu_65(){
    if(bRefrescoPantalla){
        if (iMenuAnterior!=65){
            ST7529_clear();
            ST7529_printf(sTEST_ACCE,0,0,L_,NORMAL);
            pantalla_seleccion();
        }
        read_MMA8451();
          
        sprintf(mystring,"X=%6lu X_g=%4.3f",x,x_g);
        ST7529_printfg(mystring,8,40,M_,0xff,0);
        sprintf(mystring,"Y=%6lu Y_g=%4.3f",y,y_g);
        ST7529_printfg(mystring,8,50,M_,0xff,0);
        sprintf(mystring,"Z=%6lu Z_g=%4.3f",z,z_g);
        ST7529_printfg(mystring,8,60,M_,0xff,0);
        pausa_ms(250);
       
        iMenuAnterior=iMenuActual;   
    }
    
    bRefrescoPantalla=0;

    return 0;
}

// Test del alimentacion ext
int8 menu_66(){ 
    if(bRefrescoPantalla){
        if (iMenuAnterior!=66){
            ST7529_clear();
            ST7529_printf(sTEST_AEXT,0,0,L_,NORMAL);                                                                          // 1100011101111000
            pantalla_seleccion();   
        }
       
        if(input_state(DET_CHG)){ 
            i8RepVal1=sALIMENTACION;
            i8RepVal2=sDESCONECTADA;
        }else{
            i8RepVal1=sALIMENTACION;
            i8RepVal2=sCONECTADA;
        }
       
        ST7529_printf(i8RepVal1,20,70,M_,0);
        ST7529_printf(i8RepVal2,25,85,M_,0);
       
        iMenuAnterior=iMenuActual;
    }
    
    bRefrescoPantalla=0;

    return 0;
}

// Test del status cargador
int8 menu_67(){   
    if(bRefrescoPantalla){
        if (iMenuAnterior!=67){
            ST7529_clear();
            ST7529_printf(sTEST_SCAR,0,0,L_,NORMAL);
            pantalla_seleccion();   
        }
        
        if (input_state(CHG_STAT)){                // 1--> CARGADO 0--> EN CARGA
            i8RepVal1=sCARGADO;
            output_high(LED_CHG_R); 
            output_low(LED_CHG_V);  
        }else{
            i8RepVal1=sENCARGA;
            output_high(LED_CHG_V);
            output_low(LED_CHG_R);  
        }
        ST7529_printf(i8RepVal1,28,70,M_,0);
        pausa_ms(250);
        
        output_low(LED_CHG_R);
        output_low(LED_CHG_V); 
        
        iMenuAnterior=iMenuActual;
    }
    
    bRefrescoPantalla=0;

    return 0;
}

// Test del DC/DC 12V
int8 menu_68(){   
    if(bRefrescoPantalla){
        if (iMenuAnterior!=68){
            ST7529_clear();
            ST7529_printf(sTEST_DC12,0,0,L_,NORMAL);
            pantalla_seleccion(); 
        }

        control_DC(1,EN_12);                                // Enciende el DC de 12V  
        pausa_ms(500);
        
        if (input_state(POK_12V)){                          // 1--> ALIMENTACION DESCONECTADA 0--> ALIMENTACION CONECTADA
            i8RepVal1=sDC12_NOK;
        }else{
            i8RepVal1=sDC12_OK; 
        }
        
        ST7529_printf(i8RepVal1,15,70,M_,0);

        
        iMenuAnterior=iMenuActual;
    }
    
    bRefrescoPantalla=0;

    return 0;
}


// Test del DC/DC 48V
int8 menu_69(){   
    if(bRefrescoPantalla){
        if (iMenuAnterior!=69){
            ST7529_clear();
            ST7529_printf(sTEST_DC30,0,0,L_,NORMAL);
            pantalla_seleccion(); 
            control_DC(1,EN_30); // DEBUG
        }
        /*
        control_DC(1,EN_30);   
        pausa_ms(3000);
        
        if (input_state(POK_48V)){              // 1--> ALIMENTACION DESCONECTADA 0--> ALIMENTACION CONECTADA
            i8RepVal1=sDC30_NOK;
        }else{
            i8RepVal1=sDC30_OK; 
        }
        
        ST7529_printf(i8RepVal1,15,70,M_,0);
        
        control_DC(0,EN_30);
        pausa_ms(1000);   
        */
        // DEBUG
        if (input_state(POK_48V)){              // 1--> ALIMENTACION DESCONECTADA 0--> ALIMENTACION CONECTADA
            i8RepVal1=sDC30_NOK;
        }else{
            i8RepVal1=sDC30_OK; 
        }
        
        ST7529_printf(i8RepVal1,15,70,M_,0);
        iMenuAnterior=iMenuActual;
    }
    
    bRefrescoPantalla=0;

    return 0;
}

// Test reles
int8 menu_70(){   
    if(bRefrescoPantalla){
        if (iMenuAnterior!=70){
            ST7529_clear();
            ST7529_printf(sTEST_RELE,0,0,L_,NORMAL);
            pantalla_seleccion();
            giPos=0;
        }
        
        giPos%=5;
        
        ST7529_printf(sRELE_GALV,10,10,S_,giPos==0);
        ST7529_printf(sRELE_ECHA,10,20,S_,giPos==1);
        ST7529_printf(sRELE_ECHB,10,30,S_,giPos==2);
        ST7529_printf(sRELE_ECHC,10,40,S_,giPos==3);
        ST7529_printf(sRELE_PROG,10,50,S_,giPos==4);
        
        control_rele(switch_led,giPos);                      
        pausa_ms(500);
        
        switch_led=~switch_led;

        iMenuAnterior=iMenuActual;
    }
    
    bRefrescoPantalla=0;

    return 0;
}
 
/*
* Test BQ34Z1000G1
* Comprueba el tipo de dispositivo y la tensi�n medida
*/
int8 menu_71(){
    if(bRefrescoPantalla){
        if (iMenuAnterior!=71){
            ST7529_clear();
            ST7529_printf(sTEST_BQ34,0,0,L_,NORMAL);
            pantalla_seleccion();
        
        }
        
        if(getDeviceType()==0x0100){                                               // Detecta que el dispositivo colocado es el correcto y funciona
            i8RepVal1=sDEV_OK;
        }else{
            i8RepVal1=sDEV_NOK;
        }

        ST7529_printf(i8RepVal1,30,15,S_,0);
        
        ST7529_printf(sBQ_VOLTAJE,10,25,S_,0);
        sprintf(mystring,"%4Ld mV",getVoltage());                        // Obtenci�n de la tensi�n de la bater�a 
        ST7529_printf(mystring,30,25,S_,0);
        
        ST7529_printf(sBQ_CORRIENTE,10,35,S_,0);
        sprintf(mystring,"%4Ld mA",getCurrent());                        // Obtennci�n de la corriente que pasa por el shunt
        ST7529_printf(mystring,30,35,S_,0);
        
        ST7529_printf(sBQ_CAPACIDAD,10,45,S_,0);
        sprintf(mystring,"%Ld/%Ld mAh",getRemaining(),getCapacity());    // Obtenci�n de la capacidad restante / total de la bateria
        ST7529_printf(mystring,30,45,S_,0);
        
        ST7529_printf(sBQ_PORCENTAJE,10,55,S_,0);
        sprintf(mystring,"%u %%",nivelBateria());                      // Porcentaje del nivel de bater�a restante
        ST7529_printf(mystring,30,55,S_,0);
        
        if(estadoCarga()){                                                         // indica si el equipo est� conectado a la red el�ctrica
            i8RepVal1=sDESCONECTADA;
        }else{
            i8RepVal1=sCONECTADA;
        }
        ST7529_printf(i8RepVal1,10,65,S_,0);
        
        ST7529_printf(sBQ_TEMPERATURA,10,75,S_,0);
        sprintf(mystring,"Temperature: %3.1w C",getTemp());                        // Obtenci�n de la temperatura del sensor de temperatura interno (o externo?)
        ST7529_printf(mystring,10,75,S_,0);
        //sprintf(mystring,"Flags:   0x%LX",getFlags());                             // Obtenci�n de los flags de control
        //ST7529_printf(mystring,10,85,S_,0);
        //sprintf(mystring,"FlagsB:  0x%LX",getFlagsB());                            // Obtenci�n de los flags de control
        //ST7529_printf(mystring,10,95,S_,0);
        ST7529_printf(sBQ_CICLOS,10,105,S_,0);
        sprintf(mystring,"Cycle Count:  %Lu",getCycleCount());                     // N�mero de ciclos de craga de la bater�a
        ST7529_printf(mystring,30,105,S_,0);
        
        sprintf(mystring,"ATTF: %Lu / ATTE: %Lu",getATTF(),getATTE());             // Average Time To Full / Average Time To Empty 
        ST7529_printf(mystring,10,115,S_,0);
        iMenuAnterior=iMenuActual;
    }
    
    bRefrescoPantalla=0;

    return 0;
}   

int8 menu_72(){                      // Test COMUNICACION ENTRE PIC�S 
    if(bRefrescoPantalla){
        ST7529_clear();                                 // Se ha eliminado la condici�n IF porque quiero que siempre limipe la pantalla
        ST7529_printf(sTEST_CPIC,0,0,L_,NORMAL);
        pantalla_seleccion();
        giPos=0;
        
        ST7529_printf(sTODO,10,25,M_,NORMAL);

        //TODO    

    }

    bRefrescoPantalla=0;

    return 0;
} 

int8 menu_73(){                      // Test CHA
    if(bRefrescoPantalla){
        ST7529_clear();                                 // Se ha eliminado la condici�n IF porque quiero que siempre limipe la pantalla
        ST7529_printf(sTEST_CPIC,0,0,L_,NORMAL);
        pantalla_seleccion();
        giPos=0;
        
        ST7529_printf(sTODO,10,25,M_,NORMAL);

        //TODO    

    }

    bRefrescoPantalla=0;
    
    return 0;
} 

int8 menu_74(){                      // Test CHB 
    if(bRefrescoPantalla){
        ST7529_clear();                                 // Se ha eliminado la condici�n IF porque quiero que siempre limipe la pantalla
        ST7529_printf(sTEST_CPIC,0,0,L_,NORMAL);
        pantalla_seleccion();
        giPos=0;
        
        ST7529_printf(sTODO,10,25,M_,NORMAL);

        //TODO    

    }

    bRefrescoPantalla=0;
    
    return 0;
} 

int8 menu_75(){                      // Test CHC 
    if(bRefrescoPantalla){
        ST7529_clear();                                 // Se ha eliminado la condici�n IF porque quiero que siempre limipe la pantalla
        ST7529_printf(sTEST_CPIC,0,0,L_,NORMAL);
        pantalla_seleccion();
        giPos=0;
         
        ST7529_printf(sTODO,10,25,M_,NORMAL);

        //TODO    

    }

    bRefrescoPantalla=0;
    
    return 0;
} 

// Muestra que canales deben de ser configurados
int8 menu_91(){
    if(bRefrescoPantalla){                          // Si se ha cambiado alg�n valor
        if(iMenuAnterior!=91){                      // Si venimos de otro men�
            ST7529_clear();                         // Limpio pantalla
            ST7529_printf(sPRESETS,0,0,L_,NORMAL);  // Muestra este titulo
            ST7529_printf(sSELEC_TITULO,10,36,L_,NORMAL);  // Muestra este titulo
            giPos=0;
        }
        
        pantalla_seleccion();                       // Muestro iconos
        poner_cargar();
        
        if(giPos<=SEL_CANAL_A){                                   // Si el valor de selecci�n es menor o igual a SEL_CANAL_A
            giPos=SEL_CANAL_A;                                    // Inicializo giPos
        }
        
        if(giPos>SEL_CANAL_ABC){                                    // Si el valor de selecci�n es mayor que SEL_CANAL_ABC
            giPos=SEL_CANAL_ABC;                                    // Inicializo giPos al m�ximo
        }
        
        ST7529_printf(sSELEC_CANAL_A+giPos,12,70,M_,NORMAL);  // Muestra los canales a configurar
        
        iMenuAnterior=iMenuActual;
    }
    
    bRefrescoPantalla=0;                // Inicializo flag de refresco

    return 0;                           // Return 0
}

// Guardar presets
int8 menu_92(){
    if(bRefrescoPantalla){                          // Si se ha cambiado alg�n valor
        if(iMenuAnterior!=92){                      // Si venimos de otro men�
            ST7529_clear();                         // Limpio pantalla
            ST7529_printf(sPRESETS,0,0,L_,NORMAL);  // Muestra este titulo
            giPos=0;
        }
        
        pantalla_seleccion();                       // Muestro iconos
        //quitar_flecha_der();
        poner_guardar();
        
        if(giPos<=0){                                   // Si el valor de selecci�n es menor o igual a 0
            giPos=0;                                    // Inicializo giPos
        }
        
        if(giPos>9){                                    // Si el valor de selecci�n es mayor que 5
            giPos=9;                                    // Inicializo giPos al m�ximo
        }

        representacionPresets();
    
        iMenuAnterior=iMenuActual;
    }
    
    bRefrescoPantalla=0;                // Inicializo flag de refresco

    return 0;                           // Return 0
}


// Pantalla de inicio tratamiento Galvanica + microcorrientes
int8 menu_120(){
    if(bRefrescoPantalla){
        int8 i8Time_min, i8Time_seg;      // Variables utilizadas para la asignaci�n de tiempo
        
        gI=50;
        
        if(iMenuAnterior==20){      // Si viene del men� de configuraci�n debe de inicializar algunas variables
            bTerapia=0;
        }
        
        // Revisar este trozo en error de electrodo!
        if(!bTerapia){
            if(iMenuAnterior==123){
                ST7529_clear();       
                
                // Solo en el caso de galv�nica quiero que vuelva a recargar los valores de tiempo configurados
                if(!bTerapia){
                    if(i16TGalv[bSeleccionGalvanica]==0){
                        i16TimeRaw[0]=i16TGalv[bSeleccionGalvanica];
                    }else{
                        i16TimeRaw[0]=i16TGalv[bSeleccionGalvanica]+i8TrampaGalv[bSeleccionGalvanica];
                    }
                    Calc_representacion_t(i16TimeRaw[0],0);
                    //sprintf(mystring2,"%06lu",(i32CGalv+i16CRampaGalv));
                    sprintf(mystring2,"%7lu",0); // Ahora se  quiere que la carga sea acumulativa
                    
                    giPos=i16IGalv[bSeleccionGalvanica];
                }else{
                    giPos=i16Imicro;
                }

                i16IMedGalv=0;
                i16VMedGalv=0;
                i16ResGalv=0; 
                
                structMedidasGalvanica.si16IMedGalv=i16IMedGalv;
                structMedidasGalvanica.si16ResGalv=i16ResGalv; 
                structMedidasGalvanica.si16VMedGalv=i16VMedGalv;
            }
        }

        if((iMenuAnterior==123 || iMenuAnterior==121) && iMenuActual==120){
            ST7529_clear();
        }
        if(bRefrescoPantalla){
            pantalla_seleccion();
        }
        if(iMenuActual!=123){        // Si no hay error de electrodo
            controlSonido(0);
            if(iMenuActual==120){
                i16IMedGalv=0;
                i16VMedGalv=0;
                i16ResGalv=0; 
                
                structMedidasGalvanica.si16IMedGalv=i16IMedGalv;
                structMedidasGalvanica.si16ResGalv=i16ResGalv; 
                structMedidasGalvanica.si16VMedGalv=i16VMedGalv;
                
                if(!bPausaTratamiento){
                    i32CargaGalvanicaRestante=i32CGalv+i16CRampaGalv;
                }
                i16DecrementoCargaGalvanica=i16IGalv[bSeleccionGalvanica]*50;
            }
            
            if(iMenuAnterior==120 && iMenuActual==121){
                controlSonido(1);
                pausa_ms(200);
            }
            
            if(iMenuAnterior!=120 && iMenuAnterior!=121){           // Si es la primera vez que entramos en el men� o volvemos de un error de electrodo
                ST7529_clear();                                     // Limpia la pantalla
                
                // Solo en el caso de galv�nica quiero que vuelva a recargar los valores de tiempo configurados
                if(!bTerapia){                                          // Si estamos en terapia galvanica
                    if(i16TGalv[bSeleccionGalvanica]==0){
                        i16TimeRaw[0]=i16TGalv[bSeleccionGalvanica];
                    }else{
                        i16TimeRaw[0]=i16TGalv[bSeleccionGalvanica]+i8TrampaGalv[bSeleccionGalvanica];
                    }
                    Calc_representacion_t(i16TimeRaw[0],0);
                    //sprintf(mystring2,"%06lu",(i32CGalv+i16CRampaGalv));
                    sprintf(mystring2,"%7lu",0); // Muestra el valor de carga, lo pone a cero (ahora es acumulativa)
                    
                    giPos=i16IGalv[bSeleccionGalvanica];             // Asigna el valor de correinte galvanica a giPos
                }else{
                    giPos=i16Imicro;            // Asigna el valor de microcorrintes a giPos
                }
           
                pantalla_seleccion();
                
                // Si habia ocurrido un error de electrodo en galvanica, el tratamiento se para 
                // pero debe de dibujar todo de nuevo y cargar los valores por defecto
                //if((iMenuAnterior==123 && (TRATAMIENTO_GALVANICA == i8TratamientoSeleccionado)) || (iMenuAnterior!=120 && iMenuAnterior!=121 && iMenuAnterior!=123)){
                
                if((iMenuAnterior!=120 && iMenuAnterior!=121 && iMenuAnterior!=123)){  // Si viene del men� de configuracion (menu_20)
                    
                    // Envia los datos de configuraci�n a Orco
                    // Set configuraci�n del tratamiento - Galv�nica
                    structTratamientoGalvanica.si32CGalv=i32CGalv+i16CRampaGalv;
                    structTratamientoGalvanica.si16IGalv=i16IGalv[bSeleccionGalvanica];
                    structTratamientoGalvanica.si8TrampaGalv=i8TrampaGalv[bSeleccionGalvanica];
                    
                    // Set configuraci�n del tratamiento - Microcorrientes
                    structTratamientoGalvanica.si16Imicro=i16Imicro;
                    structTratamientoGalvanica.si16PWmicro=i16PWmicro;
                    structTratamientoGalvanica.si8Trampamicro=i8Trampamicro;
                    structTratamientoGalvanica.si16frecmicro=i16frecmicro;
                    structTratamientoGalvanica.sbPolaridadMicro=bPolaridadMicro;
                    
                    // Carga de datos para el autocalculado del tiempo de tratamiento
                    i32CargaGalvanicaRestante=i32CGalv+i16CRampaGalv;
                    i16DecrementoCargaGalvanica=i16IGalv[bSeleccionGalvanica]*50;

                    i8ErrorCom=0;                                                                       // Inicializa el valor del contador de errores
                    
                    configuraDatos(MODO_TRAT_GALV);                                                  // Envia comando

                    i8TratamientoSeleccionado=TRATAMIENTO_GALVANICA;
                    
                    structTratamientoGalvanicaActivo.si16IGalv=0;
                    
                    // Inicializamos algunos valores
                    i16IMedGalv=0;
                    i16VMedGalv=0;
                    i16ResGalv=0; 
                    
                    structMedidasGalvanica.si16IMedGalv=i16IMedGalv;
                    structMedidasGalvanica.si16ResGalv=i16ResGalv; 
                    structMedidasGalvanica.si16VMedGalv=i16VMedGalv;
                }
            }
            
            if(iMenuAnterior==22){
                if(i16TGalv[bSeleccionGalvanica]!=0){
                    if((float)i8TrampaGalv[bSeleccionGalvanica]>=(i16TGalv[bSeleccionGalvanica]/3.0)){
                        i8TrampaGalv[bSeleccionGalvanica]=(i16TGalv[bSeleccionGalvanica]/3);
                    }
                }
                if(i8TrampaGalv[bSeleccionGalvanica]>=10){
                    i8TrampaGalv[bSeleccionGalvanica]=10;
                }
            }
            
            if(iMenuAnterior==121 && iMenuActual==120){
                if(bPausaTratamiento){
                    if(bTerapia){
                        giPos=i16Imicro;
                    }else{
                        giPos=i16IGalv[bSeleccionGalvanica];
                    }
                }else{
                    giPos=i16IGalv[bSeleccionGalvanica];
                }
            }
            /*
            // Si el men� anterior es la pantalla de tratamiento y el tratamiento de galvanica no est� activado 
            if(!bPausaTratamiento && iMenuAnterior==120 && !bTratamientoGalvanicaActivado){
                // Asigno el valor de corriente galv�nica a giPos
                //giPos=i16IGalv[bSeleccionGalvanica];
            }*/
            
            // Si inicio el tratamiento o me recupero de un error de electrodo en microcorrinetes
            if((iMenuAnterior==120 && iMenuActual==121) || (iMenuAnterior==123 && iMenuActual==121)){
                // Quito botones innecesarios
                quitar_cancelar();
                quitar_config();
            }
            
            // Si para el tratamiento
            if(iMenuAnterior==121 && iMenuActual==120){
                // Pongo botones necesarios
                poner_cancelar();
            }
            
            // Limites de valores de terapia
            if ((giPos>=200)&&(bTerapia==0)){ // Si estamos en terapia de galvanica
                giPos=200;                      //200*50 = 10000uA
            }

            if ((giPos>=200)&&(bTerapia==1)){   // Si estamos en terapia de microcorrientes
                giPos=200;                       //200*50 = 10000uA 
            }
            
            if(giPos<=2){
                giPos=2;
            }
            
            // Si estamos en tratamiento de galvanica
            if(iMenuActual==121 && !bTerapia){
                // Asigno corriente a galvanica
                i16IGalv[bSeleccionGalvanica]=giPos;
            }else if(iMenuActual==121 && bTerapia){     // Si estamos en tratamiento de micrococrriemtes
                // asigno correinte a microcorrientes
                i16Imicro=giPos;
            }
        
            // Dependiendo del tratamiento activo, muestra un nombre u otro
            if(!bTerapia){
                ST7529_printf(sGALV,0,0,L_,NORMAL); 
            }else{
                ST7529_printf(sMICRO_CORRIENTES,0,0,L_,NORMAL); 
            }

            sprintf(mystring1,"%5lu",redondeoI_50(i16IMedGalv));        
            ST7529_printf(mystring1,0,40,XL_,0);
            ST7529_printf(sINTENSIDAD,2,26,S_,0);
            ST7529_printf("[A",36,55,S_,0);
            
            // Mostrar carga al iniciar uC??
            if(!bTerapia){
                sprintf(mystring2,"           ");
                ST7529_printf(mystring2,41,26,M_,0);
                sprintf(mystring2,"           ");
                ST7529_printf(mystring2,41,44,M_,0);
                ST7529_printf(sCARGA,41,26,S_,0);
                sprintf(mystring2,"%7lu",(i16CRampaGalv+i32Cgalv)-i32CargaGalvanicaRestante);
                ST7529_printf("[Q",68,55,S_,0);
                ST7529_printf(mystring2,45,44,L_,0);
            }else{
                ST7529_printf("     ",41,26,S_,0);
                sprintf(mystring2,"       ");
                ST7529_printf(mystring2,45,44,L_,0);
                ST7529_printf("  ",68,55,S_,0);
                sprintf(mystring2,"PW: %4lu [S",i16PWmicro);
                ST7529_printf(mystring2,41,26,M_,0);
                sprintf(mystring2,"F: %5lu Hz",i16frecmicro);
                ST7529_printf(mystring2,41,44,M_,0);
            }
            
            Calc_representacion_t(i16TimeRaw[0],0);
            
            ST7529_printf(sTIEMPO,2,80,S_,0);
            sprintf(mystring,"%2u:%02u",i8Tmin,i8Tseg);
            ST7529_printf(mystring,0,94,XL_,0);
            
            i16IMedGalv=structMedidasGalvanica.si16IMedGalv;
            i16VMedGalv=structMedidasGalvanica.si16VMedGalv;
            i16ResGalv=structMedidasGalvanica.si16ResGalv;
            
            if(bTerapia){
                if(bPolaridadMicro){
                    i8RepVal1=sBIPOLAR;
                }else{
                    i8RepVal1=sMONOPOLAR;
                }
                ST7529_printf(i8RepVal1,44,75,S_,0);
            }
            
            ST7529_printf(sINTENSIDAD_SET,44,85,S_,0);
            sprintf(mystring,"%5LU [A",giPos*gI);
            ST7529_printf(mystring,57,85,S_,0);
            ST7529_printf(sVMED,44,95,S_,0);
            sprintf(mystring,"%5LU mV",i16VMedGalv);
            ST7529_printf(mystring,57,95,S_,0);
            ST7529_printf(sRMED,44,105,S_,0);
            sprintf(mystring,"%5LU ohm",i16ResGalv);
            ST7529_printf(mystring,57,105,S_,0);
            
            if(i16VMedGalv>=10000){ // Si la tensi�n de salida es superior a 10 voltios (HV)
                ST7529_printf(sHIGH_VOLTAGE,70,63,L_,0);
            }else{
                ST7529_printf(sHIGH_VOLTAGE_VACIO,70,63,L_,0);
            }
            iMenuAnterior=iMenuActual;
            controlSonido(0);
        }else{       // Si hay error de electrodo, debe de para el tratamiento
        
            if (iMenuAnterior!=123){
                ST7529_clear();
            }
            
            Calc_representacion_t(i16TimeRaw[0],0);                           // C�lcula de nuevo la representaci�n del tiempo
            
            i8Time_min=i8Tmin;                                                         // Recarga de nuevo las variables para usarlas de nuevo en el caso de error de electrodo
            i8Time_seg=i8Tseg;            
            ControlSonido(1);    
            
            if(!bTerapia){
                ST7529_printf(sGALV,0,0,L_,NORMAL);
            }else{
                ST7529_printf(sMICRO_CORRIENTES,0,0,L_,NORMAL);
            }
            
            ST7529_printf(sERROR_ELECTRODO,10,50,L_,NORMAL);
            //sprintf(mystring,"%02u:%02u",i8Time_min,i8Time_seg);
            //ST7529_printf(mystring,32,112,L_,0);
            if(!bTerapia){
                control_rele(0,rele_GALV);                              // Apagado rele galvanica
                pausa_ms(1500);
                ControlSonido(0);
                iMenuActual=120;
                apagadoGalvanica();
                ST7529_clear();
            }else{
                ST7529_printf(sTACTIVO,29,85,S_,0);

                sprintf(mystring,"%2u:%02u",i8Time_min,i8Time_seg);
                ST7529_printf(mystring,30,95,L_,0);
            }
            
            iMenuAnterior=iMenuActual;
            
        }   // Cierre if error de electrodo
    }

    bRefrescoPantalla=0;

    return 0;
}

// Pantalla de inicio tratamiento Transcraneal
int8 menu_130(){
    if(bRefrescoPantalla){
        int8 i8Time_min, i8Time_seg;      // Variables utilizadas para la asignaci�n de tiempo
        
        gI=50;
        
        if(iMenuAnterior==30){      // Si viene del men� de configuraci�n debe de inicializar algunas variables
            bTerapia=0;
        }
    
        if(iMenuAnterior==133){
            ST7529_clear();       
            
            if(i16Ttrans==0){
                i16TimeRaw[0]=i16Ttrans;
            }else{
                i16TimeRaw[0]=i16Ttrans+i8TrampaTrans;
            }
            Calc_representacion_t(i16TimeRaw[0],0);

            sprintf(mystring2,"%7lu",0); // Ahora se  quiere que la carga sea acumulativa
            
            giPos=i16Itrans;


            i16IMedTrans=0;
            i16VMedTrans=0;
            i16ResTrans=0; 
            
            structMedidasGalvanica.si16IMedGalv=i16IMedTrans;
            structMedidasGalvanica.si16ResGalv=i16ResTrans; 
            structMedidasGalvanica.si16VMedGalv=i16VMedTrans;
        }

        if((iMenuAnterior==133 || iMenuAnterior==131) && iMenuActual==130){
            ST7529_clear();
        }
        
        if(bRefrescoPantalla){
            pantalla_seleccion();
        }
        
        if(iMenuActual!=133){        // Si no hay error de electrodo
            controlSonido(0);
            if(iMenuActual==130){
                i16IMedTrans=0;
                i16VMedTrans=0;
                i16ResTrans=0; 
                
                structMedidasGalvanica.si16IMedGalv=i16IMedTrans;
                structMedidasGalvanica.si16ResGalv=i16ResTrans; 
                structMedidasGalvanica.si16VMedGalv=i16VMedTrans;
                
                if(!bPausaTratamiento){
                    i32CargaTranscranealRestante=i32CTrans+i16CRampaTrans;
                }
                i16DecrementoCargaTranscraneal=i16ITrans*50;
            }
            
            if(iMenuAnterior==130 && iMenuActual==131){
                controlSonido(1);
                pausa_ms(200);
            }
            
            if(iMenuAnterior!=130 && iMenuAnterior!=131){           // Si es la primera vez que entramos en el men� o volvemos de un error de electrodo
                ST7529_clear();                                     // Limpia la pantalla
                

                if(i16TTrans==0){
                    i16TimeRaw[0]=i16TTrans;
                }else{
                    i16TimeRaw[0]=i16TTrans+i8TrampaTrans;
                }
                Calc_representacion_t(i16TimeRaw[0],0);
                //sprintf(mystring2,"%06lu",(i32CGalv+i16CRampaGalv));
                sprintf(mystring2,"%7lu",0); // Muestra el valor de carga, lo pone a cero (ahora es acumulativa)
                
                giPos=i16ITrans;             // Asigna el valor de correinte galvanica a giPos

                pantalla_seleccion();
                
                // Si habia ocurrido un error de electrodo en galvanica, el tratamiento se para 
                // pero debe de dibujar todo de nuevo y cargar los valores por defecto
                //if((iMenuAnterior==123 && (TRATAMIENTO_GALVANICA == i8TratamientoSeleccionado)) || (iMenuAnterior!=120 && iMenuAnterior!=121 && iMenuAnterior!=123)){
                if((iMenuAnterior!=130 && iMenuAnterior!=131 && iMenuAnterior!=133)){  // Si viene del men� de configuracion (menu_20)
                    // Envia los datos de configuraci�n a Orco
                    // Set configuraci�n del tratamiento - Galv�nica
                    structTratamientoGalvanica.si32CGalv=i32CTrans+i16CRampaTrans;
                    structTratamientoGalvanica.si16IGalv=i16ITrans;
                    structTratamientoGalvanica.si8TrampaGalv=i8TrampaTrans;
                    
                    // Set configuraci�n del tratamiento - Microcorrientes
                    structTratamientoGalvanica.si16Imicro=0;
                    structTratamientoGalvanica.si16PWmicro=0;
                    structTratamientoGalvanica.si8Trampamicro=0;
                    structTratamientoGalvanica.si16frecmicro=0;
                    structTratamientoGalvanica.sbPolaridadMicro=0;
                    
                    // Carga de datos para el autocalculado del tiempo de tratamiento
                    i32CargaTranscranealRestante=i32CTrans+i16CRampaTrans;
                    i16DecrementoCargaTranscraneal=i16ITrans*50;

                    i8ErrorCom=0;                                                                       // Inicializa el valor del contador de errores
                    
                    configuraDatos(MODO_TRAT_GALV);                                                  // Envia comando

                    i8TratamientoSeleccionado=TRATAMIENTO_TRANSCRANEAL;
                    
                    structTratamientoGalvanicaActivo.si16IGalv=0;
                    
                    // Inicializamos algunos valores
                    i16IMedTrans=0;
                    i16VMedTrans=0;
                    i16ResTrans=0; 
                    
                    structMedidasGalvanica.si16IMedGalv=i16IMedTrans;
                    structMedidasGalvanica.si16ResGalv=i16ResTrans; 
                    structMedidasGalvanica.si16VMedGalv=i16VMedTrans;
                }
            }
            
            if(iMenuAnterior==22){
                if(i16TTrans!=0){
                    if((float)i8TrampaTrans>=(i16TTrans/3.0)){
                        i8TrampaTrans=(i16TTrans/3);
                    }
                }
                if(i8TrampaTrans>=10){
                    i8TrampaTrans=10;
                }
            }
            
            if(iMenuAnterior==131 && iMenuActual==130){
                giPos=i16ITrans;
            }
            /*
            // Si el men� anterior es la pantalla de tratamiento y el tratamiento de galvanica no est� activado 
            if(!bPausaTratamiento && iMenuAnterior==120 && !bTratamientoGalvanicaActivado){
                // Asigno el valor de corriente galv�nica a giPos
                //giPos=i16IGalv[bSeleccionGalvanica];
            }*/
            
            // Si inicio el tratamiento o me recupero de un error de electrodo en microcorrinetes
            if((iMenuAnterior==130 && iMenuActual==131) || (iMenuAnterior==133 && iMenuActual==131)){
                // Quito botones innecesarios
                quitar_cancelar();
                quitar_config();
            }
            
            // Si para el tratamiento
            if(iMenuAnterior==131 && iMenuActual==130){
                // Pongo botones necesarios
                poner_cancelar();
            }
            
            // Limites de valores de terapia
            if(limiteDensidadCorriente(LIMIT_CORRIENTE)){
                max=i16Itrans;
            }else{
                max=MAXIMA_CORRIENTE_TRANSCRANEAL;
            }
            
            if (giPos>=max){ // Si estamos en terapia
                giPos=max;                   
            }
            
            if(giPos<=2){
                giPos=2;
            }
            
            // Si estamos en tratamiento de galvanica
            if(iMenuActual==131){
                // Asigno corriente a galvanica
                i16ITrans=giPos;
            }
        
            // Dependiendo del tratamiento activo, muestra un nombre u otro
            ST7529_printf(sTRANS,0,0,L_,NORMAL); 

            sprintf(mystring1,"%5lu",redondeoI_50(i16IMedTrans));        
            ST7529_printf(mystring1,0,40,XL_,0);
            ST7529_printf(sINTENSIDAD,2,26,S_,0);
            ST7529_printf("[A",36,55,S_,0);
            
            // Mostrar carga al iniciar uC?
            sprintf(mystring2,"           ");
            ST7529_printf(mystring2,41,26,M_,0);
            sprintf(mystring2,"           ");
            ST7529_printf(mystring2,41,44,M_,0);
            ST7529_printf(sCARGA,41,26,S_,0);
            sprintf(mystring2,"%7lu",(i16CRampaTrans+i32CTrans)-i32CargaTranscranealRestante);
            ST7529_printf("[Q",68,55,S_,0);
            ST7529_printf(mystring2,45,44,L_,0);
            
            Calc_representacion_t(i16TimeRaw[0],0);
            
            ST7529_printf(sTIEMPO,2,80,S_,0);
            sprintf(mystring,"%2u:%02u",i8Tmin,i8Tseg);
            ST7529_printf(mystring,0,94,XL_,0);
            
            i16IMedTrans=structMedidasGalvanica.si16IMedGalv;
            i16VMedTrans=structMedidasGalvanica.si16VMedGalv;
            i16ResTrans=structMedidasGalvanica.si16ResGalv;
            
            ST7529_printf(sINTENSIDAD_SET,42,85,S_,0);
            sprintf(mystring,"%5LU [A",giPos*gI);
            ST7529_printf(mystring,55,85,S_,0);
            ST7529_printf(sVMED,42,95,S_,0);
            sprintf(mystring,"%5LU mV",i16VMedTrans);
            ST7529_printf(mystring,55,95,S_,0);
            ST7529_printf(sRMED,42,105,S_,0);
            sprintf(mystring,"%5LU ohm",i16ResTrans);
            ST7529_printf(mystring,55,105,S_,0);
            sprintf(mystring,"j = %3lu [A/cm]",i32DensidadCorriente);              
            ST7529_printf(mystring,42,115,S_,0);           
            
            if(i16VMedTrans>=10000){ // Si la tensi�n de salida es superior a 10 voltios (HV)
                ST7529_printf(sHIGH_VOLTAGE,70,63,L_,0);
            }else{
                ST7529_printf(sHIGH_VOLTAGE_VACIO,70,63,L_,0);
            }
            
            iMenuAnterior=iMenuActual;
            controlSonido(0);
        }else{       // Si hay error de electrodo, debe de para el tratamiento
        
            if (iMenuAnterior!=133){
                ST7529_clear();
            }
            
            Calc_representacion_t(i16TimeRaw[0],0);                           // C�lcula de nuevo la representaci�n del tiempo
            
            i8Time_min=i8Tmin;                                                         // Recarga de nuevo las variables para usarlas de nuevo en el caso de error de electrodo
            i8Time_seg=i8Tseg;            
            ControlSonido(1);    
            
            ST7529_printf(sTRANS,0,0,L_,NORMAL);
            
            ST7529_printf(sERROR_ELECTRODO,10,50,L_,NORMAL);
            //sprintf(mystring,"%02u:%02u",i8Time_min,i8Time_seg);
            //ST7529_printf(mystring,32,112,L_,0);

            control_rele(0,rele_GALV);                              // Apagado rele galvanica
            pausa_ms(1500);
            ControlSonido(0);
            iMenuActual=130;
            //apagadoGalvanica();
            apagadoTranscraneal();
            ST7529_clear();
            
            iMenuAnterior=iMenuActual;
            
        }   // Cierre if error de electrodo
    }

    bRefrescoPantalla=0;

    return 0;
}

// Pantalla de inicio electroestimulacion
int8 menu_140(){
    if(bRefrescoPantalla){
        int8 i8Time_min, i8Time_seg, i8Time1_min, i8Time1_seg;      // Variables utilizadas para la asignaci�n de tiempo
        
        //if ((!bErrorElectrodoA)&&(!bErrorElectrodoB))
        if(iMenuActual!=143){               // Si no hay error de electrodo
            //if(iMenuAnterior==140 && imenuActual==141){
            //   controlSonido(1);
            //}else{
            controlSonido(0);
            //}
            gI=50;                          // Variable de escalado de la corriente

            if(iMenuAnterior!=140 && iMenuAnterior!=141 && iMenuAnterior!=142){                // Si es la primera vez que entra al menu de terapia
                ST7529_clear();                                                                 // Limpio la pantalla
                ST7529_printf(sELECTRO_ESTIMULACION,0,0,L_,NORMAL);                            // Pongo el t�tulo del men�

                if (iMenuAnterior!=143){                                                        // Si vengo de error electrodo no reinicio variables de tiempo
                    if(!(iMenuAnterior==40 && (iMenuActual==141 || iMenuActual==142))){
                        i16TimeRaw[i8ConfigCanal]=i16TacElec[i8ConfigCanal]+i8TrElec[i8ConfigCanal];                                                      // Asignacion tiempo activo a variable que se puede modificar sin machacar
                        i16TimeRepRaw[i8ConfigCanal]=i16TdElec[i8ConfigCanal];                                                    // Asignacion tiempo reposo a variable que se puede modificar sin machacar
                        i8NrepRaw[i8ConfigCanal]=i8Nrep[i8ConfigCanal];                                                           // Asignacion repeticiones a variable que se puede modificar sin machacar
                    }
                }
                pantalla_seleccion();                                                           // A�ado botones control
                
                if (iMenuAnterior!=143){ 
                    if(!(iMenuAnterior==40 && (iMenuActual==141 || iMenuActual==142))){
                        // Envio de los datos
                        // Una vez ha pintado todo el men�, procedemos a enviar el paquete con los datos configurados en el men� 40
                        // Preparo paquete de datos
                        structTratamientoElectro.si8CanalesConfigurados=i8CanalesConfigurados;
                        structTratamientoElectro.si8ConfigCanal=i8ConfigCanal;
                        structTratamientoElectro.si8SimetriaCanales=i8SimetriaCanales;
                        structTratamientoElectro.sbSimetriaElec=bSimetriaElec[i8ConfigCanal];
                        structTratamientoElectro.sbPolaridadElec=bPolaridadElec[i8ConfigCanal];
                        structTratamientoElectro.si16TacElec=i16TacElec[i8ConfigCanal];
                        structTratamientoElectro.si16TdElec=i16TdElec[i8ConfigCanal];
                        structTratamientoElectro.si16TfElec12=i16TfElec12;
                        structTratamientoElectro.si16TfElec23=i16TfElec23;
                        structTratamientoElectro.si8TrElec=i8TrElec[i8ConfigCanal];
                        structTratamientoElectro.si8Nrep=i8Nrep[i8ConfigCanal];
                        structTratamientoElectro.si16IElec=i16IElec[i8ConfigCanal];
                        structTratamientoElectro.si16FrecElec=i16FrecElec[i8ConfigCanal];
                        structTratamientoElectro.si16PW_plusElec=i16PW_plusElec[i8ConfigCanal];
                        structTratamientoElectro.si16PW_minusElec=i16PW_minusElec[i8ConfigCanal];
                        structTratamientoElectro.si8Checksum=0;           
               
                        i8ErrorCom=0;                                                                       // Inicializa el valor del contador de errores
                        
                        configuraDatos(MODO_TRAT_ELECT);                                                  // Envia comando
            
                        i8TratamientoSeleccionado=TRATAMIENTO_ELECTRO;
                        
                        // inicializacion de los valores de tratamiento activo
                        // Estos valore sno hayque enviarlos, simplemente es para inicializar esas variables
                        structTratamientoElectroActivo.si16IElec=i16IElec[i8ConfigCanal];
                        
                        structMedidasElectro.sbMAX[i8ConfigCanal]=0;
                        structMedidasElectro.sbCC[i8ConfigCanal]=0;
                        
                        giPos=i16IElec[i8ConfigCanal];
                    }
                }
            }       // Cierre if primera vez en el men�
           
            Calc_representacion_t(i16TimeRaw[i8ConfigCanal],i16TimeRepRaw[i8ConfigCanal]); 
            
            /*switch(iMenuActual){
                case 140:
                    poner_flecha_izq();
                    break;
                case 141:
                    quitar_flecha_izq();
                    break;
            }*/
            if(!bPointerSeleccionado){
                ST7529_printf(sA,3,FILA_INIT-8,L_,i8ConfigCanal==0);
            }else{
                ST7529_printf(sP,3,FILA_INIT-8,L_,i8ConfigCanal==3);
            }
            ST7529_printf(sB,29,FILA_INIT-8,L_,i8ConfigCanal==1);
            ST7529_printf(sC,53,FILA_INIT-8,L_,i8ConfigCanal==2);  
           
            sprintf(mystring,"F= %4LU Hz",i16frecElec[i8ConfigCanal]);
            ST7529_printf(mystring,24,40,L_,0);
            
           //sprintf(mystring,"Isel= %05lu [A",i16IElec[i8ConfigCanal]*50);
           
            i16IMedElec=redondeoI_100(structMedidasElectro.si16IMedElec[i8ConfigCanal][PULSO_POS]);
            
            if(i8CanalesActivados&(1<<i8ConfigCanal)){
                if(i16IMedElec!=(i16IElec[i8ConfigCanal]*50)){
                    sprintf(mystring,"Imed= %5lu [A",i16IMedElec);
                    ST7529_printfg(mystring,20,54,L_,ai8EscalaGrises[1],0);
                    sprintf(mystring,"Iset= %5lu [A",i16IElec[i8ConfigCanal]*50);
                    ST7529_printfg(mystring,20,72,M_,ai8EscalaGrises[0],0);
                }else{
                    sprintf(mystring,"Imed= %5lu [A",i16IMedElec);
                    ST7529_printfg(mystring,20,54,L_,ai8EscalaGrises[0],0);
                    sprintf(mystring,"              ");
                    ST7529_printfg(mystring,20,72,M_,ai8EscalaGrises[0],0);
                }
            }else{
                sprintf(mystring,"Imed= %5lu [A",0);
                ST7529_printfg(mystring,20,54,L_,ai8EscalaGrises[0],0);
                sprintf(mystring,"              ");
                ST7529_printfg(mystring,20,72,M_,ai8EscalaGrises[0],0);
            }
           
            i16ResElec[CHA_C]=((int32)structMedidasElectro.si16VMedElec[CHA_C][PULSO_POS]*1000)/structMedidasElectro.si16IMedElec[CHA_C][PULSO_POS];
            i16ResElec[CHB_C]=((int32)structMedidasElectro.si16VMedElec[CHB_C][PULSO_POS]*1000)/structMedidasElectro.si16IMedElec[CHB_C][PULSO_POS];
            i16ResElec[CHC_C]=((int32)structMedidasElectro.si16VMedElec[CHC_C][PULSO_POS]*1000)/structMedidasElectro.si16IMedElec[CHC_C][PULSO_POS];
            i16ResElec[POINTER_C]=((int32)structMedidasElectro.si16VMedElec[POINTER_C][PULSO_POS]*1000)/structMedidasElectro.si16IMedElec[POINTER_C][PULSO_POS];
            
            if(i8CanalesActivados&(1<<i8ConfigCanal)){
                sprintf(mystring,"Rmed= %5LU ohm",i16ResElec[i8ConfigCanal]);
                ST7529_printf(mystring,4,85,S_,0);  
                
                sprintf(mystring,"Vmed= %5LU mV",structMedidasElectro.si16VMedElec[i8ConfigCanal][PULSO_POS]);
                ST7529_printf(mystring,45,85,S_,0);
                
                if(structMedidasElectro.si16VMedElec[i8ConfigCanal][PULSO_POS]>=10000){ // Si la tensi�n de salida es superior a 10 voltios (HV)
                    ST7529_printf(sHIGH_VOLTAGE,70,45,L_,0);
                }else{
                    ST7529_printf(sHIGH_VOLTAGE_VACIO,70,45,L_,0);
                }
            }else{
                sprintf(mystring,"Rmed= %5LU ohm",0);
                ST7529_printf(mystring,4,85,S_,0);  
                
                sprintf(mystring,"Vmed= %5LU mV",0);
                ST7529_printf(mystring,45,85,S_,0);
            }
            
            if(i8ConfigCanal!=POINTER_C){
                sprintf(mystring,"  Ta %2u:%02u",i8Tmin,i8Tseg);
                ST7529_printf(mystring,4,96,S_,0);
               
                sprintf(mystring,"  Td %2u:%02u",i8T1min,i8T1seg);
                ST7529_printf(mystring,30,96,S_,0);
               
                sprintf(mystring,"  N %2u",i8NrepRaw[i8ConfigCanal]);
                ST7529_printf(mystring,56,96,S_,0);
            }else{
                sprintf(mystring,"              ");
                ST7529_printf(mystring,4,96,S_,0);
               
                sprintf(mystring,"PW = %lu [s",i16PW_plusElec[POINTER_C]);
                ST7529_printf(mystring,28,96,S_,0);
               
                sprintf(mystring,"        ");
                ST7529_printf(mystring,56,96,S_,0);
            }     
           
        }else{  // Si hay error de elctrodo
        
            if (iMenuAnterior!=143){
                ST7529_clear();
                controlSonido(1);
            }
            
            Calc_representacion_t(i16TimeRaw[i8ConfigCanal],i16TimeRepRaw[i8ConfigCanal]);                           // C�lcula de nuevo la representaci�n del tiempo
            i8Time_min=i8Tmin;                                                         // Recarga de nuevo las variables para usarlas de nuevo en el caso de error de electrodo
            i8Time_seg=i8Tseg;            
            i8Time1_min=i8T1min;
            i8Time1_seg=i8T1seg;
        
            ST7529_printf(sTACTIVO,10,85,S_,0);
            ST7529_printf(sTREPOSO,35,85,S_,0);      
            //ST7529_printf("N",60,85,S_,0);             
            ST7529_printf(sELECTRO_ESTIMULACION,0,0,L_,NORMAL);
            ST7529_printf(sERROR_ELECTRODO,10,50,L_,NORMAL);
            
            if(bErrorElectrodo[CHA_C]){
                ST7529_printf(sCHA_EE,10,64,L_,NORMAL);
            }
            if(bErrorElectrodo[CHB_C]){
                ST7529_printf(sCHB_EE,10,64,L_,NORMAL);
            }
            if(bErrorElectrodo[CHC_C]){
                ST7529_printf(sCHC_EE,10,64,L_,NORMAL);
            }

            sprintf(mystring,"%2u:%02u",i8Time_min,i8Time_seg);
            ST7529_printf(mystring,12,95,L_,0);
            sprintf(mystring,"%2u:%02u",i8Time1_min,i8Time1_seg);
            ST7529_printf(mystring,37,95,L_,0);
        }   // Cierre if error de electrodo

        // Representaci�n corrientes en tratamiento - Recuadro inferior de la pantalla
        ST7529_printf(sLINEA_SEPARACION,0,107,S_,0);
        //ST7529_printf(" ________________________________________________",0,107,S_,0);
        
        if(!bPointerSeleccionado){
            if(i8CanalesActivados&CHA_ACT){
                sprintf(mystring,"Ia=%5lu [A",redondeoI_50(structMedidasElectro.si16IMedElec[CHA_C][PULSO_POS]));
            }else{
                sprintf(mystring,"           ");
                structMedidasElectro.si16VMedElec[CHA_C][PULSO_POS]=0;
                structMedidasElectro.si16IMedElec[CHA_C][PULSO_POS]=0;
                i16ResElec[CHA_C]=0;
            }
            ST7529_printf(mystring,COLUMNA_IA,FILA_CORRIENTE,S_,(i8CanalesActivados&CHA_ACT) && (i8ConfigCanal==CHA_C));
        }else{
            if(i8CanalesActivados&POINTER_ACT){
                sprintf(mystring,"Ip=%5lu [A",redondeoI_50(structMedidasElectro.si16IMedElec[POINTER_C][PULSO_POS]));
            }else{
                sprintf(mystring,"           ");
                structMedidasElectro.si16VMedElec[POINTER_C][PULSO_POS]=0;
                structMedidasElectro.si16IMedElec[POINTER_C][PULSO_POS]=0;
                i16ResElec[POINTER_C]=0;
            }
            ST7529_printf(mystring,COLUMNA_IA,FILA_CORRIENTE,S_,(i8CanalesActivados&POINTER_ACT) && (i8ConfigCanal==POINTER_C));
        }
        
        if(i8CanalesActivados&CHB_ACT){
            sprintf(mystring,"Ib=%5lu [A",redondeoI_50(structMedidasElectro.si16IMedElec[CHB_C][PULSO_POS]));
        }else{
            sprintf(mystring,"           ");
            structMedidasElectro.si16VMedElec[CHB_C][PULSO_POS]=0;
            structMedidasElectro.si16IMedElec[CHB_C][PULSO_POS]=0;
            i16ResElec[CHB_C]=0;
        }
        ST7529_printf(mystring,COLUMNA_IB,FILA_CORRIENTE,S_,(i8CanalesActivados&CHB_ACT) && (i8ConfigCanal==CHB_C));
        
        if(i8CanalesActivados&CHC_ACT){
            sprintf(mystring,"Ic=%5lu [A",redondeoI_50(structMedidasElectro.si16IMedElec[CHC_C][PULSO_POS]));
        }else{
            sprintf(mystring,"           ");
            structMedidasElectro.si16VMedElec[CHC_C][PULSO_POS]=0;
            structMedidasElectro.si16IMedElec[CHC_C][PULSO_POS]=0;
            i16ResElec[CHC_C]=0;
        }
        ST7529_printf(mystring,COLUMNA_IC,FILA_CORRIENTE,S_,(i8CanalesActivados&CHC_ACT) && (i8ConfigCanal==CHC_C));
        
        iMenuAnterior=iMenuActual;

    }
    
    bRefrescoPantalla=0;
    
    return 0;
}


int8 menu_180(){
    if(bRefrescoPantalla){
        int8 i8Time_min, i8Time_seg;      // Variables utilizadas para la asignaci�n de tiempo
        
        if(iMenuActual!=183){ // Si no hay erro de electrodo
            controlSonido(0);
            if(iMenuAnterior!=180 && iMenuAnterior!=181){
                ST7529_clear();                                                                 // Limpio la pantalla
                ST7529_printf(sSMP,0,0,L_,NORMAL);                            // Pongo el t�tulo del men�
                
                if(iMenuAnterior!=183){
                    giPos=1;
                    i8PulsosSMP=1;
                    bCorrientePulsos=0;
                    i16TimeRaw[0]=i16TacSMP;
                    structMedidasMultipulsos.si16IMedSMP=0;         // Init values para no poner basura
                    structMedidasMultipulsos.si16ResSMP=0; 
                }
               
                pantalla_seleccion();
            }    
            
            if(iMenuActual==180){
                structMedidasMultipulsos.si16IMedSMP=0;       
                structMedidasMultipulsos.si16ResSMP=0;
            }
            
            if(iMenuActual==180){
                quitar_config();
                poner_flecha_izq();
            }else if(iMenuActual==181){
                poner_config();
                quitar_flecha_izq();
            }
            
            Calc_representacion_t(i16TimeRaw[0],0);
            
            if(giPos<=4 && !bCorrientePulsos){
                giPos=4;
            }else if(bCorrientePulsos && giPos<=1){
                giPos=1;
            }
            
            ST7529_printf(sINTENSIDAD,3,26,S_,!bCorrientePulsos);
            ST7529_printf("[A",39,53,S_,0);
                
            ST7529_printf(sTIEMPO,3,80,S_,0);
                
            ST7529_printf(sPULSOS,51,26,S_,bCorrientePulsos);
            
            ST7529_printf(sINTENSIDAD_SET,41,95,S_,0);
            ST7529_printf("[A",65,95,S_,0);
                
            ST7529_printf(sRMED,41,108,S_,0);   
            ST7529_printf(sOHM,65,108,S_,0);
            
            i16IMedSMP=structMedidasMultipulsos.si16IMedSMP;        // Cargo valores smedidas    
            i16ResSMP=structMedidasMultipulsos.si16ResSMP;
        
            if(((i16IMedSMP/1000.0)*i16ResSMP)>=10000){ // Si la tensi�n de salida es superior a 10 voltios (HV)
                ST7529_printf(sHIGH_VOLTAGE,70,45,L_,0);
            }else{
                ST7529_printf(sHIGH_VOLTAGE_VACIO,70,45,L_,0);
            }
           
            if((iMenuAnterior==80 && iMenuActual==180)){        // Envio el paquete de datos si es la primera vez que entra al men�
                // Una vez ha pintado todo el men�, procedemos a enviar el paquete con los datos configurados en el men� 80
                // Preparo paquete de datos
                
                structTratamientoMultipulsos.si16FrecSMP=i16FrecSMP;                                // Frecuencia del SMP
                structTratamientoMultipulsos.si16PWSMP=i16PWSMP;                                    // Ancho de pulso del sistema multipulsos
                structTratamientoMultipulsos.si32TDesfaseSMP=i32TDesfaseSMP;                        // Desfase entre pulsos
                
                i8ErrorCom=0;                                                                       // Inicializa el valor del contador de errores

                configuraDatos(MODO_TRAT_SMP);                                                    // Envia comando

                i8TratamientoSeleccionado=TRATAMIENTO_SMP;
                
                // Inicializacion de los valores de tratamiento activo
                // Estos valore sno hayque enviarlos, simplemente es para inicializar esas variables
                if(!bPausaTratamiento){
                    i16ISMP=2;  // 200uA
                    i8PulsosSMP=1;
                }
                maxPulsosSMP();
                
                structTratamientoMultipulsosActivo.si16ISMP=i16ISMP;              // Configuraci�n corriente en el sistema multipulsos (activo)
                structTratamientoMultipulsosActivo.si8PulsosSMP=i8PulsosSMP;      // Configuracii�n pulsos en el sistema multipulsos (activo)
                
            }   // Cierre if primera vez
            
            if((iMenuAnterior==180 && iMenuActual==181)|| (iMenuAnterior==183 && iMenuActual==181)){
                quitar_cancelar();
            }
            
            if(iMenuAnterior==181 && iMenuActual==180){
                poner_cancelar();
            }
            
            
            sprintf(mystring,"%5lu",redondeoI_50(i16IMedSMP));
            ST7529_printf(mystring,1,40,XL_,0);
            
            sprintf(mystring,"%2u:%02u",i8Tmin,i8Tseg);
            ST7529_printf(mystring,1,94,XL_,0);
            
            sprintf(mystring,"%2U",i8PulsosSMP);
            ST7529_printf(mystring,49,40,XL_,0);
            
            sprintf(mystring,"%5LU",i16ISMP*100);
            ST7529_printf(mystring,54,95,S_,0);
            
            sprintf(mystring,"%5LU",i16ResSMP);
            ST7529_printf(mystring,54,108,S_,0);  

        }else{              // Si hay error de electrodo, hay que apagar el canal y tal
            if (iMenuAnterior!=183){
                ST7529_clear();
                controlSonido(1);
            }

            Calc_representacion_t(i16TimeRaw[0],0);                           // C�lcula de nuevo la representaci�n del tiempo
            i8Time_min=i8Tmin;                                                         // Recarga de nuevo las variables para usarlas de nuevo en el caso de error de electrodo
            i8Time_seg=i8Tseg;            

            
            ST7529_printf(sTACTIVO,35,102,S_,0);          
            ST7529_printf(sSMP,10,0,L_,NORMAL);
            ST7529_printf(sERROR_ELECTRODO,10,50,L_,NORMAL);
            sprintf(mystring,"%2u:%02u",i8Time_min,i8Time_seg);
            ST7529_printf(mystring,37,112,L_,0);
        }
        iMenuAnterior=iMenuActual;
    }
    
    bRefrescoPantalla=0;
    
    return 0;
}

// Men� indicaci�n de autoapagado
int8 menu_200(){
    if(iMenuAnterior!=200){
        ST7529_clear();
        iMenuReposo=iMenuAnterior;
    }
   
    int32 iTiempoDesc=(600000-var_tiempo)*0.001;    // Calcula el timepo en segundos
       /*if(iTiempoDesc<=0 || iTiempoDesc>61){      // Para el caso en que desborde o pase algo raro
          iTiempoDesc=0;
       }*/

    sprintf(mystring,"Quedan %Lu segundos",iTiempoDesc);     // Muestra por pantalla el timepo restante
    ST7529_printf(mystring,10,30,L_,NORMAL);
    ST7529_printf(sAUTOAPAG_1,10,50,L_,NORMAL);
    ST7529_printf(sAUTOAPAG_2,0,90,L_,NORMAL);
    ST7529_printf(sAUTOAPAG_3,15,110,L_,NORMAL);
    
    giPos=0;

    iMenuAnterior=iMenuActual;

    return 0;
}

// Men� de apagado del equipo
int8 menu_201(){

    if(iMenuAnterior!=201){
        ST7529_clear();
    }

    ST7529_printf(sAPAGADO_EQUIPO,15,50,L_,NORMAL);
    iMenuAnterior=iMenuActual;
   
    return 0;
}

// Pantalla de error de transistores
int8 menu_202(){

    if(iMenuAnterior!=202){
        ST7529_clear();
    }
    ST7529_printf(sERROR_TRANSISTORES,10,50,L_,NORMAL);

    pausa_ms(1000);
    ControlSonido(0);
    
    iMenuAnterior=iMenuActual;   
    
    return 0;
}

// Pantalla de error de sistema de medida
int8 menu_203(){

    if(iMenuAnterior!=204){
        ST7529_clear();
    }
    ST7529_printf(sERROR_SISTEMA_MEDIDA,5,50,L_,NORMAL);
   
    pausa_ms(1000);
    ControlSonido(0);
    
    iMenuAnterior=iMenuActual;  
    
    return 0;
}

// Men� de carga del equipo
int8 menu_204(){

    if(iMenuAnterior!=204){
        ST7529_clear();            // Limpia la pantalla  por completo
    }
    float fCalcTiempo;
    int8 i8BatMinutos=0;
    int8 i8BatHoras=0;
    
    if(getFC()){                  // Si las baterias han sido cargadas al 100% (comprobado mediante el flag de FC del BQ34Z100G1)              
        i8RepVal1=sCARGA_COMPLETA;
    }else{
        i8RepVal1=sCARGA_CURSO;
        fCalcTiempo=getATTF()/60.0;
        i8BatHoras=fCalcTiempo;
        i8BatMinutos=(fCalcTiempo-i8BatHoras)*60;
        sprintf(mystring,"Fully Charged in %u h %u min",i8BatHoras,i8BatMinutos);
        ST7529_printf(mystring,10,100,S_,0);
    }
    ST7529_printf(i8RepVal1,15,10,L_,0);
    /*
    // Datos de test - Estos datos se sustituir�n por un nivel de porcetaje o un dibujo de una bateria en carga
    ST7529_printf(i8RepVal1,15,10,L_,0);
    sprintf(mystring,"V: %04Ld mV I: %04Ld mA",getVoltage(),getCurrent());
    ST7529_printf(mystring,10,40,S_,0);
    sprintf(mystring,"RC/FC: %Ld/%Ld mAh",getRemaining(),getCapacity());
    ST7529_printf(mystring,10,50,S_,0);
    sprintf(mystring,"Batt:  %u %%",nivelBateria());
    ST7529_printf(mystring,10,60,S_,0);
    sprintf(mystring,"Temp:  %3.1w C",getTemp());
    ST7529_printf(mystring,10,70,S_,0);
    sprintf(mystring,"Flags: 0x%LX - FlagsB: 0x%LX",getFlags(),getFlagsB());
    ST7529_printf(mystring,10,80,S_,0);
    sprintf(mystring,"Cycle Count:  %Lu",getCycleCount());
    ST7529_printf(mystring,10,90,S_,0);
    sprintf(mystring,"Time to Full Charge:  %Lu min",getATTF());
    ST7529_printf(mystring,10,100,S_,0);
    */
    
    sprintf(mystring,"%u %%",nivelBateria());
    ST7529_printf(mystring,25,40,XL_,0);

    if(!input_state(MENU_2)){
        sprintf(mystring,"V: %04Ld mV I: %04Ld mA",getVoltage(),getCurrent());
    }else{
        sprintf(mystring,"                       ");
    }
    ST7529_printf(mystring,20,80,S_,0);
    
    iMenuAnterior=iMenuActual;
   
    return 0;
}

// Men� de error de comunicaciones
int8 menu_205(){
    
    ST7529_clear();
    
    if(!bComprobacionInicial){                                                  // Si no est� comprobando las comunicaciones iniciales
        bComprobacionInicial=0;
        control_DC(0,EN_30);                                                    // Deshabilita DC/DC 30V
        if(i8CanalesActivados){                                                 // Si estamos en electroestimulaci�n
            apagadoCanales();                                                   // Inicializo variables
        }else if(iMenuAnterior>=180){                                           // Si estamos en SMP 
            apagadoSMP();                                                       // Inicializo variables
            bTratamientoSMPActivado=0;                                          // Inicializo variable
        }else{                                                                  // S iestamos en galv�nica y/o micro
            apagadoMicrocorrientes();                                           // Inicializo variables
            bTratamientoGalvanicaActivado=0;                                    // Inicializo variable
        }
        initReles();                                                            // Inicializa el estado de los rel�s
    }
    
    for (int8 i8Leds=0;i8Leds<TOTAL_LEDS;i8Leds++){                         // Recorro todos los LEDs
        control_led(1,rojo,i8Leds);                                         // Enciendo LED rojo
    }
    
    ST7529_printf(sCODIGO_ERROR,20,50,M_,NORMAL);
    
    if(bErrorComunicaciones){
        sprintf(mystring,"%03u",REG_ERROR_COMMS_O_S);
    }else{
        sprintf(mystring,"%03u",REG_ERROR_COMMS_S_O);
    }
    
    ST7529_printf(mystring,33,70,M_,NORMAL);
    
    controlSonido(1);                                                       // Enciendo pito
    reset_orco();                                                           // Hago un reset a Orco    
    pausa_ms(3000);                                                         // Delay pito + pantalla          
    controlSonido(0);                                                       // Apagado pito
    
    for (int8 i8Leds=0;i8Leds<TOTAL_LEDS;i8Leds++){                         // Recorro todos los LEDs
        control_led(0,rojo,i8Leds);                                         // Apagado LED rojo
    }
    
    return 0;
}

// Men� de error de calibrado
int8 menu_206(){
    
    ST7529_clear();                                                         // Limpio la pantalla
    
    for (int8 i8Leds=0;i8Leds<TOTAL_LEDS;i8Leds++){                         // Recorro todos los LEDs
        control_led(1,rojo,i8Leds);                                         // Enciendo LED rojo
    }
    
    ST7529_printf(sCODIGO_ERROR,20,50,M_,NORMAL);                           // Pongo el texto de c�digo de error
    
    
    if(i8CanalesActivados){                                                 // Si estamos en electroestimulaci�n
        apagadoCanales();                                                   // Inicializo variables
    }else if(iMenuAnterior>=180){                                           // Si estamos en SMP 
        apagadoSMP();                                                       // Inicializo variables
        bTratamientoSMPActivado=0;                                          // Inicializo variable
    }else{                                                                  // S iestamos en galv�nica y/o micro
        apagadoMicrocorrientes();                                           // Inicializo variables
        bTratamientoGalvanicaActivado=0;                                    // Inicializo variable
    }
    
    initReles();                                                            // Inicializaci�n rel�s
    
    if(i16ErroresOcurridos & ERROR_CALIBRADO_CHA){                          // Error de calibrado CHA
        sprintf(mystring,"%03u",REG_ERROR_CAL_A);
    }else if(i16ErroresOcurridos & ERROR_CALIBRADO_CHB){                    // Error de calibrado CHB
        sprintf(mystring,"%03u",REG_ERROR_CAL_B);
    }else if(i16ErroresOcurridos & ERROR_CALIBRADO_CHC){                    // Error de calibrado CHC
        sprintf(mystring,"%03u",REG_ERROR_CAL_C);
    }

    ST7529_printf(mystring,33,70,M_,NORMAL);                                // Muestro error por pantalla
    
    controlSonido(1);                                                       // Enciendo pito
    reset_orco();                                                           // Hago un reset a Orco    
    pausa_ms(3000);                                                         // Delay pito + pantalla          
    controlSonido(0);                                                       // Apagado pito
    
    for (int8 i8Leds=0;i8Leds<TOTAL_LEDS;i8Leds++){                         // Recorro todos los LEDs
        control_led(0,rojo,i8Leds);                                         // Apagado LED rojo
    }
    
    return 0;
}

// Submenu 22
void submenu_22(){

    switch (iMenuActual){
        case 20:
            if (giPos==1){
                min=2;
                max=200;
                //giPosRulancha=i16IGalv[bSeleccionGalvanica];
            }else if (giPos==4){
                min=2;   // 2*50=100uA 
                max=20;  // 100*50=5000uA
                //giPosRulancha=i16Imicro; 
            }
            break;
        case 30:
            min=2;
            if(limiteDensidadCorriente(LIMIT_CORRIENTE)){
                max=i16ITrans;
            }else{
                max=MAXIMA_CORRIENTE_TRANSCRANEAL;
            }
            break;
        case 40:
            max=20;        // 1 mA
            min=2;
            gI=50;
            //giPosRulancha=i16IElec[i8ConfigCanal];
            break;
    }

    if(giPosRulancha>max){
        giPosRulancha=max;
    }
    
    if (giPosRulancha<=min){
        giPosRulancha=min;
    }

    switch (iMenuActual){
        case 20:
            if(giPos==1){
                i16IGalv[bSeleccionGalvanica]=giPosRulancha;  
                i32CGalv=calc_CargaGalv(i16IGalv[bSeleccionGalvanica]);
            }else if(giPos==4){
                i16Imicro=giPosRulancha; 
            }
            break;
        case 30:
            i16Itrans=giPosRulancha;  
            i32CTrans=calc_CargaGalv(i16Itrans);
            break;
        case 40:
            i16IElec[i8ConfigCanal]=giPosRulancha;
            break;
    }
}

// Submenu 23
void submenu_23(){

    /*switch (iMenuActual){
        case 20:
            if (giPos==3){
                giPosRulancha=i8TrampaGalv[bSeleccionGalvanica];
            }else if (giPos==6){
                giPosRulancha=i8Trampamicro;
            }
            break;
        case 40:
            giPosRulancha=i8TrElec[i8ConfigCanal];
            break;
    }*/

    if(giPosRulancha>10){
        giPosRulancha=10;
    }

    if (giPosRulancha<=0){
        giPosRulancha=0;
    }

    switch (iMenuActual){
        case 20:
            if(giPos==3){
                if(i16TGalv[bSeleccionGalvanica]!=0){
                    if((float)giPosRulancha>=(i16TGalv[bSeleccionGalvanica]/3.0)){
                        giPosRulancha=(i16TGalv[bSeleccionGalvanica]/3);
                    }
                }
                i8TrampaGalv[bSeleccionGalvanica]=giPosRulancha;    
                i32CGalv=calc_CargaGalv(i16IGalv[bSeleccionGalvanica]);
            }
            break;
        case 30:
            if(giPos==3){
                if(i16Ttrans!=0){
                    if((float)giPosRulancha>=(i16Ttrans/3.0)){
                        giPosRulancha=(i16Ttrans/3);
                    }
                }
                i8Trampatrans=giPosRulancha;    
                i32CTrans=calc_CargaGalv(i16ITrans);
            }
            break;
        case 40:
            i8TrElec[i8ConfigCanal]=giPosRulancha;
            if(giPos==4){
                if((float)giPosRulancha>=(i16TacElec[i8ConfigCanal]/3.0)){
                    giPosRulancha=(i16TacElec[i8ConfigCanal]/3);
                }
                i8TrElec[i8ConfigCanal]=giPosRulancha;
            }
            break;
    }
}

// Submenu 27
void submenu_27(){

    switch (iMenuActual){
        case 20:
            //giPosRulancha=i16PWmicro/25;      
            maxBW=20;
            break;
        case 40:
            /*if(giPos==10){
                giPosRulancha=i16PW_plusElec[i8ConfigCanal]/25;
            }else if (giPos==11){
                giPosRulancha=i16PW_minusElec[i8ConfigCanal]/25;
            }*/
            if(i8ConfigCanal==POINTER_C){
                maxBW=40;
            }else{
                maxBW=40;
            }
            
            if(giPos==10){
                maxBW=((900000.0/i16FrecElec[i8ConfigCanal])-(i16PW_minusElec[i8ConfigCanal]))/25; 
            }else if(giPos==11){
                maxBW=((900000.0/i16FrecElec[i8ConfigCanal])-(i16PW_plusElec[i8ConfigCanal]))/25;
            }
            
            if(maxBW>=40){
                maxBW=40;
            }
            break;
        case 80:
            //giPosRulancha=i16PWSMP/25;

            maxBW=20;    // 500us
            break;
    }


    if(giPosRulancha>=maxBW){
        giPosRulancha=maxBW;
    }

    if(giPosRulancha<4){
        giPosRulancha=4;
    }

    switch (iMenuActual){
        case 20:
            i16PWmicro=giPosRulancha*25;
            break;
        case 40:
            if (giPos==10){
                i16PW_plusElec[i8ConfigCanal]=giPosRulancha*25;
                //maxBW=Calc_BWmax(i16frecElec[i8ConfigCanal],bpolaridadElec[i8ConfigCanal]);

                if(i8SimetriaCanales!=0){
                    copiarDatosSimetria(0);
                }

                if(i8ConfigCanal==POINTER_C){
                    i16PW_minusElec[i8ConfigCanal]=i16PW_plusElec[i8ConfigCanal];
                }
            }else if(giPos==11){
                i16PW_minusElec[i8ConfigCanal]=giPosRulancha*25;
                //maxBW=Calc_BWmax(i16frecElec[i8ConfigCanal],bpolaridadElec[i8ConfigCanal]);
                
                if(i8SimetriaCanales!=0){
                    copiarDatosSimetria(0);
                }
            }
            break;
        case 80:
            i16PWSMP=giPosRulancha*25;
            if((i16PWSMP*2+BANDA_GUARDA*2) >= i32TDesfaseSMP){
                giPosRulancha=(i32TDesfaseSMP-BANDA_GUARDA*2)/2;
                giPosRulancha/=25;
                i16PWSMP=giPosRulancha*25;
            }
            //maxBW=maxPWSMP();   //500us
            break;
    }
}

// Submenu 28
void submenu_28(){

    switch (iMenuActual){
        case 20:
            max=100;
            min=2;                                    
            //aux=i16frecmicro;
            gF=1;
            //giPosRulancha=aux/gF;
            break;       
        case 40:
            // MOD ORIGINAL
            //aux=i16frecElec[i8ConfigCanal];

            max=i16FrecLimSup[i8ConfigCanal];
            min=i16FrecLimInf[i8ConfigCanal];
            break;
        case 80:
            max=100;
            min=2;
            //aux=i16FrecSMP;

            break;
    }
    
    i16FrecuenciaAnterior=giPosRulancha*gF;

    if(iMenuActual!=20){
        if (i16FrecuenciaAnterior>200 && i16FrecuenciaAnterior<=10000){
            gF=50;
            giPosRulancha=i16FrecuenciaAnterior/gF;
        }else if(i16FrecuenciaAnterior==200){
            if(bascendente){
                gF=50;
                giPosRulancha=i16FrecuenciaAnterior/gF;
            }else{
                gF=10;
                giPosRulancha=i16FrecuenciaAnterior/gF;
            }
        }else if (i16FrecuenciaAnterior>100 && i16FrecuenciaAnterior<200){
            if(giPosRulancha==3 && gF==50){         // Si estabamos en 200 y ahora al volver atras quiere mostrar 150
                giPosRulancha=19;                    // Le decimos que la cuenta es de 10 en 10
                i16FrecuenciaAnterior=190;                    // Salta a 190
            }
            gF=10;
            giPosRulancha=i16FrecuenciaAnterior/gF;
        }else if(i16FrecuenciaAnterior==100){
            if(bascendente){
                gF=10;
                giPosRulancha=i16FrecuenciaAnterior/gF;
            }else{
                gF=2;
                giPosRulancha=i16FrecuenciaAnterior/gF;
            } 
        }else if (i16FrecuenciaAnterior>20 && i16FrecuenciaAnterior<100){
            if(giPosRulancha==9 && gF==10){            // Si estabamos en 100 y ahora al volver atras quiere mostrar 90
                giPosRulancha=49;                    // Le decimos que la cuenta es de 2 en 2
                i16FrecuenciaAnterior=98;                        // Salta a 98
            }
            gF=2;
            giPosRulancha=i16FrecuenciaAnterior/gF;
        }else if(i16FrecuenciaAnterior==20){
            if(bascendente){
                gF=2;
                giPosRulancha=i16FrecuenciaAnterior/gF;
            }else{
                gF=1;
                giPosRulancha=i16FrecuenciaAnterior/gF;
            } 
        }else{
            if(giPosRulancha==9 && gF==2){            // Si estabamos en 20 y ahora al volver atras quiere mostrar 18                
                giPosRulancha=19;                    // Le decimos que la cuenta es de 10 en 10        
                i16FrecuenciaAnterior=19;                        // Salta a 19    
            }
            gF=1;
            giPosRulancha=i16FrecuenciaAnterior;
        }
    }

    if ((giPosRulancha*gF)>=max){
        giPosRulancha=max/gF;
    }

    if ((giPosRulancha*gF)<min){
        giPosRulancha=min/gF;
    }

    switch (iMenuActual){
        case 20:
            //aux=giPosRulancha*gF;
            i16frecmicro=giPosRulancha*gF;
            maxBW=Calc_BWmax(i16frecmicro,bpolaridadmicro);
            break;
        case 40:
            //aux=giPosRulancha*gF;
            i16frecElec[i8ConfigCanal]=giPosRulancha*gF;
            maxBW=Calc_BWmax(i16frecElec[i8ConfigCanal],bpolaridadElec[i8ConfigCanal]);
            i16PW_plusElec[i8ConfigCanal]=Calc_BW(maxBW,i16PW_plusElec[i8ConfigCanal]);
            i16PW_minusElec[i8ConfigCanal]=Calc_BW(maxBW,i16PW_minusElec[i8ConfigCanal]);

            if(i8SimetriaCanales!=0){
                copiarDatosSimetria(0);
            }
            break;
        case 80:
            //aux=giPosRulancha*gF;
            i16FrecSMP=giPosRulancha*gF;
            maxBW=Calc_BWmax(i16FrecSMP,1);
            i16PWSMP=Calc_BW(maxBW,i16PWSMP);
            break;
    }
}

// Submenu 29
void submenu_29(){

    /*switch (iMenuActual){
        case 20:
            giPosRulancha=bPolaridadMicro;
            break;                       
        case 40:
            giPosRulancha=bpolaridadElec[i8ConfigCanal];
            break;
    }*/

    if(giPosRulancha>1){
        giPosRulancha=1;
    }

    if (giPosRulancha<=0){
        giPosRulancha=0;
    }

    switch(iMenuActual){
        case 20:
            bPolaridadMicro=giPosRulancha;
            maxBW=Calc_BWmax(i16frecmicro,bpolaridadmicro);
            i16PWmicro=Calc_BW(maxBW,i16PWmicro);
            break;
        case 40:
            bpolaridadElec[i8ConfigCanal]=giPosRulancha;
            maxBW=Calc_BWmax(i16frecElec[i8ConfigCanal],bpolaridadElec[i8ConfigCanal]);
            i16PW_plusElec[i8ConfigCanal]=Calc_BW(maxBW,i16PW_plusElec[i8ConfigCanal]);
            i16PW_minusElec[i8ConfigCanal]=Calc_BW(maxBW,i16PW_minusElec[i8ConfigCanal]);
            if(i8SimetriaCanales!=0){
                copiarDatosSimetria(0);
            }
            break;      
    }
}

// Submenu 33
void submenu_33(){

    /*switch (iMenuActual){
        case 40:
            giPosRulancha=bsimetriaElec[i8ConfigCanal];
            break;
    }*/
   
    if(giPosRulancha>1){
        giPosRulancha=1;
    }
    
    if (giPosRulancha<=0){
        giPosRulancha=0;
    }
   
    if(giPosRulancha){
        bpolaridadElec[i8ConfigCanal]=1;
    }
                 
    switch (iMenuActual){
        case 40:
            bsimetriaElec[i8ConfigCanal]=giPosRulancha;
            maxBW=Calc_BWmax(i16frecElec[i8ConfigCanal],bpolaridadElec[i8ConfigCanal]);
            i16PW_plusElec[i8ConfigCanal]=Calc_BW(maxBW,i16PW_plusElec[i8ConfigCanal]);
            i16PW_minusElec[i8ConfigCanal]=Calc_BW(maxBW,i16PW_minusElec[i8ConfigCanal]);
            if(i8SimetriaCanales!=0){
                copiarDatosSimetria(0);
            }
            break;
    }
}

void submenu_34(){
 
    if(limiteDensidadCorriente(LIMIT_SUPERFICIE)){
        min=i8SuperficieElectrodo;
    }else{
        min=MIN_TAM_ELECTRODO;
    }
    
    if(giPosRulancha>MAX_TAM_ELECTRODO){
        giPosRulancha=MAX_TAM_ELECTRODO;
    }
   
    if (giPosRulancha<min){
        giPosRulancha=min;
    }
   
    i8SuperficieElectrodo=giPosRulancha;

}

// Submenu 42
void submenu_42(){

    switch (iMenuActual){
        case 20:
            if(giPos==2){
                //giPosRulancha=i16TGalv[bSeleccionGalvanica];
                if(giPosRulancha>1800){             // Max 30 min 
                    giPosRulancha=1800;
                }
                if(bSeleccionGalvanica){
                    if (giPosRulancha<=1){          
                        giPosRulancha=1;
                    }
                }else{
                    if (giPosRulancha<=0){          // Si es 0, tiempo ilimitado
                    giPosRulancha=0;
                    }
                }
                i16TGalv[bSeleccionGalvanica]=giPosRulancha;

                if(i16TGalv[bSeleccionGalvanica]!=0){
                    if((float)i8TrampaGalv[bSeleccionGalvanica]>=(i16TGalv[bSeleccionGalvanica]/3.0)){
                        i8TrampaGalv[bSeleccionGalvanica]=(i16TGalv[bSeleccionGalvanica]/3);
                    }
                }
                if(i8TrampaGalv[bSeleccionGalvanica]>=10){
                    i8TrampaGalv[bSeleccionGalvanica]=10;
                }
                i32CGalv=calc_CargaGalv(i16IGalv[bSeleccionGalvanica]);
            }else if (giPos==5){
                //giPosRulancha=i16Tmicro/5;
                if(giPosRulancha>720){ //720*5=3600 segundos - 60 min 00 s
                    giPosRulancha=720;
                }
                if (giPosRulancha<=1){
                    giPosRulancha=1;
                }
                i16Tmicro=giPosRulancha*5;
            }
            break;
        case 30:
            if(giPos==2){
                //giPosRulancha=i16TGalv[bSeleccionGalvanica];
                if(giPosRulancha>1800){             // Max 30 min 
                    giPosRulancha=1800;
                }

                if (giPosRulancha<=0){          // Si es 0, tiempo ilimitado
                    giPosRulancha=0;
                }
                i16Ttrans=giPosRulancha;

                if(i16Ttrans!=0){
                    if((float)i8Trampatrans>=(i16Ttrans/3.0)){
                        i8Trampatrans=(i16Ttrans/3);
                    }
                }
                if(i8Trampatrans>=10){
                    i8Trampatrans=10;
                }
                i32Ctrans=calc_CargaGalv(i16Itrans);
            }
            break;
        case 40:
            if(giPos==2){
                //giPosRulancha=i16TacElec[i8ConfigCanal]/5;
                if(giPosRulancha>719){ //719*5=3595 segundos - 59 min 55 s
                    giPosRulancha=719;
                }
                if (giPosRulancha<=1){
                    giPosRulancha=1;
                }
                i16TacElec[i8ConfigCanal]=giPosRulancha*5;          

                if(i8TrElec[i8ConfigCanal] > i16TacElec[i8ConfigCanal]/3){
                    i8TrElec[i8ConfigCanal]=i16TacElec[i8ConfigCanal]/3;
                }

                if((float)i8TrElec[i8ConfigCanal]>=(i16TacElec[i8ConfigCanal]/3.0)){
                    i8TrElec[i8ConfigCanal]=(i16TacElec[i8ConfigCanal]/3);
                }
                if(i8TrElec[i8ConfigCanal]>=10){
                    i8TrElec[i8ConfigCanal]=10;
                }
            }else if(giPos==3){
                //giPosRulancha=i16TdElec[i8ConfigCanal]/5;
                if(giPosRulancha>719){ //719*5=3595 segundos - 59 min 55 s
                    giPosRulancha=719;
                }
                if (giPosRulancha<=0){
                    giPosRulancha=0;
                }
                i16TdElec[i8ConfigCanal]=giPosRulancha*5;
            }
            break;
        case 80:
            if(giPos==0){
                if(giPosRulancha>719){ //719*5=3595 segundos - 59 min 55 s
                    giPosRulancha=719;
                }
                if (giPosRulancha<=1){
                    giPosRulancha=1;
                }
                i16TacSMP=giPosRulancha*5;
            }else if(giPos==1){
                //giPosRulancha=i32TDesfaseSMP/100;
                if(giPosRulancha>1000){ 
                    giPosRulancha=1000;
                }
                if (giPosRulancha<=5){
                    giPosRulancha=5;
                }
                i32TDesfaseSMP=giPosRulancha*100;
                if((i16PWSMP*2+BANDA_GUARDA*2) >= i32TDesfaseSMP){
                    giPosRulancha=(i32TDesfaseSMP-BANDA_GUARDA*2)/2;
                    giPosRulancha/=25;
                    i16PWSMP=giPosRulancha*25;
                }
            }
            break;
    }
}

// Submenu 43
void submenu_43(){

    //giPosRulancha=i8Nrep[i8ConfigCanal];

    if(giPosRulancha>100){
        giPosRulancha=100;  
    }
    if (giPosRulancha<1){
        giPosRulancha=1;
    }
    
    i8Nrep[i8ConfigCanal]=giPosRulancha;   
}






