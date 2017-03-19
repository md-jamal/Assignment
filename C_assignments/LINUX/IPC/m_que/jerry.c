#include "fcntl.h"           /* For O_* constants */
#include "sys/stat.h"        /* For mode constants */
#include "mqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
int main( void ) 
{

	mqd_t q2;
	char *recv_msg , *send_msg;
	struct mq_attr *attr1;

	attr1 = malloc(sizeof(struct mq_attr));
	recv_msg = malloc(10*sizeof(char));
    send_msg = malloc(10*sizeof(char));

	q2 = mq_open("/test_q",O_CREAT | O_RDWR,0666,NULL);
	if(q2 == -1) 
	{
		printf("Error");
	}
	
	mq_getattr(q2, attr1);
	
	while(1){
		mq_receive(q2, recv_msg, attr1->mq_msgsize, NULL);

		printf("Received Message %s\n",recv_msg);

		printf("Enter The Send Message:");
		fgets(send_msg, MAX, stdin);	

		if(-1 == mq_send(q2,send_msg,strlen(send_msg),1))
			perror("mq_send failed");

	}
	free(recv_msg);
	free(send_msg);
	return 0;
}

