#include "filter.h"
#include "ui_filter.h"
#include <QDebug>
#include <alg.h>

Filter::Filter(QByteArray arr, int w, int h,int firstBytePix, bool isGray, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Filter)
{
    if (isGray){
        gray=1;
    }
    this->w=w;
    this->h=h;
    this->firstBytePix=firstBytePix;
    ui->setupUi(this);
    block = arr;
    mix(2,3,4);
    clamp(1,2,3);
}

Filter::~Filter()
{
    delete ui;
}

void Filter::on_show_clicked()
{
    QByteArray temp;
    temp = DoFilter(block);
    emit showDizer(temp,false);
}

void Filter::on_sawe_clicked()
{
    QByteArray temp;
    temp = DoFilter(block);
    emit showDizer(temp,true);
}

QByteArray Filter::DoFilter(QByteArray arr)
{
    if (ui->porog->isChecked() || ui->ocu->isChecked()){
        arr = Porog(arr);
    }else{
        int rad = 1;
        if (ui->median->isChecked()){
            rad=ui->medYadro->value();
        }
        if (ui->lineraMed->isChecked()){
            rad=ui->linYadro->value();
        }
        if (ui->gaus->isChecked()){
            rad=3*ui->gausYadro->value();
        }
        int X,Y;
        QByteArray temp = arr;
        for (int e = 0; e < gray; ++e) {
            for (int i = 0; i < w; ++i) {

                QVector<QVector<int>> v;
                v.resize(rad*2+1);
                for (int x = i-rad; x < i+rad+1; ++x) {
                    for (int y = 0-rad-1; y < 0+rad; ++y) {
                        X=x;
                        Y=y;
                        if (X<0){
                            X=0;
                        }
                        if (Y<0){
                            Y=0;
                        }
                        if (X>=w){
                            X=w-1;
                        }
                        if (Y>=h){
                            Y=h-1;
                        }
                        //qDebug()<<x+rad<<i<<j<<x<<y;
                        v[x-i+rad].push_back((unsigned char)temp[Pix(X,Y)+e]);
                    }
                }

                for (int j = 0; j < h; ++j) {

                    for (int x = i-rad; x < i+rad+1; ++x) {
                            X=x;
                            Y=j+rad;
                            X=clamp(X,0,w-1);
                            Y=clamp(Y,0,h-1);
                            /*if (X<0){
                                X=0;
                            }
                            if (Y<0){
                                Y=0;
                            }
                            if (X>=w){
                                X=w-1;
                            }
                            if (Y>=h){
                                Y=h-1;
                            }*/
                            //qDebug()<<x+rad<<i<<j<<x<<y;
                            v[x-i+rad].pop_front();
                            v[x-i+rad].push_back((unsigned char)temp[Pix(X,Y)+e]);
                    }

                    if (ui->median->isChecked()){
                        arr[Pix(i,j)+e]=MedianFilter(v);
                    }
                    if (ui->lineraMed->isChecked()){
                        arr[Pix(i,j)+e]=LinMedianFilter(v);
                    }
                    if (ui->gaus->isChecked()){
                        arr[Pix(i,j)+e]=GausFilter(v);
                    }
                    if (ui->sobel->isChecked()){
                        arr[Pix(i,j)+e]=SobelFilter(v);
                    }
                    if (ui->CAS->isChecked()){
                        arr[Pix(i,j)+e]=CASFilter(v);
                    }
                }
            }
        }
    }

    /*
        for (int e = 0; e < gray; ++e) {
            for (int i = 0; i < w; ++i) {
                for (int j = 0; j < h; ++j) {
                    QVector<QVector<int>> v;
                    v.resize(rad*2+1);
                    for (int x = i-rad; x < i+rad+1; ++x) {
                        for (int y = j-rad; y < j+rad+1; ++y) {
                            X=x;
                            Y=y;
                            if (X<0){
                                X=0;
                            }
                            if (Y<0){
                                Y=0;
                            }
                            if (X>=w){
                                X=w-1;
                            }
                            if (Y>=h){
                                Y=h-1;
                            }
                            //qDebug()<<x+rad<<i<<j<<x<<y;
                            v[x-i+rad].push_back((unsigned char)temp[Pix(X,Y)+e]);
                        }
                    }
                    if (ui->median->isChecked()){
                        arr[Pix(i,j)+e]=MedianFilter(v);
                    }
                    if (ui->lineraMed->isChecked()){
                        arr[Pix(i,j)+e]=LinMedianFilter(v);
                    }
                    if (ui->gaus->isChecked()){
                        arr[Pix(i,j)+e]=GausFilter(v);
                    }
                    if (ui->sobel->isChecked()){
                        arr[Pix(i,j)+e]=SobelFilter(v);
                    }
                    if (ui->CAS->isChecked()){
                        arr[Pix(i,j)+e]=CASFilter(v);
                    }
                }
            }
        }
     */
    return arr;
}

int Filter::MedianFilter(QVector<QVector<int> > v)
{
    int rad = v.size();
    QVector<int> line;
    for (int i = 0; i < rad; ++i) {
        for (int j = 0; j < rad; ++j) {
            line.push_back(v[i][j]);
        }
    }
    qSort(line);
    //qDebug()<<line;
    return line[rad*rad/2];
}

int Filter::GausFilter(QVector<QVector<int> > v)
{
    int rad=v.size(),g=(rad-1)/6;
    int radQrt=pow((rad-1)/6,2);
    double pi=3.14159265358979323846,sum=0;
    for (int i = 0; i < rad; ++i) {
        for (int j = 0; j < rad; ++j) {
            sum+=exp(-(pow(i-rad/2,2)+pow(j-rad/2,2))/2/radQrt)*v[i][j];
        }
    }
    sum/=(2*pi*radQrt);
    if (sum<0) sum=0;
    if (sum>255) sum=255;
    //qDebug()<<exp(1);
    return sum;
}

int Filter::LinMedianFilter(QVector<QVector<int> > v)
{
    int rad=v.size();
    double sum=0;
    for (int i = 0; i < rad; ++i) {
        for (int j = 0; j < rad; ++j) {
            sum+=v[i][j];
        }
    }
    sum/=(rad*rad);
    if (sum<0) sum=0;
    if (sum>255) sum=255;
    //qDebug()<<exp(1);
    return sum;
}

int Filter::SobelFilter(QVector<QVector<int> > v)
{
    double gx=0,gy=0,sum=0;
    gy+=v[0][0]+v[0][2]-v[2][0]-v[2][2]+2*v[0][1]-2*v[2][1];
    gy+=-v[0][0]+v[0][2]-v[2][0]+v[2][2]+2*v[1][2]-2*v[1][0];
    sum=sqrt(gy*gy+gx*gx);

    if (sum<0) sum=0;
    if (sum>255) sum=255;
    //qDebug()<<exp(1);
    return sum;
}

int Filter::CASFilter(QVector<QVector<int> > v)
{
    // fetch a 3x3 neighborhood around the pixel 'e',
    //  a b c
    //  d(e)f
    //  g h i

    float a = v[0][0]/255.0;
    float b = v[0][1]/255.0;
    float c = v[0][2]/255.0;

    float d = v[1][0]/255.0;
    float e = v[1][1]/255.0;
    float f = v[1][2]/255.0;

    float g = v[2][0]/255.0;
    float h = v[2][1]/255.0;
    float i = v[2][2]/255.0;

    // Soft min and max.
    //  a b c			b
    //  d e f * 0.5	+ d e f * 0.5
    //  g h i			h
    // These are 2.0x bigger (factored out the extra multiply).

    float mnL = min(min(min(d, e), min(f, b)), h);
    float mxL = max(max(max(d, e), max(f, b)), h);

    float mnL2 = min(mnL, min(min(a, c), min(g, i)));
    mnL += mnL2;

    float mxL2 = max(mxL, max(max(a, c), max(g, i)));
    mxL += mxL2;

    // Smooth minimum distance to signal limit divided by smooth max.
    const float bdval = bool(1) ? 2.0 : 1.0;

    float ampL = clamp(min(mnL, bdval - mxL) / mxL, 0.0, 1.0);


    // Shaping amount of sharpening.
    ampL = sqrt(ampL);

   // Filter shape.
   //  0 w 0
   //  w 1 w
   //  0 w 0

    const float peak = -(mix(8.0, 5.0, clamp(ui->sharpness->value(), 0.0, 1.0)));
    float wL = ampL / peak;

    // Filter.
    // Using green coef only
    float Weight = 1.0 + 4.0 * wL;
    float pix = 0.0;
    pix = ((b + d + f + h) * wL) + e;

    pix /= Weight;

    pix = clamp(pix, 0.0, 1.0);
    //qDebug()<<(int)(e*255)<<(int)(pix*255);
    return pix*255;
}

QByteArray Filter::Porog(QByteArray arr)
{
    int porog[3];
    if (ui->porog->isChecked()){
        porog[0]=ui->porogValue->value();
        porog[1]=ui->porogValue->value();
        porog[2]=ui->porogValue->value();
    }else {
        for (int e = 0; e < gray; ++e) {
            QVector<int> hist;
            hist.clear();
            hist.resize(256);

            for (int x = 0; x < w; ++x) {
                for (int y = 0; y < h; ++y) {
                    hist[(unsigned char)arr[Pix(x,y)+e]]++;
                }
            }

            /*for (int i = 0; i < arr.size()-firstBytePix; ++i) {
                hist[(unsigned char)arr[i*gray+firstBytePix+e]]++;
            }*/
            //qDebug()<<hist;

            // Необходимы для быстрого пересчёта разности дисперсий между классами
            int all_pixel_count = w*h;

            int all_intensity_sum=0;
            for (int i = 0; i < hist.size(); ++i) {
                all_intensity_sum+=hist[i]*i;
            }
            //qDebug()<<all_intensity_sum<<all_pixel_count;

            int best_thresh = 0;
            double best_sigma = 0.0;

            int first_class_pixel_count = 0;
            int first_class_intensity_sum = 0;

            // Перебираем границу между классами
            // thresh < INTENSITY_LAYER_NUMBER - 1, т.к. при 255 в ноль уходит знаменатель внутри for
            for (int thresh = 0; thresh < 256 - 1; ++thresh) {
                first_class_pixel_count += hist[thresh];
                first_class_intensity_sum += thresh * hist[thresh];

                double first_class_prob = first_class_pixel_count / (double) all_pixel_count;
                double second_class_prob = 1.0 - first_class_prob;

                double first_class_mean;
                double second_class_mean;

                if (first_class_pixel_count==0){
                    first_class_mean=0;
                }else{
                    first_class_mean = first_class_intensity_sum / (double) first_class_pixel_count;
                }

                if((all_pixel_count - first_class_pixel_count)==0){
                    second_class_mean=0;
                }else{
                    second_class_mean = (all_intensity_sum - first_class_intensity_sum)
                        / (double) (all_pixel_count - first_class_pixel_count);
                }

                double mean_delta = first_class_mean - second_class_mean;

                double sigma = first_class_prob * second_class_prob * mean_delta * mean_delta;
                //qDebug()<<sigma<<thresh<<first_class_mean<<second_class_mean<<(all_intensity_sum - first_class_intensity_sum)<<(all_pixel_count - first_class_pixel_count);
                if (sigma > best_sigma) {
                    best_sigma = sigma;
                    best_thresh = thresh;
                }
            }

            porog[e]=best_thresh;
        }
    }
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            for (int e = 0; e < gray; ++e) {
                if ((unsigned char)arr[Pix(i,j)+e]>porog[e]){
                    arr[Pix(i,j)+e]=255;
                }else{
                    arr[Pix(i,j)+e]=0;
                }
            }
        }
    }
    return arr;
}

int Filter::Pix(int x, int y, bool re)
{
    if (re) return firstBytePix+x*gray*w+gray*y;
    return firstBytePix+y*gray*w+gray*x;
}

float Filter::clamp(float v, float lo, float hi)
{
    if (v<lo) return lo;
    if (v>hi) return hi;
    return v;
}

float Filter::mix(float a, float b, float t)
{
    return a*((float)1-t)+b*t;
}
