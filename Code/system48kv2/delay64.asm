	.global _delayB64;
	
startAddr	.set	0x001860

iD64		.set	19500+startAddr
delayB64Ptr	.set	18600+startAddr

resetPtri64:	MOV #0,*(#iD64)
			RET		

inputDelay64	.macro	
	; "Circular" data in Buffer
	MOV #delayB64Ptr,AC0			; Load address of input data into AC0
	ADD *(#iD64),AC0				; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV T0, *AR0				; Move the value in T0 to the address
	ADD #1,*(#iD64)				; Increment the data pointer
	CMP *(#iD64)==#60,TC1			; Check if the data pointer should reset to 0
	CALLCC resetPtri64, TC1
	MOV #delayB64Ptr,AC0			; Load address of input data into AC0
	ADD *(#iD64),AC0	
	MOV AC0,AR0
	MOV *AR0,T0		
	.endm
	
_delayB64
	inputDelay64
	RET



	
	
