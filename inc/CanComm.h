#include <chrono>
#include <thread>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <signal.h>
#include <cmath>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <sstream>
#include <array>
#include <algorithm>
#include <unistd.h>

#include <linux/can.h>
#include <linux/can/bcm.h>



#define CAN_EFF_FLAG 0x80000000U /* EFF/SFF is set in the MSB */
#define CAN_RTR_FLAG 0x40000000U /* remote transmission request */
#define CAN_ERR_FLAG 0x20000000U /* error frame */


class CanComm
{
	struct sockaddr_can addr;
	struct ifreq ifr;

public:
    void CanInit(const std::string&);
    int SendCanMsg(uint16_t can_address, uint8_t *data, size_t length, uint8_t type);
    int ReadCanMsg(uint16_t *can_address, uint8_t *data, size_t *length);
    void Close();

    int can_port;

private:
    bool port_opened_;


};
