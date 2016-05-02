	.global _delayB2;
	
startAddr	.set	0x001860

iD2			.set	13999+startAddr
delayB2Ptr	.set	10500+startAddr

resetPtri2:	MOV #0,*(#iD2)
			RET		


inputDelay2	.macro	
	; "Circular" data in Buffer
	MOV #delayB2Ptr,AC0			; Load address of input data into AC0
	ADD *(#iD2),AC0				; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV T0, *AR0				; Move the value in T0 to the address
	ADD #1,*(#iD2)				; Increment the data pointer
	CMP *(#iD2)==#3036,TC1			; Check if the data pointer should reset to 0
	CALLCC resetPtri2, TC1
	MOV #delayB2Ptr,AC0			; Load address of input data into AC0
	ADD *(#iD2),AC0	
	MOV AC0,AR0
	MOV *AR0,T0		
	.endm
	
_delayB2
	inputDelay2
	RET



	
	
