#include "dizering.h"
#include "ui_dizering.h"
#include <QDebug>

Dizering::Dizering(QByteArray arr, int w, int h,int firstBytePix, bool isGray, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dizering)
{
    if (isGray){
        gray=1;
    }
    this->w=w;
    this->h=h;
    this->firstBytePix=firstBytePix;
    ui->setupUi(this);
    block = arr;
    ui->noDizering->click();
}

Dizering::~Dizering()
{
    delete ui;
}

QByteArray Dizering::noDiz(QByteArray arr)
{
    int d;
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            for (int e = 0; e < gray; ++e) {
                if (nc==-1){
                    if ((unsigned char)arr[Pix(i,j)+e]>=128){
                        arr[Pix(i,j)+e]=(unsigned char)255;
                    }else{
                        arr[Pix(i,j)+e]=0;
                    }
                    //qDebug()<<(unsigned char)arr[Pix(i,j)+e];
                }else{
                    d=(unsigned char)arr[Pix(i,j)+e]/nc*(255/(ui->bitnost->value()));
                    if (d>255) d=255;
                    if (d<0) d=0;
                    arr[Pix(i,j)+e]=d;
                }
            }
            if (!((unsigned char)arr[Pix(i,j)]==(unsigned char)arr[Pix(i,j)+1]&&(unsigned char)arr[Pix(i,j)]==(unsigned char)arr[Pix(i,j)+2])){
                //qDebug()<<(unsigned char)arr[Pix(i,j)+0]<<" "<<(unsigned char)arr[Pix(i,j)+1]<<" "<<(unsigned char)arr[Pix(i,j)+2];
                //qDebug()<<(unsigned char)block[Pix(i,j)+0]<<" "<<(unsigned char)block[Pix(i,j)+1]<<" "<<(unsigned char)block[Pix(i,j)+2];
            }
        }
    }
    return arr;
}

QByteArray Dizering::ordDiz(QByteArray arr)
{
    int matr[8][8] = {{0,32,8,40,2,34,10,42},
                {48,16,56,24,50,18,58,26},
                {12,44,4,36,14,46,6,38},
                {60,28,52,20,62,30,54,22},
                {3,35,11,43,1,33,9,41},
                {51,19,59,27,49,17,57,25},
                {15,47,7,39,13,45,5,37},
                {63,31,55,23,61,29,53,21}};
    int d;
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            for (int e = 0; e < gray; ++e) {
                d=(unsigned char)arr[Pix(i,j)+e]+(1.0*matr[i%8][j%8]/64-0.5)*(nc/2);
                if (d>255) d=255;
                if (d<0) d=0;
                arr[Pix(i,j)+e]=d;
            }
        }
    }
    return arr;
}

QByteArray Dizering::randomDiz(QByteArray arr)
{
    int r,d;
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            r = std::rand()%nc-nc/2;
            for (int e = 0; e < gray; ++e) {
                d=(unsigned char)arr[Pix(i,j)+e]+r;
                if (d>255) d=255;
                if (d<0) d=0;
                arr[Pix(i,j)+e]=d;
            }
        }
    }
    return arr;
}

QByteArray Dizering::floydDiz(QByteArray arr)
{
    int d,r;
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            for (int e = 0; e < gray; ++e) {
                if (i+1<w){
                    if (nc==128){
                        if ((unsigned char)arr[Pix(i,j)+e]>=128){
                            r=(255-(unsigned char)arr[Pix(i,j)+e])*-1/16;
                        }else{
                            r=((unsigned char)arr[Pix(i,j)+e])/16;
                        }
                    }else{
                        r=(unsigned char)arr[Pix(i,j)+e]%nc/16;
                    }
                    d=(unsigned char)arr[Pix(i+1,j)+e]+r*7;
                    if (d>255) d=255;
                    if (d<0) d=0;
                    arr[Pix(i+1,j)+e]=d;
                    if (j>0){
                        d=(unsigned char)arr[Pix(i+1,j-1)+e]+r*3;
                        if (d>255) d=255;
                        if (d<0) d=0;
                        arr[Pix(i+1,j-1)+e]=d;
                    }
                    if (j+1<h){
                        d=(unsigned char)arr[Pix(i+1,j+1)+e]+r;
                        if (d>255) d=255;
                        if (d<0) d=0;
                        arr[Pix(i+1,j+1)+e]=d;
                    }
                }

                if (j+1<h){
                    d=(unsigned char)arr[Pix(i,j+1)+e]+r*5;
                    if (d>255) d=255;
                    if (d<0) d=0;
                    arr[Pix(i,j+1)+e]=d;
                }
            }
        }
    }
    return arr;
}

QByteArray Dizering::atkiDiz(QByteArray arr)
{
    double d,r;
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            for (int e = 0; e < gray; ++e) {
                if (i+1<w){
                    if (nc==128){
                        if ((unsigned char)arr[Pix(i,j)+e]>=128){
                            r=((unsigned char)255-arr[Pix(i,j)+e])*-1/8.0;
                        }else{
                            r=((unsigned char)arr[Pix(i,j)+e])/8.0;
                        }
                    }else{
                        r=(unsigned char)arr[Pix(i,j)+e]%nc/8.0;
                    }
                    d=(unsigned char)arr[Pix(i+1,j)+e]+r;
                    if (d>255) d=255;
                    if (d<0) d=0;
                    arr[Pix(i+1,j)+e]=d;
                    if (j>0){
                        d=(unsigned char)arr[Pix(i+1,j-1)+e]+r;
                        if (d>255) d=255;
                        if (d<0) d=0;
                        arr[Pix(i+1,j-1)+e]=d;
                    }
                    if (j+1<h){
                        d=(unsigned char)arr[Pix(i+1,j+1)+e]+r;
                        if (d>255) d=255;
                        if (d<0) d=0;
                        arr[Pix(i+1,j+1)+e]=d;
                    }
                }

                if (j+1<h){
                    d=(unsigned char)arr[Pix(i,j+1)+e]+r;
                    if (d>255) d=255;
                    if (d<0) d=0;
                    arr[Pix(i,j+1)+e]=d;
                }

                if (i+2<w){
                    d=(unsigned char)arr[Pix(i+2,j)+e]+r;
                    if (d>255) d=255;
                    if (d<0) d=0;
                    arr[Pix(i+2,j)+e]=d;
                }

                if (j+2<h){
                    d=(unsigned char)arr[Pix(i,j+2)+e]+r;
                    if (d>255) d=255;
                    if (d<0) d=0;
                    arr[Pix(i,j+2)+e]=d;
                }
            }
        }
    }
    return arr;
}

int Dizering::Pix(int x, int y, bool re)
{
    if (re) return firstBytePix+x*gray*w+gray*y;
    return firstBytePix+y*gray*w+gray*x;
}

void Dizering::on_showDiz_clicked()
{
    nc=256/(ui->bitnost->value()+1);
    QByteArray tempBlock;
    if (ui->noDizering->isChecked()){
        tempBlock = noDiz(block);
    }
    if (ui->randDizering->isChecked()){
        tempBlock=noDiz(randomDiz(block));
    }
    if (ui->atkiDizering->isChecked()){
        tempBlock=noDiz(atkiDiz(block));
    }
    if (ui->floydDizering->isChecked()){
        tempBlock=noDiz(floydDiz(block));
    }
    if (ui->ordDizering->isChecked()){
        tempBlock=noDiz(ordDiz(block));
    }
    emit showDizer(tempBlock,false);
}

void Dizering::on_saveDiz_clicked()
{
    nc=256/(ui->bitnost->value()+1);
    QByteArray tempBlock;
    if (ui->noDizering->isChecked()){
        tempBlock = noDiz(block);
    }
    if (ui->randDizering->isChecked()){
        tempBlock=noDiz(randomDiz(block));
    }
    if (ui->atkiDizering->isChecked()){
        tempBlock=noDiz(atkiDiz(block));
    }
    if (ui->floydDizering->isChecked()){
        tempBlock=noDiz(floydDiz(block));
    }
    if (ui->ordDizering->isChecked()){
        tempBlock=noDiz(ordDiz(block));
    }
    emit showDizer(tempBlock,true);
}
