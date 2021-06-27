; ECH_VAR.INC - declaration of variables used in the AK subroutines

D_Ctr1	RES	1	; could be more than 1 byte, e.g., for int or float
D_Ctr2	RES 1	; 1 byte (one GPR) is reserved here and below
D_Ctr3	RES	1
R_Old	RES	1
S_Tmp		RES	1	; scratch pad registers
S_Tmp1	RES	1
; the above variables could be named like Tmp1 Tmp2 etc, and used in
; the rest of the program if necessary to save RAM (not in the ISR though)
