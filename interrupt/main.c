#include "driverlib.h"

int main(void) 
{
    WDT_A_holdTimer();

    MAP_Interrupt_disableMaster();
    //init gpio

    P1DIR |= 0x01;
    P2DIR |= 0x04;

    /*P1DIR &= ~0x12;
    P1REN |= 0x12; <-- doesn't work!!!!
    P2OUT |= 0x12;*/

    P1OUT &= ~0x01;
    P2OUT &= ~0x04;

    /*MAP_GPIO_interruptEdgeSelect ( GPIO_PORT_P1, GPIO_PIN1, GPIO_LOW_TO_HIGH_TRANSITION );
    MAP_GPIO_clearInterruptFlag ( GPIO_PORT_P1, GPIO_PIN1 );
    MAP_GPIO_enableInterrupt ( GPIO_PORT_P1, GPIO_PIN1 );

    MAP_GPIO_interruptEdgeSelect ( GPIO_PORT_P1, GPIO_PIN4, GPIO_LOW_TO_HIGH_TRANSITION );
    MAP_GPIO_clearInterruptFlag ( GPIO_PORT_P1, GPIO_PIN4 );
    MAP_GPIO_enableInterrupt ( GPIO_PORT_P1, GPIO_PIN4 );*/


    //MAP_GPIO_setOutputLowOnPin( GPIO_PORT_P1, GPIO_PIN0 );
        //MAP_GPIO_setAsOutputPin( GPIO_PORT_P1, GPIO_PIN0 );

        // Set pin P2.0/2.1/2.1 to output direction and turn LED off                // RGB LED (LED2)
        //MAP_GPIO_setOutputLowOnPin( GPIO_PORT_P2, GPIO_PIN2 );
        //MAP_GPIO_setAsOutputPin( GPIO_PORT_P2, GPIO_PIN2 );

        // Set P1.1 as input with pull-up resistor (for push button S1)
        //  First, configure the interrupt to trigger on low-to-high transition
        //  and then clear flag and enable the interrupt
        P1DIR &= ~0x02;
        P1REN |= 0x02;
        P1OUT |= 0x02;//MAP_GPIO_setAsInputPinWithPullUpResistor( GPIO_PORT_P1, GPIO_PIN1 );
        MAP_GPIO_interruptEdgeSelect ( GPIO_PORT_P1, GPIO_PIN1, GPIO_LOW_TO_HIGH_TRANSITION );
        MAP_GPIO_clearInterruptFlag ( GPIO_PORT_P1, GPIO_PIN1 );
        MAP_GPIO_enableInterrupt ( GPIO_PORT_P1, GPIO_PIN1 );

        // Set P1.4 as input with pull-up resistor (for push button S2)
        //  First, configure the interrupt to trigger on low-to-high transition
        //  and then clear flag and enable the interrupt
        P1DIR &= ~0x10;
        P1REN |= 0x10;
        P1OUT |= 0x10;
        //P1SEL0 &
        //MAP_GPIO_setAsInputPinWithPullUpResistor( GPIO_PORT_P1, GPIO_PIN4 );
        MAP_GPIO_interruptEdgeSelect ( GPIO_PORT_P1, GPIO_PIN4, GPIO_LOW_TO_HIGH_TRANSITION );
        MAP_GPIO_clearInterruptFlag ( GPIO_PORT_P1, GPIO_PIN4 );
        MAP_GPIO_enableInterrupt ( GPIO_PORT_P1, GPIO_PIN4 );

    Interrupt_unpendInterrupt ( INT_PORT1 );                                    // (DriverLib) Clear pending bit for Port1 IRQ
    MAP_Interrupt_enableInterrupt( INT_PORT1 );                                     // (DriverLib) Enable NVIC for individual Port1 IRQ

    MAP_Interrupt_enableMaster();

    while(1);
}
