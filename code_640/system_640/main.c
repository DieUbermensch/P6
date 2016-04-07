

#include "stdio.h"
#include "ezdsp_setup.h"

#define XmitL 0x10
#define XmitR 0x20
#define Rcv 0x04 // (0x04 MONO) (0x08 STEREO)
#define Xmit 0x10 // (0x10 MONO) (0x20 STEREO)

int16 FIR_TEST(int16 DataIn){
	static uint8 n = 11;
	static int16 b[11] = {-43,378,976,-1776,-9174,19081,-9174,-7793,976,378,-43};
	static int16 BUF[11] = {0,0,0,0,0,0,0,0,0,0,0};
	long output = 0;
	long REG;
	static int16 test;
	static uint8 i;
	
	BUF[0] = DataIn;
	
	for(i = 0; i <= n-1; i++){
		REG = (long)(b[i])*BUF[i];
		output += REG>>15;
		//output = output>>1;
	}
	
	for(i = n-1; i >= 1; i-- ){
		BUF[i] = BUF[i-1];
	}
	
	test = (int16)(output>>2);
	return test*10;
}

void playback(void){
    int16 AudioInMSB, FilterOut;
    while(1){
    	if((Rcv & I2S0_IR) == Rcv){  // Wait for interrupt pending flag
	        AudioInMSB = I2S0_W0_MSW_R;  // 16 bit left channel received audio data
	        //AudioInLSB = I2S0_W0_LSW_R; // Only when more than 16-bit
	        FilterOut = FIR_TEST(AudioInMSB);
	        
	        while((Xmit & I2S0_IR) == 0);  // Wait for interrupt pending flag
			I2S0_W0_MSW_W = FilterOut;  // 16 bit left channel transmit audio data
	        //I2S0_W0_LSW_W = AudioInLSB; // Only when > 16-bit
    	}
    }

}

void main(){
	printf("\n\nSystem initializing\n");
	system_init();
	printf("\nPlayback Loop\n");
	playback();
	
	while(1);
}














