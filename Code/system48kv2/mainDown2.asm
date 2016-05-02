	.global _FIR2, _downFunc2, _initArray2;
	
startAddr	.set	0x001860
bCoeff		.set	0+startAddr
dataIn2		.set	200+startAddr
firOut2		.set	230+startAddr
i2			.set	280+startAddr ; Data pointer
k2			.set	281+startAddr ; FIR output pointer
b2			.set	282+startAddr ; Band pass filter data pointer
d2			.set	283+startAddr ; Delay pointer

band2		.set	284+startAddr
down2		.set	285+startAddr	

_initArray2
	MOV #12, *(#d2)
	RET

resetPtri2:	MOV #0,*(#i2)
			RET	

resetPtrd2:	MOV #0,*(#d2)
			RET	

DownOut2: 	MOV T0,*(#down2)
			RET			

resetK2: 	MOV #0,*(#k2)
			RET	
			

_FIR2	
	MOV #0, AC1					; Clear AC1
	MOV #25, BK03				; Set buffer size to filter order
	MOV #dataIn2,AC0				; Load AC0 with the data start addr
	MOV AC0,XAR2				; AR2 as coefficient pointer
	MOV mmap(AR2),BSA23        	; Set up base address for AR2
	MOV *(#i2),AC0				; Start the circular buffer at i'th data
	MOV AC0,AR2					; Start from the i'th data
	bset AR2LC					; Set pointer as circular
	MOV #bCoeff,AC0				; Load AC0 with the addr of the coefficients
	MOV AC0, AR1				; Load AR0 with the val of AC0
	RPT #24						
	MAC *AR2+,*AR1+,AC1 		; Do filter convolution
	SFTL AC1, #-15				; Bit shift to fit Q15
	MOV AC1,T0     				
	RET
	
inputData2	.macro	
	; "Circular" data in Buffer
	MOV #dataIn2,AC0				; Load address of input data into AC0
	ADD *(#i2),AC0				; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV T0, *AR0				; Move the value in T0 to the address
	ADD #1,*(#i2)				; Increment the data pointer
	ADD #1,*(#d2)				; Increment the delay pointer
	CMP *(#i2)==#25,TC1			; Check if the data pointer should reset to 0
	CALLCC resetPtri2, TC1
	CMP *(#d2)==#25,TC1			; Check if the delay pointer should reset to 0
	CALLCC resetPtrd2, TC1
	.endm
	
				
_downFunc2					; Read data in
	inputData2
	CALL _FIR2					
	MOV T0, *(#firOut2)			; Save data in addr of firOut1
	;Sub Spectrum
	MOV #dataIn2, AC0			
	ADD *(#d2), AC0				
	MOV AC0, AR0
	MOV *AR0,AC0
	SUB T0, AC0
	MOV AC0,*(#band2)
	;DownSample
	CMP *(#k2)==#0, TC1
	CALLCC DownOut2, TC1
	ADD #1, *(#k2)
	CMP *(#k2)==#2, TC1
	CALLCC resetK2, TC1
	RET
	
	
	
