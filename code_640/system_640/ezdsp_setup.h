// Author: Group 16GR640 Spring 2016

/*------------------------------------------------------------------
TMS320C5515 eZdsp USB Stick Setup and Initialization
------------------------------------------------------------------*/


/*------------------------------------------------------------------
	0.1 Define Variable Types
------------------------------------------------------------------*/
#define uint32  unsigned long
#define uint16  unsigned short
#define uint8   unsigned char
#define int32   long
#define int16   short
#define int8    char

/*------------------------------------------------------------------
	0.1 TMS320C5515 Setup
------------------------------------------------------------------*/
#define SYS_EXBUSSEL       *(volatile ioport uint16*)(0x1c00)
#define SYS_PCGCR1         *(volatile ioport uint16*)(0x1c02)
#define SYS_PCGCR2         *(volatile ioport uint16*)(0x1c03)
#define SYS_PRCNTR         *(volatile ioport uint16*)(0x1c04)
#define SYS_PRCNTRLR       *(volatile ioport uint16*)(0x1c05)
#define SYS_GPIO_DIR0      *(volatile ioport uint16*)(0x1c06)
#define SYS_GPIO_DIR1      *(volatile ioport uint16*)(0x1c07)
#define SYS_GPIO_DATAIN0   *(volatile ioport uint16*)(0x1c08)
#define SYS_GPIO_DATAIN1   *(volatile ioport uint16*)(0x1c09)
#define SYS_GPIO_DATAOUT0  *(volatile ioport uint16*)(0x1c0a)
#define SYS_GPIO_DATAOUT1  *(volatile ioport uint16*)(0x1c0b)
#define SYS_OUTDRSTR       *(volatile ioport uint16*)(0x1c16)
#define SYS_SPPDIR         *(volatile ioport uint16*)(0x1c17)

/*------------------------------------------------------------------
	1.1 I2C TMS320C5515 Setup (Interface to TLV320AIC3204)
------------------------------------------------------------------*/
#define I2C_IER    	       *(volatile ioport uint16*)(0x1A04)
#define I2C_STR    	       *(volatile ioport uint16*)(0x1A08)
#define I2C_CLKL           *(volatile ioport uint16*)(0x1A0C)
#define I2C_CLKH           *(volatile ioport uint16*)(0x1A10)
#define I2C_CNT    		   *(volatile ioport uint16*)(0x1A14)
#define I2C_DRR    		   *(volatile ioport uint16*)(0x1A18)
#define I2C_SAR    	       *(volatile ioport uint16*)(0x1A1C)
#define I2C_DXR    	       *(volatile ioport uint16*)(0x1A20)
#define I2C_MDR            *(volatile ioport uint16*)(0x1A24)
#define I2C_EDR    	       *(volatile ioport uint16*)(0x1A2C)
#define I2C_PSC    	       *(volatile ioport uint16*)(0x1A30)

#define MDR_STT				0x2000
#define MDR_TRX				0x0200
#define MDR_MST				0x0400
#define MDR_IRS				0x0020
#define MDR_FREE			0x4000
#define STR_XRDY			0x0010
#define STR_RRDY			0x0008
#define MDR_STP 			0x0800

/*------------------------------------------------------------------
	2.1 GPIO TMS320C5515 Setup 
------------------------------------------------------------------*/
#define GPIO_IN                 0
#define GPIO_OUT                1

#define GPIO0                   0x00
#define GPIO1                   0x01
#define GPIO2                   0x02
#define GPIO3                   0x03
#define GPIO4                   0x04
#define GPIO5                   0x05
#define GPIO6                   0x06
#define GPIO7                   0x07
#define GPIO8                   0x08
#define GPIO9                   0x09

#define GPIO10                  0x0A
#define GPIO11                  0x0B
#define GPIO12                  0x0C
#define GPIO13                  0x0D
#define GPIO14                  0x0E
#define GPIO15                  0x0F
#define GPIO16                  0x10
#define GPIO17                  0x11
#define GPIO18                  0x12
#define GPIO19                  0x13

#define GPIO20                  0x14
#define GPIO21                  0x15
#define GPIO22                  0x16
#define GPIO23                  0x17
#define GPIO24                  0x18
#define GPIO25                  0x19
#define GPIO26                  0x1A
#define GPIO27                  0x1B
#define GPIO28                  0x1C
#define GPIO29                  0x1D

#define GPIO30                  0x1E
#define GPIO31                  0x1F

/*------------------------------------------------------------------
	2.1 I2S	TMS320C5515 Setup
------------------------------------------------------------------*/

#define I2S0_CTRL          *(volatile ioport uint16*)(0x2800)
#define I2S0_SRATE         *(volatile ioport uint16*)(0x2804)
#define I2S0_W0_LSW_W      *(volatile ioport uint16*)(0x2808)
#define I2S0_W0_MSW_W      *(volatile ioport uint16*)(0x2809)
#define I2S0_W1_LSW_W      *(volatile ioport uint16*)(0x280C)
#define I2S0_W1_MSW_W      *(volatile ioport uint16*)(0x280D)
#define I2S0_IR            *(volatile ioport uint16*)(0x2810)
#define I2S0_INTMASK       *(volatile ioport uint16*)(0x2814)
#define I2S0_W0_LSW_R      *(volatile ioport uint16*)(0x2828)
#define I2S0_W0_MSW_R      *(volatile ioport uint16*)(0x2829)
#define I2S0_W1_LSW_R      *(volatile ioport uint16*)(0x282C)
#define I2S0_W1_MSW_R      *(volatile ioport uint16*)(0x282D)

/*------------------------------------------------------------------
	2.1 TLV320AIC3204 Register Setup
------------------------------------------------------------------*/
#define AIC3204_I2C_ADDR 0x18


void wait(uint32 delay);
void waitusec(uint32 usec);
void system_init(uint8 audioType, uint8 resolution, uint8 fs);

int16 I2C_init();
int16 I2C_close();
int16 I2C_reset();
int16 I2C_write(uint16 i2c_addr, uint8* data, uint16 len);
int16 I2C_read(uint16 i2c_addr, uint8* data, uint16 len);

int16 GPIO_init();
int16 GPIO_setDirection(uint16 number, uint16 direction);
int16 GPIO_setOutput(uint16 number, uint16 output);
int16 GPIO_getInput(uint16 number);

void I2S_init(uint8 Type);
void TLV320AIC3204_set(uint16 regnum, uint16 regval);
void TLV320AIC3204_init(uint8 BCLK, uint8 PLLJ, uint16 HI_BYTE, uint16 LO_BYTE);




/* I2S Technical Documentation
	I2S0 Interrupt Mask Register
		Acronym				I2S0INTMASK 
		Bit number		[	15-6	| 	5	| 	4	| 	3	| 	2	| 	1	| 	0	]
		Data Size		[	10-bit	| 1-bit	| 1-bit	| 1-bit	| 1-bit	| 1-bit	| 1-bit	]
		Address			[	0x2814													]	
		Content			[	Reserved| XMITST|XMITMON| RCVST | RCVMON| FERR	| OUERR ]	
		COMMENTS
			XMITST: 	Enable stereo left/right transmit data interrupt. Used only when the MONO bit 12 in the I2SSCTRL is 0 (stereo mode). 
				0 = disable, 
				1 = enable
			XMITMON: 	Enable mono left transmit data interrupt. Used only when the MONO bit 12 in the I2SSCTRL is 1 (mono mode). 
				0 = disable 
				1 = enable
			RCVST:		Enable stereo left/right receive data interrupt. Used only when the MONO bit 12 in the I2SSCTRL register = 0 (Stereo mode). 
				0 = disable 
				1 = enable
			RCVMON:		Enable mono left receive data interrupt. Used only when the MONO bit 12 in the I2SSCTRL register = 1 (Mono mode).
				0 = disable 
				1 = enable
			FERR:		Enable frame sync error.
				0 = disable 
				1 = enable
			OUERR:		Enable overrun or underrun condition.
				0 = disable 
				1 = enable
			
		DEFAULT SETTING (0x3f)
		Content			[	0	0	| 	1	| 	1	| 	1	| 	1	| 	1	| 	1	]
		
		16gr640 SETTING (Mono mode interrupt)(0x17)
		Content			[	0	0	| 	0	| 	1	| 	0	| 	1	| 	1	| 	1	]
	-----------------------------------------------------------------------------------------------------------------
	I2S0 Serializer Control Register
		Acronym				I2S0CTRL 
		Bit number		[	15		| 14-13		| 	12		| 	11		| 	10		| 	9		| 	8		|	7		|	6		|	5-2		|	1		|	0		]
		Data Size		[	1-bit	| 2-bit		| 1-bit		| 1-bit		| 1-bit		| 1-bit		| 1-bit		| 1-bit		| 1-bit		| 3-bit		| 1-bit		| 1-bit		]
		Address			[	0x2800																																		]	
		Content			[	ENABLE	| RESERVED	|	MONO	| LOOPBACK 	| FSPOL		| CLKPOL	| DATADLY	|	PACK	| SIGN_EXT 	| WDLNGTH	| MODE		| FRMT		]	
		COMMENTS
			ENABLE: 	Resets or enables the serializer transmission or reception. (1 = Enable I2S)
			MONO: 		Sets I2S into mono or Stereo mode. 0 = Stereo mode, 1 = Mono mode. Valid only when bit 0, FRMT=1 (DSP Format)
			LOOPBACK:	Routes data from transmit shift register back to receive shift register for internal digital loopback. 0 = Normal operation, no loopback.
			FSPOL:		Inverts I2S frame-synchronization polarity. See documentation for more explaination
			CLKPOL:		Controls I2S clock polarity. See documentation for more explaination
			DATADLY:	Sets the I2S receive/transmit data delay. 
				0 = 1-bit data delay, 
				1 = 2-bit -||-
			PACK:		Enable data packing. Divides down the generation of interrupts so that data is packed into the 32-bit receive/transmit word registers for each channel (left/right). 
				0 = Data packing mode disabled.
			SIGN_EXT:	Enable sign extension of words. 
				0 = No sign ext, 
				1 =  Received data is sign extended. Transmit data is expected to be sign extended.
			WDLNGTH:	Choose serializer word length.
				0 = 8-bit data word.
				1h = 10-bit data word.
				2h = 12-bit data word.
				3h = 14-bit data word.
				4h = 16-bit data word.
				5h = 18-bit data word.
				6h = 20-bit data word.
				7h = 24-bit data word.
				8h = 32-bit data word.
				9 to Fh = Reserved.
			MODE:		Sets the serializer in master or slave mode.  
				0 = Serializer is configured as a slave. I2Sn_CLK and I2Sn_FS pins are configured as inputs.
				1 = Serializer is configured as a master. I2Sn_CLK and I2Sn_FS pins are configured as outputs.
			FRMT:		Sets the serializer data format.
				0 = I2S/left-justified format.
				1 = DSP format
			
		DEFAULT SETTING (16-bit, stereo, slave, enable I2S) (0x8010)
		Content			[	0b1		| 	0b00	|	0b0		| 0b0	 	| 0b0		| 0b0		| 0b0		|	0b0		| 0b0	 	| 0x4		| 0b0		| 0b0		]
		
		16gr640 SETTING (24-bit, mono, slave, enable I2S) (0x901C)
		Content			[	0b1		| 	0b00	|	0b1		| 0b0	 	| 0b0		| 0b0		| 0b0		|	0b0		| 0b0	 	| 0x7		| 0b0		| 0b0		]
		
		NOTE: DMA0 -> I2S0
	-----------------------------------------------------------------------------------------------------------------		
	I2S0 Sample Rate Generator Register
		Acronym				I2S0SRATE 		
		Data Size		[	10-bit			|	3-bit			|	3-bit 		]
		Address			[	0x2804												]
		Content			[	Reserved		|	FSDIV			|	CLKDIV		]
		
		COMMENTS		
			CLKDIV: Systen clock division. Generates a clock signal by division of the system clock
			0x0 = Divide by 8
			0x1 = Divide by 16
			0x2 = Divide by 32
			0x3 = Divide by 64
			0x4 = Divide by 128
			0x5 = Divide by 256
			0x6 = Reserved
			0x7 = Reserved
			
			FSDIV: Clock division of CLKDIV. Generates a clock signal used as the  by division of the system clock
			0x0 = Divide by 8
			0x1 = Divide by 16
			0x2 = Divide by 32
			0x3 = Divide by 64
			0x4 = Divide by 128
			0x5 = Divide by 256
			0x6 = Reserved
			0x7 = Reserved		
		
		IS NOT AFFECTED IF CTRL IS SET 
		DEFAULT SETTING (Disabled, since external clock is used)
		Content			[	0x0000	]
	-----------------------------------------------------------------------------------------------------------------		
	I2S0 Interrupt Flag Register (READ-ONLY)
		Acronym				I2S0INTFL '
		Bit number		[	15-6			| 	5			| 	4			| 	3			| 	2			| 	1			|	0			]		
		Data Size		[	10-bit			|	1-bit 		|	1-bit 		|	1-bit 		|	1-bit 		|	1-bit 		|	1-bit 		]
		Address			[	0x2810																											]
		Content			[	Reserved		|	XMITSTFL	|	XMITMONFL	|	RCVSTFL		|	RCVMONFL	|	FERRFL		|	OUERRFL		]		
	
		COMMENTS
			XMITSTFL:	Stereo data transmit flag. Used only when the MONO bit 12 in the I2SSCTRL register = 0 (Stereo mode)
			XMITMONFL:	Mono data transmit flag. Used only when the MONO bit 12 in the I2SSCTRL register = 1 (Mono mode).
				0 = No pending mono transmit interrupt.
				1 = Mono transmit interrupt pending. Write new data value to Transmit Left Data 0 and 1 registers.
			RCVSTFL:	Stereo data receive flag. Used only when the MONO bit 12 in the I2SSCTRL register = 0 (Stereo mode).
			RCVMONFL:	Mono data receive flag. Used only when the MONO bit 12 in the I2SSCTRL register = 1 (Mono mode).
				0 = No pending mono receive interrupt.
				1 = Mono receive interrupt pending. Read Receive Left data 0 and 1 registers
			FERRFL:		Frame-synchronization error flag.
				0 = No frame-synchronization errors.
				1 = Frame-synchronization error(s) occurred.
			OUERRFL:	Overrun or Underrun condition
				0 = No overrun/under-run errors.
				1 = The data registers were not read from or written to before the receive/transmit buffer was overwritten.
				
		DEFAULT SETTING RECEIVE (Stereo interrupt flag) (0x0008)
		Content			[	Reserved		|		-		|		-		|	CHECK		|		-		|		-		|		-		]
		DEFAULT SETTING TRANSMIT (Stereo interrupt flag) (0x0020)
		Content			[	Reserved		|	CHECK		|		-		|		-		|		-		|		-		|		-		]
		
		16gr640 SETTING RECEIVE (Mono interrupt flag) (0x0004)
		Content			[	Reserved		|		-		|		-		|		-		|	CHECK		|		-		|		-		]
		16gr640 SETTING TRANSMIT (Mono interrupt flag) (0x0010)
		Content			[	Reserved		|		-		|	CHECK		|		-		|		-		|		-		|		-		]		
	-----------------------------------------------------------------------------------------------------------------
	
*/












