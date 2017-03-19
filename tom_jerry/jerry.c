#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <error.h>

/*Macro*/
#define MAX 50

#define JERRY "/dev/mqueue"

#define MAX_MESSAGES 10
#define MAX_MSG_SIZE 256
#define MSG_BUFFER_SIZE MAX_MSG_SIZE + 10
#define QUEUE_PERMISSIONS 0666

int main( void )
{
	mqd_t q_tom;

	struct mq_attr attr;

	char *sendmsg = NULL, *recvmsg = NULL;
    	attr.mq_flags = 0;
    	attr.mq_maxmsg = MAX_MESSAGES;
    	attr.mq_msgsize = MAX_MSG_SIZE;
    	attr.mq_curmsgs = 0;

	if(NULL == (sendmsg = (char *)malloc(sizeof(char *) * MAX)))
	{
		printf("\nMalloc Failed");
		exit(1);
	}

	if(NULL == (recvmsg = (char *)malloc(sizeof(char *) * MAX)))
        {
                printf("\nMalloc Failed");
                exit(1);
        }
	
	if ((q_tom = mq_open (JERRY, O_RDWR | O_CREAT | O_EXCL, QUEUE_PERMISSIONS, &attr)) == -1) {
     		if((q_tom = mq_open (JERRY, O_RDWR))== 1){
			printf("\nTom:Queue Not Created");
			exit(1);
		}
    	}
	recvmsg = " ";
	sendmsg = " ";
	
	//while(strcmp(recvmsg,"stop")){

		mq_receive (q_tom, recvmsg, MSG_BUFFER_SIZE, NULL);
		
		printf("\n%s",recvmsg);

		//fgets(sendmsg, MAX, stdin);
	
		//mq_send(q_tom, sendmsg, strlen(sendmsg), 0);

	//}
	printf("Communication Ended\n");
	
	return 0;
}

