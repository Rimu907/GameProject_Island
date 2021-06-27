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


;} 
; end of your initialisation

MLoop	nop

; place your superloop code here ...  
;{
 call  Select4
        ps:
        movwf Temp
	BTFSc Temp,0
	goto pa
	BTFSc Temp,1
	goto pb
	BTFSc Temp,2
	goto pc
	BTFSc Temp,3
	goto pd
	;position 0
	pa:
        bsf	LEDs,LD7  ;1
	movlw	3
	call	DelWds
	bcf    LEDs,LD7
	movlw	3
	call	DelWds
	bsf	LEDs,LD7  ;2
	movlw	3
	call	DelWds
	bcf    LEDs,LD7
	movlw	3
	call	DelWds
        bsf	LEDs,LD7  ;3
	movlw	3
	call	DelWds
	bcf    LEDs,LD7
	movlw	3   
	call	DelWds
	bsf	LEDs,LD7  ;4
	movlw	3
	call	DelWds
	bcf    LEDs,LD7
	movlw	3 
	call	DelWds
	bsf	LEDs,LD7  ;5
	movlw	3
	call	DelWds
	bcf    LEDs,LD7
	movlw	3  
	call	DelWds
	
        clrf	LEDs
	call 	Select4
	
	goto ps
	;position 1
	pb:	
        bsf	LEDs,LD7
	bsf	LEDs,LD6
	bsf	LEDs,LD5
	movlw	3
	call	DelWds
        clrf	LEDs
	call 	Select4
	
	goto ps
	;position 2
	pc:	
        bsf	LEDs,LD7
	movlw	3
	call	DelWds
        clrf	LEDs
	call 	Select4
	
	goto ps
	;position 3
	pd:
	bsf	LEDs,LD5
	movlw	3
	call	DelWds
        clrf	LEDs
	call 	Select4
	
        goto ps

;}	
; end of your superloop code

    goto	MLoop

end
