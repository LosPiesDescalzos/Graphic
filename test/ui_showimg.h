/********************************************************************************
** Form generated from reading UI file 'showimg.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWIMG_H
#define UI_SHOWIMG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowImg
{
public:
    QAction *lineSettings;
    QAction *lineDraw;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *img;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ShowImg)
    {
        if (ShowImg->objectName().isEmpty())
            ShowImg->setObjectName(QString::fromUtf8("ShowImg"));
        ShowImg->resize(800, 600);
        lineSettings = new QAction(ShowImg);
        lineSettings->setObjectName(QString::fromUtf8("lineSettings"));
        lineDraw = new QAction(ShowImg);
        lineDraw->setObjectName(QString::fromUtf8("lineDraw"));
        centralwidget = new QWidget(ShowImg);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        img = new QLabel(centralwidget);
        img->setObjectName(QString::fromUtf8("img"));
        img->setMouseTracking(true);

        gridLayout->addWidget(img, 0, 0, 1, 1);

        ShowImg->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ShowImg);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menu);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        ShowImg->setMenuBar(menubar);
        statusbar = new QStatusBar(ShowImg);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ShowImg->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(menu_2->menuAction());
        menu_2->addAction(lineSettings);
        menu_2->addAction(lineDraw);

        retranslateUi(ShowImg);

        QMetaObject::connectSlotsByName(ShowImg);
    } // setupUi

    void retranslateUi(QMainWindow *ShowImg)
    {
        ShowImg->setWindowTitle(QCoreApplication::translate("ShowImg", "MainWindow", nullptr));
        lineSettings->setText(QCoreApplication::translate("ShowImg", "\320\235\320\260\321\201\321\202\321\200\320\276\320\270\321\202\321\214", nullptr));
        lineDraw->setText(QCoreApplication::translate("ShowImg", "\320\240\320\270\321\201\320\276\320\262\320\260\321\202\321\214", nullptr));
        img->setText(QCoreApplication::translate("ShowImg", "TextLabel", nullptr));
        menu->setTitle(QCoreApplication::translate("ShowImg", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        menu_2->setTitle(QCoreApplication::translate("ShowImg", "\320\233\320\270\320\275\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowImg: public Ui_ShowImg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWIMG_H
