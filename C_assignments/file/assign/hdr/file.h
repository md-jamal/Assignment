/*Header File Of File_word_count */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50
/*Structure Of EH */
struct EH
{
	unsigned char e_ident[16];
	short e_type;
	short e_machine;
	int e_version;
	unsigned int e_entry;
};

void file_write(FILE * , struct EH *);

