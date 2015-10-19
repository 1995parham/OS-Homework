#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>

#include "client_net.h"
#include "constants.h"
#include "error_functions.h"
#include "message.h"

static int socket_fd = -1;
static int is_connect = 0;

int build_socket_fd(){
	if(socket_fd == -1){
		socket_fd = socket(AF_INET, SOCK_STREAM, 0);
		if(socket_fd == -1){
			error_die("socket()");
		}
		return socket_fd;
	}
}

void connect_socket(){
	if(is_connect == 0){
		build_socket_fd();

		struct sockaddr_in server_addr;
		server_addr.sin_family = AF_INET;
		server_addr.sin_addr.s_addr = inet_addr(server_ip_address);
		server_addr.sin_port = htons(server_port_number);

		if(connect(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1){
			error_die("connect()");	
		}else{
			is_connect = 1;
		}
	}
}

int send_message(Message* message){
	connect_socket();
	
	char buffer[MAX_BUFF];
	
	strcpy(message->client_name, client_name); 

	serialize_message(buffer, message);

	return send(socket_fd, buffer, strlen(buffer), 0);
}

int recv_message(Message* message){
	connect_socket();

	char buffer[MAX_BUFF];

	FILE* socket_file = fdopen(socket_fd, "a+");

	fgets(buffer, MAX_BUFF, socket_file);

	deserialize_message(buffer, message);

	return strlen(buffer);
}

