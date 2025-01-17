
#include <xc.h>
#include "LCD.h"
#include "AS5600.h"

//SDA -> RD5
//SCL -> RD6
//DIR -> 3.3V or GND
//GPO and OUT leave unconnected
//VCC -> 3.3V
//GND -> GND
//pull-ups on board

void main(void) {
    TRISBbits.TRISB0 = 1;
    OSCTUNEbits.PLLEN = 1;
    LCDInit();
    lprintf(0, "AS5600");
    __delay_ms(2000);
    AS5600_Init();
    while (1) {
        if (PORTBbits.RB0 == 0) { //is button down?
            __delay_ms(20);  //debounce
            if (PORTBbits.RB0 == 0) {  //is button still down?
                while (PORTBbits.RB0 == 0); //wait for it to go up
                AS5600_SetZeroPosition();
            }
        }
        uint8_t status = AS5600_GetStatus();
        float angle = AS5600_GetAngle();
        lprintf(1, "%.1f, %02x", angle, status);
        __delay_ms(200);
    }
}


 