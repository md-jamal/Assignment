#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/* Type for a 16-bit quantity.  */
typedef uint16_t Elf_Half;

/* Types for signed and unsigned 32-bit quantities.  */
typedef uint32_t Elf_Word;

/* Type of file offsets.  */
typedef uint32_t Elf_Off;

/* Type of addrees.  */
typedef uint32_t Elf_Addr;

/*Macro*/
#define EI_NIDENT 1
typedef struct
{
	unsigned char e_ident[EI_NIDENT];	/* Magic number and other info */
	Elf_Half	e_type;					/* Type Object file type */
	Elf_Half	e_machine;				/* Architecture */
	Elf_Word	e_version;				/* Object file version */
	Elf_Addr	e_entry;				/* Entry point virtual addre#include <stdio.h> */
	Elf_Off		e_phoff;				/* Program header table file offset */
	Elf_Off		e_shoff;				/* Section header table file offset */
	Elf_Word	e_flags;				/* Proce#include <stdio.h>or-specific flags */
	Elf_Half	e_ehsize;				/* ELF header size in bytes */
	Elf_Half	e_phentsize;			/* Program header table entry size */
	Elf_Half	e_phnum;				/* Program header table entry count */
	Elf_Half	e_shentsize;			/* Section header table entry size */
	Elf_Half	e_shnum;				/* Section header table entry count */
	Elf_Half	e_shstrndx;				/* Section header string table index */
} Elf_Ehdr;
