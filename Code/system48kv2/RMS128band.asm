	.global _RMS128band;
	
startAddr	.set	0x001860

lookUpBand2	.set	20000+startAddr
dataIn2		.set	24200+startAddr
ptrBuff2	.set	24220+startAddr
ptrLUb2		.set	24221+startAddr
sumHigh2	.set	24222+startAddr
sumLow2		.set	24223+startAddr


resetptrBuff2:	MOV #0,*(#ptrBuff2)
				RET		
	
_RMS128band
	; "Circular" data in Buffer
	MOV #dataIn2,AC0			; Load address of input data into AC0
	ADD *(#ptrBuff2),AC0		; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV *AR0, AC0				; Move the value which AR0 points to into AC0
	MOV #0, AC1
	MOV uns(*(#sumLow2)), AC1
	MOV uns(*(#sumHigh2))<<#16, AC2
	ADD AC2, AC1
	SUB AC0, AC1				; Subtract AC0 from AC1 and save it in AC1	 
	MOV T0, HI(AC2)					; Move the value in T0 to the address
	MPY T0, AC2, AC2											; Square AC0 and save it in AC2
	SFTL AC2, #-15				; 
	ADD AC2, AC1
	MOV AC1, *(#sumLow2)
	MOV HI(AC1), *(#sumHigh2)
	MOV AC2, *AR0
	ADD #1,*(#ptrBuff2)				; Increment the data pointer
	CMP *(#ptrBuff2)==#16,TC1		; Check if the data pointer should reset to 0
	CALLCC resetptrBuff2, TC1
	SFTL AC1, #-7
	ADD #lookUpBand2, AC1			; Adjust the value to correct loaction in memory
	MOV AC1, AR0
	MOV *AR0, AC0
	SFTL AC0, #16
	MPY T0, AC0, AC1
	SFTL AC1, #-15
	MOV AC1, T0						
	RET



	
	
