This code simulates a toy using an MSP430 microcontroller. The toy uses buttons to change states, which in turn control LEDs and sound output through a buzzer. The code is written in C and utilizes multiple libraries for handling timers, buzzer, sound, and LEDs.

Buttons are configured on pins P2.0, P2.1, P2.2, and P2.3.
Button press interrupts are enabled, and the interrupt flag is cleared after each press.

Port_2(): Handles button presses to change the state.
WDT(): Handles the watchdog timer interrupt to update the sound and call the state machine function every ~1 second.

When a button is pressed, the state changes, toggling the LEDs accordingly and producing sound notes in a loop.