// Comprobación del segundo tipo de error de max value
if((i16RegDuty[CHB_C][ANTERIOR]!=i16RegDuty[CHB_C][ACTUAL])||i8ContadorPropagacion){     // Si hay cambios en el duty...                                        
    if((abs(fRegMedV[CHB_C][ANTERIOR]-fRegMedV[CHB_C][ACTUAL])<=MIN_DIFERENCIA_TENSION_MAX_VALUE)){       // Si no existe realmente una diferencia al variar el duty...
        // Debo de iincrementar el contador de veces que he pasado por aqui para contemplar el tiempo de propagación
        i8ContadorPropagacion++;                // Incremmento el contador
        if(i8ContadorPropagacion>3){            // Si ya ha pasado varias veces y se sigue cumpliendo la condición inicial
            i8ContadorPropagacion=0;            // Inicializo el valor
            bMAX[CHB_C][PULSO_POS]=1;           // Indico max value
        }
    }else{                                      // Si si que hay diferencia
        i8ContadorPropagacion=0;                // Inicializo el valor
        bMAX[CHB_C][PULSO_POS]=0;           // Init max value
    }
}else{                                                  // Si todo está correcto, actualizo los valores
    fRegMedV[CHB_C][ANTERIOR]=fRegMedV[CHB_C][ACTUAL];      // Almaceno el valor actual como anterior
    i8ContadorPropagacion=0;
    bMAX[CHB_C][PULSO_POS]=0;           // Init max value
}
i16RegDuty[CHB_C][ANTERIOR]=i16RegDuty[CHB_C][ACTUAL];  // Almaceno el valor actual como anterior







if(i8ChannelSel==GALVANICA_C){
    i16RegDuty[CHB_C][ACTUAL]=tras_i16DutyP;
    if(bPrimeraIteracion){
        bPrimeraIteracion=0;
        i16RegDuty[CHB_C][ANTERIOR]=i16RegDuty[CHB_C][ACTUAL];
    }
}else{
    i16RegDuty[i8ConfigCanal][ACTUAL]=tras_i16DutyP;
    if(bPrimeraIteracion){
        bPrimeraIteracion=0;
        i16RegDuty[i8ConfigCanal][ANTERIOR]=i16RegDuty[i8ConfigCanal][ACTUAL];
    }
}

