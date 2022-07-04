#include<lpc214x.h>

void wait()
{
	T0TCR=0x1;
	while(T0TC!=T0MR0);
}

int main()
{
	IODIR0=0xFFFFFFFF;
	T0MR0=0x1234;
	T0MCR=0x4;
	while(1)
	{
		
		IOSET0=0x1;
		wait();
		IOCLR0=0x1;
		wait();
	}
}
