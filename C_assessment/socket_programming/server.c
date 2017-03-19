/* socket programming */
/* at server side : tcp socket */

#include "errors.h"
#include <sys/types.h>
#include <sys/socket.h>			
#include <netinet/in.h>			

#define MAX 256

int main( void )
{
	int sockfd, client_sockfd;				//socket file descriptor
	struct sockaddr_in serveraddr, clientaddr;
	socklen_t len;							//length of socket
	char buf[MAX];

	serveraddr.sin_family = AF_INET;			//family of socket
	serveraddr.sin_port = 21;				//port serveress
	//ip serveraddress : inet_server -> convet dotted decimal to binary format
	serveraddr.sin_addr.s_addr = inet_addr("172.16.5.63");		

	/* creating endpoint for communication */
	if(-1 == (sockfd = socket(AF_INET, SOCK_STREAM, 0)))
		errno_abort("socket () failed ");
	else
		printf("socket created %d\n", sockfd);

	/* bind a name to socket */
	if(-1 == bind(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)))
		errno_abort("bind () failed ");
	else
		printf("binded \n");

	/* listen for connection on a socket:listen(sockfd, no. of connections ) */
	if(-1 == listen(sockfd, 0))
		errno_abort(" listen () failed ");
	else
		printf("listening \n");

	len = sizeof(clientaddr);
	/* accepting connection on socket */
	if(-1 == (client_sockfd = accept(sockfd, (struct sockaddr *) &clientaddr,
					&len)))
		errno_abort(" accept () failed ");
	else
		printf("%d connection accepted \n", client_sockfd);

	while(1) {
		read(client_sockfd, buf, sizeof(buf));			//receive from client
		
       if(strncmp("exit", buf, 4) == 0)                                            
            exit(EXIT_SUCCESS);    

		printf("server received : %s \n", buf);

		printf("Enter string : ");
		if(NULL ==  fgets(buf, MAX, stdin))                                         
	        perror("fgets () failed ");                                             
                                                                                
	    write(client_sockfd, buf, sizeof(buf));    //send to server 
	}

	close(sockfd);  

	return 0;
} //End of main ()
