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
#include "ECH_1.inc"

; Place your SUBROUTINE(S) (if any) here ...  
;{ 
ISR CODE H'20'
ISR retfie ; replace retfie with your ISR if necessary



;}
; end of your subroutines
; Provided code - do not edit  
Main nop
 
; This include contains code that runs each time your board is turned on, such 
; as configuring the pins, peripherals and flashing the LEDs. Read it to
; understand what is going on.
#include "ECH_INIT.inc"
bsf TRISD,0
bsf TRISD,1
bsf TRISD,2
bsf TRISD,3

banksel OSCCON
BSF OSCCON,IRCF2
BSF OSCCON,IRCF1
BSF OSCCON,IRCF0
 
banksel TRISC
 CLRF TRISC          ;10khz Fosc=4mhz dutycycle=18% 
 BANKSEL PR2          ;pr2 = 99 = 01100011 
 MOVLW D'01100011'    
 MOVWF PR2
 
 BANKSEL CCP1CON      ;18%*4*(99+1)=CCPR1L:CCP1CON <5:4>
 MOVLW B'01101100'    ;= 72 = 1001000
 MOVWF CCP1CON         ;00
 
 BANKSEL CCPR1L       ;0010010
 MOVLW B'0010010'
 MOVWF CCPR1L
 BANKSEL T2CON
 bsf T2CON,TMR2ON

; Place your INITIALISATION code (if any) here ...   
;{ ***  ***************************************************
; e.g.,  movwf Ctr1 ; etc


;} 
; end of your initialisation


MLoop nop
;call    Select4


 goto MLoop

 end