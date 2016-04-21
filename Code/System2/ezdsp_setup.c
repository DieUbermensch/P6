// Author: Group 16GR640 Spring 2016

/*------------------------------------------------------------------
TMS320C5515 eZdsp USB Stick Setup and Initialization
------------------------------------------------------------------*/

/*	TABLE OF CONTENT
		0.1 TMS320C5515 Setup .............................. 
		1.1 I2C TMS320C5515 Setup .......................... 
		2.1 GPIO TMS320C5515 Setup ......................... 
		
		
*/

#include "ezdsp_setup.h"
#include "stdio.h"



/*-------------------------- PAGE 0 ------------------------------*/

/*------------------------------------------------------------------
	0.1 TMS320C5515 Setup
------------------------------------------------------------------*/

void wait(uint32 delay){
    volatile uint32 i;
    for ( i = 0 ; i < delay ; i++ ){ };
}

void waitusec(uint32 usec){
    wait((uint32)usec * 8);
}

void system_init(uint8 audioType, uint8 resolution, uint8 fs){
    SYS_PCGCR1 	 = 0x0000;     		/* Enable clocks to all peripherals */
    SYS_PCGCR2 	 = 0x0000;
	SYS_EXBUSSEL = 0x6100;         	// Enable I2S bus
	I2C_init();        				// Initialize I2C
	
	if 		(fs == 48 && resolution == 16) TLV320AIC3204_init(0x0d, 0x07, 0x06, 0x90);
	else if (fs == 48 && resolution == 24) TLV320AIC3204_init(0x2d, 0x07, 0x06, 0x90);	
	else if (fs == 96 && resolution == 16) TLV320AIC3204_init(0x0d, 0x0E, 0x0D, 0x20);	
	else if	(fs == 96 && resolution == 24) TLV320AIC3204_init(0x2d, 0x0E, 0x0D, 0x20);
	else TLV320AIC3204_init(0x0d, 0x07, 0x06, 0x90);	
	
	wait(200);        				// Wait	
	if 		(audioType == 0 && resolution == 16) I2S_init(0x9010);
	else if (audioType == 0 && resolution == 24) I2S_init(0x901C);	
	else if (audioType == 1 && resolution == 16) I2S_init(0x8010);	
	else if	(audioType == 1 && resolution == 24) I2S_init(0x801C);
	else I2S_init(0x9010);
	
}






/*------------------------------------------------------------------
	1.1 I2C TMS320C5515 Setup (Interface to TLV320AIC3204)
------------------------------------------------------------------*/

int32 i2c_timeout = 0x0fff;

int16 I2C_init(void){
    I2C_MDR 	= 0x0400;             	// Reset I2C
    I2C_PSC   	= 15;               	// Config prescaler for 100MHz
    I2C_CLKL  	= 25;               	// Config clk LOW for 100kHz
    I2C_CLKH  	= 25;               	// Config clk HIGH for 100kHz
    I2C_MDR   	= 0x0420;	        	// Release from reset; Master, Transmitter, 7-bit address
    return 0;
}

int16 I2C_close(){
    I2C_MDR 	= 0;                    // Reset I2C
    return 0;
}

int16 I2C_reset(){
    I2C_close();
    I2C_init();
    return 0;
}

int16 I2C_write( uint16 i2c_addr, uint8* data, uint16 len ){
    int16 timeout, i;
	I2C_CNT 	= len;                  	// Set length
	I2C_SAR 	= i2c_addr;             	// Set I2C slave address
	I2C_MDR 	= MDR_STT | MDR_TRX | MDR_MST | MDR_IRS | MDR_FREE;              // Set for Master Write
	wait(100);              		// Short delay
	for( i = 0 ; i < len ; i++ ){
		I2C_DXR = data[i];            		// Write
		timeout = 0x510;             		// I2C_timeout = 1ms;
		GPIO_setOutput( 17, 1);
		do{
			if( timeout-- < 0  ){
				GPIO_setOutput( 17, 0);
				I2C_reset( );
				return -1;
			}
		} while( (I2C_STR & STR_XRDY) == 0 );// Wait for Tx Ready
	}
	I2C_MDR |= MDR_STP;             		// Generate STOP
	waitusec(1000);
	return 0;
}

int16 I2C_read( uint16 i2c_addr, uint8* data, uint16 len ){
    int32 timeout, i;
    I2C_CNT = len;                    // Set length
    I2C_SAR = i2c_addr;               // Set I2C slave address
    I2C_MDR = MDR_STT | MDR_MST | MDR_IRS | MDR_FREE;             // Set for Master Read
    wait( 10 );            // Short delay
    for ( i = 0 ; i < len ; i++ ){
        timeout = i2c_timeout;
        //Wait for Rx Ready 
        do{
            if ( timeout-- < 0 ){
                I2C_reset( );
                return -1;
            }
        } while ( (I2C_STR & STR_RRDY) == 0 );// Wait for Rx Ready
        data[i] = I2C_DRR;            // Read
    }
    I2C_MDR |= MDR_STP;               // Generate STOP
	waitusec(10);
    return 0;
}








/*------------------------------------------------------------------
	2.1 GPIO TMS320C5515 Setup 
------------------------------------------------------------------*/

int16 GPIO_init(){
    return 0;
}

int16 GPIO_setDirection(uint16 number, uint16 direction){
    uint32 bank_id = ( number >> 4);
    uint32 pin_id  = ( 1 << ( number & 0xF ) );
    if (bank_id == 0)
        if ((direction & 1) == GPIO_IN)
    	    SYS_GPIO_DIR0 &= ~pin_id;
        else
            SYS_GPIO_DIR0 |= pin_id;

    if (bank_id == 1)
        if ((direction & 1) == GPIO_IN)
    	    SYS_GPIO_DIR1 &= ~pin_id;
        else
            SYS_GPIO_DIR1 |= pin_id;

    return 0;
}

int16 GPIO_setOutput( uint16 number, uint16 output ){
    uint32 bank_id = ( number >> 4 );
    uint32 pin_id  = ( 1 << ( number & 0xF ) );
    if (bank_id == 0)
        if ((output & 1) == 0)
    	    SYS_GPIO_DATAOUT0 &= ~pin_id;
        else
            SYS_GPIO_DATAOUT0 |= pin_id;

    if (bank_id == 1)
        if ((output & 1) == 0)
    	    SYS_GPIO_DATAOUT1 &= ~pin_id;
        else
            SYS_GPIO_DATAOUT1 |= pin_id;
    return 0;
}

int16 GPIO_getInput( uint16 number ){
    uint32 input;
    uint32 bank_id = ( number >> 4 );
    uint32 pin_id  = ( number & 0xF );
    if (bank_id == 0)
        input = (SYS_GPIO_DATAIN0 >> pin_id) & 1;
    if (bank_id == 1)
        input = (SYS_GPIO_DATAIN1 >> pin_id) & 1; 
    return input;
}


/*------------------------------------------------------------------
	2.1 Screen OSD9616 (SSD1306) Setup
------------------------------------------------------------------*/

uint8 endPoint = 0;
uint8 scroll;
short i = 0;

void screen_init()
{
	char mes1[] = "HELLO";
	char mes2[] = "POUL";
	uint8 cmd[10];    // For multibyte commands
    
    I2C_init( );
    
    /* Initialize LCD power */
    GPIO_setDirection( 12, 1 );  // Output
    GPIO_setOutput( 12, 1 );     // Enable 13V 
    
    /* Initialize OSD9616 display */
    OSD9616_send(0x00,0x00); // Set low column address
    OSD9616_send(0x00,0x10); // Set high column address
    OSD9616_send(0x00,0x40); // Set start line address

    cmd[0] = 0x00 & 0x00FF;  // Set contrast control register
    cmd[1] = 0x81;
    cmd[2] = 0xFF;						// CONTRAST! 0x00 to 0xFF
    I2C_write( OSD9616_I2C_ADDR, cmd, 3 );

    OSD9616_send(0x00,0xa1); // Set segment re-map 95 to 0 (0xA1 95 to 0, 0xA0 0 to 95)
    OSD9616_send(0x00,0xa6); 			// Set normal display (0xA6 is normal, 0xA7 is awesomely reversed)
	
    cmd[0] = 0x00 & 0x00FF;  // Set multiplex ratio(1 to 16)
    cmd[1] = 0xa8; 
    cmd[2] = 0x0F;			// Multiplex rate (0x0F slowest, 0x3F fastest)
    I2C_write( OSD9616_I2C_ADDR, cmd, 3 );

    OSD9616_send(0x00,0xd3); // Set display offset
    OSD9616_send(0x00,0x00); // Not offset
    OSD9616_send(0x00,0xd5); // Set display clock divide ratio/oscillator frequency
    OSD9616_send(0x00,0xf0); // Set divide ratio

    cmd[0] = 0x00 & 0x00FF;  // Set pre-charge period
    cmd[1] = 0xd9;
    cmd[2] = 0x22;
    I2C_write( OSD9616_I2C_ADDR, cmd, 3 );

    cmd[0] = 0x00 & 0x00FF;  // Set com pins hardware configuration
    cmd[1] = 0xda;
    cmd[2] = 0x02;
    I2C_write( OSD9616_I2C_ADDR, cmd, 3 );

    OSD9616_send(0x00,0xdb); // Set vcomh
    OSD9616_send(0x00,0x49); // 0.83*vref
    
    cmd[0] = 0x00 & 0x00FF;  //--set DC-DC enable
    cmd[1] = 0x8d;
    cmd[2] = 0x14;
    I2C_write( OSD9616_I2C_ADDR, cmd, 3 );

    OSD9616_send(0x00,0xAF); // Turn on oled panel    
        /* Set vertical and horizontal scrolling */
    OSD9616_send(0x00,0x2E); 		 // Activate scroll (0x2F), deactivate scroll (0x2E)
    
    
    cmd[0] = 0x00;
    cmd[1] = 0x29;  // Vertical and Right Horizontal Scroll
    cmd[2] = 0x00;  // Dummy byte
    cmd[3] = 0x00;  // Define start page address
    cmd[4] = 0x01;  // Set time interval between each scroll step
    cmd[5] = 0x01;  // Define end page address
    cmd[6] = 0x00;  // Vertical scrolling offset  (off 0x00, on 0x01)
    OSD9616_multiSend( cmd, 7 );
    OSD9616_send(0x00,scroll); 		 // Activate scroll (0x2F), deactivate scroll (0x2E)
    /* Keep first 8 rows from vertical scrolling  */
    cmd[0] = 0x00;
    cmd[1] = 0xa3;  // Set Vertical Scroll Area
    cmd[2] = 0x08;  // Set No. of rows in top fixed area
    cmd[3] = 0x08;  // Set No. of rows in scroll area
    OSD9616_multiSend( cmd, 4 );
    message1(mes1);
    message2(mes2);
}

void message1(char *mes){
	    /* Write to page 0 */
    OSD9616_send(0x00,0x00);   // Set low column address
    OSD9616_send(0x00,0x10);   // Set high column address
    OSD9616_send(0x00,0xb0+0); // Set page for page 0 to page 5
    for(i=0;i<128;i++)
    {
    	OSD9616_send(0x40,0x00);  // Spaces (Clear Screen)
    }
    printChar(mes);
}

void message2(char *mes){
	    /* Write to page 0 */
    OSD9616_send(0x00,0x00);   // Set low column address
    OSD9616_send(0x00,0x10);   // Set high column address
    OSD9616_send(0x00,0xb0+1); // Set page for page 0 to page 5
    for(i=0;i<128;i++)
    {
    	OSD9616_send(0x40,0x00);  // Spaces (Clear Screen)
    }
    printChar(mes);
}

void printChar(char *mes){
	for(i=0; *(mes+i)!=NULL; i++) endPoint = i;	// Find the last element in string
	scroll = (endPoint>17) ? 0x2F : 0x2E; 		// if more than 17 characters enable scrolling
	for(i=endPoint; i>=0; i--){					// Write all characters in string
		switch(mes[i]){
			case 'A': PRINT_A; break;
			case 'B': PRINT_B; break;
			case 'C': PRINT_C; break;
			case 'D': PRINT_D; break;
			case 'E': PRINT_E; break;
			case 'F': PRINT_F; break;
			case 'G': PRINT_G; break;
			case 'H': PRINT_H; break;
			case 'I': PRINT_I; break;
			case 'J': PRINT_J; break;
			case 'K': PRINT_K; break;
			case 'L': PRINT_L; break;
			case 'M': PRINT_M; break;
			case 'N': PRINT_N; break;
			case 'O': PRINT_O; break;
			case 'P': PRINT_P; break;
			case 'Q': PRINT_Q; break;
			case 'R': PRINT_R; break;
			case 'S': PRINT_S; break;
			case 'T': PRINT_T; break;
			case 'U': PRINT_U; break;
			case 'V': PRINT_V; break;
			case 'W': PRINT_W; break;
			case 'X': PRINT_X; break;
			case 'Y': PRINT_Y; break;
			case 'Z': PRINT_Z; break;
			case '1': PRINT_1; break;
			case '2': PRINT_2; break;
			case '3': PRINT_3; break;
			case '4': PRINT_4; break;
			case '5': PRINT_5; break;
			case '6': PRINT_6; break;
			case '7': PRINT_7; break;
			case '8': PRINT_8; break;
			case '9': PRINT_9; break;	
			case '0': PRINT_0; break;
			case '!': PRINT_MARK; break;
			case '?': PRINT_QUESTION; break;	
			case ' ': PRINT_SPACE; break;
			default: PRINT_QUESTION; break;		
		}		
	}
}

void printLetter(uint16 l1,uint16 l2,uint16 l3,uint16 l4){
	OSD9616_send(0x40,l1);
    OSD9616_send(0x40,l2);
    OSD9616_send(0x40,l3);
    OSD9616_send(0x40,l4);
    OSD9616_send(0x40,0x00);
}

void OSD9616_send(uint16 comdat,uint16 data ){
    uint8 cmd[2];
    cmd[0] = comdat & 0x00FF;     // Specifies whether data is Command or Data
    cmd[1] = data;                // Command / Data
    I2C_write( OSD9616_I2C_ADDR, cmd, 2 );
}

void OSD9616_multiSend(uint8* data, uint16 len ){
    uint16 x;
    uint8 cmd[10];
    for(x=0;x<len;x++)               // Command / Data
    {
    	cmd[x] = data[x];
    }
    I2C_write( OSD9616_I2C_ADDR, cmd, len );
}

/*------------------------------------------------------------------
	2.1 I2S	TMS320C5515 Setup
------------------------------------------------------------------*/

void I2S_init(uint8 Type){
	I2S0_SRATE 		= 0x0;
    I2S0_CTRL 		= Type;    	// 16-bit word, slave, enable I2S (0x8010), stereo. 24-bit word, slave, enable I2S, mono (0x901C). 
    I2S0_INTMASK 	= 0x3F;    		// Enable interrupts (Stereo 0x2B, Mono 0x17)
}

/*------------------------------------------------------------------
	2.1 TLV320AIC3204 Register Setup
------------------------------------------------------------------*/

void TLV320AIC3204_set(uint16 regnum, uint16 regval){
	uint8 cmd[2];
    cmd[0] = regnum & 0x007F;       // 7-bit Register Address
    cmd[1] = regval;                // 8-bit Register Data
	I2C_write(AIC3204_I2C_ADDR, cmd, 2);
}

void TLV320AIC3204_init(uint8 BCLK, uint8 PLLJ, uint16 HI_BYTE, uint16 LO_BYTE){
    /* Configure AIC3204 */
    TLV320AIC3204_set( 0, 0 );          // Select page 0
    TLV320AIC3204_set( 1, 1 );          // Reset codec
    TLV320AIC3204_set( 0, 1 );          // Select page 1
    TLV320AIC3204_set( 1, 8 );          // Disable crude AVDD generation from DVDD
    TLV320AIC3204_set( 2, 1 );          // Enable Analog Blocks, use LDO power
    TLV320AIC3204_set( 0, 0 );          // Select page 0
	
	
    /* PLL and Clocks config and Power Up  */
    TLV320AIC3204_set( 27, BCLK );      // BCLK and WCLK is set as o/p to AIC3204(Master) (0x2D for 24-bit)
    TLV320AIC3204_set( 28, 0x00 );      // Data ofset = 0
    TLV320AIC3204_set( 4, 3 );          // PLL setting: PLLCLK <- MCLK, CODEC_CLKIN <-PLL CLK
    TLV320AIC3204_set( 6, PLLJ );       // PLL setting: J=7	(J=14 for 96 kHz)
    TLV320AIC3204_set( 7, HI_BYTE );    // PLL setting: HI_BYTE(D=1680)(0x06) (D=3360 for 96 kHz)(0x0D)
    TLV320AIC3204_set( 8, LO_BYTE );    // PLL setting: LO_BYTE(D=1680)(0X90) (D=3360 for 96 kHz)(0x20)
    TLV320AIC3204_set( 30, 0x88 );      // For 32 bit clocks per frame in Master mode ONLY
                                   		// BCLK=DAC_CLK/N =(12288000/8) = 1.536MHz = 32*fs (0X88)(Power up and divide by 8) (12288000/4 when 96 kHz, data=0x84)
    TLV320AIC3204_set( 5, 0x91 );       // PLL setting: Power up PLL, P=1 and R=1
    TLV320AIC3204_set( 13, 0 );         // Hi_Byte(DOSR) for DOSR = 128 decimal or 0x0080 DAC oversamppling
    TLV320AIC3204_set( 14, 0x80 );      // Lo_Byte(DOSR) for DOSR = 128 decimal or 0x0080
    TLV320AIC3204_set( 20, 0x80 );      // AOSR for AOSR = 128 decimal or 0x0080 for decimation filters 1 to 6
    TLV320AIC3204_set( 11, 0x82 );      // Power up NDAC and set NDAC value to 2
    TLV320AIC3204_set( 12, 0x87 );      // Power up MDAC and set MDAC value to 7
    TLV320AIC3204_set( 18, 0x87 );      // Power up NADC and set NADC value to 7
    TLV320AIC3204_set( 19, 0x82 );      // Power up MADC and set MADC value to 2
	
	
    /* DAC ROUTING and Power Up */
    TLV320AIC3204_set(  0, 0x01 );      // Select page 1
    TLV320AIC3204_set( 12, 0x08 );      // LDAC AFIR routed to HPL (Headphone driver Left)
    TLV320AIC3204_set( 13, 0x08 );      // RDAC AFIR routed to HPR (Headphone driver Right)
    TLV320AIC3204_set(  0, 0x00 );      // Select page 0
    TLV320AIC3204_set( 64, 0x02 );      // Left vol=right vol.  Left Channel Volume is controlled by Right Channel Volume Control setting
    TLV320AIC3204_set( 65, 0x00 );      // Left DAC gain to 0dB VOL; Right tracks Left
    TLV320AIC3204_set( 63, 0xd4 );      // Power up left,right data paths and set channel
    TLV320AIC3204_set(  0, 0x01 );      // Select page 1
    TLV320AIC3204_set( 16, 0x00 );      // Unmute HPL , 0dB gain (0x40 to mute)
    TLV320AIC3204_set( 17, 0x00 );      // Unmute HPR , 0dB gain (0x40 to mute)
    TLV320AIC3204_set(  9, 0x30 );      // Power up HPL,HPR
    TLV320AIC3204_set(  0, 0x00 );      // Select page 0
    wait( 500 );        // Wait
    
	
    /* ADC ROUTING and Power Up */
    TLV320AIC3204_set( 0, 1 );          // Select page 1
    TLV320AIC3204_set( 0x34, 0x30 );    // STEREO 1 Jack	(dec: 52 )
		                           		// IN2_L to LADC_P through 40 kohm
    TLV320AIC3204_set( 0x37, 0x30 );    // IN2_R to RADC_P through 40 kohmm
    TLV320AIC3204_set( 0x36, 3 );       // CM_1 (common mode) to LADC_M through 40 kohm
    TLV320AIC3204_set( 0x39, 0xc0 );    // CM_1 (common mode) to RADC_M through 40 kohm
    TLV320AIC3204_set( 0x3b, 0 );       // MIC_PGA_L unmute
    TLV320AIC3204_set( 0x3c, 0 );       // MIC_PGA_R unmute
    TLV320AIC3204_set( 0, 0 );          // Select page 0
    TLV320AIC3204_set( 0x51, 0xc0 );    // Powerup Left and Right ADC
    TLV320AIC3204_set( 0x52, 0x00 );       // Unmute Left and Right ADC

    TLV320AIC3204_set( 0, 0 );    
}









