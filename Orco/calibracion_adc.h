// Variables y definiciones
#define ITER_MED_CAL	10
signed int16 si16ValorReferenciaCal=0;

// Prototipo de funciones
void calibracionInicial();
int16 read_adc_chupi_piruli();

// Funciones
void calibracionInicial(){
	signed int16 si16RawADC=0;
	signed int16 si16Lectura=0;
   	
	set_adc_channel(ADC_CAL);    
    delay_us(DELAY_INT_SIG);            
    
    si16RawADC=read_adc();
    while(!adc_done());
    si16RawADC=0;
    
    for(int8 i8Cont=0; i8Cont<ITER_MED_CAL; i8Cont++){
        set_adc_channel(ADC_CAL);  
        delay_us(DELAY_INT_SIG); 
        
		si16Lectura=read_adc();
		while(!adc_done());
        si16RawADC+=si16Lectura;
        //fprintf(DEBUG_UART,"Valor Lectura Ref -> %li\r\n",si16Lectura);
        delay_ms(10);
    }
    si16RawADC/=ITER_MED_CAL;

    si16ValorReferenciaCal=si16RawADC;
    //fprintf(DEBUG_UART,"Valor Ref -> %li\r\n",si16ValorReferenciaCal);
}

int16 read_adc_chupi_piruli(){
	int16 i16ReadADC=0;
	signed int16 si16RawADC=0;

	si16RawADC=read_adc();
	while(!adc_done());
	si16RawADC-=si16ValorReferenciaCal;

	if(si16RawADC<=0){
		i16ReadADC=0;
	}else{
		i16ReadADC=si16RawADC;
	}

	return i16ReadADC;
}
