	.global _FIR64, _downFunc64, _initArray64;
	
startAddr	.set	0x001860
bCoeff		.set	0+startAddr
dataIn64	.set	700+startAddr
firOut64	.set	730+startAddr
i64			.set	780+startAddr ; Data pointer
k64			.set	781+startAddr ; FIR output pointer
b64			.set	782+startAddr ; Band pass filter data pointer
d64			.set	783+startAddr ; Delay pointer

band64		.set	784+startAddr
down64		.set	785+startAddr	

_initArray64
	MOV #12, *(#d64)
	RET

resetPtri64:	MOV #0,*(#i64)
			RET	

resetPtrd64:	MOV #0,*(#d64)
			RET	

DownOut1: 	MOV T0,*(#down64)
			RET			

resetk64: 	MOV #0,*(#k64)
			RET	

_FIR64
	MOV #0, AC1					; Clear AC1
	MOV #25, BK03				; Set buffer size to filter order
	MOV #dataIn64,AC0				; Load AC0 with the data start addr
	MOV AC0,XAR2				; AR2 as coefficient pointer
	MOV mmap(AR2),BSA23        	; Set up base address for AR2
	MOV *(#i64),AC0				; Start the circular buffer at i'th data
	MOV AC0,AR2					; Start from the i'th data
	bset AR2LC					; Set pointer as circular
	MOV #bCoeff,AC0				; Load AC0 with the addr of the coefficients
	MOV AC0, AR1				; Load AR0 with the val of AC0
	RPT #24						
	MAC *AR2+,*AR1+,AC1 		; Do filter convolution
	SFTL AC1, #-15				; Bit shift to fit Q15
	MOV AC1,T0     				
	RET
	
inputData64	.macro	
	; "Circular" data in Buffer
	MOV #dataIn64,AC0				; Load address of input data into AC0
	ADD *(#i64),AC0				; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV T0, *AR0				; Move the value in T0 to the address
	ADD #1,*(#i64)				; Increment the data pointer
	ADD #1,*(#d64)				; Increment the delay pointer
	CMP *(#i64)==#25,TC1			; Check if the data pointer should reset to 0
	CALLCC resetPtri64, TC1
	CMP *(#d64)==#25,TC1			; Check if the delay pointer should reset to 0
	CALLCC resetPtrd64, TC1
	.endm
	
				
_downFunc64
	; Circular Buffer initialize
	inputData64					; Read data in
	CALL _FIR64					
	MOV T0, *(#firOut64)			; Save data in addr of firOut64
	;Sub Spectrum
	MOV #dataIn64, AC0			
	ADD *(#d64), AC0				
	MOV AC0, AR0
	MOV *AR0,AC0
	SUB T0, AC0
	MOV AC0,*(#band64)
	;DownSample
	CMP *(#k64)==#0, TC1
	CALLCC DownOut1, TC1
	ADD #1, *(#k64)
	CMP *(#k64)==#2, TC1
	CALLCC resetk64, TC1
	RET
	
	
	
