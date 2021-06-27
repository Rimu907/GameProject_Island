; DO NOT EDIT ! ! !

; ECH_SUB.INC - subroutines supplied for
; delay for 1 ms  (Del_ms)
; delay for 1 ms  times W (DelWms)
; delay for 0.1 s times W (DelWds)


#ifdef __DEBUG 	; to facilitate in-circuit debugging -
				; all delay subroutines return immediately as below

Del_ms	return
DelWms	return
DelWds	return
Del_100us	return

#else			; this is the code to provide the delays

; precise delay for 100 us
; uses	D_Ctr1
; calls	nothing		
Del_100us
		movlw	D'31'
		movwf	D_Ctr1
D_L4	decfsz	D_Ctr1
		goto	D_L4
		nop
		nop
		return
; precise delay for 1 ms
; uses	D_Ctr1
; calls	nothing 
Del_ms	movlw 	D'248'	; value tuned at the debug stage
		movwf	D_Ctr1
D_L1	nop
		decfsz	D_Ctr1, F
		goto	D_L1
		nop
		nop
		nop
		return
; not precise but approximate delay for W times 1 ms
; uses	D_Ctr2
; calls	Del_ms 
DelWms	movwf	D_Ctr2
D_L2	call	Del_ms
		decfsz	D_Ctr2, F
		goto 	D_L2
		return
; not precise but approximate delay for W times 1 ds (0.1 s)
; uses	D_Ctr3
; calls	DelWms 
DelWds	movwf	D_Ctr3
D_L3	movlw	D'100'
		call	DelWms
		decfsz	D_Ctr3, F
		goto	D_L3
		return

#endif


; reading the ADC with the delay for conversion
ReadADC	bsf		ADCON0, GO_DONE		; strat the conversion
RADC1	btfss	ADCON0, GO_DONE		; test the DONE bit
		goto	RADC1				; if not set, test again
		movfw	ADRESH				; data ready => copy to W
		return

; de-bouncing switches using a delay for 20 ms
; uses	R_Old
; calls	DelWms 
DeBounce
		movfw	PORTB			; copy SwPort to W
		andlw	B'00000001'		; mask unused bits (one bit is in use only)
		movwf	R_Old			; save data to a work register
		movlw	D'20'
		call	DelWms			; wait for 20 ms and read again
		movfw	PORTB
		andlw	B'00000001'		
		xorwf	R_Old,W			; compare with the old value
		btfss	STATUS,Z
		goto	DeBounce		; if the value changed - do again
		movfw	R_Old			; reading is stable => return it
		return


; selecting one option out of four
; rotate the potentiometer to have the right LED on 
; then press the button to confirm
; LD4 is used to show that potentiometer input is on
Select4
		movfw	LEDs
		movwf	S_Tmp1		; LEDs -> Tmp1 to restore later

Sel4Rd	clrf	LEDs
		movfw	S_Tmp1
		andlw	B'11000000'
		movwf	LEDs		; restore 3 MSB of LEDs
		bsf		LEDs,LD4	; indicator on

;		get the two MSBs of the ADC value
		call	ReadADC
		andlw	B'11000000'	; mask unused bits
		movwf	S_Tmp			; copy MSBs only

;		analyse two MSBs of the ADC value
		btfsc	S_Tmp, D'7'	; test bit 7
		goto	SelMSB1
		btfsc	S_Tmp, D'6'	; test bit 6
		goto	Sel1

Sel0	bsf		LEDs, LD0	; bits were 00
		movlw	B'00000001'	; choice 0 selected
		goto	SelBut
			
Sel1	bsf		LEDs, LD1	; bits were 01
		movlw	B'00000010'	; choice 1 selected
		goto	SelBut

SelMSB1						; bit 7 was 1, test bit 6
		btfsc	S_Tmp, D'6'
		goto	Sel3

Sel2	bsf		LEDs, LD2	; bits were 10
		movlw	B'00000100'	; choice 2 selected
		goto	SelBut

Sel3	bsf		LEDs, LD3	; bits were 11
		movlw	B'00001000'	; choice 1 selected

SelBut	movwf	S_Tmp			; W is used in DeBounce
		call	DeBounce
		skipPre
		goto	Sel4Rd		; no confirmation - start again

		clrf	LEDs		; blink the selection
		movlw	3
		call	DelWds
		movfw	S_Tmp
		movwf	LEDs
		movlw	4
		call	DelWds
		clrf	LEDs
		movlw	3
		call	DelWds

		movfw	S_Tmp1
		movwf	LEDs		; Tmp1 -> LEDs restore before return

		movfw	S_Tmp			; return Sel4 in W

		return

; selecting 2 bit binary value
; rotate the potentiometer to have the right LED on 
; then press the button to confirm
; LD4 is used to show that potentiometer input is on
SelectB
		movfw	LEDs
		movwf	S_Tmp1		; LEDs -> Tmp1 to restore later

SelBRd	clrf	LEDs
		movfw	S_Tmp1
		andlw	B'11000000'
		movwf	LEDs		; restore 3 MSB of LEDs
		bsf		LEDs,LD4	; indicator on

;		get the two MSBs of the ADC value
SelL2	call	ReadADC
		andlw	B'11000000'	; mask unused bits
		movwf	S_Tmp			; copy MSBs only

;		rotate MSBs to LSBs
		bcf		STATUS, C	; clear carry flag as it is used for rotation
		rrf		S_Tmp, F
		rrf		S_Tmp, F
		rrf		S_Tmp, F
		rrf		S_Tmp, F
		rrf		S_Tmp, F
		rrf		S_Tmp, F

		movfw	LEDs
		andlw	B'11111100'
		iorwf	S_Tmp,W
		movwf	LEDs

		call	DeBounce
		skipPre
		goto	SelBRd		; loop here until the button is pressed 

		clrf	LEDs		; blink the result
		movlw	3
		call	DelWds
		movfw	S_Tmp
		movwf	LEDs
		movlw	4
		call	DelWds
		clrf	LEDs
		movlw	3
		call	DelWds

		movfw	S_Tmp1
		movwf	LEDs		; Tmp1 -> LEDs restore before return

		movfw	S_Tmp			; return Sel4 in W

		return
		