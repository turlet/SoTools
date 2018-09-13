#pragma once
#ifndef _ELF_H
#define _ELF_H

/* unsigned 32-bit value */
typedef unsigned int __u32;
typedef signed int __s32;
typedef unsigned long long __u64;
typedef signed long long __s64;
typedef unsigned short __u16;
typedef signed short __s16;

/* 无符号程序地址 大小4*/
typedef __u32 Elf32_Addr;
/* 无符号中等整数 大小2 */
typedef __u16 Elf32_Half;
/* 无符号文件偏移 大小4 */
typedef __u32 Elf32_Off;
/* 有符号大整数 大小4 */
typedef __s32 Elf32_Sword;
/* 无符号大整数 大小1*/
typedef __u32 Elf32_Word;

typedef __u64 Elf64_Addr;

typedef __u16 Elf64_Half;
typedef __s16 Elf64_SHalf;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
typedef __u64 Elf64_Off;
typedef __s32 Elf64_Sword;
typedef __u32 Elf64_Word;
typedef __u64 Elf64_Xword;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
typedef __s64 Elf64_Sxword;

#define EI_NIDENT 16

/* ELF Header */
typedef struct elf32_hdr {
	/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
	unsigned char e_ident[EI_NIDENT];
	Elf32_Half e_type;
	Elf32_Half e_machine;
	Elf32_Word e_version;
	/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
	Elf32_Addr e_entry;
	Elf32_Off e_phoff;
	Elf32_Off e_shoff;
	Elf32_Word e_flags;
	/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
	Elf32_Half e_ehsize;
	Elf32_Half e_phentsize;
	Elf32_Half e_phnum;
	Elf32_Half e_shentsize;
	/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
	Elf32_Half e_shnum;
	Elf32_Half e_shstrndx;
} Elf32_Ehdr;

typedef struct elf64_hdr {
	/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
	unsigned char e_ident[EI_NIDENT];
	Elf64_Half e_type;
	Elf64_Half e_machine;
	Elf64_Word e_version;
	/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
	Elf64_Addr e_entry;
	Elf64_Off e_phoff;
	Elf64_Off e_shoff;
	Elf64_Word e_flags;
	/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
	Elf64_Half e_ehsize;
	Elf64_Half e_phentsize;
	Elf64_Half e_phnum;
	Elf64_Half e_shentsize;
	/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
	Elf64_Half e_shnum;
	Elf64_Half e_shstrndx;
} Elf64_Ehdr;

/*Program Header 程序头部 结构定义*/
typedef struct elf32_phdr {
	Elf32_Word p_type;		/* segment type */
	Elf32_Off p_offset;		/* segment offset */
	Elf32_Addr p_vaddr;		/* virtual address of segment */
	Elf32_Addr p_paddr;		/* physical address - ignored? */
	Elf32_Word p_filesz;	/* number of bytes in file for seg. */
	Elf32_Word p_memsz;		/* number of bytes in mem. for seg. */
	Elf32_Word p_flags;		/* flags */
	Elf32_Word p_align;		/* memory alignment */
} Elf32_Phdr;

typedef struct elf64_phdr {
	Elf64_Half    p_type;        /* entry type */
	Elf64_Half    p_flags;    /* flags */
	Elf64_Off    p_offset;    /* offset */
	Elf64_Addr    p_vaddr;    /* virtual address */
	Elf64_Addr    p_paddr;    /* physical address */
	Elf64_Xword    p_filesz;    /* file size */
	Elf64_Xword    p_memsz;    /* memory size */
	Elf64_Xword    p_align;    /* memory & file alignment */
} Elf64_Phdr;

/*Section Header 节区头部 结构定义*/
typedef struct elf32_shdr {
	/* name - index into section header string table section */
	Elf32_Word sh_name;
	/* type */
	Elf32_Word sh_type;
	/* flags */
	Elf32_Word sh_flags;
	/* address */
	Elf32_Addr sh_addr;
	/* file offset */
	Elf32_Off sh_offset;
	/* section size */
	Elf32_Word sh_size;
	/* section header table index link */
	Elf32_Word sh_link;
	/* extra information */
	Elf32_Word sh_info;
	/* address alignment */
	Elf32_Word sh_addralign;
	/* section entry size */
	Elf32_Word sh_entsize;
} Elf32_Shdr;

typedef struct elf64_shdr {
	Elf64_Word sh_name;
	Elf64_Word sh_type;
	Elf64_Xword sh_flags;
	Elf64_Addr sh_addr;
	Elf64_Off sh_offset;
	Elf64_Xword sh_size;
	Elf64_Word sh_link;
	Elf64_Word sh_info;
	Elf64_Xword sh_addralign;
	Elf64_Xword sh_entsize;
} Elf64_Shdr;

/*
符号表包含用来定位、重定位程序中符号定义和引用的信息，
简单的理解就是符号表记录了该文件中的所有符号，
所谓的符号就是经过修饰了的函数名或者变量名，
不同的编译器有不同的修饰规则。
例如符号_ZL15global_static_a，就是由global_static_a变量名经过修饰而来
*/
typedef struct elf32_sym {
	// //符号表项名称。如果该值非0，则表示符号名的字
	Elf32_Word st_name;
	//符号的取值。依赖于具体的上下文，可能是一个绝对值、一个地址等等。
	Elf32_Addr st_value;
	//符号的尺寸大小。例如一个数据对象的大小是对象中包含的字节数。
	Elf32_Word st_size;
	//符号的类型和绑定属性。
	unsigned char st_info;
	//未定义。
	unsigned char st_other;
	//每个符号表项都以和其他节区的关系的方式给出定义。
	Elf32_Half st_shndx;
} Elf32_Sym;
typedef struct elf64_sym {
	Elf64_Word st_name;
	/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
	unsigned char st_info;
	unsigned char st_other;
	Elf64_Half st_shndx;
	Elf64_Addr st_value;
	/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
	Elf64_Xword st_size;
} Elf64_Sym;

/*elf header 中magic魔法数的大小52位*/
const __u16 E32_HEAD_MAGIC_SIZE = sizeof(Elf32_Ehdr);
const __u16 E64_HEAD_MAGIC_SIZE = sizeof(Elf64_Ehdr);

/*EI_CLASS 文件类,其实代表的是32位/64位程序*/
#define SELFMAG 4
#define ELFCLASSNONE 0
/*32位程序*/
#define ELFCLASS32 1
/*64位程序*/
#define ELFCLASS64 2

#define ELFCLASSNUM 3
/*非法数据编码*/
#define ELFDATANONE 0
/*小端：高位在前 Least Significant Bit*/
#define ELFDATA2LSB 1
/*大端：低位在前 Most Significant Bit*/
#define ELFDATA2MSB 2

#define 	ELF_EI_MAG0   0
#define 	ELF_EI_MAG1   1
#define 	ELF_EI_MAG2   2
#define 	ELF_EI_MAG3   3
#define 	ELF_EI_CLASS   4
#define 	ELF_EI_DATA   5
#define 	ELF_EI_VERSION   6
#define 	ELF_EI_OSABI   7
#define 	ELF_EI_ABIVERSION   8
#define 	ELF_EI_PAD   9
#define 	EI_NIDENT   16
#define 	ELFMAG0   0x7f
#define 	ELFMAG1   'E'
#define 	ELFMAG2   'L'
#define 	ELFMAG3   'F'
#define 	ELFCLASSNONE   0
#define 	ELFCLASS32   1
#define 	ELFCLASS64   2
#define 	ELFDATANONE   0
#define 	ELFDATA2LSB   1
#define 	ELFDATA2MSB   2
#define		ELFOSABI_NONE 0
#define 	ELFOSABI_SYSV   0
#define 	ELFOSABI_HPUX   1
#define 	ELFOSABI_NETBSD   2
#define 	ELFOSABI_LINUX   3
#define 	ELFOSABI_HURD   4
#define 	ELFOSABI_86OPEN   5
#define 	ELFOSABI_SOLARIS   6
#define 	ELFOSABI_MONTEREY   7
#define		ELFOSABI_AIX	ELFOSABI_MONTEREY
#define 	ELFOSABI_IRIX   8
#define 	ELFOSABI_FREEBSD   9
#define 	ELFOSABI_TRU64   10
#define 	ELFOSABI_MODESTO   11
#define 	ELFOSABI_OPENBSD   12
#define 	ELFOSABI_ARM   97
#define 	ELFOSABI_STANDALONE   255

/*目标文件类型*/
/*未知目标文件格式*/
#define 	ELF_ET_NONE   0
/*可重定位文件*/
#define 	ELF_ET_REL   1
/*可执行文件*/
#define 	ELF_ET_EXEC   2
/*共享目标文件*/
#define 	ELF_ET_DYN   3
/*Core文件(转储格式)*/
#define 	ELF_ET_CORE   4
/*特定处理器文件*/
#define 	ELF_ET_LOOS   0xFE00
#define 	ELF_ET_HIOS   0xFEFF
/*特定处理器文件*/
#define 	ELF_ET_LOPROC   0xFF00
/*特定处理器文件*/
#define 	ELF_ET_HIPROC   0xFFFF
#define 	ELF_EM_NONE   0
#define 	ELF_EM_M32   1
#define 	ELF_EM_SPARC   2
#define 	ELF_EM_386   3
#define 	ELF_EM_68K   4
#define 	ELF_EM_88K   5
#define 	ELF_EM_486   6
#define 	ELF_EM_860   7
#define 	ELF_EM_MIPS   8
#define 	ELF_EM_S370   9
#define 	ELF_EM_MIPS_RS4_BE   10
#define 	ELF_EM_MIPS_RS3_LE   10
#define		ELF_EM_RESERVED11	11
#define		ELF_EM_RESERVED14	14
#define 	ELF_EM_PARISC   15
#define		ELF_EM_RESERVED16	16
#define 	ELF_EM_VPP550   17
#define 	ELF_EM_SPARC32PLUS   18
#define 	ELF_EM_960   19
#define 	ELF_EM_PPC   20
#define 	ELF_EM_PPC64   21
#define 	ELF_EM_V800   36
#define 	ELF_EM_FR20   37
#define 	ELF_EM_RH32   38
#define 	ELF_EM_MCORE   39
#define 	ELF_EM_RCE   39
#define 	ELF_EM_ARM   40
#define 	ELF_EM_OLD_ALPHA   41
#define 	ELF_EM_SH   42
#define 	ELF_EM_SPARCV9   43
#define 	ELF_EM_TRICORE   44
#define 	ELF_EM_ARC   45
#define 	ELF_EM_H8_300   46
#define 	ELF_EM_H8_300H   47
#define 	ELF_EM_H8S   48
#define 	ELF_EM_H8_500   49
#define 	ELF_EM_IA_64   50
#define 	ELF_EM_MIPS_X   51
#define 	ELF_EM_COLDFIRE   52
#define 	ELF_EM_68HC12   53
#define 	ELF_EM_MMA   54
#define 	ELF_EM_PCP   55
#define 	ELF_EM_NCPU   56
#define 	ELF_EM_NDR1   57
#define 	ELF_EM_STARCORE   58
#define 	ELF_EM_ME16   59
#define 	ELF_EM_ST100   60
#define 	ELF_EM_TINYJ   61
#define 	ELF_EM_X86_64   62
#define 	ELF_EM_FX66   66
#define 	ELF_EM_ST9PLUS   67
#define 	ELF_EM_ST7   68
#define 	ELF_EM_68HC16   69
#define 	ELF_EM_68HC11   70
#define 	ELF_EM_68HC08   71
#define 	ELF_EM_68HC05   72
#define 	ELF_EM_SVX   73
#define 	ELF_EM_ST19   74
#define 	ELF_EM_VAX   75
#define 	ELF_EM_CRIS   76
#define 	ELF_EM_JAVELIN   77
#define 	ELF_EM_FIREPATH  78
#define 	ELF_EM_ZSP   79
#define 	ELF_EM_MMIX   80
#define 	ELF_EM_HUANY   81
#define 	ELF_EM_PRISM   82
#define ELF_EM_AVR 83
#define ELF_EM_FR30 84
#define ELF_EM_D10V 85
#define ELF_EM_D30V 86
#define ELF_EM_V850 87
#define ELF_EM_MN10200 90
#define ELF_EM_PJ 91
#define ELF_EM_ARC_COMPACT 93
#define ELF_EM_XTENSA 94
#define ELF_EM_VIDEOCORE 95
#define ELF_EM_TMM_GPP 96
#define ELF_EM_NS32K 97
#define ELF_EM_TPC 98
#define ELF_EM_SNP1K 99
#define ELF_EM_ST200 100
#define ELF_EM_IP2K 101
#define ELF_EM_MAX 102
#define ELF_EM_CR 103
#define ELF_EM_F2MC16 104
#define ELF_EM_MSP430 105
#define ELF_EM_SE_C33 107
#define ELF_EM_SEP 108
#define ELF_EM_ARCA 109
#define ELF_EM_UNICORE 110
#define ELF_EM_EXCESS 111
#define ELF_EM_DXP 112
#define ELF_EM_CRX 114
#define ELF_EM_XGATE 115
#define ELF_EM_C166 116
#define ELF_EM_M16C 117
#define ELF_EM_DSPIC30F 118
#define ELF_EM_CE 119
#define ELF_EM_M32C 120
#define ELF_EM_TSK3000 131
#define ELF_EM_RS08 132
#define ELF_EM_SHARC 133
#define ELF_EM_ECOG2 134
#define ELF_EM_SCORE7 135
#define ELF_EM_DSP24 136
#define ELF_EM_VIDEOCORE3 137
#define ELF_EM_LATTICEMICO32 138
#define ELF_EM_SE_C17 139
#define ELF_EM_TI_C2000 141
#define ELF_EM_TI_C5500 142
#define ELF_EM_MMDSP_PLUS 160
#define ELF_EM_CYPRESS_M8C 161
#define ELF_EM_R32C 162
#define ELF_EM_TRIMEDIA 163
#define ELF_EM_QDSP6 164
#define ELF_EM_8051 165
#define ELF_EM_STXP7X 166
#define ELF_EM_NDS32 167
#define ELF_EM_ECOG1 168
#define ELF_EM_ECOG1X 168
#define ELF_EM_MAXQ30 169
#define ELF_EM_XIMO16 170
#define ELF_EM_MANIK 171
#define ELF_EM_CRAYNV2 172
#define ELF_EM_RX 173
#define ELF_EM_METAG 174
#define ELF_EM_MCST_ELBRUS 175
#define ELF_EM_ECOG16 176
#define ELF_EM_CR16 177
#define ELF_EM_ETPU 178
#define ELF_EM_SLE9X 179
#define ELF_EM_L10M 180
#define ELF_EM_K10M 181
#define ELF_EM_AVR32 185
#define ELF_EM_STM8 186
#define ELF_EM_TILE64 187
#define ELF_EM_CUDA 190
#define ELF_EM_CLOUDSHIELD 192
#define ELF_EM_COREA_1ST 193
#define ELF_EM_COREA_2ND 194
#define ELF_EM_ARC_COMPACT2 195
#define ELF_EM_OPEN8 196
#define ELF_EM_RL78 197
#define ELF_EM_VIDEOCORE5 198
#define ELF_EM_78KOR 199
#define ELF_EM_56800EX 200
#define ELF_EM_BA1 201
#define ELF_EM_BA2 202
#define ELF_EM_XCORE 203
#define ELF_EM_MCHP_PIC 204
#define ELF_EM_INTEL205 205
#define ELF_EM_INTEL206 206
#define ELF_EM_INTEL207 207
#define ELF_EM_INTEL208 208
#define ELF_EM_INTEL209 209
#define ELF_EM_KM32 210
#define ELF_EM_KMX32 211
#define ELF_EM_KMX16 212
#define ELF_EM_KMX8 213
#define ELF_EM_KVARC 214
#define ELF_EM_CDP 215
#define EM_COGE 216
#define ELF_EM_COOL 217
#define ELF_EM_NORC 218
#define ELF_EM_CSR_KALIMBA 219
#define ELF_EM_Z80 220
#define ELF_EM_VISIUM 221
#define ELF_EM_FT32 222
#define ELF_EM_MOXIE 223
#define ELF_EM_AMDGPU 224
#define ELF_EM_RISCV 243
/*更多处理器类型请参考https://android.googlesource.com/platform/bionic/+/master/libc/include/elf.h*/



#define 	ELF_EV_NONE   0
#define 	ELF_EV_CURRENT   1
#define 	ELF_SHN_UNDEF   0
#define 	ELF_SHN_ABS   0xfff1
#define 	ELF_SHN_COMMON   0xfff2
#define 	ELF_SHT_NULL   0
#define 	ELF_SHT_PROGBITS   1
#define 	ELF_SHT_SYMTAB   2
#define 	ELF_SHT_STRTAB   3
#define 	ELF_SHT_RELA   4
#define 	ELF_SHT_HASH   5
#define 	ELF_SHT_DYNAMIC   6
#define 	ELF_SHT_NOTE   7
#define 	ELF_SHT_NOBITS   8
#define 	ELF_SHT_REL   9
#define 	ELF_SHT_SHLIB   10
#define 	ELF_SHT_DYNSYM   11
#define 	ELF_SHT_INIT_ARRAY   14
#define 	ELF_SHT_FINI_ARRAY   15
#define 	ELF_SHT_PREINIT_ARRAY   16
#define 	ELF_SHF_WRITE   (1<<0)
#define 	ELF_SHF_ALLOC   (1<<1)
#define 	ELF_SHF_EXECINSTR   (1<<2)
#define 	ELF_SHF_MERGE   (1<<4)
#define 	ELF_SHF_STRINGS   (1<<5)
#define 	ELF_SHF_INFO_LINK   (1<<6)
#define 	ELF_SHF_LINK_ORDER   (1<<7)
#define 	ELF_SHF_OS_NONCONFORMING   (1<<8)
#define 	ELF_PT_NULL   0
#define 	ELF_PT_LOAD   1
#define 	ELF_PT_DYNAMIC   2
#define 	ELF_PT_INTERP   3
#define 	ELF_PT_NOTE   4
#define 	ELF_PT_SHLIB   5
#define 	ELF_PT_PHDR   6
#define		ELF_PT_TLS 7
#define		ELF_PT_LOOS 0x60000000
#define		ELF_PT_HIOS 0x6fffffff
#define		ELF_PT_LOPROC 0x70000000
#define		ELF_PT_HIPROC 0x7fffffff
#define		ELF_PT_GNU_EH_FRAME 0x6474e550
#define		ELF_PT_SUNW_EH_FRAME 0x6474e550
#define		ELF_PT_SUNW_UNWIND 0x6464e550
#define		ELF_PT_GNU_STACK 0x6474e551
#define		ELF_PT_GNU_RELRO 0x6474e552
#define		ELF_PT_OPENBSD_RANDOMIZE 0x65a3dbe6
#define		ELF_PT_OPENBSD_WXNEEDED 0x65a3dbe7
#define		ELF_PT_OPENBSD_BOOTDATA 0x65a41be6
#define		ELF_PT_ARM_ARCHEXT 0x70000000
#define		ELF_PT_ARM_EXIDX 0x70000001
#define		ELF_PT_ARM_UNWIND 0x70000001
#define		ELF_PT_MIPS_REGINFO 0x70000000
#define		ELF_PT_MIPS_RTPROC 0x70000001
#define		ELF_PT_MIPS_OPTIONS 0x70000002
#define		ELF_PT_MIPS_ABIFLAGS 0x70000003
#define 	ELF_STB_LOCAL   0
#define 	ELF_STB_GLOBAL   1
#define 	ELF_STB_WEAK   2
#define 	ELF_STT_NOTYPE   0
#define 	ELF_STT_OBJECT   1
#define 	ELF_STT_FUNC   2
#define 	ELF_STT_SECTION   3
#define 	ELF_STT_FILE   4
#define 	ELF_STT_COMMON   5
#define 	ELF32_ST_BIND(i)   ((i)>>4)
#define 	ELF32_ST_TYPE(i)   ((i)&0xf)
#define 	ELF32_ST_INFO(b, t)   (((b)>>4)|((t)&0xf))
#define 	ELF64_ST_BIND(i)   ((i)>>4)
#define 	ELF64_ST_TYPE(i)   ((i)&0xf)
#define 	ELF64_ST_INFO(b, t)   (((b)>>4)|((t)&0xf))
#define 	ELF32_R_SYM(i)   ((i)>>8)
#define 	ELF32_R_TYPE(i)   ((unsigned char)(i))
#define 	ELF32_R_INFO(s, t)   (((s)<<8)+(unsigned char)(t))
#define 	ELF_R_386_NONE   0
#define 	ELF_R_386_32   1
#define 	ELF_R_386_PC32   2
#define 	ELF_R_386_GOT32   3
#define 	ELF_R_386_PLT32   4
#define 	ELF_R_386_COPY   5
#define 	ELF_R_386_GLOB_DAT   6
#define 	ELF_R_386_JMP_SLOT   7
#define 	ELF_R_386_RELATIVE   8
#define 	ELF_R_386_GOTOFF   9
#define 	ELF_R_386_GOTPC   10

/*程序头 Flag 段相关的标志*/
/* 可读的段 */
#define PF_R 0x4
/* 可写的段 */
#define PF_W 0x2
/*可执行的段*/
#define PF_X 0x1
/*保留*/
#define PF_MASKPROC 0xf0000000
#endif // !_ELF_H