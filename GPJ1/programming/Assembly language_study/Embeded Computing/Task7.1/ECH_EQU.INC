;	symbolic name for the port connected to LEDs (PORTD)
LEDs	EQU		PORTD
;	symbolic names for individual LEDs for BSF and BCF
LD0		EQU		0
LD1		EQU		1
LD2		EQU		2
LD3		EQU		3
LD4		EQU		4
LD5		EQU		5
LD6		EQU		6
LD7		EQU		7
;
; e.g.	BSF		LEDs, LD3	; to switch LD3 on
;		BCF		LEDs, LD5	; to switch LD5 off

; use the following macros to test the switch
#define skipRel		btfss PORTB,RB0	; skip the next instruction if button is released
#define skipPre		btfsc PORTB,RB0 ; skip the next instruction if the button is pressed