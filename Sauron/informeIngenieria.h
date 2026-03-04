/*
*   File: regErrores.h
*   
*   Descripción: Header file para el control de registro de errores
*   
*   Versión: 1.0
*
*   Ionclinics & Deionics SL
*/

#define GENERAL     0                   // Selecci�n bloque general
#define PARCIAL     1                   // Selecci�n bloque parcial 

#define DELAY_ESCRITURA_EEPROM  100     // Delay escritura EEPROM - Tiempo en us

#ROM (DIRECCION_INICIAL_EEPROM_INTERNA|BORRAR_REGISTRO_PARCIAL)={BORRA_PARCIAL}         // Guarda un dato en la EEPROM para que sepa que ha de borrar la eeprom

// Def. Funciones

/*
*   Funci�n: initRegError(int1 bSeleccion)
*   Descripci�n: Inicializa el estado de los registros de error,
*                   ya sea el registro parcial o general
*
*   Input:
*         - int1 bSeleccion - 0 - General
*                           - 1 - Parcial
*   Output:
*         - 
*/
void initRegError(int1);     

/*
*   Funci�n: initRegCont(int1 bSeleccion)
*   Descripci�n: Inicializa el estado de los registros de contadores,
*                   ya sea el registro parcial o general
*
*   Input:
*         - int1 bSeleccion - 0 - General
*                           - 1 - Parcial
*   Output:
*         - 
*/
void initRegCont(int1);    

 /*
*   Funci�n: initRegistros()
*   Descripci�n: Inicializa el estado de los registros de contadores y errores
*
*   Input:
*         - 
*   Output:
*         - 
*/            
void initRegistros();                   
    
/*
*   Función: initRegistrosParciales()
*   Descripción: Inicializa el estado de los registros de contadores y errores
*
*   Input:
*         - 
*   Output:
*         - 
*/
void initRegistrosParciales();

/*
*   Funci�n: incRegError(int8 i8Registro)
*   Descripci�n: Incrementa el registor de error correspondiente al registro seleccionado para incrementar
*
*   Input: 
*         - int8 i8Registro - Indica el registro en el que se quiere incrementar el registor de error
*   Output:
*         - 
*/       
void incRegError(int8);  

/*
*   Funci�n: incRegCont(int8 i8Registro)
*   Descripci�n: Incrementa el registor de contadores correspondiente al registro seleccionado para incrementar
*
*   Input: 
*         - int8 i8Registro - Indica el registro en el que se quiere incrementar el registor de contadores
*   Output:
*         - 
*/     
void incRegCont(int8);    

/*
*   Funci�n: incRegTiempo(int8 i8Registro)
*   Descripci�n: Incrementa el registor de tiempo correspondiente al registro seleccionado para incrementar
*
*   Input: 
*         - int8 i8Registro - Indica el registro en el que se quiere incrementar el registor de tiempo
*   Output:
*         - 
*/ 
void incRegTiempo(int8);                
             
/*
*   Funci�n: muestraRegError()
*   Descripci�n: Representa por UART el registro de errores
*
*   Input:
*         - 
*   Output:
*         - 
*/
// void muestraRegError();  
void muestraRegErrorMejorado();  

/*
*   Funci�n: muestraRegCont()
*   Descripci�n: Representa por UART el registro de contadores
*
*   Input:
*         - 
*   Output:
*         - 
*/          
// void muestraRegCont();         
void muestraRegContMejorado();         
                   
/*
*   Funci�n: refreshRegError()
*   Descripci�n: Refresca los registros de error de la memoria. 
*                   Se recomienda en el datasheet que cada cierto tiempo 
*                   se refresquen los datos para evitar que se borren
*
*   Input:
*         - 
*   Output:
*         - 
*/
void refreshRegError();  

/*
*   Funci�n: refreshRegCont()
*   Descripci�n: Refresca los registros de contadores de la memoria. 
*                   Se recomienda en el datasheet que cada cierto tiempo 
*                   se refresquen los datos para evitar que se borren
*
*   Input:
*         - 
*   Output:
*         - 
*/
void refreshRegCont();                  
                     
/*
*   Funci�n: informeIngenieria()
*   Descripci�n: Muestra por UART el registro completo de ingenier�a
*
*   Input:
*         - 
*   Output:
*         - 
*/
void informeIngenieria();               




































