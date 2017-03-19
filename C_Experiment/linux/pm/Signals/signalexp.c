
#include "errors.h"
#include <signal.h>

void my_sig_handler(int sig)
{
	if(sig == SIGUSR1) 
		printf("Signal Received\n");
	if (sig == SIGUSR2) {
		printf ("signal 2 received\n");
	}
}

int main(void)
{
	signal(SIGUSR1, my_sig_handler);
	signal(SIGUSR2, my_sig_handler);
	kill(getpid(), SIGUSR1);
	kill(getpid(), SIGUSR2);
	printf("HELLO\n");
	return 0;
}
