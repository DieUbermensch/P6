	.global _FIR, _ADDNUM;
	
	; int16 *DataIn 	--> AR0
	; int16 *b_coeffs 	--> AR1
	; int i 			--> T0
_FIR	
	MOV #0, AC1
	MOV #23, BK03				; Set buffer size to filter order
	MOV XAR0,XAR2				; CDP as coefficient pointer
	MOV mmap(AR2),BSA23        	; Set up base address for CDP
	MOV T0,AR2					; Start from the i'th data
	bset AR2LC					; Set pointer as circular
	RPT #22
	MAC *AR2+,*AR1+,AC1 
	SFTL AC1, #-15
	mov AC1,T0     ; Store the rounded & scaled result
	RET
	
	
	
	; int x 			--> T0
	; int y 			--> T1
_ADDNUM
	MOV T0, AC0
	ADD T1, AC0
	MOV AC0,T0
	RET
	
	
