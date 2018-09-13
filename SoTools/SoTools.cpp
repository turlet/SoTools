#include "SoTools.h"

#include "ElfReader.h"

SoTools::SoTools(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	statusLabel = new QLabel(this);

	statusLabel->setMinimumSize(1010, 22); // 设置标签最小大小

	statusLabel->setFrameShape(QFrame::WinPanel); // 设置标签形状

	statusLabel->setFrameShadow(QFrame::Sunken); // 设置标签阴影

	ui.statusBar->addWidget(statusLabel);

	statusLabel->setText(QString::fromLocal8Bit("欢迎使用So可视化分析工具！"));

	QLabel *second_statusLabel = new QLabel;

	second_statusLabel->setMinimumSize(100, 22);
	second_statusLabel->setText(QString::fromLocal8Bit("Silen制作!"));
	second_statusLabel->setFrameShape(QFrame::WinPanel);

	second_statusLabel->setFrameShadow(QFrame::Sunken);
	ui.statusBar->addWidget(second_statusLabel);
	/*
	QLabel *statusLabel = new QLabel(this);
	statusLabel->setFrameShape(QFrame::WinPanel);
	statusLabel->setFrameShadow(QFrame::Sunken);
	ui.statusBar->addWidget(statusLabel);
	statusLabel->setText("欢迎！！！");

	QMenuBar *menuBar = new QMenuBar(this);
	QMenu *menu = menuBar->addMenu("&File");
	QAction *open = new QAction("&Open1", this);
	open->setStatusTip("open exsiting file");
	menu->addAction(open);
	*/
	//QLineEdit* magicEdit = ui.magicEdit;
	//initParse(ui);

	//connect(ui.fileOpen, SIGNAL(sigTodo()), this, SLOT(doJob()));
	/*
	connect(ui.fileOpen, &QAction::triggered, this, [=](bool checked) {
		statusLabel->setText(QString::fromLocal8Bit("open file."));
			ui.machineKeyEdit->setText(QString::number(100));
	});
	*/
	//emit sigTodo(5);
	connect(ui.fileOpen, &QAction::triggered, this, &SoTools::openFile);


	connect(ui.phTable, SIGNAL(cellClicked(int, int)), this, SLOT(phTableClickItem(int,int)));

	//cellDoubleClicked
	connect(ui.shTable, SIGNAL(cellClicked(int, int)), this, SLOT(shTableClickItem(int, int)));
}


void SoTools::openFile()
{
	QFileDialog *fileDialog = new QFileDialog(this);
	fileDialog->setWindowTitle(QString::fromLocal8Bit("打开SO文件"));
	fileDialog->setDirectory(".");
	fileDialog->setNameFilter(QString::fromLocal8Bit("So文件(*.so)"));
	//设置可以选择多个文件,默认为只能选择一个文件QFileDialog::ExistingFiles
	fileDialog->setFileMode(QFileDialog::ExistingFile);
	//设置视图模式
	fileDialog->setViewMode(QFileDialog::Detail);

	if (fileDialog->exec()) 
	{
		QStringList fileNames = fileDialog->selectedFiles();
		if (!fileNames.isEmpty())
		{
			QString fileName = fileNames.at(0);
			qDebug() << "open so file=" << fileName << endl;

			//一定要分开写，要不然又是乱码
			QByteArray fileNameQb = fileName.toLatin1();
			soPath = strcpy(soPath, fileNameQb.data());// "D://hello.so";// fileNameQb.data();

			ElfReader *reader = new ElfReader(this);
			reader->setUI(ui);
			int ret = reader->loadSo(soPath);
			if (ret != 0) {
				return;
			}
			reader->parseElfHeader();
			reader->parseProgramHeader();
			reader->parseSectionHeader();
			reader->closeSo();
		}


	}



}

void SoTools::phTableClickItem(int row, int column)
{
	qDebug() << "row:" << row << ",column=" << column << endl;
	QString item = ui.phTable->item(row, column)->text();
	if (item == "") {
		return;
	}
	qDebug() << item << endl;
}

void SoTools::shTableClickItem(int row, int column)
{
	qDebug() << "row:" << row << ",column=" << column << endl;
	QString item = ui.shTable->item(row, 1)->text();
	if (item == "") {
		return;
	}
	qDebug() << item << endl;
	Elf32_Shdr sheader = sectionHeaders[row];
	SectionWindow *sectionUi = new SectionWindow(this);//将类指针实例化);
	//关联信号和槽函数
	connect(this, SIGNAL(sendData(char*,QString, Elf32_Shdr*)), sectionUi, SLOT(receiveData(char*, QString, Elf32_Shdr*)));
	sectionUi->show();
	qDebug() << "shTableClickItem=" << soPath << endl;
	emit sendData(soPath, item, &sheader);
}
