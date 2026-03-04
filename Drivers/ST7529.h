/*     
*   Code: GLCD Driver for ST7529 - Header file
*
*   Developed by: Ionclinics & Deionics SL
*   Rev: 1.0
*
*/

#include "fat.c"
//#include "../Idiomas/castellano.c"

/* Configuration */
// Incluir define necesarios para configurarlo
#define S_   0         // Small
#define M_   1         // Medium
#define L_   2         // Large
#define XL_   3         // XLarge


#define DATA      1      // Definición de instrucción DATA
#define COMMAND   0      // Definición de instrucción COMMAND

#define MINLINE   0x10    // Primera limnea del display
#define MAXLINE   0x9F    // Última línea del display
#define MINCOL    0x05    // Primera columna del display
#define MAXCOL    0x54    // Última columna del display

#ifndef   HIGH
   #define HIGH   1
#endif

#ifndef   LOW
   #define LOW      0
#endif

#ifndef   INVERT
   #define INVERT   1
#endif

#ifndef   NORMAL
   #define NORMAL   0
#endif

/* Commands */
#define EXTIN   0x30
#define EXTOUT  0x31

// Ext = 0
#define DISON   0xaf
#define DISOFF  0xae
#define DISNOR  0xa6
#define DISINV  0xa7
#define COMSCN  0xbb
#define DISCTRL 0xca
#define SLPIN   0x95
#define SLPOUT  0x94
#define LASET   0x75
#define CASET   0x15
#define DATSDR  0xbc
#define RAMWR   0x5c
#define RAMRD   0x5d
#define PTLIN   0xa8
#define PTLOUT  0xa9
#define RMWIN   0xe0
#define RMWOUT  0xee
#define ASCSET  0xaa
#define SCSTART 0xab
#define OSCON   0xd1
#define OSCOFF  0xd2
#define PWRCTRL 0x20
#define VOLCTRL 0x81
#define VOLUP   0xd6
#define VOLDOWN 0xd7
#define EPSRRD1 0x7c
#define EPSRRD2 0x7d
#define NOP     0x25
#define EPINT   0x07

// Ext = 1
#define GRAY1SET    0x20
#define GRAY2SET    0x21
#define ANASET      0x32
#define SWINT       0x34
#define EPCTIN      0xcd
#define EPCOUT      0xcc
#define EPMWR       0xfc
#define EPMRD       0xfd

/* Escala de grises */
#define WHITE   0x00
#define GRAY1   0x20
#define GRAY2   0x30
#define GRAY3   0x40
#define GRAY4   0x50
#define GRAY5   0x60
#define GRAY6   0x70
#define GRAY7   0x80
#define GRAY8   0x90
#define GRAY9   0xA0
#define GRAY10   0xB0
#define GRAY11   0xC0
#define GRAY12   0xD0
#define GRAY13   0xE0
#define GRAY14   0xF0
#define BLACK   0xFF

#define ICON_HEIGHT     16   
#define ICON_WIDTH      16
#define ICON_LENGTH     32

#define ICON_BAT0       0
#define ICON_BAT1       1
#define ICON_BAT2       2
#define ICON_BAT3       3
#define ICON_BAT4       4
#define ICON_BAT5       5
#define ICON_ON         6
#define ICON_ALERT      7
#define ICON_UP         11
#define ICON_DOWN       10
#define ICON_RIGHT      9
#define ICON_LEFT       8
#define ICON_CANCEL     12
#define ICON_ALTON      13
#define ICON_ALTOFF     14
#define ICON_ILUM       15
#define ICON_CONTRAST   16
#define ICON_FLECHA     17
#define ICON_CONFIG     18
#define ICON_ALMACEN    19
#define ICON_NONE       20
#define ICON_SON_FULL   21
#define ICON_SON_MED    22
#define ICON_SON_NONE   23
#define ICON_TICK       24
#define ICON_NO_BAT     25

/********************************** Definiciones necesarias para el GLCD ****************************************/


/* Variales globales */
rom int8 *pCurrentFont;
int8 iRowStep,iColumnStep,iNumBytes;

/* Functions */
/*
*   Función: Chip Select
*   Descripción: Habilita / Deshabilita la escritura.
*   Está configurada para invertir la salida de lo que ponemos (esquema Perico)
*   i.e: Si ponemos ST7529_cs(HIGH), en la placa el CS estará en HIGH 
*   enviando un LOW por la salida del PIC
*
*   Input:
*         - iValue - Nivel al que se pone el chip select. Este es activo a nivel bajo
*               - Se han definido varios defines para solo tener que 
*                  colocar HIGH o LOW como argumento de entrada
*   Output:
*         - 
*/
void ST7529_cs(int1);


/*
*   Función: Modo de comandos
*   Descripción: Habilita capturar los datos que enviamos 
*   por SPI como comando o como dato
*
*   Input:
*         - iValue - Selección de modo.
*               - Se han definido varios defines para solo tener que 
*                  colocar COMMAND o DATA como argumento de entrada
*   Output:
*         - 
*/
void ST7529_a0(int1);


/*
*   Función: Sleep
*   Descripción: Envia la pantalla a dormir
*
*   Input:
*         -
*   Output:
*         - 
*/
void ST7529_sleep();


/*
*   Función: Despertar
*   Descripción: Despierta la pantalla del modo sleep
*
*   Input:
*         -
*   Output:
*         - 
*/
void ST7529_wakeUp();


/*
*   Función: Pantalla ON
*   Descripción: Enciende la pantalla
*
*   Input:
*         -
*   Output:
*         - 
*/
void ST7529_displayOn();


/*
*   Función: Pantalla OFF
*   Descripción: Apaga la pantalla
*
*   Input:
*         -
*   Output:
*         - 
*/
void ST7529_displayOff();


/*
*   Función: Reset
*   Descripción: Resetea la pantalla
*
*   Input:
*         -
*   Output:
*         - 
*/
void ST7529_reset();


/*
*   Función: Inicialización
*   Descripción: Inicializa la pantalla
*
*   Input:
*         -
*   Output:
*         - 
*/
void ST7529_init();


/*
*   Función: Enviar dato
*   Descripción: Envio de datos a la pantalla
*
*   Input:
*            - iSel - Seleccionar entre COMMAND o DATA, 
*            dependiendo de lo que se va a enviar
*         - iData - Dato o comando a enviar
*   Output:
*         - 
*/
void ST7529_send(int1, int8);


/*
*   Función: Incrementar contraste
*   Descripción: Incrementa el contraste de la pantalla
*
*   Input:
*         -
*   Output:
*         - 
*/
void ST7529_incContrast();


/*
*   Función: Decrementar contraste
*   Descripción: Decrementa el contraste de la pantalla
*
*   Input:
*         -
*   Output:
*         - 
*/
void ST7529_decContrast();


/*
*   Función: Clear
*   Descripción: Borra toda la pantalla
*
*   Input:
*         -
*   Output:
*         - 
*/
void ST7529_clear();


/*
*   Función: PutChar
*   Descripción: Envia un caracter la pantalla
*
*   Input:
*         - iChar      - Caracter a enviar  
*         - iX         - Coordenada del eje X
*         - iY         - Coordenada del eje Y
*         - iFont      - Fuente seleccionada, se selecciona con los defines definidos
*               - S_  - Tamaño pequeño
*               - M_  - Tamaño Mediano
*               - L_  - Tamaño Grande
*               - XL_ - Tamaño Muu grande
*                  
*         - iGrayScale - Color eleido para pintar el caracter, 
*               existen los siguientes niveles definidos
*               - WHITE
*               - GRAY1
*               - GRAY2
*               - GRAY3
*               - GRAY4
*               - GRAY5
*               - GRAY6
*               - GRAY7
*               - GRAY8
*               - GRAY9
*               - GRAY10
*               - GRAY11
*               - GRAY12
*               - GRAY13
*               - GRAY14
*               - BLACK
*
*         - iInvert - Selecciona lainversion de texto.
*               Existen los siguientes niveles definidos  
*               - NORMAL
*               - INVERT
*
*   Output:
*         - 
*/
void ST7529_putChar(int8, int8, int8, int8, int8, int1);


/*
*   Función: Printf
*   Descripción: Imprime una string por pantala
*
*   Input:
*         - *sText     - Texto a enviar
*         - iX         - Coordenada del eje X
*         - iY         - Coordenada del eje Y
*         - iFont      - Fuente seleccionada, se selecciona con los defines definidos
*               - S_  - Tamaño pequeño
*               - M_  - Tamaño Mediano
*               - L_  - Tamaño Grande
*               - XL_ - Tamaño Muu grande
*                  
*         - iInvert - Selecciona lainversion de texto.
*               Existen los siguientes niveles definidos  
*               - NORMAL
*               - INVERT
*
*   Output:
*         - 
*/
void ST7529_printf(char *, int8, int8, int1, int1);



/*
*   Función: PrintfG
*   Descripción: Envia una string la pantalla de la escala de grises que elijas
*
*   Input:
*         - *sText     - Texto a enviar  
*         - iX         - Coordenada del eje X
*         - iY         - Coordenada del eje Y
*         - iFont      - Fuente seleccionada, se selecciona con los defines definidos
*               - S_  - Tamaño pequeño
*               - M_  - Tamaño Mediano
*               - L_  - Tamaño Grande
*               - XL_ - Tamaño Muu grande
*                  
*         - iGrayScale - Color eleido para pintar el caracter, 
*               existen los siguientes niveles definidos
*               - WHITE
*               - GRAY1
*               - GRAY2
*               - GRAY3
*               - GRAY4
*               - GRAY5
*               - GRAY6
*               - GRAY7
*               - GRAY8
*               - GRAY9
*               - GRAY10
*               - GRAY11
*               - GRAY12
*               - GRAY13
*               - GRAY14
*               - BLACK
*
*         - iInvert - Selecciona lainversion de texto.
*               Existen los siguientes niveles definidos  
*               - NORMAL
*               - INVERT
*
*   Output:
*         - 
*/
void ST7529_printfg(char *, int8, int8, int, int8, int1);


/*
*   Función: Fuente
*   Descripción: Configuración de la fuente a usar
*
*   Input:
*         - iFont      - Fuente seleccionada, se selecciona con los defines definidos
*               - S_  - Tamaño pequeño
*               - M_  - Tamaño Mediano
*               - L_  - Tamaño Grande
*               - XL_ - Tamaño Muu grande
*                 
*   Output:
*         - 
*/
void ST7529_selectFont(int8);
//void ST7529_putImage(char *, int8, int8, int16, int16);
//void ST7529_putImageGS(rom int8 *, int8, int8, int16, int16);


/*
*   Función: PutIcon
*   Descripción: Pone un icono en pantalla
*
*   Input:
*         - iIcon   - Icono a poner en pantalla. 
*            Existen los siguientes iconos definidos
*               - ICON_BAT     
*               - ICON_ON       
*               - ICON_ALERT    
*               - ICON_LEFT   
*               - ICON_RIGHT    
*               - ICON_DOWN    
*               - ICON_UP      
*               - ICON_CANCEL    
*               - ICON_ALTON   
*               - ICON_ALTOFF    
*               - ICON_ILUM   
*               - ICON_CONTRAS 
*               - ICON_FLECHA   
*               - ICON_CONFIG    
*               - ICON_ALMACEN
*               - ICON_TEST   
*               
*         - iX         - Coordenada del eje X
*         - iY         - Coordenada del eje Y
*
*   Output:
*         - 
*/
void ST7529_putIcon(int8, int8, int8);


/*
*   Función: PutIconG
*   Descripción: Pone un icono en pantalla con la escala de grises que elijas
*
*   Input:
*         - iIcon   - Icono a poner en pantalla. 
*            Existen los siguientes iconos definidos
*               - ICON_BAT     
*               - ICON_ON       
*               - ICON_ALERT    
*               - ICON_LEFT   
*               - ICON_RIGHT    
*               - ICON_DOWN    
*               - ICON_UP      
*               - ICON_CANCEL    
*               - ICON_ALTON   
*               - ICON_ALTOFF    
*               - ICON_ILUM   
*               - ICON_CONTRAS 
*               - ICON_FLECHA   
*               - ICON_CONFIG    
*               - ICON_ALMACEN
*               - ICON_TEST   
*               
*         - iX         - Coordenada del eje X
*         - iY         - Coordenada del eje Y
*         - iGray - Color eleido para pintar el caracter, 
*               existen los siguientes niveles definidos
*               - WHITE
*               - GRAY1
*               - GRAY2
*               - GRAY3
*               - GRAY4
*               - GRAY5
*               - GRAY6
*               - GRAY7
*               - GRAY8
*               - GRAY9
*               - GRAY10
*               - GRAY11
*               - GRAY12
*               - GRAY13
*               - GRAY14
*               - BLACK
*
*   Output:
*         - 
*/
void ST7529_putIcon2(int8, int8, int8, int8);

void ST7529_putImageGS(rom int8 *, int8, int8, int16, int16);
