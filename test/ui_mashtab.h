/********************************************************************************
** Form generated from reading UI file 'mashtab.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MASHTAB_H
#define UI_MASHTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mashtab
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QDoubleSpinBox *Xshift;
    QDoubleSpinBox *Yshift;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *newH;
    QSpinBox *newW;
    QLabel *label;
    QRadioButton *Neighbor;
    QRadioButton *Bilineral;
    QRadioButton *Lanckhoz3;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *BCsplain;
    QDoubleSpinBox *Bcoef;
    QDoubleSpinBox *Ccoef;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *show;
    QPushButton *sawe;

    void setupUi(QWidget *Mashtab)
    {
        if (Mashtab->objectName().isEmpty())
            Mashtab->setObjectName(QString::fromUtf8("Mashtab"));
        Mashtab->resize(288, 216);
        verticalLayout = new QVBoxLayout(Mashtab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Xshift = new QDoubleSpinBox(Mashtab);
        Xshift->setObjectName(QString::fromUtf8("Xshift"));
        Xshift->setMinimum(-1000.000000000000000);
        Xshift->setMaximum(1000.000000000000000);

        horizontalLayout->addWidget(Xshift);

        Yshift = new QDoubleSpinBox(Mashtab);
        Yshift->setObjectName(QString::fromUtf8("Yshift"));
        Yshift->setMinimum(-1000.000000000000000);
        Yshift->setMaximum(1000.000000000000000);

        horizontalLayout->addWidget(Yshift);

        label_2 = new QLabel(Mashtab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        newH = new QSpinBox(Mashtab);
        newH->setObjectName(QString::fromUtf8("newH"));
        newH->setMaximum(5000);

        horizontalLayout_2->addWidget(newH);

        newW = new QSpinBox(Mashtab);
        newW->setObjectName(QString::fromUtf8("newW"));
        newW->setMaximum(5000);

        horizontalLayout_2->addWidget(newW);

        label = new QLabel(Mashtab);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_2);

        Neighbor = new QRadioButton(Mashtab);
        Neighbor->setObjectName(QString::fromUtf8("Neighbor"));

        verticalLayout->addWidget(Neighbor);

        Bilineral = new QRadioButton(Mashtab);
        Bilineral->setObjectName(QString::fromUtf8("Bilineral"));

        verticalLayout->addWidget(Bilineral);

        Lanckhoz3 = new QRadioButton(Mashtab);
        Lanckhoz3->setObjectName(QString::fromUtf8("Lanckhoz3"));

        verticalLayout->addWidget(Lanckhoz3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        BCsplain = new QRadioButton(Mashtab);
        BCsplain->setObjectName(QString::fromUtf8("BCsplain"));

        horizontalLayout_3->addWidget(BCsplain);

        Bcoef = new QDoubleSpinBox(Mashtab);
        Bcoef->setObjectName(QString::fromUtf8("Bcoef"));
        Bcoef->setMaximum(1.000000000000000);
        Bcoef->setSingleStep(0.100000000000000);

        horizontalLayout_3->addWidget(Bcoef);

        Ccoef = new QDoubleSpinBox(Mashtab);
        Ccoef->setObjectName(QString::fromUtf8("Ccoef"));
        Ccoef->setMaximum(1.000000000000000);
        Ccoef->setSingleStep(0.100000000000000);
        Ccoef->setValue(0.500000000000000);

        horizontalLayout_3->addWidget(Ccoef);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        show = new QPushButton(Mashtab);
        show->setObjectName(QString::fromUtf8("show"));

        horizontalLayout_5->addWidget(show);

        sawe = new QPushButton(Mashtab);
        sawe->setObjectName(QString::fromUtf8("sawe"));

        horizontalLayout_5->addWidget(sawe);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(Mashtab);

        QMetaObject::connectSlotsByName(Mashtab);
    } // setupUi

    void retranslateUi(QWidget *Mashtab)
    {
        Mashtab->setWindowTitle(QCoreApplication::translate("Mashtab", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("Mashtab", "\320\241\320\274\320\265\321\211\320\265\320\275\320\270\321\217 \320\277\320\276 X \320\270 Y", nullptr));
        label->setText(QCoreApplication::translate("Mashtab", "\320\235\320\276\320\262\321\213\320\265 \320\262\321\213\321\201\320\276\321\202\320\260 \320\270 \321\210\320\270\321\200\320\270\320\275\320\260", nullptr));
        Neighbor->setText(QCoreApplication::translate("Mashtab", "\320\221\320\273\320\270\320\266\321\204\320\271\321\210\320\270\320\271 \321\201\320\276\321\201\320\265\320\264", nullptr));
        Bilineral->setText(QCoreApplication::translate("Mashtab", "\320\221\320\270\320\273\320\270\320\275\320\265\320\271\320\275\320\276\320\265", nullptr));
        Lanckhoz3->setText(QCoreApplication::translate("Mashtab", "\320\233\320\260\320\275\321\206\320\276\321\201\320\2603", nullptr));
        BCsplain->setText(QCoreApplication::translate("Mashtab", "\320\222\320\241-\321\201\320\277\320\273\320\260\320\271\320\275", nullptr));
        show->setText(QCoreApplication::translate("Mashtab", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214", nullptr));
        sawe->setText(QCoreApplication::translate("Mashtab", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mashtab: public Ui_Mashtab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASHTAB_H
