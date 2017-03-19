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
	int csockd;
	char buf[MAX];                                                              
	struct sockaddr_in addr;                                                    
	addr.sin_family = AF_INET;                                                  
	addr.sin_port = htons(7000);                                                        
	addr.sin_addr.s_addr = inet_addr("172.16.5.59");                            

	if(-1 == (sockd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))) {             
		perror("Socket creation failed\n");                                     
		exit(1);                                                                
	}

	if(-1 == bind(sockd, (struct sockaddr*)&addr, sizeof(addr))) {
		perror("bind failed\n");
		exit(1);
	}

	if(-1 == listen(sockd, 5)) {
		perror("listen failed\n");
		exit(1);
	}
	
	getchar();

	int len = sizeof(struct sockaddr);
	if(-1 == (csockd = accept(sockd, (struct sockaddr*)&addr, &len))) {
		perror("accept failed\n");
		exit(1);
	}

//	while(1){

		if(-1 == read(csockd, buf, sizeof(buf))) {
			perror("Read failed\n");
			exit(1);
		}

		printf("Received data :  %s\n", buf);

		if(NULL == fgets(buf, MAX, stdin)) {
			perror("fgets failed\n");
			exit(1);
		}

		if(-1 == write(csockd, buf, sizeof(buf))) {
			perror("write failed\n");
			exit(1);
		}
//	}
	return 0;
}
