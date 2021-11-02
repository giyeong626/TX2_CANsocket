#include "../inc/RmdControl.h"


void RmdControl::GenBufPositionControl(int32_t angle, uint8_t*buf)
{
    buf[0] = 0xA4;
    buf[1] = 0x00;
    buf[2] = MaxSpeed & 0xFF;
    buf[3] = (MaxSpeed >> 8) & 0xFF;
    buf[4] = angle & 0xFF;
    buf[5] = (angle >> 8) & 0xFF;
    buf[6] = (angle >>16) & 0xFF;
    buf[7] = (angle >>24) & 0xFF;
}
void RmdControl::GenBufSetZero(uint8_t*buf)
{
    buf[0] = 0x19;
    for (int i = 1; i<8; i++){
        buf[i] = 0x00;
    }
}