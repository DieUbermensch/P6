	.global _FIRUp2, _upFunc2;
	
startAddr	.set	0x001860
bCoeff		.set	0+startAddr
dataInUp2	.set	1200+startAddr
iUp2		.set	1280+startAddr ; Data pointer
zeroCnt2	.set	1281+startAddr ; Data pointer

resetPtriUp2:	MOV #0,*(#iUp2)
			RET	

resetZeroCnt2:	MOV #0,*(#zeroCnt2)
			RET	

	
_FIRUp2
	MOV #0, AC1					; Clear AC1
	MOV #56, BK03				; Set buffer size to filter order
	MOV #dataInUp2,AC0				; Load AC0 with the data start addr
	MOV AC0,XAR2				; AR2 as coefficient pointer
	MOV mmap(AR2),BSA23        	; Set up base address for AR2
	MOV *(#iUp2),AC0				; Start the circular buffer at i'th data
	MOV AC0,AR2					; Start from the i'th data
	bset AR2LC					; Set pointer as circular
	MOV #bCoeff,AC0				; Load AC0 with the addr of the coefficients
	MOV AC0, AR1				; Load AR0 with the val of AC0
	RPT #24						
	MAC *AR2-,*AR1+,AC1 		; Do filter convolution
	SFTL AC1, #-15				; Bit shift to fit Q15				
	RET
	
	
_inputDataUp2
	; "Circular" data in Buffer
	MOV #dataInUp2,AC0				; Load address of input data into AC0
	ADD *(#iUp2),AC0				; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV T0, *AR0				; Move the value in T0 to the address
	RET

_inputZeroUp2
	; "Circular" data in Buffer
	MOV #dataInUp2,AC0				; Load address of input data into AC0
	ADD *(#iUp2),AC0				; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV #0, *AR0				; Move the value in T0 to the address
	RET

_upFunc2
	CMP *(#zeroCnt2)==#0,TC1
	CALLCC _inputDataUp2,TC1
	CMP *(#zeroCnt2)==#1,TC1
	CALLCC _inputZeroUp2,TC1
	ADD #1, *(#zeroCnt2)
	CMP *(#zeroCnt2)==#2,TC1
	CALLCC resetZeroCnt2, TC1
	CALL _FIRUp2
	ADD #1,*(#iUp2)				; Increment the data pointer
	CMP *(#iUp2)==#56,TC1			; Check if the data pointer should reset to 0
	CALLCC resetPtriUp2, TC1
	;MPY #2,AC1
	SFTS AC1, #1
	MOV AC1,T0
	ADD T1,T0
	RET
	
	
	
