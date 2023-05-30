#include "showimg.h"
#include "ui_showimg.h"
#include <QtDebug>
#include <QMouseEvent>

ShowImg::ShowImg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShowImg)
{
    ui->setupUi(this);
    lineSettings = new LineSettings;
    connect(lineSettings, &LineSettings::SaveSettings, this, &ShowImg::SaveSettings);
}

void ShowImg::mousePressEvent(QMouseEvent *event)
{
    //x=event->x();
    //y=event->y();
    if (startChecking){
        //qDebug()<<x<<" "<<y;
        if (isSecondClick){
            QSize cw = ui->centralwidget->size();
            QSize im = ui->img->size();
            int xd=(cw.width()-im.width())/2;
            int yd=(cw.height()-im.height())/2+26;
            emit drawLine(x-xd, y-yd, event->x()-xd, event->y()-yd,r,g,b,t,smoothing,thick);
            startChecking = false;
        }else{
            x=event->x();
            y=event->y();
            isSecondClick = true;
        }
    }
    qDebug()<<event->x()<<" "<<event->y()<<" "<<ui->centralwidget->size();
}

void ShowImg::ShowI(QPixmap pix){
    ui->img->setMaximumSize(pix.size());
    //ui->img->resize(pix.width(),pix.height());
    ui->img->setPixmap(pix);
    qDebug()<<ui->img->x()<<" "<<ui->img->sizeHint();
    //ui->img->resize(pix.width(),pix.height());
}

ShowImg::~ShowImg()
{
    delete ui;
}

void ShowImg::on_lineDraw_triggered()
{
    startChecking = true;
    isSecondClick = false;
}

void ShowImg::on_lineSettings_triggered()
{
    lineSettings->show();
}

void ShowImg::SaveSettings(int r, int g, int b, double t, bool smoothing, int thick)
{
    qDebug()<<r<<" "<<g<<" "<<b<<" "<<t<<" "<<smoothing<<" "<<thick;
    this->r=r;
    this->g=g;
    this->b=b;
    this->t=t;
    this->smoothing=smoothing;
    this->thick=thick;
}
