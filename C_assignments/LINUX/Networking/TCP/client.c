/* socket programming */
/* client program : tcp socket */

#include "errors.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX 256

int main ( void )
{
	int sockfd;
	struct sockaddr_in addr;
	char buf[MAX];

	addr.sin_family = AF_INET;
	addr.sin_port = 21;
	addr.sin_addr.s_addr = inet_addr("172.16.5.228");
	
	/* creating end point communication */
	if(-1 == (sockfd = socket(AF_INET, SOCK_STREAM, 0)))
		errno_abort(" socket () failed ");
	else
		printf("socket created::%d\n", sockfd);
	
	/* initiating a connection on socket */
	if(-1 == connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)))
		errno_abort(" connect () failed ");
	else
		printf("connected to server \n");
	
	while(1) {
		/* taking input from user */
		printf("At client : ");

		if(NULL ==  fgets(buf, MAX, stdin))
			perror("fgets () failed ");	

		write(sockfd, buf, sizeof(buf));	//send to server
		
		read(sockfd, buf, sizeof(buf));

		if(strcmp("exit", buf) == 0)
			exit(EXIT_SUCCESS);
			
		printf("server received : %s \n", buf); 
	}
	close(sockfd);
	
	return 0;
} //end of main()


