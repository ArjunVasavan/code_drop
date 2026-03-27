#include <xc.h>

volatile unsigned int flag;
volatile unsigned long int delay;

#define EDGE 1

unsigned int read_switch(int key) {
    if (key == EDGE) {
        if ((PORTC & 0x0F) != 0x0F) {
            return PORTC & 0x0F;
        }
    }
    return 0x0F;
}

int main(void) {
    TRISB = 0;
    PORTB = 0;
    PORTBbits.RB0 = 1;
    TRISC |= 0x0F;

    delay = 0;
    flag = 0;

    int duty_cycle = 20;
    int period = 100;
    int program_cycle = 0;
    int key = 0;
    unsigned long int sec_counter = 0;

    while (1) {
        key = read_switch(EDGE);

        if (key == 0x0E) {
            flag = 1;
            sec_counter = 0;
        }

        if (flag == 1) {
            sec_counter++;
            duty_cycle = 100;
            if (sec_counter >= 300000) {
                flag = 0;
                duty_cycle = 20;
                sec_counter = 0;
            }
        }

        if (duty_cycle == 100) {
            PORTBbits.RB0 = 1;
        } else {
            if (program_cycle <= duty_cycle) {
                PORTBbits.RB0 = 1;
            } else if (program_cycle <= period) {
                PORTBbits.RB0 = 0;
            }
            program_cycle++;
            if (program_cycle > period) {
                program_cycle = 0;
            }
        }
    }
}
