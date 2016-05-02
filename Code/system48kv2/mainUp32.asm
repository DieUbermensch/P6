	.global _FIRUp32, _upFunc32;
	
startAddr	.set	0x001860
bCoeff		.set	0+startAddr
dataInUp32	.set	1600+startAddr
iUp32		.set	1680+startAddr ; Data pointer
zeroCnt32	.set	1681+startAddr ; Data pointer

resetPtriUp32:	MOV #0,*(#iUp32)
			RET	

resetzeroCnt32:	MOV #0,*(#zeroCnt32)
			RET	
	
	
_FIRUp32
	MOV #0, AC1					; Clear AC1
	MOV #56, BK03				; Set buffer size to filter order
	MOV #dataInUp32,AC0				; Load AC0 with the data start addr
	MOV AC0,XAR2				; AR2 as coefficient pointer
	MOV mmap(AR2),BSA23        	; Set up base address for AR2
	MOV *(#iUp32),AC0				; Start the circular buffer at i'th data
	MOV AC0,AR2					; Start from the i'th data
	bset AR2LC					; Set pointer as circular
	MOV #bCoeff,AC0				; Load AC0 with the addr of the coefficients
	MOV AC0, AR1				; Load AR0 with the val of AC0
	RPT #24						
	MAC *AR2-,*AR1+,AC1 		; Do filter convolution
	SFTL AC1, #-15				; Bit shift to fit Q15				
	RET
	
	
_inputDataUp32
	; "Circular" data in Buffer
	MOV #dataInUp32,AC0				; Load address of input data into AC0
	ADD *(#iUp32),AC0				; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV T0, *AR0				; Move the value in T0 to the address
	RET

_inputZeroUp32
	; "Circular" data in Buffer
	MOV #dataInUp32,AC0				; Load address of input data into AC0
	ADD *(#iUp32),AC0				; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV #0, *AR0				; Move the value in T0 to the address
	RET

_upFunc32
	CMP *(#zeroCnt32)==#0,TC1
	CALLCC _inputDataUp32,TC1
	CMP *(#zeroCnt32)==#1,TC1
	CALLCC _inputZeroUp32,TC1
	ADD #1, *(#zeroCnt32)
	CMP *(#zeroCnt32)==#2,TC1
	CALLCC resetzeroCnt32, TC1
	CALL _FIRUp32
	ADD #1,*(#iUp32)				; Increment the data pointer
	CMP *(#iUp32)==#56,TC1			; Check if the data pointer should reset to 0
	CALLCC resetPtriUp32, TC1
	;MPY #2,AC1
	SFTS AC1, #1
	MOV AC1,T0
	ADD T1,T0
	RET
	
	
	
