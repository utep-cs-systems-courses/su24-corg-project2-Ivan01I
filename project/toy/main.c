#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "sound.h"
#include "led.h"

int sound[] = {NC, NCS, ND, NDS, NE};
int secondCount = 0;
int i = 0;
int state = 0;

void configureButtons() {
    P2DIR &= ~(BIT0 | BIT1 | BIT2 | BIT3);
    P2REN |= (BIT0 | BIT1 | BIT2 | BIT3);
    P2OUT |= (BIT0 | BIT1 | BIT2 | BIT3);
    P2IE |= (BIT0 | BIT1 | BIT2 | BIT3);
    P2IES |= (BIT0 | BIT1 | BIT2 | BIT3);
    P2IFG &= ~(BIT0 | BIT1 | BIT2 | BIT3);
}

void stateMachine() {
    switch (state) {
        case 0:
            P1OUT &= ~(LED_RED | LED_GREEN);
            break;
        case 1:
            P1OUT ^= LED_RED;
            break;
        case 2:
            P1OUT ^= LED_GREEN;
            break;
        case 3:
            P1OUT ^= (LED_RED | LED_GREEN);
            break;
        default:
            state = 0;
            break;
    }
}

int main(){
  configureClocks();
  enableWDTInterrupts();
  buzzer_init();
  led_init();
  configureButtons();
  or_sr(0x18);
}

void __interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & BIT0) {
    P2IFG &= ~BIT0;
    state = 1;
  }
  if (P2IFG & BIT1) {
    P2IFG &= ~BIT1;
    state = 2;
  }
  if (P2IFG & BIT2) {
    P2IFG &= ~BIT2;
    state = 3;
  }
  if (P2IFG & BIT3) {
    P2IFG &= ~BIT3;
    state = 0;
  }
}

void __interrupt_vec(WDT_VECTOR) WDT(){
  secondCount++;
  if(secondCount >= 170){
    secondCount = 0;
    buzzer_set_period(sound[i]);
    stateMachine();
    i++;
    if(i >= 5){
      i = 0;
    }
  }
}
