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
	int sockd;
	char buf[MAX];
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(7000);
	addr.sin_addr.s_addr = inet_addr("172.16.5.59");

	if(-1 == (sockd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))) {
		perror("Socket creation failed\n");
		exit(1);
	}

	if(-1 == connect(sockd, (struct sockaddr*)&addr, sizeof(addr))) {
		perror("Connect failed\n");
		exit(1);
	}

//	while(1) {

		printf("Enter data : ");
		if(NULL == fgets(buf, MAX, stdin)) {
			perror("fgets failed\n");
			exit(1);
		}

		if(-1 == write(sockd, buf, sizeof(buf))) {
			perror("write failed\n");
			exit(1);
		}

		if(-1 == read(sockd, buf, sizeof(buf))) {
			perror("read failed\n");
			exit(1);
		}
		printf("Received data : %s\n", buf);
//	}
	close(sockd);
	return 0;
}
