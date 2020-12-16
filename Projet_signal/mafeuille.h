#ifndef MAFEUILLE_H
#define MAFEUILLE_H

#include <QWidget>

class MaFeuille : public QWidget
{
    Q_OBJECT
private:
    int m_largeur = 800;
    int m_hauteur = 800;
    int m_unite = 100;
    double frequence=1;
    double frequence2=1;
    double amplitude=1;
    double amplitude2=1;
    double offset=0;
    double dephasage=1;

public:
    explicit MaFeuille(QWidget *parent = nullptr);
    QPoint coo(double x, double y);
    void paintEvent(QPaintEvent *);
signals:

public slots:
    void frequenceChanged (int f);
    void frequence2Changed (int f);
    void amplitudeChanged (int a);
    void amplitude2Changed (int a);
    void offsetChanged (int off);
    void dephasageChanged (int deph);
};

#endif // MAFEUILLE_H
