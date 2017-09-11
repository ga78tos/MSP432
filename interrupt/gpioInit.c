#include <driverlib.h>

void Port1_ISR(void)
{
	switch(P1IV)
	{
		case P1IV__NONE:   break;
		case P1IV__P1IFG0:                                       // Pin 0
					__no_operation();
					break;
		case P1IV__P1IFG1:                                       // Pin 0
			P2OUT ^= 0x04;
					break;
		case P1IV__P1IFG2:                                       // Pin 0
					__no_operation();
					break;
		case P1IV__P1IFG3:                                       // Pin 0
					__no_operation();
					break;
		case P1IV__P1IFG4:                                       // Pin 0
			P1OUT ^= 0x01;
					break;
		case P1IV__P1IFG5:                                       // Pin 0
					__no_operation();
					break;
		case P1IV__P1IFG6:                                       // Pin 0
					__no_operation();
					break;
		case P1IV__P1IFG7:                                       // Pin 0
					__no_operation();
					break;
		default: break;
	}
}
