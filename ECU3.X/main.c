#include <xc.h>
#include <stdint.h>
#include "clcd.h"
#include "msg_id.h"
#include "message_handler.h"
#include "timer0.h"
#include "can.h"
static void init_leds() {
    TRISB = 0x08; 
    PORTB = 0x00;
}
static void init_config(void) {
    init_clcd();
    init_can();
    init_leds();
    PEIE = 1;
    GIE = 1;
    init_timer0();
}
void main(void) {
    init_config();
    display_labels();
    while (1) {
        process_canbus_data();
    }
    return;
}
