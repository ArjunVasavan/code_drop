#include <xc.h>

#define DKS1 (PORTC & 0x0F)

char digital[] = {0xE7,0x21,0xCB,0x6B,0x2D,0x6E,0xEE,0x23,0xEF,0x6F};

unsigned int count = 0;
unsigned int tim = 0;
char prev_key = 0x0F;

char read_digital_keypad() 
{
    return (PORTC & 0x0F);
}

void display(char data[])
{
    for(unsigned int digit = 0; digit < 4; digit++)
    {
        PORTD = data[digit];
        PORTA = (PORTA & 0xF0) | (1 << digit);
        for(unsigned int delay = 1000; delay--;);
    }
}

void main(void) 
{
    TRISD = 0x00;
    TRISA &= 0xF0;
    TRISC |= 0x0F;   // keypad input

    char ssd[4];
    char key;

    while (1) 
    {
        key = read_digital_keypad();

        // Key Pressed
        if(key != 0x0F)
        {
            tim++;

            // Long press (2 sec approx)
            if(tim >= 200)
            {
                count = 0;
            }
        }
        else // Key Released
        {
            // Short press
            if(prev_key != 0x0F && tim < 200 && tim > 0)
            {
                count++;
                if(count > 9999)
                    count = 0;
            }

            tim = 0;
        }

        prev_key = key;

        // Split digits correctly
        ssd[0] = digital[count / 1000];
        ssd[1] = digital[(count / 100) % 10];
        ssd[2] = digital[(count / 10) % 10];
        ssd[3] = digital[count % 10];

        display(ssd);
    }
}
