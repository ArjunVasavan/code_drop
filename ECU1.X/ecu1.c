#include "ecu1_sensor.h"
#include "adc.h"
#include "can.h"
#include "msg_id.h"
#include "matrix_keypad.h"
#include "clcd.h"
#include <stdint.h>
char gear[9][3]={"ON","GN","G1","G2","G3","G4","G5","Rr","Cl"};
int ind = 0;
#define _XTAL_FREQ 8000000
uint16_t msg_id;
uint8_t rx1_data[4];
char len1;
uint16_t gear_id;
uint8_t rx2_data[4];
char len2;
uint16_t get_speed()
{
    char str[3];
   unsigned short speed= read_adc(CHANNEL4)/10.33;
   str[0]=(speed/10)+48;
   str[1]=(speed%10)+48;
   str[2]='\0';
   can_transmit(SPEED_MSG_ID ,(const uint8_t*)str,2);
   __delay_ms(20);
   return speed;
}
unsigned char get_gear_pos() {
    int key=read_switches(STATE_CHANGE);
    if(key== 1) {
        if(ind<7) {
            ind++;
        }
    } else if(key == 2) {
        if(ind>0) {
            ind--;
        }
    } else if(key== 3) {
        ind=8;
    }
    can_transmit(GEAR_MSG_ID,(const uint8_t*)&ind,1);
    __delay_ms(80);
    return gear[ind][0];
}
