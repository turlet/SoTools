/********************************************************************************
** Form generated from reading UI file 'SectionWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECTIONWINDOW_H
#define UI_SECTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SectionWindowClass
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SectionWindowClass)
    {
        if (SectionWindowClass->objectName().isEmpty())
            SectionWindowClass->setObjectName(QStringLiteral("SectionWindowClass"));
        SectionWindowClass->resize(800, 600);
        centralwidget = new QWidget(SectionWindowClass);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        SectionWindowClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SectionWindowClass);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        SectionWindowClass->setMenuBar(menubar);
        statusbar = new QStatusBar(SectionWindowClass);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SectionWindowClass->setStatusBar(statusbar);

        retranslateUi(SectionWindowClass);

        QMetaObject::connectSlotsByName(SectionWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *SectionWindowClass)
    {
        SectionWindowClass->setWindowTitle(QApplication::translate("SectionWindowClass", "\350\212\202\345\214\272\344\277\241\346\201\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SectionWindowClass: public Ui_SectionWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECTIONWINDOW_H
