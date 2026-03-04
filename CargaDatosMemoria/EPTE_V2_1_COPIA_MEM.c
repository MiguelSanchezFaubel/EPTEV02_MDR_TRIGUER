/*
*   File: EPTE_V2_1_COPIA_MEM.c
*   
*   Descripci�n: Program file del programa principal de Sauron
*   
*   Proyecto: EPTE 2
*   Versi�n: 3.0
*
*   Ionclinics & Deionics SL
*/

/******************************** Identificador del programma ********************************/
#define CARGA_DATOS

/************************************ Libreria de Programa ***********************************/
#include <EPTE_V2_1_COPIA_MEM.h>        // Libreria de definiciones
#include <math.h>                       // Libreria matem�tica
#include <stdlib.h>                     // Libreria est�ndar
#include <string.h>

/************************************ Librerias Definidas ************************************/
#include "../Drivers/M25AA1024.c"  
#include "../Drivers/ST7529.c"                     // Librer�a del GLCD 
#include "../Drivers/Pictures/main_logo.c"
#include "../Idiomas/castellano_mem.c"
#include "../Idiomas/ingles_mem.c"
#include "../Sauron/preset_registers.h"            // Librer�a que define el bloque de presets de tratamientos
#include "../Sauron/internal_eeprom_registers.h"   // Librer�a que define el bloque de presets de tratamientos

/*********************************** Definiciones de tipo ************************************/

/************************************ Prototipo Funciones ************************************/
void control_DC(int1 control,int8 DC);                                  // Control de las alimentaciones
void showMem(int32);
void initPresetsPredefinidos();

/************************************ Librerias Definidas ************************************/

/************************************** Interrupciones ***************************************/

/************************************ Programa Principal *************************************/
void main() {
    
    // Asignaci�n de puertos anal�gicos +++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    ANCON0=0x00;        // ANCON0: Anal�gicas -> X    Digitales -> AN0,AN1,AN2,AN3,AN4,AN5,AN6,AN7
    ANCON1=0x00;        // ANCON1: Anal�gicas -> X    Digitales -> AN8,AN9,AN10,AN11,AN12,AN14,AN14,AN15 
    ANCON2=0x00;        // ANCON2: Anal�gicas -> X    Digitales -> AN16,AN17,AN18,AN19,AN20,AN21,AN22,AN23
    
    // Puesta a nivel bajo de todos los pines ++++++++++++++++++++++++++++++++++++++++++++++++++++++
    output_a(0x00);                     // Pongo a nivel bajo el puerto A
    output_b(0x00);                     // Pongo a nivel bajo el puerto B
    output_c(0x00);                     // Pongo a nivel bajo el puerto C
    output_d(0x00);                     // Pongo a nivel bajo el puerto D
    output_e(0x00);                     // Pongo a nivel bajo el puerto E
    output_f(0x00);                     // Pongo a nivel bajo el puerto F
    output_g(0x00);                     // Pongo a nivel bajo el puerto G
    
    control_DC(0,EN_5);                 // Apago alimentaci�n 5V
    control_DC(0,EN_5_sw);              // Apago alimentaci�n 5V de perif�ricos
    control_DC(0,EN_12);                // Apago alimentaci�n 12 V
    
    I2C_1_ON=0;                         // Apagado del I2C       
    DEBUG_UART_ON=0;                    // Apagado UART depuraci�n
    COM_PIC_UART_ON=0;                  // Apagado UART comunicaci�n

    
    output_high(RST_ORCO);              // Reseteo y mantengo nivel alto en el PIC ORCO (RESET ACTIVO A NIVEL ALTO!)
    
    TRISC|=0xD8;                
    TRISC&=~0x21;                       // Configuraci�n TRISC para poder hacer uso de los pines - Si no se hace esta configuraci�n, da problemas con el FIXED_IO/FAST/STANDARD_IO

    TRISG|=0x02;                        // Configuraci�n TRISG
    
    DEBUG_UART_ON=1;                    // Apagado UART Debug
    COM_PIC_UART_ON=1;                  // Encendido UART comunicaci�n
    
    MEMCON=0xFF;                        // Deshabilitamos el bus de memoria externo
   
    control_DC(1,EN_5);                 // Habilito alimentaci�n de 5 V
    delay_ms(500);                      // Delay de estabilizaci�n
    
    // Setup Timer 2    - Timer resto de moduladores 250 us overflow, 250 us interrupt
    setup_timer_2(T2_DIV_BY_16,249,1);   
    
    // Configuracion pito
    setup_ccp7(CCP_PWM|CCP_SHUTDOWN_AC_L|CCP_SHUTDOWN_BD_L);        // Modulador para se�al acustica
    set_pwm7_duty((int16)((i16nivel_son*4.5)));                     // Cargamos duty de trabajo [0..500]
    
    for(int8 i8Init=0; i8Init<3; i8Init++){         // Bucle que parpadea un led al inicio para indicar que se ha encendido el equipo
        output_high(LED_CHG_V);
        delay_ms(125);
        output_low(LED_CHG_V);
        delay_ms(125);
    }
    
    control_DC(1,EN_5_sw);              // Habilitaci�n alimentaci�n de  5V sw
    delay_ms(500);                      // Delay de estabilizacion
    
    control_DC(1,EN_12);                // Habilitaci�n de la alimentacion de 12 V
    delay_ms(500);                      // Delay de estabilizaci�n 
    
    I2C_1_ON=1;                         // Encendido I2C
    i2c_init(true);                     // Habilitci�n I2C
    SPI_2_ON=1;                         // Habilitaci�n SPI
    
    // Configuraci�n de los PWM
    setup_ccp8(CCP_PWM);                                        // Modulador iluminacion pantalla
    
    setup_comparator(NC_NC_NC_NC);
    set_pwm7_duty((int16)0);                                    // Pone el valor de se�al ac�stica a 0
    set_pwm8_duty((int16)i8nivel_ilum*10);                      // Cargamos duty de trabajo [0..1000] 

    // Inicializaci�n de la pantalla
    ST7529_init();                                              // Inicializaci�n del controlador de pantalla
    M25AA1024_init();
    // Pongo imagen inicial
    //ST7529_putImageGS(imagen,9,25,iImagRow,iImagCol);           // Pongo logo EPTE en pantalla              
    sprintf(mystring,"CARGA DE DATOS");  
    ST7529_printf(mystring,0,0,L_,0);
    sprintf(mystring,"EN MEMORIA");
    ST7529_printf(mystring,0,20,L_,0);
    delay_ms(1000);                                             // Delay de muestra por pantalla

    ST7529_clear();                                             // Limpio la pantalla                                                  

    // --------------------------------------- BUCLE PRINCIPAL ----------------------------------
    /* Copia de datos a memoria SPI */
    // Las primeras 500 posiciones (0..499) de la memoria son para la FAT
    // a partir de ahi hasta donde alcanza la vista son fuentes
    
    int32 iAddress=TAM_FAT_TOTAL;
    char *cString;
    int32 iConv;
    int32 iCont=0;

    // Inicializacion EEPROM interna------------------------------------------------------
    for(iCont=0;iCont<1024;iCont++){                                    // Se graban todas las posiciones eeprom interna con 0
        writeEEPROM_8bits(iCont,0);
    }

    // Valores predefinidos del sistema
    writeEEPROM_8bits(EEPROM_LOC_ILUMINACION,40);   // Iluminacion  40%
    writeEEPROM_8bits(EEPROM_LOC_CONTRASTE,40);     // Contraste    40%
    writeEEPROM_16bits(EEPROM_LOC_SONIDO,0);        // Sonido       0% 
    writeEEPROM_8bits(EEPROM_LOC_IDIOMA,0);         // Idioma       ESP
    
    // Fuente peque�a ---------------------------------------------------------------------
    sprintf(mystring,"FUENTE S %lu",(int32)iAddress);  
    ST7529_printf(mystring,0,0,L_,0);
    
    M25AA1024_write(FAT_S,make8(iAddress,2));
    M25AA1024_write(FAT_S+1,make8(iAddress,1));
    M25AA1024_write(FAT_S+2,make8(iAddress,0));
    
    for(iCont=0; iCont<(sizeof(smallFont)/sizeof(smallFont[0])); iCont++, iAddress++){
        M25AA1024_write(iAddress,smallFont[iCont]);
        showMem(iAddress);
    }
    sprintf(mystring,"OK");  
    ST7529_printf(mystring,50,0,L_,0);
    
    // Fuente mediana ---------------------------------------------------------------------
    sprintf(mystring,"FUENTE M %lu",(int32)iAddress);  
    ST7529_printf(mystring,0,20,L_,0);
    
    M25AA1024_write(FAT_M,make8(iAddress,2));
    M25AA1024_write(FAT_M+1,make8(iAddress,1));
    M25AA1024_write(FAT_M+2,make8(iAddress,0));

    for(iCont=0; iCont<(sizeof(mediumFont)/sizeof(mediumFont[0])); iCont++, iAddress++){
        M25AA1024_write(iAddress,mediumFont[iCont]);
        showMem(iAddress);
    }
    sprintf(mystring,"OK");  
    ST7529_printf(mystring,50,20,L_,0);

    // Fuente grande ---------------------------------------------------------------------
    sprintf(mystring,"FUENTE L %lu",(int32)iAddress);  
    ST7529_printf(mystring,0,40,L_,0);
    
    M25AA1024_write(FAT_L,make8(iAddress,2));
    M25AA1024_write(FAT_L+1,make8(iAddress,1));
    M25AA1024_write(FAT_L+2,make8(iAddress,0));
    
    for(iCont=0; iCont<(sizeof(largeFont)/sizeof(largeFont[0])); iCont++, iAddress++){
        M25AA1024_write(iAddress,largeFont[iCont]);
        showMem(iAddress);
    }
    sprintf(mystring,"OK");  
    ST7529_printf(mystring,50,40,L_,0);
    
    // Fuente mu grande ---------------------------------------------------------------------
    sprintf(mystring,"FUENTE XL %lu",(int32)iAddress);  
    ST7529_printf(mystring,0,60,L_,0);
    
    M25AA1024_write(FAT_XL,make8(iAddress,2));
    M25AA1024_write(FAT_XL+1,make8(iAddress,1));
    M25AA1024_write(FAT_XL+2,make8(iAddress,0));
   
    for(iCont=0; iCont<(sizeof(xlargeFont)/sizeof(xlargeFont[0])); iCont++,iAddress++){
        M25AA1024_write(iAddress,xlargeFont[iCont]);
        showMem(iAddress);
    }
    sprintf(mystring,"OK");  
    ST7529_printf(mystring,50,60,L_,0);
    
    // Iconos ---------------------------------------------------------------------
    sprintf(mystring,"ICONOS %lu",(int32)iAddress);   
    ST7529_printf(mystring,0,80,L_,0);
    
    M25AA1024_write(FAT_ICON,make8(iAddress,2));
    M25AA1024_write(FAT_ICON+1,make8(iAddress,1));
    M25AA1024_write(FAT_ICON+2,make8(iAddress,0));
    
    for(iCont=0; iCont<(sizeof(ICON_16X16)/sizeof(ICON_16X16[0])); iCont++, iAddress++){
        M25AA1024_write(iAddress,ICON_16X16[iCont]);
        showMem(iAddress);
    }
    sprintf(mystring,"OK");  
    ST7529_printf(mystring,50,80,L_,0);
    
    // Imagen ---------------------------------------------------------------------
    sprintf(mystring,"IMAGEN %lu",(int32)iAddress);  
    ST7529_printf(mystring,0,100,L_,0);
    
    M25AA1024_write(FAT_IMAGEN,make8(iAddress,2));
    M25AA1024_write(FAT_IMAGEN+1,make8(iAddress,1));
    M25AA1024_write(FAT_IMAGEN+2,make8(iAddress,0));
    
    for(iCont=0; iCont<(sizeof(imagen)/sizeof(imagen[0])); iCont++, iAddress++){
        M25AA1024_write(iAddress,imagen[iCont]);
        showMem(iAddress);
    }
    sprintf(mystring,"OK");  
    ST7529_printf(mystring,50,100,L_,0);
    
    ST7529_clear();
    
    // Idioma Castellano ---------------------------------------------------------------------
    sprintf(mystring,"IDIOMA CASTELLANO %lu",(int32)iAddress);  
    ST7529_printf(mystring,0,0,L_,0);
    //fprintf(DEBUG_UART,"Idioma Castellano\r\n");
    
    char string1[100];
    int8 i8Length=0;

    for(int32 i32Cont=PRIMERA_POS_FAT,i32Indice=0;i32Cont<FAT_FINAL; i32Cont+=TAM_DIR_BYTES, i32Indice++){
        M25AA1024_write(i32Cont,make8(iAddress,2));
        M25AA1024_write(i32Cont+1,make8(iAddress,1));
        M25AA1024_write(i32Cont+2,make8(iAddress,0));
        
        strcpy(string1,textoCastellano[i32Indice]);
        i8Length=strlen(string1);         
        
        //fprintf(DEBUG_UART,"%lu L %u--> ",i32Indice,i8Length);
        
        for(iCont=0; iCont<i8Length/*strlen(textoCastellano[i32Indice])*/ ;iCont++, iAddress++){
            M25AA1024_write(iAddress,textoCastellano[i32Indice][iCont]);
            //fprintf(DEBUG_UART,"%c",textoCastellano[i32Indice][iCont]);
            showMem(iAddress);
        }
        //fprintf(DEBUG_UART,"\r\n");
        sprintf(mystring,"%3lu/%3lu",i32Indice+1,NUM_TOTAL_TEXTOS);  
        ST7529_printf(mystring,0,20,L_,0);
        if(i32Indice+1==NUM_TOTAL_TEXTOS){
            sprintf(mystring,"OK %lu",(int32)i32Cont);  
            ST7529_printf(mystring,55,0,L_,0);
        }
    }
    
    // Idioma Ingles ---------------------------------------------------------------------
    sprintf(mystring,"IDIOMA INGLES %lu",(int32)(iAddress));  
    ST7529_printf(mystring,0,40,L_,0);
    //fprintf(DEBUG_UART,"\r\nIdioma Ingles\r\n");
    //POLLA
    for(int32 i32Cont=(OFFSET_DIR_ENGLISH+PRIMERA_POS_FAT),i32Indice=0;i32Cont<(OFFSET_DIR_ENGLISH+FAT_FINAL); i32Cont+=TAM_DIR_BYTES, i32Indice++){
        M25AA1024_write(i32Cont,make8(iAddress,2));
        M25AA1024_write(i32Cont+1,make8(iAddress,1));
        M25AA1024_write(i32Cont+2,make8(iAddress,0));
        
        strcpy(string1,textoIngles[i32Indice]);
        i8Length=strlen(string1);    
        
       // fprintf(DEBUG_UART,"%lu L %u--> ",i32Indice,i8Length);
        
        for(iCont=0; iCont<i8Length/*strlen(textoIngles[i32Indice])*/ ;iCont++, iAddress++){
            M25AA1024_write(iAddress,textoIngles[i32Indice][iCont]);
            //fprintf(DEBUG_UART,"%c",textoIngles[i32Indice][iCont]);
            showMem(iAddress);
        }
        //fprintf(DEBUG_UART,"\r\n");
        sprintf(mystring,"%3lu/%3lu",i32Indice,NUM_TOTAL_TEXTOS);  
        ST7529_printf(mystring,0,60,L_,0);
        if(i32Indice==NUM_TOTAL_TEXTOS){
            sprintf(mystring,"OK %lu",(int32)i32Cont);  
            ST7529_printf(mystring,55,40,L_,0);
        }
    }

    ST7529_printf("INICIALIZANDO PRESETS",0,80,L_,0);
    initPresetsPredefinidos();

    while(TRUE){                                    // Bucle de programa principal
        sprintf(mystring,"Transferencia completada");                        
        ST7529_printf(mystring,0,120,S_,0);
    }   // Cierre bucle while principal
}   // Cierre main

void  control_DC(int1 control,int8 DC){                                                                                     // Control 0--> Apagar 1--> Encender  

    output_bit(DC,control);                                                                                                 // Pone a "control" el pin "DC"
    if(DC==EN_12){                                                                                                          // TODO - Revisar para ver para que vale
        bDebug=control;
    }
}

void showMem(int32 iAddress){
    if(i8PercentMem < (int8) (100*iAddress/MAX_MEM_BYTES)){
        i8PercentMem=100*iAddress/MAX_MEM_BYTES;
        sprintf(mystring,"%u %%", i8PercentMem);                        
        ST7529_printf(mystring,50,120,S_,0); 
    }
}

void initPresetsPredefinidos(){
    int16 direccion_aux=0;      // Variable para calcular la posicion e

    // Terapia: 0-Galv+micro, 1-tDCS, 2-SMP, 3-Electro

    // 0---------------------------GALV+MICRO----------------------------
    // Preset 1 - EPTE
    direccion_aux=OFFSET_EEPROM_PRESET_1;                                    // 0=120*0
    writeEEPROM_16bits(direccion_aux+EEPROM_GALV_CORRIENTE,7);                         // 350 uA              
    writeEEPROM_16bits(direccion_aux+EEPROM_GALV_TIEMPO_ACTIVO,80);                    // 1 m 20 s
    writeEEPROM_8bits(direccion_aux+EEPROM_GALV_TIEMPO_RAMPA,10);                      // 10 s
    writeEEPROM_8bits(direccion_aux+EEPROM_GALV_TIEMPO_COMP,1);                        // Tiempo compensado

    direccion_aux=OFFSET_REGISTRO_PRESETS+PRESET_1;                          // 0=6*0
    writeEEPROM_8bits(direccion_aux,2);                                      // Escribe en la EEPROM el indicador del preset guardado

    // Preset 2 - EPTE+MICRO
    direccion_aux=OFFSET_EEPROM_PRESET_2;                                    // 0=120*0
    writeEEPROM_16bits(direccion_aux+EEPROM_GALVMICRO_GALV_CORRIENTE,7);               // 350 uA 
    writeEEPROM_16bits(direccion_aux+EEPROM_GALVMICRO_GALV_TIEMPO_ACTIVO,80);          // 1 m 20 s   
    writeEEPROM_8bits(direccion_aux+EEPROM_GALVMICRO_GALV_TIEMPO_RAMPA,10);            // 10 s
    writeEEPROM_8bits(direccion_aux+EEPROM_GALVMICRO_GALV_TIEMPO_COMP,1);              // Tiempo compensado

    writeEEPROM_16bits(direccion_aux+EEPROM_GALVMICRO_MICRO_CORRIENTE,10);             // 500 uA
    writeEEPROM_16bits(direccion_aux+EEPROM_GALVMICRO_MICRO_TIEMPO_ACTIVO,480);        // 8 m
    writeEEPROM_8bits(direccion_aux+EEPROM_GALVMICRO_MICRO_POLARIDAD,1);               // Bipolar
    writeEEPROM_16bits(direccion_aux+EEPROM_GALVMICRO_MICRO_ANCHO_PULSO,800);          // 800 us
    writeEEPROM_16bits(direccion_aux+EEPROM_GALVMICRO_MICRO_FRECUENCIA,150);           // 150 Hz

    direccion_aux=OFFSET_REGISTRO_PRESETS+PRESET_2;                          // 0=6*0
    writeEEPROM_8bits(direccion_aux,3);                                      // Escribe en la EEPROM el indicador del preset guardado


    // 1------------------------------TDCS-------------------------------
    // Preset 1 - TDCS MAIN
    direccion_aux=OFFSET_EEPROM_PRESET_1+120;
    writeEEPROM_16bits(direccion_aux+EEPROM_TRANSC_CORRIENTE,40);                      // 2000 uA
    writeEEPROM_16bits(direccion_aux+EEPROM_TRANSC_TIEMPO_ACTIVO,1200);                // 20 m  
    writeEEPROM_16bits(direccion_aux+EEPROM_TRANSC_TIEMPO_RAMPA,30);                   // 30 s
    writeEEPROM_32bits(direccion_aux+EEPROM_TRANSC_TAM_ELECTRODO,350);                 // 35 cm2 (está multiplicado por 10 porque es un float, y así guardo los decimales)
    writeEEPROM_8bits(direccion_aux+EEPROM_TRANSC_TCOMP,0);                            // Tiempo no compensado
    writeEEPROM_8bits(direccion_aux+EEPROM_TRANSC_TIEMPO_RAMPA_BAJADA,10);             // 10 s

    direccion_aux=OFFSET_REGISTRO_PRESETS+PRESET_1+6;
    writeEEPROM_8bits(direccion_aux,4);                                     // Escribe en la EEPROM el indicador del preset guardado


    // 2------------------------------SMP--------------------------------

    // Preset 1 - TB (Theta Burst)
    direccion_aux=OFFSET_EEPROM_PRESET_1+240;
    writeEEPROM_8bits(direccion_aux+EEPROM_TB_POLARIDAD,1);
    writeEEPROM_16bits(direccion_aux+EEPROM_TB_ANCHO_PULSO,20*25);
    writeEEPROM_16bits(direccion_aux+EEPROM_TB_NUMERO_PULSOS,4);
    writeEEPROM_8bits(direccion_aux+EEPROM_TB_SEPARACION_PULSOS,10);
    writeEEPROM_8bits(direccion_aux+EEPROM_TB_NUMERO_BURST,10);
    writeEEPROM_16bits(direccion_aux+EEPROM_TB_SEPARACION_BURST,200);
    writeEEPROM_8bits(direccion_aux+EEPROM_TB_NUMERO_TRENES,40);
    writeEEPROM_8bits(direccion_aux+EEPROM_TB_SEPARACION_TRENES,10);
    writeEEPROM_16bits(direccion_aux+EEPROM_TB_CORRIENTE,2);

    direccion_aux=OFFSET_REGISTRO_PRESETS+PRESET_1+12;
    writeEEPROM_8bits(direccion_aux,5);

    // Preset 2 - HIB (High Intensity Burst)
    direccion_aux=OFFSET_EEPROM_PRESET_2+240;
    writeEEPROM_8bits(direccion_aux+EEPROM_TB_POLARIDAD,1);
    writeEEPROM_16bits(direccion_aux+EEPROM_TB_ANCHO_PULSO,10*25);
    writeEEPROM_16bits(direccion_aux+EEPROM_TB_NUMERO_PULSOS,200);
    writeEEPROM_8bits(direccion_aux+EEPROM_TB_SEPARACION_PULSOS,5);
    writeEEPROM_8bits(direccion_aux+EEPROM_TB_NUMERO_BURST,1);
    writeEEPROM_16bits(direccion_aux+EEPROM_TB_SEPARACION_BURST,50);
    writeEEPROM_8bits(direccion_aux+EEPROM_TB_NUMERO_TRENES,1);
    writeEEPROM_8bits(direccion_aux+EEPROM_TB_SEPARACION_TRENES,1);
    writeEEPROM_16bits(direccion_aux+EEPROM_TB_CORRIENTE,145);

    direccion_aux=OFFSET_REGISTRO_PRESETS+PRESET_2+12;
    writeEEPROM_8bits(direccion_aux,5);

    // 3----------------------------ELECTRO------------------------------
    // Preset 1 - NMP LTP
    direccion_aux=OFFSET_EEPROM_PRESET_1_EXT;                                   // 800=120*selec_terapia+4*20
    writeEEPROM_16bits(direccion_aux+EEPROM_ELECTRO_TIEMPO_ACTIVO,5);                  // 5 s
    writeEEPROM_16bits(direccion_aux+EEPROM_ELECTRO_TIEMPO_DESCANSO,55);               // 55 s 
    writeEEPROM_8bits(direccion_aux+EEPROM_ELECTRO_REPETICIONES,5);                    // 5
    writeEEPROM_16bits(direccion_aux+EEPROM_ELECTRO_CORRIENTE,10);                     // 500 uA
    writeEEPROM_16bits(direccion_aux+EEPROM_ELECTRO_FRECUENCIA,100);                   // 100 Hz
    writeEEPROM_8bits(direccion_aux+EEPROM_ELECTRO_POLARIDAD,1);                       // Bipolar
    writeEEPROM_8bits(direccion_aux+EEPROM_ELECTRO_SIMETRIA,1);                        // Simetrica
    writeEEPROM_32bits(direccion_aux+EEPROM_ELECTRO_ANCHO_PULSO_POSITIVO,250);         // 250 us         
    writeEEPROM_32bits(direccion_aux+EEPROM_ELECTRO_ANCHO_PULSO_NEGATIVO,250);         // 250 us
    writeEEPROM_8bits(direccion_aux+EEPROM_ELECTRO_MODULACION,0);                      // Modulación OFF
    
    writeEEPROM_16bits(direccion_aux+EEPROM_ELECTRO_MODULACION_FREC_INI,0);
    writeEEPROM_16bits(direccion_aux+EEPROM_ELECTRO_MODULACION_FREC_FIN,0);
    writeEEPROM_8bits(direccion_aux+EEPROM_ELECTRO_MODULACION_AMPLITUD,0);
    writeEEPROM_32bits(direccion_aux+EEPROM_ELECTRO_MODULACION_PW_INI,0);
    writeEEPROM_32bits(direccion_aux+EEPROM_ELECTRO_MODULACION_PW_FIN,0);
    writeEEPROM_8bits(direccion_aux+EEPROM_ELECTRO_MODULACION_TIEMPO,0);

    direccion_aux=OFFSET_REGISTRO_PRESETS+PRESET_1+18;
    writeEEPROM_8bits(direccion_aux,1);                                         // Escribe en la EEPROM el indicador del preset guardado

    // Preset 2 - NMP LTD
    direccion_aux=OFFSET_EEPROM_PRESET_2_EXT;                                   // 820=120*selec_terapia+5*20
    writeEEPROM_16bits(direccion_aux+EEPROM_ELECTRO_TIEMPO_ACTIVO,960);                // 16 m
    writeEEPROM_16bits(direccion_aux+EEPROM_ELECTRO_TIEMPO_DESCANSO,0);                // 0 s 
    writeEEPROM_8bits(direccion_aux+EEPROM_ELECTRO_REPETICIONES,1);                    // 1
    writeEEPROM_16bits(direccion_aux+EEPROM_ELECTRO_CORRIENTE,10);                     // 500 uA
    writeEEPROM_16bits(direccion_aux+EEPROM_ELECTRO_FRECUENCIA,2);                     // 20 Hz
    writeEEPROM_8bits(direccion_aux+EEPROM_ELECTRO_POLARIDAD,1);                       // Bipolar
    writeEEPROM_8bits(direccion_aux+EEPROM_ELECTRO_SIMETRIA,1);                        // Simetrica
    writeEEPROM_32bits(direccion_aux+EEPROM_ELECTRO_ANCHO_PULSO_POSITIVO,250);         // 250 us         
    writeEEPROM_32bits(direccion_aux+EEPROM_ELECTRO_ANCHO_PULSO_NEGATIVO,250);         // 250 us
    writeEEPROM_8bits(direccion_aux+EEPROM_ELECTRO_MODULACION,0);                      // Modulación OFF

    writeEEPROM_16bits(direccion_aux+EEPROM_ELECTRO_MODULACION_FREC_INI,0);
    writeEEPROM_16bits(direccion_aux+EEPROM_ELECTRO_MODULACION_FREC_FIN,0);
    writeEEPROM_8bits(direccion_aux+EEPROM_ELECTRO_MODULACION_AMPLITUD,0);
    writeEEPROM_32bits(direccion_aux+EEPROM_ELECTRO_MODULACION_PW_INI,0);
    writeEEPROM_32bits(direccion_aux+EEPROM_ELECTRO_MODULACION_PW_FIN,0);
    writeEEPROM_8bits(direccion_aux+EEPROM_ELECTRO_MODULACION_TIEMPO,0);
    
    direccion_aux=OFFSET_REGISTRO_PRESETS+PRESET_2+18;
    writeEEPROM_8bits(direccion_aux,1);                                         // Escribe en la EEPROM el indicador del preset guardado

    //Preset 3 - POINTER SPOT                                                  // Variables guardadas directamente en los menus de sauron al ser solo 2
    direccion_aux=OFFSET_EEPROM_PRESET_3_EXT;                                   // 820=120*selec_terapia+5*20
    // writeEEPROM_16bits(direccion_aux+EEPROM_ELECTRO_TIEMPO_ACTIVO,60);                // 60s o 1m
    // writeEEPROM_16bits(direccion_aux+EEPROM_ELECTRO_TIEMPO_DESCANSO,0);                // 0 s 
    // writeEEPROM_8bits(direccion_aux+EEPROM_ELECTRO_REPETICIONES,0);                    // 0
    // writeEEPROM_16bits(direccion_aux+EEPROM_ELECTRO_CORRIENTE,4);                     // 200 uA
    // writeEEPROM_16bits(direccion_aux+EEPROM_ELECTRO_FRECUENCIA,8);                     // 8 Hz
    // writeEEPROM_8bits(direccion_aux+EEPROM_ELECTRO_POLARIDAD,1);                       // Bipolar
    // writeEEPROM_8bits(direccion_aux+EEPROM_ELECTRO_SIMETRIA,1);                        // Simetrica
    // writeEEPROM_32bits(direccion_aux+EEPROM_ELECTRO_ANCHO_PULSO_POSITIVO,250);         // 250 us         
    // writeEEPROM_32bits(direccion_aux+EEPROM_ELECTRO_ANCHO_PULSO_NEGATIVO,250);         // 250 us
    // writeEEPROM_8bits(direccion_aux+EEPROM_ELECTRO_MODULACION,0);                      // Modulación OFF

    // writeEEPROM_16bits(direccion_aux+EEPROM_ELECTRO_MODULACION_FREC_INI,0);
    // writeEEPROM_16bits(direccion_aux+EEPROM_ELECTRO_MODULACION_FREC_FIN,0);
    // writeEEPROM_8bits(direccion_aux+EEPROM_ELECTRO_MODULACION_AMPLITUD,0);
    // writeEEPROM_32bits(direccion_aux+EEPROM_ELECTRO_MODULACION_PW_INI,0);
    // writeEEPROM_32bits(direccion_aux+EEPROM_ELECTRO_MODULACION_PW_FIN,0);
    // writeEEPROM_8bits(direccion_aux+EEPROM_ELECTRO_MODULACION_TIEMPO,0);
    
    direccion_aux=OFFSET_REGISTRO_PRESETS+PRESET_3+18;
    writeEEPROM_8bits(direccion_aux,1);                                 // Escribe en la EEPROM el indicador del preset guardado
    writeEEPROM_8bits(PRIMER_INICIO,0xFF);                                      // FLAG PRIMER INICIO DE ORCO DESPUES DE PRPGRAMAR EEPROM


}

























