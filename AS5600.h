#ifndef AS5600_H
#define	AS5600_H

#include <stdint.h>

#define DEVICE_ADDRESS  0x36
void AS5600_Init(void);
float AS5600_GetAngle(void);
uint8_t AS5600_GetStatus(void);
uint8_t AS5600_GetAGC(void);
void AS5600_SetZeroPosition(void);

//Register addresses
enum {
    AS5600_ZMCO = 0x00,
    AS5600_ZPOS = 0x01,
    AS5600_MPOS = 0x03,
    AS5600_MANG = 0x05,
    AS5600_CONF = 0x07,
    AS5600_RAW_ANGLE = 0x0c,
    AS5600_ANGLE = 0x0e,
    AS5600_STATUS = 0x0b,
    AS5600_AGC = 0x1a,
    AS5600_MAGNITUDE = 0x1b,
    AS5600_BURN = 0xff
};

#endif	/* AS5600_H */

