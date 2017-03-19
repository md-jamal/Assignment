#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

/* Type for a 16-bit quantity.  */                                              
typedef uint16_t Elf32_Half;                                                    
                                                    
                                                                                
/* Types for signed and unsigned 32-bit quantities.  */                         
typedef uint32_t Elf32_Word;                                                    
typedef int32_t  Elf32_Sword;                                                   
                                 
/* Types for signed and unsigned 64-bit quantities.  */                         
typedef uint64_t Elf32_Xword;                                                   
typedef int64_t  Elf32_Sxword;                                                  
                                                                                                                                 /* Type of addresses.  */                                                       
typedef uint32_t Elf32_Addr;                                                    

                                                                                
/* Type of file offsets.  */                                                    
typedef uint32_t Elf32_Off;                                                     
                                                     
                                                                                
/* Type for section indices, which are 16-bit quantities.  */                   
typedef uint16_t Elf32_Section;                                                 

#define EI_IDENT 16
typedef uint32_t Elf32_Addr;
typedef uint32_t Elf32_Off;

typedef struct {
	unsigned char magic_number[EI_IDENT];
	uint16_t obj_file_type;
	uint16_t file_arch;
	uint32_t file_version;
	Elf32_Addr virtual_address;
	Elf32_Off prog_header_offset;
	Elf32_Off section_header_offset;
	uint32_t file_processor_flags;
	uint16_t ELF_header_size;
	uint16_t prog_header_size;
	uint16_t header_entries;
	uint16_t sec_header_size;
	uint16_t section_entries;
	uint16_t section_header_index;
}ELF32_Eheader;

#define EI_MAG0 0
#define ELFMAG0 0X7F
#define EI_MAG1 1
#define ELFMAG1 'E'
#define EI_MAG2 2
#define ELFMAG2 'L'
#define EI_MAG3 3
#define ELFMAG3 'F'

#define EI_CLASS 4
#define ELFCLASSNONE 0                           
#define ELFCLASS32 1                                     
#define ELFCLASS64 2

#define EI_DATA 5
#define ELFDATANONE 0
#define ELFDATA2LSB 1
#define ELFDATA2MSB 2

#define EI_VERSION 6
#define EV_NONE 0
#define EV_CURRENT 1

#define EI_OSABI    7                            
#define ELFOSABI_NONE       0                           
#define ELFOSABI_SYSV       0           
#define ELFOSABI_LINUX      1         
#define ELFOSABI_SOLARIS    2                     
#define ELFOSABI_ARM        3                                   
#define ELFOSABI_STANDALONE 4      
                                                                                
#define EI_ABIVERSION   8                                 
                                                                                
#define  ET_NONE 0
#define  ET_REL  1
#define  ET_EXEc 2
#define  ET_DYN  3
#define  ET_CORE 4

#define EM_NONE  0
#define EM_M32   1
#define EM_SPARC 2
#define EM_386   3
#define EM_68k   4
#define EM_88k   5
#define EM_860   6
#define EM_ARM   7

#define EV_NONE 0
#define EV_CURRENT 1


typedef struct                                                                  
{                                                                               
	 Elf32_Word    sh_name;        /* Section name (string tbl index) */           
	 Elf32_Word    sh_type;        /* Section type */                              
	 Elf32_Word    sh_flags;       /* Section flags */                             
	 Elf32_Addr    sh_addr;        /* Section virtual addr at execution */         
	 Elf32_Off sh_offset;      /* Section file offset */                           
	 Elf32_Word    sh_size;        /* Section size in bytes */                     
	 Elf32_Word    sh_link;        /* Link to another section */                   
	 Elf32_Word    sh_info;        /* Additional section information */            
	 Elf32_Word    sh_addralign;       /* Section alignment */                     
	 Elf32_Word    sh_entsize;     /* Entry size if section holds table */         
} Elf32_Shdr;

ELF32_Eheader *elf_header();
int elf_section_header(ELF32_Eheader *);
