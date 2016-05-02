	.global _FIR4, _downFunc4, _initArray4;
	
startAddr	.set	0x001860
bCoeff		.set	0+startAddr
dataIn4		.set	300+startAddr
firOut4		.set	330+startAddr
i4			.set	380+startAddr ; Data pointer
k4			.set	381+startAddr ; FIR output pointer
b4			.set	382+startAddr ; Band pass filter data pointer
d4			.set	383+startAddr ; Delay pointer

band4		.set	384+startAddr
down4		.set	385+startAddr	

_initArray4
	MOV #12, *(#d4)
	RET

resetPtri4:	MOV #0,*(#i4)
			RET	

resetPtrd4:	MOV #0,*(#d4)
			RET	

DownOut1: 	MOV T0,*(#down4)
			RET			

resetk4: 	MOV #0,*(#k4)
			RET	

_FIR4
	MOV #0, AC1					; Clear AC1
	MOV #25, BK03				; Set buffer size to filter order
	MOV #dataIn4,AC0				; Load AC0 with the data start addr
	MOV AC0,XAR2				; AR2 as coefficient pointer
	MOV mmap(AR2),BSA23        	; Set up base address for AR2
	MOV *(#i4),AC0				; Start the circular buffer at i'th data
	MOV AC0,AR2					; Start from the i'th data
	bset AR2LC					; Set pointer as circular
	MOV #bCoeff,AC0				; Load AC0 with the addr of the coefficients
	MOV AC0, AR1				; Load AR0 with the val of AC0
	RPT #24						
	MAC *AR2+,*AR1+,AC1 		; Do filter convolution
	SFTL AC1, #-15				; Bit shift to fit Q15
	MOV AC1,T0     				
	RET
	
inputData4	.macro	
	; "Circular" data in Buffer
	MOV #dataIn4,AC0				; Load address of input data into AC0
	ADD *(#i4),AC0				; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV T0, *AR0				; Move the value in T0 to the address
	ADD #1,*(#i4)				; Increment the data pointer
	ADD #1,*(#d4)				; Increment the delay pointer
	CMP *(#i4)==#25,TC1			; Check if the data pointer should reset to 0
	CALLCC resetPtri4, TC1
	CMP *(#d4)==#25,TC1			; Check if the delay pointer should reset to 0
	CALLCC resetPtrd4, TC1
	.endm
	
				
_downFunc4
	; Circular Buffer initialize
	inputData4					; Read data in
	CALL _FIR4					
	MOV T0, *(#firOut4)			; Save data in addr of firOut4
	;Sub Spectrum
	MOV #dataIn4, AC0			
	ADD *(#d4), AC0				
	MOV AC0, AR0
	MOV *AR0,AC0
	SUB T0, AC0
	MOV AC0,*(#band4)
	;DownSample
	CMP *(#k4)==#0, TC1
	CALLCC DownOut1, TC1
	ADD #1, *(#k4)
	CMP *(#k4)==#2, TC1
	CALLCC resetk4, TC1
	RET
	
	
	
