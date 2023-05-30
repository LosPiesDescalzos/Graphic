#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QRgb>
#include <QPainter>
#include <QtZlib/zlib.h>
#include <inttypes.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->colorChose->addItem("RGB");
    ui->colorChose->addItem("HSL");
    ui->colorChose->addItem("HSV");
    ui->colorChose->addItem("YCbCr.601");
    ui->colorChose->addItem("YCbCr.709");
    ui->colorChose->addItem("YCoCg");
    ui->colorChose->addItem("CMY");

    ui->firstCh->setChecked(true);
    ui->secondCh->setChecked(true);
    ui->thirdCh->setChecked(true);

    gammaCorect = new GammaCorrect;
    showImg = new ShowImg;
    connect(gammaCorect, &GammaCorrect::setGamma, this, &MainWindow::setGamma);
    connect(gammaCorect, &GammaCorrect::convertGamma, this, &MainWindow::convertGamma);
    connect(showImg, &ShowImg::drawLine, this, &MainWindow::drLine);
    /*QColor color = QColorDialog::getColor();
    qDebug()<<color.red()<<" "<<color.green()<<" "<<color.blue()<<" ";*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drLine(int x1, int y1, int x2, int y2, int r, int g, int b, double t, bool smoothing, int thick)
{
    RGBblock = DrawLine(RGBblock, x1, y1, x2, y2,r,g,b,t,smoothing,thick);
    block = ConvertFromRGB(RGBblock);
    block = ChanelCheck(block);
    picture = CorrectGam(ConvertToRGB(block));
    showImg->ShowI(picture);
}

void MainWindow::setGamma(QString gam)
{
    gamma=gam.toDouble();
    ui->statusbar->showMessage(gam);
}

void MainWindow::convertGamma(QString gam)
{
    gamma=gam.toDouble();
    CorrectGam(RGBblock,true);
    ui->statusbar->showMessage(gam);
}

void MainWindow::showDizer(QByteArray arr, bool save)
{
    showImg->show();
    picture = CorrectGam(arr);
    showImg->ShowI(picture);
    if (save){
        RGBblock = arr;
        block=ConvertFromRGB(RGBblock);
    }
}

void MainWindow::showZoom(QByteArray arr, bool save, int w, int h)
{
    int tempW=this->w;
    int tempH=this->h;
    this->w=w;
    this->h=h;
    showImg->show();
    picture = CorrectGam(arr);
    showImg->ShowI(picture);
    if (save){
        RGBblock = arr;
        block=ConvertFromRGB(RGBblock);
    }else{
        this->w=tempW;
        this->h=tempH;
    }
}

QPixmap MainWindow::ConvertBytToPix (QByteArray arr, int startI){
    QImage im(w,h,QImage::Format_RGB888);
    QRgb value;
    for (int i=0;i<h;++i){
        for (int j=0;j<w;++j){
            if (!isGrey){
                value = qRgb((unsigned char)arr[startI],(unsigned char)arr[startI+1],(unsigned char)arr[startI+2]);
                startI+=3;
            }else{
                value = qRgb((unsigned char)arr[startI],(unsigned char)arr[startI],(unsigned char)arr[startI]);
                startI++;
            }
            im.setPixel(j,i,value);
        }
    }

    QPixmap pic = QPixmap::fromImage(im);
    return pic;
}

void MainWindow::on_showImg_clicked()
{
    //showImg = new ShowImg();
    showImg->show();
    picture = CorrectGam(ConvertToRGB(block));
    showImg->ShowI(picture);
}

QByteArray MainWindow::ConvertToRGB (QByteArray arr){

    std::map <QString, int> mapping;

    mapping["RGB"]=0;
    mapping["HSL"]=1;
    mapping["HSV"]=2;
    mapping["YCbCr.601"]=3;
    mapping["YCbCr.709"]=4;
    mapping["YCoCg"]=5;
    mapping["CMY"]=6;

    if (mapping[colorType]==0) return arr;

    QByteArray narr=arr;

    switch (mapping[colorType]) {
    case 1:
        for(int i=firstPixByte;i<arr.size();i+=3){
            std::tuple<int,int,int> tup = ColC.HSLinRGB((unsigned char)arr[i],(unsigned char)arr[i+1],(unsigned char)arr[i+2]);
            narr[i]=std::get<0>(tup);
            narr[i+1]=std::get<1>(tup);
            narr[i+2]=std::get<2>(tup);
        }
        return narr;
        break;

    case 2:
        for(int i=firstPixByte;i<arr.size();i+=3){
            std::tuple<int,int,int> tup = ColC.HSVinRGB((unsigned char)arr[i],(unsigned char)arr[i+1],(unsigned char)arr[i+2]);
            narr[i]=std::get<0>(tup);
            narr[i+1]=std::get<1>(tup);
            narr[i+2]=std::get<2>(tup);
        }
        return narr;
        break;

    case 3:
        for(int i=firstPixByte;i<arr.size();i+=3){
            std::tuple<int,int,int> tup = ColC.YCbCrinRGB((unsigned char)arr[i],(unsigned char)arr[i+1],(unsigned char)arr[i+2],true);
            narr[i]=std::get<0>(tup);
            narr[i+1]=std::get<1>(tup);
            narr[i+2]=std::get<2>(tup);
        }
        return narr;
        break;

    case 4:
        for(int i=firstPixByte;i<arr.size();i+=3){
            std::tuple<int,int,int> tup = ColC.YCbCrinRGB((unsigned char)arr[i],(unsigned char)arr[i+1],(unsigned char)arr[i+2],false);
            narr[i]=std::get<0>(tup);
            narr[i+1]=std::get<1>(tup);
            narr[i+2]=std::get<2>(tup);
        }
        return narr;
        break;

    case 5:
        for(int i=firstPixByte;i<arr.size();i+=3){
            std::tuple<int,int,int> tup = ColC.YCoCginRGB((unsigned char)arr[i],(unsigned char)arr[i+1],(unsigned char)arr[i+2]);
            narr[i]=std::get<0>(tup);
            narr[i+1]=std::get<1>(tup);
            narr[i+2]=std::get<2>(tup);
        }
        return narr;
        break;

    case 6:
        for(int i=firstPixByte;i<arr.size();i+=3){
            std::tuple<int,int,int> tup = ColC.CMYinRGB((unsigned char)arr[i],(unsigned char)arr[i+1],(unsigned char)arr[i+2]);
            narr[i]=std::get<0>(tup);
            narr[i+1]=std::get<1>(tup);
            narr[i+2]=std::get<2>(tup);
        }
        return narr;
        break;

    default:
        return narr;
        break;
    }
}

QByteArray MainWindow::ConvertFromRGB (QByteArray arr){

    std::map <QString, int> mapping;

    mapping["RGB"]=0;
    mapping["HSL"]=1;
    mapping["HSV"]=2;
    mapping["YCbCr.601"]=3;
    mapping["YCbCr.709"]=4;
    mapping["YCoCg"]=5;
    mapping["CMY"]=6;

    if (mapping[colorType]==0) return arr;

    QByteArray narr=arr;

    switch (mapping[colorType]) {
    case 1:
        for(int i=firstPixByte;i<arr.size();i+=3){
            std::tuple<int,int,int> tup = ColC.RGBinHSL((unsigned char)arr[i],(unsigned char)arr[i+1],(unsigned char)arr[i+2]);
            narr[i]=std::get<0>(tup);
            narr[i+1]=std::get<1>(tup);
            narr[i+2]=std::get<2>(tup);
        }
        return narr;
        break;

    case 2:
        for(int i=firstPixByte;i<arr.size();i+=3){
            std::tuple<int,int,int> tup = ColC.RGBinHSV((unsigned char)arr[i],(unsigned char)arr[i+1],(unsigned char)arr[i+2]);
            narr[i]=std::get<0>(tup);
            narr[i+1]=std::get<1>(tup);
            narr[i+2]=std::get<2>(tup);
        }
        return narr;
        break;

    case 3:
        for(int i=firstPixByte;i<arr.size();i+=3){
            std::tuple<int,int,int> tup = ColC.RGBinYCbCr((unsigned char)arr[i],(unsigned char)arr[i+1],(unsigned char)arr[i+2],true);
            narr[i]=std::get<0>(tup);
            narr[i+1]=std::get<1>(tup);
            narr[i+2]=std::get<2>(tup);
        }
        return narr;
        break;

    case 4:
        for(int i=firstPixByte;i<arr.size();i+=3){
            std::tuple<int,int,int> tup = ColC.RGBinYCbCr((unsigned char)arr[i],(unsigned char)arr[i+1],(unsigned char)arr[i+2],false);
            narr[i]=std::get<0>(tup);
            narr[i+1]=std::get<1>(tup);
            narr[i+2]=std::get<2>(tup);
        }
        return narr;
        break;

    case 5:
        for(int i=firstPixByte;i<arr.size();i+=3){
            std::tuple<int,int,int> tup = ColC.RGBinYCoCg((unsigned char)arr[i],(unsigned char)arr[i+1],(unsigned char)arr[i+2]);
            narr[i]=std::get<0>(tup);
            narr[i+1]=std::get<1>(tup);
            narr[i+2]=std::get<2>(tup);
        }
        return narr;
        break;

    case 6:
        for(int i=firstPixByte;i<arr.size();i+=3){
            std::tuple<int,int,int> tup = ColC.RGBinCMY((unsigned char)arr[i],(unsigned char)arr[i+1],(unsigned char)arr[i+2]);
            narr[i]=std::get<0>(tup);
            narr[i+1]=std::get<1>(tup);
            narr[i+2]=std::get<2>(tup);
        }
        return narr;
        break;

    default:
        return narr;
        break;
    }
}

void MainWindow::on_changeColor_clicked()
{
    colorType = ui->colorChose->currentItem()->text();
    block = ConvertFromRGB(RGBblock);
    block = ChanelCheck(block);
    //RGBblock = ConvertToRGB(block);

}

QByteArray MainWindow::ChanelCheck(QByteArray arr){
    QByteArray narr = arr;
    int temp[3];
    if (ui->firstCh->isChecked()){
        temp[0]=1;
    }else{
        temp[0]=0;
    }
    if (ui->secondCh->isChecked()){
        temp[1]=1;
    }else{
        temp[1]=0;
    }
    if (ui->thirdCh->isChecked()){
        temp[2]=1;
    }else{
        temp[2]=0;
    }
    for (int i = firstPixByte;i<narr.size();i+=3){
        for (int j=0;j<3;++j){
            double rr=narr[i+0]/255.0,rg=narr[i+1]/255.0,rb=narr[i+2]/255.0;
            double y = 0.25*rr+0.5*rg+0.25*rb;
            if (!temp[j]){
                if ((colorType=="YCoCg"&&j<0)||((colorType=="HSL"||colorType=="HSV")&&j>0)||colorType=="YCbCr.601"||colorType=="YCbCr.709"||colorType=="YCoCg"){
                    narr[i+j]=127;
                }else{
                    narr[i+j]=0;
                }
            }
            //narr[i]=255*y;
        }
    }
    return narr;
}

void MainWindow::on_gammaCorrection_triggered()
{
    gammaCorect->show();
}

QByteArray MainWindow::DrawLine(QByteArray arr, int x1, int y1, int x2, int y2, int r, int g, int b, double t, bool smoothing, int thick){
    bool re=false;
    QByteArray narr=arr;
    if (x1>x2){
        std::swap(x1,x2);
        std::swap(y1,y2);
    }
    if(1.0*std::abs(y2-y1)/std::abs(x2-x1)>1){
        std::swap(x1,y1);
        std::swap(x2,y2);
        if (y1>y2){
            std::swap(x1,x2);
            std::swap(y1,y2);
        }
        re = true;
    }
    thick=(thick+1)/2;
    double k,c=0;
    double grad=1.0*(y2-y1)/(x2-x1),Y=y1;
    for (int i=x1;i<x2+1;++i){
        narr[Pix(i,Y,re)]=(unsigned char)narr[Pix(i,Y,re)]-((unsigned char)narr[Pix(i,Y,re)]-r)*t;
        narr[Pix(i,Y,re)+1]=(unsigned char)narr[Pix(i,Y,re)+1]-((unsigned char)narr[Pix(i,Y,re)+1]-g)*t;
        narr[Pix(i,Y,re)+2]=(unsigned char)narr[Pix(i,Y,re)+2]-((unsigned char)narr[Pix(i,Y,re)+2]-b)*t;

        for (int j = 1; j < thick; ++j) {
            narr[Pix(i,Y+j,re)]=(unsigned char)narr[Pix(i,Y+j,re)]-((unsigned char)narr[Pix(i,Y+j,re)]-r)*t;
            narr[Pix(i,Y+j,re)+1]=(unsigned char)narr[Pix(i,Y+j,re)+1]-((unsigned char)narr[Pix(i,Y+j,re)+1]-g)*t;
            narr[Pix(i,Y+j,re)+2]=(unsigned char)narr[Pix(i,Y+j,re)+2]-((unsigned char)narr[Pix(i,Y+j,re)+2]-b)*t;

            narr[Pix(i,Y-j,re)]=(unsigned char)narr[Pix(i,Y-j,re)]-((unsigned char)narr[Pix(i,Y-j,re)]-r)*t;
            narr[Pix(i,Y-j,re)+1]=(unsigned char)narr[Pix(i,Y-j,re)+1]-((unsigned char)narr[Pix(i,Y-j,re)+1]-g)*t;
            narr[Pix(i,Y-j,re)+2]=(unsigned char)narr[Pix(i,Y-j,re)+2]-((unsigned char)narr[Pix(i,Y-j,re)+2]-b)*t;
        }

        if (smoothing){
            k=1-(Y-(int)Y);
            narr[Pix(i,Y-thick,re)]=((unsigned char)narr[Pix(i,Y-thick,re)]-((unsigned char)narr[Pix(i,Y-thick,re)]-r)*t*(k+c));
            narr[Pix(i,Y-thick,re)+1]=((unsigned char)narr[Pix(i,Y-thick,re)+1]-((unsigned char)narr[Pix(i,Y-thick,re)+1]-g)*t*(k+c));
            narr[Pix(i,Y-thick,re)+2]=((unsigned char)narr[Pix(i,Y-thick,re)+2]-((unsigned char)narr[Pix(i,Y-thick,re)+2]-b)*t*(k+c));

            k=(Y-(int)Y);
            narr[Pix(i,Y+thick,re)]=((unsigned char)narr[Pix(i,Y+thick,re)]-((unsigned char)narr[Pix(i,Y+thick,re)]-r)*t*(k+c));
            narr[Pix(i,Y+thick,re)+1]=((unsigned char)narr[Pix(i,Y+thick,re)+1]-((unsigned char)narr[Pix(i,Y+thick,re)+1]-g)*t*(k+c));
            narr[Pix(i,Y+thick,re)+2]=((unsigned char)narr[Pix(i,Y+thick,re)+2]-((unsigned char)narr[Pix(i,Y+thick,re)+2]-b)*t*(k+c));

        }
        Y+=grad;
    }
    return narr;
}

QPixmap MainWindow::CorrectGam(QByteArray arr, bool isConvert)
{
    /*double d;
    qDebug()<<gamma;
    if (gamma!=0){
        for (int i = firstPixByte; i < arr.size(); ++i) {
            d=pow((unsigned char)arr[i],gamma);
            if (d>255) d=255;
            arr[i]=d;
        }
    }else{

    }

    if (isConvert) {
        RGBblock = arr;
        block = ConvertFromRGB(arr);
    }
    return ConvertBytToPix(arr,firstPixByte);*/
    //if (gamma==0) return picture;
    QByteArray narr = arr;
    for(int i=firstPixByte;i<arr.size();i+=3){
        std::tuple<int,int,int> tup = ColC.RGBinYCoCg((unsigned char)arr[i],(unsigned char)arr[i+1],(unsigned char)arr[i+2]);
        narr[i]=std::get<0>(tup);
        narr[i+1]=std::get<1>(tup);
        narr[i+2]=std::get<2>(tup);
    }
    double g = gamma;
    /*if (gamma>0){
        g=gamma/100.0*2+1;
    }else{
        g=(100-(gamma*-1))/100.0;
    }
    //g+=1.2;*/
    //if (isConvert) g = 1/g;
    //qDebug()<<g;
    double temp;
    for(int i=firstPixByte;i<narr.size();i+=3){
        if (g!=0){
            temp=pow(((unsigned char)narr[i]/255.0),g);
        }else{
            g=1/2.4;
            temp=1.055*pow(((unsigned char)narr[i]/255.0),g)-0.055;
        }
        if (temp>1) temp=1;
        //qDebug()<<narr[i]<<" "<<temp*255;
        narr[i]=temp*255;
    }

    for(int i=firstPixByte;i<arr.size();i+=3){
        std::tuple<int,int,int> tup = ColC.YCoCginRGB((unsigned char)narr[i],(unsigned char)narr[i+1],(unsigned char)narr[i+2]);
        narr[i]=std::get<0>(tup);
        narr[i+1]=std::get<1>(tup);
        narr[i+2]=std::get<2>(tup);
    }
    if (isConvert) {
        RGBblock = narr;
        block = ConvertFromRGB(narr);
    }
    if (isConvert){
        if (gamma!=0){
            gamma=1/gamma;
        }else{
            gamma=2.4;
        }
    }
    return ConvertBytToPix(narr,firstPixByte);
}

int MainWindow::Pix(int x, int y, bool re)
{
    int g=3;
    if (isGrey) g=1;
    if (re) return firstPixByte+x*g*w+g*y;
    return firstPixByte+y*g*w+g*x;
}

void MainWindow::on_openFile_triggered()
{
    QString str = QFileDialog::getOpenFileName();
    ui->statusbar->showMessage(str);
    QFile file(str);
    colorType = ui->colorChose->currentItem()->text();
    if (file.open(QIODevice::ReadOnly))
    {
        h=0;
        w=0;
        block = file.readAll();
        file.close();
        if (block[0]=='P'){
            format = "pnm";
        }else if (block[1]=='P'&&block[2]=='N'&&block[3]=='G'){
            format = "png";
        }else if ((unsigned char)block[0] == 255 && (unsigned char)block[2] == 255){
            format = "jpg";
        }else{
            ui->statusbar->showMessage("данный формат не поддерживается");
            return;
        }
        qDebug()<<format;
        for (int i = 0; i < 20; ++i) {
            if ((int)block[i]>33&&(int)block[i]<126){
                //qDebug()<<block[i];
            }else{
                //qDebug()<<(int)block[i];
            }
        }
        if (format == "pnm"){
            if (block[1]=='5'){
                isGrey = true;
            }else{
                isGrey=false;
            }
            int i=3;
            while (block[i]-48>=0){
                w=10*w+block[i]-48;
                ++i;
            }
            ++i;
            while (block[i]-48>=0){
                h=10*h+block[i]-48;
                ++i;
            }
            ++i;
            while (block[i]-48>=0){
                ++i;
            }
            firstPixByte = i+1;

            if (colorType!="RGB"){
                RGBblock = ConvertToRGB(block);
            }else{
                RGBblock=block;
            }
        }else if (format == "png"){
            qDebug()<<ConvertToPNG(block);
        }else if (format == "jpg"){
            qDebug()<<"RETURN"<<ConvertToJPG(block);
        }
    }
}

void MainWindow::on_saveFile_triggered()
{
    QString strFilter=tr("Images (*.png *.pnm *.jpg)");
    QString str = QFileDialog::getSaveFileName(0,
                                    "Сохранить изображение",
                                    "C:\\",
                                    tr("Images (*.png *.pnm *.jpg)"),
                                    &strFilter
                                    );
    if (!str.isEmpty())
    {
          //qDebug()<<strFilter;
          QFile fileOut(str);
             if(fileOut.open(QIODevice::WriteOnly))
             {
                 if (str[str.size()-1]=='m'){
                     if ((ui->firstCh->isChecked() ^ ui->secondCh->isChecked() ^ ui->thirdCh->isChecked())&&
                             (!(ui->firstCh->isChecked() && ui->secondCh->isChecked() && ui->thirdCh->isChecked()))){
                         QByteArray tempBlock;
                         tempBlock.resize(firstPixByte+w*h);
                         for (int i = 0; i < firstPixByte; ++i) {
                             tempBlock[i]=block[i];
                         }
                         tempBlock[1]='5';
                         int e=0;
                         if (ui->secondCh->isChecked()){
                             e=1;
                         }
                         if (ui->thirdCh->isChecked()){
                             e=2;
                         }
                         for (int i = 0; i < h; ++i) {
                             for (int j = 0; j < w; ++j) {
                                 tempBlock[firstPixByte+i*w+j]=block[Pix(j,i)+e];
                             }
                         }
                         fileOut.write(tempBlock);
                     }else{
                        if (firstPixByte < 15){
                            QByteArray temp;
                            temp.push_back('P');
                            if (isGrey){
                                temp.push_back('5');
                            }else{
                                temp.push_back('6');
                            }
                            temp.push_back((unsigned char)10);
                            QVector<int> wh;
                            int tempoW=w;
                            while (tempoW>0) {
                                wh.push_back(tempoW%10);
                                tempoW/=10;
                            }
                            for (int i = wh.size()-1; i >= 0; --i) {
                                temp.push_back((unsigned char)(wh[i]+(int)'0'));
                            }

                            temp.push_back((unsigned char)32);

                            wh.clear();
                            wh.resize(0);
                            tempoW=h;
                            while (tempoW>0) {
                                wh.push_back(tempoW%10);
                                tempoW/=10;
                            }
                            for (int i = wh.size()-1; i >= 0; --i) {
                                temp.push_back((unsigned char)(wh[i]+(int)'0'));
                            }

                            temp.push_back((unsigned char)10);
                            temp.push_back('2');
                            temp.push_back('5');
                            temp.push_back('5');
                            temp.push_back((unsigned char)10);

                            fileOut.write(temp);
                        }
                        fileOut.write(block);
                     }
                 }else if (str[str.size()-3]=='p'){
                     //qDebug()<<"BLOCK_SIZE"<<block.size();
                     fileOut.write(ConvertFromPNG(block));
                 }else{

                 }
                 fileOut.close();
             }
    }
}

void MainWindow::on_gradGen_clicked()
{
    w=255;
    h=255;
    isGrey=false;
    firstPixByte=15;
    QByteArray arr;
    arr.resize(255*255+15);
    arr[0]='P';
    arr[1]='5';
    arr[2]='\n';
    arr[3]='2';
    arr[4]='5';
    arr[5]='5';
    arr[6]=' ';
    arr[7]='2';
    arr[8]='5';
    arr[9]='5';
    arr[10]='\n';
    arr[11]='2';
    arr[12]='5';
    arr[13]='5';
    arr[14]='\n';
    int rgb[3];
    double rh,t[3];
    for (int e = 0; e < 360; ++e) {
        //qDebug()<<rgb[0]<<" "<<rgb[1]<<" "<<rgb[2];
        for (int j = 0; j < 360; ++j) {
            rh=e;
            t[0]=(rh/360.0)+(1.0/3);
            t[1]=(rh/360.0);
            t[2]=(rh/360.0)-(1.0/3);

            for (int i=0;i<3;++i){
                if (t[i]<0) t[i]+=1;
                if (t[i]>1) t[i]-=1;

                if (t[i]<(1.0/6)){
                    rgb[i]=(6*t[i])*255;
                }else if (t[i]<(1.0/2)){
                    rgb[i]=255;
                }else if (t[i]<(2.0/3)){
                    rgb[i]=(6*((2.0/3)-t[i]))*255;
                }else{
                    rgb[i]=0;
                }
            }
//            int d = std::rand()%32-16;
//            for (int k = 0; k < 3; ++k) {
//                rgb[k]+=d;
//                if (rgb[k]>255) rgb[k]=255;
//                if (rgb[k]<0) rgb[k]=0;
//            }

            arr[Pix(e,j)]=rgb[0];
            arr[Pix(e,j)+1]=rgb[1];
            arr[Pix(e,j)+2]=rgb[2];

            arr[Pix(e,j)]=((unsigned char)arr[Pix(e,j)]);
            arr[Pix(e,j)+1]=((unsigned char)arr[Pix(e,j)+1]);
            arr[Pix(e,j)+2]=((unsigned char)arr[Pix(e,j)+2]);
            if (j==0){
                qDebug()<<(unsigned char)arr[Pix(e,j)]<<" "<<(unsigned char)arr[Pix(e,j)+1]<<" "<<(unsigned char)arr[Pix(e,j)+2];
            }
        }
    }
    int drgb[3],i1,j1;
    double map[2][2] ={{-0.25,0.25},
                       {0.5,0.}};
    for (int i = 0; i < 360; ++i) {
        for (int j = 0; j < 360; ++j) {
            /*for (int e = 0; e < 3; ++e) {
                drgb[e]=(unsigned char)arr[Pix(i,j)+e]/32*32-(unsigned char)arr[Pix(i,j)+e];
                i1=(unsigned char)arr[Pix(i+1,j)+e]+drgb[e];
                j1=(unsigned char)arr[Pix(i,j+1)+e]+drgb[e];
                if (i1<0) i1=0;
                if (i1>255) i1=255;
                if (j1<0) j1=0;
                if (j1>255) j1=255;
                arr[Pix(i+1,j)+e]=i1;
                arr[Pix(i,j+1)+e]=j1;
            }*/

            arr[Pix(i,j)]=(unsigned char)arr[Pix(i,j)];
            arr[Pix(i,j)+1]=(unsigned char)arr[Pix(i,j)+1];
            arr[Pix(i,j)+2]=(unsigned char)arr[Pix(i,j)+2];

//            int d = std::rand()%32-16;
//            arr[Pix(i,j)]=(unsigned char)arr[Pix(i,j)]+d;
//            arr[Pix(i,j)+1]=(unsigned char)arr[Pix(i,j)+1]+d;
//            arr[Pix(i,j)+2]=(unsigned char)arr[Pix(i,j)+2]+d;
            //arr[Pix(i,j)]=(unsigned char)arr[Pix(i,j)]+map[i%2][j%2]*255/3.0;
            //arr[Pix(i,j)+1]=(unsigned char)arr[Pix(i,j)+1]+map[i%2][j%2]*255/3.0;
            //arr[Pix(i,j)+2]=(unsigned char)arr[Pix(i,j)+2]+map[i%2][j%2]*255/3.0;
            //if ((unsigned char)arr[Pix(i,j)]>255)
        }
    }
    showImg->show();
    showImg->ShowI(ConvertBytToPix(arr,firstPixByte));
    RGBblock=arr;
    block=arr;

    //QByteArray ar = QByteArrayLiteral("\x49\x48\x44\x52\x00\x00\x00\x20\x00\x00\x00\x20\x08\x02\x00\x00\x00");
    //qDebug()<<(uint32_t)CRC32(ar);
}

void MainWindow::on_dizerButton_triggered()
{
    dizering = new Dizering(ConvertToRGB(block),w,h,firstPixByte,isGrey);
    connect(dizering, &Dizering::showDizer, this, &MainWindow::showDizer);
    dizering->show();
}

void MainWindow::on_mashtab_triggered()
{
    mashtab = new Mashtab(ConvertToRGB(block),w,h,firstPixByte,isGrey);
    connect(mashtab, &Mashtab::showDizer, this, &MainWindow::showZoom);
    mashtab->show();
}

int MainWindow::ConvertToPNG(QByteArray arr)
{
    int ret;
    unsigned have;

    std::map <QString, int> mapping;

    mapping["IHDR"]=1;
    mapping["PLTE"]=2;
    mapping["IDAT"]=3;
    mapping["IEND"]=4;
    mapping["gAMA"]=5;

    bool isPlt = false;
    int i=8,chankLen;
    int plt[256][3];
    QByteArray decomp,temp;
    QString chankName;
    chankName.resize(4);
    bool end = false;

    while (!end) {
        chankLen=pow(256,3)*(unsigned char)arr[i]+pow(256,2)*((unsigned char)arr[i+1])+256*((unsigned char)arr[i+2])+((unsigned char)arr[i+3]);
        i+=4;
        for (int j = 0; j < 4; ++j) {
            chankName[j]=arr[i+j];
        }
        i+=4;
        qDebug()<<chankName;
        switch (mapping[chankName]) {
            case 1:
                w=pow(256,3)*(unsigned char)arr[i]+pow(256,2)*((unsigned char)arr[i+1])+256*((unsigned char)arr[i+2])+((unsigned char)arr[i+3]);
                i+=4;
                h=pow(256,3)*(unsigned char)arr[i]+pow(256,2)*((unsigned char)arr[i+1])+256*((unsigned char)arr[i+2])+((unsigned char)arr[i+3]);
                i+=4;
                if ((unsigned char)arr[i]!=8){
                    ui->statusbar->showMessage("ошибка при чтении файла");
                    return -11;
                }
                i++;
                switch ((unsigned char)arr[i]) {
                    case 0:
                        isGrey = true;
                        break;

                    case 2:
                        isGrey = false;
                        break;

                    case 3:
                        isGrey = false;
                        isPlt = true;
                        break;

                    default:
                    qDebug()<<(unsigned char)arr[i];
                        ui->statusbar->showMessage("ошибка при чтении файла");
                        return -12;
                        break;
                }
                i++;
                if ((unsigned char)arr[i]!=0){
                    ui->statusbar->showMessage("ошибка при чтении файла");
                    return -13;
                }
                i++;
                if ((unsigned char)arr[i]!=0){
                    ui->statusbar->showMessage("ошибка при чтении файла");
                    return -14;
                }
                i++;
                if ((unsigned char)arr[i]!=0){
                    ui->statusbar->showMessage("ошибка при чтении файла");
                    return -15;
                }
                i+=5;
                break;

            case 2:
                for (int j = 0; j < chankLen; j+=3) {
                    plt[j/3][0]=arr[i+j];
                    plt[j/3][1]=arr[i+j+1];
                    plt[j/3][2]=arr[i+j+2];
                }
                i+=chankLen+4;
                break;

            case 3:
                qDebug()<<"is Palitra ="<<isPlt;

                decomp.append(arr.mid(i,chankLen));

    /*
                // decompress until deflate stream ends or end of file
                do {
                    strm.avail_in = fread(in, 1, chunk, source);
                    if (ferror(source)) {
                        (void)inflateEnd(&strm);
                        return Z_ERRNO;
                    }
                    qDebug()<<'0';
                    if (strm.avail_in == 0)
                        break;
                    strm.next_in = in;
                    // run inflate() on input until output buffer not full
                    do {
                        qDebug()<<'1';
                        strm.avail_out = chunk;
                        strm.next_out = out;
                        ret = inflate(&strm, Z_NO_FLUSH);
                        assert(ret != Z_STREAM_ERROR);  // state not clobbered
                        qDebug()<<'2';
                        switch (ret) {
                            case Z_NEED_DICT:
                                ret = Z_DATA_ERROR;     // and fall through
                            case Z_DATA_ERROR:
                            case Z_MEM_ERROR:
                                (void)inflateEnd(&strm);
                                input.close();
                                output.close();
                                return ret;
                        }
                        qDebug()<<'3';
                        have = chunk - strm.avail_out;
                        qDebug()<<in[0]<<out[0];
                        if (fwrite(out, 1, have, dest) != have || ferror(dest)) {
                            (void)inflateEnd(&strm);
                            return Z_ERRNO;
                        }
                        qDebug()<<'5';
                    } while (strm.avail_out == 0);
                    // done when inflate() says it's done
                } while (ret != Z_STREAM_END);
                // clean up and return
                (void)inflateEnd(&strm);
                return ret == Z_STREAM_END ? Z_OK : Z_DATA_ERROR;
                input.close();
                output.close();
    */
                i+=chankLen+4;
                break;

            case 4:
                i+=chankLen+4;
                end=true;
                break;

            case 5:
                int g;
                g=pow(256,3)*(unsigned char)arr[i]+pow(256,2)*((unsigned char)arr[i+1])+256*((unsigned char)arr[i+2])+((unsigned char)arr[i+3]);
                gamma=g/100000.0*2.2;
                i+=chankLen+4;
                break;

            default:
                if (chankName[0]<=90){
                    ui->statusbar->showMessage("ошибка при чтении файла");
                    return -1;
                }
                qDebug()<<"NOT_CLASSIC"<<chankName;
                i+=chankLen+4;
                break;
        }
    }

    temp=Inflate(decomp);
    decomp.resize(w*h*3);
    firstPixByte=0;
    ret=0;
    have=0;

    qDebug()<<"H and W"<<h<<w<<temp.size();

    for (int x = 0; x < h; ++x) {
        if (!isGrey && !isPlt){
            //qDebug()<<x<<":temp:"<<(unsigned char)temp[ret];
            ret++;
        }else{
            //qDebug()<<x<<":temp:"<<(unsigned char)temp[have];
            have++;
        }
        for (int y = 0; y < w; ++y) {
            /*if(x<10&&y<10){
                qDebug()<<(unsigned char)temp[have];
            }*/
            if (!isGrey){
                for (int e = 0; e < 3; ++e) {
                    if (isPlt){
                        //if(y==0) qDebug()<<(unsigned char)plt[(unsigned char)temp[have]][e];
                        decomp[Pix(y,x)+e]=(unsigned char)plt[(unsigned char)temp[have]][e];
                    }else{
                        decomp[Pix(y,x)+e]=(unsigned char)temp[ret+e];
                    }
                }
            }else {
                decomp[Pix(y,x)]=(unsigned char)temp[have];
            }
            have++;
            ret+=3;
            //if(ret>100000) ret--;
        }
    }
    //qDebug()<<isGrey;
    /*showImg->show();
    picture = CorrectGam(decomp);
    showImg->ShowI(picture);*/

    for (int j = 0; j < 8; ++j) {
        //qDebug()<<plt[j][0]<<plt[j][1]<<plt[j][2];
    }
    firstPixByte=0;
    RGBblock=decomp;
    block=decomp;
    qDebug()<<decomp.size()<<block.size()<<RGBblock.size();
    return 0;
}

int MainWindow::ConvertToJPG(QByteArray arr)
{
//    QVector<int> v(16);
//    v.insert(3,228);
//    qDebug()<<v;
    unsigned char indef=0;
    int i=3,len,ins,byt;
    QVector<QVector<int>> chanels(3);
    QVector<QVector<int>> chanelsHaf(3);
    QVector<QVector<QVector<int>>> dqt(16);
    QVector<QVector<QVector<int>>> trees(6);
    //QVector<QVector<QVector<int>>> matrix(6);
    QVector<bool> data;
    bool partData[8];
    while (indef!=217){
        indef=(unsigned char)arr[i];
        qDebug()<<(uint8_t)indef;
        ++i;
        switch (indef) {
            case 192:
                len = (unsigned char)arr[i]*256+(unsigned char)arr[i+1];
                if ((int)arr[i+2]!=8) return -2;
                h=(unsigned char)arr[i+3]*256+(unsigned char)arr[i+4];
                w=(unsigned char)arr[i+5]*256+(unsigned char)arr[i+6];
                if ((int)arr[i+7]==1){
                    isGrey = true;
                }else if ((int)arr[i+7]==3){
                    isGrey = false;
                }else{
                    return -3;
                }
                for (int j = 0; j < (int)arr[i+7]; ++j) {
                    chanels[(unsigned char)arr[i+8+j*3]-1].push_back((unsigned char)arr[i+9+j*3]/16);
                    chanels[(unsigned char)arr[i+8+j*3]-1].push_back((unsigned char)arr[i+9+j*3]%16);
                    chanels[(unsigned char)arr[i+8+j*3]-1].push_back((unsigned char)arr[i+10+j*3]);
                }
                i+=len;
                break;

            case 196:
                len = (unsigned char)arr[i]*256+(unsigned char)arr[i+1];
                len-=3;
                i+=3;
                trees[(unsigned char)arr[i-1]/16*3+(unsigned char)arr[i-1]%16]=buildHafTree(arr.mid(i,len));
                qDebug()<<"TREE:"<<(unsigned char)arr[i-1]/16*3+(unsigned char)arr[i-1]%16<<buildHafTree(arr.mid(i,len));
                i+=len;
                break;

            case 218:
                len = (unsigned char)arr[i]*256+(unsigned char)arr[i+1];
                for (int j = 0; j < (int)arr[i+2]; ++j) {
                    chanelsHaf[(unsigned char)arr[i+3+j*2]-1].push_back((unsigned char)arr[i+4+j*2]/16);
                    chanelsHaf[(unsigned char)arr[i+3+j*2]-1].push_back((unsigned char)arr[i+4+j*2]%16);
                    //chanelsHaf[(unsigned char)arr[i+3+j*2]-1].push_back((unsigned char)arr[i+5+j*2]);
                }
                i+=len;
                while (i<arr.size()){
                    if ((unsigned char)arr[i]==0 && (unsigned char)arr[i-1]==255){
                        ++i;
                    }
                    byt=(unsigned char)arr[i];
                    for (int j = 0; j < 8; ++j) {
                        partData[j]=byt%2;
                        byt/=2;
                    }
                    for (int j = 7; j >= 0; --j) {
                        data.push_back(partData[j]);
                    }

                    if ((unsigned char)arr[i]==255 && (unsigned char)arr[i+1]!=0){
                        for (int j = 0; j < 8; ++j) {
                            data.pop_back();
                        }
                        break;
                    }
                    ++i;
                }
                break;

            case 219:
                len = (unsigned char)arr[i]*256+(unsigned char)arr[i+1];
                i+=2;
                if ((unsigned char)arr[i]/16!=0){
                    return -1;
                }
                ins = (unsigned char)arr[i]%16;
                i++;
                len-=3;
                dqt[ins]=zigzagArr(arr.mid(i,len));
                i+=len;
                break;
            default:
                len = (unsigned char)arr[i]*256+(unsigned char)arr[i+1];
                i+=len;
                break;
        }
        if ((unsigned char)arr[i]!=255)
            return -100;
        ++i;
        indef=(unsigned char)arr[i];
    }

    i=0;
    bool isNeg;
    int matrNum=0,treeCur,DCcoef,e;
    QVector<int> matrLine;
    matrLine.resize(64);
    QVector<QVector<QVector<int>>> matrData;
    QVector<QVector<int> > *tree;
    qDebug()<<(uint8_t)indef;
    qDebug()<<w<<h<<isGrey;
    qDebug()<<data<<data.size();
    qDebug()<<"Начал расшифровывать данные";
    while (i<data.size()) {
        //qDebug()<<"I:"<<i;
        e=1;
        tree=&trees[0];
        if (!isGrey && matrNum%6>3){
            tree=&trees[chanelsHaf[matrNum%6-3][0]];
        }
        treeCur = 0;
//        for (int j = 0; j < tree->size(); ++j) {
//            qDebug()<<tree->value(j);
//        }
        while (tree->value(treeCur).value(0)!=-1){
            //qDebug()<<treeCur;
            treeCur=tree->value(treeCur).value(data[i]);
            ++i;
        }
        treeCur=tree->value(treeCur).value(1);
        DCcoef=0;
        isNeg = false;
        //qDebug()<<"DI"<<data[i];
        if (!data[i]) isNeg=true;
        for (int j = 0; j < treeCur; ++j) {
            //qDebug()<<data[i];
            DCcoef*=2;
            DCcoef+=(int)data[i];
            ++i;
        }
        if (isNeg){
            //qDebug()<<DCcoef<<treeCur;
            DCcoef-=pow(2,treeCur)-1;
        }
        //qDebug()<<"DCcoef"<<treeCur<<DCcoef;
        matrLine[0]=DCcoef;

        tree=&trees[3];
        if (!isGrey && matrNum%6>3){
            //qDebug()<<"HAF"<<chanelsHaf;
            tree=&trees[chanelsHaf[matrNum%6-3][1]+3];
        }
//        for (int j = 0; j < tree->size(); ++j) {
//            qDebug()<<tree->value(j);
//        }
        while (e<64){
            treeCur = 0;
            while (tree->value(treeCur).value(0)!=-1){
                treeCur=tree->value(treeCur).value(data[i]);
                ++i;
            }
            treeCur=tree->value(treeCur).value(1);
            //qDebug()<<treeCur;
            if (treeCur==0){
                while (e<64) {
                    matrLine[e]=0;
                    ++e;
                }
            }else{
                while (treeCur/16>0) {
                    matrLine[e]=0;
                    ++e;
                    treeCur-=16;
                }

                DCcoef=0;
                isNeg = false;
                //qDebug()<<"DI"<<data[i];
                if (!data[i]) isNeg=true;
                for (int j = 0; j < treeCur; ++j) {
                    DCcoef*=2;
                    DCcoef+=(int)data[i];
                    ++i;
                }
                if (isNeg){
                    //qDebug()<<DCcoef<<treeCur;
                    DCcoef-=pow(2,treeCur)-1;
                }
                matrLine[e]=DCcoef;
                ++e;
            }
        }
//        if (matrNum ==0){
//            qDebug()<<matrLine;
//        }
        matrData.push_back(zigzagArr(matrLine,false));
        ++matrNum;
        if (i-data.size()<8){
            bool flag=true;
            for (int j = i; j < data.size(); ++j) {
                flag*=data[j];
            }
            if (flag) i+=8;
        }
    }

    qDebug()<<"Начал исправлять DC коэфициенты";
    if (isGrey){
        for (int j = 1; j < matrNum; ++j) {
            matrData[j][0][0]+=matrData[j-1][0][0];
        }
    }else{
        for (int j = 1; j < matrNum; ++j) {
            if (j%6==4){
                if (j/6>0){
                   matrData[j][0][0]+=matrData[j-6][0][0];
                   matrData[j+1][0][0]+=matrData[j-5][0][0];
                }
                if (matrNum-j>6){
                    matrData[j+2][0][0]+=matrData[j-1][0][0];
                }
                j+=2;
            }else{
                matrData[j][0][0]+=matrData[j-1][0][0];
            }
        }
    }

    qDebug()<<"Начал домножение на DQT";
    QVector<QVector<int>> *rightMatr;
    for (int j = 0; j < matrNum; ++j) {
        rightMatr = &dqt[chanels[0][2]];
        if (j%6>3&&!isGrey){
            rightMatr = &dqt[chanels[j%6-3][2]];
        }
        for (int x = 0; x < 8; ++x) {
            for (int y = 0; y < 8; ++y) {
                matrData[j][x][y]*=rightMatr->value(x).value(y);
            }
        }
    }

    qDebug()<<"Начал преобразование фурье";
    double cu,cv,summa,pi=3.14159265358979323846;
    for (int j = 0; j < matrNum; ++j) {
        QVector<QVector<int>> ansMatr;
        ansMatr.resize(8);
        for (int x = 0; x < 8; ++x) {
            for (int y = 0; y < 8; ++y) {
                summa=0;
                for (int u = 0; u < 8; ++u) {
                    for (int v = 0; v < 8; ++v) {
                        cv=1;
                        cu=1;
                        if (u==0){
                            cu=1/std::sqrt(2);
                        }
                        if (v==0){
                            cv=1/std::sqrt(2);
                        }
                        summa+=cu*cv*matrData[j][v][u]*cos((2*x+1)*u*pi/16)*cos((2*y+1)*v*pi/16);
                    }
                }
                ansMatr[y].push_back(0.25*summa);
            }
        }
        for (int x = 0; x < 8; ++x) {
            for (int y = 0; y < 8; ++y) {
                ansMatr[x][y]+=128;
                if (ansMatr[x][y]<0){
                    ansMatr[x][y]=0;
                }
                if (ansMatr[x][y]>255){
                    ansMatr[x][y]=255;
                }
            }
        }
        matrData[j]=ansMatr;
    }

    qDebug()<<"Начал преобразование в картинку";
    firstPixByte =0;
    if(isGrey){
        block.resize(w*h);
        for (int x = 0; x < h; ++x) {
            for (int y = 0; y < w; ++y) {
                //qDebug()<<x/8*w/8+y/8;
                block[Pix(y,x)]=matrData[x/8*((w+7)/8)+y/8][x%8][y%8];
            }
        }
    }else{
        qDebug()<<chanels;
        QVector<QVector<QVector<int>>> Y,Cb,Cr;
        for (int i = 0; i < matrNum; ++i) {
            if (i%6<4){
                Y.push_back(matrData[i]);
            }else if (i%6==4){
                Cb.push_back(matrData[i]);
            }else{
                Cr.push_back(matrData[i]);
            }
        }
        QByteArray blockCb,blockCr;
        w/=2;
        h/=2;
        blockCr.resize(w*h);
        blockCb.resize(w*h);
        isGrey=true;
        for (int x = 0; x < h; ++x) {
            for (int y = 0; y < w; ++y) {
                //qDebug()<<x/8*(w+7)/8+y/8;
                blockCr[Pix(y,x)]=Cr[x/8*((w+7)/8)+y/8][x%8][y%8];
                blockCb[Pix(y,x)]=Cb[x/8*((w+7)/8)+y/8][x%8][y%8];
            }
        }
        mashtab = new Mashtab(blockCb,w,h,firstPixByte,true);
        blockCb = mashtab->changeZoomToJPEG(w*2,h*2);

        mashtab = new Mashtab(blockCr,w,h,firstPixByte,true);
        blockCr = mashtab->changeZoomToJPEG(w*2,h*2);

        qDebug()<<chanels;

        w*=2;
        h*=2;
        block.resize(w*h*3);
        isGrey=false;
        for (int x = 0; x < h; ++x) {
            for (int y = 0; y < w; ++y) {
                //qDebug()<<x/8*(w+7)/8<<"+"<<y/8<<"="<<x/8*(w+7)/8+y/8<<x<<y<<w<<h;
                block[Pix(y,x)]=Y[((x)/16*((w+15)/16)+(y)/16)*4+x%16/8*2+y%16/8][x%8][y%8];
                block[Pix(y,x)+1]=blockCb[firstPixByte+x*w+y];
                block[Pix(y,x)+2]=blockCr[firstPixByte+x*w+y];
            }
        }
    }
    if (!isGrey){
        colorType="YCbCr.601";
        RGBblock=ConvertToRGB(block);
    }else{
        RGBblock=block;
    }
    /*for (int j = 0; j < matrNum; ++j) {
        qDebug()<<"J:"<<j;
        if (j%6<6){
            for (int e = 0; e < 8; ++e) {
                qDebug()<<matrData[j][e];
            }
            qDebug()<<" ";
        }
    }*/

    qDebug()<<chanels;
    return 0;
}

QVector<QVector<int> > MainWindow::buildHafTree(QByteArray arr)
{
    int i=0;
    QVector<QVector<int>> v(1);
    v[0]=QVector<int>(3);
    QVector<int> count(16);
    for (int j = 0; j < 16; ++j) {
        count[j]=(unsigned char)arr[j];
    }
    i+=16;
    int cur=0,jcount=0,dep=0;
    for (int j = i; j < arr.size(); ++j) {
        while (count[jcount]==0) {
            jcount++;
        }
        while(dep!=jcount){
            dep++;
            Diper(v,cur);
        }
        Diper(v,cur);
        v[cur][0]=-1;
        v[cur][1]=(unsigned char)arr[j];
        cur=v[cur][2];
        count[jcount]--;
    }
//    qDebug()<<"!!!";
//    qDebug()<<v;
//    qDebug()<<"&&&";
    return v;
}

void MainWindow::Diper(QVector<QVector<int> > &tree, int &cur)
{
    //qDebug()<<tree<<cur;
    QVector<int> v(3);
    if (tree[cur][0]==0){
        tree[cur][0]=tree.size();
        v[2]=cur;
        tree.push_back(v);
        //qDebug()<<tree.size();
        cur=tree[cur][0];
    }else if (tree[cur][1]==0){
        tree[cur][1]=tree.size();
        v[2]=cur;
        tree.push_back(v);
        //qDebug()<<tree.size();
        cur=tree[cur][1];
    }else{
        cur=tree[cur][2];
        Diper(tree,cur);
        Diper(tree,cur);
    }
}

QVector<QVector<int> > MainWindow::zigzagArr(QByteArray arr, bool isUnsigned)
{
    int n=sqrt(arr.size());
    QVector<QVector<int>>dqt(n);
    for (int v = 0; v < n; ++v) {
        dqt[v].resize(n);
    }
    //qDebug()<<(unsigned char)arr[i]<<(unsigned char)arr[i+1]<<(unsigned char)arr[i+2];
    int next=0;
    for (int j = 0; j < 2*n-1; ++j) {
        int x=0,y=j,se=j,fe=j*n;
        if (j>=n){
            se+=(j-(n-1))*(n-1);
            fe-=(j-(n-1))*(n-1);
            x=j-(n-1);
            y=n-1;
        }
        //qDebug()<<n<<se<<fe<<x<<y;
        if (j%2==0){
            for (int e = fe; e > se-1; e-=(n-1)) {
                if (isUnsigned){
                    dqt[y][x] = (unsigned char)arr[next];
                }else{
                    dqt[y][x] = arr[next];
                }
                y--;
                x++;
                next++;
            }
        }else{
            for (int e = se; e < fe+1; e+=(n-1)) {
                if (isUnsigned){
                    dqt[x][y] = (unsigned char)arr[next];
                }else{
                    dqt[x][y] = arr[next];
                }
                y--;
                x++;
                next++;
            }
        }
    }
//    for (int x = 0; x < n; ++x) {
//        qDebug()<<dqt[x];
//    }
    return dqt;
}

QVector<QVector<int> > MainWindow::zigzagArr(QVector<int> arr, bool isUnsigned)
{
    int n=sqrt(arr.size());
    QVector<QVector<int>>dqt(n);
    for (int v = 0; v < n; ++v) {
        dqt[v].resize(n);
    }
    //qDebug()<<(unsigned char)arr[i]<<(unsigned char)arr[i+1]<<(unsigned char)arr[i+2];
    int next=0;
    for (int j = 0; j < 2*n-1; ++j) {
        int x=0,y=j,se=j,fe=j*n;
        if (j>=n){
            se+=(j-(n-1))*(n-1);
            fe-=(j-(n-1))*(n-1);
            x=j-(n-1);
            y=n-1;
        }
        //qDebug()<<n<<se<<fe<<x<<y;
        if (j%2==0){
            for (int e = fe; e > se-1; e-=(n-1)) {
                if (isUnsigned){
                    dqt[y][x] = (unsigned char)arr[next];
                }else{
                    dqt[y][x] = arr[next];
                }
                y--;
                x++;
                next++;
            }
        }else{
            for (int e = se; e < fe+1; e+=(n-1)) {
                if (isUnsigned){
                    dqt[x][y] = (unsigned char)arr[next];
                }else{
                    dqt[x][y] = arr[next];
                }
                y--;
                x++;
                next++;
            }
        }
    }
//    for (int x = 0; x < n; ++x) {
//        qDebug()<<dqt[x];
//    }
    return dqt;
}

uint32_t MainWindow::CRC32(QByteArray data)
{
    uint32_t crcTable[256] = {
                0x00000000u, 0x77073096u, 0xee0e612cu, 0x990951bau, 0x076dc419u,
                0x706af48fu, 0xe963a535u, 0x9e6495a3u, 0x0edb8832u, 0x79dcb8a4u,
                0xe0d5e91eu, 0x97d2d988u, 0x09b64c2bu, 0x7eb17cbdu, 0xe7b82d07u,
                0x90bf1d91u, 0x1db71064u, 0x6ab020f2u, 0xf3b97148u, 0x84be41deu,
                0x1adad47du, 0x6ddde4ebu, 0xf4d4b551u, 0x83d385c7u, 0x136c9856u,
                0x646ba8c0u, 0xfd62f97au, 0x8a65c9ecu, 0x14015c4fu, 0x63066cd9u,
                0xfa0f3d63u, 0x8d080df5u, 0x3b6e20c8u, 0x4c69105eu, 0xd56041e4u,
                0xa2677172u, 0x3c03e4d1u, 0x4b04d447u, 0xd20d85fdu, 0xa50ab56bu,
                0x35b5a8fau, 0x42b2986cu, 0xdbbbc9d6u, 0xacbcf940u, 0x32d86ce3u,
                0x45df5c75u, 0xdcd60dcfu, 0xabd13d59u, 0x26d930acu, 0x51de003au,
                0xc8d75180u, 0xbfd06116u, 0x21b4f4b5u, 0x56b3c423u, 0xcfba9599u,
                0xb8bda50fu, 0x2802b89eu, 0x5f058808u, 0xc60cd9b2u, 0xb10be924u,
                0x2f6f7c87u, 0x58684c11u, 0xc1611dabu, 0xb6662d3du, 0x76dc4190u,
                0x01db7106u, 0x98d220bcu, 0xefd5102au, 0x71b18589u, 0x06b6b51fu,
                0x9fbfe4a5u, 0xe8b8d433u, 0x7807c9a2u, 0x0f00f934u, 0x9609a88eu,
                0xe10e9818u, 0x7f6a0dbbu, 0x086d3d2du, 0x91646c97u, 0xe6635c01u,
                0x6b6b51f4u, 0x1c6c6162u, 0x856530d8u, 0xf262004eu, 0x6c0695edu,
                0x1b01a57bu, 0x8208f4c1u, 0xf50fc457u, 0x65b0d9c6u, 0x12b7e950u,
                0x8bbeb8eau, 0xfcb9887cu, 0x62dd1ddfu, 0x15da2d49u, 0x8cd37cf3u,
                0xfbd44c65u, 0x4db26158u, 0x3ab551ceu, 0xa3bc0074u, 0xd4bb30e2u,
                0x4adfa541u, 0x3dd895d7u, 0xa4d1c46du, 0xd3d6f4fbu, 0x4369e96au,
                0x346ed9fcu, 0xad678846u, 0xda60b8d0u, 0x44042d73u, 0x33031de5u,
                0xaa0a4c5fu, 0xdd0d7cc9u, 0x5005713cu, 0x270241aau, 0xbe0b1010u,
                0xc90c2086u, 0x5768b525u, 0x206f85b3u, 0xb966d409u, 0xce61e49fu,
                0x5edef90eu, 0x29d9c998u, 0xb0d09822u, 0xc7d7a8b4u, 0x59b33d17u,
                0x2eb40d81u, 0xb7bd5c3bu, 0xc0ba6cadu, 0xedb88320u, 0x9abfb3b6u,
                0x03b6e20cu, 0x74b1d29au, 0xead54739u, 0x9dd277afu, 0x04db2615u,
                0x73dc1683u, 0xe3630b12u, 0x94643b84u, 0x0d6d6a3eu, 0x7a6a5aa8u,
                0xe40ecf0bu, 0x9309ff9du, 0x0a00ae27u, 0x7d079eb1u, 0xf00f9344u,
                0x8708a3d2u, 0x1e01f268u, 0x6906c2feu, 0xf762575du, 0x806567cbu,
                0x196c3671u, 0x6e6b06e7u, 0xfed41b76u, 0x89d32be0u, 0x10da7a5au,
                0x67dd4accu, 0xf9b9df6fu, 0x8ebeeff9u, 0x17b7be43u, 0x60b08ed5u,
                0xd6d6a3e8u, 0xa1d1937eu, 0x38d8c2c4u, 0x4fdff252u, 0xd1bb67f1u,
                0xa6bc5767u, 0x3fb506ddu, 0x48b2364bu, 0xd80d2bdau, 0xaf0a1b4cu,
                0x36034af6u, 0x41047a60u, 0xdf60efc3u, 0xa867df55u, 0x316e8eefu,
                0x4669be79u, 0xcb61b38cu, 0xbc66831au, 0x256fd2a0u, 0x5268e236u,
                0xcc0c7795u, 0xbb0b4703u, 0x220216b9u, 0x5505262fu, 0xc5ba3bbeu,
                0xb2bd0b28u, 0x2bb45a92u, 0x5cb36a04u, 0xc2d7ffa7u, 0xb5d0cf31u,
                0x2cd99e8bu, 0x5bdeae1du, 0x9b64c2b0u, 0xec63f226u, 0x756aa39cu,
                0x026d930au, 0x9c0906a9u, 0xeb0e363fu, 0x72076785u, 0x05005713u,
                0x95bf4a82u, 0xe2b87a14u, 0x7bb12baeu, 0x0cb61b38u, 0x92d28e9bu,
                0xe5d5be0du, 0x7cdcefb7u, 0x0bdbdf21u, 0x86d3d2d4u, 0xf1d4e242u,
                0x68ddb3f8u, 0x1fda836eu, 0x81be16cdu, 0xf6b9265bu, 0x6fb077e1u,
                0x18b74777u, 0x88085ae6u, 0xff0f6a70u, 0x66063bcau, 0x11010b5cu,
                0x8f659effu, 0xf862ae69u, 0x616bffd3u, 0x166ccf45u, 0xa00ae278u,
                0xd70dd2eeu, 0x4e048354u, 0x3903b3c2u, 0xa7672661u, 0xd06016f7u,
                0x4969474du, 0x3e6e77dbu, 0xaed16a4au, 0xd9d65adcu, 0x40df0b66u,
                0x37d83bf0u, 0xa9bcae53u, 0xdebb9ec5u, 0x47b2cf7fu, 0x30b5ffe9u,
                0xbdbdf21cu, 0xcabac28au, 0x53b39330u, 0x24b4a3a6u, 0xbad03605u,
                0xcdd70693u, 0x54de5729u, 0x23d967bfu, 0xb3667a2eu, 0xc4614ab8u,
                0x5d681b02u, 0x2a6f2b94u, 0xb40bbe37u, 0xc30c8ea1u, 0x5a05df1bu,
                0x2d02ef8du
            };
    uint32_t crc_32 = 0xffffffffu;

    for (int i = 0; i < data.size(); i++) {
        //const uint32_t lookupIndex = (crc_32 ^ (unsigned char)data[i]) & 0xff;
        crc_32 = (crc_32 >> 8) ^ crcTable[(crc_32 ^ (unsigned char)data[i]) & 0xff];  // CRCTable is an array of 256 32-bit constants
    }

    crc_32 ^= 0xFFFFFFFFu;
    return crc_32;
}

QByteArray MainWindow::Inflate(QByteArray arr)
{
    QByteArray temp;
    int ret;
    z_stream strm;
    unsigned char in[16384];
    unsigned char out[16384];

    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    strm.avail_in = 0;
    strm.next_in = Z_NULL;

    int chi=0;
    qDebug()<<"Check 1";

    ret = inflateInit(&strm);
    // decompress until deflate stream ends or end of file
    do {
        qDebug()<<"Check 2"<<chi<<arr.size()<<ret;

        strm.avail_in = std::min(16384,arr.size()-chi);
        for (int j = chi; j < chi+std::min(16384,arr.size()-chi); ++j) {
            in[j-chi]=(unsigned char)arr[j];
        }
        chi+=chunk;
        strm.next_in = in;

        //strm.avail_in = chankLen;
        //strm.next_in = in;
        // run inflate() on input until output buffer not full
        do {
            strm.avail_out = chunk;
            strm.next_out = out;
            ret = inflate(&strm, Z_NO_FLUSH);

            qDebug()<<"Check 3"<<ret<<strm.msg;

            for (int j = 0; j < chunk-strm.avail_out; ++j) {
                temp.append(out[j]);
            }
        } while (strm.avail_out == 0);
        // done when inflate() says it's done
    } while (chi<arr.size());
    // clean up and return
    (void)inflateEnd(&strm);

    return temp;
}

QByteArray MainWindow::Deflate(QByteArray arr)
{
    //qDebug()<<"BLOCK_SIZE0"<<arr.size();
    int ret, flush;
    z_stream strm;
    unsigned char in[16384];
    unsigned char out[16384];

    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    ret = deflateInit(&strm, Z_DEFAULT_COMPRESSION);

    QByteArray decomp;

    //qDebug()<<"BLOCK_SIZE1"<<arr.size()<<firstPixByte;
    int i = firstPixByte;

    qDebug()<<"fbp"<<firstPixByte<<std::min(16384,arr.size()-i)<<arr.size()<<i<<ret;
    // decompress until deflate stream ends or end of file

    //qDebug()<<"BLOCK_SIZE2"<<arr.size();

    do {
        flush = arr.size()-i<=chunk ? Z_FINISH : Z_NO_FLUSH;
        strm.avail_in = std::min(16384,arr.size()-i);
        for (int j = i; j < i+std::min(16384,arr.size()-i); ++j) {
            in[j-i]=(unsigned char)arr[j];
        }
        i+=chunk;
        strm.next_in = in;
        // run inflate() on input until output buffer not full
        do {
            strm.avail_out = chunk;
            strm.next_out = out;
            qDebug()<<ret<<strm.avail_in<<strm.avail_out;
            ret = deflate(&strm, flush);
            qDebug()<<ret<<strm.avail_in<<strm.avail_out;
            for (int j = 0; j < chunk-strm.avail_out; ++j) {
                decomp.append(out[j]);
            }
        } while (strm.avail_out == 0);
        // done when inflate() says it's done
    } while (flush != Z_FINISH);
    // clean up and return

    /*qDebug()<<decomp.size();

    for (int i = 0; i < 10; ++i) {
        qDebug()<<out[i];
    }*/
    return decomp;
}

QByteArray MainWindow::ConvertFromPNG(QByteArray arr)
{
    //arr=arr.right(arr.size()-firstPixByte);
    QByteArray decode;
    for (int i = 0; i < h; ++i) {
        //arr.insert(i*(w-1),(char)0);
    }
    for (int i = firstPixByte; i < arr.size(); ++i) {
        if ((i-firstPixByte-((i-firstPixByte)/(w*3)))%(w*3)==0){
            arr.insert(i,(char)0);
            i+=2;
        }
    }
    //arr.insert(0,(char)0);
    decode = Deflate(arr);

    arr.resize(8+25+16+decode.size()+12+12);

    arr[0]=0x89u;
    arr[1]=0x50u;
    arr[2]=0x4eu;
    arr[3]=0x47u;
    arr[4]=0x0du;
    arr[5]=0x0au;
    arr[6]=0x1au;
    arr[7]=0x0au;

    arr[8]=0x00u;
    arr[9]=0x00u;
    arr[10]=0x00u;
    arr[11]=0x0du;
    arr[12]=0x49u;
    arr[13]=0x48u;
    arr[14]=0x44u;
    arr[15]=0x52u;
    /*if (isGrey){
        w--;
    }*/
    arr[16]=(w)/256/256/256;
    arr[17]=(w)/256/256%256;
    arr[18]=(w)/256%256;
    arr[19]=(w)%256;
    arr[20]=(h)/256/256/256;
    arr[21]=(h)/256/256%256;
    arr[22]=(h)/256%256;
    arr[23]=(h)%256;
    arr[24]=8;
    if (isGrey){
        w++;
        arr[25]=0;
    }else{
        arr[25]=2;
    }
    arr[26]=0x00u;
    arr[27]=0x00u;
    arr[28]=0x00u;
    int crc_32 = CRC32(arr.mid(12,17));
    arr[29]=crc_32/256/256/256;
    arr[30]=crc_32/256/256%256;
    arr[31]=crc_32/256%256;
    arr[32]=crc_32%256;

    arr[33]=0x00u;
    arr[34]=0x00u;
    arr[35]=0x00u;
    arr[36]=0x04u;
    arr[37]=0x67u;
    arr[38]=0x41u;
    arr[39]=0x4du;
    arr[40]=0x41u;
    int g = gamma*100000/2.2;
    arr[41]=g/256/256/256;
    arr[42]=g/256/256%256;
    arr[43]=g/256%256;
    arr[44]=g%256;
    crc_32 = CRC32(arr.mid(37,8));
    arr[45]=crc_32/256/256/256;
    arr[46]=crc_32/256/256%256;
    arr[47]=crc_32/256%256;
    arr[48]=crc_32%256;

    g = decode.size();
    arr[49]=g/256/256/256;
    arr[50]=g/256/256%256;
    arr[51]=g/256%256;
    arr[52]=g%256;
    arr[53]=0x49u;
    arr[54]=0x44u;
    arr[55]=0x41u;
    arr[56]=0x54u;
    for (int i = 57; i < 57+g; ++i) {
        arr[i]=decode[i-57];
    }
    crc_32 = CRC32(arr.mid(53,4+g));
    arr[57+g]=crc_32/256/256/256;
    arr[58+g]=crc_32/256/256%256;
    arr[59+g]=crc_32/256%256;
    arr[60+g]=crc_32%256;

    arr[61+g]=0x00u;
    arr[62+g]=0x00u;
    arr[63+g]=0x00u;
    arr[64+g]=0x00u;

    arr[65+g]=0x49u;
    arr[66+g]=0x45u;
    arr[67+g]=0x4eu;
    arr[68+g]=0x44u;
    crc_32 = CRC32(arr.mid(65+g,4));
    arr[69+g]=crc_32/256/256/256;
    arr[70+g]=crc_32/256/256%256;
    arr[71+g]=crc_32/256%256;
    arr[72+g]=crc_32%256;
    return arr;
}

void MainWindow::on_filter_triggered()
{
    filter = new Filter(ConvertToRGB(block),w,h,firstPixByte,isGrey);
    connect(filter, &Filter::showDizer, this, &MainWindow::showDizer);
    filter->show();
}

void MainWindow::on_contrastCorection_triggered()
{
   contrast = new Contrast(ConvertToRGB(block),w,h,firstPixByte,isGrey);
   connect(contrast, &Contrast::showDizer, this, &MainWindow::showDizer);
   contrast->show();
}
