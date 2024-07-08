#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "sound.h"

int sound[] = {NA, NB, NC, ND, NE};
int secondCount = 0;
int i = 0;
int play = 0;

void configureButton(){
  P1DIR &= ~BIT3;
  P1REN |= BIT3;
  P1OUT |= BIT3;
  P1IE |= BIT3;
  P1IES |= BIT3;
  P1IFG &= ~BIT3;
}

int main(){
  configureClocks();
  enableWDTInterrupts();
  buzzer_init();
  configureButton();
  or_sr(0x18);
}

void __interrupt_vec(PORT1_VECTOR) Port_1(){
  if (P1IFG & BIT3){
    P1IFG &= ~BIT3;
    play = 1;
  }
}

void __interrupt_vec(WDT_VECTOR) WDT(){
  if (play){
    secondCount++;
    if(secondCount >= 170){
      secondCount = 0;
      buzzer_set_period(sound[i]);
      i++;
      if (i >= 5){
        i = 0;
      }
    }
  }
}
