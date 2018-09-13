/********************************************************************************
** Form generated from reading UI file 'SoTools.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOTOOLS_H
#define UI_SOTOOLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SoToolsClass
{
public:
    QAction *fileOpen;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *elfTab;
    QLabel *flagLabel;
    QLineEdit *flagKeyEdit;
    QLineEdit *shstrndxKeyEdit;
    QLabel *phentsizeLabel;
    QLabel *osAbiLabel;
    QLabel *shstrndxLabel;
    QLineEdit *typeKeyEdit;
    QLineEdit *magicEdit;
    QLineEdit *ehsizeKeyEdit;
    QLabel *ehsizeLabel;
    QLineEdit *phentsizeKeyEdit;
    QLineEdit *osAbiKeyEdit;
    QLineEdit *osAbiValueEdit;
    QLabel *abiVersionLabel;
    QLineEdit *abiVersionKeyEdit;
    QLineEdit *typeValueEdit;
    QLabel *phnumLabel;
    QLineEdit *phnumKeyEdit;
    QLabel *shentsizeLabel;
    QLineEdit *machineKeyEdit;
    QLabel *machineLabel;
    QLabel *magicLabel;
    QLineEdit *entryPointKeyEdit;
    QLabel *classLabel;
    QLabel *phoffLabel;
    QLabel *dataLabel;
    QLineEdit *dataKeyEdit;
    QLabel *eiVersionLabel;
    QLineEdit *eiVersionKeyEdit;
    QLabel *typeLabel;
    QLabel *versionLabel;
    QLineEdit *versionKeyEdit;
    QLabel *entryPointLabel;
    QLineEdit *classKeyEdit;
    QLineEdit *classValueEdit;
    QLineEdit *phoffKeyEdit;
    QLineEdit *dataValueEdit;
    QLabel *shoffLabel;
    QLineEdit *shoffKeyEdit;
    QLineEdit *shentsizeKeyEdit;
    QLabel *shnumLabel;
    QLineEdit *shnumKeyEdit;
    QWidget *phTab;
    QTableWidget *phTable;
    QLabel *phinfoLabel;
    QWidget *shTab;
    QLabel *shinfoLabel;
    QTableWidget *shTable;
    QMenuBar *menuBar;
    QMenu *menu_F;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SoToolsClass)
    {
        if (SoToolsClass->objectName().isEmpty())
            SoToolsClass->setObjectName(QStringLiteral("SoToolsClass"));
        SoToolsClass->resize(1101, 722);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        SoToolsClass->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral("icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        SoToolsClass->setWindowIcon(icon);
        SoToolsClass->setStyleSheet(QStringLiteral(""));
        fileOpen = new QAction(SoToolsClass);
        fileOpen->setObjectName(QStringLiteral("fileOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/SoTool/Resources/icon/file_open.ico"), QSize(), QIcon::Normal, QIcon::Off);
        fileOpen->setIcon(icon1);
        centralWidget = new QWidget(SoToolsClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1101, 641));
        elfTab = new QWidget();
        elfTab->setObjectName(QStringLiteral("elfTab"));
        flagLabel = new QLabel(elfTab);
        flagLabel->setObjectName(QStringLiteral("flagLabel"));
        flagLabel->setGeometry(QRect(30, 560, 131, 16));
        flagKeyEdit = new QLineEdit(elfTab);
        flagKeyEdit->setObjectName(QStringLiteral("flagKeyEdit"));
        flagKeyEdit->setGeometry(QRect(170, 550, 141, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        flagKeyEdit->setFont(font1);
        flagKeyEdit->setReadOnly(true);
        shstrndxKeyEdit = new QLineEdit(elfTab);
        shstrndxKeyEdit->setObjectName(QStringLiteral("shstrndxKeyEdit"));
        shstrndxKeyEdit->setGeometry(QRect(610, 510, 241, 31));
        shstrndxKeyEdit->setFont(font1);
        shstrndxKeyEdit->setReadOnly(true);
        phentsizeLabel = new QLabel(elfTab);
        phentsizeLabel->setObjectName(QStringLiteral("phentsizeLabel"));
        phentsizeLabel->setGeometry(QRect(610, 160, 261, 16));
        osAbiLabel = new QLabel(elfTab);
        osAbiLabel->setObjectName(QStringLiteral("osAbiLabel"));
        osAbiLabel->setGeometry(QRect(30, 210, 111, 16));
        shstrndxLabel = new QLabel(elfTab);
        shstrndxLabel->setObjectName(QStringLiteral("shstrndxLabel"));
        shstrndxLabel->setGeometry(QRect(610, 480, 471, 20));
        typeKeyEdit = new QLineEdit(elfTab);
        typeKeyEdit->setObjectName(QStringLiteral("typeKeyEdit"));
        typeKeyEdit->setGeometry(QRect(170, 300, 191, 31));
        typeKeyEdit->setFont(font1);
        typeKeyEdit->setReadOnly(true);
        magicEdit = new QLineEdit(elfTab);
        magicEdit->setObjectName(QStringLiteral("magicEdit"));
        magicEdit->setGeometry(QRect(150, 30, 381, 31));
        magicEdit->setFont(font1);
        ehsizeKeyEdit = new QLineEdit(elfTab);
        ehsizeKeyEdit->setObjectName(QStringLiteral("ehsizeKeyEdit"));
        ehsizeKeyEdit->setGeometry(QRect(610, 110, 241, 31));
        ehsizeKeyEdit->setFont(font1);
        ehsizeKeyEdit->setReadOnly(true);
        ehsizeLabel = new QLabel(elfTab);
        ehsizeLabel->setObjectName(QStringLiteral("ehsizeLabel"));
        ehsizeLabel->setGeometry(QRect(610, 80, 221, 16));
        phentsizeKeyEdit = new QLineEdit(elfTab);
        phentsizeKeyEdit->setObjectName(QStringLiteral("phentsizeKeyEdit"));
        phentsizeKeyEdit->setGeometry(QRect(610, 190, 241, 31));
        phentsizeKeyEdit->setFont(font1);
        phentsizeKeyEdit->setReadOnly(true);
        osAbiKeyEdit = new QLineEdit(elfTab);
        osAbiKeyEdit->setObjectName(QStringLiteral("osAbiKeyEdit"));
        osAbiKeyEdit->setGeometry(QRect(170, 200, 141, 31));
        osAbiKeyEdit->setFont(font1);
        osAbiKeyEdit->setReadOnly(true);
        osAbiValueEdit = new QLineEdit(elfTab);
        osAbiValueEdit->setObjectName(QStringLiteral("osAbiValueEdit"));
        osAbiValueEdit->setGeometry(QRect(340, 200, 181, 31));
        osAbiValueEdit->setFont(font1);
        osAbiValueEdit->setReadOnly(true);
        abiVersionLabel = new QLabel(elfTab);
        abiVersionLabel->setObjectName(QStringLiteral("abiVersionLabel"));
        abiVersionLabel->setGeometry(QRect(30, 260, 131, 16));
        abiVersionKeyEdit = new QLineEdit(elfTab);
        abiVersionKeyEdit->setObjectName(QStringLiteral("abiVersionKeyEdit"));
        abiVersionKeyEdit->setGeometry(QRect(170, 250, 141, 31));
        abiVersionKeyEdit->setFont(font1);
        abiVersionKeyEdit->setReadOnly(true);
        typeValueEdit = new QLineEdit(elfTab);
        typeValueEdit->setObjectName(QStringLiteral("typeValueEdit"));
        typeValueEdit->setGeometry(QRect(380, 300, 151, 31));
        typeValueEdit->setFont(font1);
        typeValueEdit->setReadOnly(true);
        phnumLabel = new QLabel(elfTab);
        phnumLabel->setObjectName(QStringLiteral("phnumLabel"));
        phnumLabel->setGeometry(QRect(610, 240, 271, 16));
        phnumKeyEdit = new QLineEdit(elfTab);
        phnumKeyEdit->setObjectName(QStringLiteral("phnumKeyEdit"));
        phnumKeyEdit->setGeometry(QRect(610, 270, 241, 31));
        phnumKeyEdit->setFont(font1);
        phnumKeyEdit->setReadOnly(true);
        shentsizeLabel = new QLabel(elfTab);
        shentsizeLabel->setObjectName(QStringLiteral("shentsizeLabel"));
        shentsizeLabel->setGeometry(QRect(610, 320, 261, 16));
        machineKeyEdit = new QLineEdit(elfTab);
        machineKeyEdit->setObjectName(QStringLiteral("machineKeyEdit"));
        machineKeyEdit->setGeometry(QRect(170, 340, 361, 31));
        machineKeyEdit->setFont(font1);
        machineKeyEdit->setReadOnly(true);
        machineLabel = new QLabel(elfTab);
        machineLabel->setObjectName(QStringLiteral("machineLabel"));
        machineLabel->setGeometry(QRect(30, 350, 131, 16));
        magicLabel = new QLabel(elfTab);
        magicLabel->setObjectName(QStringLiteral("magicLabel"));
        magicLabel->setGeometry(QRect(30, 40, 101, 16));
        entryPointKeyEdit = new QLineEdit(elfTab);
        entryPointKeyEdit->setObjectName(QStringLiteral("entryPointKeyEdit"));
        entryPointKeyEdit->setGeometry(QRect(240, 420, 131, 31));
        entryPointKeyEdit->setFont(font1);
        entryPointKeyEdit->setReadOnly(true);
        classLabel = new QLabel(elfTab);
        classLabel->setObjectName(QStringLiteral("classLabel"));
        classLabel->setGeometry(QRect(30, 80, 101, 16));
        phoffLabel = new QLabel(elfTab);
        phoffLabel->setObjectName(QStringLiteral("phoffLabel"));
        phoffLabel->setGeometry(QRect(30, 470, 291, 16));
        dataLabel = new QLabel(elfTab);
        dataLabel->setObjectName(QStringLiteral("dataLabel"));
        dataLabel->setGeometry(QRect(30, 130, 101, 16));
        dataKeyEdit = new QLineEdit(elfTab);
        dataKeyEdit->setObjectName(QStringLiteral("dataKeyEdit"));
        dataKeyEdit->setGeometry(QRect(170, 120, 141, 31));
        dataKeyEdit->setFont(font1);
        dataKeyEdit->setReadOnly(true);
        eiVersionLabel = new QLabel(elfTab);
        eiVersionLabel->setObjectName(QStringLiteral("eiVersionLabel"));
        eiVersionLabel->setGeometry(QRect(30, 170, 111, 16));
        eiVersionKeyEdit = new QLineEdit(elfTab);
        eiVersionKeyEdit->setObjectName(QStringLiteral("eiVersionKeyEdit"));
        eiVersionKeyEdit->setGeometry(QRect(170, 160, 141, 31));
        eiVersionKeyEdit->setFont(font1);
        eiVersionKeyEdit->setReadOnly(true);
        typeLabel = new QLabel(elfTab);
        typeLabel->setObjectName(QStringLiteral("typeLabel"));
        typeLabel->setGeometry(QRect(30, 310, 111, 16));
        versionLabel = new QLabel(elfTab);
        versionLabel->setObjectName(QStringLiteral("versionLabel"));
        versionLabel->setGeometry(QRect(30, 390, 131, 16));
        versionKeyEdit = new QLineEdit(elfTab);
        versionKeyEdit->setObjectName(QStringLiteral("versionKeyEdit"));
        versionKeyEdit->setGeometry(QRect(170, 380, 131, 31));
        versionKeyEdit->setFont(font1);
        versionKeyEdit->setReadOnly(true);
        entryPointLabel = new QLabel(elfTab);
        entryPointLabel->setObjectName(QStringLiteral("entryPointLabel"));
        entryPointLabel->setGeometry(QRect(30, 430, 191, 16));
        classKeyEdit = new QLineEdit(elfTab);
        classKeyEdit->setObjectName(QStringLiteral("classKeyEdit"));
        classKeyEdit->setGeometry(QRect(170, 70, 141, 31));
        classKeyEdit->setFont(font1);
        classKeyEdit->setReadOnly(true);
        classValueEdit = new QLineEdit(elfTab);
        classValueEdit->setObjectName(QStringLiteral("classValueEdit"));
        classValueEdit->setGeometry(QRect(330, 70, 121, 31));
        classValueEdit->setFont(font1);
        classValueEdit->setReadOnly(true);
        phoffKeyEdit = new QLineEdit(elfTab);
        phoffKeyEdit->setObjectName(QStringLiteral("phoffKeyEdit"));
        phoffKeyEdit->setGeometry(QRect(340, 460, 191, 31));
        phoffKeyEdit->setFont(font1);
        phoffKeyEdit->setReadOnly(true);
        dataValueEdit = new QLineEdit(elfTab);
        dataValueEdit->setObjectName(QStringLiteral("dataValueEdit"));
        dataValueEdit->setGeometry(QRect(330, 120, 121, 31));
        dataValueEdit->setFont(font1);
        dataValueEdit->setReadOnly(true);
        shoffLabel = new QLabel(elfTab);
        shoffLabel->setObjectName(QStringLiteral("shoffLabel"));
        shoffLabel->setGeometry(QRect(30, 510, 291, 16));
        shoffKeyEdit = new QLineEdit(elfTab);
        shoffKeyEdit->setObjectName(QStringLiteral("shoffKeyEdit"));
        shoffKeyEdit->setGeometry(QRect(340, 500, 191, 31));
        shoffKeyEdit->setFont(font1);
        shoffKeyEdit->setReadOnly(true);
        shentsizeKeyEdit = new QLineEdit(elfTab);
        shentsizeKeyEdit->setObjectName(QStringLiteral("shentsizeKeyEdit"));
        shentsizeKeyEdit->setGeometry(QRect(610, 350, 241, 31));
        shentsizeKeyEdit->setFont(font1);
        shentsizeKeyEdit->setReadOnly(true);
        shnumLabel = new QLabel(elfTab);
        shnumLabel->setObjectName(QStringLiteral("shnumLabel"));
        shnumLabel->setGeometry(QRect(610, 400, 281, 16));
        shnumKeyEdit = new QLineEdit(elfTab);
        shnumKeyEdit->setObjectName(QStringLiteral("shnumKeyEdit"));
        shnumKeyEdit->setGeometry(QRect(610, 430, 241, 31));
        shnumKeyEdit->setFont(font1);
        shnumKeyEdit->setReadOnly(true);
        tabWidget->addTab(elfTab, QString());
        phTab = new QWidget();
        phTab->setObjectName(QStringLiteral("phTab"));
        phTable = new QTableWidget(phTab);
        phTable->setObjectName(QStringLiteral("phTable"));
        phTable->setGeometry(QRect(0, 70, 1100, 541));
        phinfoLabel = new QLabel(phTab);
        phinfoLabel->setObjectName(QStringLiteral("phinfoLabel"));
        phinfoLabel->setGeometry(QRect(0, 0, 1091, 71));
        phinfoLabel->setWordWrap(true);
        tabWidget->addTab(phTab, QString());
        shTab = new QWidget();
        shTab->setObjectName(QStringLiteral("shTab"));
        shinfoLabel = new QLabel(shTab);
        shinfoLabel->setObjectName(QStringLiteral("shinfoLabel"));
        shinfoLabel->setGeometry(QRect(0, 0, 1091, 71));
        shinfoLabel->setWordWrap(true);
        shTable = new QTableWidget(shTab);
        shTable->setObjectName(QStringLiteral("shTable"));
        shTable->setGeometry(QRect(0, 70, 1100, 541));
        tabWidget->addTab(shTab, QString());
        SoToolsClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SoToolsClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1101, 23));
        menu_F = new QMenu(menuBar);
        menu_F->setObjectName(QStringLiteral("menu_F"));
        SoToolsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SoToolsClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SoToolsClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SoToolsClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SoToolsClass->setStatusBar(statusBar);

        menuBar->addAction(menu_F->menuAction());
        menu_F->addAction(fileOpen);
        mainToolBar->addAction(fileOpen);

        retranslateUi(SoToolsClass);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(SoToolsClass);
    } // setupUi

    void retranslateUi(QMainWindow *SoToolsClass)
    {
        SoToolsClass->setWindowTitle(QApplication::translate("SoToolsClass", "So\345\217\257\350\247\206\345\214\226\345\210\206\346\236\220\345\267\245\345\205\267", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        SoToolsClass->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        fileOpen->setText(QApplication::translate("SoToolsClass", "\346\211\223\345\274\200(&O)", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        fileOpen->setStatusTip(QApplication::translate("SoToolsClass", "\350\257\267\351\200\211\346\213\251so\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        fileOpen->setShortcut(QApplication::translate("SoToolsClass", "Ctrl+O", Q_NULLPTR));
        flagLabel->setText(QApplication::translate("SoToolsClass", "\345\244\204\347\220\206\345\231\250\346\240\207\345\277\227(Flags)\357\274\232", Q_NULLPTR));
        shstrndxKeyEdit->setText(QString());
        phentsizeLabel->setText(QApplication::translate("SoToolsClass", "\347\250\213\345\272\217\345\244\264\351\203\250\350\241\250\346\240\274\345\244\247\345\260\217(Size of program headers)\357\274\232", Q_NULLPTR));
        osAbiLabel->setText(QApplication::translate("SoToolsClass", "\347\263\273\347\273\237\347\216\257\345\242\203(OS/ABI)\357\274\232", Q_NULLPTR));
        shstrndxLabel->setText(QApplication::translate("SoToolsClass", "\350\212\202\345\214\272\345\244\264\351\203\250\350\241\250\346\240\274\344\270\216\350\212\202\345\214\272\345\220\215\347\247\260\345\255\227\347\254\246\344\270\262\350\241\250\347\233\270\345\205\263\347\264\242\345\274\225(Section header string table index)\357\274\232", Q_NULLPTR));
        ehsizeLabel->setText(QApplication::translate("SoToolsClass", "ELF\345\244\264\351\203\250\345\244\247\345\260\217(Size of this headers)\357\274\232", Q_NULLPTR));
        phentsizeKeyEdit->setText(QString());
        abiVersionLabel->setText(QApplication::translate("SoToolsClass", "ABI\347\211\210\346\234\254(ABI Version)\357\274\232", Q_NULLPTR));
        phnumLabel->setText(QApplication::translate("SoToolsClass", "\347\250\213\345\272\217\345\244\264\351\203\250\350\241\250\346\240\274\346\225\260\347\233\256(Number of program headers)\357\274\232", Q_NULLPTR));
        phnumKeyEdit->setText(QString());
        shentsizeLabel->setText(QApplication::translate("SoToolsClass", "\350\212\202\345\214\272\345\244\264\351\203\250\350\241\250\346\240\274\345\244\247\345\260\217(Size of section headers)\357\274\232", Q_NULLPTR));
        machineLabel->setText(QApplication::translate("SoToolsClass", "\345\244\204\347\220\206\345\231\250\347\261\273\345\236\213(Machine)\357\274\232", Q_NULLPTR));
        magicLabel->setText(QApplication::translate("SoToolsClass", "\351\255\224\346\263\225\345\200\274(Magic)\357\274\232", Q_NULLPTR));
        classLabel->setText(QApplication::translate("SoToolsClass", "\346\226\207\344\273\266\347\261\273\345\210\253(Class)\357\274\232", Q_NULLPTR));
        phoffLabel->setText(QApplication::translate("SoToolsClass", "\347\250\213\345\272\217\345\244\264\351\203\250\350\241\250\346\240\274\345\201\217\347\247\273\351\207\217(Start of program headers)\357\274\232", Q_NULLPTR));
        dataLabel->setText(QApplication::translate("SoToolsClass", "\346\225\260\346\215\256\347\274\226\347\240\201(Data)\357\274\232", Q_NULLPTR));
        eiVersionLabel->setText(QApplication::translate("SoToolsClass", "\345\244\264\351\203\250\347\211\210\346\234\254(Version)\357\274\232", Q_NULLPTR));
        typeLabel->setText(QApplication::translate("SoToolsClass", "\346\226\207\344\273\266\347\261\273\345\236\213(Type)\357\274\232", Q_NULLPTR));
        versionLabel->setText(QApplication::translate("SoToolsClass", "\346\226\207\344\273\266\347\211\210\346\234\254(Version)\357\274\232", Q_NULLPTR));
        entryPointLabel->setText(QApplication::translate("SoToolsClass", "\347\250\213\345\272\217\345\205\245\345\217\243(Entry point address)\357\274\232", Q_NULLPTR));
        shoffLabel->setText(QApplication::translate("SoToolsClass", "\350\212\202\345\214\272\345\244\264\351\203\250\350\241\250\346\240\274\345\201\217\347\247\273\351\207\217(Start of section headers)\357\274\232", Q_NULLPTR));
        shentsizeKeyEdit->setText(QString());
        shnumLabel->setText(QApplication::translate("SoToolsClass", "\350\212\202\345\214\272\345\244\264\351\203\250\350\241\250\346\240\274\346\225\260\347\233\256(Number of section headers)\357\274\232", Q_NULLPTR));
        shnumKeyEdit->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(elfTab), QApplication::translate("SoToolsClass", "ELF\345\244\264\351\203\250", Q_NULLPTR));
        phinfoLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(phTab), QApplication::translate("SoToolsClass", "\347\250\213\345\272\217\345\244\264\351\203\250", Q_NULLPTR));
        shinfoLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(shTab), QApplication::translate("SoToolsClass", "\350\212\202\345\214\272\345\244\264\351\203\250", Q_NULLPTR));
        menu_F->setTitle(QApplication::translate("SoToolsClass", "\346\226\207\344\273\266(&F)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SoToolsClass: public Ui_SoToolsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOTOOLS_H
