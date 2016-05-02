	.global _RMS128;
	
startAddr	.set	0x001860

lookUpBand1	.set	20000+startAddr
dataIn1		.set	24100+startAddr
ptrBuff1	.set	24120+startAddr
ptrLUb1		.set	24121+startAddr
sumHigh		.set	24122+startAddr
sumLow		.set	24123+startAddr


resetptrBuff1:	MOV #0,*(#ptrBuff1)
				RET		
	
_RMS128
	; "Circular" data in Buffer
	MOV #dataIn1,AC0			; Load address of input data into AC0
	ADD *(#ptrBuff1),AC0		; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV *AR0, AC0				; Move the value which AR0 points to into AC0
	MOV #0, AC1
	MOV uns(*(#sumLow)), AC1
	MOV uns(*(#sumHigh)), AC2
	SFTL AC2, #16
	ADD AC2, AC1
	SUB AC0, AC1				; Subtract AC0 from AC1 and save it in AC1	 
	MOV T0, HI(AC2)					; Move the value in T0 to the address
	MPY T0, AC2, AC2											; Square AC0 and save it in AC2
	SFTL AC2, #-15				; 
	ADD AC2, AC1
	MOV AC1, *(#sumLow)
	MOV HI(AC1), *(#sumHigh)
	MOV AC2, *AR0
	ADD #1,*(#ptrBuff1)				; Increment the data pointer
	CMP *(#ptrBuff1)==#16,TC1		; Check if the data pointer should reset to 0
	CALLCC resetptrBuff1, TC1
	SFTL AC1, #-7
	ADD #lookUpBand1, AC1			; Adjust the value to correct loaction in memory
	MOV AC1, AR0
	MOV *AR0, AC0
	SFTL AC0, #16
	MPY T0, AC0, AC1
	SFTL AC1, #-15
	MOV AC1, T0						
	RET



	
	
