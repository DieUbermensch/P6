	.global _delayB16;
	
startAddr	.set	0x001860

iD16		.set	17700+startAddr
delayB16Ptr	.set	17100+startAddr

resetPtri16:	MOV #0,*(#iD16)
			RET		

inputDelay16	.macro	
	; "Circular" data in Buffer
	MOV #delayB16Ptr,AC0			; Load address of input data into AC0
	ADD *(#iD16),AC0				; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV T0, *AR0				; Move the value in T0 to the address
	ADD #1,*(#iD16)				; Increment the data pointer
	CMP *(#iD16)==#348,TC1			; Check if the data pointer should reset to 0
	CALLCC resetPtri16, TC1
	MOV #delayB16Ptr,AC0			; Load address of input data into AC0
	ADD *(#iD16),AC0	
	MOV AC0,AR0
	MOV *AR0,T0		
	.endm
	
_delayB16
	inputDelay16
	RET



	
	
