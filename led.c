#include <xc.h>

void main(void)
{
    TRISBbits.TRISB0 = 0;   
    ADCON0 = 0xfF;   
    TRISBbits.TRISB1 = 0;   
    ADCON1 = 0xfF;
     TRISBbits.TRISB2 = 0;   
    ADCON2 = 0xfF; 
     TRISBbits.TRISB3 = 0;   
    ADCON3 = 0xfF; 
     TRISBbits.TRISB4 = 0;   
    ADCON4 = 0xfF; 
     TRISBbits.TRISB5 = 0;   
    ADCON5 = 0xfF; 
     TRISBbits.TRISB6 = 0;   
    ADCON6 = 0xfF;
     TRISBbits.TRISB7 = 0;   
    ADCON7 = 0xfF; 

    while(1)
    {
        LATBbits.LATB0 = 1;  
        for(long int i = 0; i < 50000; i++); 
        
        LATBbits.LATB0 = 0;  
        for(long int i = 0; i < 50000; i++); 
        
        LATBbits.LATB1 = 1;  
        for(long int i = 0; i < 50000; i++);  

        LATBbits.LATB1 = 0;  
        for(long int i = 0; i < 50000; i++);
        
        LATBbits.LATB2 = 1;  
        for(long int i = 0; i < 50000; i++);  

        LATBbits.LATB2 = 0;  
        for(long int i = 0; i < 50000; i++);
        
        LATBbits.LATB3 = 1;  
        for(long int i = 0; i < 50000; i++);  

        LATBbits.LATB3 = 0;  
        for(long int i = 0; i < 50000; i++);
        
        LATBbits.LATB4 = 1;  
        for(long int i = 0; i < 50000; i++);  

        LATBbits.LATB4 = 0;  
        for(long int i = 0; i < 50000; i++);
        
        LATBbits.LATB5 = 1;  
        for(long int i = 0; i < 50000; i++);  

        LATBbits.LATB5 = 0;  
        for(long int i = 0; i < 50000; i++);
        
        LATBbits.LATB6 = 1;  
        for(long int i = 0; i < 50000; i++);  

        LATBbits.LATB6 = 0;  
        for(long int i = 0; i < 50000; i++);
        
        LATBbits.LATB7 = 1;  
        for(long int i = 0; i < 50000; i++);  

        LATBbits.LATB7 = 0;  
        for(long int i = 0; i < 50000; i++);
    }
}
