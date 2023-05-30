#ifndef FILTER_H
#define FILTER_H

#include <QWidget>

namespace Ui {
class Filter;
}

class Filter : public QWidget
{
    Q_OBJECT

public:
    explicit Filter(QByteArray arr = NULL, int w=0, int h=0,int firstBytePix = 15, bool isGray=false, QWidget *parent = nullptr);
    ~Filter();

signals:
    void showDizer(QByteArray arr, bool save);

private slots:
    void on_show_clicked();

    void on_sawe_clicked();

private:
    QByteArray DoFilter (QByteArray arr);
    int MedianFilter (QVector<QVector<int>> v);
    int GausFilter (QVector<QVector<int>> v);
    int LinMedianFilter (QVector<QVector<int>> v);
    int SobelFilter (QVector<QVector<int>> v);
    int CASFilter (QVector<QVector<int>> v);
    QByteArray Porog(QByteArray arr);

    int gray=3;
    int Pix(int x, int y, bool re=false);
    int w=0,h=0,firstBytePix=15;

    float clamp(float v, float lo, float hi);
    float mix(float a, float b, float t);

    QByteArray block;
    Ui::Filter *ui;
};

#endif // FILTER_H
