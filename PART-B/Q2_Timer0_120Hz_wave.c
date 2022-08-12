#include<lpc214x.h>

void wait()
{
	T0TCR=1;
	while(T0TC!=T0MR1);
}



int main()
{
	T0MR1=0xCB71;
	T0MCR=0x30;
	while(1)
	{
		IODIR0=0x1;
		IOSET0=0x1;
		wait();
		IOCLR0=0x1;
		wait();
	}
}
