	.global _RMS32up;
	
startAddr	.set	0x001860

lookUpUp	.set	21024+startAddr
dataInUp	.set	24500+startAddr
ptrBuffUp	.set	24564+startAddr
ptrLUbUp	.set	24565+startAddr
sumHighUp	.set	24566+startAddr
sumLowUp	.set	24567+startAddr


resetptrBuffUp:	MOV #0,*(#ptrBuffUp)
				RET		
	
_RMS32up
	; "Circular" data in Buffer
	MOV #dataInUp,AC0			; Load address of input data into AC0
	ADD *(#ptrBuffUp),AC0		; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV *AR0, AC0				; Move the value which AR0 points to into AC0
	MOV #0, AC1
	MOV uns(*(#sumLowUp)), AC1
	MOV uns(*(#sumHighUp))<<#16, AC2
	ADD AC2, AC1
	SUB AC0, AC1				; Subtract AC0 from AC1 and save it in AC1	 
	MOV T0, HI(AC2)					; Move the value in T0 to the address
	MPY T0, AC2, AC2											; Square AC0 and save it in AC2
	SFTL AC2, #-15				; 
	ADD AC2, AC1
	MOV AC1, *(#sumLowUp)
	MOV HI(AC1), *(#sumHighUp)
	MOV AC2, *AR0
	ADD #1,*(#ptrBuffUp)				; Increment the data pointer
	CMP *(#ptrBuffUp)==#64,TC1		; Check if the data pointer should reset to 0
	CALLCC resetptrBuffUp, TC1
	SFTL AC1, #-9
	ADD #lookUpUp, AC1			; Adjust the value to correct loaction in memory
	MOV AC1, AR0
	MOV *AR0, AC0
	SFTL AC0, #16
	MPY T0, AC0, AC1
	SFTL AC1, #-15
	MOV AC1, T0						
	RET



	
	
