#include "linesettings.h"
#include "ui_linesettings.h"
#include <QColorDialog>
#include <QDebug>

LineSettings::LineSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LineSettings)
{
    ui->setupUi(this);
}

LineSettings::~LineSettings()
{
    delete ui;
}

void LineSettings::on_Sawe_clicked()
{
    double t = ui->tChoose->value();
    t=(100-t)/100;
    //qDebug()<<r<<" "<<g<<" "<<b<<" "<<t<<" "<<ui->isSmoothing->isChecked()<<" "<<ui->thinkChoose->value();
    emit SaveSettings(r,g,b,t,ui->isSmoothing->isChecked(),ui->thinkChoose->value());
    this->hide();
}

void LineSettings::on_colorChoose_clicked()
{
    QColor color = QColorDialog::getColor();
    r=color.red();
    g=color.green();
    b=color.blue();
}
