
; ECH_1.inc - to be put before your SUBROUTINES		


; DEFINITIONS related to the PIC and board used
; DO NOT EDIT ! ! !


; this #include enables use of register and bit names from the datasheet
; consists of 
; SymbolicName EQU NumericalValue   ; equates symbolic names to appropriate bit patterns
#include <p16F887.inc>
; ! the name of the file should match the PIC microcontroller part name


; setting the CONFIG1 configuration bits - required, explained at the end of the lecture course
	__CONFIG 	_CONFIG1, _INTOSCIO & _WDT_OFF & _PWRTE_ON & _MCLRE_ON & _CP_ON & _CPD_OFF & _BOR_OFF & _IESO_OFF & _FCMEN_OFF & _LVP_OFF & _DEBUG_ON
;	configuration bits from the original Microchip code
;	__CONFIG    _CONFIG1, _LVP_OFF & _FCMEN_OFF & _IESO_OFF & _BOR_OFF & _CPD_OFF & _CP_OFF & _MCLRE_OFF & _PWRTE_ON & _WDT_OFF & _INTRC_OSC_NOCLKOUT
;
; _INTOSCIO - use internal 4 MHz oscillator, RA6 and RA7 pins are used for I/O
; _WDT_OFF - the watchdog timer is DISABLED and can be enabled by SWDTEN bit of the WDTCON register
; _PWRTE_ON - power up timer - ENABLED
; _MCLRE_ON - master clear pin function - ENABLED
; _CP_OFF - program memory protection - DISABLED
; _CPD_OFF - EEPROM protection - DISABLED
; _BOR_OFF - brown out reset - DISABLED
; _IESO_OFF - internal external oscillator switchover - DISABLED
; _FCMEN_OFF - fail safe clock monitor - DISABLED
; _LVP_OFF - low voltage programming - DISABLED
; _DEBUG_ON - in circuit debugger - ENABLED, pins RB6 and RB7 are used by it
; (these and all the other available options are specified in the p16F887.inc file
; ! the best practice is to ALWAYS specify all the bits in the code

; setting the CONFIG2 configuration bits - required, explained at the end of the lecture course
	__CONFIG 	_CONFIG2, _WRT_OFF & _BOR21V
;	as in the Microchip original code
;
; _WRT_OFF - program memory self write function - OFF
; _BOR21V - brown out reset voltage set to 2.1 V (this feature is disabled anyway in CONFIG1 above)


#include		ECH_EQU.inc	; for EQU statements related to the 44 pin demo board wiring of PORTD and RB0


; ALLOCATION of user RAM, starts where SFRs end at 0x20
gr1		udata		; GPRs for bank 1							
		include 	VAR.inc		; YOUR VARIABLES from this file
		include		ECH_VAR.inc	; variables required for subroutines
gr2		udata		; GPRs for bank 2 - none used
; GPRs for banks 3 and 4 can be defined as above
gr3		udata_shr	; these variables will be put to the RAM shared among all the banks (last 16 GPRs)	
W_TMP	RES		1
ST_TMP	RES		1


; CODE sections at different addresses
		; entry on reset - address 0x0 is fixed by PIC architecture
V_RES	CODE 	0x0
		MOVLW   HIGH(Main)
	    MOVWF   PCLATH
		goto	Main
		; entry on interrupt - address 0x4 fixed by PIC architecture
V_INT	CODE	0x4
		goto	ISR
		CODE    ; conventional placement of subroutines - before the INITIALISATION


; subroutines prepared for the coursework
		include	ECH_SUB.INC

