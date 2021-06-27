#include <xc.h>
#define LEDs	PORTD		/* definitions similar to EQU in assembly */
#include "prologue.c"

main ()
{
    //	declare variables if any required
	unsigned char tmp,tmp1;// examples for GPR variables
    unsigned char lut[]={
       0b00000000,
       0b00000001,
       0b00000010,
       0b00000011,
       0b00000101,
       0b00000100,
       0b00000111,
       0b00000110,
       0b00001010,
       0b00001011,
       0b00001000,
       0b00001001,
       0b00001111,
       0b00001110,
       0b00001101,
       0b00001100
    };
    #include "init.c"
    //*** your code for initialisation if required
   
    //*** end of your initialisation

    //***  your code for the superloop
	while (1){
	    //input A
	    RD7=1;
        RD6=0;
        tmp=SelectB();
        //input B
        RD7=0;
        RD6=1;
        tmp1=SelectB();
        //Result   
        
        tmp=tmp<<2;
        tmp1=tmp+tmp1;
        LEDs=lut[tmp1];
        RD7=1;
        RD6=1;
        __delay_ms(1500);
	}
	
    //*** end of the superloop
}  // end main


//{
// An example for masking several bits 
//		ctr |= 0b00010010; // sets RB1 and RB4 only leaving the other bits unchanged
//		ctr &= 0b11110011; // clears RB3 and RB2 only leaving the other bits unchanged
//		ctr ^= 0b00100001; // inverts RB5 and RB1 only leaving the other bits unchanged 	
//}
