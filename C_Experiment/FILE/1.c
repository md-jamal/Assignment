#include <stdio.h>

 

void main()

{

    FILE *fptr;
	fptr = fopen("text.txt", "w");
    char name[20];

    int age;

    float salary;
	fgetc( fptr );	
	printf("%s",fptr->_IO_read_ptr);
 

    /*  open for writing */

 //   fptr = fopen("emp.dat", " ");

	printf("%p",fptr); 

    if (fptr == NULL)

    {

        printf("File does not exists \n");

        return;

    }

    printf("Enter the name \n");

    scanf("%s", name);

//	printf("%d",fwrite(name, sizeof(name),1, fptr));

    printf("Enter the age\n");

    scanf("%d", &age);

    fprintf(fptr, "Age     = %d\n", age);

  /*  printf("Enter the salary\n");

    scanf("%f", &salary);

    fprintf(fptr, "Salary  = %.2f\n", salary);*/

//    fclose(fptr);
printf("%d",fclose(fptr));
}
