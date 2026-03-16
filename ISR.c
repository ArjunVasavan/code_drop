#include <xc.h>

void main()
{
    TRISB0 = 1;
    TRISB7 = 0;
    PORTBbits.RB7 = 0;
    GIE = 1;
    PEIE = 1;
    INT0IE = 1;
    INT0IF = 0;
    
    INTEDG0 = 1;
    while(1);
}
void __interrupt() isr()
{
    if(INT0IF)
    {
        PORTBbits.RB7 = !PORTBbits.RB7;
        INT0IF = 0;
    }
}
