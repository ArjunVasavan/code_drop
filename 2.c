#include <xc.h>
#define EDGE 1
unsigned char pos = 0;

char read_digital_keybad(char key) // This function reads the state of the digital keypad and returns the corresponding value based on the key pressed.
{
    if (key == EDGE)
    {
        if ((PORTC & 0x0f) != 0x0f) // This condition checks if any of the lower 4 bits of PORTC are not equal to 0x0f, which indicates that a key is pressed.
            return PORTC & 0x0f;    // If a key is pressed, it returns the value of the lower 4 bits of PORTC, which corresponds to the key pressed on the keypad.
    }
    return 0x0f; // If no key is pressed, it returns 0x0f, indicating that all keys are in the unpressed state.
}

int main(void)
{
    TRISB = 0x00; // This line sets all the pins of PORTB as output by writing 0x00 to the TRISB register.
    PORTB = 0x00;
    TRISC = TRISC | 0x0f;
    unsigned char led = 0x01; // This variable is used to keep track of the current LED pattern that is being displayed on PORTB. It is initialized to 0x01, which corresponds to the first LED being turned on.
    unsigned long int delay = 0;
    unsigned char i = 0;
    while (1)
    {
        char key = read_digital_keybad(EDGE); // This line calls the read_digital_keybad function to read the state of the digital keypad and stores the returned value in the variable 'key'.
        if (key == 0x0e)
        {
            pos = 1;
            delay = 0;
            PORTB = 0x00; // This line clears all the LEDs connected to PORTB by writing 0x00 to it.
            led = 0x01;
            i = 0;
        }
        else if (key == 0x0d)
        {
            delay = 0;    // This line resets the delay counter to 0, which is used to control the timing of the LED patterns.
            PORTB = 0x00; // This line clears all the LEDs connected to PORTB by writing 0x00 to it.
            led = 1;
            i = 0;
            pos = 2;
        }
        else if (key == 0x0b) // This condition checks if the value of 'key' is equal to 0x0b, which corresponds to a specific key on the keypad.
        {
            PORTB = 0x00;
            delay = 0;
            i = 0;
            pos = 3;
        }
        else if (key == 0x07) // This condition checks if the value of 'key' is equal to 0x07, which corresponds to another specific key on the keypad.
        {
            i = 0;
            delay = 0;
            PORTB = 0x00;
            pos = 4;
        }
        if (pos == 1) // This condition checks if the variable 'pos' is equal to 1, which indicates that a specific key has been pressed on the keypad and the corresponding LED pattern should be displayed on PORTB.
        {
            if (delay++ == 60000) // This line increments the 'delay' variable and checks if it has reached a specific value (60000 in this case). This is used to create a delay between changes in the LED pattern on PORTB.
            {
                if (i < 8)
                {
                    PORTB = PORTB | led;
                    led = (unsigned char)(led << 1); // This line shifts the bits of the 'led' variable to the left by one position, which effectively moves the LED pattern to the next LED on PORTB.
                    i++;
                    if (i == 8)
                    {
                        led = 0x01; // This line resets the 'led' variable back to 0x01, which corresponds to the first LED being turned on, after all 8 LEDs have been turned on in sequence.
                    }
                }
                else if (i >= 8 && i < 16)
                {
                    PORTB = PORTB & (~led);
                    led = (unsigned char)(led << 1); // This line shifts the bits of the 'led' variable to the left by one position, which effectively moves the LED pattern to the next LED on PORTB while turning off the previous LED.
                    i++;
                    if (i == 16)
                    {
                        led = 0x80; // This line sets the 'led' variable to 0x80, which corresponds to the last LED being turned on, after all 8 LEDs have been turned off in sequence.
                    }
                }
                else if (i >= 16 && i < 24)
                {
                    PORTB = PORTB | led;
                    led = (unsigned char)(led >> 1); // This line shifts the bits of the 'led' variable to the right by one position, which effectively moves the LED pattern back to the previous LED on PORTB while turning on the next LED.
                    i++;
                    if (i == 24)
                    {
                        led = 0x80;
                    }
                }
                else
            {
                    PORTB = PORTB & (~led);
                    led = (unsigned char)(led >> 1); // This line shifts the bits of the 'led' variable to the right by one position, which effectively moves the LED pattern back to the previous LED on PORTB while turning off the next LED.
                    i++;
                    if (i == 32)
                    {
                        i = 0;
                        led = 0x01; // This line resets the 'led' variable back to 0x01, which corresponds to the first LED being turned on, after all 8 LEDs have been turned on and off in sequence.
                    }
                }

                delay = 0;
            }
        }
        else if (pos == 2)
        {
            if (delay++ == 60000) // This line increments the 'delay' variable and checks if it has reached a specific value (60000 in this case). This is used to create a delay between changes in the LED pattern on PORTB.
            {
                if (i < 8)
                {
                    PORTB = PORTB | led;
                    led = (unsigned char)(led << 1); // This line shifts the bits of the 'led' variable to the left by one position, which effectively moves the LED pattern to the next LED on PORTB while turning on the current LED.
                    i++;
                    if (i == 8)
                    {
                        led = 0x01;
                    }
                }
                else if (i >= 8 && i < 16)
                {
                    PORTB = PORTB & (~led);
                    led = (unsigned char)(led << 1); //  This line shifts the bits of the 'led' variable to the left by one position, which effectively moves the LED pattern to the next LED on PORTB while turning off the current LED.
                    i++;
                    if (i == 16)
                    {
                        i = 0;
                        led = 0x01; // This line resets the 'led' variable back to 0x01, which corresponds to the first LED being turned on, after all 8 LEDs have been turned on and off in sequence.
                    }
                }
                delay = 0;
            }
        }
        else if (pos == 3)
        {
            if (delay++ == 60000) // This line increments the 'delay' variable and checks if it has reached a specific value (60000 in this case). This is used to create a delay between changes in the LED pattern on PORTB.
            {
                if (i == 0)
                {
                    PORTB = 0xAA;
                    i = 1;
                }
                else
            {
                    PORTB = 0x55; // This line sets the value of PORTB to 0x55, which corresponds to a specific LED pattern where every alternate LED is turned on (i.e., LEDs 1, 3, 5, and 7 are turned on while LEDs 0, 2, 4, and 6 are turned off).
                    i = 0;
                }
                delay = 0;
            }
        }
        else if (pos == 4)
        {
            if (delay++ == 60000) // This line increments the 'delay' variable and checks if it has reached a specific value (60000 in this case). This is used to create a delay between changes in the LED pattern on PORTB.
            {
                if (i == 0)
                {
                    PORTB = 0xF0; // This line sets the value of PORTB to 0xF0, which corresponds to a specific LED pattern where the upper 4 LEDs (LEDs 4, 5, 6, and 7) are turned on while the lower 4 LEDs (LEDs 0, 1, 2, and 3) are turned off.
                    i = 1;
                }
                else
            {
                    PORTB = 0x0F; // This line sets the value of PORTB to 0x0F, which corresponds to a specific LED pattern where the lower 4 LEDs (LEDs 0, 1, 2, and 3) are turned on while the upper 4 LEDs (LEDs 4, 5, 6, and 7) are turned off.
                    i = 0;
                }
                delay = 0; // This line resets the 'delay' variable to 0, which is used to control the timing of the LED patterns on PORTB.
            }
        }
    }

    return;
}
