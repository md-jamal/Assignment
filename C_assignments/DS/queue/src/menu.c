#include"que.h"
/*Show Menu*/
int opt( void )
{
	int opt_ch = 0;
	printf("\n\n\n.............Queue........");
	printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n..Choose Option:");
	opt_ch = valid();	
	printf("\n");
	
	return opt_ch;
}
