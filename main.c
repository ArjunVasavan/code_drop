#include <xc.h>
#include <stdint.h>

#define _XTAL_FREQ 20000000



// SSD
#define DATA_PORT PORTD
#define DATA_DDR  TRISD

#define CTRL_PORT PORTA
#define CTRL_DDR  TRISA

// KEYPAD (PORTC)
#define SWITCH1 0x0E
#define SWITCH2 0x0D
#define SWITCH3 0x0B
#define SWITCH4 0x07
#define ALL_RELEASED 0x0F

#define LEVEL 0
#define EDGE  1

// GLOBAL
volatile unsigned int half_sec = 0;

// SSD codes (Common Cathode)
// 👉 If Common Anode → use ~seg[i]
uint8_t seg[10] = {0xE7,0x21,0xCB,0x6B,0x2D,0x6E,0xEE,0x23,0xEF,0x6F};

// ---------------- TIMER ----------------
void init_timer0(void)
{
    TMR0 = 6;

    T08BIT = 1;
    T0CS = 0;
    PSA = 1;

    INTCONbits.TMR0IF = 0;
    INTCONbits.TMR0IE = 1;
    INTCONbits.GIE = 1;

    TMR0ON = 1;
}

// ---------------- ISR ----------------
void __interrupt() isr(void)
{
    static unsigned int count = 0;

    if (INTCONbits.TMR0IF)
    {
        TMR0 += 8;

        if (++count >= 10000)   // ~500ms
        {
            half_sec++;
            count = 0;
        }

        INTCONbits.TMR0IF = 0;
    }
}

// ---------------- SSD ----------------
void init_ssd(void)
{
    ADCON1 = 0x0F;   // PORTA digital

    DATA_DDR = 0x00;
    CTRL_DDR = 0xF0;

    DATA_PORT = 0x00;
    CTRL_PORT = 0x00;
}

void display(uint8_t *ssd)
{
    for (int i = 0; i < 4; i++)
    {
        CTRL_PORT = 0x00;          // 🔥 turn OFF all digits first

        DATA_PORT = ssd[i];        // 👉 use ~ssd[i] if Common Anode

        CTRL_PORT = (1 << i);      // enable one digit

        __delay_ms(2);             // 🔥 stable multiplex delay
    }
}

// ---------------- KEYPAD ----------------
unsigned char read_keypad(unsigned char mode)
{
    static unsigned char once = 1;

    if (mode == LEVEL)
        return PORTC & 0x0F;

    if (mode == EDGE)
    {
        if ((PORTC & 0x0F) != ALL_RELEASED && once)
        {
            once = 0;
            return PORTC & 0x0F;
        }
        else if ((PORTC & 0x0F) == ALL_RELEASED)
        {
            once = 1;
        }
    }

    return ALL_RELEASED;
}

// ---------------- MAIN ----------------
void main(void)
{
    TRISC = 0x0F;   // keypad input

    init_ssd();
    init_timer0();

    uint8_t ssd[4];

    uint8_t hrs = 0, min = 0;
    uint8_t mode = 0;
    uint8_t field = 0;

    unsigned char key_e, key_l;

    while (1)
    {
        key_e = read_keypad(EDGE);
        key_l = read_keypad(LEVEL);

        // MODE CHANGE
        if (key_e == SWITCH4)
            mode = !mode;

        // -------- EDIT MODE --------
        if (mode == 1)
        {
            if (key_e == SWITCH3)
                field = !field;

            // MINUTE
            if (field == 0)
            {
                if (key_l == SWITCH1)
                {
                    __delay_ms(200);
                    while ((PORTC & 0x0F) != ALL_RELEASED);

                    min = (min == 59) ? 0 : min + 1;
                }

                if (key_l == SWITCH2)
                {
                    __delay_ms(200);
                    while ((PORTC & 0x0F) != ALL_RELEASED);

                    min = (min == 0) ? 59 : min - 1;
                }
            }
            // HOUR
            else
            {
                if (key_l == SWITCH1)
                {
                    __delay_ms(200);
                    while ((PORTC & 0x0F) != ALL_RELEASED);

                    hrs = (hrs == 23) ? 0 : hrs + 1;
                }

                if (key_l == SWITCH2)
                {
                    __delay_ms(200);
                    while ((PORTC & 0x0F) != ALL_RELEASED);

                    hrs = (hrs == 0) ? 23 : hrs - 1;
                }
            }

            // BLINK
            if (half_sec % 2 == 0)
            {
                if (field == 0)
                {
                    ssd[3] = seg[min % 10];
                    ssd[2] = seg[min / 10];
                }
                else
                {
                    ssd[1] = seg[hrs % 10];
                    ssd[0] = seg[hrs / 10];
                }
            }
            else
            {
                if (field == 0)
                {
                    ssd[3] = 0x00;
                    ssd[2] = 0x00;
                }
                else
                {
                    ssd[1] = 0x00;
                    ssd[0] = 0x00;
                }
            }

            // OTHER FIELD
            if (field == 0)
            {
                ssd[1] = seg[hrs % 10];
                ssd[0] = seg[hrs / 10];
            }
            else
            {
                ssd[3] = seg[min % 10];
                ssd[2] = seg[min / 10];
            }
        }

        // -------- RUN MODE --------
        else
        {
            if (half_sec >= 120)
            {
                half_sec = 0;
                min++;

                if (min == 60)
                {
                    min = 0;
                    hrs++;

                    if (hrs == 24)
                        hrs = 0;
                }
            }

            uint8_t dot = (half_sec % 2 == 0) ? 0x10 : 0x00;

            ssd[3] = seg[min % 10];
            ssd[2] = seg[min / 10];
            ssd[1] = seg[hrs % 10] | dot;
            ssd[0] = seg[hrs / 10];
        }

        // 🔥 IMPORTANT: refresh multiple times for stability
        for (int i = 0; i < 20; i++)
        {
            display(ssd);
        }
    }
}
