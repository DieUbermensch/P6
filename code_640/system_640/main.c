

#include "stdio.h"
#include "ezdsp_setup.h"

#define MONO 			0
#define STEREO 			1
#define RESOLUTION 		16
#define SAMPLINGRATE 	48

uint8 Rcv; // (0x04 MONO) (0x08 STEREO)
uint8 Xmit; // (0x10 MONO) (0x20 STEREO)

const uint8 Q_Format 	= 15;
const uint8 n 			= 21;
const int16 b[21] 		= {85,234,465,782,1173,1615,2070,2492,2837,3062,3140,3062,2837,2492,2070,1615,1173,782,465,234,85};

int16 FIR_TEST(int16 DataIn, const int16 *b_coeffs, const uint8 *N){
	static 	int16 BUF[21];
	static 	uint8 i;
	int16 	output 		= 0;
	BUF[0] 				= DataIn;
	
	for(i = 0; i <= n-1; i++){
		output += ((long)(*(b_coeffs+i))*BUF[i])>>Q_Format;
	}
	for(i = n-1; i >= 1; i-- ){
		BUF[i] = BUF[i-1];
	}
	return (int16)(output);
}

void playback(void){
    int16 AudioInMSB, FilterOut;
    while(1){
    	if((Rcv & I2S0_IR) == Rcv){  					// Wait for interrupt pending flag
	        AudioInMSB 	= I2S0_W0_MSW_R;  				// 16 bit left channel received audio data
	        FilterOut 	= FIR_TEST(AudioInMSB,b,&n);
	        
	        while((Xmit & I2S0_IR) == 0);  				// Wait for interrupt pending flag
			I2S0_W0_MSW_W = FilterOut;  				// 16 bit left channel transmit audio data
	        I2S0_W1_MSW_W = AudioInMSB; 				// Only when > 16-bit
    	}
    }

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

void main(){
	initialize(STEREO,RESOLUTION,SAMPLINGRATE); // MONO/STEREO, 16/24-bit, sampling rate (48 kHz or 96 kHz) 
	printf("\nPlayback Loop\n");
	playback();
	
	while(1);
}













