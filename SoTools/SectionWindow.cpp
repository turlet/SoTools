#include "SectionWindow.h"

const char * pSoFilePath;
ifstream pSoFile;

SectionWindow::SectionWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setAttribute(Qt::WA_DeleteOnClose, 1);
}


SectionWindow::~SectionWindow()
{
	qDebug() << "SectionWindow release" << endl;
	pSoFile.close();
}

void SectionWindow::receiveData(char* soPath, QString text, Elf32_Shdr *sheader)
{
	//获取传递过来的数据
	qDebug() << "new="<< sheader->sh_name << text  << endl;
	
	qDebug() << "so=" << soPath << endl;
	pSoFilePath = soPath;

	openSo();
	if (text == QString::fromLatin1(".interp"))
	{
		parseInterp(sheader);
	}
	else if (text == QString::fromLatin1(".dynsym"))
	{
		Elf32_Off offset = sheader->sh_offset;
		Elf32_Word fSize = sheader->sh_size;
		pSoFile.seekg(offset);
		size_t len = sizeof(Elf32_Sym);
		size_t count = fSize / len;
		qDebug() << "dynsym=" << count << endl;
		Elf32_Sym *dynsym;
		for (size_t i = 0; i < count; i++)
		{
			char *buf = new char[len];
			pSoFile.read(buf, len);
			dynsym = (Elf32_Sym *)buf;
			qDebug() << "dynsym struct=" << dynsym->st_name << dynsym->st_value << dynsym->st_size << dynsym->st_info << dynsym->st_other << dynsym->st_shndx << endl;
		}


	}
	else {
		qDebug() << "else=" << text << endl;
	}

	

	//qDebug() << "Elf32_Sym" << sizeof(Elf32_Sym) << endl;

}


int SectionWindow::openSo()
{

	pSoFile.open(pSoFilePath, ios::binary);
	if (!pSoFile)
	{
		//pUi.messageEdit->setText("Read so file error!");
		QString err("select file path:%1,Read so file error!");
		err = err.arg(pSoFilePath);
		
		return -1;
	}
	return 0;
}

void SectionWindow::parseInterp(Elf32_Shdr *sheader)
{
	Elf32_Off interpOff = sheader->sh_offset;
	Elf32_Word interpSize = sheader->sh_size;
	qDebug() << "new=" << interpOff << interpSize << endl;
	pSoFile.seekg(interpOff);
	char *interpValue = new char[interpSize];
	pSoFile.read(interpValue, interpSize);


	qDebug() << "interp=" << interpValue << endl;
	delete[]interpValue;

}



