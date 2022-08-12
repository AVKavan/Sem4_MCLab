#include<lpc214x.h>

unsigned int x=0;

__irq void Timer0_ISR(void)
{
	x ^=1;
	if(x)
		IOSET1=1<<20;
	else
		IOCLR1=1<<20;
	  T0IR=0x01;
	 VICVectAddr=0x00000000;
}


int main()
{
	IODIR1=0xFFFFFFFF;
	T0MCR=0x00000003;
	T0MR0=0x1000;
	
	VICVectAddr4=(unsigned)Timer0_ISR;
	VICVectCntl4=0x00000024;
	
	VICIntEnable=0x00000010;
	
	T0TCR=1;
	for(;;){}
	}
