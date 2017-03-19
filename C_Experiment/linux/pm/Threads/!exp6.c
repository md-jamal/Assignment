
#include <stdio.h>
#include "errors.h"

struct alarm_info {
	int seconds;
	char *message;
	struct alarm_info *link;
};

struct alarm_info *start = NULL;
struct alarm_info *temp = NULL;
struct alarm_info *handler = NULL;

void thread(void);

int main (void)
{
	int seconds;
	char message[64];
	char line[128];
	pthread_t pt;

	if (0 > pthread_create(&pt, NULL, (void *) &thread, NULL)) {
		err_abort(errno, "thread creation failed\n");
	}

	while (1) {

		printf("Alarm> ");                                                      

		if (fgets (line, sizeof (line), stdin) == NULL) {                       
			printf("\n");                                                       
			exit(1);                                                            	
		}


		if (strlen (line) <= 1) {
			continue;            
		} 

		if (NULL == start) {                                                    

			if (sscanf (line, "%d  %64[^\n]", &seconds, message ) < 2) {                
				fprintf (stderr, "Bad command\n");                                      
			} else {

				temp = (struct alarm_info *) malloc (sizeof (struct alarm_info));                 
				temp -> message = message;
				temp -> seconds = seconds;                                                
				temp -> link = NULL;                                                
				start = temp;  
			}         

		} else {     

			if (sscanf (line, "%d  %64[^\n]", &seconds, message ) < 2) {                
				fprintf (stderr, "Bad command\n");                                      
			} else { 

				handler = start;                                                    
				while (handler -> link != NULL) {                                   
					handler = handler -> link;                                      
				};                                                                  

				temp = (struct alarm_info *) malloc (sizeof (struct alarm_info));                                              
				temp -> seconds = seconds;
				temp -> message = message;
				temp -> link = NULL;                                                
				handler -> link = temp; 
			}
		}
	}
	return 0;
}

void thread(void)                                                    
{    
	while (1) {
		if (NULL == start) {
			sleep(1);
		} else {
			sleep(start -> seconds);                                                         
			printf(" (%d) %s\n", start -> seconds, start -> message);
			start = start -> link;     
		}
	}
}                                                                               

