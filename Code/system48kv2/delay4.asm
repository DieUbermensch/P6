	.global _delayB4;
	
startAddr	.set	0x001860

iD4			.set	15900+startAddr
delayB4Ptr	.set	14100+startAddr

resetPtri4:	MOV #0,*(#iD4)
			RET		

inputDelay4	.macro	
	; "Circular" data in Buffer
	MOV #delayB4Ptr,AC0			; Load address of input data into AC0
	ADD *(#iD4),AC0				; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV T0, *AR0				; Move the value in T0 to the address
	ADD #1,*(#iD4)				; Increment the data pointer
	CMP *(#iD4)==#1500,TC1			; Check if the data pointer should reset to 0
	CALLCC resetPtri4, TC1
	MOV #delayB4Ptr,AC0			; Load address of input data into AC0
	ADD *(#iD4),AC0	
	MOV AC0,AR0
	MOV *AR0,T0		
	.endm
	
_delayB4
	inputDelay4
	RET



	
	
