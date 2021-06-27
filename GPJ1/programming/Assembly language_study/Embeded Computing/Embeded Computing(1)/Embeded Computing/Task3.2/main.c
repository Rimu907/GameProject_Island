#include <xc.h>
#define LEDs	PORTD		/* definitions similar to EQU in assembly */
#include "prologue.c"

main ()
{
    //	declare variables if any required
	unsigned char tmp,tmp1,tmp2;		// examples for GPR variables

    #include "init.c"
    //*** your code for initialisation if required

    //*** end of your initialisation

    //***  your code for the superloop
	while (1) {
		//input A
	    RD7=1;
        RD6=0;
        tmp=SelectB();
        
        //input B
        RD7=0;
        RD6=1;
        tmp1=SelectB();
        //Result   
        
        tmp2=tmp*5;  
        tmp2=tmp2^tmp1;
        LEDs=tmp2;
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
