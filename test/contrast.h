#ifndef CONTRAST_H
#define CONTRAST_H

#include <QWidget>
#include <qcustomplot.h>

namespace Ui {
class Contrast;
}

class Contrast : public QWidget
{
    Q_OBJECT

public:
    explicit Contrast(QByteArray arr = NULL, int w=0, int h=0,int firstBytePix = 15, bool isGray=false, QWidget *parent = nullptr);
    ~Contrast();

signals:
    void showDizer(QByteArray arr, bool save);

private slots:
    void on_show_clicked();

    void on_sawe_clicked();

private:
    void CountData(QByteArray arr);
    void setHists(bool firsttime = false);
    void makeHist(QVector<double> data, QString color, QCustomPlot *customPlot, int index, bool firsttime = false);
    QByteArray ChangeContrast(QByteArray arr);
    int gray=3;
    int nc = 256/2;
    int Pix(int x, int y, bool re=false);
    int w=0,h=0,firstBytePix=15;
    //QCPBars *bar[3];
    QVector<QCPBars *> bar;
    QVector<QVector<double>> data;

    QByteArray block;
    Ui::Contrast *ui;
};

#endif // CONTRAST_H
