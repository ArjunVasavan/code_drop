#include <xc.h>

void delay()
{
    long int i;
    for(i = 0; i < 50000; i++);   // simple delay loop
}

void main(void)
{
    TRISBbits.TRISB1 = 0;   // Set RB1 as OUTPUT
    ADCON1 = 0x0F;          // Configure all pins as DIGITAL

    while(1)
    {
        LATBbits.LATB1 = 1;   // LED ON
        delay();

        LATBbits.LATB1 = 0;   // LED OFF
        delay();
    }
}
