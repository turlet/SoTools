#include "ElfReader.h"

ElfReader::ElfReader()
{

}

ElfReader::ElfReader(SoTools *ui)
{
	mainUi = ui;
}

ElfReader::~ElfReader(void) 
{
	//pSoFile.close;
}

void ElfReader::setUI(Ui::SoToolsClass ui) 
{
	pUi = ui;
}

int ElfReader::loadSo(const char* soFilePath) 
{
	pSoFilePath = soFilePath;
	pSoFile.open(pSoFilePath, ios::binary);
	if (!pSoFile) 
	{
		//pUi.messageEdit->setText("Read so file error!");
		QString err("select file path:%1,Read so file error!");
		err = err.arg(pSoFilePath);
		mainUi->statusLabel->setText(err);
		return -1;
	}
	return 0;
}

/*
	ELF头部(ELF_Header): 每个ELF文件都必须存在一个ELF_Header,这里存放了很多重要的信息用来描述整个文件的组织,如: 版本信息,入口信息,偏移信息等。程序执行也必须依靠其提供的信息。
*/
void ElfReader::parseElfHeader()
{
	if (!pSoFile) 
	{
		return;
	}


	char *buf =new char[E32_HEAD_MAGIC_SIZE];
	pSoFile.read(buf, E32_HEAD_MAGIC_SIZE);
	elfHeader = (Elf32_Ehdr *)buf;
	char magicValue[sizeof(elfHeader->e_ident)];
	unsigned char EI_MAG0 = elfHeader->e_ident[0];
	unsigned char EI_MAG1 = elfHeader->e_ident[1];
	unsigned char EI_MAG2 = elfHeader->e_ident[2];
	unsigned char EI_MAG3 = elfHeader->e_ident[3];
	unsigned char EI_MAG4 = elfHeader->e_ident[4];
	unsigned char EI_MAG5 = elfHeader->e_ident[5];
	unsigned char EI_MAG6 = elfHeader->e_ident[6];
	unsigned char EI_MAG7 = elfHeader->e_ident[7];
	unsigned char EI_MAG8 = elfHeader->e_ident[8];
	unsigned char EI_MAG9 = elfHeader->e_ident[9];
	unsigned char EI_MAG10 = elfHeader->e_ident[10];
	unsigned char EI_MAG11 = elfHeader->e_ident[11];
	unsigned char EI_MAG12 = elfHeader->e_ident[12];
	unsigned char EI_MAG13 = elfHeader->e_ident[13];
	unsigned char EI_MAG14 = elfHeader->e_ident[14];
	unsigned char EI_MAG15 = elfHeader->e_ident[15];

	QString magic("%1 %2 %3 %4 %5 %6 %7 %8 %9 %10 %11 %12 %13 %14 %15 %16");
	magic = magic.arg(EI_MAG0,2,16, QLatin1Char('0'))
		.arg(EI_MAG1, 2, 16, QLatin1Char('0'))
		.arg(EI_MAG2, 2, 16, QLatin1Char('0'))
		.arg(EI_MAG3, 2, 16, QLatin1Char('0'))
		.arg(EI_MAG4, 2, 16, QLatin1Char('0'))
		.arg(EI_MAG5, 2, 16, QLatin1Char('0'))
		.arg(EI_MAG6, 2, 16, QLatin1Char('0'))
		.arg(EI_MAG7, 2, 16, QLatin1Char('0'))
		.arg(EI_MAG8, 2, 16, QLatin1Char('0'))
		.arg(EI_MAG9, 2, 16, QLatin1Char('0'))
		.arg(EI_MAG10, 2, 16, QLatin1Char('0'))
		.arg(EI_MAG11, 2, 16, QLatin1Char('0'))
		.arg(EI_MAG12, 2, 16, QLatin1Char('0'))
		.arg(EI_MAG13, 2, 16, QLatin1Char('0'))
		.arg(EI_MAG14, 2, 16, QLatin1Char('0'))
		.arg(EI_MAG15, 2, 16, QLatin1Char('0'))
		;
	//sprintf(magicValue, "%02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx %02hhx", elfHeader->e_ident[0], elfHeader->e_ident[1], elfHeader->e_ident[2], elfHeader->e_ident[3], elfHeader->e_ident[4], elfHeader->e_ident[5], elfHeader->e_ident[6], elfHeader->e_ident[7], elfHeader->e_ident[8], elfHeader->e_ident[9], elfHeader->e_ident[10], elfHeader->e_ident[11], elfHeader->e_ident[12], elfHeader->e_ident[13], elfHeader->e_ident[14], elfHeader->e_ident[15]);
	pUi.magicEdit->setText(magic);

	//标识文件的类别，或者说是容量，取魔法值中的第4个位
	if (EI_MAG4 == ELFCLASSNONE) 
	{
		pUi.classKeyEdit->setText("ELFCLASSNONE");
		pUi.classValueEdit->setText(QString::fromLocal8Bit("非法类别"));
	}
	else if (EI_MAG4 == ELFCLASS32) 
	{
		pUi.classKeyEdit->setText("ELF32");
		pUi.classValueEdit->setText(QString::fromLocal8Bit("32位程序"));
	}
	else if (EI_MAG4 == ELFCLASS64) 
	{
		pUi.classKeyEdit->setText("ELF64");
		pUi.classValueEdit->setText(QString::fromLocal8Bit("64位程序"));
	}
	else 
	{
		//QString::fromStdString(to_string(ei_class))
		//QString::number(50,10);
		pUi.classKeyEdit->setText(QString::number(EI_MAG4));
		pUi.classValueEdit->setText(QString::fromLocal8Bit("未知值"));
	}
	//给出处理器特定数据的数据编码方式,一般都是01。即大端还是小端方式。取值可为3种：ELFDATANONE（0）非法数据编码；ELFDATA2LSB（1）高位在前；ELFDATA2MSB（2）低位在前。
	__u16 ei_data = (__u16)EI_MAG5;
	if (EI_MAG5 == ELFDATANONE) 
	{
		pUi.dataKeyEdit->setText("ELFDATANONE");
		pUi.dataValueEdit->setText(QString::fromLocal8Bit("非法数据编码"));
	}
	else if (EI_MAG5 == ELFDATA2LSB) 
	{
		pUi.dataKeyEdit->setText("little endian");
		pUi.dataValueEdit->setText(QString::fromLocal8Bit("小端"));
	}
	else if (EI_MAG5 == ELFDATA2MSB) 
	{
		pUi.dataKeyEdit->setText("big endian");
		pUi.dataValueEdit->setText(QString::fromLocal8Bit("大端"));
	}
	else 
	{
		pUi.dataKeyEdit->setText(QString::number(EI_MAG5));
		pUi.dataValueEdit->setText(QString::fromLocal8Bit("未知值"));
	}

	//EI_VERSION 文件版本,固定值01 EV_CURRENT
	pUi.eiVersionKeyEdit->setText(QString::number(EI_MAG6));

	//oa/abi运行系统环境
	pUi.osAbiKeyEdit->setText(QString::number(EI_MAG7));
	pUi.osAbiValueEdit->setText(ebl_osabi_name(EI_MAG7));

	//ABI版本
	pUi.abiVersionKeyEdit->setText(QString::number(EI_MAG8));

	//目标文件类型 
	if (elfHeader->e_type == ELF_ET_NONE) 
	{
		pUi.typeKeyEdit->setText("NONE (None)");
		pUi.typeValueEdit->setText(QString::fromLocal8Bit("未知格式"));
	}else if (elfHeader->e_type == ELF_ET_REL) 
	{
		pUi.typeKeyEdit->setText("REL (Relocatable file)");
		pUi.typeValueEdit->setText(QString::fromLocal8Bit("可重定位文件"));
	}
	else if (elfHeader->e_type == ELF_ET_EXEC)
	{
		pUi.typeKeyEdit->setText("EXEC (Executable file)");
		pUi.typeValueEdit->setText(QString::fromLocal8Bit("可执行文件"));
	}
	else if (elfHeader->e_type == ELF_ET_DYN)
	{
		pUi.typeKeyEdit->setText("DYN (Shared object file)");
		pUi.typeValueEdit->setText(QString::fromLocal8Bit("共享目标文件"));
	}
	else if (elfHeader->e_type == ELF_ET_CORE)
	{
		pUi.typeKeyEdit->setText("CORE (Core file)");
		pUi.typeValueEdit->setText(QString::fromLocal8Bit("转储格式"));
	}
	else if (elfHeader->e_type >= ELF_ET_LOOS && elfHeader->e_type <= ELF_ET_HIOS)
	{
		QString str("OS Specific: (%1)");
		str = str.arg(elfHeader->e_type);
		pUi.typeKeyEdit->setText(str);
		pUi.typeValueEdit->setText(QString::fromLocal8Bit("特定处理器"));
	}
	else if (elfHeader->e_type == ELF_ET_CORE)
	{
		QString str("Processor Specific: (%1)");
		str = str.arg(elfHeader->e_type);
		pUi.typeKeyEdit->setText(str);
		pUi.typeValueEdit->setText(QString::fromLocal8Bit("特定处理器"));
	}
	else
	{
		pUi.typeKeyEdit->setText(QString::number(elfHeader->e_type));
		pUi.typeValueEdit->setText(QString::fromLocal8Bit("未知值"));
	}

	//处理器类型
	QString machine("(0x%1) %2");
	machine = machine.arg(elfHeader->e_machine, 2, 16, QLatin1Char('0')).arg(e_machine(elfHeader->e_machine));
	pUi.machineKeyEdit->setText(machine);

	//目标文件版本
	QString targetVersion("0x%1 %2");
	targetVersion = targetVersion.arg(elfHeader->e_version, 2, 16, QLatin1Char('0')).arg(QString::fromLocal8Bit("当前版本"));
	pUi.versionKeyEdit->setText(targetVersion);

	//程序入口虚拟地址
	QString entryPoint("0x%1");
	entryPoint = entryPoint.arg(elfHeader->e_entry, 2, 16, QLatin1Char('0'));
	pUi.entryPointKeyEdit->setText(entryPoint);

	//程序头部表格偏移量
	QString phoff("%1 (bytes into file)");
	phoff = phoff.arg(elfHeader->e_phoff);
	pUi.phoffKeyEdit->setText(phoff);

	//节区头部表格的偏移量，如果文件没有节区头部表格，可以为0
	QString shoff("%1 (bytes into file)");
	shoff = shoff.arg(elfHeader->e_shoff);
	pUi.shoffKeyEdit->setText(shoff);

	//保存与文件相关的，特定于处理器的标志，标志名称采用EF_machine_flag的格式
	QString flag("0x%1");
	flag = flag.arg(elfHeader->e_flags, 2, 16);
	pUi.flagKeyEdit->setText(flag);

	//elf头部的大小
	QString elfHeadSize("%1 (bytes)");
	elfHeadSize = elfHeadSize.arg(elfHeader->e_ehsize);
	pUi.ehsizeKeyEdit->setText(elfHeadSize);

	//程序头部表格的表项大小
	QString phentsize("%1 (bytes)");
	phentsize = phentsize.arg(elfHeader->e_phentsize);
	pUi.phentsizeKeyEdit->setText(phentsize);

	//程序头部表格的表项数量
	pUi.phnumKeyEdit->setText(QString::number(elfHeader->e_phnum));

	//节区头部表格的表项大小
	QString shentsize("%1 (bytes)");
	shentsize = shentsize.arg(elfHeader->e_shentsize);
	pUi.shentsizeKeyEdit->setText(shentsize);

	//节区头部表格的表项数量
	pUi.shnumKeyEdit->setText(QString::number(elfHeader->e_shnum));

	//节区头部表格中与节区名称字符串表相关的表项的索引，如果文件没有节区名称字符串表，些参数可以为SHN_UNDEF
	pUi.shstrndxKeyEdit->setText(QString::number(elfHeader->e_shstrndx));
}

void ElfReader::parseProgramHeader()
{
	if (!pSoFile)
	{
		return;
	}
	Elf32_Phdr *pheader;
	const __u32 size = elfHeader->e_phentsize;

	//char *buf = new char;


	//pUi.magicEdit->setText(QString::number(pheader->p_offset));
	//设置行列数量
	int columnCount = 8;
	int rowCount = elfHeader->e_phnum;
	pUi.phTable->setColumnCount(columnCount);
	pUi.phTable->setRowCount(rowCount + 1);

	QString phInfo(QString::fromLocal8Bit("程序头部表(Program_Header_Table): 有 %1 个程序头, 从文件 %2 字节开始\r\n\t可选的一个表，用于告诉系统如何在内存中创建映像,在图中也可以看出来,有程序头部表才有段,有段就必须有程序头部表。其中存放各个段的基本信息(包括地址指针)。\r\n\t---需要查看表中字段的值，请把鼠标放在表项上面。"));
	phInfo = phInfo.arg(rowCount,0,10).arg(elfHeader->e_ehsize, 0, 10);
	pUi.phinfoLabel->setText(phInfo);
	//QStringList headerTab;
	//headerTab << "Type" << "Offset" << "VirtAddr" << "PhysAddr" << "FileSiz" << "MemSiz" << "Flg" << "Align";
	//pUi.phTable->setHorizontalHeaderLabels(headerTab);
	//
	QTableWidgetItem *headeritem = new QTableWidgetItem(QString::fromLocal8Bit("段类型(Type)"));
	//headeritem->setTextAlignment(Qt::AlignCenter);
	headeritem->setToolTip(QString::fromLocal8Bit("这个成员告诉这个数组元素描述什么样的段，或者如何解释数组元素的信息。"));
	pUi.phTable->setHorizontalHeaderItem(0, headeritem);

	QTableWidgetItem *headeritem1 = new QTableWidgetItem(QString::fromLocal8Bit("段偏移(Offset)"));
	headeritem1->setToolTip(QString::fromLocal8Bit("此成员给出从文件头到该段第一个字节的偏移。"));
	pUi.phTable->setHorizontalHeaderItem(1, headeritem1);

	QTableWidgetItem *headeritem2 = new QTableWidgetItem(QString::fromLocal8Bit("段虚拟地址(VirtAddr)"));
	headeritem2->setToolTip(QString::fromLocal8Bit("此成员给出段的第一个字节将被放到内存中的虚拟地址。"));
	pUi.phTable->setHorizontalHeaderItem(2, headeritem2);

	QTableWidgetItem *headeritem3 = new QTableWidgetItem(QString::fromLocal8Bit("物理地址(PhysAddr)"));
	headeritem3->setToolTip(QString::fromLocal8Bit("此成员仅用于与物理地址相关的系统中。因为 System V 忽略所有应用程序的物理地址信息，此字段对与可执行文件和共享目标文件而言，具体内容是未指定的。"));
	pUi.phTable->setHorizontalHeaderItem(3, headeritem3);

	QTableWidgetItem *headeritem4 = new QTableWidgetItem(QString::fromLocal8Bit("段文件字节数(FileSiz)"));
	headeritem4->setToolTip(QString::fromLocal8Bit("此成员给出段在文件映像中所占的字节数。可以为 0。"));
	pUi.phTable->setHorizontalHeaderItem(4, headeritem4);

	QTableWidgetItem *headeritem5 = new QTableWidgetItem(QString::fromLocal8Bit("段内存字节数(MemSiz)"));
	headeritem5->setToolTip(QString::fromLocal8Bit("此成员给出段在内存映像中占用的字节数。可以为 0。"));
	pUi.phTable->setHorizontalHeaderItem(5, headeritem5);

	QTableWidgetItem *headeritem6 = new QTableWidgetItem(QString::fromLocal8Bit("段标志(Flag)"));
	headeritem6->setToolTip(QString::fromLocal8Bit("此成员给出与段相关的标志。值：1,可执行的段;2,可写的段;4,可读的段;0,保留"));
	pUi.phTable->setHorizontalHeaderItem(6, headeritem6);

	QTableWidgetItem *headeritem7 = new QTableWidgetItem(QString::fromLocal8Bit("段对齐方式(Align)"));
	headeritem7->setToolTip(QString::fromLocal8Bit("可加载的进程段的 p_vaddr 和 p_offset 取值必须合适，相对于对页面大小的取模而言。此成员给出段在文件中和内存中如何 对齐。数值 0 和 1 表示不需要对齐。否则 p_align 应该是个 正整数，并且是 2 的幂次数，p_vaddr 和 p_offset 对 p_align 取模后应该相等。"));
	pUi.phTable->setHorizontalHeaderItem(7, headeritem7);
	//自动调整宽度
	pUi.phTable->horizontalHeader()->setStretchLastSection(true);
	pUi.phTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	pUi.phTable->verticalHeader()->setVisible(false);
	//不能对表格内容进行修改
	pUi.phTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	pUi.phTable->setSelectionMode(QAbstractItemView::ExtendedSelection);  //可多选（Ctrl、Shift、  Ctrl+A都可以）
	pUi.phTable->setStyleSheet("selection-background-color:lightblue;"); //设置选中背景色

	//让表头的文字靠左
	pUi.phTable->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
	QFont font = pUi.phTable->horizontalHeader()->font();
	font.setBold(true);
	pUi.phTable->horizontalHeader()->setFont(font);
	pUi.phTable->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}"); //设置表头背景色

	pSoFile.seekg(elfHeader->e_ehsize);
	//qDebug() <<"num=" << rowCount << endl;
	bool hasInterp = false;
	size_t interpRow;
	Elf32_Off interpOff;
	Elf32_Word interpSize;
	for(int row = 0; row < rowCount; row++)
	{
		char buf[32];
		pSoFile.read(buf, size);
		pheader = (Elf32_Phdr *)buf;
		//qDebug() << row << endl;
		setPhRow(hasInterp ? row+1:row, pheader);
		/* We can show the user the name of the interpreter.  */
		if (pheader->p_type == ELF_PT_INTERP) 
		{

			QTableWidgetItem *item = new QTableWidgetItem(QString::fromLocal8Bit("[Requesting program interpreter: /system/bin/linker]"));
			item->setTextAlignment(Qt::AlignCenter);
			item->setToolTip("hello");
			pUi.phTable->setSpan(row + 1, 0, 1, columnCount);
			pUi.phTable->setItem(row + 1, 0, item);
			hasInterp = true;
			interpRow = row + 1;
			interpOff = pheader->p_offset;
			interpSize = pheader->p_filesz;
		}
		else if (pheader->p_type == ELF_PT_GNU_RELRO)
		{
			//has_relro = true;
			//relro_from = phdr->p_vaddr;
			//relro_to = relro_from + phdr->p_memsz;
		}
	}
	if (hasInterp) 
	{
		pSoFile.seekg(interpOff);
		char *interpValue = new char[interpSize];
		pSoFile.read(interpValue, interpSize);

		QString interpStr("[Requesting program interpreter: %1]");
		interpStr = interpStr.arg(interpValue);
		QTableWidgetItem *itemInterp = new QTableWidgetItem(interpStr);
		itemInterp->setTextAlignment(Qt::AlignCenter);
		itemInterp->setToolTip(QString::fromLocal8Bit("使用的动态加载器路径，主要用于实现共享库的加载与链接"));
		pUi.phTable->setSpan(interpRow, 0, 1, columnCount);
		pUi.phTable->setItem(interpRow, 0, itemInterp);
		delete[]interpValue;
	}
}

void ElfReader::parseSectionHeader()
{
	if (!pSoFile)
	{
		return;
	}
	//e_shoff 成员给出从文件头到节区头部表格的偏移字节数
	size_t shoff = elfHeader->e_shoff;
	//e_shnum 给出表格中条目数目
	size_t shnum = elfHeader->e_shnum;
	//e_shentsize 给出每个项目的字节数。从这些信息中可以确切地定 位节区的具体位置、长度
	size_t size = elfHeader->e_shentsize;
	//每个节区头部数据结构描述
	Elf32_Shdr *sheader;

	size_t cnt;	
	
	QString phentsize(QString::fromLocal8Bit("\t有 %1 节区头部, 文件的偏移地址 0x%2\r\n\t---需要查看表中字段的值，请把鼠标放在表项上面。\r\n\t---点击段名(Name)查看更多"));
	phentsize = phentsize.arg(shnum).arg(shoff, 0, 16);
	pUi.shinfoLabel->setText(phentsize);

	pUi.shTable->setColumnCount(11);
	pUi.shTable->setRowCount(shnum);

	//QStringList headerTab;
	//headerTab << "[Nr]" << "Name" << "Type" << "Addr" << "Off" << "Size" << "ES" << "Flg" << "Lk" << "Inf" << "Al";
	//pUi.shTable->setHorizontalHeaderLabels(headerTab);

	QTableWidgetItem *headeritem = new QTableWidgetItem(QString::fromLocal8Bit("行号[Nr]"));
	headeritem->setToolTip(QString::fromLocal8Bit("一行代表一个节区头部"));
	pUi.shTable->setHorizontalHeaderItem(0, headeritem);

	QTableWidgetItem *headeritem1 = new QTableWidgetItem(QString::fromLocal8Bit("段名(Name)"));
	headeritem1->setToolTip(QString::fromLocal8Bit("Section Name 段名"));
	pUi.shTable->setHorizontalHeaderItem(1, headeritem1);

	QTableWidgetItem *headeritem2 = new QTableWidgetItem(QString::fromLocal8Bit("类型(Type)"));
	headeritem2->setToolTip(QString::fromLocal8Bit("Section Type 段的类型，主要决定段的属性是段的类型和标志位"));
	pUi.shTable->setHorizontalHeaderItem(2, headeritem2);

	QTableWidgetItem *headeritem3 = new QTableWidgetItem(QString::fromLocal8Bit("地址(Addr)"));
	headeritem3->setToolTip(QString::fromLocal8Bit("Section Address 段虚拟地址,如果该段可以被加载，则sh_addr为该段被加载后在进程地址空间中的虚拟地址；否则sh_addr为0"));
	pUi.shTable->setHorizontalHeaderItem(3, headeritem3);

	QTableWidgetItem *headeritem4 = new QTableWidgetItem(QString::fromLocal8Bit("偏移(Off)"));
	headeritem4->setToolTip(QString::fromLocal8Bit("Section Offset段偏移，如果该段存在于文件中，则表示该段在文件中的偏移，否则无意义，比如sh_offset对于BSS段来说就没有意义"));
	pUi.shTable->setHorizontalHeaderItem(4, headeritem4);

	QTableWidgetItem *headeritem5 = new QTableWidgetItem(QString::fromLocal8Bit("长度(Size)"));
	headeritem5->setToolTip(QString::fromLocal8Bit("Section Size 段的长度"));
	pUi.shTable->setHorizontalHeaderItem(5, headeritem5);

	QTableWidgetItem *headeritem6 = new QTableWidgetItem(QString::fromLocal8Bit("项长度(ES)"));
	headeritem6->setToolTip(QString::fromLocal8Bit("Section Entry Size项的长度"));
	pUi.shTable->setHorizontalHeaderItem(6, headeritem6);

	QTableWidgetItem *headeritem7 = new QTableWidgetItem(QString::fromLocal8Bit("标记(Flg)"));
	headeritem7->setToolTip(QString::fromLocal8Bit("Section flag段的标记位，表示该节在进程虚拟地址空间中的属性，比如是否可写，可执行等"));
	pUi.shTable->setHorizontalHeaderItem(7, headeritem7);

	QTableWidgetItem *headeritem8 = new QTableWidgetItem(QString::fromLocal8Bit("链接(Lk)"));
	headeritem8->setToolTip(QString::fromLocal8Bit("Section Link 段的链接，如果节区的类型是和链接相关的，比如重定位表，符号表等，那么sh_link和sh_info两个成员包含的意义，对于其它段，这两个成员有没意义"));
	pUi.shTable->setHorizontalHeaderItem(8, headeritem8);

	QTableWidgetItem *headeritem9 = new QTableWidgetItem(QString::fromLocal8Bit("信息(Inf)"));
	headeritem9->setToolTip(QString::fromLocal8Bit("Section Information 段的信息，看段的链接"));
	pUi.shTable->setHorizontalHeaderItem(9, headeritem9);

	QTableWidgetItem *headeritem10 = new QTableWidgetItem(QString::fromLocal8Bit("对应(Al)"));
	headeritem10->setToolTip(QString::fromLocal8Bit("Section Address Alignment 段地址对齐，有些段对于地址对齐有要求，比如我们假设有个段刚开始的位置包含了一个double变量，因为Intel x86系统要求浮点数的存储地址必须是本身的整数倍，也就是说保存double变量的地址必须是8字节的整数倍，这样对一个段来说，它的sh_addr必须是8的整数倍。如果sh_addralign为0或1，则表示该段没有对齐要求"));
	pUi.shTable->setHorizontalHeaderItem(10, headeritem10);

	pUi.shTable->horizontalHeader()->setStretchLastSection(true);
	pUi.shTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	pUi.shTable->verticalHeader()->setVisible(false);
	//不能对表格内容进行修改
	pUi.shTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	pUi.shTable->setSelectionMode(QAbstractItemView::ExtendedSelection);  //可多选（Ctrl、Shift、  Ctrl+A都可以）
	pUi.shTable->setStyleSheet("selection-background-color:lightblue;"); //设置选中背景色

	//让表头的文字靠左
	pUi.shTable->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
	QFont font = pUi.shTable->horizontalHeader()->font();
	font.setBold(true);
	pUi.shTable->horizontalHeader()->setFont(font);
	pUi.shTable->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}"); //设置表头背景色
	//隐藏水平滚动条
	pUi.shTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	pUi.shTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
	pUi.shTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
	pUi.shTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);

	pUi.shTable->setSelectionBehavior(QAbstractItemView::SelectRows); //设置选择行为，以行为单位
	pUi.shTable->setSelectionMode(QAbstractItemView::SingleSelection); //设置选择模式，选择单行

	shstrtabs = new size_t[shnum];
	mainUi->sectionHeaders = new Elf32_Shdr[shnum];
	pSoFile.seekg(shoff);
	for (cnt = 0; cnt < shnum; ++cnt)
	{
		char buf[40];
		pSoFile.read(buf, size);
		sheader = (Elf32_Shdr *)buf;
		mainUi->sectionHeaders[cnt] = (*sheader);
		setShRow(cnt, sheader);
	}

	//对Name列重新读取字符串
	for (cnt = 0; cnt < shnum; ++cnt)
	{
		size_t start = shstrtabs[cnt];
		
		//
		pSoFile.seekg(sectionHeaderOffset + start);
		char shNameValue[20];
		pSoFile.read(shNameValue, 20);

		QTableWidgetItem *item = new QTableWidgetItem(QString::fromLocal8Bit(shNameValue));
		item->setTextAlignment(Qt::AlignCenter);
		pUi.shTable->setItem(cnt, 1, item);

	}
	delete []shstrtabs;
	shstrtabs = NULL;
}

void ElfReader::closeSo()
{
	if (!pSoFile)
	{
		return;
	}
	pSoFile.close();
}

//每一行节区数据
void ElfReader::setShRow(int row, Elf32_Shdr *sheader)
{
	//插入行
	QString nr("[%1]");
	nr = nr.arg(row, 2, 10, QLatin1Char(' '));
	QTableWidgetItem *item = new QTableWidgetItem(nr);
	item->setTextAlignment(Qt::AlignCenter);
	//item->setToolTip(QString::fromLocal8Bit(getphtypedesc(pheader->p_type)));
	pUi.shTable->setItem(row, 0, item);

	QString shName("%1");
	shName = shName.arg(sheader->sh_name);
	QTableWidgetItem *item1 = new QTableWidgetItem(shName);
	item1->setTextAlignment(Qt::AlignCenter);
	pUi.shTable->setItem(row, 1, item1);
	shstrtabs[row] = sheader->sh_name;

	QTableWidgetItem *item2 = new QTableWidgetItem(getshtype(sheader->sh_type));
	item2->setTextAlignment(Qt::AlignCenter);
	item2->setToolTip(getshtypedesc(sheader->sh_type));
	pUi.shTable->setItem(row, 2, item2);
	//当sh_type等于.shstrtab的值是，记录段名字符串的偏移地址和长度
	if (sheader->sh_type == SHT_STRTAB) {
		sectionHeaderAddress = sheader->sh_addr;
		sectionHeaderOffset = sheader->sh_offset;
		sectionHeaderSize = sheader->sh_size;
	}

	QString shAddr("%1");
	shAddr = shAddr.arg(sheader->sh_addr, 8, 16, QLatin1Char('0'));
	QTableWidgetItem *item3 = new QTableWidgetItem(shAddr);
	item3->setTextAlignment(Qt::AlignCenter);
	pUi.shTable->setItem(row, 3, item3);

	QString shOff("%1");
	shOff = shOff.arg(sheader->sh_offset, 6, 16, QLatin1Char('0'));
	QTableWidgetItem *item4 = new QTableWidgetItem(shOff);
	item4->setTextAlignment(Qt::AlignCenter);
	pUi.shTable->setItem(row, 4, item4);

	QString shSize("%1");
	shSize = shSize.arg(sheader->sh_size, 6, 16, QLatin1Char('0'));
	QTableWidgetItem *item5 = new QTableWidgetItem(shSize);
	item5->setTextAlignment(Qt::AlignCenter);
	pUi.shTable->setItem(row, 5, item5);

	QString shEs("%1");
	shEs = shEs.arg(sheader->sh_entsize, 2, 16, QLatin1Char('0'));
	QTableWidgetItem *item6 = new QTableWidgetItem(shEs);
	item6->setTextAlignment(Qt::AlignCenter);
	pUi.shTable->setItem(row, 6, item6);

	QString shFlag("%1");
	shFlag = shFlag.arg(getshflag(sheader->sh_flags));
	QTableWidgetItem *item7 = new QTableWidgetItem(shFlag);
	item7->setTextAlignment(Qt::AlignCenter);
	pUi.shTable->setItem(row, 7, item7);

	QString shLk("%1");
	shLk = shLk.arg(sheader->sh_link);
	QTableWidgetItem *item8 = new QTableWidgetItem(shLk);
	item8->setTextAlignment(Qt::AlignCenter);
	pUi.shTable->setItem(row, 8, item8);

	QString shInf("%1");
	shInf = shInf.arg(sheader->sh_info);
	QTableWidgetItem *item9 = new QTableWidgetItem(shInf);
	item9->setTextAlignment(Qt::AlignCenter);
	pUi.shTable->setItem(row, 9, item9);

	QString shAl("%1");
	shAl = shAl.arg(sheader->sh_addralign);
	QTableWidgetItem *item10 = new QTableWidgetItem(shAl);
	item10->setTextAlignment(Qt::AlignCenter);
	pUi.shTable->setItem(row, 10, item10);
}

//每一行程序头数据
void ElfReader::setPhRow(int row, Elf32_Phdr *pheader)
{
	//插入行
	QTableWidgetItem *item = new QTableWidgetItem(QString::fromLocal8Bit(getphtype(pheader->p_type)));
	item->setTextAlignment(Qt::AlignCenter);
	item->setToolTip(QString::fromLocal8Bit(getphtypedesc(pheader->p_type)));
	pUi.phTable->setItem(row, 0, item);

	QString phOffset("0x%1");
	phOffset = phOffset.arg(pheader->p_offset, 6, 16, QLatin1Char('0'));
	QTableWidgetItem *item1 = new QTableWidgetItem(phOffset);
	item1->setTextAlignment(Qt::AlignCenter);
	pUi.phTable->setItem(row, 1, item1);

	QString phVirtAddr("0x%1");
	phVirtAddr = phVirtAddr.arg(pheader->p_vaddr, 8, 16, QLatin1Char('0'));
	QTableWidgetItem *item2 = new QTableWidgetItem(phVirtAddr);
	item2->setTextAlignment(Qt::AlignCenter);
	pUi.phTable->setItem(row, 2, item2);

	QString phPhysAddr("0x%1");
	phPhysAddr = phPhysAddr.arg(pheader->p_paddr, 8, 16, QLatin1Char('0'));
	QTableWidgetItem *item3 = new QTableWidgetItem(phPhysAddr);
	item3->setTextAlignment(Qt::AlignCenter);
	pUi.phTable->setItem(row, 3, item3);

	QString phFileSiz("0x%1");
	phFileSiz = phFileSiz.arg(pheader->p_filesz, 5, 16, QLatin1Char('0'));
	QTableWidgetItem *item4 = new QTableWidgetItem(phFileSiz);
	item4->setTextAlignment(Qt::AlignCenter);
	pUi.phTable->setItem(row, 4, item4);

	QString phMemSize("0x%1");
	phMemSize = phMemSize.arg(pheader->p_memsz, 5, 16, QLatin1Char('0'));
	QTableWidgetItem *item5 = new QTableWidgetItem(phMemSize);
	item5->setTextAlignment(Qt::AlignCenter);
	pUi.phTable->setItem(row, 5, item5);

	QTableWidgetItem *item6 = new QTableWidgetItem(getphflg(pheader->p_flags));
	item6->setTextAlignment(Qt::AlignCenter);
	pUi.phTable->setItem(row, 6, item6);

	QString phAlign("0x%1");
	phAlign = phAlign.arg(pheader->p_align, 0, 16, QLatin1Char('0'));
	QTableWidgetItem *item7 = new QTableWidgetItem(phAlign);
	item7->setTextAlignment(Qt::AlignCenter);
	pUi.phTable->setItem(row, 7, item7);
}



