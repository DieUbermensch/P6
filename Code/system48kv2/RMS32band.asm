	.global _RMS32band;
	
startAddr	.set	0x001860

lookUpBand8	.set	20000+startAddr
dataIn8		.set	24400+startAddr
ptrBuff8	.set	24420+startAddr
ptrLUb8		.set	24421+startAddr
sumHigh8	.set	24422+startAddr
sumLow8		.set	24423+startAddr


resetptrBuff8:	MOV #0,*(#ptrBuff8)
				RET		
	
_RMS32band
	; "Circular" data in Buffer
	MOV #dataIn8,AC0			; Load address of input data into AC0
	ADD *(#ptrBuff8),AC0		; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV *AR0, AC0				; Move the value which AR0 points to into AC0
	MOV #0, AC1
	MOV uns(*(#sumLow8)), AC1
	MOV uns(*(#sumHigh8))<<#16, AC2
	ADD AC2, AC1
	SUB AC0, AC1				; Subtract AC0 from AC1 and save it in AC1	 
	MOV T0, HI(AC2)					; Move the value in T0 to the address
	MPY T0, AC2, AC2											; Square AC0 and save it in AC2
	SFTL AC2, #-15				; 
	ADD AC2, AC1
	MOV AC1, *(#sumLow8)
	MOV HI(AC1), *(#sumHigh8)
	MOV AC2, *AR0
	ADD #1,*(#ptrBuff8)				; Increment the data pointer
	CMP *(#ptrBuff8)==#16,TC1		; Check if the data pointer should reset to 0
	CALLCC resetptrBuff8, TC1
	SFTL AC1, #-7
	ADD #lookUpBand8, AC1			; Adjust the value to correct loaction in memory
	MOV AC1, AR0
	MOV *AR0, AC0
	SFTL AC0, #16
	MPY T0, AC0, AC1
	SFTL AC1, #-15
	MOV AC1, T0						
	RET



	
	
