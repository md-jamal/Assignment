#include "elf_header.h"

int elf_section_header(ELF32_Eheader *ehdr)
{
	int i,index,j;
	Elf32_Shdr *shdr;

	char *buf1;	
	FILE *fp = fopen("a.out","r");

	printf("Ehdr::%d",ehdr->section_header_index);
	shdr = ( Elf32_Shdr *)malloc(sizeof( Elf32_Shdr));

	fseek(fp, ( ehdr -> section_header_offset + (/*ehdr -> sec_header_size*/40 * ehdr -> section_header_index)), SEEK_SET);
	
	fread(shdr, sizeof(Elf32_Shdr), 1, fp);
	
	buf1 = (char *)malloc(sizeof(char) * shdr -> sh_size);
	
	fseek(fp, shdr -> sh_offset , SEEK_SET);
	fread(buf1, shdr -> sh_size, 1, fp);		
	fseek(fp, ehdr -> section_header_offset, SEEK_SET);

	
	printf("\nSection Header\n\n[Nr]  Nam\t\t\t\tType\t\tAddr\t\tOff\tSize\tES\tFlag\tLk\tInf\tAl\n");
	for( i = 0; i < ehdr -> section_entries; i++) {
		fread(shdr, sizeof(Elf32_Shdr), 1, fp); 
		printf("[%d]  ", i);
		index = ( unsigned int )shdr -> sh_name;
		printf("%-14s\t\t\t",(buf1 + index));

		switch( shdr -> sh_type ) {
			case 0 :
					printf("NULL\t\t"); 
					break;
			case 1 :
					printf("PROGBITS\t");
					break;
			case 2 :
					printf("SYSTAB\t\t");
					break;
			case 3 :
					printf("STRTAB\t\t");
					break;
			case 4 :
					printf("RELA\t\t");
					break;
			case 5 :	
					printf("HASH\t\t");
					break;
			case 6 :
					printf("DYNAMIC\t\t");
					break;
			case 7 :
					printf("NOTE\t\t");
					break;
			case 8 :
					printf("NOBITS\t\t");
					break;
			case 9 :
					printf("REL\t\t");
					break;
			case 10 :
					printf("SHLIB\t\t");
					break;
			case 11 :
					printf("DYNSYS\t\t");
					break;
			case 14:
					printf("Init_Array\t");
					break;
			case 15:
					printf("Fini_Array\t");
					break;
			case 0x6fffffff:
					printf("VERSYM\t\t");
					break;
			case 0x6ffffffe:
					printf("VERNEED\t\t");
					break;
			case 0x70000000 :
					printf("LOPROC\t\t");
					break;
			case 0x7fffffff :
					printf("HIPROC\t\t");
					break;
			case 0x80000000 :
					printf("LOUSER\t\t");
					break;
			case 0xffffffff :
					printf("tHIUSER\t\t");
					break;
			case 0x6ffffff6 :
					printf("GNU_Hash\t");
					break;
			default :
					break;
		}
		printf("%08x\t", shdr -> sh_addr);
		printf("%06x\t",shdr -> sh_offset);
		printf("%06x\t",shdr -> sh_size); 
		printf("%02d\t",shdr -> sh_entsize); 
		if(!shdr -> sh_flags)
			printf("\t");

		else {
			switch(shdr -> sh_flags) {
				case 1 : printf("W\t");
							break;
				case 2 : printf("A\t");
							break;
				case 3 : printf("WA\t");
							break;
				case 4 : printf("X\t");
							break;
				case 5 : printf("M\t");
							break;
				case 6 : printf("AX\t");
							break;
				case 48 :
						 printf("MS\t");
							break;
				default : 
						printf("\t");
						break;
			}
	}
		printf("%d\t",shdr -> sh_link); 
		printf("%d\t", shdr -> sh_info); 
		printf("%d\n", shdr -> sh_addralign); 
	}

	fclose(fp);
}
