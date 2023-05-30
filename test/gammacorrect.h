#ifndef GAMMACORRECT_H
#define GAMMACORRECT_H

#include <QWidget>

namespace Ui {
class GammaCorrect;
}

class GammaCorrect : public QWidget
{
    Q_OBJECT

public:
    explicit GammaCorrect(QWidget *parent = nullptr);
    ~GammaCorrect();

private:
    Ui::GammaCorrect *ui;

signals:
    void setGamma(QString);
    void convertGamma(QString);

private slots:
    void on_set_clicked();
    void on_convert_clicked();
};

#endif // GAMMACORRECT_H
