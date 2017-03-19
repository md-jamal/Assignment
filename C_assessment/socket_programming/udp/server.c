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
	struct sockaddr_in addr, caddr;
	char buf[MAX];
	int addrlen;

	addr.sin_family = AF_INET;
	addr.sin_port = htons(6000);
	addr.sin_addr.s_addr = inet_addr("0.0.0.0");

	addrlen = sizeof(addr);
	if(-1 == (sockfd = socket(AF_INET, SOCK_DGRAM, 0))) {
		perror("socket creation failed\n");
		exit(1);
	}

	if(-1 == bind(sockfd, (struct sockaddr*)&addr, sizeof(addr))){
		perror("bind failed\n");
		exit(1);
	}
	addrlen = sizeof(addr);
/*	while(1) {
*/
		recvfrom(sockfd, buf, sizeof(buf),0,(struct sockaddr*)&caddr, &addrlen);
		printf("Client address : %u", htonl(caddr.sin_addr.s_addr));
		printf("Client port : %u", htons(caddr.sin_port));
		printf("Received data : %s\n", buf);

//		sleep(1);

		printf("Enter data to sent : ");
		if(NULL == fgets(buf, MAX, stdin)) {
			perror("fgets failed\n");
		}

		sendto(sockfd, buf, sizeof(buf), 0,(struct sockaddr*)&caddr, sizeof(addr));
//}
	close(sockfd);
	return 0;
}	
