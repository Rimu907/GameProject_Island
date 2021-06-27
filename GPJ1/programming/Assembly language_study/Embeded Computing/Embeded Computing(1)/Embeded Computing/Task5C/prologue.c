// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 
// 			This file is for your information only
//
// 					DO NOT EDIT
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//; the options used must be selected from the pic16f887.h file from INCLUDE directory of Hi-Tech compiler
//; setting the CONFIG1 configuration bits - required, explained at the end of the lecture course
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR21V   // Brown-out Reset Selection bit (Brown-out Reset set to 2.1V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)//; CONFIG1 
//; CONFIG1
//; FOSC_INTRC_NOCLKOUT - use internal 4 MHz oscillator, RA6 and RA7 pins are used for I/O
//; WDTE_OFF - the watchdog timer is DISABLED and can be enabled by SWDTEN bit of the WDTCON register
//; PWRTE_ON - power up timer - ENABLED
//; MCLRE_ON - master clear pin function - ENABLED
//; CP_OFF - program memory protection - DISABLED
//; CPD_OFF - EEPROM protection - DISABLED
//; BOREN_OFF - brown out reset - DISABLED
//; IESO_OFF - internal external oscillator switchover - DISABLED
//; FCMEN_OFF - fail safe clock monitor - DISABLED
//; LVP_OFF - low voltage programming - DISABLED
//; DEBUG_ON - in circuit debugger - ENABLED, pins RB6 and RB7 are used by it
//; ! the best practice is to ALWAYS specify all the bits in the code
//; CONFIG2
//; BOR4V_BOR21V - Brown-out Reset set to 2.1V
//; WRT_OFF - program memory self write protection - DISABLED


/* to make __delay functions available with right timing*/
#define _XTAL_FREQ 4000000

unsigned char ReadADC(void) {
	ADCON0 |= 0b00000010;
	while ( (ADCON0 & 0b00000010) );
	return ADRESH;
}


unsigned char ReadSw(void) {
	unsigned char tmp;
	do {
		tmp = PORTB & 0b00000001;
		__delay_ms(20);
	} while( tmp != (PORTB & 0b00000001) );
	return tmp;
}

unsigned char Select4(void) {
	unsigned char tmp, oldLEDs, result;
	oldLEDs=LEDs;
	LEDs=0b00010000;
	
	do {
		tmp = ReadADC();
		tmp >>= 6;
		switch (tmp) {
			case 0: result=1; break;
			case 1: result=2; break;
			case 2: result=4; break;
			case 3: result=8;
		}
		LEDs = result | 0b00010000 | (oldLEDs & 0b11000000);
	} while( ReadSw() );
	
	LEDs = 0; __delay_ms(300);
	LEDs = result; __delay_ms(400);
	LEDs = 0; __delay_ms(300);
	
	LEDs=oldLEDs;
	return result;
}

unsigned char SelectB(void) {
	unsigned char oldLEDs, result;
	oldLEDs=LEDs;
	LEDs=0b00010000;
	
	do {
		result = ReadADC();
		result >>= 6;
		LEDs = result | 0b00010000 | (oldLEDs & 0b11000000);
	} while( ReadSw() );

	LEDs = 0; __delay_ms(300);
	LEDs = result; __delay_ms(400);
	LEDs = 0; __delay_ms(300);

	LEDs=oldLEDs;
	return result;
}

