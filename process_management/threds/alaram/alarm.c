#include<stdlib.h>
#include<string.h>
#include<stdio.h>
//# include "error.h"

int main (int argc,char *argv[] )
{
	int seconds=5 ,stat;
	char line[120] = {"Pritam"};
	char message[64] = {"Yogesh"};
	pid_t pid,w;
	int status = 2;
	while(1) {
		printf("alarm> ");
		if (fgets (line,sizeof (line), stdin)==NULL) exit (0);
		if (strlen (line) <= 1) continue;
	
		if (sscanf (line, "%d %64[^\n]",&seconds,message) > 2) {
			fprintf(stderr, "Bad command\n");
		}
		else {
			pid = fork();	
					
			if(pid == 0 )
			{
				sleep (10);
				wait(&status);
				printf ("(%d) %s \n",seconds,"Child");
				exit(0);
			}
			else
			{
				 sleep (5);
                                printf ("(%d) %s \n",seconds,"Parent");
			}
		}
	//	exit(0);
	}
}



