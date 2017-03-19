
#include "errors.h"
#include <signal.h>

void my_sign_handler(int sig)
{
	if(SIGUSR1 == sig)
		printf("Signal Received\n");
}

int main(void)
{
	struct sigaction sa;
	sa.sa_handler = my_sign_handler;

	if(sigaction(SIGUSR1, &sa, NULL) == -1) {
		errno_abort("Sigaction failed\n");
	}

	kill(getpid(), SIGUSR1);
	return 0;
}
