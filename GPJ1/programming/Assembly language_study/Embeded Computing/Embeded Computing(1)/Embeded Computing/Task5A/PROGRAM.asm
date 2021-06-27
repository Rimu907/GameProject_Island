; SOME INFORMATION AND INITIALISATION HERE   ;{

; operating BUILD CONFIGURATIONS drop down menu in the DEBUG toolbar
; SIMULATIONS with MPLAB SIM: select "Debug" this will switch off delays that take thousands of instructions
; HARDWARE: select "Release" all delays will be on

; Provided code - do not edit  
#include	ECH_1.inc

;}

; Place your SUBROUTINE(S) (if any) here ...  ;{ 
ISR	CODE	H'20'
ISR	retfie	; replace retfie with your ISR if necessary
		
;} end of your subroutines

; Provided code - do not edit  
Main	nop
#include ECH_INIT.inc
		movlw	B'00000001'	; initial choice for Select4 value - bit 0 is set
		movwf	Temp
		movlw  D'28'
		movwf  it
; Place your INITIALISATION code (if any) here ...   
;{ ***		***************************************************
; e.g.,		movwf	Ctr1 ; etc


;} 
; end of your initialisation

MLoop	nop
; place your superloop code here ...   ;{
	
        movfw	Temp
	skipPre
	call	Select4
	movwf	Temp
;	Select4 data are stored in the variable Temp
;	Check which bit was set in this variable and set X		
;	(btfsc	Temp,0		; checking bit 0, skip next instruction if Clear)
;	after this line
       
	BTFSC Temp,0
	goto p0
	BTFSC Temp,1
	goto p1
	BTFSC Temp,2
	goto p2
	BTFSC Temp,3
	goto p3
        
        p0:
        movlw D'1'
	movwf X ;
	goto P4
        p1:
        movlw D'1'
	movwf X ;
	goto P4
        p2:
        movlw D'5'
	movwf X ;
	goto P4
        p3:
        movlw D'12'
	movwf X ;
	goto P4
;	after this line will come the loop as specified in the coursework description
        P4:
        clrf	LEDs
	bsf     LEDs,LD1
	movlw  D'28'
        movwf  it
        lp:
        ;DECFSZ it,w
	MOVFW it
	XORWF  X,w
	BTFSC STATUS,Z
	
	bsf LEDs,LD0
	
	Call Del_100us
	
	DECFSZ it
        goto lp
	
	
;}	
; end of your superloop code

	goto	MLoop

end
