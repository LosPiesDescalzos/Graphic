/********************************************************************************
** Form generated from reading UI file 'filter.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTER_H
#define UI_FILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Filter
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *porog;
    QSpinBox *porogValue;
    QRadioButton *ocu;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *median;
    QSpinBox *medYadro;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *gaus;
    QSpinBox *gausYadro;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *lineraMed;
    QSpinBox *linYadro;
    QRadioButton *sobel;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *CAS;
    QDoubleSpinBox *sharpness;
    QHBoxLayout *horizontalLayout;
    QPushButton *show;
    QPushButton *sawe;

    void setupUi(QWidget *Filter)
    {
        if (Filter->objectName().isEmpty())
            Filter->setObjectName(QString::fromUtf8("Filter"));
        Filter->resize(400, 300);
        verticalLayout = new QVBoxLayout(Filter);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        porog = new QRadioButton(Filter);
        porog->setObjectName(QString::fromUtf8("porog"));

        horizontalLayout_2->addWidget(porog);

        porogValue = new QSpinBox(Filter);
        porogValue->setObjectName(QString::fromUtf8("porogValue"));
        porogValue->setMinimum(1);
        porogValue->setMaximum(254);

        horizontalLayout_2->addWidget(porogValue);


        verticalLayout->addLayout(horizontalLayout_2);

        ocu = new QRadioButton(Filter);
        ocu->setObjectName(QString::fromUtf8("ocu"));

        verticalLayout->addWidget(ocu);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        median = new QRadioButton(Filter);
        median->setObjectName(QString::fromUtf8("median"));

        horizontalLayout_4->addWidget(median);

        medYadro = new QSpinBox(Filter);
        medYadro->setObjectName(QString::fromUtf8("medYadro"));
        medYadro->setMinimum(1);

        horizontalLayout_4->addWidget(medYadro);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        gaus = new QRadioButton(Filter);
        gaus->setObjectName(QString::fromUtf8("gaus"));

        horizontalLayout_3->addWidget(gaus);

        gausYadro = new QSpinBox(Filter);
        gausYadro->setObjectName(QString::fromUtf8("gausYadro"));
        gausYadro->setMinimum(1);

        horizontalLayout_3->addWidget(gausYadro);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lineraMed = new QRadioButton(Filter);
        lineraMed->setObjectName(QString::fromUtf8("lineraMed"));

        horizontalLayout_5->addWidget(lineraMed);

        linYadro = new QSpinBox(Filter);
        linYadro->setObjectName(QString::fromUtf8("linYadro"));
        linYadro->setMinimum(1);

        horizontalLayout_5->addWidget(linYadro);


        verticalLayout->addLayout(horizontalLayout_5);

        sobel = new QRadioButton(Filter);
        sobel->setObjectName(QString::fromUtf8("sobel"));

        verticalLayout->addWidget(sobel);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        CAS = new QRadioButton(Filter);
        CAS->setObjectName(QString::fromUtf8("CAS"));

        horizontalLayout_6->addWidget(CAS);

        sharpness = new QDoubleSpinBox(Filter);
        sharpness->setObjectName(QString::fromUtf8("sharpness"));
        sharpness->setMaximum(1.000000000000000);
        sharpness->setSingleStep(0.100000000000000);

        horizontalLayout_6->addWidget(sharpness);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        show = new QPushButton(Filter);
        show->setObjectName(QString::fromUtf8("show"));

        horizontalLayout->addWidget(show);

        sawe = new QPushButton(Filter);
        sawe->setObjectName(QString::fromUtf8("sawe"));

        horizontalLayout->addWidget(sawe);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Filter);

        QMetaObject::connectSlotsByName(Filter);
    } // setupUi

    void retranslateUi(QWidget *Filter)
    {
        Filter->setWindowTitle(QCoreApplication::translate("Filter", "Form", nullptr));
        porog->setText(QCoreApplication::translate("Filter", "\320\237\320\276\321\200\320\276\320\263\320\276\320\262\320\260\321\217 \321\204\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\321\217, \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\277\320\276\321\200\320\276\320\263\320\260:", nullptr));
        ocu->setText(QCoreApplication::translate("Filter", "\320\237\320\276\321\200\320\276\320\263\320\276\320\262\320\260\321\217 \321\204\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\321\217 \320\274\320\265\321\202\320\276\320\264\320\276\320\274 \320\236\321\206\321\203", nullptr));
        median->setText(QCoreApplication::translate("Filter", "\320\234\320\265\320\264\320\270\320\260\320\275\320\275\321\213\320\271 \321\204\320\270\320\273\321\214\321\202\321\200, \321\200\320\260\320\264\320\270\321\203\321\201 \321\217\320\264\321\200\320\260:", nullptr));
        gaus->setText(QCoreApplication::translate("Filter", "\320\244\320\270\320\273\321\214\321\202\321\200 \320\263\320\260\321\203\321\201\320\260, \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200 \317\203:", nullptr));
        lineraMed->setText(QCoreApplication::translate("Filter", "\320\233\320\270\320\275\320\265\320\271\320\275\321\213\320\271 \321\203\321\201\321\200\320\265\320\264\320\275\321\217\321\216\321\211\320\270\320\271 \321\204\320\270\320\273\321\214\321\202\321\200, \321\200\320\260\320\264\320\270\321\203\321\201 \321\217\320\264\321\200\320\260:", nullptr));
        sobel->setText(QCoreApplication::translate("Filter", "\320\244\320\270\320\273\321\214\321\202\321\200 \321\201\320\276\320\261\320\265\320\273\321\217", nullptr));
        CAS->setText(QCoreApplication::translate("Filter", "Contrast Adaptive Sharpnes, sharpness:", nullptr));
        show->setText(QCoreApplication::translate("Filter", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214", nullptr));
        sawe->setText(QCoreApplication::translate("Filter", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Filter: public Ui_Filter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTER_H
