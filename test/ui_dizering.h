/********************************************************************************
** Form generated from reading UI file 'dizering.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIZERING_H
#define UI_DIZERING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dizering
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *bitnost;
    QLabel *label;
    QRadioButton *noDizering;
    QRadioButton *ordDizering;
    QRadioButton *randDizering;
    QRadioButton *floydDizering;
    QRadioButton *atkiDizering;
    QHBoxLayout *horizontalLayout;
    QPushButton *showDiz;
    QPushButton *saveDiz;

    void setupUi(QWidget *Dizering)
    {
        if (Dizering->objectName().isEmpty())
            Dizering->setObjectName(QString::fromUtf8("Dizering"));
        Dizering->resize(306, 279);
        verticalLayout_2 = new QVBoxLayout(Dizering);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        bitnost = new QSpinBox(Dizering);
        bitnost->setObjectName(QString::fromUtf8("bitnost"));
        bitnost->setMinimum(1);
        bitnost->setMaximum(8);

        horizontalLayout_3->addWidget(bitnost);

        label = new QLabel(Dizering);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);


        verticalLayout_2->addLayout(horizontalLayout_3);

        noDizering = new QRadioButton(Dizering);
        noDizering->setObjectName(QString::fromUtf8("noDizering"));

        verticalLayout_2->addWidget(noDizering);

        ordDizering = new QRadioButton(Dizering);
        ordDizering->setObjectName(QString::fromUtf8("ordDizering"));

        verticalLayout_2->addWidget(ordDizering);

        randDizering = new QRadioButton(Dizering);
        randDizering->setObjectName(QString::fromUtf8("randDizering"));

        verticalLayout_2->addWidget(randDizering);

        floydDizering = new QRadioButton(Dizering);
        floydDizering->setObjectName(QString::fromUtf8("floydDizering"));

        verticalLayout_2->addWidget(floydDizering);

        atkiDizering = new QRadioButton(Dizering);
        atkiDizering->setObjectName(QString::fromUtf8("atkiDizering"));

        verticalLayout_2->addWidget(atkiDizering);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        showDiz = new QPushButton(Dizering);
        showDiz->setObjectName(QString::fromUtf8("showDiz"));

        horizontalLayout->addWidget(showDiz);

        saveDiz = new QPushButton(Dizering);
        saveDiz->setObjectName(QString::fromUtf8("saveDiz"));

        horizontalLayout->addWidget(saveDiz);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(Dizering);

        QMetaObject::connectSlotsByName(Dizering);
    } // setupUi

    void retranslateUi(QWidget *Dizering)
    {
        Dizering->setWindowTitle(QCoreApplication::translate("Dizering", "Form", nullptr));
        label->setText(QCoreApplication::translate("Dizering", "\320\221\320\270\321\202\320\275\320\276\321\201\321\202\321\214", nullptr));
        noDizering->setText(QCoreApplication::translate("Dizering", "\320\221\320\265\320\267 \320\264\320\270\320\267\320\265\321\200\320\270\320\275\320\263\320\260", nullptr));
        ordDizering->setText(QCoreApplication::translate("Dizering", "Ordered dizering(8x8)", nullptr));
        randDizering->setText(QCoreApplication::translate("Dizering", "Random dizering", nullptr));
        floydDizering->setText(QCoreApplication::translate("Dizering", "Floyd-Steinberg dizering", nullptr));
        atkiDizering->setText(QCoreApplication::translate("Dizering", "Atkinson dizering", nullptr));
        showDiz->setText(QCoreApplication::translate("Dizering", "\320\237\321\200\320\265\320\264\320\277\321\200\320\276\321\201\320\274\320\276\321\202\321\200", nullptr));
        saveDiz->setText(QCoreApplication::translate("Dizering", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dizering: public Ui_Dizering {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIZERING_H
