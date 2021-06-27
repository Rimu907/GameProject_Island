#include <xc.h>
#define LEDs	PORTD		/* definitions similar to EQU in assembly */
#include "prologue.c"
	unsigned char Temp;
    unsigned char sw;// examples for GPR variables
    int countA;
    int countT;
    int countE;
main ()
{
    //	declare variables if any required

    #include "init.c"
    //*** your code for initialisation if required
     INTEDG = 1;
     T1CON = 0b00110001;
     ADIF = 0;
     TMR1IF = 0;
     INTF = 0;
     PEIE = 1;
     ADIE = 1;
     INTE = 1;
     TMR1IE = 1;
     GIE = 1;
    //*** end of your initialisation
     Temp = Select4();
    //***  your code for the superloop
	while (1) {
		ReadADC();
        if(Temp == 0b00000001){
            LEDs = countA;
        }

        if(Temp == 0b00000010){
            LEDs = countT;
        }

        if(Temp == 0b00000100){
            LEDs = countE;
        }

        if(Temp == 0b00001000){
            LEDs = countE;
        }
        
        sw = ReadSw();
        while (sw == 0){
            sw = ReadSw();
            if(sw == 1){
                //__delay_ms(200);
                Temp = Select4();
                break;
            }
         }
        
	}
	
    //*** end of the superloop
}  // end main

void __interrupt() myISR(void)
{
 if(TMR1IE && TMR1IF){
        TMR1IF = 0; 
        countT++;
    }
    
    if(ADIE && ADIF){
        ADIF = 0; 
        countA++;
    }
    
    if(INTE && INTF){
        INTF = 0; 
        countE++;
}
}
//{
// An example for masking several bits 
//		ctr |= 0b00010010; // sets RB1 and RB4 only leaving the other bits unchanged
//		ctr &= 0b11110011; // clears RB3 and RB2 only leaving the other bits unchanged
//		ctr ^= 0b00100001; // inverts RB5 and RB1 only leaving the other bits unchanged 	
//}
