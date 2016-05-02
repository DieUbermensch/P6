	.global _delayB32;
	
startAddr	.set	0x001860

iD32		.set	18500+startAddr
delayB32Ptr	.set	17999+startAddr

resetPtri32:	MOV #0,*(#iD32)
			RET		

inputDelay32	.macro	
	; "Circular" data in Buffer
	MOV #delayB32Ptr,AC0			; Load address of input data into AC0
	ADD *(#iD32),AC0				; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV T0, *AR0				; Move the value in T0 to the address
	ADD #1,*(#iD32)				; Increment the data pointer
	CMP *(#iD32)==#156,TC1			; Check if the data pointer should reset to 0
	CALLCC resetPtri32, TC1
	MOV #delayB32Ptr,AC0			; Load address of input data into AC0
	ADD *(#iD32),AC0	
	MOV AC0,AR0
	MOV *AR0,T0		
	.endm
	
_delayB32
	inputDelay32
	RET



	
	
