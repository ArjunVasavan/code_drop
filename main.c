#include <xc.h>

volatile unsigned int sec = 0;

void __interrupt() isr() {

    if (INTCONbits.INT0IF) {
        INTCONbits.INT0IF = 0;
        sec = 0;
    }
}

void display(char* data) {

    for ( int i = 0 ; i < 4 ; i++ ) {
        PORTD = data[i];
        PORTA = (unsigned)(PORTA & 0xF0) | ( 1 << i );
        for ( unsigned int delay = 1000 ; delay--;);
    }
}

unsigned long int delay;
char digit[12] = {0xE7,0x21,0xCB,0x6B,0x2D,0X6E,0xEE,0x23,0xEF,0x6F,0x40,0x40};
char ssd[4];
unsigned long int delay = 0;

int main(void) {

    TRISD = 0x00;
    TRISA &= 0xF0; // or chech TRISA = 0x00
    TRISB = 0x01 ;// here interrupt will take RB0

    PORTB = 0x00;
    PORTBbits.RB7 = 0;

    INTCONbits.GIE = 1;
    INTCONbits.INT0IE = 1;
    INTCONbits.INT0IF = 0;


    while (1) {

        ssd[0] = digit[0];
        ssd[1] = digit[1];
        ssd[2] = digit[2];
        ssd[3] = digit[3];

        display(ssd);

        if (delay++ == 300 ) {

            delay = 0;
            PORTBbits.RB7 = !PORTBbits.RB7;
            sec+=1;
        }

        if ( sec == 5 ) {
            SLEEP();
        }
    }
}

