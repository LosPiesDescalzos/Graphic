/********************************************************************************
** Form generated from reading UI file 'gammacorrect.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMMACORRECT_H
#define UI_GAMMACORRECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GammaCorrect
{
public:
    QGridLayout *gridLayout;
    QPushButton *convert;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *gammaSet;
    QPushButton *set;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *gammaConvert;

    void setupUi(QWidget *GammaCorrect)
    {
        if (GammaCorrect->objectName().isEmpty())
            GammaCorrect->setObjectName(QString::fromUtf8("GammaCorrect"));
        GammaCorrect->resize(400, 300);
        gridLayout = new QGridLayout(GammaCorrect);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        convert = new QPushButton(GammaCorrect);
        convert->setObjectName(QString::fromUtf8("convert"));

        gridLayout->addWidget(convert, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(GammaCorrect);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        gammaSet = new QLineEdit(GammaCorrect);
        gammaSet->setObjectName(QString::fromUtf8("gammaSet"));
        gammaSet->setEnabled(true);
        gammaSet->setAutoFillBackground(false);

        horizontalLayout_2->addWidget(gammaSet);


        gridLayout->addLayout(horizontalLayout_2, 5, 0, 1, 1);

        set = new QPushButton(GammaCorrect);
        set->setObjectName(QString::fromUtf8("set"));

        gridLayout->addWidget(set, 7, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(GammaCorrect);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        gammaConvert = new QLineEdit(GammaCorrect);
        gammaConvert->setObjectName(QString::fromUtf8("gammaConvert"));

        horizontalLayout->addWidget(gammaConvert);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(GammaCorrect);

        QMetaObject::connectSlotsByName(GammaCorrect);
    } // setupUi

    void retranslateUi(QWidget *GammaCorrect)
    {
        GammaCorrect->setWindowTitle(QCoreApplication::translate("GammaCorrect", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\263\320\260\320\274\320\274\321\213", nullptr));
        convert->setText(QCoreApplication::translate("GammaCorrect", "\320\237\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("GammaCorrect", "\320\235\320\260\320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\263\320\260\320\274\320\274\321\213", nullptr));
        gammaSet->setText(QString());
        gammaSet->setPlaceholderText(QCoreApplication::translate("GammaCorrect", "\320\276\321\202 -100 \320\264\320\276 100", nullptr));
        set->setText(QCoreApplication::translate("GammaCorrect", "\320\235\320\260\320\267\320\275\320\260\321\207\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("GammaCorrect", "\320\237\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\270\320\265 \320\262 \320\275\320\260\320\267\320\275\320\260\321\207\320\265\320\275\320\275\321\203\321\216 \320\263\320\260\320\274\320\274\321\203", nullptr));
        gammaConvert->setText(QString());
        gammaConvert->setPlaceholderText(QCoreApplication::translate("GammaCorrect", "\320\276\321\202 -100 \320\264\320\276 100", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GammaCorrect: public Ui_GammaCorrect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMMACORRECT_H
