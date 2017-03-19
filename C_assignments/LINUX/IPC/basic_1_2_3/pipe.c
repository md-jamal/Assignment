#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main( void )
{
	int pipefd[2];
	pid_t cpid;
       	char buf[20];
	char string[12] ="Global Edge";
	char ch;
	if(pipe(pipefd) != 0){
		printf("\nPipe Is Not Created");
		exit(EXIT_FAILURE);
	}
	
	cpid = fork();	/*Child Process Created*/
	
	if(cpid == -1){
		printf("Fork Is Not Executed");
		exit(EXIT_FAILURE);
	}

	if(cpid == 0){
		close(pipefd[1]);	/*Close Write File*/
	
		
		while(read(pipefd[0], &ch, 1) > 0)
			printf("Child read %c from the parent program\n",ch);
		
		close(pipefd[0]);

		exit(EXIT_FAILURE); 	
	}
	else{				/*Parent Process*/
	
		close(pipefd[0]);	/*Close Read File*/

		while(1){
			ch = getchar();
			if(ch == 27)
				break;
			write(pipefd[1], &ch, 1);
		}
		close(pipefd[1]);
		exit(EXIT_SUCCESS);
	}
	return 0;
}
