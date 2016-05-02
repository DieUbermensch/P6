	.global _FIR1, _downFunc1, _initArray1;
	
startAddr	.set	0x001860
bCoeff		.set	0+startAddr
dataIn1		.set	100+startAddr
firOut1		.set	130+startAddr
i1			.set	180+startAddr ; Data pointer
k1			.set	181+startAddr ; FIR output pointer
b1			.set	182+startAddr ; Band pass filter data pointer
d1			.set	183+startAddr ; Delay pointer

band1		.set	184+startAddr
down1		.set	185+startAddr	

_initArray1
	MOV #12, *(#d1)
	RET

resetPtri1:	MOV #0,*(#i1)
			RET	

resetPtrd1:	MOV #0,*(#d1)
			RET	

DownOut1: 	MOV T0,*(#down1)
			RET			

resetK1: 	MOV #0,*(#k1)
			RET	

_FIR1	
	MOV #0, AC1					; Clear AC1
	MOV #25, BK03				; Set buffer size to filter order
	MOV #dataIn1,AC0				; Load AC0 with the data start addr
	MOV AC0,XAR2				; AR2 as coefficient pointer
	MOV mmap(AR2),BSA23        	; Set up base address for AR2
	MOV *(#i1),AC0				; Start the circular buffer at i'th data
	MOV AC0,AR2					; Start from the i'th data
	bset AR2LC					; Set pointer as circular
	MOV #bCoeff,AC0				; Load AC0 with the addr of the coefficients
	MOV AC0, AR1				; Load AR0 with the val of AC0
	RPT #24						
	MAC *AR2+,*AR1+,AC1 		; Do filter convolution
	SFTL AC1, #-15				; Bit shift to fit Q15
	MOV AC1,T0     				
	RET
	
inputData1	.macro	
	; "Circular" data in Buffer
	MOV #dataIn1,AC0				; Load address of input data into AC0
	ADD *(#i1),AC0				; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV T0, *AR0				; Move the value in T0 to the address
	ADD #1,*(#i1)				; Increment the data pointer
	ADD #1,*(#d1)				; Increment the delay pointer
	CMP *(#i1)==#25,TC1			; Check if the data pointer should reset to 0
	CALLCC resetPtri1, TC1
	CMP *(#d1)==#25,TC1			; Check if the delay pointer should reset to 0
	CALLCC resetPtrd1, TC1
	.endm
	
				
_downFunc1
	; Circular Buffer initialize
	inputData1					; Read data in
	CALL _FIR1					
	MOV T0, *(#firOut1)			; Save data in addr of firOut1
	;Sub Spectrum
	MOV #dataIn1, AC0			
	ADD *(#d1), AC0				
	MOV AC0, AR0
	MOV *AR0,AC0
	SUB T0, AC0
	MOV AC0,*(#band1)
	;DownSample
	CMP *(#k1)==#0, TC1
	CALLCC DownOut1, TC1
	ADD #1, *(#k1)
	CMP *(#k1)==#2, TC1
	CALLCC resetK1, TC1
	RET
	
	
	
