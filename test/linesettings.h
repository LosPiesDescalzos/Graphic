#ifndef LINESETTINGS_H
#define LINESETTINGS_H

#include <QWidget>

namespace Ui {
class LineSettings;
}

class LineSettings : public QWidget
{
    Q_OBJECT

public:
    explicit LineSettings(QWidget *parent = nullptr);
    ~LineSettings();

signals:
    void SaveSettings(int r, int g, int b, double t, bool smoothing, int thick);

private slots:
    void on_Sawe_clicked();

    void on_colorChoose_clicked();

private:
    int r=0,g=0,b=0;
    Ui::LineSettings *ui;
};

#endif // LINESETTINGS_H
