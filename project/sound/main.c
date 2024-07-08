#include <msp430.h>
#include "libTimer.h"
#include "make_sound.h"

void play_song() {
    buzzer_set_period(3000);   // Adjust frequencies as needed
    __delay_cycles(500000);    // Increase delay between notes for slower speed
    buzzer_set_period(2500);
    __delay_cycles(500000);
    buzzer_set_period(2000);
    __delay_cycles(500000);
}

int main() {
    configureClocks();
    buzzer_init();

    while (1) {
        play_song();
    }
}
