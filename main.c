#include <xc.h>
#include "clcd.h"

static void init_config(void) {
    init_clcd();
  
}

unsigned char arr[17] = "HELLO_WORLD_____";
char backup;
long int delay = 0;

int main(void) {

    init_config();

    while(1) {
        if(delay++ >= 90000) {
            backup = arr[15];
            for(int i = 15; i>0 ; i--){
                arr[i] = arr[i-1];
            }
            arr[0] = backup;
            delay = 0;
            clcd_print(arr,LINE2(0));
        }
    }
    
}

