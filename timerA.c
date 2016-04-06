#include "timerA.h"
#include "LED.h"


void ConfigureTimerA(void)
{
	TACCR0 = 20000;
	TACCR1 = 0;
	TACCTL0 = CCIE;
	TACCTL1 = CCIE;
	//Set up the timer
	TACTL = (TASSEL_2|ID_0|MC_1|TACLR |TAIE);
	P1OUT = 0;
	P1DIR = BIT0;
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer0_A0(void)
{
// Timer A interrupt service routine when TACCR0 value is reached
// and CCIFG0 interrupt is set
	static enum {up, down} direction = up;

	//if (!x) {
		if (direction == up) {
			//P1DIR = BIT0;
			TACCR1 += 800;
			if (TACCR1 > TACCR0) {
				direction = down;
				//SET_LED2_AS_AN_OUTPUT;
				//TOGGLE_LED2;
			}
		} else {
			//P1DIR = BIT0;
			TACCR1 -= 800;
			if (TACCR1 == 0) {
				direction = up;
				//SET_LED2_AS_AN_OUTPUT;
				//TOGGLE_LED2;
			}

		}
	}
	/*else {
		TACCR1 = TACCR1;
	}
}*/

#pragma vector=TIMER0_A1_VECTOR
__interrupt void Timer0_A1(void)
{
// Timer0 A1 interrupt service routine when TACCR1 value is reached
// and CCIFG1 is set. Note that this ISR also services the Timer A
// interrupt when TAIFG is set.

	switch (__even_in_range(TAIV, 10)) {
	case 0:
		break;
	case 2:
		LED1_PORT &= ~BIT0;
		break;
	case 10:
		if (TACCR1 != 0) {
			LED1_PORT |= BIT0;
		}
		break;
	default:
		for(;;) {

		}
	}
}

