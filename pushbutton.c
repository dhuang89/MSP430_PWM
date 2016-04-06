#include "pushbutton.h"

void InitializePushButtonPortPin (void)
{
	P1DIR &= ~BIT3; //set direction as input
	P1OUT |= BIT3; //pull up resistor
	P1REN |= BIT3; //resistor enabled
	P1IE |= BIT3; //enables interrupt

}


#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
/*//Interrupt routine for button
	if (x == 0) {
		//TACCR1 += 0;
		x = 1;
	}
	else {
		//TACCR1 += 800;
		x = 0;
	}

	P1IFG &= ~BIT3;*/

}
