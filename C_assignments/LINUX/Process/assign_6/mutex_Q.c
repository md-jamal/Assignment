#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

 
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

struct que
{
	int data;
	struct que *next;
}*fr = NULL, *rr = NULL;

struct que *create_node(int d)
{
	struct que *new = NULL;
	new = (struct que *)malloc(sizeof(struct que));
	new->data = d;
	new->next = NULL;
	return new;
}
void insert(int d)
{
	struct que *new = create_node(d);
	if(fr == NULL)
		fr = new;
	else
		rr->next = new;
	rr = new;
}

void rm_q()
{
	struct que *p = fr;
	if(fr == NULL)
		return;
	if(fr == rr)
		fr = rr = NULL;
	else
		fr = fr->next;
	free(p);
}

void *counting_fun(void *arg)
{
	struct que *p = fr;
	int offset = *(int *)arg;

	printf("Queue Data%d\n",(p->data) + offset);
	sleep(5);
	rm_q();
}
int main( void )
{
	/*Spawn Threads*/
	pthread_t id1;
	int offset1 = 1;
	int data;
	
	while(1)
        {
		//pthread_mutex_lock(&mutex);
                printf("Enter The Data:");
                scanf("%d",&data);
                if(data == -1)
                        break;
                insert(data);
		pthread_mutex_unlock(&mutex);
	
		pthread_create(&id1, NULL, counting_fun, &offset1);
        }

	pthread_create(&id1, NULL, counting_fun, &offset1);
	/*Waiting For Thread Complete*/ 
	pthread_join(id1, NULL);
	
	return 0;
}
