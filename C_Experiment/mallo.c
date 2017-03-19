#include<stdio.h>
#include<stdlib.h>

int main ( void )
{
	int *ptr = ( int * ) malloc (0);
	int *ptr1 = ( int * ) malloc (0);
	printf (" ptr = %p\n",ptr);
	printf (" ptr1 = %p\n",ptr1);	
	
	int *ptr3 = ( int *)malloc ( 0 );
	printf ("ptr3 = %p\n",ptr3);
	free(ptr);
	free(ptr1);
    free(ptr3);		
	printf ("f ptr = %x\n",*(ptr));
	printf ("f ptr1 = %x\n",*(ptr1));
	printf ("f ptr3 = %x\n",*(ptr3));
	return 0;
}
