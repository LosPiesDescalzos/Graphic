#ifndef MASHTAB_H
#define MASHTAB_H

#include <QWidget>

namespace Ui {
class Mashtab;
}

class Mashtab : public QWidget
{
    Q_OBJECT

public:
    explicit Mashtab(QByteArray arr = NULL, int w=0, int h=0,int firstBytePix = 15, bool isGray=false, QWidget *parent = nullptr);
    ~Mashtab();
    QByteArray changeZoomToJPEG (int W, int H);

signals:
    void showDizer(QByteArray arr, bool save, int w, int h);

private slots:
    void on_show_clicked();

    void on_sawe_clicked();

private:
    QByteArray changeZoom (QByteArray arr, bool incH, int inc);
    int Neigbor(QVector<double> position, QVector<int> value, double pix);
    int Bilineral(QVector<double> position, QVector<int> value, double pix);
    int Lanchoz(QVector<double> position, QVector<int> value, double pix);
    int BCsplain(QVector<double> position, QVector<int> value, double pix);

    int gray=3;
    int nc = 256/2;
    int Pix(int x, int y,int NewW=-1 , bool re=false);
    int w=0,h=0,firstBytePix=15,newW,newH;

    QByteArray block;
    QByteArray tempoBlock;


    Ui::Mashtab *ui;
};

#endif // MASHTAB_H
