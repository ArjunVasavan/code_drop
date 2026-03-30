/* ========================================
 * Author : Arjun Vasavan
 * Date   : 30-03-2026
 * ========================================
 */

#include <xc.h>

#define EDGE 1

signed char hr = 0;
signed char min = 0;
char sec = 0;
char mode = 0;
int count = 0;
char flag = 1;
char field_flag = 0;
char digit[10] = {0xE7,0x21,0xCB,0x6B,0x2D,0X6E,0xEE,0x23,0xEF,0x6F}; // 7-seg codes
char ssd[4];     // 4-digit display buffer

void __interrupt() isr() {
    if(INTCONbits.TMR0IF) {

        TMR0 = 8 + TMR0; // adding preloaded value 6 + 2 ( instruction + execute )

        if(count++ == 20000) {
            sec++;
            count = 0;
        }
        INTCONbits.TMR0IF = 0;
    }
}

void display(char *data) {
    for( int i = 0 ; i < 4 ; i++ ) {
        PORTD = data[i];   // Send segment data
        PORTA = (unsigned char)((PORTA & 0XF0) | (1 << i)); // Select digit
        for( int delay_1 = 500; delay_1--; ); // Multiplexing delay
    }
}

char read_digital_keypad() {
        if ((PORTC & 0x0F) != 0x0F && flag) {
            flag = 0;
            return PORTC & 0x0F;
        }
        else if((PORTC & 0x0F) == 0x0F) {
            flag = 1;
        }
    return 0x0F; 
}

int main(void) {
    
    TRISC = TRISC | 0X0F;
    TRISD = 0x00;
    TRISA = TRISA & 0xF0;
    PORTA = PORTA & 0XF0;
    
    
    T08BIT = 1;
    T0CS = 0;
    PSA = 1;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.TMR0IE = 1;
    INTCONbits.TMR0IF = 0;
    TMR0 = 6;
    T0CONbits.TMR0ON = 1;
    ADCON1 = 0x0F;
    while(1)
    {
        char key = read_digital_keypad();
        
        if(key == 0x07)
        {
            mode = !mode;
            sec = 0;
        }
        else if(key == 0x0B)
        {
            field_flag = !field_flag;
        }
        
        
        if(mode == 0)
        {
            if(sec == 60)
            {
                sec = 0;
                min++;
                if(min == 60)
                {
                    hr++;
                    min = 0;
                    if(hr == 24)
                    {
                        hr = 0;
                    }
                }
            }
            ssd[0] = digit[hr/10];
            ssd[2] = digit[min/10];
            ssd[3] = digit[min%10];
            
            if(count < 10000)
                ssd[1] = 0x10 | digit[hr%10];
            else
                ssd[1] = digit[hr%10];
            
            display(ssd);    
        }
        else if(mode == 1)
        {
            if(key == 0x0E)
            {
                if(field_flag == 0)
                {
                    min++;
                    if(min == 60)
                    {
                        hr++;
                        min = 0;
                        if(hr == 24)
                        {
                            hr = 0;
                        }
                    }
                    
                }
                else
                {
                    hr++;
                    if((hr == 24))
                    {
                        hr = 0;
                    }
                }    
            }
            else if(key == 0x0D)
            {
                if(field_flag == 0)
                {
                    min--;
                    if(min == -1)
                    {
                        hr--;
                        min = 59;
                        if(hr == -1)
                        {
                            hr = 23;
                        }
                    }
                    
                }
                else
                {
                    hr--;
                    if(hr == -1 )
                    {
                        hr = 23;
                    }
                }
            }
            
            if(count < 10000)
            {   
                ssd[2] = digit[min/10];
                ssd[3] = digit[min%10];
                ssd[0] = digit[hr/10];
                ssd[1] = digit[hr%10];      
            }
            else
            {
                if(field_flag == 0)
                {
                    ssd[2] = 0;
                    ssd[3] = 0;
                }
                else
                {
                    ssd[0] = 0;
                    ssd[1] = 0;  
                }    
            }
            display(ssd);        
        }
    }

    return;
}

