#include "SoTools.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SoTools w;
	w.setWindowFlags(w.windowFlags() &~Qt::WindowMaximizeButtonHint);
	w.setFixedSize(w.width(), w.height());
	w.show();
	return a.exec();
}
