/*
 *		Programe : File Open Programe
 *  	Author   : Pritam Mali.
 *  	Date	   : 15 DEC 2016
 */
#include <stdio.h>
#include <string.h>
/*Main Function*/

#if EX1
int main()
{
	/*Variables*/

	FILE *fptr = NULL,*fptr1;		/*File Pointer To keep information of file*/
	 float temp=10;    /*Temporary Number*/
     	float f=111.0;
	float _f;
	float _temp;
	fptr = fopen("temp.txt","wb");
	
	fprintf(fptr,"%f %f",temp,f);
	fscanf(fptr,"%f%f",&_temp,&_f);
	printf("temp%f f:%f",_temp,_f);				/*To write Data to file Ascii Format*/
//	printf("Pritam%d",fwrite(fptr1, sizeof("abc"), 2, fptr)); 

	fclose(fptr);
}
#endif

#if EX2
int main()                                                                      
{                                                                               
    /*Variables*/                                                               
                                                                                
    FILE *fptr = NULL;      /*File Pointer To keep information of file*/        
    int temp_number = 10;    /*Temporary Number*/                               
    
//	fseek(fptr, -3, SEEK_CUR);                                                                            
    fptr = fopen("temp.txt","a+");                                              
                      
//	printf("%d",ftell(fptr));
                                                          
    printf("%d",fprintf(fptr,"%s%d","abc",10));                                                   
	                           
                                                                                
//   printf("Close%d:",fclose(fptr));     
//	printf("Close%d:",fileno(fptr));                                                          
}
#endif

