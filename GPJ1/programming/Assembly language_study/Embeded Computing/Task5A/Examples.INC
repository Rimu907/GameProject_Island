; the code for the main loop - copy any one and paste in the PROGRAM

;	example 0 - heart beat when the button is pressed as shown in the class initially
;				before debugging. Follow the lecture slides to debug yourself.
;   The complete code that we have used at the end is presented in Examples.inc (example 1) 
		movlw	B'1000001'
		movwf	PORTD		; or LEDs instead of PORTB
		movlw	D'5'		
		call	DelWds		; hold for 0.5 s
		clrf	LEDs

;----------------------------------------------------------

;	example 1 - heart beat when the button is pressed
		call 	DeBounce	; to avoid switch bouncing
		skipPre				; skip if pressed
		goto	MLoop
		; the above code shows an example on how to operate the button

		movlw	B'1000001'
		movwf	PORTD		; or LEDs instead of PORTB
		movlw	D'5'		
		call	DelWds		; hold for 0.5 s
		clrf	LEDs
		movlw	D'5'		
		call	DelWds		; hold for 0.5 s

		bsf		ADCON0, GO_DONE		; this line requests ADC read
									; do not use it in your code (use ReadADC instead)
									; it shows that in circuit debugging
									; can give you register values from the hardware
									; on the board which cannot be fully simulated using MPLAB SIM

;----------------------------------------------------------

;	example 2 - copying ADC value to LEDs
		call	ReadADC
		movwf	LEDs
; ? modify the example - if the button is pressed
;   the LEDs should not change (HOLD function)

;----------------------------------------------------------

;	example 3 - monitor switch SW1 and
;   increment LEDs if it was toggled - check bouncing
		clrf	LEDs
		movlw 	0x0
M_L1	movwf	Tmp			; register to keep the previous state of SW1
		movf	PORTB,W	; direct read - no debouncing
		andlw	B'00000001' ; mask out the other bits
		xorwf	Tmp,F
		btfsc	STATUS,Z	; if Z set, no toggling occured
		goto	M_L1
		incf	LEDs		; SW toggled, increment LEDs
		goto	M_L1

;----------------------------------------------------------

;	example 4 - using Select4

		movlw	B'10101010'	; test pattern to be restored after the call Select4
		movwf	LEDs
		movlw	D'10'		; show it for a while
		call	DelWds

		call 	Select4
		movwf	Temp			; selection -> Tmp

		movlw	D'10'		; show test pattern for a while again
		call	DelWds

		clrf	LEDs		; switch off all LEDs

		movfw	Temp
		xorlw	B'11111111'	; invert all the bits
		movwf	LEDs		; all LEDs on except the selected one
L1		goto	L1	

;----------------------------------------------------------

;	example 5 - using SelectB

		movlw	B'10101010'	; test pattern to be restored after the call Select4
		movwf	LEDs
		movlw	D'10'		; show it for a while
		call	DelWds

		call 	SelectB
		movwf	Temp			; selection -> Tmp

		movlw	D'10'		; show test pattern for a while again
		call	DelWds

		clrf	LEDs		; switch off all LEDs

		movfw	Temp
		xorlw	B'11111111'	; invert all the bits
		movwf	LEDs		; all LEDs on except the selected one
L1		goto	L1

;----------------------------------------------------------

;	example 6 - use of TMR0 to measure the execution time
;	of various codes - hardware check for the MPLAB "Watch"

		bcf		INTCON, T0IF	; clear the TMR0 flag
L2		btfss	INTCON, T0IF	; wait until TMR0 overflows
		goto	L2
		movfw	TMR0			; read TMR0 to W
		movwf	Tmp				; save to Tmp


; place your code to time here *************************
		nop		; any 'normal' instruction 1 Tcy
		goto	L4	; goto requires 2 Tcy even if jumps at the next address
L4		nop		; any 'normal' instruction 1 Tcy
		nop		; any 'normal' instruction 1 Tcy
		nop		; any 'normal' instruction 1 Tcy
		nop		; any 'normal' instruction 1 Tcy
;		nop
; 		end of the code to time************************* 


		movfw	TMR0		; read TMR0 to W
		movwf	Tmp1		; new TMR0 to Tmp1
		movfw	Tmp			; restore old TMR0 to W
		subwf	Tmp1,W		; calculate the difference
		movwf	LEDs		; display it
		decf	LEDs,F		; adjust it for the 2 Tcy overhead code
		decf	LEDs,F		;

L3		goto	L3			; stop here


		
				

		

		
		
