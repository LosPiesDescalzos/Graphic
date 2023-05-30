/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *gammaCorrection;
    QAction *openFile;
    QAction *saveFile;
    QAction *dizerButton;
    QAction *mashtab;
    QAction *filter;
    QAction *contrastCorection;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QListWidget *colorChose;
    QHBoxLayout *ColorChanges;
    QCheckBox *firstCh;
    QCheckBox *secondCh;
    QCheckBox *thirdCh;
    QPushButton *changeColor;
    QHBoxLayout *file;
    QPushButton *gradGen;
    QPushButton *showImg;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        gammaCorrection = new QAction(MainWindow);
        gammaCorrection->setObjectName(QString::fromUtf8("gammaCorrection"));
        openFile = new QAction(MainWindow);
        openFile->setObjectName(QString::fromUtf8("openFile"));
        saveFile = new QAction(MainWindow);
        saveFile->setObjectName(QString::fromUtf8("saveFile"));
        dizerButton = new QAction(MainWindow);
        dizerButton->setObjectName(QString::fromUtf8("dizerButton"));
        mashtab = new QAction(MainWindow);
        mashtab->setObjectName(QString::fromUtf8("mashtab"));
        filter = new QAction(MainWindow);
        filter->setObjectName(QString::fromUtf8("filter"));
        contrastCorection = new QAction(MainWindow);
        contrastCorection->setObjectName(QString::fromUtf8("contrastCorection"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        colorChose = new QListWidget(centralwidget);
        colorChose->setObjectName(QString::fromUtf8("colorChose"));

        verticalLayout->addWidget(colorChose);

        ColorChanges = new QHBoxLayout();
        ColorChanges->setObjectName(QString::fromUtf8("ColorChanges"));
        firstCh = new QCheckBox(centralwidget);
        firstCh->setObjectName(QString::fromUtf8("firstCh"));

        ColorChanges->addWidget(firstCh);

        secondCh = new QCheckBox(centralwidget);
        secondCh->setObjectName(QString::fromUtf8("secondCh"));

        ColorChanges->addWidget(secondCh);

        thirdCh = new QCheckBox(centralwidget);
        thirdCh->setObjectName(QString::fromUtf8("thirdCh"));

        ColorChanges->addWidget(thirdCh);

        changeColor = new QPushButton(centralwidget);
        changeColor->setObjectName(QString::fromUtf8("changeColor"));

        ColorChanges->addWidget(changeColor);


        verticalLayout->addLayout(ColorChanges);

        file = new QHBoxLayout();
        file->setObjectName(QString::fromUtf8("file"));
        gradGen = new QPushButton(centralwidget);
        gradGen->setObjectName(QString::fromUtf8("gradGen"));

        file->addWidget(gradGen);

        showImg = new QPushButton(centralwidget);
        showImg->setObjectName(QString::fromUtf8("showImg"));

        file->addWidget(showImg);


        verticalLayout->addLayout(file);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu->menuAction());
        menu->addAction(gammaCorrection);
        menu->addAction(mashtab);
        menu->addAction(filter);
        menu->addAction(dizerButton);
        menu->addAction(contrastCorection);
        menu_2->addAction(openFile);
        menu_2->addAction(saveFile);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        gammaCorrection->setText(QCoreApplication::translate("MainWindow", "\320\223\320\260\320\274\320\274\320\260 \320\272\320\276\321\200\321\200\320\265\320\272\321\206\320\270\321\217", nullptr));
        openFile->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        saveFile->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        dizerButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\274\320\265\320\275\321\214\321\210\320\270\321\202\321\214 \320\277\320\260\320\273\320\270\321\202\321\200\321\203", nullptr));
        mashtab->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        filter->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\273\320\276\320\266\320\270\321\202\321\214 \321\204\320\270\320\273\321\214\321\202\321\200", nullptr));
        contrastCorection->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\321\200\320\265\320\272\321\206\320\270\321\217 \320\272\320\276\320\275\321\202\321\200\320\260\321\201\320\275\320\276\321\201\321\202\320\270", nullptr));
        firstCh->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\262\321\213\320\271 \320\272\320\260\320\275\320\260\320\273", nullptr));
        secondCh->setText(QCoreApplication::translate("MainWindow", "\320\222\321\202\320\276\321\200\320\276\320\271 \320\272\320\260\320\275\320\260\320\273", nullptr));
        thirdCh->setText(QCoreApplication::translate("MainWindow", "\320\242\321\200\320\265\321\202\320\270\320\271 \320\272\320\260\320\275\320\260\320\273", nullptr));
        changeColor->setText(QCoreApplication::translate("MainWindow", "\320\241\320\274\320\265\320\275\320\270\321\202\321\214 \321\206\320\262\320\265\321\202\320\276\320\262\320\276\320\265 \320\277\321\200\320\276\321\201\321\202\321\200\320\260\320\275\321\201\321\202\320\262\320\276", nullptr));
        gradGen->setText(QCoreApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\263\321\200\320\260\320\264\320\270\320\265\320\275\321\202", nullptr));
        showImg->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\272\320\260\321\200\321\202\320\270\320\275\320\272\321\203", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
