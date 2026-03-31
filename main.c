#include <xc.h>

int count0 = 0;
int count1 = 0;
int count2 = 0;

void __interrupt() isr()
{
    if(INTCONbits.TMR0IF)
    {
        TMR0 = TMR0 + 8;
        
        if(count0++ == 10000)
        {
            PORTBbits.RB0 = !PORTBbits.RB0;
            count0 = 0; 
        }
        
        INTCONbits.TMR0IF = 0;    
    }
    
    if(PIR1bits.TMR1IF)
    {
        TMR1 = TMR1 + 3038;
        
        if(count1++ == 40)
        {
            PORTBbits.RB2 = !PORTBbits.RB2;
            count1 = 0;
        }
        
        PIR1bits.TMR1IF = 0;
    }
    
    if(PIR1bits.TMR2IF)
    {      
        if(count2++ == 10000)
        {
            PORTBbits.RB7 = !PORTBbits.RB7;
            count2 = 0;
        }
        
        PIR1bits.TMR2IF = 0;
    }
    
            
}

void init_timer0()
{
    TRISBbits.TRISB0 = 0;
    PORTBbits.RB0 = 0;
    T08BIT = 1;
    T0CS = 0;
    PSA = 1;
    INTCONbits.TMR0IE = 1;
    INTCONbits.TMR0IF = 0;
    TMR0 = 6;
    T0CONbits.TMR0ON = 1;
}
void init_timer1()
{
    TRISBbits.TRISB2 = 0;
    PORTBbits.RB2 = 0;
    PIE1bits.TMR1IE = 1;
    PIR1bits.TMR1IF = 0;
    T1CONbits.TMR1ON = 1;
    
}
void init_timer2()
{
    TRISBbits.TRISB7= 0;
    PORTBbits.RB7 = 0;
    PIE1bits.TMR2IE = 1;
    PIR1bits.TMR2IF = 0;
    PR2 = 249;
    TMR2ON = 1;
}
void init_config()
{
    init_timer0();
    init_timer1();
    init_timer2();
}
int main(void) {
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    init_config();
    while(1);
}
