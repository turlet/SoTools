#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SoTools.h"
#include "qfiledialog.h"
#include "qdebug.h"
#include "SectionWindow.h"

class SoTools : public QMainWindow
{
	Q_OBJECT

public:
	SoTools(QWidget *parent = Q_NULLPTR);
	QLabel *statusLabel;
	Elf32_Shdr *sectionHeaders;
signals:
	void sigTodo(int);
	//用来传递数据的信号
	void sendData(char *, QString, Elf32_Shdr *);
private slots:
	void openFile();
	void phTableClickItem(int, int);
	void shTableClickItem(int row, int column);
private:
	Ui::SoToolsClass ui;
	char *soPath;
};
