#define DIRECCION_INICIAL_EEPROM_INTERNA    0xF00000

// Definiciones
enum{
    REG_ERROR_DUMMY=0,              // Dummy
    REG_ERROR_COMMS_S_O,            // Error de comunicaciones Sauron -> Orco        
    REG_ERROR_COMMS_O_S,            // Error de comunicaciones Orco -> Sauron        
    REG_ERROR_ALIM_5V,              // Error alimentaci�n 5V
    REG_ERROR_ALIM_12V,             // Error alimentaci�n 12V    
    REG_ERROR_ALIM_48V,             // Error alimentaci�n 48V    
    REG_ERROR_BUS_I2C,              // Error bus I2C - Pueder ser BQ o expansor    
    REG_ERROR_ACC_INIT,             // Error aceler�metro - Inicializaci�n    
    REG_ERROR_ACC_MOV,              // Error aceler�metro - Movimiento brusco    
    REG_ERROR_CARGADOR,             // Error cargador - Alimentaci�n incorrecta    
    REG_ERROR_WDT_SW,               // Error watchdog software    
    REG_ERROR_RESERVADO_0,          // Error watchdog hardware    
    REG_ERROR_RESERVADO_1,          // Error reservado 1
    REG_ERROR_RESERVADO_2,          // Error reservado 1
    REG_ERROR_RESERVADO_3,          // Error reservado 1
    REG_ERROR_CAL_A,                // Error calibrado A
    REG_ERROR_CAL_B,                // Error calibrado B
    REG_ERROR_CAL_C,                // Error calibrado C
    REG_ERROR_TRAN_A,               // Error transistores A
    REG_ERROR_TRAN_B,               // Error transistores B
    REG_ERROR_TRAN_C,               // Error transistores C
    REG_ERROR_VREF_ORCO,            // Error tensi�n referencia Orco    
    REG_ERROR_MAX,                  // Define el final de errores
};// REG_ERRORES;
int8 i8OffsetErrorParcial=REG_ERROR_MAX+1;    // Offset donde empieza el bloque de parcial

enum{
    REG_VECES_ENCENDIDO=2*REG_ERROR_MAX+1,      // Registro n�mero de veces que se ha encendido el equipo                            
    REG_TRAT_CHA=REG_VECES_ENCENDIDO+2,         // Registro n�mero de tratamientos electroestimulaci�n canal A                                
    REG_TRAT_CHB=REG_TRAT_CHA+2,                // Registro n�mero de tratamientos electroestimulaci�n canal B
    REG_TRAT_CHC=REG_TRAT_CHB+2,                // Registro n�mero de tratamientos electroestimulaci�n canal C
    REG_TRAT_POINTER=REG_TRAT_CHC+2,            // Registro n�mero de tratamientos pointer
    REG_TRAT_GALV=REG_TRAT_POINTER+2,           // Registro n�mero de tratamientos galv�nica
    REG_TRAT_MICRO=REG_TRAT_GALV+2,        // Registro n�mero de tratamientos galv�nica+microcorrientes
    REG_TRAT_TRANS=REG_TRAT_MICRO+2,       // Registro n�mero de tratamientos transcraneal
    REG_TRAT_SMP=REG_TRAT_TRANS+2,              // Registro n�mero de tratamientos sistema multipulsos
    REG_TIEMPO_CHA=REG_TRAT_SMP+2,              // Registro tiempo de tratamiento electr�nica canal A 
    REG_TIEMPO_CHB=REG_TIEMPO_CHA+4,            // Registro tiempo de tratamiento electr�nica canal B
    REG_TIEMPO_CHC=REG_TIEMPO_CHB+4,            // Registro tiempo de tratamiento electr�nica canal C
    REG_CONT_MAX=REG_TIEMPO_CHC+4,              // Define el final de contadores 
};// REG_CONTADORES;                                
int8 i8OffsetContParcial=REG_CONT_MAX-REG_VECES_ENCENDIDO;    // Offset donde empieza el bloque de parcial


// Added 12/05/2022 Redefinición de los presets
#define OFFSET_REGISTRO_PRESETS                     950                                                 // Indica a partir de qué posición de EEPROM están los strings de presets
#define OFFSET_EEPROM_PRESETS                       129                                                 // Escribe a partir de la posici�n 129
#define OFFSET_ENTRE_PRESETS                        20                                                  // Indica que como m�ximo se van a grabar 20 bytes por preset 
#define OFFSET_EEPROM_PRESETS_EXT                   489
#define OFFSET_ENTRE_PRESETS_EXT                    40

// Presets globalizados (presets de 20 bytes)
#define OFFSET_EEPROM_PRESET_1                      OFFSET_EEPROM_PRESETS                              // Indica la posici�n inicial del preset 1 - Pos: 129+120*i8SeleccionTerapia*i8DobleElectro
#define OFFSET_EEPROM_PRESET_2                      OFFSET_ENTRE_PRESETS + OFFSET_EEPROM_PRESET_1      // Indica la posici�n inicial del preset 2 - Pos: 149+120*i8SeleccionTerapia*i8DobleElectro
#define OFFSET_EEPROM_PRESET_3                      OFFSET_ENTRE_PRESETS + OFFSET_EEPROM_PRESET_2      // Indica la posici�n inicial del preset 3 - Pos: 169+120*i8SeleccionTerapia*i8DobleElectro
#define OFFSET_EEPROM_PRESET_4                      OFFSET_ENTRE_PRESETS + OFFSET_EEPROM_PRESET_3      // Indica la posici�n inicial del preset 4 - Pos: 189+120*i8SeleccionTerapia*i8DobleElectro
#define OFFSET_EEPROM_PRESET_5                      OFFSET_ENTRE_PRESETS + OFFSET_EEPROM_PRESET_4      // Indica la posici�n inicial del preset 5 - Pos: 209+120*i8SeleccionTerapia*i8DobleElectro
#define OFFSET_EEPROM_PRESET_6                      OFFSET_ENTRE_PRESETS + OFFSET_EEPROM_PRESET_5      // Indica la posici�n inicial del preset 6 - Pos: 229+120*i8SeleccionTerapia*i8DobleElectro

// Presets extendidos (presets de 40 bytes)
#define OFFSET_EEPROM_PRESET_1_EXT                      OFFSET_EEPROM_PRESETS_EXT                              // Indica la posici�n inicial del preset 1 - Pos: 129+120*i8SeleccionTerapia*i8DobleElectro
#define OFFSET_EEPROM_PRESET_2_EXT                      OFFSET_ENTRE_PRESETS_EXT + OFFSET_EEPROM_PRESET_1_EXT      // Indica la posici�n inicial del preset 2 - Pos: 149+120*i8SeleccionTerapia*i8DobleElectro
#define OFFSET_EEPROM_PRESET_3_EXT                      OFFSET_ENTRE_PRESETS_EXT + OFFSET_EEPROM_PRESET_2_EXT      // Indica la posici�n inicial del preset 3 - Pos: 169+120*i8SeleccionTerapia*i8DobleElectro
#define OFFSET_EEPROM_PRESET_4_EXT                      OFFSET_ENTRE_PRESETS_EXT + OFFSET_EEPROM_PRESET_3_EXT      // Indica la posici�n inicial del preset 4 - Pos: 189+120*i8SeleccionTerapia*i8DobleElectro
#define OFFSET_EEPROM_PRESET_5_EXT                      OFFSET_ENTRE_PRESETS_EXT + OFFSET_EEPROM_PRESET_4_EXT      // Indica la posici�n inicial del preset 5 - Pos: 209+120*i8SeleccionTerapia*i8DobleElectro
#define OFFSET_EEPROM_PRESET_6_EXT                      OFFSET_ENTRE_PRESETS_EXT + OFFSET_EEPROM_PRESET_5_EXT      // Indica la posici�n inicial del preset 6 - Pos: 229+120*i8SeleccionTerapia*i8DobleElectro

// Interfaz
#define EEPROM_LOC_ILUMINACION              0x3ED       // Iluminaci�n es de 1 byte
#define EEPROM_LOC_CONTRASTE                0x3EE       // Contraste es de 1 byte    
#define EEPROM_LOC_SONIDO                   0x3EF       // Sonido es de 2 bytes              
#define EEPROM_LOC_IDIOMA                   0x3F1       // Idioma es de 1 byte       
#define MEMORIA_EEPROM_PROGRAMADA           0x3F2       // Memoria EEPROM programmada
#define PRIMER_INICIO                       0x3F3       // Primer inicio del equipo
#define BORRAR_REGISTRO_PARCIAL             0x3F4       // Indica que debe de reiniciar el contador parcial

//******** EN MEMORIA EXTERNA
#define POSICION_MEM_VREF                   0x1FBD0     // Valor de calibraci�n tensi�n de referencia del microcontrolador principal (en memoria externa!)

// NO SON POSICIONES, SON VALORES
#define MEMORIA_NO_PROGRAMADA   0xFF        // Indica que la memoria no ha sido programmada
#define MEMORIA_PROGRAMADA      0x96        // Indica que la memoria ha sido programmada

#define BORRA_PARCIAL           0xBA        // Indica que borra el contador parcial
#define PARCIAL_BORRADO         0xFF        // Indica que el registro parcial se ha borrado
