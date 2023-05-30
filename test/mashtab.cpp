#include "mashtab.h"
#include "ui_mashtab.h"
#include <QDebug>

Mashtab::Mashtab(QByteArray arr, int w, int h,int firstBytePix, bool isGray, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mashtab)
{
    if (isGray){
        gray=1;
    }
    this->w=w;
    this->h=h;
    this->firstBytePix=firstBytePix;
    ui->setupUi(this);
    block = arr;
    ui->Bilineral->click();
    ui->newH->setValue(h);
    ui->newW->setValue(w);
    ui->Bcoef->setValue(0);
    ui->Ccoef->setValue(0.5);
}

Mashtab::~Mashtab()
{
    delete ui;
}

QByteArray Mashtab::changeZoomToJPEG(int W, int H)
{
    QByteArray tempBlock;
    newH=H;
    newW=w;
    tempBlock=changeZoom(block,true, newH);
    newW=W;
    tempBlock=changeZoom(tempBlock,false,newW);
    return tempBlock;
}

QByteArray Mashtab::changeZoom(QByteArray arr, bool incH, int inc)
{
    double xs=ui->Xshift->value(),ys=ui->Yshift->value();
    QByteArray ret;
    int lastDem,newDem;
    double coef,numberBytesToCons=0.5;
    bool is4pix=false;
    if (ui->Lanckhoz3->isChecked() || ui->BCsplain->isChecked()){
        numberBytesToCons=1.5;
        is4pix = true;
    }
    if (incH){
        lastDem=h;
    }else{
        lastDem=w;
    }
    newDem=inc;
    coef = 1.0*newDem/lastDem;
    if (incH){
        ret.resize(inc*w*gray+firstBytePix);
        for (int cons = 0; cons < w; ++cons) {
            for (int i = 0; i < inc; ++i) {
                QVector<double> poz;
                if (inc>=h){
                    if (is4pix){
                       poz.push_back((int)(i/coef-1+xs));
                    }
                    poz.push_back((int)(i/coef+xs));
                    poz.push_back((int)(i/coef+1+xs));
                    if (is4pix){
                       poz.push_back((int)(i/coef+2+xs));
                    }
                    for (int j = 0; j < poz.size(); ++j) {
                        if (poz[j]<0){
                            poz[j]=0;
                        }
                        if (poz[j]>h-1){
                            poz[j]=h-1;
                        }
                    }
                }else{
                    for (int p = ((i-numberBytesToCons)/coef)+1+xs; p<((i+numberBytesToCons)/coef)+1+xs; ++p){
                        poz.push_back(p);
                    }
                    for (int j = 0; j < poz.size(); ++j) {
                        if (poz[j]<0){
                            poz[j]=0;
                        }
                        if (poz[j]>h-1){
                            poz[j]=h-1;
                        }
                    }
                }
                for (int e = 0; e < gray; ++e) {
                    QVector<int> val;
                    for (int j = 0; j < poz.size(); ++j) {
                        val.push_back((unsigned char)arr[Pix(cons, poz[j])+e]);
                    }
                    if (ui->Neighbor->isChecked()){
                        ret[Pix(cons, i)+e]=Neigbor(poz,val,i/coef+xs);
                    }
                    if (ui->Bilineral->isChecked()){
                        ret[Pix(cons, i)+e]=Bilineral(poz,val,i/coef+xs);
                    }
                    if (ui->Lanckhoz3->isChecked()){
                        ret[Pix(cons, i)+e]=Lanchoz(poz,val,i/coef+xs);
                    }
                    if (ui->BCsplain->isChecked()){
                        ret[Pix(cons, i)+e]=BCsplain(poz,val,i/coef+xs);
                    }
                }
            }
        }
    }else{
        ret.resize(inc*newH*gray+firstBytePix);
        //qDebug()<<"SIZE:"<<ret.size()<<inc<<newH;
        for (int cons = 0; cons < newH; ++cons) {
            for (int i = 0; i < inc; ++i) {
                QVector<double> poz;
                if (inc>=w){
                    if (is4pix){
                       poz.push_back((int)(i/coef-1+ys));
                    }
                    poz.push_back((int)(i/coef+ys));
                    poz.push_back((int)(i/coef+1+ys));
                    if (is4pix){
                       poz.push_back((int)(i/coef+2+ys));
                    }
                    for (int j = 0; j < poz.size(); ++j) {
                        if (poz[j]<0){
                            poz[j]=0;
                        }
                        if (poz[j]>w-1){
                            poz[j]=w-1;
                        }
                    }
                }else{
                    for (int p = ((i-numberBytesToCons)/coef)+1+ys; p<((i+numberBytesToCons)/coef)+1+ys; ++p){
                        poz.push_back(p);
                    }
                    for (int j = 0; j < poz.size(); ++j) {
                        if (poz[j]<0){
                            poz[j]=0;
                        }
                        if (poz[j]>w-1){
                            poz[j]=w-1;
                        }
                    }
                }
                for (int e = 0; e < gray; ++e) {
                    QVector<int> val;
                    for (int j = 0; j < poz.size(); ++j) {
                        val.push_back((unsigned char)arr[Pix(cons, poz[j],-1,true)+e]);
                    }
                    if (ui->Neighbor->isChecked()){
                        ret[Pix(cons, i, newW,true)+e]=Neigbor(poz,val,i/coef+ys);
                    }
                    if (ui->Bilineral->isChecked()){
                        ret[Pix(cons, i, newW,true)+e]=Bilineral(poz,val,i/coef+ys);
                    }
                    if (ui->Lanckhoz3->isChecked()){
                        ret[Pix(cons, i, newW,true)+e]=Lanchoz(poz,val,i/coef+ys);
                    }
                    if (ui->BCsplain->isChecked()){
                        ret[Pix(cons, i, newW,true)+e]=BCsplain(poz,val,i/coef+ys);
                    }
                }
            }
        }
    }
    return ret;
}

int Mashtab::Pix(int x, int y, int NewW, bool re)
{
    if (NewW==-1) NewW=w;
    if (re) return firstBytePix+x*gray*NewW+gray*y;
    return firstBytePix+y*gray*NewW+gray*x;
}

void Mashtab::on_show_clicked()
{
    QByteArray tempBlock;
    newH=ui->newH->value();
    newW=w;
    tempBlock=changeZoom(block,true, newH);
    newW=ui->newW->value();
    tempBlock=changeZoom(tempBlock,false,newW);
    emit showDizer(tempBlock, false, newW, newH);
}

void Mashtab::on_sawe_clicked()
{
    QByteArray tempBlock;
    newH=ui->newH->value();
    newW=w;
    tempBlock=changeZoom(block,true, newH);
    newW=ui->newW->value();
    tempBlock=changeZoom(tempBlock,false,newW);
    emit showDizer(tempBlock, true, newW, newH);
}

int Mashtab::Neigbor(QVector<double> position, QVector<int> value, double pix)
{
    double dif=10000,ret;
    for (int i = 0; i < position.size(); ++i) {
        if (abs(position[i]-pix)<dif){
            dif=abs(position[i]-pix);
            ret=i;
        }
    }
    return value[ret];
}

int Mashtab::Bilineral(QVector<double> position, QVector<int> value, double pix)
{
    if (position.size()==1){
        return value[0];
    }
    //qDebug()<<position<<value<<pix;
    double ret=0;
    for (int i = 1; i < position.size(); ++i) {
        position[i]-=position[0];
    }
    if (position.last()==0){
        return value[0];
    }
    pix-=position[0];
    pix/=position.last();
    position[0]=0;
    for (int i = 0; i < position.size(); ++i) {
        position[i]/=position.last();
        position[i]-=pix;
    }
    for (int i = 0; i < position.size(); ++i) {
        if (position[i]>=0){
            ret+=(1-position[i])*value[i];
        }else{
            ret+=(1+position[i])*value[i];
        }
    }
    ret/=(position.size()/2.0);
    if (ret<0){
        ret=0;
    }
    if (ret>255){
        ret=255;
    }
    //qDebug()<<ret;
    return ret;
}

int Mashtab::Lanchoz(QVector<double> position, QVector<int> value, double pix)
{
    double pi=3.14159265358979323846, summa=0;
    if (position.size()==1){
        return value[0];
    }
    //qDebug()<<position<<value<<pix;
    double ret=0;
    for (int i = 1; i < position.size(); ++i) {
        position[i]-=position[0];
    }
    if (position.last()==0){
        return value[0];
    }
    pix-=position[0];
    pix/=position.last()*2;
    position[0]=0;
    for (int i = 0; i < position.size(); ++i) {
        position[i]/=position.last()*2;
        position[i]-=pix;
    }
    QVector<double> coefs;
    coefs.resize(value.size());
    for (int i = 0; i < position.size(); ++i) {
        if (position[i]==0){
            coefs[i]=1;
        }else{
            coefs[i]=3*sin(pi*position[i])*sin(pi*position[i]/3)/pi/pi/position[i]/position[i];
        }
        summa+=coefs[i];
    }
    for (int i = 0; i < position.size(); ++i) {
        ret+=coefs[i]/summa*value[i];
    }
    if (ret<0){
        ret=0;
    }
    if (ret>255){
        ret=255;
    }
    //qDebug()<<ret;
    return ret;
}

/*int Mashtab::BCsplain(QVector<double> position, QVector<int> value, double pix)
{
    if (position.size()==1){
        return value[0];
    }
    //qDebug()<<position<<value<<pix;
    double ret=0;
    for (int i = 1; i < position.size(); ++i) {
        position[i]-=position[0];
    }
    if (position.last()==0){
        return value[0];
    }
    pix-=position[0];
    pix/=position.last();
    position[0]=0;
    for (int i = 0; i < position.size(); ++i) {
        position[i]/=position.last();
        position[i]-=pix;
    }
    for (int i = 0; i < position.size(); ++i) {
        if (position[i]>=0){
            ret+=(1-position[i])*value[i];
        }else{
            ret+=(1+position[i])*value[i];
        }
    }
    ret/=(position.size()/2.0);
    if (ret<0){
        ret=0;
    }
    if (ret>255){
        ret=255;
    }
    //qDebug()<<ret;
    return ret;
}*/

int Mashtab::BCsplain(QVector<double> position, QVector<int> value, double pix)
{
    double pi=3.14159265358979323846, summa=0;
    if (position.size()==1){
        return value[0];
    }
    //qDebug()<<position<<value<<pix;
    double ret=0;
    for (int i = 1; i < position.size(); ++i) {
        position[i]-=position[0];
    }
    if (position.last()==0){
        return value[0];
    }
    pix-=position[0];
    pix/=position.last()*2;
    position[0]=0;
    for (int i = 0; i < position.size(); ++i) {
        position[i]/=position.last()*2;
        position[i]-=pix;
    }
    QVector<double> coefs;
    double b=ui->Bcoef->value(),c=ui->Ccoef->value();
    coefs.resize(value.size());
    for (int i = 0; i < position.size(); ++i) {
        if (position[i]==0){
            coefs[i]=1;
        }else if (abs(position[i])<1){
            coefs[i]=(12-9*b-6*c)*pow(abs(position[i]),3)+(-18+12*b+6*c)*pow(position[i],2)+(6-2*b);
            coefs[i]/=6;
        }else{
            coefs[i]=(-b-6*c)*pow(abs(position[i]),3)+(62*b+30*c)*pow(position[i],2)+(-12*b-48*c)*abs(position[i])+(8*b+24*c);
            coefs[i]/=6;
        }
        summa+=coefs[i];
    }
    for (int i = 0; i < position.size(); ++i) {
        ret+=coefs[i]/summa*value[i];
    }
    if (ret<0){
        ret=0;
    }
    if (ret>255){
        ret=255;
    }
    //qDebug()<<ret;
    return ret;
}
