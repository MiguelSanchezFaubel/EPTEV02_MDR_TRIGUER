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

#define NIVEL   12               // Define la separaci�n entre lineas

int16 i16FrecuenciaAnterior;     // Indica cual era el valor de la frecuencia anterior al variarla

/*
*   Funci�n: pantalla_seleccion
*   Descripci�n: Incluye los s�mbolos principales de los men�s
*
*   Input:
*         - 
*   Output:
*         - 
*/
void pantalla_seleccion();

/*
*   Funci�n: poner_cancelar
*   Descripci�n: Pone el s�mbolo de cancelar
*
*   Input:
*         - 
*   Output:
*         - 
*/
void poner_cancelar();

/*
*   Funci�n: quitar_cancelar
*   Descripci�n: Quita el s�mbolo de cancelar
*
*   Input:
*         - 
*   Output:
*         - 
*/
void quitar_cancelar();

/*
*   Funci�n: poner_config
*   Descripci�n: Pone el s�mbolo de configuraci�n
*
*   Input:
*         - 
*   Output:
*         - 
*/
void poner_config();

/*
*   Funci�n: quitar_config
*   Descripci�n: Quita el s�mbolo de configuraci�n
*
*   Input:
*         - 
*   Output:
*         - 
*/
void quitar_config();

/*
*   Funci�n: poner_flecha_izq
*   Descripci�n: Pone la flecha izquierda
*
*   Input:
*         - 
*   Output:
*         - 
*/
void poner_flecha_izq();

/*
*   Funci�n: quitar_flecha_izq
*   Descripci�n: Quita la flecha izquierda
*
*   Input:
*         - 
*   Output:
*         - 
*/
void quitar_flecha_izq();

/*
*   Funci�n: poner_flecha_der
*   Descripci�n: Pone la flecha derecha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void poner_flecha_der();

/*
*   Funci�n: quitar_flecha_der
*   Descripci�n: Quita la flecha derecha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void quitar_flecha_der();

/*
*   Funci�n: poner_guardar
*   Descripci�n: Pone el s�mbolo de guardar
*
*   Input:
*         - 
*   Output:
*         - 
*/
void poner_guardar();

/*
*   Funci�n: quitar_guardar
*   Descripci�n: Quita el s�mbolo de guardar
*
*   Input:
*         - 
*   Output:
*         - 
*/
void quitar_guardar();

/*
*   Funci�n: poner_cargar
*   Descripci�n: Pone el s�mbolo de cargar
*
*   Input:
*         - 
*   Output:
*         - 
*/
void poner_cargar();

/*
*   Funci�n: quitar_cargar
*   Descripci�n: Quita el s�mbolo de guardar
*
*   Input:
*         - 
*   Output:
*         - 
*/
void quitar_cargar();

/*
*   Funci�n: representacionPresets
*   Descripci�n: Representa por pantalla el men� de presets
*
*   Input:
*         - 
*   Output:
*         - 
*/
void representacionPresets();

/*
*   Funci�n: menu_0
*   Descripci�n: Men� principal
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_0();

/*
*   Funci�n: menu_10
*   Descripci�n: Men� configuraci�n del dispositivo
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_10(); 

/*
*   Funci�n: menu_20
*   Descripci�n: Men� de galv�nica / galv�nica + microcorrientes
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_20();

/*
*   Funci�n: menu_30
*   Descripci�n: Men� de trabscraneal
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_30();   

/*
*   Funci�n: menu_40
*   Descripci�n: Men� de electroestimulaci�n
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_40();  

/*
*   Funci�n: menu_80
*   Descripci�n: Men� del sistema multipulsos
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_80();  

/*
*   Funci�n: menu_90
*   Descripci�n: Men� de presets
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_90();  

/*
*   Funci�n: menu_11
*   Descripci�n: Configuraci�n de la iluminaci�n de pantalla
*
*   Input:
*         - 
*   Output:
*         - 
*/
// int8 menu_11();   

/*
*   Funci�n: menu_12
*   Descripci�n: Configuraci�n de la se�al ac�stica
*
*   Input:
*         - 
*   Output:
*         - 
*/
// int8 menu_12();

/*
*   Funci�n: menu_13
*   Descripci�n: Informaci�n firmware/hardware
*
*   Input:
*         - 
*   Output:
*         - 
*/
// int8 menu_13();

/*
*   Funci�n: menu_14
*   Descripci�n: Configuraci�n del contraste de pantalla
*
*   Input:
*         - 
*   Output:
*         - 
*/
// int8 menu_14();

/*
*   Funci�n: menu_15
*   Descripci�n: Selecci�n de idioma
*
*   Input:
*         - 
*   Output:
*         - 
*/
// int8 menu_15();  

/*
*   Funci�n: DEPRECATED menu_21
*   Descripci�n: DEPRECATED Ajuste del nivel de carga 
*
*   Input:
*         - 
*   Output:
*         - 
*/
//int8 menu_21();   

/*
*   Funci�n: menu_22
*   Descripci�n: Ajuste del nivel de corriente 
*
*   Input:
*         - 
*   Output:
*         - 
*/
//int8 menu_22(); 

/*
*   Funci�n: menu_23
*   Descripci�n: Ajuste del tiempo de rampa
*
*   Input:
*         - 
*   Output:
*         - 
*/
//int8 menu_23();

/*
*   Funci�n: menu_27
*   Descripci�n: Ajuste del ancho de pulso positivo y negativo
*
*   Input:
*         - 
*   Output:
*         - 
*/
//int8 menu_27();

/*
*   Funci�n: menu_28
*   Descripci�n: Ajuste de la frecuencia  de tratamiento
*
*   Input:
*         - 
*   Output:
*         - 
*/
//int8 menu_28(); 

/*
*   Funci�n: menu_29
*   Descripci�n: Ajuste de la polaridad de la se�al
*
*   Input:
*         - 
*   Output:
*         - 
*/
//int8 menu_29(); 

/*
*   Funci�n: menu_33
*   Descripci�n: Ajuste de la simetr�a de la se�al
*
*   Input:
*         - 
*   Output:
*         - 
*/
//int8 menu_33();

/*
*   Funci�n: menu_34
*   Descripci�n: Ajuste de la superficie del electrodo
*
*   Input:
*         - 
*   Output:
*         - 
*/
//int8 menu_34();  

/*
*   Funci�n: menu_41
*   Descripci�n: Selecci�n del canal de electroestimulaci�n
*
*   Input:
*         - 
*   Output:
*         - 
*/
//int8 menu_41();

/*
*   Funci�n: menu_42
*   Descripci�n: Ajuste del tiempo de tratamiento
*
*   Input:
*         - 
*   Output:
*         - 
*/
//int8 menu_42(); 

/*
*   Funci�n: menu_43
*   Descripci�n: Ajuste del n�mero de repeticiones en electroestimulaci�n
*
*   Input:
*         - 
*   Output:
*         - 
*/
//int8 menu_43(); 

/*
*   Funci�n: menu_91
*   Descripci�n: Men� de selecci�n del canal de electroestimulaci�n
*                     a cargar en el men� de presets
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_91(); 

/*
*   Funci�n: menu_92
*   Descripci�n: Men� de guardado de presets
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_92(); 

/*
*   Funci�n: menu_120
*   Descripci�n: Men� de tratamiento galv�nica / galv�nica+microcorrientes
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_120(); 

/*
*   Funci�n: menu_130
*   Descripci�n: Men� de tratamiento transcraneal
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_130(); 

/*
*   Funci�n: menu_140
*   Descripci�n: Men� de tratamiento de electroestimulaci�n
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_140();

/*
*   Funci�n: menu_180
*   Descripci�n: Men� de tratamiento del sistema multipulsos
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_180(); 

/*
*   Funci�n: menu_200
*   Descripci�n: Men� de autoapagado
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_200(); 

/*
*   Funci�n: menu_201
*   Descripci�n: Men� de apagado del equipo
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_201(); 

/*
*   Funci�n: DEPRECATED menu_202
*   Descripci�n: DEPRECATED Men� de error de transistores
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_202();

/*
*   Funci�n: DEPRECATED menu_203
*   Descripci�n: DEPRECATED Men� de error del sistema de medida
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_203();

/*
*   Funci�n: menu_204
*   Descripci�n: Men� de carga del dispositivo
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_204();

/*
*   Funci�n: menu_205
*   Descripci�n: Men� de error de comunicaciones
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_205();

/*
*   Funci�n: menu_206
*   Descripci�n: Men� de error de calibrado
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_206();

/*
*   Funci�n: menu_207
*   Descripci�n: Men� c�digo de error gen�rico
*
*   Input:
*         - 
*   Output:
*         - 
*/
int8 menu_207();

/*
*   Funci�n: submenu_22
*   Descripci�n: Ajuste del nivel de corriente con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_22();

/*
*   Funci�n: submenu_23
*   Descripci�n: Ajuste del tiempo de rampa con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_23();

/*
*   Funci�n: submenu_27
*   Descripci�n: Ajuste del ancho de pulso con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_27();

/*
*   Funci�n: submenu_28
*   Descripci�n: Ajuste de la frecuencia con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_28();

/*
*   Funci�n: submenu_29
*   Descripci�n: Selecci�n de polaridad de la se�al con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_29();

/*
*   Funci�n: submenu_33
*   Descripci�n: Selecci�n de simetr�a de la se�al con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_33();

/*
*   Funci�n: submenu_34
*   Descripci�n: Selecci�n de la superficie del electrodo con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_34();

/*
*   Funci�n: submenu_42
*   Descripci�n: Ajuste del tiempo de tratamiento con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_42();

/*
*   Funci�n: submenu_43
*   Descripci�n: Ajuste del n�mero de repeticiones con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_43();

/*
*   Función: submenu_81
*   Descripción: Ajuste campos SMP
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_81();

/*
*   Función: submenu_21 Added 27/01/2022
*   Descripción: Selección de tiempo automatico con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_21();

/*
*   Función: submenu_25 Added 27/01/2022
*   Descripción: Selección de tipo de tratamiento Galvanica (0), Microcorrientes (1), Galvanica + Microcorrientes (2)
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_25();

/*
*   Función: submenu_41 Added 05/04/2022
*   Descripción: Selección del canal de electroestimulación
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_41();

/*
*   Función: submenu_49 Added 06/04/2022
*   Descripción: Selección del tipo de modulación
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_49();

/*
*   Función: submenu_491 Added 07/04/2022
*   Descripción: Ajuste de porcentaje de modulación AM
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_491();

/*
*   Función: submenu_11
*   Descripción: Ajuste del nivel de iluminacion con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_11();

/*
*   Función: submenu_14
*   Descripción: Ajuste del nivel de contraste con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_14();

/*
*   Función: submenu_12
*   Descripción: Ajuste del nivel de senal acustica con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_12();

/*
*   Función: submenu_15
*   Descripción: Ajuste del idioma con rulancha
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_15();

/*
*   Función: submenu_90 NEW: Added 12/05/2022
*   Descripción: Seleccion de terapia de presets
*
*   Input:
*         - 
*   Output:
*         - 
*/
void submenu_90();