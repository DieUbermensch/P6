	.global _FIR16, _downFunc16, _initArray16;
	
startAddr	.set	0x001860
bCoeff		.set	0+startAddr
dataIn16	.set	500+startAddr
firOut16		.set	530+startAddr
i16			.set	580+startAddr ; Data pointer
k16			.set	581+startAddr ; FIR output pointer
b16			.set	582+startAddr ; Band pass filter data pointer
d16			.set	583+startAddr ; Delay pointer

band16		.set	584+startAddr
down16		.set	585+startAddr	

_initArray16
	MOV #12, *(#d16)
	RET

resetPtri16:	MOV #0,*(#i16)
			RET	

resetPtrd16:	MOV #0,*(#d16)
			RET	

DownOut1: 	MOV T0,*(#down16)
			RET			

resetk16: 	MOV #0,*(#k16)
			RET	

_FIR16
	MOV #0, AC1					; Clear AC1
	MOV #25, BK03				; Set buffer size to filter order
	MOV #dataIn16,AC0				; Load AC0 with the data start addr
	MOV AC0,XAR2				; AR2 as coefficient pointer
	MOV mmap(AR2),BSA23        	; Set up base address for AR2
	MOV *(#i16),AC0				; Start the circular buffer at i'th data
	MOV AC0,AR2					; Start from the i'th data
	bset AR2LC					; Set pointer as circular
	MOV #bCoeff,AC0				; Load AC0 with the addr of the coefficients
	MOV AC0, AR1				; Load AR0 with the val of AC0
	RPT #24						
	MAC *AR2+,*AR1+,AC1 		; Do filter convolution
	SFTL AC1, #-15				; Bit shift to fit Q15
	MOV AC1,T0     				
	RET
	
inputData16	.macro	
	; "Circular" data in Buffer
	MOV #dataIn16,AC0				; Load address of input data into AC0
	ADD *(#i16),AC0				; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV T0, *AR0				; Move the value in T0 to the address
	ADD #1,*(#i16)				; Increment the data pointer
	ADD #1,*(#d16)				; Increment the delay pointer
	CMP *(#i16)==#25,TC1			; Check if the data pointer should reset to 0
	CALLCC resetPtri16, TC1
	CMP *(#d16)==#25,TC1			; Check if the delay pointer should reset to 0
	CALLCC resetPtrd16, TC1
	.endm
	
				
_downFunc16
	; Circular Buffer initialize
	inputData16					; Read data in
	CALL _FIR16					
	MOV T0, *(#firOut16)			; Save data in addr of firOut16
	;Sub Spectrum
	MOV #dataIn16, AC0			
	ADD *(#d16), AC0				
	MOV AC0, AR0
	MOV *AR0,AC0
	SUB T0, AC0
	MOV AC0,*(#band16)
	;DownSample
	CMP *(#k16)==#0, TC1
	CALLCC DownOut1, TC1
	ADD #1, *(#k16)
	CMP *(#k16)==#1, TC1
	CALLCC resetk16, TC1
	RET
	
	
	
