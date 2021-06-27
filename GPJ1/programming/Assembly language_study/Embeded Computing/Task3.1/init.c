//; DO NOT EDIT ! ! !

//  clear all output pins
	PORTA=0; PORTB=0; PORTC=0; PORTD=0; PORTE=0;
	
//	set the analog input for RA0 only
	ANSELH= 0;
	ANSEL = 0b00000001;
	TRISA = 0b00000001;

//  set digital input for RB0 pin of PORTB only
	TRISB = 0b00000001;

//	init unused pins to outputs
	TRISC=0; TRISD=0; TRISE=0b11111000;

//	init TMR0
	OPTION_REG = 0b00001000;	

// 	init the ADC
	ADCON1 = 0;
	ADCON0 = 0b01000001;       

//	blink LEDs for 0.3 s for testing   
	LEDs = 0xFF;
	__delay_ms(300);
	LEDs = 0;
	__delay_ms(300);	
