#include "gammacorrect.h"
#include "ui_gammacorrect.h"

GammaCorrect::GammaCorrect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GammaCorrect)
{
    ui->setupUi(this);
}

GammaCorrect::~GammaCorrect()
{
    delete ui;
}

void GammaCorrect::on_set_clicked()
{
    emit setGamma(ui->gammaSet->text());
}

void GammaCorrect::on_convert_clicked()
{
    emit convertGamma(ui->gammaConvert->text());
}
