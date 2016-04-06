#include <msp430.h>
#include "LED.h"
#include "pushbutton.h"
#include "timerA.h"

//int x = 0; //sets bit to green LED at first, button switch causes red LED to start

// Function prototypes
void ConfigureClockModule(void);

void main(void)
{
	// Stop the watchdog timer, and configure the clock module.
	WDTCTL = WDTPW + WDTHOLD;
	ConfigureClockModule();

    // Initialize port pins associated with the LEDs and turn off LEDs.
    SetLEDState(LED1,OFF);
    SetLEDState(LED2,OFF);
    InitializeLEDPortPins();

    // Initialize the port pin associated with the pushbutton
    InitializePushButtonPortPin();

    // Configure timer A to generate the required interrupt.
	ConfigureTimerA();

	//Set the GIE Bit
	_BIS_SR(GIE);

	// Infinite loop
//	while(1) {
//		TOGGLE_LED1;
//		_delay_cycles(500000);
//	}

}

void ConfigureClockModule(void)
{
    // Configure Digitally Controlled Oscillator (DCO) for 16 MHz using factory
    // calibrations.
	DCOCTL  = CALDCO_1MHZ;
	BCSCTL1 = CALBC1_1MHZ;
}

