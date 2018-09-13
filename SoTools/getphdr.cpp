#include "getphdr.h"

const char *getphtype(Elf32_Word type) {
	const char *res;
	if (type == ELF_PT_NULL)
		res = "NULL";
	else if (type == ELF_PT_LOAD)
		res = "LOAD";
	else if (type == ELF_PT_DYNAMIC)
		res = "DYNAMIC";
	else if (type == ELF_PT_INTERP)
		res = "INTERP";
	else if (type == ELF_PT_NOTE)
		res = "NOTE";
	else if (type == ELF_PT_SHLIB)
		res = "SHLIB";
	else if (type == ELF_PT_PHDR)
		res = "PHDR";
	else if (type == ELF_PT_TLS)
		res = "TLS";
	else if (type == ELF_PT_LOOS)
		res = "LOOS";
	else if (type == ELF_PT_HIOS)
		res = "HIOS";
	else if (type == ELF_PT_LOPROC)
		res = "LOPROC";
	else if (type == ELF_PT_HIPROC)
		res = "HIPROC";
	else if (type == ELF_PT_GNU_EH_FRAME)
		res = "GNU_EH_FRAME";
	else if (type == ELF_PT_SUNW_EH_FRAME)
		res = "SUNW_EH_FRAME";
	else if (type == ELF_PT_SUNW_UNWIND)
		res = "SUNW_UNWIND";
	else if (type == ELF_PT_GNU_STACK)
		res = "GNU_STACK";
	else if (type == ELF_PT_GNU_RELRO)
		res = "GNU_RELRO";
	else if (type == ELF_PT_OPENBSD_RANDOMIZE)
		res = "OPENBSD_RANDOMIZE";
	else if (type == ELF_PT_OPENBSD_WXNEEDED)
		res = "OPENBSD_WXNEEDED";
	else if (type == ELF_PT_OPENBSD_BOOTDATA)
		res = "OPENBSD_BOOTDATA";
	else if (type == ELF_PT_ARM_ARCHEXT)
		res = "ARCHEXT";
	else if (type == ELF_PT_ARM_EXIDX)
		res = "EXIDX";
	else if (type == ELF_PT_ARM_UNWIND)
		res = "UNWIND";
	else if (type == ELF_PT_MIPS_REGINFO)
		res = "MIPS_REGINFO";
	else if (type == ELF_PT_MIPS_RTPROC)
		res = "MIPS_RTPROC";
	else if (type == ELF_PT_MIPS_OPTIONS)
		res = "MIPS_OPTIONS";
	else if (type == ELF_PT_MIPS_ABIFLAGS)
		res = "MIPS_ABIFLAGS";
	else
	{
		QString other("(0x%1) <unknown>");
		other = other.arg(type, 8, 16, QLatin1Char('0'));
		res = other.toLocal8Bit().data();
	}
	return res;
}

/*动态链接,详见： https://docs.oracle.com/cd/E24847_01/html/E22196/chapter6-14428.html*/
const char *getphtypedesc(Elf32_Word type) {
	const char *res;
	if (type == ELF_PT_NULL)
		res = "此数组元素未用，结构中其它成员都是未定义的。";
	else if (type == ELF_PT_LOAD)
		res = "此数组元素给出一个可加载的段,段的大小由 p_filesz 和 p_memsz 描述。文件中的字节被映射到内存段开始处。如果 p_memsz 大于 p_filesz,“剩余”的字节要清零。p_filesz 不能大于 p_memsz。可加载的段在程序头部表格中根据 p_vaddr 成员按升序排列。";
	else if (type == ELF_PT_DYNAMIC)
		res = "数组元素给出动态链接信息。";
	else if (type == ELF_PT_INTERP)
		res = "数组元素给出一个 NULL 结尾的字符串的位置和长度,该字符串将被当作解释器调用。这种段类型仅对与可执行文件有意义(尽管也可能在共享目标文件上发生)。在一个文件中不能出现一次以上。如果存在这种类型的段,它必须在所有可加载段项目的前面。";
	else if (type == ELF_PT_NOTE)
		res = "此数组元素给出附加信息的位置和大小。";
	else if (type == ELF_PT_SHLIB)
		res = "此段类型被保留,不过语义未指定。包含这种类型的段的程序与 ABI不符。";
	else if (type == ELF_PT_PHDR)
		res = "此类型的数组元素如果存在,则给出了程序头部表自身的大小和位置,既包括在文件中也包括在内存中的信息。此类型的段在文件中不能出现一次以上。并且只有程序头部表是程序的内存映像的一部分时才起作用。如果存在此类型段,则必须在所有可加载段项目的前面。";
	else if (type == ELF_PT_TLS)
		res = "指定线程局部存储模板,编译时分配的线程局部数据的独立副本必须与各个执行线程关联。此类型的数组元素一个指向 TLS 初始化映像的指针,TLS 初始化映像的大小(TLS initialisation image),显示模块是否使用静态 TLS 模式的标识（仅当架构支持静态 TLS 模式）。";
	else if (type == ELF_PT_LOOS)
		res = "此范围内包含的值保留用于特定于操作系统的语义。";
	else if (type == ELF_PT_HIOS)
		res = "此范围内包含的值保留用于特定于操作系统的语义。";
	else if (type == ELF_PT_LOPROC)
		res = "此范围内包含的值（包括这两个值）保留用于特定于处理器的语义。";
	else if (type == ELF_PT_HIPROC)
		res = "此范围内包含的值（包括这两个值）保留用于特定于处理器的语义。";
	else if (type == ELF_PT_GNU_EH_FRAME)
		res = "GNU_EH_FRAME";
	else if (type == ELF_PT_SUNW_EH_FRAME)
		res = "此段包含栈扩展表。PT_SUNW_EH_FRAME 与 PT_SUNW_EH_UNWIND 等效。";
	else if (type == ELF_PT_SUNW_UNWIND)
		res = "此段包含栈扩展表。";
	else if (type == ELF_PT_GNU_STACK)
		res = "GNU_STACK";
	else if (type == ELF_PT_GNU_RELRO)
		res = "GNU_RELRO";
	else if (type == ELF_PT_OPENBSD_RANDOMIZE)
		res = "OPENBSD_RANDOMIZE";
	else if (type == ELF_PT_OPENBSD_WXNEEDED)
		res = "OPENBSD_WXNEEDED";
	else if (type == ELF_PT_OPENBSD_BOOTDATA)
		res = "OPENBSD_BOOTDATA";
	else if (type == ELF_PT_ARM_ARCHEXT)
		res = "ARM_ARCHEXT";
	else if (type == ELF_PT_ARM_EXIDX)
		res = "ARM_EXIDX";
	else if (type == ELF_PT_ARM_UNWIND)
		res = "ARM_UNWIND";
	else if (type == ELF_PT_MIPS_REGINFO)
		res = "MIPS_REGINFO";
	else if (type == ELF_PT_MIPS_RTPROC)
		res = "MIPS_RTPROC";
	else if (type == ELF_PT_MIPS_OPTIONS)
		res = "MIPS_OPTIONS";
	else if (type == ELF_PT_MIPS_ABIFLAGS)
		res = "MIPS_ABIFLAGS";
	else
		res = "<unknown>";
	return res;
}

const QString getphflg(Elf32_Word flag)
{
	QString flags("");
	if (flag & PF_R)
		flags = flags.append(QString::fromLocal8Bit("读"));
	else
		flags = flags.append(QString::fromLocal8Bit(" "));

	if (flag & PF_W)
		flags = flags.append(QString::fromLocal8Bit("写"));
	else
		flags = flags.append(QString::fromLocal8Bit(" "));

	if (flag & PF_X)
		flags = flags.append(QString::fromLocal8Bit("执行"));
	else
		flags = flags.append(QString::fromLocal8Bit(" "));
	
	//if (flag & PF_MASKPROC)
	//	res = "保留";
	return flags;
}
