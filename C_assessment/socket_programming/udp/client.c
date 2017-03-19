#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> 
#define MAX 256

int main(void)
{
	int sockfd;
	struct sockaddr_in addr;
	char buf[MAX] = "global";
	int addrlen;

	addr.sin_family = AF_INET;
	addr.sin_port = htons(6000);
	addr.sin_addr.s_addr = inet_addr("172.16.5.59");

	addrlen = sizeof(addr);
	if(-1 == (sockfd = socket(AF_INET, SOCK_DGRAM, 0))) {
		perror("socket creation failed\n");
		exit(1);
	}
//	while(1) {
/*	printf("Enter data to sent : ");
	if(NULL == fgets(buf, MAX, stdin)) {
		perror("fgets failed\n");
	}*/
	sleep(1);
	if(-1 == sendto(sockfd, buf, sizeof(buf), 0,(struct sockaddr *)&addr, sizeof(addr))) {
		perror("send failed\n");
		exit(1);
	}
	recvfrom(sockfd, buf, sizeof(buf),0,(struct sockaddr*)&addr, &addrlen);
	printf("Received data : %s\n", buf);
	 printf("Client address : %u", htonl(addr.sin_addr.s_addr));            
	         printf("Client port : %u", htons(addr.sin_port));
//	}
	close(sockfd);
	return 0;
}	
