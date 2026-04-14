#include <xc.h>
#include "timer0.h"
void init_timer0(void) {
    
    T08BIT = 1;
    T0CS = 0;
    TMR0ON = 1;
    PSA = 1;
    TMR0 = 6;
    TMR0IF = 0;
    TMR0IE = 1;
}
