

#include "stdio.h"
#include "ezdsp_setup.h"			// System setup and 

#define MONO 			0
#define STEREO 			1
#define RESOLUTION 		16
#define SAMPLINGRATE 	48

uint8 Rcv; // 0x002A49
uint8 Xmit; 

extern int16 FIR(int16 *DataIn, const int16 *b_coeffs, int16 i);
extern int16 ADDNUM(int16 x, int16 y);
void initialize(uint8 audioType, uint8 resolution, uint8 fs);

int16 FIR1Out[45];
int16 AudioIn[23];
int16 COEFF[23] = {14, 52, -53, -267, -23, 738, 557, -1404, 
				   -2277, 2016, 9971, 14118, 9971, 2016, -2277, 
				   -1404, 557, 738, -23, -267, -53, 52, 14};
int16 Band1[23];


void playback(void){
    int16 i1 = 0; 
    int16 k = 0;
    int16 D1 = 11;
    int16 B1 = 1;
    int16 temp = 0;
    
    while(1){
    	while((Rcv & I2S0_IR) == 0); 							// Wait for interrupt pending flag
	    //AudioInVar 	= I2S0_W0_MSW_R;  						// 16 bit left channel received audio data
	    AudioIn[i1] = I2S0_W0_MSW_R; 
	    //temp = AudioIn[i1]; 
	    i1++; if(i1 == 23) i1 = 0;
	    D1++; if(D1 == 23) D1 = 0;
	    FIR1Out[k] = FIR(AudioIn, COEFF, i1); 
	    Band1[B1] = AudioIn[D1] - FIR1Out[k];

	    temp = ADDNUM(Band1[B1],FIR1Out[k]);   

	    while((Xmit & I2S0_IR) == 0);  						// Wait for interrupt pending flag
		k++; if(k == 45) k = 0;
		B1++; if(B1 == 23) B1 = 0;
		I2S0_W0_MSW_W = temp;  						// 16 bit left channel transmit audio data
		

    }

}



int16 AudioIn2[5];
int16 COEFF2[5] = {0, 8123, 16518, 8123, 0};
void playback_test(void){
    int16 AudioOut2;
    int16 i_test = 0; 
    
    while(1){
    	while((Rcv & I2S0_IR) == 0);  							// Wait for interrupt pending flag
	    AudioIn2[i_test] 	= I2S0_W0_MSW_R;  						// 16 bit left channel received audio data
	    i_test++;
	    if(i_test > 4) i_test = 0;
	    //AudioOut2 = FIRNew(AudioIn2, COEFF2, i_test);
	        
	    while((Xmit & I2S0_IR) == 0);  						// Wait for interrupt pending flag
		I2S0_W0_MSW_W = AudioOut2;  						// 16 bit left channel transmit audio data
    }

}



void main(){
	
	initialize(STEREO,RESOLUTION,SAMPLINGRATE); // MONO/STEREO, 16/24-bit, sampling rate (48 kHz or 96 kHz)
	printf("\nPlayback Loop\n");
	playback();
	
	while(1);
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


	        //asm("FIROut: MOV AC1,port(#0x2809)");
