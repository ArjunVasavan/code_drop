#include "can.h"
#include "ecu2_sensor.h"
#include "adc.h"
#include "msg_id.h"
#include "digital_keypad.h"
#include <stdint.h>
char status;
uint16_t get_rpm()
{
    unsigned char data[5] = {0x00};
    unsigned int rpm = ((unsigned long)read_adc(CHANNEL4) * 6000) / 1023;
    int i = 0, num = rpm;
    if(num == 0) { data[i++] = '0'; }
    else {
        while(num != 0) { data[i++] = (num % 10) + '0'; num /= 10; }
        int s = 0, e = i - 1;
        while(s < e) { char t = data[s]; data[s] = data[e]; data[e] = t; s++; e--; }
    }
    data[i] = '\0';
    can_transmit(RPM_MSG_ID, data, i + 1);
    return rpm;
}

IndicatorStatus process_indicator()
{
    static int indicator = 0x00, key;
    key = read_digital_keypad(STATE_CHANGE);
    if(key != ALL_RELEASED) {
        if(key == SWITCH1) indicator = e_ind_left;
        else if(key == SWITCH2) indicator = e_ind_right;
        else if(key == SWITCH3) indicator = e_ind_hazard;
        else if(key == SWITCH4) indicator = e_ind_off;
    }
    can_transmit(INDICATOR_MSG_ID, (uint8_t*)&indicator, 1);
    return indicator;
}
