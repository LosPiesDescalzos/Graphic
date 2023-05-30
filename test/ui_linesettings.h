/********************************************************************************
** Form generated from reading UI file 'linesettings.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINESETTINGS_H
#define UI_LINESETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LineSettings
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QCheckBox *isSmoothing;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *thinkChoose;
    QPushButton *colorChoose;
    QLabel *label_4;
    QSlider *tChoose;
    QPushButton *Sawe;

    void setupUi(QWidget *LineSettings)
    {
        if (LineSettings->objectName().isEmpty())
            LineSettings->setObjectName(QString::fromUtf8("LineSettings"));
        LineSettings->resize(325, 168);
        formLayout = new QFormLayout(LineSettings);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(LineSettings);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        isSmoothing = new QCheckBox(LineSettings);
        isSmoothing->setObjectName(QString::fromUtf8("isSmoothing"));

        formLayout->setWidget(1, QFormLayout::FieldRole, isSmoothing);

        label_2 = new QLabel(LineSettings);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(LineSettings);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        thinkChoose = new QSpinBox(LineSettings);
        thinkChoose->setObjectName(QString::fromUtf8("thinkChoose"));
        thinkChoose->setMinimum(1);
        thinkChoose->setMaximum(15);
        thinkChoose->setSingleStep(2);

        formLayout->setWidget(2, QFormLayout::FieldRole, thinkChoose);

        colorChoose = new QPushButton(LineSettings);
        colorChoose->setObjectName(QString::fromUtf8("colorChoose"));

        formLayout->setWidget(3, QFormLayout::FieldRole, colorChoose);

        label_4 = new QLabel(LineSettings);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        tChoose = new QSlider(LineSettings);
        tChoose->setObjectName(QString::fromUtf8("tChoose"));
        tChoose->setMaximum(100);
        tChoose->setOrientation(Qt::Horizontal);

        formLayout->setWidget(0, QFormLayout::FieldRole, tChoose);

        Sawe = new QPushButton(LineSettings);
        Sawe->setObjectName(QString::fromUtf8("Sawe"));

        formLayout->setWidget(5, QFormLayout::FieldRole, Sawe);


        retranslateUi(LineSettings);

        QMetaObject::connectSlotsByName(LineSettings);
    } // setupUi

    void retranslateUi(QWidget *LineSettings)
    {
        LineSettings->setWindowTitle(QCoreApplication::translate("LineSettings", "Form", nullptr));
        label->setText(QCoreApplication::translate("LineSettings", "\320\237\321\200\320\276\320\267\321\200\320\260\321\207\320\275\320\276\321\201\321\202\321\214 \320\273\320\270\320\275\320\270\320\270", nullptr));
        isSmoothing->setText(QCoreApplication::translate("LineSettings", "\320\241\320\263\320\273\320\260\320\264\320\270\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("LineSettings", "\320\241\320\263\320\273\320\260\320\266\320\270\320\262\320\260\320\275\320\270\320\265 \320\273\320\270\320\275\320\270\320\270", nullptr));
        label_3->setText(QCoreApplication::translate("LineSettings", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260 \320\273\320\270\320\275\320\270\320\270 (\321\202\320\276\320\273\321\214\320\272\320\276 \320\275\320\265\321\207\320\265\321\202\320\275\321\213\320\265)", nullptr));
        colorChoose->setText(QCoreApplication::translate("LineSettings", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("LineSettings", "\320\222\321\213\320\261\320\276\321\200 \321\206\320\262\320\265\321\202\320\260 \320\273\320\270\320\275\320\270\320\270", nullptr));
        Sawe->setText(QCoreApplication::translate("LineSettings", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LineSettings: public Ui_LineSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINESETTINGS_H
