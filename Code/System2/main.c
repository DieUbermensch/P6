

#include "stdio.h"
#include "ezdsp_setup.h"			// System setup and 

#define MONO 			0
#define STEREO 			1
#define RESOLUTION 		16
#define SAMPLINGRATE 	48
#define startAddr		0x001860
int16 array[10000];


uint8 Rcv; // 0x002A49
uint8 Xmit; 

extern int16 FIR(int16 *DataIn, const int16 *b_coeffs, int16 i);
extern void downFunc(int16 dataIn, int16 bandNum);
extern void initArray(void);
void initialize(uint8 audioType, uint8 resolution, uint8 fs);

int16 COEFF[23] = {14, 52, -53, -267, -23, 738, 557, -1404, 
				   -2277, 2016, 9971, 14118, 9971, 2016, -2277, 
				   -1404, 557, 738, -23, -267, -53, 52, 14};

void playback(void){
    int16 audioIn = 0;
    int16 band1 = 0; 
    int16 down1 = 0; 
    unsigned long DownOut1 = 0;
    while(1){
    	while((Rcv & I2S0_IR) == 0); 							// Wait for interrupt pending flag
	    audioIn = I2S0_W0_MSW_R;
	    downFunc(audioIn,0); 
		band1 = array[184];
		down1 = array[185];
	    while((Xmit & I2S0_IR) == 0);  						// Wait for interrupt pending flag
		I2S0_W0_MSW_W = band1;  						// 16 bit left channel transmit audio data
    }
}


void init_array(void){
	int16 cnt;
	// Clear array
	for(cnt=0;cnt<10000;cnt++) array[cnt] = 0;	
	
	//Read coefficients into array
	for(cnt=0;cnt<23;cnt++) array[cnt] = COEFF[cnt];
	
	initArray();
	
}


int16 *test(int16 x){
	int16 y[2];
	y[0] = x + 1;
	y[1] = x + 2;
	return y;
}

void main(){
	int16 *z;
	z = test(1);
	
	
	init_array();
	initialize(STEREO,RESOLUTION,SAMPLINGRATE); // MONO/STEREO, 16/24-bit, sampling rate (48 kHz or 96 kHz)
	playback();
}


void initialize(uint8 audioType, uint8 resolution, uint8 fs){
	printf("\n\nSystem initializing\n");
	switch(audioType){
		case 0:
			Rcv  = 0x04; 				// MONO receive interrupt flag register
			Xmit = 0x10;				// MONO transmit interrupt flag register
			system_init(audioType,resolution,fs); // SETUP - Codec registers and C5515 I2S registers
		case 1:
			Rcv  = 0x08; 				// STEREO receive interrupt flag register
			Xmit = 0x20;				// STEREO transmit interrupt flag register
			system_init(audioType,resolution,fs); // SETUP - Codec registers and C5515 I2S registers
		default:
			Rcv  = 0x04; 				// MONO receive interrupt flag register
			Xmit = 0x10;				// MONO transmit interrupt flag register
			system_init(audioType,resolution,fs); // SETUP - Codec registers and C5515 I2S registers
	}
}

