	.global _FIRUp1, _upFunc1;
	
startAddr	.set	0x001860
bCoeff		.set	0+startAddr
dataInUp1	.set	1100+startAddr
iUp1		.set	1180+startAddr ; Data pointer
zeroCnt		.set	1181+startAddr ; Data pointer

resetPtriUp1:	MOV #0,*(#iUp1)
			RET	

resetZeroCnt:	MOV #0,*(#zeroCnt)
			RET	
	
_FIRUp1	
	MOV #0, AC1					; Clear AC1
	MOV #56, BK03				; Set buffer size to filter order
	MOV #dataInUp1,AC0				; Load AC0 with the data start addr
	MOV AC0,XAR2				; AR2 as coefficient pointer
	MOV mmap(AR2),BSA23        	; Set up base address for AR2
	MOV *(#iUp1),AC0				; Start the circular buffer at i'th data
	MOV AC0,AR2					; Start from the i'th data
	bset AR2LC					; Set pointer as circular
	MOV #bCoeff,AC0				; Load AC0 with the addr of the coefficients
	MOV AC0, AR1				; Load AR0 with the val of AC0
	RPT #24					
	MAC *AR2-,*AR1+,AC1 		; Do filter convolution
	SFTL AC1, #-15				; Bit shift to fit Q15				
	RET
	
	
_inputDataUp1
	; "Circular" data in Buffer
	MOV #dataInUp1,AC0				; Load address of input data into AC0
	ADD *(#iUp1),AC0				; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV T0, *AR0				; Move the value in T0 to the address
	;ADD #1,*(#iUp1)				; Increment the data pointer
	;CMP *(#iUp1)==#56,TC1			; Check if the data pointer should reset to 0
	;CALLCC resetPtriUp1, TC1
	RET

_inputZeroUp1
	; "Circular" data in Buffer
	MOV #dataInUp1,AC0				; Load address of input data into AC0
	ADD *(#iUp1),AC0				; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV #0, *AR0				; Move the value in T0 to the address
	RET

_upFunc1
	CMP *(#zeroCnt)==#0,TC1
	CALLCC _inputDataUp1,TC1
	CMP *(#zeroCnt)==#1,TC1
	CALLCC _inputZeroUp1,TC1
	ADD #1, *(#zeroCnt)
	CMP *(#zeroCnt)==#2,TC1
	CALLCC resetZeroCnt, TC1
	CALL _FIRUp1
	ADD #1,*(#iUp1)				; Increment the data pointer
	CMP *(#iUp1)==#56,TC1			; Check if the data pointer should reset to 0
	CALLCC resetPtriUp1, TC1
	;MPY #2,AC1
	SFTS AC1, #1
	MOV AC1,T0
	ADD T1,T0
	RET
	
	
	
