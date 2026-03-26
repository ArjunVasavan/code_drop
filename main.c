#include <xc.h>

/* NOTE: Logic
     * if ( mode == 0 ) {
     *      if ( sec == 60 ) {
     *
     *          min++;
     *          sec = 0;
     *          if ( min == 60 ) {
     *              hr++;
     *          } 
     *
     *          if ( hr == 24 ) {
     *              hr = 0;
     *          }
     *      }
     *      ssd[0] = digit[hr/10];
     *      ssd[3] = digit[min/10];
     *      ssd[0] = digit[min%10];
     *
     *      if ( count < 10000 ) {
     *          ssd[1] = 0x10 | digit[hr%10];
     *
     *      } else {
     *          ssd[1] = digit[hr%10];
     *      }
     *
     * } else if ( mode == 1 ) {
     *
     * }
     */

/* NOTE: Edit Mode
 * Edit mode is switch 4
 * Dp should be turned off
 * Editable field blinks ( minute and hour )
 * Blinking (min) -> 0000 -> 00XX -> 0000 -> 00XX
 * Switch 3 -> for choosing which field
 * Switch 1 => increment Switch 2 => Decrement
 * if Switch 4 is once more pressed it should go back to run mode
 * on run mode switch 1, 2, 3 should not work
 */

/* TODO: Steps
 * hr = 0, min = 0, sec = 0
 * mode = 0 is run 1 is edit
 * if ( mode == 0 ) run mode
 * 
 */

unsigned long int sec;
unsigned long int count;
unsigned int ssd[4];


char digit[] = {0xE7,0x21,0xCB,0x6B,0x2D,0x6E,0xEE,0x23,0xEF,0x6F};

void __interrupt() isr() {

    if (INTCONbits.TMR0IF) {

        TMR0+=8;

        if ( count++ == 20000) {
            sec+=1;
        }
    }
}


char read_digital_keypad(){
    return (PORTC & 0x0F); // Pull up keyboard all are setted up as input
}

void display(char data[]) {

    for(unsigned int digit = 0; digit < 4; digit++) {
        PORTD = data[digit];
        PORTA = (PORTA & 0xF0) | (1 << digit);
        for(unsigned int delay = 1000; delay--;);
    }
}

int main(void) {

    int hr = 0;
    int min = 0;
    sec = 0;

    int mode = 0;

    TRISD = 0x00;
    TRISA &= 0xF0;
    TRISC |= 0x0F;   // keypad input

    char ssd[4];
    char key;

    
    while (1) {
        key = read_digital_keypad();

        if ( key == 0x2D ) {
            mode = !mode;
        }

        if ( mode == 1) {


            if ( sec == 60 ) {

                min++;
                sec = 0;

                if ( min == 60 ) {
                    hr++;
                    min = 0;
                }

                if ( hr == 24 ) {
                    hr = 0;
                }

            }

            ssd[0] = digit[hr/10];

            if ( count < 10000 ){  // 500 ms
                ssd[1] = 0x10|digit[hr%10];
            } else {
                ssd[1] = digit[hr%10];
            }

            ssd[0] = digit[min/10];
            ssd[0] = digit[min%10];


        } else if ( mode == 0 ) {
        

        }
    }
}
