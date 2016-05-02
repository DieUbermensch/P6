	.global _delayB8;
	
startAddr	.set	0x001860

iD8			.set	16999+startAddr
delayB8Ptr	.set	15999+startAddr

resetPtri8:	MOV #0,*(#iD8)
			RET		

inputDelay8	.macro	
	; "Circular" data in Buffer
	MOV #delayB8Ptr,AC0			; Load address of input data into AC0
	ADD *(#iD8),AC0				; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV T0, *AR0				; Move the value in T0 to the address
	ADD #1,*(#iD8)				; Increment the data pointer
	CMP *(#iD8)==#732,TC1			; Check if the data pointer should reset to 0
	CALLCC resetPtri8, TC1
	MOV #delayB8Ptr,AC0			; Load address of input data into AC0
	ADD *(#iD8),AC0	
	MOV AC0,AR0
	MOV *AR0,T0		
	.endm
	
_delayB8
	inputDelay8
	RET



	
	
