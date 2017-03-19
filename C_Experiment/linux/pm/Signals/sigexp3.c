
#include "errors.h"
#include <signal.h>

void my_sig_handler(int sig, siginfo_t *data, void *a)
{
	if(SIGSEGV == sig) {
		printf("Signal no : %d\n", data -> si_signo);
		printf("Error no : %d\n", data -> si_errno);
		printf("Signal code : %d\n", data -> si_code);
		printf("Address : %p\n", data -> si_addr);
		printf("Illegal Address\n");
		exit(1);
	}
}

int main(void)
{
	struct sigaction sig;
	int *p = 1123;
	sig.sa_sigaction = my_sig_handler;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGSEGV, &sig, NULL);
	printf("%d", *p);
	return 0;
}
