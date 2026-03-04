/*
*   Header File: preset_registers.h
*   
*   Descripci�n: Definiciones de los registros EEPROM
*   
*   Proyecto: EPTE 2
*   Versi�n: 3.0
*
*   Ionclinics & Deionics SL
*/

// ---------------------------- Definiciones ----------------------------                                         

#define OFFSET_INT8                                 1                                                   // Indica que ocupa un byte
#define OFFSET_INT16                                2                                                   // Indica que ocupa dos bytes
#define OFFSET_INT32                                4                                                   // Indica que ocupa cuatro bytes
    
#define PRESET_1                                    0                                                   // Selecci�n del preset 1
#define PRESET_2                                    1                                                   // Selecci�n del preset 2
#define PRESET_3                                    2                                                   // Selecci�n del preset 3
#define PRESET_4                                    3                                                   // Selecci�n del preset 4
#define PRESET_5                                    4                                                   // Selecci�n del preset 5
#define PRESET_6                                    5                                                   // Selecci�n del preset 6

// Registros Presets Galvanica - 7 bytes
#define EEPROM_GALV_CORRIENTE                       0                                                   // Direcci�n Memoria Galvanica - Corriente - 16 bits
#define EEPROM_GALV_TIEMPO_ACTIVO                   EEPROM_GALV_CORRIENTE + OFFSET_INT16                // Direcci�n Memoria Galvanica - Tiempo Activo - 16 bits
#define EEPROM_GALV_TIEMPO_RAMPA                    EEPROM_GALV_TIEMPO_ACTIVO + OFFSET_INT16            // Direcci�n Memoria Galvanica - Tiempo Rampa - 8 bits
#define EEPROM_GALV_TIEMPO_COMP                     EEPROM_GALV_TIEMPO_RAMPA + OFFSET_INT8              // Direcci�n Memoria Galvanica - Compensación de tiempo - 8 bits

// Registro Presets Galvanica+Micro - 15 bytes
#define EEPROM_GALVMICRO_GALV_CORRIENTE             0                                                   // Direcci�n Memoria Galv�nica + Microcorrientes - Corriente Galv�nica - 16 bits
#define EEPROM_GALVMICRO_GALV_TIEMPO_ACTIVO         EEPROM_GALVMICRO_GALV_CORRIENTE + OFFSET_INT16      // Direcci�n Memoria Galv�nica + Microcorrientes - Tiempo Activo Galv�nica - 16 bits
#define EEPROM_GALVMICRO_GALV_TIEMPO_RAMPA          EEPROM_GALVMICRO_GALV_TIEMPO_ACTIVO + OFFSET_INT16  // Direcci�n Memoria Galv�nica + Microcorrientes - Tiempo Rampa Galv�nica - 8 bits
#define EEPROM_GALVMICRO_GALV_TIEMPO_COMP           EEPROM_GALVMICRO_GALV_TIEMPO_RAMPA + OFFSET_INT8    // Direcci�n Memoria Galvanica + Microcorrientes - Compensación de tiempo - 8 bits
#define EEPROM_GALVMICRO_MICRO_CORRIENTE            EEPROM_GALVMICRO_GALV_TIEMPO_COMP + OFFSET_INT8     // Direcci�n Memoria Galv�nica + Microcorrientes - Corriente - 16 bits
#define EEPROM_GALVMICRO_MICRO_TIEMPO_ACTIVO        EEPROM_GALVMICRO_MICRO_CORRIENTE + OFFSET_INT16     // Direcci�n Memoria Galv�nica + Microcorrientes - Tiempo Activo - 16 bits
#define EEPROM_GALVMICRO_MICRO_POLARIDAD            EEPROM_GALVMICRO_MICRO_TIEMPO_ACTIVO + OFFSET_INT16 // Direcci�n Memoria Galv�nica + Microcorrientes - Polaridad - 8 bits
#define EEPROM_GALVMICRO_MICRO_ANCHO_PULSO          EEPROM_GALVMICRO_MICRO_POLARIDAD + OFFSET_INT8      // Direcci�n Memoria Galv�nica + Microcorrientes - Ancho Pulso - 16 bits
#define EEPROM_GALVMICRO_MICRO_FRECUENCIA           EEPROM_GALVMICRO_MICRO_ANCHO_PULSO + OFFSET_INT16   // Direcci�n Memoria Galv�nica + Microcorrientes - Frecuencia - 16 bits
                        
// Registros Presets Transcraneal - 12 bytes
#define EEPROM_TRANSC_CORRIENTE                     0                                                   // Direcci�n Memoria Transcraneal - Corriente - 16 bits
#define EEPROM_TRANSC_TIEMPO_ACTIVO                 EEPROM_TRANSC_CORRIENTE    + OFFSET_INT16           // Direcci�n Memoria Transcraneal - Tiempo Activo - 16 bits
#define EEPROM_TRANSC_TIEMPO_RAMPA                  EEPROM_TRANSC_TIEMPO_ACTIVO + OFFSET_INT16          // Direcci�n Memoria Transcraneal - Tiempo Rampa - 16 bits
#define EEPROM_TRANSC_TAM_ELECTRODO                 EEPROM_TRANSC_TIEMPO_RAMPA + OFFSET_INT16           // Direcci�n Memoria Transcraneal - Superficie Electrodo - 32 bits
#define EEPROM_TRANSC_TCOMP                         EEPROM_TRANSC_TAM_ELECTRODO + OFFSET_INT32          // Direcci�n Memoria Transcraneal - Tiempo compensado - 8 bits  
#define EEPROM_TRANSC_TIEMPO_RAMPA_BAJADA           EEPROM_TRANSC_TCOMP + OFFSET_INT8                   // Direcci�n Memoria Transcraneal - Tiempo de ramap de bajada - 8 bits  

// Registros Presets Electroestimulaci�n - 20 + 16 = 36 bytes (electro + modulación)
#define EEPROM_ELECTRO_TIEMPO_ACTIVO                0                                                   // Direcci�n Memoria Electroestimulaci�n - Tiempo Activo - 16 bits
#define EEPROM_ELECTRO_TIEMPO_DESCANSO              EEPROM_ELECTRO_TIEMPO_ACTIVO + OFFSET_INT16         // Direcci�n Memoria Electroestimulaci�n - Tiempo Descanso - 16 bits
#define EEPROM_ELECTRO_REPETICIONES                 EEPROM_ELECTRO_TIEMPO_DESCANSO + OFFSET_INT16       // Direcci�n Memoria Electroestimulaci�n - Repeticiones - 8 bits
#define EEPROM_ELECTRO_CORRIENTE                    EEPROM_ELECTRO_REPETICIONES + OFFSET_INT8           // Direcci�n Memoria Electroestimulaci�n - Corriente - 16 bits
#define EEPROM_ELECTRO_FRECUENCIA                   EEPROM_ELECTRO_CORRIENTE + OFFSET_INT16             // Direcci�n Memoria Electroestimulaci�n - Frecuencia - 16 bits
#define EEPROM_ELECTRO_POLARIDAD                    EEPROM_ELECTRO_FRECUENCIA + OFFSET_INT16            // Direcci�n Memoria Electroestimulaci�n - Polaridad - 8 bits
#define EEPROM_ELECTRO_SIMETRIA                     EEPROM_ELECTRO_POLARIDAD + OFFSET_INT8              // Direcci�n Memoria Electroestimulaci�n - Simetria - 8 bits
#define EEPROM_ELECTRO_ANCHO_PULSO_POSITIVO         EEPROM_ELECTRO_SIMETRIA + OFFSET_INT8               // Direcci�n Memoria Electroestimulaci�n - Ancho pulso positivo - 32 bits
#define EEPROM_ELECTRO_ANCHO_PULSO_NEGATIVO         EEPROM_ELECTRO_ANCHO_PULSO_POSITIVO + OFFSET_INT32  // Direcci�n Memoria Electroestimulaci�n - Ancho pulso negativo - 32 bits
// Added 05/05/2022
// Registros de la modulación de electro  - 16 bytes
#define EEPROM_ELECTRO_MODULACION                   EEPROM_ELECTRO_ANCHO_PULSO_NEGATIVO + OFFSET_INT32  // Direcci�n Memoria Electroestimulaci�n - Modulación - 8 bits
#define EEPROM_ELECTRO_MODULACION_FREC_INI          EEPROM_ELECTRO_MODULACION + OFFSET_INT8             // Direcci�n Memoria Electroestimulaci�n - Frecuencia inicial - 16 bits
#define EEPROM_ELECTRO_MODULACION_FREC_FIN          EEPROM_ELECTRO_MODULACION_FREC_INI + OFFSET_INT16   // Direcci�n Memoria Electroestimulaci�n - Frecuencia final - 16 bits
#define EEPROM_ELECTRO_MODULACION_AMPLITUD          EEPROM_ELECTRO_MODULACION_FREC_FIN + OFFSET_INT16   // Direcci�n Memoria Electroestimulaci�n - Amplitud - 8 bits
#define EEPROM_ELECTRO_MODULACION_PW_INI            EEPROM_ELECTRO_MODULACION_AMPLITUD + OFFSET_INT8    // Direcci�n Memoria Electroestimulaci�n - PW inicial - 32 bits
#define EEPROM_ELECTRO_MODULACION_PW_FIN            EEPROM_ELECTRO_MODULACION_PW_INI + OFFSET_INT32     // Direcci�n Memoria Electroestimulaci�n - PW final - 32 bits
#define EEPROM_ELECTRO_MODULACION_TIEMPO            EEPROM_ELECTRO_MODULACION_PW_FIN + OFFSET_INT32     // Direcci�n Memoria Electroestimulaci�n - Tiempo modulación - 8 bits

// Registros Presets Sistema Multipulsos - 10 bytes
#define EEPROM_SMP_TIEMPO_ACTIVO                    0                                                   // Direcci�n Memoria SMP - Tiempo Activo - 16 bits
#define EEPROM_SMP_DESFASE_PULSOS                   EEPROM_SMP_TIEMPO_ACTIVO + OFFSET_INT16             // Direcci�n Memoria SMP - Desfase entre pulsos - 32 bits
#define EEPROM_SMP_FRECUENCIA                       EEPROM_SMP_DESFASE_PULSOS + OFFSET_INT32            // Direcci�n Memoria SMP - Frecuencia - 16 bits
#define EEPROM_SMP_ANCHO_PULSO                      EEPROM_SMP_FRECUENCIA + OFFSET_INT16                // Direcci�n Memoria SMP - Ancho de pulso - 16 bits

// Registros Presets Sistema Multipulsos EXTENDED VERSION (Pica-F y Theta-Burst) - 13 bytes
#define EEPROM_TB_POLARIDAD                         0                                                   // Direccion Memoria TB - Polaridad                 - 8 bits
#define EEPROM_TB_ANCHO_PULSO                       EEPROM_TB_POLARIDAD + OFFSET_INT8                   // Direccion Memoria TB - Ancho de pulso            - 16 bits
#define EEPROM_TB_NUMERO_PULSOS                     EEPROM_TB_ANCHO_PULSO + OFFSET_INT16                // Direccion Memoria TB - Numero de pulsos          - 8 bits
#define EEPROM_TB_SEPARACION_PULSOS                 EEPROM_TB_NUMERO_PULSOS + OFFSET_INT16              // Direccion Memoria TB - Separacion de pulsos      - 16 bits
#define EEPROM_TB_NUMERO_BURST                      EEPROM_TB_SEPARACION_PULSOS + OFFSET_INT8           // Direccion Memoria TB - Numero de burst           - 8 bits
#define EEPROM_TB_SEPARACION_BURST                  EEPROM_TB_NUMERO_BURST + OFFSET_INT8                // Direccion Memoria TB - Separacion entre burst    - 16 bits
#define EEPROM_TB_NUMERO_TRENES                     EEPROM_TB_SEPARACION_BURST + OFFSET_INT16           // Direccion Memoria TB - Numero de trenes          - 8 bits
#define EEPROM_TB_SEPARACION_TRENES                 EEPROM_TB_NUMERO_TRENES + OFFSET_INT8               // Direccion Memoria TB - Separacion de trenes      - 8 bits
#define EEPROM_TB_CORRIENTE                         EEPROM_TB_SEPARACION_TRENES + OFFSET_INT8           // Direccion Memoria TB - Corriente                 - 16 bits


#define DELAY_EEPROM_PRESETS                        5                                                   // Delay de 5 ms para la escritura en la EEPROM

#define SELECCIONA_GALV     0
#define SELECCIONA_MICRO    1

// ---------------------------- Prototipo de funciones para la carga de datos en EEPROM ----------------------------      
int8 writeEEPROM_8bits(int16 i16Dir, int8 i8Data);                          // Escritura de 1 byte de la memoria EEPROM 
int8 writeEEPROM_16bits(int16 i16Dir, int16 i16Data);                       // Escritura de 2 bytes de la memoria EEPROM 
int8 writeEEPROM_32bits(int16 i16Dir, int32 i32Data);                       // Escritura de 4 bytes de la memoria EEPROM 
int8 readEEPROM_8bits(int16 i16Dir);                                        // Lectura de 1 byte de la memoria EEPROM
int16 readEEPROM_16bits(int16 i16Dir);                                      // Lectura de 2 bytes de la memoria EEPROM
int32 readEEPROM_32bits(int16 i16Dir);                                      // Lectura de 4 bytes de la memoria EEPROM
#ifdef SAURON
int8 guardarPresets(int8 i8RegistroPreset);                                 // Guarda los datos en el banco de presets seleccionado
int8 cargarPresets(int8 i8RegistroPreset);                                  // Carga los datos del banco de presets seleccionado
int1 cargaElectro();                                                        // Indica si va a cargar un canal de electroestimulaci�n
void initRegistroPresets();                                                 // Inicializa el resgistro de presets
#endif
// ---------------------------- Funciones para la carga de datos en EEPROM ----------------------------

/*
*   Funci�n: writeEEPROM_8bits(int16 i16Dir, int8 i8Data)
*   Descripci�n: Escribe un dato de 8 bits en la memoria EEPROM
*
*   Input:
*         - int16 i16Dir - Direcci�n de memoria a escribir
*         - int8 i8Data - Dato a escribir en memoria
*   Output:
*         - int8 - Return no utilizado
*/
int8 writeEEPROM_8bits(int16 i16Dir, int8 i8Data){                          // Escritura de 1 byte de la memoria EEPROM 

    int8 i8Return=0;                                                        // Variable de retorno (NOT USED)

    write_eeprom(i16Dir,i8Data);                                            // Escribe el byte en EEPROM
    delay_ms(DELAY_EEPROM_PRESETS);                                         // Peque�o delay de escritura

    return i8Return;                                                        // Devuelvo valor
}

/*
*   Funci�n: writeEEPROM_16bits(int16 i16Dir, int16 i16Data)
*   Descripci�n: Escribe un dato de 16 bits en la memoria EEPROM
*
*   Input:
*         - int16 i16Dir - Direcci�n de memoria a escribir
*         - int16 i16Data - Dato a escribir en memoria
*   Output:
*         - int8 - Return no utilizado
*/
int8 writeEEPROM_16bits(int16 i16Dir, int16 i16Data){                       // Escritura de 2 bytes de la memoria EEPROM 

    int8 i8Return=0;                                                        // Variable de retorno (NOT USED)

    write_eeprom(i16Dir,make8(i16Data,1));                                  // Escribe el byte en EEPROM - MSB
    delay_ms(DELAY_EEPROM_PRESETS);                                         // Peque�o delay de escritura

    write_eeprom(i16Dir+1,make8(i16Data,0));                                // Escribe el byte en EEPROM - LSB
    delay_ms(DELAY_EEPROM_PRESETS);                                         // Peque�o delay de escritura

    return i8Return;                                                        // Devuelvo valor
}

/*
*   Funci�n: writeEEPROM_32bits(int16 i16Dir, int32 i32Data)
*   Descripci�n: Escribe un dato de 32 bits en la memoria EEPROM
*
*   Input:
*         - int16 i16Dir - Direcci�n de memoria a escribir
*         - int32 i32Data - Dato a escribir en memoria
*   Output:
*         - int8 - Return no utilizado
*/
int8 writeEEPROM_32bits(int16 i16Dir, int32 i32Data){                       // Escritura de 3 bytes de la memoria EEPROM

    int8 i8Return=0;                                                        // Variable de retorno (NOT USED)

    write_eeprom(i16Dir,make8(i32Data,3));                                  // Escribe el byte en EEPROM - MSB
    delay_ms(DELAY_EEPROM_PRESETS);                                         // Peque�o delay de escritura

    write_eeprom(i16Dir+1,make8(i32Data,2));                                // Escribe el byte en EEPROM - mMSB
    delay_ms(DELAY_EEPROM_PRESETS);                                         // Peque�o delay de escritura

    write_eeprom(i16Dir+2,make8(i32Data,1));                                // Escribe el byte en EEPROM - mLSB
    delay_ms(DELAY_EEPROM_PRESETS);                                         // Peque�o delay de escritura

    write_eeprom(i16Dir+3,make8(i32Data,0));                                // Escribe el byte en EEPROM - LSB
    delay_ms(DELAY_EEPROM_PRESETS);                                         // Peque�o delay de escritura

    return i8Return;                                                        // Devuelvo valor
}

/*
*   Funci�n: readEEPROM_8bits(int16 i16Dir)
*   Descripci�n: Lee un dato de 8 bits de la memoria EEPROM
*
*   Input:
*         - int16 i16Dir - Direcci�n de memoria a leer
*   Output:
*         - int8 - Devuelve el valor del registro
*/
int8 readEEPROM_8bits(int16 i16Dir){                                        // Lectura de 1 byte de la memoria EEPROM
    return read_eeprom(i16Dir);                                             // Devuelve el valor de la direcci�n de memoria
}

/*
*   Funci�n: readEEPROM_16bits(int16 i16Dir)
*   Descripci�n: Lee un dato de 16 bits de la memoria EEPROM
*
*   Input:
*         - int16 i16Dir - Direcci�n de memoria a leer
*   Output:
*         - int16 - Devuelve el valor del registro
*/
int16 readEEPROM_16bits(int16 i16Dir){                                      // Lectura de 2 byte de la memoria EEPROM
    return make16(read_eeprom(i16Dir),read_eeprom(i16Dir+1));               // Devuelve los valores de la direcci�n de memoria y los junta en un int16
}    

/*
*   Funci�n: readEEPROM_32bits(int16 i16Dir)
*   Descripci�n: Lee un dato de 32 bits de la memoria EEPROM
*
*   Input:
*         - int16 i16Dir - Direcci�n de memoria a leer
*   Output:
*         - int32 - Devuelve el valor del registro
*/
int32 readEEPROM_32bits(int16 i16Dir){                                      // Lectura de 3 byte de la memoria EEPROM
    return make32(read_eeprom(i16Dir),read_eeprom(i16Dir+1),read_eeprom(i16Dir+2),read_eeprom(i16Dir+3));       // Devuelve los valores de la direcci�n de memoria y los junta en un int32
}

#ifdef SAURON
/*
*   Funci�n: guardarPresets(int8 i8RegistroPreset)
*   Descripci�n: Guarda los presets en la memoria EEPROM
*
*   Input:
*         - int8 i8RegistroPreset - Regsitro del preset a guardar
*   Output:
*         - int8 - No utilizado
*/
int8 guardarPresets(int8 i8RegistroPreset){                                 // Guarda los datos en el banco de presets seleccionado

    int8 i8Return=0;                                                        // Variable de retorno
    int16 i16DirEEPROM=0;                                                   // Variable de direcci�n global de inicio de EEPROM
    int8 i8Registro=0;

    // Indica direcci�n de memoria de inicio para guardar
    if(i8SeleccionTerapia!=3){
        switch(i8RegistroPreset){                                               // Selecci�n del registro de presets
            // case PRESET_1:                                                      // Selecci�n del preset 1    
            //     i16DirEEPROM=OFFSET_EEPROM_PRESET_1+120*i8SeleccionTerapia;                                     // Asigna la posici�n de memoria correspondiente
            //     break;
            // case PRESET_2:                                                      // Selecci�n del preset 2
            //     i16DirEEPROM=OFFSET_EEPROM_PRESET_2+120*i8SeleccionTerapia;                              // Asigna la posici�n de memoria correspondiente
            //     break;
             case PRESET_2:                                                      // Selecci�n del preset 2
                if(i8SeleccionTerapia==1){
                    i16DirEEPROM=OFFSET_EEPROM_PRESET_2+120;                            // Asigna la posici�n de memoria correspondiente
                }                                                               // Asigna la posici�n de memoria correspondiente
                break;
            case PRESET_3:                                                      // Selecci�n del preset 3
                i16DirEEPROM=OFFSET_EEPROM_PRESET_3+120*i8SeleccionTerapia;                            // Asigna la posici�n de memoria correspondiente
                break;
            case PRESET_4:                                                      // Selecci�n del preset 4
                i16DirEEPROM=OFFSET_EEPROM_PRESET_4+120*i8SeleccionTerapia;                            // Asigna la posici�n de memoria correspondiente
                break;
            // case PRESET_5:                                                      // Selecci�n del preset 5
            //     if(i8SeleccionTerapia==1){
            //         i16DirEEPROM=OFFSET_EEPROM_PRESET_5+120;                            // Asigna la posici�n de memoria correspondiente
            //     }
                break;
            case PRESET_5:                                                      // Selecci�n del preset 5
                i16DirEEPROM=OFFSET_EEPROM_PRESET_5+120*i8SeleccionTerapia;                            // Asigna la posici�n de memoria correspondiente
                break;
            case PRESET_6:                                                      // Selecci�n del preset 6
                i16DirEEPROM=OFFSET_EEPROM_PRESET_6+120*i8SeleccionTerapia;                            // Asigna la posici�n de memoria correspondiente
                break;
        }
    }else{
        switch(i8RegistroPreset){                                               // Selecci�n del registro de presets
            // case PRESET_1:                                                      // Selecci�n del preset 1    
            //     i16DirEEPROM=OFFSET_EEPROM_PRESET_1_EXT;                                     // Asigna la posici�n de memoria correspondiente
            //     break;
            // case PRESET_2:                                                      // Selecci�n del preset 2
            //     i16DirEEPROM=OFFSET_EEPROM_PRESET_2_EXT;                              // Asigna la posici�n de memoria correspondiente
            //     break;
            // case PRESET_3:                                                      // Selecci�n del preset 3
            //     i16DirEEPROM=OFFSET_EEPROM_PRESET_3_EXT;                            // Asigna la posici�n de memoria correspondiente
            //     break;
            case PRESET_4:                                                      // Selecci�n del preset 4
                i16DirEEPROM=OFFSET_EEPROM_PRESET_4_EXT;                            // Asigna la posici�n de memoria correspondiente
                break;
            case PRESET_5:                                                      // Selecci�n del preset 5
                i16DirEEPROM=OFFSET_EEPROM_PRESET_5_EXT;                            // Asigna la posici�n de memoria correspondiente
                break;
            case PRESET_6:                                                      // Selecci�n del preset 6
                i16DirEEPROM=OFFSET_EEPROM_PRESET_6_EXT;                            // Asigna la posici�n de memoria correspondiente
                break;
        }
    }


    // Bloque escribir en memoria
    switch(i8VariablesPreset){                                                                          // Dependiendo del tratamiento a guardar
        case PRESET_MOD:
        case PRESET_ELECTRO:                                                                            // Variables Electro a memoria
            writeEEPROM_16bits(i16DirEEPROM+EEPROM_ELECTRO_TIEMPO_ACTIVO,i16TacElec[i8ConfigCanal]);                // Guarda en Memoria Electroestimulaci�n - Tiempo Activo - 16 bits    
            writeEEPROM_16bits(i16DirEEPROM+EEPROM_ELECTRO_TIEMPO_DESCANSO,i16TdElec[i8ConfigCanal]);               // Guarda en Memoria Electroestimulaci�n - Tiempo Descanso - 16 bits     
            writeEEPROM_8bits(i16DirEEPROM+EEPROM_ELECTRO_REPETICIONES,i8Nrep[i8ConfigCanal]);                      // Guarda en Memoria Electroestimulaci�n - Repeticiones - 8 bits    
            writeEEPROM_16bits(i16DirEEPROM+EEPROM_ELECTRO_CORRIENTE,i16IElec[i8ConfigCanal]);                      // Guarda en Memoria Electroestimulaci�n - Corriente - 16 bits
            writeEEPROM_16bits(i16DirEEPROM+EEPROM_ELECTRO_FRECUENCIA,i16frecElec[i8ConfigCanal]);                  // Guarda en Memoria Electroestimulaci�n - Frecuencia - 16 bits
            writeEEPROM_8bits(i16DirEEPROM+EEPROM_ELECTRO_POLARIDAD,bPolaridadElec[i8ConfigCanal]);                 // Guarda en Memoria Electroestimulaci�n - Polaridad - 8 bits
            writeEEPROM_8bits(i16DirEEPROM+EEPROM_ELECTRO_SIMETRIA,bSimetriaElec[i8ConfigCanal]);                   // Guarda en Memoria Electroestimulaci�n - Simetria - 8 bits
            writeEEPROM_32bits(i16DirEEPROM+EEPROM_ELECTRO_ANCHO_PULSO_POSITIVO,i16PW_plusElec[i8ConfigCanal]);     // Guarda en Memoria Electroestimulaci�n - Ancho pulso positivo - 16 bits            
            writeEEPROM_32bits(i16DirEEPROM+EEPROM_ELECTRO_ANCHO_PULSO_NEGATIVO,i16PW_minusElec[i8ConfigCanal]);    // Guarda en Memoria Electroestimulaci�n - Ancho pulso negativo - 16 bits     
            // Added 05/05/2022
            // Se convierte en un preset independiente PRESET_MOD
            writeEEPROM_8bits(i16DirEEPROM+EEPROM_ELECTRO_MODULACION,i8SeleccionMod);
            writeEEPROM_16bits(i16DirEEPROM+EEPROM_ELECTRO_MODULACION_FREC_INI,i16FrecInicialMod);
            writeEEPROM_16bits(i16DirEEPROM+EEPROM_ELECTRO_MODULACION_FREC_FIN,i16FrecFinalMod);
            writeEEPROM_8bits(i16DirEEPROM+EEPROM_ELECTRO_MODULACION_AMPLITUD,i8ModulacionAM);
            writeEEPROM_32bits(i16DirEEPROM+EEPROM_ELECTRO_MODULACION_PW_INI,i32PWInicialMod);
            writeEEPROM_32bits(i16DirEEPROM+EEPROM_ELECTRO_MODULACION_PW_FIN,i32PWFinalMod);
            writeEEPROM_8bits(i16DirEEPROM+EEPROM_ELECTRO_MODULACION_TIEMPO,i8Tmodulacion);
            break;                
        case PRESET_GALV:                                                                               // Variables Galvanica a memoria
            writeEEPROM_16bits(i16DirEEPROM+EEPROM_GALV_CORRIENTE,i16IGalv[SELECCIONA_GALV]);                       // Guarda en Memoria Galvanica - Corriente - 16 bits                
            writeEEPROM_16bits(i16DirEEPROM+EEPROM_GALV_TIEMPO_ACTIVO,i16TGalv[bSeleccionGalvanica]);               // Guarda en Memoria Galvanica - Tiempo Activo - 16 bits    
            writeEEPROM_8bits(i16DirEEPROM+EEPROM_GALV_TIEMPO_RAMPA,i8TrampaGalv[SELECCIONA_GALV]);                 // Guarda en Memoria Galvanica - Tiempo Rampa - 16 bits
            writeEEPROM_8bits(i16DirEEPROM+EEPROM_GALV_TIEMPO_COMP,bTiempoAutoGalv);                                // Guarda en Memoria Galvanica - Compensación de tiempo - 8 bits
            break;
        case PRESET_MICRO:
        case PRESET_GALVMICRO:                                                                          // Variables Galv�nica a memoria
            writeEEPROM_16bits(i16DirEEPROM+EEPROM_GALVMICRO_GALV_CORRIENTE,i16IGalv[SELECCIONA_MICRO]);            // Guarda en Memoria Galv�nica + Microcorrientes - Corriente Galv�nica - 16 bits
            writeEEPROM_16bits(i16DirEEPROM+EEPROM_GALVMICRO_GALV_TIEMPO_ACTIVO,i16TGalv[bSeleccionGalvanica]);     // Guarda en Memoria Galv�nica + Microcorrientes - Tiempo Activo Galv�nica - 16 bits    
            writeEEPROM_8bits(i16DirEEPROM+EEPROM_GALVMICRO_GALV_TIEMPO_RAMPA,i8TrampaGalv[SELECCIONA_MICRO]);      // Guarda en Memoria Galv�nica + Microcorrientes - Tiempo Rampa Galv�nica - 8 bits
            writeEEPROM_8bits(i16DirEEPROM+EEPROM_GALVMICRO_GALV_TIEMPO_COMP,bTiempoAutoGalv);                                // Guarda en Memoria Galvanica + Microcorrientes - Compensación de tiempo - 8 bits
            writeEEPROM_16bits(i16DirEEPROM+EEPROM_GALVMICRO_MICRO_CORRIENTE,i16Imicro);                            // Guarda en Memoria Galv�nica + Microcorrientes - Corriente - 16 bits
            writeEEPROM_16bits(i16DirEEPROM+EEPROM_GALVMICRO_MICRO_TIEMPO_ACTIVO,i16Tmicro);                        // Guarda en Memoria Galv�nica + Microcorrientes - Tiempo Activo - 16 bits    
            writeEEPROM_8bits(i16DirEEPROM+EEPROM_GALVMICRO_MICRO_POLARIDAD,bPolaridadMicro);                       // Guarda en Memoria Galv�nica + Microcorrientes - Polaridad - 8 bits
            writeEEPROM_16bits(i16DirEEPROM+EEPROM_GALVMICRO_MICRO_ANCHO_PULSO,i16PWmicro);                         // Guarda en Memoria Galv�nica + Microcorrientes - Ancho Pulso - 16 bits    
            writeEEPROM_16bits(i16DirEEPROM+EEPROM_GALVMICRO_MICRO_FRECUENCIA,i16frecmicro);                        // Guarda en Memoria Galv�nica + Microcorrientes - Frecuencia - 16 bits
            break;
        case PRESET_TRANSCRANEAL:                                                                       // Variables Transcraneal a memoria
            writeEEPROM_16bits(i16DirEEPROM+EEPROM_TRANSC_CORRIENTE,i16ITrans);                                     // Guarda en Memoria Transcraneal - Corriente - 16 bits
            writeEEPROM_16bits(i16DirEEPROM+EEPROM_TRANSC_TIEMPO_ACTIVO,i16TTrans);                                 // Guarda en Memoria Transcraneal - Tiempo Activo - 16 bits    
            writeEEPROM_16bits(i16DirEEPROM+EEPROM_TRANSC_TIEMPO_RAMPA,i8TrampaTrans);                               // Guarda en Memoria Transcraneal - Tiempo Rampa - 16 bits    
            writeEEPROM_32bits(i16DirEEPROM+EEPROM_TRANSC_TAM_ELECTRODO,fSuperficieElectrodo*10);                      // Guarda en Memoria Transcraneal - Superficie Electrodo - 32 bits    
            writeEEPROM_8bits(i16DirEEPROM+EEPROM_TRANSC_TCOMP,bTiempoAutoTrans);
            writeEEPROM_8bits(i16DirEEPROM+EEPROM_TRANSC_TIEMPO_RAMPA_BAJADA,i8TrampaTransBajada);
            break;
        case PRESET_TB:                                                                                // Variables SMP a memoria  
            writeEEPROM_8bits(i16DirEEPROM+EEPROM_TB_POLARIDAD,bPolaridadTB);
            writeEEPROM_16bits(i16DirEEPROM+EEPROM_TB_ANCHO_PULSO,i16PWBurstTB);
            writeEEPROM_16bits(i16DirEEPROM+EEPROM_TB_NUMERO_PULSOS,i16NPulsosBurstTB);
            writeEEPROM_8bits(i16DirEEPROM+EEPROM_TB_SEPARACION_PULSOS,i8SepPulsosTB);
            writeEEPROM_8bits(i16DirEEPROM+EEPROM_TB_NUMERO_BURST,i8NBurstTrenTB);
            writeEEPROM_16bits(i16DirEEPROM+EEPROM_TB_SEPARACION_BURST,i16SepBurstTB);
            writeEEPROM_8bits(i16DirEEPROM+EEPROM_TB_NUMERO_TRENES,i8NTrenesTB);
            writeEEPROM_8bits(i16DirEEPROM+EEPROM_TB_SEPARACION_TRENES,i8SepTrenesTB);
            writeEEPROM_16bits(i16DirEEPROM+EEPROM_TB_CORRIENTE,i16CorrienteTB);
            break;
    }

    i8Registro=i8RegistroPreset+6*i8SeleccionTerapia;
    i8RegistroPresets[i8Registro]=i8VariablesPreset;    // Added 12/06/2022 Para dirigirme a la parte del array que corresponda
                                                        // Indica que ha guardado en el PRESET_i8RegistroPreset el valor de i8VariablesPreset
    writeEEPROM_8bits(OFFSET_REGISTRO_PRESETS+i8Registro,i8VariablesPreset);                      // Escribe en la EEPROM el indicador del preset guardado
    
    return i8Return;                                                                                    // Devuelve el valor
}

/*
*   Funci�n: cargarPresets(int8 i8RegistroPreset)
*   Descripci�n: Carga los datos de la memoria EEPROM 
*                   para ponerlos en las variables correspondientes
*
*   Input:
*         - int8 i8RegistroPreset - Registro del preset a cargar
*   Output:
*         - int8 - 
*/
int8 cargarPresets(int8 i8RegistroPreset){                                      // Carga los datos del banco de presets seleccionado

    int8 i8Return=0;
    int16 i16DirEEPROM=0;                                                       // Variable de direcci�n global de inicio de EEPROM
    int8 i8Registro=0;

    // Indica direcci�n de memoria de inicio para guardar
    if(i8SeleccionTerapia!=3){
        switch(i8RegistroPreset){                                                   // Selecci�n del registro de presets


            case PRESET_1:                                                          // Selecci�n del preset 1    
                switch(i8SeleccionTerapia){
                    case 0:
                        i16DirEEPROM=OFFSET_EEPROM_PRESET_1;
                        break;
                    case 1:
                        i16DirEEPROM=OFFSET_EEPROM_PRESET_1+120;
                        break;
                    case 2:
                        i16DirEEPROM=OFFSET_EEPROM_PRESET_1+240;
                        break;
                }                                        // Asigna la posici�n de memoria correspondiente
                break;
            case PRESET_2:                                                          // Selecci�n del preset 2
                switch(i8SeleccionTerapia){
                    case 0:
                        i16DirEEPROM=OFFSET_EEPROM_PRESET_2;
                        break;
                    case 1:
                        i16DirEEPROM=OFFSET_EEPROM_PRESET_2+120;
                        break;
                    case 2:
                        i16DirEEPROM=OFFSET_EEPROM_PRESET_2+240;
                        break;
                }
                break;
            case PRESET_3:                                                          // Selecci�n del preset 3
                i16DirEEPROM=OFFSET_EEPROM_PRESET_3+120*i8SeleccionTerapia;                                // Asigna la posici�n de memoria correspondiente 
                break;
            case PRESET_4:                                                          // Selecci�n del preset 4
                i16DirEEPROM=OFFSET_EEPROM_PRESET_4+120*i8SeleccionTerapia;                                // Asigna la posici�n de memoria correspondiente
                break;
            case PRESET_5:                                                          // Selecci�n del preset 5
                i16DirEEPROM=OFFSET_EEPROM_PRESET_5+120*i8SeleccionTerapia;                                // Asigna la posici�n de memoria correspondiente
                break;
            case PRESET_6:                                                          // Selecci�n del preset 6
                i16DirEEPROM=OFFSET_EEPROM_PRESET_6+120*i8SeleccionTerapia;                                // Asigna la posici�n de memoria correspondiente
                break;  


            // case PRESET_1:                                                          // Selecci�n del preset 1    
            //     i16DirEEPROM=OFFSET_EEPROM_PRESET_1+120*i8SeleccionTerapia;                                         // Asigna la posici�n de memoria correspondiente
            //     break;
            // case PRESET_2:                                                          // Selecci�n del preset 2
            //     i16DirEEPROM=OFFSET_EEPROM_PRESET_2+120*i8SeleccionTerapia;                                  // Asigna la posici�n de memoria correspondiente
            //     break;
            // case PRESET_3:                                                          // Selecci�n del preset 3
            //     i16DirEEPROM=OFFSET_EEPROM_PRESET_3+120*i8SeleccionTerapia;                                // Asigna la posici�n de memoria correspondiente
            //     break;
            // case PRESET_4:                                                          // Selecci�n del preset 4
            //     i16DirEEPROM=OFFSET_EEPROM_PRESET_4+120*i8SeleccionTerapia;                                // Asigna la posici�n de memoria correspondiente
            //     break;
            // case PRESET_5:                                                          // Selecci�n del preset 5
            //     // i16DirEEPROM=OFFSET_EEPROM_PRESET_5+120*i8SeleccionTerapia;                                // Asigna la posici�n de memoria correspondiente
            //     switch(i8SeleccionTerapia){
            //         case 0:
            //             i16DirEEPROM=OFFSET_EEPROM_PRESET_5;
            //             break;
            //         case 1:
            //             i16DirEEPROM=OFFSET_EEPROM_PRESET_5+120;
            //             break;
            //         case 2:
            //             i16DirEEPROM=OFFSET_EEPROM_PRESET_5+240;
            //             break;
            //     }
            //     break;
            // case PRESET_6:                                                          // Selecci�n del preset 6
            //     // i16DirEEPROM=OFFSET_EEPROM_PRESET_6+120*i8SeleccionTerapia;                                // Asigna la posici�n de memoria correspondiente
            //     switch(i8SeleccionTerapia){
            //         case 0:
            //             i16DirEEPROM=OFFSET_EEPROM_PRESET_6;
            //             break;
            //         case 1:
            //             i16DirEEPROM=OFFSET_EEPROM_PRESET_6+120;
            //             break;
            //         case 2:
            //             i16DirEEPROM=OFFSET_EEPROM_PRESET_6+240;
            //             break;
            //     }
            //     break;   
        }
    }else{
        switch(i8RegistroPreset){                                               // Selecci�n del registro de presets
            case PRESET_1:                                                      // Selecci�n del preset 1    
                i16DirEEPROM=OFFSET_EEPROM_PRESET_1_EXT;                                     // Asigna la posici�n de memoria correspondiente
                break;
            case PRESET_2:                                                      // Selecci�n del preset 2
                i16DirEEPROM=OFFSET_EEPROM_PRESET_2_EXT;                              // Asigna la posici�n de memoria correspondiente
                break;
            case PRESET_3:                                                      // Selecci�n del preset 3
                i16DirEEPROM=OFFSET_EEPROM_PRESET_3_EXT;                            // Asigna la posici�n de memoria correspondiente
                break;
            case PRESET_4:                                                      // Selecci�n del preset 4
                i16DirEEPROM=OFFSET_EEPROM_PRESET_4_EXT;                            // Asigna la posici�n de memoria correspondiente
                break;
            case PRESET_5:                                                      // Selecci�n del preset 5
                i16DirEEPROM=OFFSET_EEPROM_PRESET_5_EXT;                            // Asigna la posici�n de memoria correspondiente
                break;
            case PRESET_6:                                                      // Selecci�n del preset 6
                i16DirEEPROM=OFFSET_EEPROM_PRESET_6_EXT;                            // Asigna la posici�n de memoria correspondiente
                break;
        }
    }
    
    i8Registro=i8RegistroPreset+6*i8SeleccionTerapia;                     // Added 12/06/2022 Añado la variable de registro nueva
    i8VariablesPreset=i8RegistroPresets[i8Registro];                      // Indica el valor del preset a cargar
    
    // Lectura y carga de datos
    switch(i8VariablesPreset){                                                  // Dependiendo del tratamiento a guardar
        case PRESET_MOD:
        case PRESET_ELECTRO:                                                    // Variables Electro a memoria
            if(i8VariablesPreset!=PRESET_MOD){
                if(i8CanalesElectroCarga<=SEL_CANAL_C){                             // Si se trata de un tratamiento de un canal (m�scara)
                    i8DeboPintar=(1<<i8CanalesElectroCarga);                        // Inidica el canal que debe de cargar los datos
                    i8ConfigCanal=i8CanalesElectroCarga;                            // Indica el canal a configurar
                }else if(i8CanalesElectroCarga<=SEL_CANAL_AC){                      // Si se trata de un tratamiento de dos canales
                    switch(i8CanalesElectroCarga){                                  // Dependiendo de la combinaci�n de canales elegida
                        case SEL_CANAL_AB:                                          // Canales AB
                            i8DeboPintar=3;                                         // Indica que canales deben cargar los datos (m�scara)
                            i8ConfigCanal=CHA_C;                                    // Debe mostrar este canal al entrar en configuraci�n de tratamientos
                            break;
                        case SEL_CANAL_BC:                                          // Canales BC                                       
                            i8DeboPintar=6;                                         // Indica que canales deben cargar los datos (m�scara)
                            i8ConfigCanal=CHB_C;                                    // Debe mostrar este canal al entrar en configuraci�n de tratamientos    
                            break;
                        case SEL_CANAL_AC:                                          // Canales AC
                            i8DeboPintar=5;                                         // Indica que canales deben cargar los datos (m�scara)    
                            i8ConfigCanal=CHA_C;                                    // Debe mostrar este canal al entrar en configuraci�n de tratamientos        
                            break;
                    }       
                }else if(i8CanalesElectroCarga==SEL_CANAL_ABC){                     // Si se trata de un tratamiento de 3 canales
                    i8DeboPintar=7;                                                 // Indica que canales deben cargar los datos (m�scara)  
                    i8ConfigCanal=CHA_C;                                            // Debe mostrar este canal al entrar en configuraci�n de tratamientos 
                }
            }else{
                i8DeboPintar=(1<<i8CanalesElectroCarga);
                i8ConfigCanal=CHB_C;
            }
            for(int8 i8Cont=0; i8Cont<NUMERO_CANALES_TOTAL; i8Cont++){          // Recorre todos los canales
                if(i8DeboPintar&(1<<i8Cont)){                                   // Si el canal actual debe de ser actualizado con los valores del preset
                    i16TacElec[i8Cont]=readEEPROM_16bits(i16DirEEPROM+EEPROM_ELECTRO_TIEMPO_ACTIVO);             // Carga en variable Electroestimulaci�n - Tiempo Activo - 16 bits
                    i16TdElec[i8Cont]=readEEPROM_16bits(i16DirEEPROM+EEPROM_ELECTRO_TIEMPO_DESCANSO);            // Carga en variable Electroestimulaci�n - Tiempo Descanso - 16 bits                   
                    i8Nrep[i8Cont]=readEEPROM_8bits(i16DirEEPROM+EEPROM_ELECTRO_REPETICIONES);                   // Carga en variable Electroestimulaci�n - Repeticiones - 8 bits    
                    i16IElec[i8Cont]=readEEPROM_16bits(i16DirEEPROM+EEPROM_ELECTRO_CORRIENTE);                   // Carga en variable Electroestimulaci�n - Corriente - 16 bits
                    i16frecElec[i8Cont]=readEEPROM_16bits(i16DirEEPROM+EEPROM_ELECTRO_FRECUENCIA);               // Carga en variable Electroestimulaci�n - Frecuencia - 16 bits
                    bPolaridadElec[i8Cont]=readEEPROM_8bits(i16DirEEPROM+EEPROM_ELECTRO_POLARIDAD);              // Carga en variable Electroestimulaci�n - Polaridad - 8 bits
                    bSimetriaElec[i8Cont]=readEEPROM_8bits(i16DirEEPROM+EEPROM_ELECTRO_SIMETRIA);                // Carga en variable Electroestimulaci�n - Simetria - 8 bits
                    i16PW_plusElec[i8Cont]=readEEPROM_32bits(i16DirEEPROM+EEPROM_ELECTRO_ANCHO_PULSO_POSITIVO);  // Carga en variable Electroestimulaci�n - Ancho pulso positivo - 16 bits            
                    i16PW_minusElec[i8Cont]=readEEPROM_32bits(i16DirEEPROM+EEPROM_ELECTRO_ANCHO_PULSO_NEGATIVO); // Carga en variable Electroestimulaci�n - Ancho pulso negativo - 16 bits            
                    
                    // Added 05/05/2022
                    // Se convierte la modulación en un preset independiente PRESET_MOD
                    i8SeleccionMod=readEEPROM_8bits(i16DirEEPROM+EEPROM_ELECTRO_MODULACION);
                    i16FrecInicialMod=readEEPROM_16bits(i16DirEEPROM+EEPROM_ELECTRO_MODULACION_FREC_INI);
                    i16FrecFinalMod=readEEPROM_16bits(i16DirEEPROM+EEPROM_ELECTRO_MODULACION_FREC_FIN);
                    i8ModulacionAM=readEEPROM_8bits(i16DirEEPROM+EEPROM_ELECTRO_MODULACION_AMPLITUD);
                    i32PWInicialMod=readEEPROM_32bits(i16DirEEPROM+EEPROM_ELECTRO_MODULACION_PW_INI);
                    i32PWFinalMod=readEEPROM_32bits(i16DirEEPROM+EEPROM_ELECTRO_MODULACION_PW_FIN);
                    i8Tmodulacion=readEEPROM_8bits(i16DirEEPROM+EEPROM_ELECTRO_MODULACION_TIEMPO);
                }
            }
            iMenuActual=40;                 // Salto al men� de configuraci�n de tratamiento en electroestimulacion
            Anterior_giPos[0]=3;            // Inicializo variables de posici�n
            Anterior_giPos[1]=0;            // Inicializo variables de posici�n
            giPos=0;                        // Inicializo variable de posici�n global
            break;
        case PRESET_GALV:                                                                               // Variables Galvanica a memoria
            i16IGalv[SELECCIONA_GALV]=readEEPROM_16bits(i16DirEEPROM+EEPROM_GALV_CORRIENTE);            // Carga en variable Galvanica - Corriente - 16 bits                
            i16TGalv[bSeleccionGalvanica]=readEEPROM_16bits(i16DirEEPROM+EEPROM_GALV_TIEMPO_ACTIVO);    // Carga en variable Galvanica - Tiempo Activo - 16 bits    
            i8TrampaGalv[SELECCIONA_GALV]=readEEPROM_8bits(i16DirEEPROM+EEPROM_GALV_TIEMPO_RAMPA);      // Carga en variable Galvanica - Tiempo Rampa - 16 bits
            bTiempoAutoGalv=readEEPROM_8bits(i16DirEEPROM+EEPROM_GALV_TIEMPO_COMP);                    // Carga en variable Galvanica - Compensación de tiempo - 8 bits
            iMenuActual=20;                 // Salto al men� de configuraci�n de tratamiento en galv�nica            
            bSeleccionGalvanica=0;          // Selecciono tratamiento galv�nica
            i8SeleccionGalvMicro=0;
            Anterior_giPos[0]=1;            // Inicializo variables de posici�n
            Anterior_giPos[1]=0;            // Inicializo variables de posici�n
            giPos=0;                        // Inicializo variable de posici�n global
            giPosRulancha=i16IGalv[SELECCIONA_GALV];    // Selecciona corriente galv�nica en galv�nica
            break;
        case PRESET_MICRO:
        case PRESET_GALVMICRO:                                                                          // Variables Galv�nica a memoria
            i16IGalv[SELECCIONA_MICRO]=readEEPROM_16bits(i16DirEEPROM+EEPROM_GALVMICRO_GALV_CORRIENTE);         // Carga en variable Galv�nica + Microcorrientes - Corriente Galv�nica - 16 bits
            i16TGalv[bSeleccionGalvanica]=readEEPROM_16bits(i16DirEEPROM+EEPROM_GALVMICRO_GALV_TIEMPO_ACTIVO);  // Carga en variable Galv�nica + Microcorrientes - Tiempo Activo Galv�nica - 16 bits    
            i8TrampaGalv[SELECCIONA_MICRO]=readEEPROM_8bits(i16DirEEPROM+EEPROM_GALVMICRO_GALV_TIEMPO_RAMPA);   // Carga en variable Galv�nica + Microcorrientes - Tiempo Rampa Galv�nica - 8 bits
            bTiempoAutoGalv=readEEPROM_8bits(i16DirEEPROM+EEPROM_GALVMICRO_GALV_TIEMPO_COMP);                   // Carga en variable Galvanica + Microcorrientes - Compensación de tiempo - 8 bits
            i16Imicro=readEEPROM_16bits(i16DirEEPROM+EEPROM_GALVMICRO_MICRO_CORRIENTE);                         // Carga en variable Galv�nica + Microcorrientes - Corriente - 16 bits
            i16Tmicro=readEEPROM_16bits(i16DirEEPROM+EEPROM_GALVMICRO_MICRO_TIEMPO_ACTIVO);                     // Carga en variable Galv�nica + Microcorrientes - Tiempo Activo - 16 bits    
            bPolaridadMicro=readEEPROM_8bits(i16DirEEPROM+EEPROM_GALVMICRO_MICRO_POLARIDAD);                    // Carga en variable Galv�nica + Microcorrientes - Polaridad - 8 bits
            i16PWmicro=readEEPROM_16bits(i16DirEEPROM+EEPROM_GALVMICRO_MICRO_ANCHO_PULSO);                      // Carga en variable Galv�nica + Microcorrientes - Ancho Pulso - 16 bits    
            i16frecmicro=readEEPROM_16bits(i16DirEEPROM+EEPROM_GALVMICRO_MICRO_FRECUENCIA);                     // Carga en variable Galv�nica + Microcorrientes - Frecuencia - 16 bits
            iMenuActual=20;                 // Salto al men� de configuraci�n de tratamiento en galv�nica+microcorrientes           
            bSeleccionGalvanica=1;          // Selecciono tratamiento galv�nica+micro    
            i8SeleccionGalvMicro=2;
            if(i8VariablesPreset==PRESET_MICRO){
                i8SeleccionGalvMicro=1;
            }
            Anterior_giPos[0]=1;            // Inicializo variables de posici�n    
            Anterior_giPos[1]=0;            // Inicializo variables de posici�n
            giPos=0;                        // Inicializo variable de posici�n global
            giPosRulancha=i16IGalv[SELECCIONA_MICRO];   // Selecciona corriente galv�nica en galv�nica
            break;
        case PRESET_TRANSCRANEAL:                                                                       // Variables Transcraneal a memoria
            i16Itrans=readEEPROM_16bits(i16DirEEPROM+EEPROM_TRANSC_CORRIENTE);                                  // Carga en variable Transcraneal - Corriente - 16 bits
            i16TTrans=readEEPROM_16bits(i16DirEEPROM+EEPROM_TRANSC_TIEMPO_ACTIVO);                              // Carga en variable Transcraneal - Tiempo Activo - 16 bits    
            i8TrampaTrans=readEEPROM_16bits(i16DirEEPROM+EEPROM_TRANSC_TIEMPO_RAMPA);                            // Carga en variable Transcraneal - Tiempo Rampa - 16 bits    
            fSuperficieElectrodo=readEEPROM_32bits(i16DirEEPROM+EEPROM_TRANSC_TAM_ELECTRODO)/10.0;                   // Carga en variable Transcraneal - Superficie Electrodo - 8 bits
            bTiempoAutoTrans=readEEPROM_8bits(i16DirEEPROM+EEPROM_TRANSC_TCOMP);
            i8TrampaTransBajada=readEEPROM_8bits(i16DirEEPROM+EEPROM_TRANSC_TIEMPO_RAMPA_BAJADA);
            iMenuActual=30;                 // Salto al men� de configuraci�n de tratamiento en transcraneal   
            Anterior_giPos[0]=2;            // Inicializo variables de posici�n  
            Anterior_giPos[1]=0;            // Inicializo variables de posici�n
            giPos=0;                        // Inicializo variable de posici�n global
            giPosRulancha=i16Itrans;        // Selecciona corriente transcraneal
            break;
        case PRESET_TB:                                                                                // Variables SMP a memoria
            bPolaridadTB=readEEPROM_8bits(i16DirEEPROM+EEPROM_TB_POLARIDAD);
            i16PWBurstTB=readEEPROM_16bits(i16DirEEPROM+EEPROM_TB_ANCHO_PULSO);
            i16NPulsosBurstTB=readEEPROM_16bits(i16DirEEPROM+EEPROM_TB_NUMERO_PULSOS);
            i8SepPulsosTB=readEEPROM_8bits(i16DirEEPROM+EEPROM_TB_SEPARACION_PULSOS);
            i8NBurstTrenTB=readEEPROM_8bits(i16DirEEPROM+EEPROM_TB_NUMERO_BURST);
            i16SepBurstTB=readEEPROM_16bits(i16DirEEPROM+EEPROM_TB_SEPARACION_BURST);
            i8NTrenesTB=readEEPROM_8bits(i16DirEEPROM+EEPROM_TB_NUMERO_TRENES);
            i8SepTrenesTB=readEEPROM_8bits(i16DirEEPROM+EEPROM_TB_SEPARACION_TRENES);
            i16CorrienteTB=readEEPROM_16bits(i16DirEEPROM+EEPROM_TB_CORRIENTE);
            iMenuActual=80;                 // Salto al men� de configuraci�n de tratamiento en TB 
            Anterior_giPos[0]=4;            // Inicializo variables de posici�n
            Anterior_giPos[1]=0;            // Inicializo variables de posici�n

            #ifdef SMP_CAPADA
                giPos=8;
                giPosRulancha=i16CorrienteTB;
            #else
                giPos=0;                        // Inicializo variable de posici�n global
                giPosRulancha=bPolaridadTB;     // Selecciona la polaridad en TB
            #endif
            
            break;
    }

    return i8Return;                        // Devuelve el valor (no usado)
}

/*
*   Funci�n: cargaElectro()
*   Descripci�n: Indica si la carga del preset que se va a realizar es del tratamiento de electroestimulaci�n
*
*   Input:
*         - 
*   Output:
*         - int1 - Devuelve si es tratamiento de electroestimulaci�n (1) o no (0) 
*/
int1 cargaElectro(){
    // Added 11/05/2022 PRESET_MOD como condición de electro
    return (PRESET_ELECTRO==i8RegistroPresets[giPos-1+6*i8SeleccionTerapia] || PRESET_MOD==i8RegistroPresets[giPos-1+6*i8SeleccionTerapia]);      // Devuelve si es tratamiento de electroestimulaci�n (1) o no (0) 
}

/*
*   Funci�n: initRegistroPresets()
*   Descripci�n: Inicializa los registros de los presets a 0
*
*   Input:
*         - 
*   Output:
*         - 
*/
void initRegistroPresets(){
    
    int8 i8RawData=0;                                                           // Variable auxiliar para la lectura de memoria
    
    // initPresetsPredefinidos(/*i8Cont*/);
    for(int8 i8Cont=0;i8Cont<TOTAL_PRESETS;i8Cont++){                           // Recorremos todos los presets
        i8RawData=readEEPROM_8bits(OFFSET_REGISTRO_PRESETS+i8Cont);             // Leemos el estado del registro
        if(i8RawData==0xFF){                                                    // Si en este registro no se habia escrito nada
            // if((i8Cont>3 && i8Cont<6) || (i8Cont==11) || (i8Cont>15 && i8Cont<18) || i8Cont>21){
            //     // if(i8Cont>3 && i8Cont<6){
            //     //     initPresetsPredefinidos(i8Cont);
            //     //     if(i8Cont==4) i8RawData=PRESET_GALV;
            //     //     if(i8Cont==5) i8RawData=PRESET_GALVMICRO;
            //     // }
            //     // if(i8Cont==11){
            //     //     initPresetsPredefinidos(i8Cont);
            //     //     i8RawData=PRESET_TRANSCRANEAL;
            //     // }
            //     // if(i8Cont>15 && i8Cont<18){
            //     //     initPresetsPredefinidos(i8Cont);
            //     //     i8RawData=PRESET_TB;
            //     // }
            //     // if(i8Cont>21){
            //     //     initPresetsPredefinidos(i8Cont);
            //     //     i8RawData=PRESET_ELECTRO;
            //     // }
            //     if(i8Cont==4)   i8RawData=PRESET_GALV;
            //     if(i8Cont==5)   i8RawData=PRESET_GALVMICRO;
            //     if(i8Cont==11)  i8RawData=PRESET_TRANSCRANEAL;
            //     if(i8Cont==16)  i8RawData=PRESET_TB;
            //     if(i8Cont==17)  i8RawData=PRESET_TB;
            //     if(i8Cont==22)  i8RawData=PRESET_ELECTRO;
            //     if(i8Cont==23)  i8RawData=PRESET_ELECTRO;
            //     // initPresetsPredefinidos(/*i8Cont*/);
            // }else{
                i8RawData=0;                                                        // Asignamos 0 (vacio) a la variable de lectura
                writeEEPROM_8bits(OFFSET_REGISTRO_PRESETS+i8Cont,i8RawData);        // Escribimos esta variable en la memoria para inicializar
            // }
        }       
        i8RegistroPresets[i8Cont]=i8RawData;                                    // Asignamos variable al registro en RAM
    }
}
#endif