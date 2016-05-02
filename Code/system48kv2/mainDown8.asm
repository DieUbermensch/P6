	.global _FIR8, _downFunc8, _initArray8;
	
startAddr	.set	0x001860
bCoeff		.set	0+startAddr
dataIn8		.set	400+startAddr
firOut8		.set	430+startAddr
i8			.set	480+startAddr ; Data pointer
k8			.set	481+startAddr ; FIR output pointer
b8			.set	482+startAddr ; Band pass filter data pointer
d8			.set	483+startAddr ; Delay pointer

band8		.set	484+startAddr
down8		.set	485+startAddr	

_initArray8
	MOV #12, *(#d8)
	RET

resetPtri8:	MOV #0,*(#i8)
			RET	

resetPtrd8:	MOV #0,*(#d8)
			RET	

DownOut1: 	MOV T0,*(#down8)
			RET			

resetk8: 	MOV #0,*(#k8)
			RET	

_FIR8
	MOV #0, AC1					; Clear AC1
	MOV #25, BK03				; Set buffer size to filter order
	MOV #dataIn8,AC0				; Load AC0 with the data start addr
	MOV AC0,XAR2				; AR2 as coefficient pointer
	MOV mmap(AR2),BSA23        	; Set up base address for AR2
	MOV *(#i8),AC0				; Start the circular buffer at i'th data
	MOV AC0,AR2					; Start from the i'th data
	bset AR2LC					; Set pointer as circular
	MOV #bCoeff,AC0				; Load AC0 with the addr of the coefficients
	MOV AC0, AR1				; Load AR0 with the val of AC0
	RPT #24						
	MAC *AR2+,*AR1+,AC1 		; Do filter convolution
	SFTL AC1, #-15				; Bit shift to fit Q15
	MOV AC1,T0     				
	RET
	
inputData8	.macro	
	; "Circular" data in Buffer
	MOV #dataIn8,AC0				; Load address of input data into AC0
	ADD *(#i8),AC0				; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV T0, *AR0				; Move the value in T0 to the address
	ADD #1,*(#i8)				; Increment the data pointer
	ADD #1,*(#d8)				; Increment the delay pointer
	CMP *(#i8)==#25,TC1			; Check if the data pointer should reset to 0
	CALLCC resetPtri8, TC1
	CMP *(#d8)==#25,TC1			; Check if the delay pointer should reset to 0
	CALLCC resetPtrd8, TC1
	.endm
	
				
_downFunc8
	; Circular Buffer initialize
	inputData8					; Read data in
	CALL _FIR8					
	MOV T0, *(#firOut8)			; Save data in addr of firOut8
	;Sub Spectrum
	MOV #dataIn8, AC0			
	ADD *(#d8), AC0				
	MOV AC0, AR0
	MOV *AR0,AC0
	SUB T0, AC0
	MOV AC0,*(#band8)
	;DownSample
	CMP *(#k8)==#0, TC1
	CALLCC DownOut1, TC1
	ADD #1, *(#k8)
	CMP *(#k8)==#2, TC1
	CALLCC resetk8, TC1
	RET
	
	
	
