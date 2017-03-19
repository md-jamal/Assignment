#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#define MAX 10000

int main(int argc, char** argv) 
{

	char arg[500];
	char request[MAX];
	char ip[40];
	struct hostent *server;
	struct sockaddr_in serveraddr;
	int port = 80;
	unsigned int j = 0;
	int i;
	int tcpSocket;

	strcpy(arg, argv[1]);				//Copying command line argument in arg

	printf("\nServer Name: %s", arg);

	if(-1 ==  (tcpSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))) {
		printf("\nError opening socket");
		exit(1);
	}

	printf("\nSuccessfully opened socket");

	if(NULL == (server = gethostbyname(arg))) {

		printf("gethostbyname() failed\n");
		exit(1);
	}

	printf("\nserver name %s = ", server->h_name);

	strcpy(ip, (inet_ntoa(*(struct in_addr **)(server -> h_addr_list[j]))));

	printf("ip : %s\n", ip);

	serveraddr.sin_family = AF_INET;

	serveraddr.sin_addr.s_addr = inet_addr(ip);

	serveraddr.sin_port = htons(port);

	printf("Connecting : \n");
	if (-1 == (connect(tcpSocket, (struct sockaddr *) &serveraddr, sizeof(serveraddr))))  {
		printf("\nError Connecting");
		exit(1);	
	}
	printf("\nSuccessfully Connected");

	strcpy(request, "GET / HTTP/1.1\r\n");
	strcat(request,"Host: ");
	strcat(request, arg);
	strcat(request, "\r\n\r\n");

	printf("\nRequest : %s", request);

	if (-1 == (send(tcpSocket, request, MAX , 0)))
		printf("Error with send()");
	else
		printf("Successfully sent html fetch request");
	printf("Request sent");

	if(-1 == (recv(tcpSocket, request, MAX, 0))) {
		perror("recv failed");
	}
	printf("\nResponse : %s\n", request);

	close(tcpSocket);

	return 0;
}
