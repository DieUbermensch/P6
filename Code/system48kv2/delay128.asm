	.global _delayB128;
	
startAddr	.set	0x001860

iD128		.set	19900+startAddr
delayB128Ptr	.set	19600+startAddr

resetPtri128:	MOV #0,*(#iD128)
			RET		

inputDelay128	.macro	
	; "Circular" data in Buffer
	MOV #delayB128Ptr,AC0			; Load address of input data into AC0
	ADD *(#iD128),AC0				; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV T0, *AR0				; Move the value in T0 to the address
	ADD #1,*(#iD128)				; Increment the data pointer
	CMP *(#iD128)==#12,TC1			; Check if the data pointer should reset to 0
	CALLCC resetPtri128, TC1
	MOV #delayB128Ptr,AC0			; Load address of input data into AC0
	ADD *(#iD128),AC0	
	MOV AC0,AR0
	MOV *AR0,T0		
	.endm
	
_delayB128
	inputDelay128
	RET



	
	
