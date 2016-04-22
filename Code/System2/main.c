

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
//1
extern void downFunc1(int16 dataIn);
extern int16 delayB1(int16 dataIn);
extern void initArray1(void);

//Up1
extern int16 upFunc1(int16 dataIn,int16 band);
//2
extern void downFunc2(int16 dataIn);
extern void initArray2(void);

void initialize(uint8 audioType, uint8 resolution, uint8 fs);

int16 COEFF[23] = {14, 52, -53, -267, -23, 738, 557, -1404, 
				   -2277, 2016, 9971, 14118, 9971, 2016, -2277, 
				   -1404, 557, 738, -23, -267, -53, 52, 14};

void playback(void){
    int16 audioIn = 0;
    
    
    //1
    int16 sum1 = 0;
    int16 band1 = 0; 
    int16 down1 = 0;
    int16 up1	= 0;
    int16 delayVar1 = 0; 
    //2
    int16 band2 = 0; 
    int16 down2 = 0;
    int16 cnt2  = 0; 
    
    //2
    
     
    while(1){
    	while((Rcv & I2S0_IR) == 0); 							// Wait for interrupt pending flag
	    audioIn = I2S0_W0_MSW_R;
	    //down1
	    downFunc1(audioIn); 
		band1 = array[184];
		down1 = array[185];
		delayVar1 = delayB1(band1);
		
		//up1
	    up1 = upFunc1(down1,delayVar1);
		//down2
		if(cnt2 == 0){
			downFunc2(down1); 
			band2 = array[284];
			down2 = array[285];
			cnt2=1;
		}
		else{
			cnt2 = 0;
		}
		
		
	    while((Xmit & I2S0_IR) == 0);  						// Wait for interrupt pending flag
		I2S0_W0_MSW_W = up1;  						// 16 bit left channel transmit audio data
    }
}


void init_array(void){
	int16 cnt;
	int16 cnt2 = 0;
	// Clear array
	for(cnt=0;cnt<10000;cnt++) array[cnt] = 0;	
	
	//Read coefficients into array
	for(cnt=0;cnt<23;cnt++) array[cnt] = COEFF[cnt];
	
	//Read coefficients into array
	for(cnt=30;cnt<42;cnt++){ 
		array[cnt] = COEFF[2*cnt2];
		cnt2++;
	}
	cnt2 = 0;
	for(cnt=60;cnt<71;cnt++){ 
		array[cnt] = COEFF[2*cnt2+1];
		cnt2++;
	}
	initArray1();
	initArray2();
	
}

void main(){	
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

