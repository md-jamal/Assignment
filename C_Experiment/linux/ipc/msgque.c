#include <stdio.h>
#include <mqueue.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#define MAX 15

int main(void)
{
	pid_t pid;
	mqd_t mqd;
	char name[MAX] = "/myque";
	char buf[MAX] = "Hello World";
	char buf2[MAX];
	struct mq_attr *mq;

	if(NULL ==(mq = (struct mq_attr *)malloc(sizeof(struct mq_attr)))) {
		perror("malloc failed\n");
		exit(1);
	}

	if(-1 == (mqd = mq_open(name, O_RDWR | O_CREAT, 00006, NULL ))) {
		perror("creating msg queue failed");
		mq_unlink(name);
		exit(1);
	}
	
	mq_getattr(mqd, mq);
	pid = fork();
	
	if(pid > 0) {
		printf("Parent\n");
		if(-1 == mq_send(mqd, buf, MAX, 1)) {
			perror("Message Sending failed\n");
			exit(1);
		}
		printf("Sent msg : %s\n : ", buf);
		wait(NULL);

	} else if(pid == 0) {
		printf("Child\n");
		getchar();
		if(-1 == mq_receive(mqd, buf2, mq -> mq_msgsize, NULL)) {
			perror("Receive failed\n");
			exit(1);
		}
		write(1, "Received message : ",20);
		write(1, buf2, strlen(buf2));
	} else {
		perror("fork failed\n");
		exit(1);
	}
	mq_unlink(name);
	return 0;
}
