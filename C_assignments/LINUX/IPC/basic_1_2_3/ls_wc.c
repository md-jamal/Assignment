#include<stdio.h> 
#include<sys/wait.h>                                           
#include<stdlib.h>                                                        
#include<unistd.h>                                                      
#include<string.h>                                                              
int main()                                                 
{                                                                            
    int pipefd[2];
    pid_t cpid;                                                                 
	if(pipe(pipefd) == -1){
		perror("pipe"); 
        exit(EXIT_FAILURE);
 	}
    cpid = fork();
    	if(cpid == -1) {
        	perror("fork");
       		exit(EXIT_FAILURE);
    }
                                        
    if(cpid == 0) {                                        
 		dup2(pipefd[1],1);                                       
        	close(pipefd[0]);                                             
      		execl("/bin/ls","ls", "-1", NULL);
    }                                                                  
    if(cpid != 0){                                         
	    dup2(pipefd[0],0);                                  
	    close(pipefd[1]);                                        
	    execl("/usr/bin/wc","wc","-l", NULL);                          
    }                                                                           
	return 0;
}

