; *** SOME INFORMATION AND INITIALISATION HERE ***   ;{

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
#include	"ECH_1.inc"

; Place your SUBROUTINE(S) (if any) here ...  
;{ 
ISR	CODE	H'20'
ISR	retfie	; replace retfie with your ISR if necessary

LUT     addwf   PCL,F 
        retlw   B'00000000' ;A00 B00
        retlw   B'00000001' ;00 01
        retlw   B'00000010' ;00 10
        retlw   B'00000011' ;00 11
        retlw   B'00000101' ;01 00
        retlw   B'00000100' ;01 01
        retlw   B'00000111' ;01 10
        retlw   B'00000110' ;01 11
        retlw   B'00001010' ;10 00
        retlw   B'00001011' ;10 01
        retlw   B'00001000' ;10 10
        retlw   B'00001001' ;10 11
        retlw   B'00001111' ;11 00
        retlw   B'00001110' ;11 01
        retlw   B'00001101' ;11 10
        retlw   B'00001100' ;11 11

;}
; end of your subroutines
; Provided code - do not edit  
Main	nop
	
; This include contains code that runs each time your board is turned on, such 
; as configuring the pins, peripherals and flashing the LEDs. Read it to
; understand what is going on.
#include "ECH_INIT.inc"

; Place your INITIALISATION code (if any) here ...   
;{ ***		***************************************************
; e.g.,		movwf	Ctr1 ; etc


;} 
; end of your initialisation


MLoop	nop

; place your superloop code here ...  
;{
	;	enter A
	bsf	LEDs,LD7
	call    SelectB
	movwf   A
	
	bcf	LEDs,LD7
	
	;       enter B
	bsf	LEDs,LD6
	call	SelectB
	movwf   Bop
	
	bcf	LEDs,LD6
        
	;DISPLAY result
	RLF     A,f
	RLF     A,w
	addwf   Bop,w   
	call    LUT
	movwf   LEDs
	bsf	LEDs,LD6
	bsf	LEDs,LD7
	
	goto $
	
	;movwf	LEDs
	;bcf	LEDs,LD7
	
	
	
;}	
; end of your superloop code

	goto	MLoop

	end
