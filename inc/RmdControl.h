#include <chrono>
#include <thread>
#include <iostream>

class RmdControl
{
public:
    void GenBufPositionControl(int32_t angle, uint8_t*buf);
    void GenBufSetZero(uint8_t*buf);


    uint16_t SteerMotorId1 = 0x141;
    uint16_t SteerMotorId2 = 0x142;
    uint16_t SteerMotorId3 = 0x143;
    uint16_t SteerMotorId4 = 0x144;



private:
    uint16_t MaxSpeed = 1000;





};