#include "driverlib.h"
#include "initGpio.h"

int main(void) 
{
	int i;
	i = 0;
    WDT_A_holdTimer();

    __disable_irq();

    init_Gpio();

    NVIC_ClearPendingIRQ(PORT1_IRQn);
    NVIC_EnableIRQ(PORT1_IRQn);

    __enable_irq();

    while(1)
    {
    	P2OUT ^= 0x04;

    	for(i = speed; i > 0; i--);
    }
}
