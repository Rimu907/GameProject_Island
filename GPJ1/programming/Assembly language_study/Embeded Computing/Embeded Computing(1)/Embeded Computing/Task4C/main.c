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
    tmp=Select4();
        switch (tmp)
    { 
            case 0b00000001:
            RD5=0;RD6=0; 
            RD7=1;          //1
            __delay_ms(300);
            RD7=0;
            __delay_ms(300);
            RD7=1;          //2
            __delay_ms(300);
            RD7=0;
            __delay_ms(300);
            RD7=1;          //3
            __delay_ms(300);
            RD7=0;
            __delay_ms(300);
            RD7=1;          //4
            __delay_ms(300);
            RD7=0;
            __delay_ms(300);
            RD7=1;          //5
            __delay_ms(300);
            RD7=0;
            __delay_ms(300);
       
            break;
            case 0b00000010:RD7=1,RD6=1,RD5=1;__delay_ms(500);
            RD7=0,RD6=0;break;  
            case 0b00000100:RD7=1,RD6=0,RD5=0;__delay_ms(500);
            RD7=0;break;  
            case 0b00001000:RD7=0,RD6=0,RD5=1;__delay_ms(500);
            break;      
	}
	}
	
    //*** end of the superloop
}  // end main


//{
// An example for masking several bits 
//		ctr |= 0b00010010; // sets RB1 and RB4 only leaving the other bits unchanged
//		ctr &= 0b11110011; // clears RB3 and RB2 only leaving the other bits unchanged
//		ctr ^= 0b00100001; // inverts RB5 and RB1 only leaving the other bits unchanged 	
//}
