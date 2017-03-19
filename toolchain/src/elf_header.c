#include"elf_header.h"

ELF32_Eheader *elf_header( void )
{
	int i;
	FILE *fp;
	ELF32_Eheader Eheader;
	ELF32_Eheader *ptr = &Eheader;

	if(NULL == (fp = fopen("a.out","r"))){
		perror("file open failed\n");
		exit(0);
	}
	if((fread(&Eheader, 52, 1, fp))<0){
		printf("can't read from a file\n");
		exit(0);
	}
	printf("MY ELF HEADER:\n");
	printf("magic:\t");
	for(i = 0; i< EI_IDENT; i++)
		printf("%4x", Eheader.magic_number[i]);
	printf("\n");

	printf("Class:\t\t\t\t\t");
	switch(Eheader.magic_number[4]){
		case 0:
			printf("%s\n","Invalid Class");
			break;
		case 1: 
			printf("%s\n","ELF32");
			break;
		case 2: 
			printf("%s\n","ELF64");
	}

	printf("Data:\t\t\t\t\t");
	switch(Eheader.magic_number[5]){
		case 0:
			printf("%s\n", "none");
			break;
		case 1: 
			printf("%s\n", "2's Complement, Little Endian");
			break;
		case 2: 
			printf("%s\n", "2's complement, Big Endian");
			break;
	}

	printf("Version:\t\t\t\t");
	switch(Eheader.magic_number[6]){
		case 0:
			printf("%s\n", "none");
			break;
		case 1:
			printf("%s\n", "1 (current)");
			break;
	}

	printf("OS/ABI:\t\t\t\t\t");
	switch(Eheader.magic_number[7]){
		case 0: 
			printf("%s\n", "UNIX - SYSTEM V");
			break;
		case 1:
			printf("%s\n", "LINUX ABI");
			break;
		case 2:
			printf("%s\n", "SOLARIS ABI");
			break;
		case 3:
			printf("%s\n", "ARM architecture ABI");
			break;
		case 4:
			printf("%s\n", "Stand - alone ABI");
			break;
	}

	printf("ABI VERSION:\t\t\t\t");
	printf("%d\n", Eheader.magic_number[8]);

	printf("Type:\t\t\t\t\t");
	switch(Eheader.obj_file_type){
		case 0:
			printf("%s\n", "Unknown file");
			break;
		case 1:
			printf("%s\n", "REL (relocatble file)");
			break;
		case 2: 
			printf("%s\n", "EXEC (executable file)");
			break;
		case 3:
			printf("%s\n", "shared object file");
			break;
		case 4: 
			printf("%s\n", "core file");
			break;
	}

	printf("Machine:\t\t\t\t");
	switch(Eheader.file_arch){
		case 0: 
			printf("Unknown machine\n");
			break;
		case 1: 
			printf("AT&T WE 32100\n");
			break;
		case 2:
			printf("Sun Microsystems SPARC\n");
			break;
		case 3:
			printf("Intel 30386\n");
			break;
		case 4: 
			printf("Motorola 68000\n");
			break;
		case 5:
			printf("Motorola 88000\n");
			break;
		case 6:
			printf("Intel 80860\n");
			break;
		case 7:
			printf("Advanced RISC architecture\n");
			break;
	}

	printf("Version:\t\t\t\t");
	switch(Eheader.file_version){
		case 0:
			printf("NONE");
			break;
		case 1:
			printf("0x%X\n", 1);
			break;
	}

	printf("Entry point Address:\t\t\t");
	printf("0x%X\n", Eheader.virtual_address);

	printf("Start of program headers:\t\t");
	printf("%d (bytes into file)\n", Eheader.prog_header_offset);

	printf("Start of section headers:\t\t");
	printf("%d (bytes into file)\n", Eheader.section_header_offset);

	printf("FLAGS:\t\t\t\t\t");
	printf("0x%x\n", Eheader.file_processor_flags);

	printf("Size of this header:\t\t\t");
	printf("%d (bytes)\n", Eheader.ELF_header_size);

	printf("Size of program headers:\t\t");
	printf("%d (bytes)\n", Eheader.prog_header_size);

	printf("Number of program headers:\t\t");
	printf("%d\n", Eheader.header_entries);

	printf("size of section headers:\t\t");
	printf("%d (bytes)\n", Eheader.sec_header_size);

	printf("number of section headers:\t\t");
	printf("%d\n", Eheader.section_entries);

	printf("Section header string table index:\t");
	printf("%d\n", Eheader.section_header_index);
	

	return ptr;
}
	
