#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_BUFF = 1024;

pid_t child;

void die(const char* msg);
void command_handler(const char* msg);

int main(int argc, char* argv[]){
	child = fork();
	if(child == -1){
		die("fork()");
	}else if(child == 0){	//child proccess for listening.
		struct sockaddr_in server_addr;
		server_addr.sin_family = AF_INET;
		server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
		server_addr.sin_port = htons(1373);

		int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
		if(sockfd == -1){
			die("socket()");
		}
		
		if(bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1){
			die("bind()");
		}
		
		while(1){
			struct sockaddr_in client_addr;
			socklen_t client_len = sizeof(struct sockaddr_in);
			memset(&client_addr, 0, sizeof(struct sockaddr_in));
			char buffer[MAX_BUFF];
			
			int read_size = 0;
			if((read_size = recvfrom(sockfd, buffer, MAX_BUFF, 0, (struct sockaddr*)&client_addr, &client_len)) > 0){
				buffer[read_size] = '\0';	//IMPORTANT
				char ip[INET_ADDRSTRLEN];
				printf("%s : %s", inet_ntop(AF_INET, &client_addr, ip, INET_ADDRSTRLEN), buffer);
			}else if(read_size < 0){
				die("recvfrom()");
			}
		}
	}else{	//parent proccess for sending
		int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
		if(sockfd == -1){
			die("socket()");
		}
		
		int broadcastEnable=1;
		int ret=setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable)); //Important line !!!

		struct sockaddr_in client_addr;
		client_addr.sin_family = AF_INET;
		client_addr.sin_addr.s_addr = inet_addr("255.255.255.255");
		client_addr.sin_port = htons(1373);

		while(1){
			char buffer[MAX_BUFF];

			fgets(buffer, MAX_BUFF, stdin);
			
			if(buffer[0] == '/'){
				command_handler(buffer);
			}else if(buffer[0] == 10){
				continue;	
			}else{
				if(sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&client_addr, sizeof(client_addr)) != strlen(buffer)){
					die("sendto()");
				}
			}
		}
	}
}

void die(const char* msg){
	perror(msg);
	if(child != 0){
		kill(child, SIGKILL);
	}
	exit(1);
}

void command_handler(const char* msg){
	switch(msg[1]){
		case 'q':
			kill(child, SIGKILL);
			exit(0);
			break;
		default:
			printf("Command invalid.\n");
	}
}
