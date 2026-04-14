#include "adc.h"
#include "can.h"
#include "ecu1_sensor.h"
#include "clcd.h"
void init_config() {
    init_adc();
    init_matrix_keypad();
    init_can();
}
int main() {
    init_config();
    while(1) {
        get_speed();
        get_gear_pos();    
    }
}
