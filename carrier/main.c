//*****************************************************************************
//
// MSP432 main.c template - Empty main
//
//****************************************************************************

#include "msp432.h"
#include <driverlib.h>
#include <stdint.h>
#include <stdbool.h>

void main(void)
{
	
    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer

    //configure I/O here

    //clock config
    CS_setDCOCenteredFrequency( CS_DCO_FREQUENCY_6 ); //maybe CS_tuneDCOFrequency

    CS_initClockSignal(CS_MCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1);MAP_CS_initClockSignal(
                CS_SMCLK,                                    // Clock you're configuring
                CS_DCOCLK_SELECT,                           // Clock source
                CS_CLOCK_DIVIDER_16                          // Divide down clock source by this much
        );

    //timer config
    Timer_A_UpModeConfig upConfig =
        {
                TIMER_A_CLOCKSOURCE_SMCLK,              // SMCLK Clock Source
                TIMER_A_CLOCKSOURCE_DIVIDER_1,          //
                0x____,                           // counter value / period (not yet set!!!!!!)
                TIMER_A_TAIE_INTERRUPT_DISABLE,         // Disable Timer interrupt
                TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE ,    // Enable CCR0 interrupt
                TIMER_A_DO_CLEAR                        // Clear value
        };
        Timer_A_configureUpMode(TIMER_A0_MODULE, &upConfig);
        Timer_A_startCounter(TIMER_A1_MODULE, TIMER_A_UP_MODE);
        //
        SysTick_enableModule();
        SysTick_setPeriod(1500000);             // check every xy ms(or change period
        SysTick_enableInterrupt();

    TA0CCR0 = 0xabcd; //counter so that counter = clock/38kHz
    TA0CCR1 = 0xbcde; //counter/2
    //also could enabe interrupt after time over and halt timer in isr (timekeeping with systick??)
    //set outmod to toggle/set
    TA0CCTL1 = OUTMOD_3;
    //set source+upmode
    TA0CTL = TASSEL__SMCLK + MC__UP + TAIE;
    /*set clock to whatever, feed timer with clock
     * timer count in up mode with outmod set/reset
     * TAxCCR0 = x, TAxCCR1 = x/2 with x  so that 38k*x = 1 second
     * => x = clock/38kHz*/
    while(1)
    {
    	//TODO
    }
}

//enable taifg in systick isr, so that timer stops on 0
void taifg_isr(void)
{
	TA0CTL &= ~(MC__UP + TAIE + TAIFG);//stop timer and disable innterrupt
}

void systick_isr(void)
{
	if(TA0CTL & MC__UP)
		TA0CTL |= TAIE;//if ta running enable interrupt to stop
	else
		TA0CTL |= MC__UP;//if ta stopped start ta
	//start/stop timer a
	/*start ta and systick(st), st interrupt -> xor taifg, new st value (maybe read from array of time values)*/
}
