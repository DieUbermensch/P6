	.global _FIR, _downFunc, _initArray;
	
startAddr	.set	0x001860
bCoeff		.set	0+startAddr
dataIn		.set	100+startAddr
firOut1		.set	130+startAddr
i1			.set	180+startAddr
k1			.set	181+startAddr
b1			.set	182+startAddr
d1			.set	183+startAddr

band1		.set	184+startAddr
down1		.set	185+startAddr	

_initArray
	MOV #11, *(#d1)
	RET


_FIR	
	MOV #0, AC1
	MOV #23, BK03				; Set buffer size to filter order
	MOV #dataIn,AC0
	MOV AC0,XAR2				; CDP as coefficient pointer
	MOV mmap(AR2),BSA23        	; Set up base address for CDP
	MOV *(#i1),AC0
	MOV AC0,AR2					; Start from the i'th data
	bset AR2LC					; Set pointer as circular
	MOV #bCoeff,AC0
	MOV AC0, AR1
	RPT #22
	MAC *AR2+,*AR1+,AC1 
	SFTL AC1, #-15
	MOV AC1,T0     ; Store the rounded & scaled result
	RET
	
inputData	.macro	
	; "Circular" data in Buffer
	MOV #dataIn,AC0
	ADD *(#i1),AC0				
	MOV AC0,AR0
	MOV T0, *AR0
	ADD #1,*(#i1)
	ADD #1,*(#d1)
	CMP *(#i1)==#23,TC1
	CALLCC resetPtri1, TC1
	CMP *(#d1)==#23,TC1
	CALLCC resetPtrd1, TC1
	.endm
	
resetPtri1:	MOV #0,*(#i1)
			RET	

resetPtrd1:	MOV #0,*(#d1)
			RET	

DownOut: 	MOV T0,*(#down1)
			RET			

resetK1: 	MOV #0,*(#k1)
			RET	
				
_downFunc
	; Circular Buffer initialize
	inputData
	CALL _FIR
	MOV T0, *(#firOut1)
	;Sub Spectrum
	MOV #dataIn, AC0
	ADD *(#d1), AC0
	MOV AC0, AR0
	MOV *AR0,AC0
	SUB T0, AC0
	MOV AC0,*(#band1)
	;DownSample
	CMP *(#k1)==#0, TC1
	CALLCC DownOut, TC1
	ADD #1, *(#k1)
	CMP *(#k1)==#2, TC1
	CALLCC resetK1, TC1
													;MOV #23, BK03				; Set buffer size to filter order
													;::MOV #dataIn,AC0
													;MOV AC0,XAR2				; CDP as coefficient pointer
													;MOV mmap(AR2),BSA23        	; Set up base address for CDP
													;MOV *(#i1),AC0	
													;ADD #1,*(#i1)
													;CMP *(#i1)==#23,TC1
													;CALLCC resetPtr, TC1
													;MOV AC0,AR2					; Start from the i'th data
													;bset AR2LC					; Set pointer as circular	
													;MOV T0, *AR2+
	RET
	
	
	
