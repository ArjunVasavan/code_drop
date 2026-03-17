#include <xc.h>
#define DELAY_COUNT 60000

int main()
{

    TRISB = 0;
    PORTB = 0;

    unsigned long long delay = 0;
    unsigned char led = 0x01;
    unsigned char i = 0;

    while (1) {

        if ( delay++ == DELAY_COUNT ) {

            if ( i < 8 ) {

                PORTB |= led;
                led <<= 1;
                i+=1;

                if ( i == 8 ) {

                    led = 0x01;

                }

            } else if ( i >= 8 && i < 16  ) {

                PORTB &= ~(led); 
                led <<= 1;
                i+=1;

                if ( i == 16 ) {
                    led = 0x80;
                }

            } else if ( i >= 16 && i < 24 ) {

                PORTB |= led; 
                led >>= 1;
                i+=1;

                if ( i == 24 ) {
                    led = 0x80;
                }

            } else {

                PORTB &= ~(led);
                led >>= 1;
                i+=1;

                if ( i == 32 ) {
                    led = 0x01;
                    i = 0;
                }

            } 


            delay = 0;
        }

    }

}


