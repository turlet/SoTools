#include <stdio.h>
#include <fstream>
#include <iostream>
#include "elf.h"
#include <QLineEdit>
#include <string>
#include <cstring> 

using namespace std;

static int initParse(QLineEdit* msgInfo)
{
	printf("hello world!\n");
	const char* pSoFileName = "d:/hello.so";
	ifstream soFile(pSoFileName, ios::binary);
	if (!soFile) {
		cerr << endl << "Read so file error!" << endl;
		return -1;
	}
	__u64 readBytes = 0L;

	__u32 r = 0;

	Elf32_Ehdr *elfHeader;
	__u16 elfHeadSize = sizeof(elfHeader);
	char buf[52];

	soFile.read(buf, 52);
	elfHeader = (Elf32_Ehdr *)buf;
	char Magic1[sizeof(elfHeader->e_ident)];
	unsigned char a = elfHeader->e_ident[0];
	//sprintf(Magic1, "%02X", elfHeader->e_ident[0]);
	sprintf(Magic1, "%02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx", elfHeader->e_ident[0], elfHeader->e_ident[1], elfHeader->e_ident[2], elfHeader->e_ident[3], elfHeader->e_ident[4], elfHeader->e_ident[5], elfHeader->e_ident[6], elfHeader->e_ident[7], elfHeader->e_ident[8], elfHeader->e_ident[9],elfHeader->e_ident[10], elfHeader->e_ident[11], elfHeader->e_ident[12], elfHeader->e_ident[13], elfHeader->e_ident[14], elfHeader->e_ident[15]);
	//strcat("Magic=", Magic);
	msgInfo->setText(Magic1);
	cout << "Magic=" << elfHeader->e_ident << endl;
	cout << "Type=" << elfHeader->e_type << endl;
	cout << "Machine=" << elfHeader->e_machine << endl;
	cout << "Version=" << elfHeader->e_version << endl;
	cout << "Entry point address=" << elfHeader->e_entry << endl;
	cout << "Start of program headers=" << elfHeader->e_phoff << endl;
	cout << "Start of section headers=" << elfHeader->e_shoff << endl;
	cout << "Flags=" << elfHeader->e_flags << endl;
	cout << "Size of this header=" << elfHeader->e_ehsize << endl;
	cout << "Size of program headers=" << elfHeader->e_phentsize << endl;
	cout << "Number of program headers=" << elfHeader->e_phnum << endl;
	cout << "Size of section headers=" << elfHeader->e_shentsize << endl;
	cout << "Number of section headers=" << elfHeader->e_shnum << endl;
	cout << "Section header string table index=" << elfHeader->e_shstrndx << endl;
	//while (! soFile.eof)
	{

	}
	return 0;
}

