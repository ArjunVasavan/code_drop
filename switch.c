#include <xc.h>

#define LEVEL 0
#define EDGE 1

char flag = 1;
char key;
char read_switch(char);

void main()
{
    TRISC = TRISC & 0x0f;
    TRISB = 0x00;
    PORTB = 0x00;
    
    while(1){
        key = read_switch(EDGE);
        if(key == 0x0E){
            //task 1;
        }
        else if(key == 0x0D){
            //task 2
        }
        else if(key == 0x0B){
            //task 3
        }
        else if(key == 0x07){
            //task 4
        }
    }
}
char read_switch(char key_detect){
    if(key_detect == EDGE){
        if((PORTC & 0x0f) != 0x0f && flag){
            flag = 0;
            return PORTC & 0x0f;
        }
        else if((PORTC & 0x0f) == 0x0f){
            flag = 1;
        }
    }
    
    if(key_detect == LEVEL){
        return PORTC & 0x0f;
    }
    return 0x0f;
}
