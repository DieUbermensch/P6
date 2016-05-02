	.global _FIRUp4, _upFunc4;
	
startAddr	.set	0x001860
bCoeff		.set	0+startAddr
dataInUp4	.set	1300+startAddr
iUp4		.set	1380+startAddr ; Data pointer
zeroCnt4	.set	1381+startAddr ; Data pointer

resetPtriUp4:	MOV #0,*(#iUp4)
			RET	

resetzeroCnt4:	MOV #0,*(#zeroCnt4)
			RET	
	
	
_FIRUp4
	MOV #0, AC1					; Clear AC1
	MOV #56, BK03				; Set buffer size to filter order
	MOV #dataInUp4,AC0				; Load AC0 with the data start addr
	MOV AC0,XAR2				; AR2 as coefficient pointer
	MOV mmap(AR2),BSA23        	; Set up base address for AR2
	MOV *(#iUp4),AC0				; Start the circular buffer at i'th data
	MOV AC0,AR2					; Start from the i'th data
	bset AR2LC					; Set pointer as circular
	MOV #bCoeff,AC0				; Load AC0 with the addr of the coefficients
	MOV AC0, AR1				; Load AR0 with the val of AC0
	RPT #24						
	MAC *AR2-,*AR1+,AC1 		; Do filter convolution
	SFTL AC1, #-15				; Bit shift to fit Q15				
	RET
	
	
_inputDataUp4
	; "Circular" data in Buffer
	MOV #dataInUp4,AC0				; Load address of input data into AC0
	ADD *(#iUp4),AC0				; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV T0, *AR0				; Move the value in T0 to the address
	RET

_inputZeroUp4
	; "Circular" data in Buffer
	MOV #dataInUp4,AC0				; Load address of input data into AC0
	ADD *(#iUp4),AC0				; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV #0, *AR0				; Move the value in T0 to the address
	RET

_upFunc4
	CMP *(#zeroCnt4)==#0,TC1
	CALLCC _inputDataUp4,TC1
	CMP *(#zeroCnt4)==#1,TC1
	CALLCC _inputZeroUp4,TC1
	ADD #1, *(#zeroCnt4)
	CMP *(#zeroCnt4)==#2,TC1
	CALLCC resetzeroCnt4, TC1
	CALL _FIRUp4
	ADD #1,*(#iUp4)				; Increment the data pointer
	CMP *(#iUp4)==#56,TC1			; Check if the data pointer should reset to 0
	CALLCC resetPtriUp4, TC1
	;MPY #2,AC1
	SFTS AC1, #1
	MOV AC1,T0
	ADD T1,T0
	RET
	
	
	
