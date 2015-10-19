#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#include "command.h"
#include "message.h"
#include "client_net.h"
#include "error_functions.h"
#include "constants.h"

int main(int argc, char* argv[]){

	printf("Gnomovision version 69, Copyright (C) 2014 Parham Alvani (parham.alvani@gmail.com)\n");
	printf("Gnomovision comes with ABSOLUTELY NO WARRANTY; for details type `show w'.\n");
	printf("This is free software, and you are welcome to redistribute it\n");
	printf("under certain conditions; type `show c' for details.\n");
	printf("\n");

	if(argc < 4){
		use_die("usage : client server_ip_address server_port_number client_name");
	}
	
	strcpy(client_name, argv[3]);
	strcpy(server_ip_address, argv[1]);
	server_port_number = atoi(argv[2]);

	int socket = build_socket_fd();
	printf("Establishing connection....\n");
	connect_socket();
	printf("Connection established.\n");
	printf("\n");

	while(1){
		printf("Client ChatHub:> ");
		fflush(stdout);
		
		fd_set fds;
		FD_ZERO(&fds);
		FD_SET(socket, &fds);
		FD_SET(0, &fds);

		select(socket + 1, &fds, NULL, NULL, NULL);
		
		if(FD_ISSET(0, &fds)){
			char command[MAX_BUFF];
			fgets(command, MAX_BUFF, stdin);
	
			command_dispatcher(command);
		}else if(FD_ISSET(socket, &fds)){
			Message message;
			
			recv_message(&message);
			
			printf("%s [%d] : %s\n", message.client_name, message.group_id, message.arg);
		}
	}
}


