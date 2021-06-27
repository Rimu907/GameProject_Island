; DO NOT EDIT ! ! !

; initialisation of the pins according to board wiring   
;{
; set all outputs to zero before configuring the pinsLEDs to off before configuring the pins
		clrf	PORTA
		clrf	PORTB
		clrf	PORTC
		clrf	PORTD
		clrf	PORTE

		banksel	ANSELH			; switch to bank 4

; disable analogue inputs except for RA0
		clrf	ANSELH
		movlw	B'00000001'
		movwf	ANSEL

		banksel	TRISA			; switch to bank 1

; init unused pins for PORTA (outputs)
		movlw	B'00000001'	; this constant was in W already, shown here for clarity
		movwf	TRISA

; init PORTB (RB0 for input, unused pins for output)
		movlw	B'00000001'	; this constant was in W already, shown here for clarity
		movwf	TRISB

; init PORTC (all pins unused - for output)
		movlw	B'00000000'	; this constant was in W already, shown here for clarity
		movwf	TRISC

; init LEDs (PORTD to outputs)
		clrf	TRISD

; init PORTE (four pins present, RE3 is MCLR anyway; all outputs for simplicity)
		movlw	B'11111000'	
		movwf	TRISE

; init the TMR0 keeping the two MSBs of OPTION_REG the same
		movfw	OPTION_REG
		andlw	B'00001000'		; prescaler to WDT to have Tcy clock for TMR0
      	movwf   OPTION_REG       

; init the ADC - need bank 0 and 1
		clrf	ADCON1		; Left justified, refernces: Vss and Vdd
		banksel	PORTD		; switch back to bank 0
		movlw	B'01000001'	; Fosc/8, AN0, enable 
		movwf	ADCON0
;}

;	
; blink LEDs for 0.3 s for testing   
;{
		movlw	B'11111111'	; all LEDs ON
		movwf	LEDs
		movlw	D'3'		; delay
		call	DelWds
		clrf	LEDs		; all LEDs OFF
		movlw	D'3'		; delay
		call	DelWds
;}
;
	
