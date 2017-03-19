#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#define MAX 64
#define FGET(str) if(NULL==(fgets(str,MAX,stdin))) {\
					perror("fgets failed\n");\
					exit(1);}

#define MAL(str) if(NULL==(str=(char *)malloc(sizeof(char)*MAX))) {\
					perror("Malloc failed\n");\
					exit(1);}
//------parent and child share same local data and global data
#if exe1

int b = 20;

int main(void)


{
	pid_t pid;
	
	int a = 5;
	printf("parent process:%d\n",getpid());
	pid = fork();
	
	char *ptr = (char *)malloc(sizeof(char)*32);
	strcpy(ptr,"sandeep");
		
	
	if (pid > 0) {
		printf("----------------parent process------------------\n");
		a = a + 10;
		printf("child process:%d\n",pid);
		printf("local data of parent for a=%d\n",a);
		printf("global value of b:%d\n",b);
		b = b - 3;
		printf("global value of b modified:%d\n",b);
		printf("parent process:heap %p for %s\n",ptr,ptr);
		strcpy(ptr,"shruthi");
		printf("parent process:heap(modified) %p for %s\n",ptr,ptr);
	}
		
	else if (pid == 0) {
		a = a-3;
		printf("---------------child process--------------------\n");
		printf("child process:%d\n",pid);
		printf("local data of child for a=%d\n",a);
		printf("global value of b:%d\n",b);
		b = b - 10;
		printf("global value of b modified:%d\n",b);
		printf("parent process:heap %p for %s\n",ptr,ptr);
		strcpy(ptr,"shorty");
		printf("parent process:heap(modified) %p for %s\n",ptr,ptr);
	}
	return 0;
}

#endif

#if exe2

int main(void)

{
	pid_t pid;
	FILE *fp;
	fp = fopen("just.txt","w+");
	pid = fork();
	if (pid > 0) {
		fprintf (fp,"Global Edge");
		fclose(fp);
	}
	else if (pid == 0) {
		fprintf(fp,"Software limited\n");
		fclose(fp);
	}
	return 0;
}
#endif

#if exe3

int main(void)

{

	pid_t pid;
	int j=0;
	int i=0;
	char *argv[10];
	char *token = NULL;
	char *command = NULL;
	char * PATH =NULL;
	char *porc=NULL;
		MAL(command);
		MAL (PATH);
		MAL(token);
		MAL(proc);
		while(1) {
		i = 0;
		printf("enter command\n");
		FGET(command);
		*(command+strlen(command)-1)='\0';
		strcpy(PATH,"/bin/");
		strcpy(proc,"kill -9");
		while (*command != '\0') {
			token = strtok(command," ,\n");
			argv[i] = token;
			command = command + strlen(token);
			i++;
		}
		argv[1]=NULL;
		strcat(PATH,argv[0]);
		pid = fork();
			
		if (pid > 0) {
			printf("this is parent %d\n",getpid());
			wait(NULL);
		}
		else if (pid == 0) {
			int cpid=0;
			cpid = getpid();
			char *str	
			conv
			strcat(proc,)
			printf("this is child executing your shell command %d\n",getpid());
			execvp(PATH,argv);
			system(proc);
//			execl("./a.out","a.out",NULL);
		}
//	free(command);
//	free(token);
//	free(PATH);
	}	

	return 0;
}

char *con(char str[],int num)  
{

    int i, rem, len = 0, n;
    n = num;
	while (n != 0) {
       len++;
       n /= 10;
    }
    for (i = 0; i < len; i++) {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}

#endif
