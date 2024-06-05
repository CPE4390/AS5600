
#include <xc.h>
#include "LCD.h"

//RD5 = SDA
//RD6 = SCL
//pull-ups on board?

void main(void) {
    OSCTUNEbits.PLLEN = 1;
    LCDInit();
    lprintf(0, "AS5600");
    __delay_ms(2000);
    
    while (1) {
        
        __delay_ms(200);
    }
}


 