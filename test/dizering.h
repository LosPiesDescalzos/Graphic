#ifndef DIZERING_H
#define DIZERING_H

#include <QWidget>

namespace Ui {
class Dizering;
}

class Dizering : public QWidget
{
    Q_OBJECT

public:
    explicit Dizering(QByteArray arr = NULL, int w=0, int h=0,int firstBytePix = 15, bool isGray=false, QWidget *parent = nullptr);
    ~Dizering();

signals:
    void showDizer(QByteArray arr, bool save);

private slots:
    void on_showDiz_clicked();

    void on_saveDiz_clicked();

private:
    int gray=3;
    int nc = 256/3;
    int Pix(int x, int y, bool re=false);
    int w=0,h=0,firstBytePix=15;
    QByteArray noDiz(QByteArray arr);
    QByteArray ordDiz(QByteArray arr);
    QByteArray randomDiz(QByteArray arr);
    QByteArray floydDiz(QByteArray arr);
    QByteArray atkiDiz(QByteArray arr);

    QByteArray block;
    Ui::Dizering *ui;
};

#endif // DIZERING_H
