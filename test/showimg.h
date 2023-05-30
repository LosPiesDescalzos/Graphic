#ifndef SHOWIMG_H
#define SHOWIMG_H

#include <QMainWindow>
#include <linesettings.h>

namespace Ui {
class ShowImg;
}

class ShowImg : public QMainWindow
{
    Q_OBJECT

public:
    int x,y;
    explicit ShowImg(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *event);
    void ShowI(QPixmap pix);

    ~ShowImg();

signals:
    void drawLine(int x1, int y1, int x2, int y2, int r, int g, int b, double t, bool smoothing, int thick);

public slots:
    void SaveSettings(int r, int g, int b, double t, bool smoothing, int thick);

private slots:
    void on_lineDraw_triggered();

    void on_lineSettings_triggered();

private:

    int r=0,g=0,b=0;
    double t=1;
    bool smoothing = true;
    int thick =5;
    bool startChecking = false;
    bool isSecondClick = false;
    Ui::ShowImg *ui;
    LineSettings *lineSettings;
};

#endif // SHOWIMG_H
