#include <xc.h>

/* NOTE: Logic
 * mode = 0 => run mode
 * mode = 1 => edit mode
 * Run mode:
 *   - Clock ticks via TMR0 ISR (count -> sec -> min -> hr)
 *   - Colon (DP) blinks every ~500ms using count threshold
 *   - Switches 1/2/3 do nothing in run mode
 *   - Switch 4 toggles into edit mode
 * Edit mode:
 *   - Clock does NOT tick (sec/count frozen)
 *   - Switch 3 toggles which field is selected (hr / min)
 *   - Switch 1 increments selected field
 *   - Switch 2 decrements selected field
 *   - Selected field blinks (00XX -> 0000 -> 00XX)
 *   - Switch 4 exits back to run mode
 */

volatile unsigned long int sec   = 0;
volatile unsigned long int count = 0;

char digit[] = {0xE7, 0x21, 0xCB, 0x6B, 0x2D, 0x6E, 0xEE, 0x23, 0xEF, 0x6F};

void __interrupt() isr(void) {
    if (INTCONbits.TMR0IF) {
        INTCONbits.TMR0IF = 0;
        TMR0 += 8;        
        if (++count >= 20000) {
            count = 0;   
            sec++;
        }
    }
}

char read_digital_keypad(void) {
    return (PORTC & 0x0F); 
}

void display(char data[]) {
    for (unsigned int d = 0; d < 4; d++) {
        PORTD = data[d];
        PORTA = (PORTA & 0xF0) | (1u << d);
        for (unsigned int delay = 1000; delay--;);
    }
}

static char prev_key = 0;
char key_pressed(char key, char bit) {
    return (key & bit) && !(prev_key & bit);
}

int main(void) {
    int hr   = 0;
    int min  = 0;
    int mode = 0;           /* 0 = run, 1 = edit                               */
    int edit_field = 0;     /* 0 = editing hours, 1 = editing minutes          */

    char ssd[4];
    char key;

    TRISD  = 0x00;      
    TRISA &= 0xF0;     
    TRISC |= 0x0F;    

    T0CON             = 0xC4;  
    TMR0              = 8;
    INTCONbits.TMR0IE = 1;
    INTCONbits.GIE    = 1;

    while (1) {
        key = read_digital_keypad();

        if (key_pressed(key, 0x08)) {
            mode = !mode;
            if (mode == 1) {
                INTCONbits.TMR0IE = 0;
                edit_field = 0;
            } else {
                sec   = 0;
                count = 0;
                INTCONbits.TMR0IE = 1;
            }
        }

        if (mode == 0) {
            if (sec >= 60) {
                sec = 0;
                min++;
                if (min >= 60) {
                    min = 0;
                    hr++;
                }
                if (hr >= 24) {
                    hr = 0;
                }
            }

            ssd[0] = digit[hr / 10];
            ssd[1] = (count < 10000)
                     ? (0x10 | digit[hr % 10])
                     :          digit[hr % 10];
            ssd[2] = digit[min / 10];
            ssd[3] = digit[min % 10];

        } else {
            if (key_pressed(key, 0x04)) {
                edit_field = !edit_field;
            }

            if (key_pressed(key, 0x01)) {
                if (edit_field == 0) {
                    hr  = (hr  + 1) % 24;
                } else {
                    min = (min + 1) % 60;
                }
            }

            if (key_pressed(key, 0x02)) {
                if (edit_field == 0) {
                    hr  = (hr  + 23) % 24;
                } else {
                    min = (min + 59) % 60;
                }
            }

            static unsigned long blink_count = 0;
            blink_count++;
            char blink_on = (blink_count < 30000);
            if (blink_count >= 60000) blink_count = 0;

            if (edit_field == 0) {
                ssd[0] = blink_on ? digit[hr / 10]  : 0x00;
                ssd[1] = blink_on ? digit[hr % 10]  : 0x00;
                ssd[2] = digit[min / 10];
                ssd[3] = digit[min % 10];
            } else {
                ssd[0] = digit[hr / 10];
                ssd[1] = digit[hr % 10];
                ssd[2] = blink_on ? digit[min / 10] : 0x00;
                ssd[3] = blink_on ? digit[min % 10] : 0x00;
            }
        }

        prev_key = key; 
        display(ssd);
    }
}
