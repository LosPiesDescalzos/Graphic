/********************************************************************************
** Form generated from reading UI file 'filter2.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTER2_H
#define UI_FILTER2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Filter
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *porog;
    QLineEdit *lineEdit;
    QRadioButton *ocu;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *median;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *gaus;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *lineral;
    QLineEdit *lineEdit_4;
    QRadioButton *sobel;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *cas;
    QLineEdit *lineEdit_5;

    void setupUi(QWidget *Filter)
    {
        if (Filter->objectName().isEmpty())
            Filter->setObjectName(QString::fromUtf8("Filter"));
        Filter->resize(384, 250);
        verticalLayout = new QVBoxLayout(Filter);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        porog = new QRadioButton(Filter);
        porog->setObjectName(QString::fromUtf8("porog"));

        horizontalLayout_2->addWidget(porog);

        lineEdit = new QLineEdit(Filter);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        ocu = new QRadioButton(Filter);
        ocu->setObjectName(QString::fromUtf8("ocu"));

        verticalLayout->addWidget(ocu);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        median = new QRadioButton(Filter);
        median->setObjectName(QString::fromUtf8("median"));

        horizontalLayout_3->addWidget(median);

        lineEdit_2 = new QLineEdit(Filter);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_3->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        gaus = new QRadioButton(Filter);
        gaus->setObjectName(QString::fromUtf8("gaus"));

        horizontalLayout_5->addWidget(gaus);

        lineEdit_3 = new QLineEdit(Filter);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_5->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lineral = new QRadioButton(Filter);
        lineral->setObjectName(QString::fromUtf8("lineral"));

        horizontalLayout_6->addWidget(lineral);

        lineEdit_4 = new QLineEdit(Filter);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout_6->addWidget(lineEdit_4);


        verticalLayout->addLayout(horizontalLayout_6);

        sobel = new QRadioButton(Filter);
        sobel->setObjectName(QString::fromUtf8("sobel"));

        verticalLayout->addWidget(sobel);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        cas = new QRadioButton(Filter);
        cas->setObjectName(QString::fromUtf8("cas"));

        horizontalLayout_7->addWidget(cas);

        lineEdit_5 = new QLineEdit(Filter);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        horizontalLayout_7->addWidget(lineEdit_5);


        verticalLayout->addLayout(horizontalLayout_7);


        retranslateUi(Filter);

        QMetaObject::connectSlotsByName(Filter);
    } // setupUi

    void retranslateUi(QWidget *Filter)
    {
        Filter->setWindowTitle(QCoreApplication::translate("Filter", "Form", nullptr));
        porog->setText(QCoreApplication::translate("Filter", "\320\237\320\276\321\200\320\276\320\263\320\276\320\262\320\260\321\217 \321\204\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("Filter", "\320\237\320\276\321\200\320\276\320\263 \321\204\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\320\270 (0; 255)", nullptr));
        ocu->setText(QCoreApplication::translate("Filter", "\320\237\320\276\321\200\320\276\320\263\320\276\320\262\320\260\321\217 \321\204\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\321\217 \320\274\320\265\321\202\320\276\320\264\320\276\320\274 \320\236\321\206\321\203", nullptr));
        median->setText(QCoreApplication::translate("Filter", "\320\234\320\265\320\264\320\270\320\260\320\275\320\275\321\213\320\271 \321\204\320\270\320\273\321\214\321\202\321\200", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("Filter", "\320\240\320\260\320\264\320\270\321\203\321\201 \321\217\320\264\321\200\320\260", nullptr));
        gaus->setText(QCoreApplication::translate("Filter", "\320\244\320\270\320\273\321\214\321\202\321\200 \320\223\320\260\321\203\321\201\321\201\320\260", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("Filter", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200 \317\203", nullptr));
        lineral->setText(QCoreApplication::translate("Filter", "\320\233\320\270\320\275\320\265\320\271\320\275\321\213\320\271 \321\203\321\201\321\200\320\265\320\264\320\275\321\217\321\216\321\211\320\270\320\271 \321\204\320\270\320\273\321\214\321\202\321\200", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("Filter", "\320\240\320\260\320\264\320\270\321\203\321\201 \321\217\320\264\321\200\320\260", nullptr));
        sobel->setText(QCoreApplication::translate("Filter", "\320\244\320\270\320\273\321\214\321\202\321\200 \320\241\320\276\320\261\320\265\320\273\321\217", nullptr));
        cas->setText(QCoreApplication::translate("Filter", "Contrast Adaptive Sharpening", nullptr));
        lineEdit_5->setPlaceholderText(QCoreApplication::translate("Filter", "Sharpness [0.0; 1.0]", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Filter: public Ui_Filter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTER2_H
