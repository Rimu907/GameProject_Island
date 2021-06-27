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
ISR	CODE	H'20'
ISR	retfie	; replace retfie with your ISR if necessary
;} end of your subroutines


; Provided code - do not edit  
Main	nop
#include ECH_INIT.inc

; Place your INITIALISATION code (if any) here ...   
;{ ***		***************************************************
; e.g.,		movwf	Ctr1 ; etc
banksel VRCON      ;
movlw B'10100001';10100001
movwf VRCON

banksel CM1CON0
movlw B'10000100'
movwf CM1CON0

L   btfss CM1CON0,6
    goto L
    
    banksel ADCON1
    movlw B'10000000'
    movwf ADCON1
    
    banksel TRISA
    bsf     TRISA,0
    banksel  ANSEL
    bsf     ANSEL,0
    
    banksel ADCON0
    movlw B'11000001'
    movlw ADCON0
    
    bsf ADCON0,GO
    btfsc ADCON0,GO
    goto $-1
    banksel ADRESL
    movfw ADRESL
    banksel PORTD
    movwf LEDs

;} 
; end of your initialisation

MLoop	nop

; place your superloop code here ...  
;{


;}	
; end of your superloop code

    goto	MLoop

end
