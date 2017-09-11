#include <driverlib.h>

#ifndef INITGPIO_H_
#define INITGPIO_H_

extern int speed;

void init_Gpio(void);
void port1_ISR(void);

#endif /* INITGPIO_H_ */
