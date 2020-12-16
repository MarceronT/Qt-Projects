#ifndef MONLCDSLIDER_H
#define MONLCDSLIDER_H

#include <QWidget>

class MonLCDSlider : public QWidget
{
    Q_OBJECT
public:
    explicit MonLCDSlider(QString label,uint nbLcd=3, int min=0, int max=999, int valDep=-1,QWidget *parent = nullptr);

signals:
    void valueChanged(int);
public slots:
};

#endif // MONLCDSLIDER_H
