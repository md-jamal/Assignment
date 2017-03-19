
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	FILE *fp;
	if(NULL == (fp = fopen("just.txt", "w+"))) {

		perror("fopen failed\n");
		exit(0);
	}

	pid = fork();
	if(pid > 0) {
		if(0 > (fprintf(fp, "Global edge"))) {
			perror("fprintf failed\n");
			exit(0);
		}
		fclose(fp);
		fprintf(fp, "abcde ");

	} else if (pid == 0) {
	
		if(0 > (fprintf(fp, "Software limited"))) {
			perror("fprintf failed\n");
			exit(0);
		}
		fclose(fp);
	} else {
		perror("fork failed\n");
		exit(0);
	}
	return 0;
}
	/* output - Global edge software limited 
	   File descriptors are also copied from parent to child so both will refer
	   to same file. Whoever gets first to execute will print it's contents,
	   then offset will be at last, so another will write from the last.
	*/

