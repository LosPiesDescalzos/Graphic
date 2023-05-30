#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <showimg.h>
#include <gammacorrect.h>
#include <colorconvert.h>
#include <dizering.h>
#include <tuple>
#include <execution>
#include <mashtab.h>
#include <contrast.h>
#include <filter.h>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void drLine(int x1, int y1, int x2, int y2, int r, int g, int b, double t, bool smoothing, int thick);
    void setGamma(QString gam);
    void convertGamma(QString gam);
    void showDizer(QByteArray arr, bool save);
    void showZoom(QByteArray arr, bool save, int w, int h);

private slots:

    void on_showImg_clicked();

    void on_changeColor_clicked();

    void on_gammaCorrection_triggered();

    void on_openFile_triggered();

    void on_saveFile_triggered();

    void on_gradGen_clicked();

    void on_dizerButton_triggered();

    void on_mashtab_triggered();

    void on_filter_triggered();

    void on_contrastCorection_triggered();

private:
    QString colorType="RGB";
    QString format="pnm";
    QPixmap picture;
    QByteArray RGBblock;
    QByteArray curblock;
    QByteArray block;
    const unsigned int chunk = 16384;
    int firstPixByte,h,w;
    double gamma=1;
    bool isGrey;

    int ConvertToPNG (QByteArray arr);
    int ConvertToJPG (QByteArray arr);
    QVector<QVector<int>> buildHafTree (QByteArray arr);
    void Diper(QVector<QVector<int>> &tree, int &cur);
    QVector<QVector<int>> zigzagArr (QByteArray arr, bool isUnsigned = true);
    QVector<QVector<int>> zigzagArr (QVector<int> arr, bool isUnsigned = true);
    uint32_t CRC32(QByteArray data);
    QByteArray Inflate (QByteArray arr);
    QByteArray Deflate (QByteArray arr);
    QByteArray ConvertFromPNG (QByteArray arr);
    QByteArray DrawLine(QByteArray arr, int x1, int y1, int x2, int y2, int r=0, int g=0, int b=0, double t=1, bool smoothing = true, int thick =5);
    QByteArray ConvertToRGB (QByteArray arr);
    QByteArray ConvertFromRGB (QByteArray arr);
    QByteArray ChanelCheck (QByteArray arr);
    QPixmap ConvertBytToPix (QByteArray arr, int startI);
    QPixmap CorrectGam(QByteArray arr, bool isConvert=false);

    int Pix(int x,int y, bool re=false);

    void colorCheck();

    Ui::MainWindow *ui;
    GammaCorrect *gammaCorect;
    ShowImg *showImg;
    Dizering *dizering;
    Mashtab *mashtab;
    Contrast *contrast;
    Filter *filter;
    ColorConvert ColC;
};

#endif // MAINWINDOW_H
