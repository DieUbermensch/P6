	.global _FIR128, _downFunc128, _initArray128;
	
startAddr	.set	0x001860
bCoeff		.set	0+startAddr
dataIn128	.set	800+startAddr
firOut128	.set	830+startAddr
i128			.set	880+startAddr ; Data pointer
k128			.set	881+startAddr ; FIR output pointer
b128			.set	882+startAddr ; Band pass filter data pointer
d128			.set	883+startAddr ; Delay pointer

band128		.set	884+startAddr
down128		.set	885+startAddr	

_initArray128
	MOV #12, *(#d128)
	RET

resetPtri128:	MOV #0,*(#i128)
			RET	

resetPtrd128:	MOV #0,*(#d128)
			RET	

DownOut1: 	MOV T0,*(#down128)
			RET			

resetk128: 	MOV #0,*(#k128)
			RET	

_FIR128
	MOV #0, AC1					; Clear AC1
	MOV #25, BK03				; Set buffer size to filter order
	MOV #dataIn128,AC0				; Load AC0 with the data start addr
	MOV AC0,XAR2				; AR2 as coefficient pointer
	MOV mmap(AR2),BSA23        	; Set up base address for AR2
	MOV *(#i128),AC0				; Start the circular buffer at i'th data
	MOV AC0,AR2					; Start from the i'th data
	bset AR2LC					; Set pointer as circular
	MOV #bCoeff,AC0				; Load AC0 with the addr of the coefficients
	MOV AC0, AR1				; Load AR0 with the val of AC0
	RPT #24					
	MAC *AR2+,*AR1+,AC1 		; Do filter convolution
	SFTL AC1, #-15				; Bit shift to fit Q15
	MOV AC1,T0     				
	RET
	
inputData128	.macro	
	; "Circular" data in Buffer
	MOV #dataIn128,AC0				; Load address of input data into AC0
	ADD *(#i128),AC0				; Add the addr with the value of the data pointer (Point to the oldest data)
	MOV AC0,AR0					; Move the addr to AR0
	MOV T0, *AR0				; Move the value in T0 to the address
	ADD #1,*(#i128)				; Increment the data pointer
	ADD #1,*(#d128)				; Increment the delay pointer
	CMP *(#i128)==#25,TC1			; Check if the data pointer should reset to 0
	CALLCC resetPtri128, TC1
	CMP *(#d128)==#25,TC1			; Check if the delay pointer should reset to 0
	CALLCC resetPtrd128, TC1
	.endm
	
				
_downFunc128
	; Circular Buffer initialize
	inputData128					; Read data in
	CALL _FIR128					
	MOV T0, *(#firOut128)			; Save data in addr of firOut128
	;Sub Spectrum
	MOV #dataIn128, AC0			
	ADD *(#d128), AC0				
	MOV AC0, AR0
	MOV *AR0,AC0
	SUB T0, AC0
	MOV AC0,*(#band128)
	;DownSample
	CMP *(#k128)==#0, TC1
	CALLCC DownOut1, TC1
	ADD #1, *(#k128)
	CMP *(#k128)==#2, TC1
	CALLCC resetk128, TC1
	RET
	
	
	
