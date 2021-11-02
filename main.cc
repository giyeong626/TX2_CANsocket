#include "inc/CanComm.h"



void get_data()
{
    while(1){
        double angle1 =-1;
        //Can.GetRMDAngle(Can.SteerMotorId1, &angle1);
        printf(" angle1 = %f\n", angle1);
    }
}


int main()
{
    CanComm Can;

    std::cout << "Trying to connect to Can port" << std::endl;
    //Can.Connect("192.168.0.100");

    Can.CanInit("can0");
    //Can.PurgeFirstByte();
    //Can.ResetCan();
    //Can.SteerMotorSetPid();
    return 0;

}
