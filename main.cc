#include "inc/CanComm.h"
#include "inc/RmdControl.h"

CanComm Can;


void get_data()
{
    while(1){
        double angle1 =-1;
        uint8_t rx_data[8];
        uint16_t ID;
        uint8_t type;
        size_t length;
        Can.ReadCanMsg(&ID, rx_data, &length);
        if (ID!= 0){
            printf("ID = %d msg =", ID);
            for (int i =0; i<8; i++)
            {
	            printf("%d ,", rx_data[i]);
	        }
            printf("\n");
        }
        usleep(1000);
    }
}


int main()
{
    RmdControl RMD;

    std::cout << "Trying to connect to Can port" << std::endl;
    //Can.Connect("192.168.0.100");

    Can.CanInit("can0");
    usleep(1000000);
    uint8_t data[8];
    //RMD.GenBufSetZero(data);
    std::thread t1(get_data);
    RMD.GenBufPositionControl(-27000, data);
    Can.SendCanMsg(RMD.SteerMotorId2, data, 8 , 1);
    Can.SendCanMsg(RMD.SteerMotorId1, data, 8 , 1);
    Can.SendCanMsg(RMD.SteerMotorId3, data, 8 , 1);
    Can.SendCanMsg(RMD.SteerMotorId4, data, 8 , 1);

    usleep(2000000);

    RMD.GenBufPositionControl(0, data);
    Can.SendCanMsg(RMD.SteerMotorId2, data, 8 , 1);
    Can.SendCanMsg(RMD.SteerMotorId1, data, 8 , 1);
    Can.SendCanMsg(RMD.SteerMotorId3, data, 8 , 1);
    Can.SendCanMsg(RMD.SteerMotorId4, data, 8 , 1);

    usleep(2000000);

    Can.Close();
    t1.detach();
    return 0;

}
