#include <stdio.h>
#include <stdlib.h>
#include <xc.h>


void display(char data[] ) {

    for ( int digit = 0 ; digit < 4 ; digit++ ) {

        PORTD = data[digit];

        PORTA = ( PORTA & 0x0F ) | ( 1 << digit );

        for (unsigned int delay = 500; delay--; );
    }

 
}

// here mazimum of controller is 2 bytes somewhat 65000 int can be stored
// HELLO HI

void main(int argc, char** argv) {

    unsigned char digit[] = {0xE7,0x21,0xCB,0x6B,0x2D,0x6E,0xEE,0x23,0xEF,0x2F};

    unsigned char ssd[4];

    TRISD = 0x00;
    TRISA = TRISA & 0xF0;
    PORTA = PORTA & 0xF0;

    while (1) {

        ssd[0] = digit[0];
        ssd[1] = digit[1];
        ssd[2] = digit[2];
        ssd[3] = digit[3];
    

        display(ssd);
    }
}

