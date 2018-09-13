#include "ElfUtil.h"

const char *ebl_osabi_name(int osabi)
{
	const char *res;
	if (osabi == ELFOSABI_NONE)
		res = "UNIX - System V";
	else if (osabi == ELFOSABI_HPUX)
		res = "HP/UX";
	else if (osabi == ELFOSABI_NETBSD)
		res = "NetBSD";
	else if (osabi == ELFOSABI_LINUX)
		res = "Linux";
	else if (osabi == ELFOSABI_SOLARIS)
		res = "Solaris";
	else if (osabi == ELFOSABI_AIX)
		res = "AIX";
	else if (osabi == ELFOSABI_IRIX)
		res = "Irix";
	else if (osabi == ELFOSABI_FREEBSD)
		res = "FreeBSD";
	else if (osabi == ELFOSABI_TRU64)
		res = "TRU64";
	else if (osabi == ELFOSABI_MODESTO)
		res = "Modesto";
	else if (osabi == ELFOSABI_OPENBSD)
		res = "OpenBSD";
	else if (osabi == ELFOSABI_ARM)
		res = "Arm";
	else if (osabi == ELFOSABI_STANDALONE)
		res = "Stand alone";
	else
		res = "<unknown>";

	return res;
}

const char * e_machine(int machine)
{
	const char *res;
	if (machine == ELF_EM_NONE)
		res = "No machine";
	else if (machine == ELF_EM_M32)
		res = "AT&T WE 32100";
	else if (machine == ELF_EM_SPARC)
		res = "SPARC";
	else if (machine == ELF_EM_386)
		res = "Intel 80386";
	else if (machine == ELF_EM_68K)
		res = "Motorola 68000";
	else if (machine == ELF_EM_88K)
		res = "Motorola 88000";
	//不知道是不是这个值
	else if (machine == ELF_EM_486)
		res = "Reserved for future use";
	else if (machine == ELF_EM_860)
		res = "Intel 80860";
	else if (machine == ELF_EM_MIPS)
		res = "MIPS I Architecture";
	else if (machine == ELF_EM_S370)
		res = "IBM System/370 Processor";
	else if (machine == ELF_EM_MIPS_RS3_LE || machine == ELF_EM_MIPS_RS4_BE)
		res = "MIPS RS3000";
	else if ((machine <= ELF_EM_RESERVED11 && machine >= ELF_EM_RESERVED14) || machine == ELF_EM_RESERVED16)
		res = "Reserved for future use";
	else if (machine == ELF_EM_PARISC)
		res = "Hewlett-Packard PA-RISC";
	else if (machine == ELF_EM_VPP550)
		res = "Fujitsu VPP500";
	else if (machine == ELF_EM_SPARC32PLUS)
		res = "Enhanced instruction set SPARC";
	else if (machine == ELF_EM_960)
		res = "Intel 80960";
	else if (machine == ELF_EM_PPC)
		res = "PowerPC";
	else if (machine == ELF_EM_PPC64)
		res = "64-bit PowerPC";
	else if (machine == ELF_EM_V800)
		res = "NEC V800";
	else if (machine == ELF_EM_FR20)
		res = "Fujitsu FR20";
	else if (machine == ELF_EM_RH32)
		res = "TRW RH-32";
	else if (machine == ELF_EM_RCE)
		res = "Motorola RCE";
	else if (machine == ELF_EM_ARM)
		res = "ARM";
	else if (machine == ELF_EM_OLD_ALPHA)
		res = "Digital Alpha";
	else if (machine == ELF_EM_SH)
		res = "Hitachi SH";
	else if (machine == ELF_EM_SPARCV9)
		res = "SPARC Version 9";
	else if (machine == ELF_EM_TRICORE)
		res = "Siemens Tricore embedded processor";
	else if (machine == ELF_EM_ARC)
		res = "Argonaut RISC Core, Argonaut Technologies Inc.";
	else if (machine == ELF_EM_H8_300)
		res = "Hitachi H8/300";
	else if (machine == ELF_EM_H8_300H)
		res = "Hitachi H8/300H";
	else if (machine == ELF_EM_H8S)
		res = "Hitachi H8S";
	else if (machine == ELF_EM_H8_500)
		res = "Hitachi H8/500";
	else if (machine == ELF_EM_IA_64)
		res = "Intel IA-64 processor architecture";
	else if (machine == ELF_EM_MIPS_X)
		res = "Stanford MIPS-X";
	else if (machine == ELF_EM_COLDFIRE)
		res = "Motorola ColdFire";
	else if (machine == ELF_EM_68HC12)
		res = "Motorola M68HC12";
	else if (machine == ELF_EM_MMA)
		res = "Fujitsu MMA Multimedia Accelerator";
	else if (machine == ELF_EM_PCP)
		res = "Siemens PCP";
	else if (machine == ELF_EM_NCPU)
		res = "Sony nCPU embedded RISC processor";
	else if (machine == ELF_EM_NDR1)
		res = "Denso NDR1 microprocessor";
	else if (machine == ELF_EM_STARCORE)
		res = "Motorola Star*Core processor";
	else if (machine == ELF_EM_ME16)
		res = "Toyota ME16 processor";
	else if (machine == ELF_EM_ST100)
		res = "STMicroelectronics ST100 processor";
	else if (machine == ELF_EM_TINYJ)
		res = "Advanced Logic Corp. TinyJ embedded processor family";
	else if (machine == ELF_EM_FX66)
		res = "Siemens FX66 microcontroller";
	else if (machine == ELF_EM_ST9PLUS)
		res = "STMicroelectronics ST9+ 8/16 bit microcontroller";
	else if (machine == ELF_EM_ST7)
		res = "STMicroelectronics ST7 8-bit microcontroller";
	else if (machine == ELF_EM_68HC16)
		res = "Motorola MC68HC16 Microcontroller";
	else if (machine == ELF_EM_68HC11)
		res = "Motorola MC68HC11 Microcontroller";
	else if (machine == ELF_EM_68HC08)
		res = "Motorola MC68HC08 Microcontroller";
	else if (machine == ELF_EM_68HC05)
		res = "Motorola MC68HC05 Microcontroller";
	else if (machine == ELF_EM_SVX)
		res = "Silicon Graphics SVx";
	else if (machine == ELF_EM_ST19)
		res = "STMicroelectronics ST19 8-bit microcontroller";
	else if (machine == ELF_EM_VAX)
		res = "Digital VAX";
	else if (machine == ELF_EM_CRIS)
		res = "Axis Communications 32-bit embedded processor";
	else if (machine == ELF_EM_JAVELIN)
		res = "Infineon Technologies 32-bit embedded processor";
	else if (machine == ELF_EM_FIREPATH)
		res = "Element 14 64-bit DSP Processor";
	else if (machine == ELF_EM_ZSP)
		res = "LSI Logic 16-bit DSP Processor";
	else if (machine == ELF_EM_MMIX)
		res = "Donald Knuth's educational 64-bit processor";
	else if (machine == ELF_EM_HUANY)
		res = "Harvard University machine-independent object files";
	else if (machine == ELF_EM_PRISM)
		res = "SiTera Prism";
	else
		res = "other";
	return res;
}
