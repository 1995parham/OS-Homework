#include "message.h"

#ifndef CLIENT_NET_H
#define CLIENT_NET_H

char client_name[255];

char server_ip_address[255];

int server_port_number;

int build_socket_fd();

void connect_socket();

int send_message(Message* message);

int recv_message(Message* message);

#endif
