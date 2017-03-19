#include <pthread.h>
#include <string.h>
#include "errors.h"

/*Macro*/
#define MAX 1024

void async_alarm( void );
void insert( char *);
void delete( void ); 

typedef struct my_struct_tag {
	pthread_mutex_t mutex;
	pthread_cond_t cond1;
	pthread_cond_t cond2;
	struct alarm **head;
}my_struct_tag;

struct alarm {
	char message[128];
	int seconds;
	struct alarm *link;
};

struct alarm *start = NULL, *temp, *t, *fnode;

my_struct_tag data = {PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER, PTHREAD_COND_INITIALIZER, &start};

int main( void )
{
	char line[128];
	pthread_t t1;
	
	if(0 != (pthread_create(&t1, NULL, (void *)&async_alarm, NULL))){
		err_abort(errno, "Thread creation failed\n");
                exit(1);
	}

	while(1){
		printf("Alarm >");
		
		if (fgets (line, sizeof (line), stdin) == NULL) {
                        exit(0);
                }
                if (strlen (line) <= 1)
                        continue; 
		pthread_mutex_lock(&(data.mutex));
                insert(line);
	}
	return 0;
}

void insert( char *line )
{
	int seconds;
	char message[128];
	temp = (struct alarm *)malloc(sizeof(struct alarm));
	
	if (sscanf (line, "%d  %64[^\n]", &seconds, message ) < 2) {
                fprintf (stderr, "Bad command\n");
                return;
        }
        temp -> seconds = time(NULL) + seconds;
        strcpy(temp -> message, message);
	
	if(start == NULL) {
                temp -> link = NULL;
                start = temp;
                pthread_mutex_unlock(&(data.mutex));
                pthread_cond_signal(&(data.cond1));

        }else {
                t = start;
                if(t -> seconds > temp -> seconds) {
                        temp -> link = start;
                        start = temp;
                        pthread_mutex_unlock(&(data.mutex));
                        pthread_cond_signal(&(data.cond2));
                }
		 else {

                        while(t -> link != NULL && (t -> link -> seconds) < temp -> seconds) {
                          t = t -> link;
                        }

                        temp -> link = t -> link;
                        t -> link = temp;
                        pthread_mutex_unlock(&(data.mutex));
                }
        }
        return;
}

void delete(void)
{
        struct alarm *t;

        t = start;
        start = t -> link;
        free(t);
}

void async_alarm(void)
{

        struct timespec abs;
        int status;
        while(1) {
                pthread_mutex_lock(&(data.mutex));
                if (start == NULL) {
                        pthread_cond_wait(&(data.cond1), &(data.mutex));
                }
                abs.tv_sec = start -> seconds;
                abs.tv_nsec = 0;
                status = pthread_cond_timedwait(&(data.cond2), &(data.mutex), &abs);
                if(ETIMEDOUT == status) {
                        printf(" (%d) %s\n", start -> seconds, start -> message);
                        delete();

                }
                pthread_mutex_unlock(&(data.mutex));
        }
}

