; operating BUILD CONFIGURATIONS drop down menu in the DEBUG toolbar
; FOR SIMULATIONS with MPLAB SIM: select "Debug" this will switch off delays that take thousands of instructions
; HARDWARE: select "Release" all delays will be on

; Provided code - do not edit  
; This include setups up various configuration bits for the microcontroller
; we are using, and importantly reserves space for variables.
; If you need to use more variables, please place them in VAR.INC, which you
; can find under the "Header Files" folder. The variables listed there will be
; placed in the first memory bank.
; This code has been provided for you to simplify your work, but you should be
; aware that you cannot ignore it.
#include	ECH_1.inc
		

; Place your SUBROUTINE(S) (if any) here ...  
;{ 

ISR
	call DeBounce
	BTFSC INTCON,RBIF
	BCF INTCON,RBIF
	call DeBounce
	incf number,f
	
	retfie	
;} end of your subroutines
; Provided code - do not edit  
Main	nop
#include ECH_INIT.inc

; Place your INITIALISATION code (if any) here ...   
;{ ***		***************************************************
; e.g.,		movwf	Ctr1 ; etc
movlw B'00000000'
movwf number
banksel PORTB
bcf PORTB,RB0
banksel TRISB
bsf TRISB,RB0

banksel IOCB
bsf IOCB,0

banksel INTCON
bsf INTCON, RBIE
bcf INTCON, RBIF
bsf INTCON, GIE	

;} 
; end of your initialisation

MLoop	nop

; place your superloop code here ...  
;{
                
	        movfw	 number
		movwf	 LEDs	
;}	
; end of your superloop code

    goto	MLoop

end
