#include <xc.h>
#define LEDs	PORTD
#include "prologue.c"
unsigned char button_released(void) {  	// no debouncing but quick - use for this task only
	return PORTB & 0b00000001;			//   rez=ReadSw(); // with debouncing
} 

main () {
	unsigned char Temp;	
   
    int x;
#include "init.c"

//***  code for the superloop
	while (1) {

		if ( button_released() )	{	// quick check whether the button is released
			LEDs=0b00000000;            
            Temp = Select4();
			// after this line analyse the tmp value and set X as required
            if (Temp == 1)
              { 
                x = 1;//0b00000001; //1
              }
            else if (Temp == 2)
              {
                x = 1;//0b00000001; //1
              }  
            else if (Temp == 4)
              {
                x = 5;//0b00000101; //5
              } 
            else if (Temp == 8)
              {
                x = 12;//0b00001100; //12     
	          }
		}
        else{
		// after this line switch the LEDs
         LEDs= 0b00000010;         
		// after this line put the loop , use a 100us delay.
         for (int i=28;i>0;i--)        //from 28 to 1
            {       
             if (i == x)
             {
                 LEDs = LEDs | 0b00000001;
              
             }
             __delay_us(100);
             }  //when x <= 1,1,5,12 and x >0 
	      
	
        }            
//*** end of the superloop
    }

}  // end main - a remark
