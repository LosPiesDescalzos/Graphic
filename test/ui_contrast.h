/********************************************************************************
** Form generated from reading UI file 'contrast.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTRAST_H
#define UI_CONTRAST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Contrast
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QCustomPlot *hist1;
    QCustomPlot *hist2;
    QCustomPlot *hist3;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QDoubleSpinBox *ignor;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *show;
    QPushButton *sawe;

    void setupUi(QWidget *Contrast)
    {
        if (Contrast->objectName().isEmpty())
            Contrast->setObjectName(QString::fromUtf8("Contrast"));
        Contrast->resize(1358, 370);
        gridLayout = new QGridLayout(Contrast);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        hist1 = new QCustomPlot(Contrast);
        hist1->setObjectName(QString::fromUtf8("hist1"));

        horizontalLayout_2->addWidget(hist1);

        hist2 = new QCustomPlot(Contrast);
        hist2->setObjectName(QString::fromUtf8("hist2"));

        horizontalLayout_2->addWidget(hist2);

        hist3 = new QCustomPlot(Contrast);
        hist3->setObjectName(QString::fromUtf8("hist3"));

        horizontalLayout_2->addWidget(hist3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_2->addItem(verticalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        ignor = new QDoubleSpinBox(Contrast);
        ignor->setObjectName(QString::fromUtf8("ignor"));
        ignor->setMaximum(50.000000000000000);
        ignor->setSingleStep(0.100000000000000);

        horizontalLayout_3->addWidget(ignor);

        label = new QLabel(Contrast);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        show = new QPushButton(Contrast);
        show->setObjectName(QString::fromUtf8("show"));

        horizontalLayout->addWidget(show);

        sawe = new QPushButton(Contrast);
        sawe->setObjectName(QString::fromUtf8("sawe"));

        horizontalLayout->addWidget(sawe);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 2, 0, 1, 1);


        retranslateUi(Contrast);

        QMetaObject::connectSlotsByName(Contrast);
    } // setupUi

    void retranslateUi(QWidget *Contrast)
    {
        Contrast->setWindowTitle(QCoreApplication::translate("Contrast", "Form", nullptr));
        label->setText(QCoreApplication::translate("Contrast", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202 \320\270\320\263\320\275\320\276\321\200\320\270\321\200\321\203\320\265\320\274\321\213\321\205 \320\277\320\270\320\272\321\201\320\265\320\273\320\265\320\271 [0;0.5]", nullptr));
        show->setText(QCoreApplication::translate("Contrast", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214", nullptr));
        sawe->setText(QCoreApplication::translate("Contrast", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Contrast: public Ui_Contrast {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTRAST_H
