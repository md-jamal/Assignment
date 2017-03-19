#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int g_var = 0;
int *gp_var = NULL;
int main( void )
{
	int l_var = 0;
	int *lp_var = NULL;
	pid_t ch_pid = 0;

	fclose(stdin);
	fclose(stdout);
	fclose(stderr);	
	FILE *fptr = fopen("sample.c","w");
	ch_pid = fork();

//	FILE *fptr = fopen("sample.c","w");

	int *malloc_p = NULL;
	
	malloc_p = (int *)malloc(sizeof(int));
	if (ch_pid >= 0)
	{
		if(ch_pid == 0){
			g_var = 10;
			l_var = 10;
			gp_var = &g_var;
			lp_var = &l_var;
			
			*malloc_p = 10;
			
			printf("\n malloc_parent::%d\n",*malloc_p);
			printf("\n Child Process:: G_Var:%d L_Var:%d\n",g_var, l_var);
			printf("\n Child Process:: G_Var:%p L_Var:%p\n",&g_var, &l_var);

			printf("\n Pointer Child Process:: G_Var:%d L_Var:%d\n",g_var, l_var);
                        printf("\n Pointer Child Process:: G_Var:%d L_Var:%d\n",*gp_var, *lp_var);

			fprintf(fptr,"%s","Software Limited");

		}
		else{
			g_var++;
			l_var++;
			gp_var = &g_var;
                        lp_var = &l_var;
	
			*malloc_p = 10000;

                        printf("\nmalloc_Child::%d\n",*malloc_p);


			printf("\n Parent Process:: G_Var:%d L_Var:%d\n",g_var, l_var);
			printf("\n Parent Process:: G_Var:%p L_Var:%p\n",&g_var, &l_var);
			
			printf("\n Pointer Parent Process:: G_Var:%d L_Var:%d\n",g_var, l_var);
                        printf("\n Pointer Parent Process:: G_Var:%d L_Var:%d\n",*gp_var, *lp_var);		
			
			fprintf(fptr,"%s","Global Edge");
		}
	}
	else {
		printf ("\nFork Is Failed");
	}
	return 0;
}
