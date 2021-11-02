#include "../inc/CanComm.h"

void CanComm::CanInit(const std::string& port)
{
	struct sockaddr_can addr;
	struct ifreq ifr;
	const char *ifname = "can0";

	int can_sock = socket(PF_CAN, SOCK_RAW, CAN_RAW);
	if (can_sock == -1){
        std::cout<<"Error while opening CAN socket" << std::endl;
		return;
    }
    std::cout<<"Success to create CAN socket" << std::endl;

	strcpy(ifr.ifr_name, ifname);
	ioctl(can_sock, SIOCGIFINDEX, &ifr);

	addr.can_family = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;

	if (bind(can_sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		std::cout<<"Fail to bind can socket"<< std::endl;
		return;
	}
    std::cout<<"Success to bind CAN socket" << std::endl;

	can_port = can_sock;
	port_opened_ = true;
}

int CanComm::SendCanMsg(uint32_t can_id, uint8_t *send_buffer, uint8_t size, uint8_t type)
{
    if(!port_opened_)
    {
    	std::cout<<"CAN port not opened" << std::endl;
        return -1;
    }	
	struct can_frame frame;
	uint32_t tx_id;
    switch(type)
    {
        case 1: // Can Standard Frame
            tx_id = can_id;
            break;
        case 2: // Remote Transmission Request
            tx_id = can_id + CAN_RTR_FLAG;
            break;
        case 3: // Can Extended Data Frame
            tx_id = can_id + CAN_EFF_FLAG;
            break;
        default:
            printf("Error with CAN Data Type");
            return -1;
    }
	frame.can_id = tx_id & 0x7FF;
	frame.can_dlc = size;
	for (int i =0; i<8; i++) {
	frame.data[i] = send_buffer[i];
	}
	int tx_bytes = ::write(can_port, &frame,sizeof(struct can_frame));
	return tx_bytes;
}

int CanComm::ReadCanMsg(uint32_t *can_id, uint8_t *send_buffer, uint8_t *size, uint8_t *type)
{
    if(!port_opened_)
    {
    	std::cout<<"CAN port not opened" << std::endl;
        return -1;
    }
	struct can_frame rx_frame;
	int rx_bytes = ::read(can_port, &rx_frame,sizeof(struct can_frame));
	*can_id = rx_frame.can_id;
	*size = rx_frame.can_dlc;
	for (int i =0; i<8; i++) {
	send_buffer[i] = frame.data[i];
	}

	frame.can_id = can_id & 0x7FF;
	frame.can_dlc = size;
	return rx_bytes;

}