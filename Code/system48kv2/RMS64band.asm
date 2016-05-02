	.global _RMS64band;
	
startAddr	.set	0x001860

lookUpBand4	.set	20000+startAddr
dataIn4		.set	24300+startAddr
ptrBuff4	.set	24320+startAddr
ptrLUb4		.set	24321+startAddr
sumHigh4	.set	24322+startAddr
sumLow4		.set	24323+startAddr


resetptrBuff4:	MOV #0,*(#ptrBuff4)
				RET		
	
_RMS64band
	; "Circular" data in Buffer
	MOV #dataIn4,AC0			; Load address of input data into AC0
	ADD *(#ptrBuff4),AC0		; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV *AR0, AC0				; Move the value which AR0 points to into AC0
	MOV #0, AC1
	MOV uns(*(#sumLow4)), AC1
	MOV uns(*(#sumHigh4))<<#16, AC2
	ADD AC2, AC1
	SUB AC0, AC1				; Subtract AC0 from AC1 and save it in AC1	 
	MOV T0, HI(AC2)					; Move the value in T0 to the address
	MPY T0, AC2, AC2											; Square AC0 and save it in AC2
	SFTL AC2, #-15				; 
	ADD AC2, AC1
	MOV AC1, *(#sumLow4)
	MOV HI(AC1), *(#sumHigh4)
	MOV AC2, *AR0
	ADD #1,*(#ptrBuff4)				; Increment the data pointer
	CMP *(#ptrBuff4)==#16,TC1		; Check if the data pointer should reset to 0
	CALLCC resetptrBuff4, TC1
	SFTL AC1, #-7
	ADD #lookUpBand4, AC1			; Adjust the value to correct loaction in memory
	MOV AC1, AR0
	MOV *AR0, AC0
	SFTL AC0, #16
	MPY T0, AC0, AC1
	SFTL AC1, #-15
	MOV AC1, T0						
	RET



	
	
