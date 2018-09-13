#ifndef ELF_READER_H
#define ELF_READER_H

#include <fstream>

#include "elf.h"
#include "SoTools.h"
#include "qstring.h"
#include <string>
#include "ElfUtil.h"
#include "qdebug.h"
#include "getphdr.h"
#include "getshdr.h"

using namespace std;

class ElfReader
{
public:
	ElfReader();   // 这是构造函数声明
	ElfReader(SoTools *mainUi);
	~ElfReader();  // 这是析构函数声明
	void setUI(Ui::SoToolsClass ui);
	int loadSo(const char* soFilePath);
	void parseElfHeader();
	//解析程序头部表
	void parseProgramHeader();
	//解析节区头部表
	void parseSectionHeader();
	void closeSo();
private:
	Ui::SoToolsClass pUi;
	const char* pSoFilePath;
	ifstream pSoFile;
	SoTools *mainUi;
	Elf32_Ehdr *elfHeader;
	void setPhRow(int row, Elf32_Phdr *pheader);
	void setShRow(int row, Elf32_Shdr * sheader);
	size_t sectionHeaderAddress;
	size_t sectionHeaderOffset;
	size_t sectionHeaderSize;
	size_t* shstrtabs;

};

#endif