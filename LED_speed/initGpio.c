#include <driverlib.h>
#include "initGpio.h"

int speed;

void init_Gpio(void)
{
	P2DIR |= 0x04;
	P2OUT |= 0x04;
	//---------------
	P1DIR &= ~0x02;
	P1REN |= 0x02;
	P1OUT |= 0x02;

	P1IES |= 0x02;
	P1IFG &= ~0x02;
	P1IE |= 0x02;
	//----------------
	P1DIR &= ~0x10;
	P1REN |= 0x10;
	P1OUT |= 0x10;

	P1IES |= 0x10;
	P1IFG &= ~0x10;
	P1IE |= 0x10;
}

void port1_ISR(void)
{
	switch(P1IV)
	{
	case P1IV__NONE: break;


	case P1IV__P1IFG0:
		__no_operation();
		break;
	case P1IV__P1IFG1:
		if(speed > 100000)
			speed -= 50000;
		break;
	case P1IV__P1IFG2:
		__no_operation();
		break;
	case P1IV__P1IFG3:
		__no_operation();
		break;
	case P1IV__P1IFG4:
		if(speed < 2000000000)
			speed += 50000;
		break;
	case P1IV__P1IFG5:
		__no_operation();
		break;
	case P1IV__P1IFG6:
		__no_operation();
		break;
	case P1IV__P1IFG7:
		__no_operation();
		break;
	}
}



