	.global _FIR, _FIRNew,_IncrementCNT;
	
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
	
	
	
	
_FIRNew	
	MOV #0, AC1
	MOV #23, BK03				; Set buffer size to filter order
	MOV XAR0,XAR2				; CDP as coefficient pointer
	MOV mmap(AR0),BSA23        	; Set up base address for CDP
	MOV T0,AR2					; Start from the i'th data
	bset AR2LC					; Set pointer as circular
	RPT #23
	MAC *AR2+,*AR1+,AC1 
	SFTL AC1, #-15
	mov AC1,T0     ; Store the rounded & scaled result
	RET
	
;_IncrementCNT
;	ADD #1,*(AR0)
;	CALLCC ResetCNT,AC1>=#2000h
;	RET
	
;ResetCNT
;	MOV #0, *(AR0)
;	RET
	