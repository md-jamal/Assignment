#include<stdio.h>
#include<pthread.h> 
#include<string.h>
#include<sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>
#define _GNU_SOURCE     

#if exe1
//int a =10;
void *thread_function(void *p)
{
//	a =  a + 15;
	printf("a thread tgid 0:%d     tid: %d\n",getpid(),syscall(SYS_gettid));
	getchar();

}	

void *thread_function1(void *p)
{
//	a =  a + 15;
	printf("a thread tgid 1:%d     tid: %d\n",getpid(),syscall(SYS_gettid));
	getchar();

}	

void *thread_function2(void *p)
{
//	a =  a + 15;
	printf("a thread tgid 2:%d     tid: %d\n",getpid(),syscall(SYS_gettid));
	getchar();

}	
void *thread_function3(void *p)
{
//	a =  a + 15;
	printf("a thread tgid 3:%d     tid: %d\n",getpid(),syscall(SYS_gettid));
	getchar();

}
	
	int main(void)
{	
	pid_t pid;
	int status;
	pthread_t th_id;
		
	status = pthread_create(&th_id,NULL, thread_function, NULL);   // 0-upon sucess; error number for error
	 pthread_create(&th_id,NULL, thread_function1, NULL);   // 0-upon sucess; error number for error
	pthread_create(&th_id,NULL, thread_function2, NULL);   // 0-upon sucess; error number for error
	 pthread_create(&th_id,NULL, thread_function3, NULL);   // 0-upon sucess; error number for error
	if (status != 0){
		printf("thread failed: %s\n",strerror(status));
	}
	printf("process tgid %d    tid:  %d\n",getpid(),syscall(SYS_gettid));
//	printf("before thread %d\n",a);
	getchar();
//	printf("after  thread %d\n",a);
	pthread_exit(NULL);
	return 0;
}

#endif

#if exe2

void *thread_func(void *p)
{
        printf("thread tgid 2 %d    tid:  %ld\n",getpid(),syscall(SYS_gettid));   
		return NULL;
}







void *thread_function(void *p)                                                  
{  
	pid_t pid;                                                                  
    printf("before fork thread 1 tgid :%d     tid: %ld\n",getpid(),syscall(SYS_gettid));    
	pid = fork();
	if (pid > 0)
	printf( "thread 1   tgid:%d  tid: %ld\n",getpid(),syscall(SYS_gettid));                                                            
	else if (pid == 0) {
		printf( "child process created in thread  tgid:%d  tid: %ld\n",getpid(),syscall(SYS_gettid));                                         
       	int status1;                                                                 
    	pthread_t th_id1;                                                            
    	status1 = pthread_create(&th_id1,NULL, thread_func, NULL);   // 0-upon sucess; error number for error
        if (status1 != 0){                                                       
            printf("thread failed: %s\n",strerror(status1));                     
        }                                                                       
    	return NULL;
	}       
	return NULL; 
}    

int main(void)

{	
	pid_t pid;
	int status;
	pthread_t th_id;
	pid = fork();	
	if (pid>0)
	printf("process tgid %d    tid:  %ld\n",getpid(),syscall(SYS_gettid));	
	else if(pid == 0){	
	printf("fork creataed process %d\n",getpid());
	status = pthread_create(&th_id,NULL, thread_function, NULL);   // 0-upon sucess; error number for error
		if (status != 0){
			printf("thread failed: %s\n",strerror(status));
		}
	}
	pthread_exit(NULL);
	
	return 0;
}
#endif

#if exe3

//int a = 15;
void *thread_function(void *p)                                                 
{                                                                               
//	a =  a + 10;                                                                
    printf("a thread tgid 3:%d     tid: %d\n",getpid(),syscall(SYS_gettid));    
 // printf("a after : %d\n",a);     
	printf("str before :%s\n",(char*)p);
	strcpy(p, "shruthi");                         
 //  	*p  = *p + 5;   
//	printf("p:%p\n",p);                          
    return NULL;                                                                            
} 
int main(void)                                                                  
                                                                                
{   
//	int s = 10;
//	int *ptr = &s;                                                                            
    pid_t pid; 
	char * str = (char *)malloc(sizeof(char)*32);      
	strcpy(str, "sandeep");                                                           
    int status;                                                                 
    pthread_t th_id;                                                            
    printf("process tgid %d    tid:  %ld\n",getpid(),syscall(SYS_gettid));      
//    printf("a before : %d\n",a);                              
    status = pthread_create(&th_id,NULL, thread_function,str);   // 0-upon sucess; error number for error
        if (status != 0){                                                       
            printf("thread failed: %s\n",strerror(status));                     
        }
  //  printf("s before : %d   addr:%p\n",*ptr,ptr);                              
	getchar();                                                                       
    printf("str after %s\n",str);                                                                           
//    printf("p after : %d\n",*ptr);                              
// 	printf("a after : %d\n",a);                              
    pthread_exit(NULL);                                                         
                                                                                
    return 0;                                                                   
}                                                                               
#endif  


#if exe4
void *thread_function(void *p)                                                  
{                                                                               
    printf("a thread tgid 3:%d     tid: %d\n",getpid(),syscall(SYS_gettid));    
    fprintf((FILE *)p,"software limited");
	fclose(p);
	return NULL;                                                                
}                                                                               
int main(void)                                                                  
                                                                                
{                                                                               
    pid_t pid;                                                                  
    int status;                                                                 
    pthread_t th_id;                                                            
    printf("process tgid %d    tid:  %ld\n",getpid(),syscall(SYS_gettid));      
	FILE *fp;
	fp = fopen("just.txt","w+");
    status = pthread_create(&th_id,NULL, thread_function,fp);   // 0-upon sucess; error number for error
        if (status != 0){                                                       
            printf("thread failed: %s\n",strerror(status));                     
        }
	fprintf(fp,"global edge");                                                                       
//    fclose(fp);
	getchar();                                                                  
    pthread_exit(NULL);                                                         
                                                                                
    return 0;                                                                   
}                                                                               
#endif      

#if exe5                                                                        
void *thread_function(void *p)                                                  
{                                                                               
    printf("a thread tgid 3:%d     tid: %d\n",getpid(),syscall(SYS_gettid));    
    return NULL;                                                                
}                                                                               
int main(void)                                                                  
                                                                                
{                                                                               
    pid_t pid;                                                                  
    int status;    
	int s;                                                             
    pthread_t th_id;                                                           
	pthread_attr_t  attr;
	int prio = 87;
	struct sched_param policy;
	s  = pthrtead_attr_init(&attr); 
	pthread_attr_setscope(&attr,PTHREAD_SCOPE_SYSTEM);
	pthread_attr_setschedpolicy(&attr, SCHED_FIFO); 	
	policy.sched_priority =
    printf("process tgid %d    tid:  %ld\n",getpid(),syscall(SYS_gettid));      
    status = pthread_create(&th_id,NULL, thread_function,fp);   // 0-upon sucess; error number for error
        if (status != 0){                                                       
            printf("thread failed: %s\n",strerror(status));                     
        }                                                                       
    getchar();                                                                  
    pthread_exit(NULL);                                                         
                                                                                
    return 0;                                                                   
}                                                                               
#endif    
