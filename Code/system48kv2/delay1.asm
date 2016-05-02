	.global _delayB1;
	
startAddr	.set	0x001860

iD1			.set	9999+startAddr
delayB1Ptr	.set	3000+startAddr

resetPtri1:	MOV #0,*(#iD1)
			RET		

inputDelay1	.macro	
	; "Circular" data in Buffer
	MOV #delayB1Ptr,AC0			; Load address of input data into AC0
	ADD *(#iD1),AC0				; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV T0, *AR0				; Move the value in T0 to the address
	ADD #1,*(#iD1)				; Increment the data pointer
	CMP *(#iD1)==#6108,TC1			; Check if the data pointer should reset to 0
	CALLCC resetPtri1, TC1
	MOV #delayB1Ptr,AC0			; Load address of input data into AC0
	ADD *(#iD1),AC0	
	MOV AC0,AR0
	MOV *AR0,T0		
	.endm
	
_delayB1
	inputDelay1
	RET



	
	
