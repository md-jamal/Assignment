#include "elf_header.h"

int main( void )
{
	ELF32_Eheader *ehdr;
	ehdr = elf_header();
	printf("SSS%d:",ehdr -> sec_header_size);
	elf_section_header(ehdr);

	return 0;
}
