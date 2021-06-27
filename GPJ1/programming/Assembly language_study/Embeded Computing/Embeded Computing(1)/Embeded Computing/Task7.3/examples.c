// example of the codes for the main loop - the same as for the ASM template

// example 0 - debug yourself
		LEDs=0b1000001;
		__delay_ms(500);
		LEDs=0;

//--------------------------------

// example 1 - blinking two LEDs when button pressed
// 			all the hardware registers accessible when debugging with PICkit2
		if ( ! ReadSw() )	{
			LEDs=0b1000001;
			__delay_ms(500);
			LEDs=0;
			__delay_ms(500);
		}
		ADCON0 |= 0b00000010;			

//--------------------------------

//	example 2 - copying ADC value to LEDs
		LEDs=ReadADC();
// ? modify the example - if the button is pressed
//   the LEDs should not change (HOLD function)

//--------------------------------

//	example 3 - monitor switch SW1 and
//   increment LEDs if it was toggled - check bouncing
		LEDs = 0;
		tmp = PORTB & 0x01;
		while (1)	{
			if ( (PORTB & 0x01) != tmp)	{
				LEDs++;
				tmp=PORTB & 0x01;
			}
		}

//--------------------------------

//	example 4 - using Select4
		LEDs = 0b10101010;
		__delay_ms(400);

		tmp=Select4();

		__delay_ms(400);
		LEDs= tmp ^ 0xFF;
		while (1);

//--------------------------------

//	example 5 - using SelectB
		LEDs = 0b10101010;
		__delay_ms(400);

		tmp=SelectB();

		__delay_ms(400);
		LEDs= tmp ^ 0xFF;
		while (1);		

//--------------------------------

//	example 6 - find timing of a piece of C code
		INTCON &= ! T0IF; //(!0b00000100);
		while ( ! (INTCON & 0b00000100) );
		tmp=TMR0;

// place your code to time here *************************
		_delay(5);			// exactly 5 Tcy
		__delay_us(10);		// exactly 10us = 10 Tcy
// 		end of the code to time************************* 
		
		tmp1=TMR0;
		LEDs=tmp1-tmp-6;	// overhead is more significant for C code
