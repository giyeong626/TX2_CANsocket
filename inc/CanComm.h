#include <chrono>
#include <thread>
#include <iostream>

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
#include <linux/can/raw.h>


#define CAN_EFF_FLAG 0x80000000U /* EFF/SFF is set in the MSB */
#define CAN_RTR_FLAG 0x40000000U /* remote transmission request */
#define CAN_ERR_FLAG 0x20000000U /* error frame */



class CanComm
{
public:
    void CanInit(const std::string&);
    int SendCanMsg(int32_t, uint8_t *, uint8_t, int32_t);
    

    int can_port;

private:
    bool port_opened_;



};