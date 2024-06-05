
#include "AS5600.h"
#include "pic18_i2c.h"

void AS5600_Init(void) {
    uint8_t reg[2];
    pic18_i2c_enable();
    pic18_i2c_read(DEVICE_ADDRESS, AS5600_CONF, reg, 2);
    reg[0] &= 0b11000000; //Set all used bits to zero
    reg[0] |= 0b00000000; //Watchdog off, Slow filter x16, Fast filter off - change as desired
    reg[1] = 0b00100000; //PWM 115Hz, Out = PWM, Hysteresis off, normal power mode
    pic18_i2c_write(DEVICE_ADDRESS, AS5600_CONF, reg, 2);
}

float AS5600_GetAngle(void) {
    uint16_t angle;
    pic18_i2c_read(DEVICE_ADDRESS, AS5600_ANGLE, (uint8_t *)&angle, 2);
    angle = (angle << 8) | (angle >> 8); //swap bytes to make little endian
    double result;
    result = angle * (360.0 / 4096.0);
    return (float)result;
}

uint8_t AS5600_GetStatus(void) {
    uint8_t status;
    pic18_i2c_read(DEVICE_ADDRESS, AS5600_STATUS, &status, 1);
    status &= 0b00111000;
    return status;
}

uint8_t AS5600_GetAGC(void) {
    uint8_t agc;
    pic18_i2c_read(DEVICE_ADDRESS, AS5600_AGC, &agc, 1);
    return agc;
}

void AS5600_SetZeroPosition(void) {
    uint8_t reg[2];
    pic18_i2c_read(DEVICE_ADDRESS, AS5600_RAW_ANGLE, reg, 2);
    pic18_i2c_write(DEVICE_ADDRESS, AS5600_ZPOS, reg, 2);
}