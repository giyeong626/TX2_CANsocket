#include "../inc/CanComm.h"

void CanComm::CanInit(const std::string& port_name)
{

	int s = socket(PF_CAN, SOCK_RAW, CAN_RAW);
	if (s == -1){
        std::cout<<"Error while opening CAN socket" << std::endl;
		return;
    }

	strcpy(ifr.ifr_name, port_name.c_str());

	
	if (ioctl(s, SIOCGIFINDEX, &ifr) < 0)
	{
		std::cout<<"Error during config"<<std::endl;
		return;
	}

	addr.can_family = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;

	if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		std::cout<<"Fail to bind can socket"<< std::endl;
		return;
	}

	int fdflags = fcntl(s, F_GETFL, 0);

    if(fcntl(s, F_SETFL, fdflags | O_NONBLOCK) < 0)
    {
        std::cout << "Set Nonblock Error!!" << std::endl;
		return;
    }
    std::cout<<"Success to create CAN socket" << std::endl;

	can_port = s;
	port_opened_ = true;
}

int CanComm::SendCanMsg(uint16_t can_address, uint8_t *data, size_t length, uint8_t type)
{
    if(!port_opened_)
    {
    	std::cout<<"CAN port not opened" << std::endl;
        return -1;
    }	

	struct can_frame frame;

	ssize_t tx_bytes;

	frame.can_id = can_address; // Set Message ID
	frame.can_dlc = length; // Set DLC(length)
	
	for (int i =0; i<8; i++) {
	frame.data[i] = data[i];
	}

	tx_bytes = sendto(can_port, &frame, sizeof(struct can_frame),0, (struct sockaddr*)&addr, sizeof(addr) );
	return tx_bytes;

/*
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
    }*/
}

int CanComm::ReadCanMsg(uint16_t *can_address, uint8_t *recv_buffer, size_t *length)
{
   if(!port_opened_)
    {
    	std::cout<<"CAN port not opened" << std::endl;
        return -1;
    }
	struct can_frame rx_frame;
	socklen_t len = sizeof(addr);

	int rx_bytes = ::read(can_port, &rx_frame, sizeof(struct can_frame));

	*can_address = rx_frame.can_id;
	*length = rx_frame.can_dlc;
	recv_buffer = rx_frame.data;
//	for (int i =0; i<8; i++) {
//	recv_buffer[i] = rx_frame.data[i];
//	}
	return rx_bytes;
}

void CanComm::Close()
{
	if(close(can_port) < 0){
		printf("closed");
	}
}