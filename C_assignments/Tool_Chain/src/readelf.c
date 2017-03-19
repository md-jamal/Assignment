#include"elf_header.h"

int main ( int argc, char *argv) 
{ 
	FILE *fptr = NULL;							/*File Pointer a.out*/
	int i = 0;									/*Loop Counter*/
	Elf_Ehdr elhdr;								/*Object Of Elf header*/

	if((fptr = fopen("a.out", "r+")) == NULL)
		printf("\n\nFile Is Not exits");
	else{
		fread(&elhdr, 52, 1, fptr);
		printf("\nELF Header:");
		printf("\n\tMagic:");
		for(i = 0; i < 16; i++)
			printf("%.2x  ",elhdr.e_ident[i]);

		switch(elhdr.e_ident[4]){
			case 0:
				printf("\n\tClass:\t\t\t%s","Invalid Class");
			case 1:
				printf("\n\tClass:\t\t\t%s","ELF 32-Bit");
				break;
			case 2:
				printf("\n\tClass:\t\t\t%s","ELF 64-Bit");
				break;
		}

		switch(elhdr.e_ident[5]){
			case 0:                                                             
				printf("\n\tClass:\t\t\t%s","Invalid Class");                   
				break;
			case 1:                                                           
				printf("\n\tData:\t\t\t%s","2's Compliment little endian");                     
				break;                                                         
			case 2:                                                             
				printf("\n\tData:\t\t\t%s","2's Compliment big endian");                      
				break;
		}
		switch(elhdr.e_ident[6]){
			case 0:
				printf("\n\tVersion:\t\t\t%s","Invalid Version");
				break;
			case 1:
				printf("\n\tVersion:\t\t%d %s",1,"(Current)");
				break;
		}
		printf("\n\tOS/ABI:\t\t\t%s","Unix - System V");
	/*	switch(elhdr.e_type){
			case 0:
				printf("\n\tType:\t\t\t%s","No File Type");
				break;
			case 1:
				printf("\n\tType:\t\t\t%s","Relocatable Object File");
				break;
			case 2:
				printf("\n\tType:\t\t\t%s","Executable Object File");
				break;
			case 3:
				printf("\n\tType:\t\t\t%s","Shared Object File");
				break;
			case 4:
				printf("\n\tType:\t\t\t%s","Core File");
				break;
		}*/
		printf("\n\tType:\t\t\t%u",elhdr.e_type);
		printf("\n\t");
		printf("\n");
	}
}
