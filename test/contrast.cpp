#include "contrast.h"
#include "ui_contrast.h"

Contrast::Contrast(QByteArray arr, int w, int h,int firstBytePix, bool isGray, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Contrast)
{
    if (isGray){
        gray=1;
    }
    bar.resize(gray);
    data.resize(gray);
    this->w=w;
    this->h=h;
    this->firstBytePix=firstBytePix;
    ui->setupUi(this);
    block = arr;
    CountData(block);
    setHists(true);
}

Contrast::~Contrast()
{
    delete ui;
}

void Contrast::CountData(QByteArray arr)
{
    for (int i = 0; i < gray; ++i) {
        data[i].clear();
        data[i].resize(256);
        data[i][0]=0;
    }
    for (int i = firstBytePix; i < arr.size(); ++i) {
        data[(i-firstBytePix)%gray][(unsigned char)arr[i]]++;
    }
}

void Contrast::setHists(bool firsttime)
{
    if (gray==1){
        makeHist(data[0],"Grey",ui->hist1,0, firsttime);
    }else{
        makeHist(data[0],"Red",ui->hist1,0, firsttime);
        makeHist(data[1],"Green",ui->hist2,1, firsttime);
        makeHist(data[2],"Blue",ui->hist3,2, firsttime);
    }
}

void Contrast::makeHist(QVector<double> data, QString color, QCustomPlot *customPlot, int index, bool firsttime)
{
    QVector<double> ticks;
    ticks.resize(data.size());
    int m=0;
    for (int i = 0; i < data.size(); ++i) {
        if (data[i]>m) m=data[i];
        ticks[i]=i;
    }
    if (firsttime){
        //ui->setupUi(this);

        // set dark background gradient:
        QLinearGradient gradient(0, 0, 0, 400);
        gradient.setColorAt(0, QColor(90, 90, 90));
        gradient.setColorAt(0.38, QColor(105, 105, 105));
        gradient.setColorAt(1, QColor(70, 70, 70));
        customPlot->setBackground(QBrush(gradient));

        // create empty bar chart objects:
        QCPBars *regen = new QCPBars(customPlot->xAxis, customPlot->yAxis);
        regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders
        regen->setStackingGap(1);
        // set names and colors:
        regen->setName(color);
        if (color=="Red"){
            regen->setPen(QPen(QColor(255, 0, 0).lighter(130)));
            regen->setBrush(QColor(255, 0, 0));
        }else if (color=="Green"){
            regen->setPen(QPen(QColor(0, 255, 0).lighter(130)));
            regen->setBrush(QColor(0, 255, 0));
        }else{
            regen->setPen(QPen(QColor(0, 0, 255).lighter(130)));
            regen->setBrush(QColor(0, 0, 255));
        }

        // stack bars on top of each other:

        //nuclear->moveAbove(fossil);
        //regen->moveAbove(nuclear);

        // prepare x axis with country labels:
        customPlot->xAxis->setRange(0, 255.1);
        customPlot->xAxis->setBasePen(QPen(Qt::white));
        customPlot->xAxis->setTickPen(QPen(Qt::white));
        customPlot->xAxis->grid()->setVisible(true);
        customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
        customPlot->xAxis->setTickLabelColor(Qt::white);
        customPlot->xAxis->setLabelColor(Qt::white);

        // prepare y axis:
        customPlot->yAxis->setRange(0, m+1);
        customPlot->yAxis->setPadding(5); // a bit more space to the left border
        customPlot->yAxis->setBasePen(QPen(Qt::white));
        customPlot->yAxis->setTickPen(QPen(Qt::white));
        customPlot->yAxis->setSubTickPen(QPen(Qt::white));
        customPlot->yAxis->grid()->setSubGridVisible(true);
        customPlot->yAxis->setTickLabelColor(Qt::white);
        customPlot->yAxis->setLabelColor(Qt::white);
        customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
        customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

        // Add data:
        regen->setData(ticks, data);

        // setup legend:
        customPlot->legend->setVisible(true);
        customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
        customPlot->legend->setBrush(QColor(255, 255, 255, 100));
        customPlot->legend->setBorderPen(Qt::NoPen);
        QFont legendFont = font();
        legendFont.setPointSize(10);
        customPlot->legend->setFont(legendFont);
        customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
        bar[index]=regen;
    }else{
        bar[index]->setData(ticks, data);
    }
    //customPlot->show();
}

QByteArray Contrast::ChangeContrast(QByteArray arr)
{
    int all=w*h,min=256,max=-1,sum;
    int ignor = all*ui->ignor->value()/100;

    for (int i = 0; i < gray; ++i) {
        sum=0;
        for (int j = 0; j < data[i].size(); ++j) {
            sum+=data[i][j];
            if (sum>ignor){
                j--;
                if (j<min){
                    min=j;
                }
                break;
            }
        }

        sum=0;
        for (int j = data[i].size()-1; j >= 0; --j) {
            sum+=data[i][j];
            if (sum>ignor){
                j++;
                if (j>max){
                    max=j;
                }
                break;
            }
        }
    }
    qDebug()<<min<<max<<(min+(255-max))<<(255.0/(max-min));
    if (min<0) min=0;
    if (max>255) max=255;
    int t;
    for (int i = firstBytePix; i < arr.size(); ++i) {
        t=(unsigned char)arr[i];
        t-=(min+(255-max));
        t*=(255.0/(max-min));
        if (t>255) t=255;
        if (t<0) t=0;
        arr[i]=t;
    }
    return arr;
}

int Contrast::Pix(int x, int y, bool re)
{
    if (re) return firstBytePix+x*gray*w+gray*y;
    return firstBytePix+y*gray*w+gray*x;
}

void Contrast::on_show_clicked()
{
    QByteArray temp;
    temp=ChangeContrast(block);
    CountData(temp);
    setHists();
    CountData(block);
    emit showDizer(temp, false);
}

void Contrast::on_sawe_clicked()
{
    QByteArray temp;
    temp=ChangeContrast(block);
    CountData(temp);
    setHists();
    CountData(block);
    emit showDizer(temp, true);
}
