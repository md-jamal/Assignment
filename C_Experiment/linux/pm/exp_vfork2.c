
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int i = 50;
int main(void)
{
	int a = 10;
	int *h_var = (int *)malloc (sizeof (int));
	*h_var = 95;
	pid_t pid;
		
	printf("Org value of i : %d\nOrg value of a : %d\nOrg value of h_var : %d\n", i, a, *h_var);
	pid = vfork();
	if(pid == 0) {
		a = 20;
		i = 30;
		*h_var = 60;
		printf("Modified in child a : %d\nModified in child i : %d\nModified in child h_var : %d\n", a, i, *h_var);
		printf("vfork address : %p\n", &vfork);
		exit(0);
	} else if (pid > 0){
		printf("Value of a in parent : %u\nValue of i in parent : %d\nvalue of h_var in parent : %d\n", a, i, *h_var);
		printf("vfork address : %p\n", &vfork);
		exit(0);
	} else {
		perror("vfork failed\n");
		exit(1);
	}
}

/* Global data - if you modify in child, it will be reflected in parent
   local data - if you modify in child, parent will get reflected value only if you do exec()/exit() in child (behaviour is undefined if you
   dont do exit() or exec() in child).
   heap data - Same as local data
*/
