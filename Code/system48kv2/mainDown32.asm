	.global _FIR32, _downFunc32, _initArray32;
	
startAddr	.set	0x001860
bCoeff		.set	0+startAddr
dataIn32	.set	600+startAddr
firOut32	.set	630+startAddr
i32			.set	680+startAddr ; Data pointer
k32			.set	681+startAddr ; FIR output pointer
b32			.set	682+startAddr ; Band pass filter data pointer
d32			.set	683+startAddr ; Delay pointer

band32		.set	684+startAddr
down32		.set	685+startAddr	

_initArray32
	MOV #12, *(#d32)
	RET

resetPtri32:	MOV #0,*(#i32)
			RET	

resetPtrd32:	MOV #0,*(#d32)
			RET	

DownOut1: 	MOV T0,*(#down32)
			RET			

resetk32: 	MOV #0,*(#k32)
			RET	

_FIR32
	MOV #0, AC1					; Clear AC1
	MOV #25, BK03				; Set buffer size to filter order
	MOV #dataIn32,AC0				; Load AC0 with the data start addr
	MOV AC0,XAR2				; AR2 as coefficient pointer
	MOV mmap(AR2),BSA23        	; Set up base address for AR2
	MOV *(#i32),AC0				; Start the circular buffer at i'th data
	MOV AC0,AR2					; Start from the i'th data
	bset AR2LC					; Set pointer as circular
	MOV #bCoeff,AC0				; Load AC0 with the addr of the coefficients
	MOV AC0, AR1				; Load AR0 with the val of AC0
	RPT #24						
	MAC *AR2+,*AR1+,AC1 		; Do filter convolution
	SFTL AC1, #-15				; Bit shift to fit Q15
	MOV AC1,T0     				
	RET
	
inputData32	.macro	
	; "Circular" data in Buffer
	MOV #dataIn32,AC0				; Load address of input data into AC0
	ADD *(#i32),AC0				; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV T0, *AR0				; Move the value in T0 to the address
	ADD #1,*(#i32)				; Increment the data pointer
	ADD #1,*(#d32)				; Increment the delay pointer
	CMP *(#i32)==#25,TC1			; Check if the data pointer should reset to 0
	CALLCC resetPtri32, TC1
	CMP *(#d32)==#25,TC1			; Check if the delay pointer should reset to 0
	CALLCC resetPtrd32, TC1
	.endm
	
				
_downFunc32
	; Circular Buffer initialize
	inputData32					; Read data in
	CALL _FIR32					
	MOV T0, *(#firOut32)			; Save data in addr of firOut32
	;Sub Spectrum
	MOV #dataIn32, AC0			
	ADD *(#d32), AC0				
	MOV AC0, AR0
	MOV *AR0,AC0
	SUB T0, AC0
	MOV AC0,*(#band32)
	;DownSample
	CMP *(#k32)==#0, TC1
	CALLCC DownOut1, TC1
	ADD #1, *(#k32)
	CMP *(#k32)==#2, TC1
	CALLCC resetk32, TC1
	RET
	
	
	
