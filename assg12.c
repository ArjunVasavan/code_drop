/*
 * File:   newmain.c
 * Author: spect
 *
 * Created on 24 March, 2026, 12:53 PM
 */


#include <xc.h>


void init_adc(void)
{
	/* Selecting right justified ADRES Registers order */
	ADFM = 1;

	/* 
	 * Acqusition time selection bits 
	 * Set for 4 Tad
	 */
	ACQT2 = 0;
	ACQT1 = 1;
	ACQT0 = 0;

	/*
	 * Selecting the conversion clock of Fosc / 32 -> 1.6usecs -> 1Tad
	 * Our device frequency is 20 MHz
	 */
	ADCS0 = 0;
	ADCS1 = 1;
	ADCS2 = 0;

	/* Stop the conversion to start with */
	GODONE = 0;

	

	/* Voltage reference bit as VSS */
	VCFG1 = 0;
	/* Voltage reference bit as VDD */
	VCFG0 = 0;

	/* Just clearing the ADRESH & ADRESL registers, for time pass */
	ADRESH = 0;
	ADRESL = 0;

	/* Turn ON the ADC module */
	ADON = 1;
}

unsigned short read_adc(unsigned char channel)
{
	unsigned short reg_val;

	/*select the channel*/
	ADCON0 = (ADCON0 & 0xC3) | (channel << 2);

	/* Start the conversion */
	GO = 1;
	while (GO);
	reg_val = (ADRESH << 8) | ADRESL; 

	return reg_val;
}


static void init_config(void)
{
	TRISB0 = 0;
    RB0 = 0;
    init_adc();
    
}

char duty_cycle;
char period = 100;
char program = 0;

void main(void)
{
    unsigned short adc_reg_val;

    init_config();

    while (1)
    {
        adc_reg_val = read_adc(0x04);
        duty_cycle = (adc_reg_val) / 10;
        
        if(program++ <= duty_cycle){
            PORTBbits.RB0 = 1;
        }
        else if(program < period){
            PORTBbits.RB0 = 0;
        }
        else{
            program = 0;
        }
            
    }
}
