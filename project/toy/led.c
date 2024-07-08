#include <msp430.h>
#include "led.h"

void led_init() {
    P1DIR |= LED_RED | LED_GREEN;
    P1OUT &= ~(LED_RED | LED_GREEN);
}
