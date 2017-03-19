#include "fcntl.h"           /* For O_* constants */
#include "sys/stat.h"        /* For mode constants */
#include "mqueue.h"
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#define MAX 50
int main( void ) 
{
	mqd_t q1;
	char *send_msg = NULL;
	char *recv_msg = NULL;
	struct mq_attr *attr1;
    attr1 = malloc(sizeof(struct mq_attr));
	send_msg = malloc(10*sizeof(char));	
	recv_msg = malloc(10*sizeof(char));

	q1 = mq_open("/test_q",O_RDWR);
	
	if(q1 == -1) 
	{
 		printf("Error");
	}
	while(1){
	
	printf("Enter The send Message");
	fgets(send_msg,MAX,stdin);
	mq_send(q1,send_msg,strlen(send_msg),1);
	
    mq_getattr(q1, attr1);

	
	if(-1 ==  mq_receive(q1,recv_msg,attr1->mq_msgsize,NULL))
			perror("mq failed");

    printf("\nReceived Message = %s\n",recv_msg);
	}
	free(send_msg);
	free(recv_msg);
	return 0;
}
