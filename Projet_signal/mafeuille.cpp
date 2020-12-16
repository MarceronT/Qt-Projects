#include "mafeuille.h"
#include<QPainter>
#include <cmath>

MaFeuille::MaFeuille(QWidget *parent) : QWidget(parent)
{
    setFixedSize(m_largeur,m_hauteur);
}

QPoint MaFeuille::coo(double x, double y)
{
    return QPoint(int(m_unite*x+m_largeur/2),int(-m_unite*y+m_hauteur/2));
}

void MaFeuille::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPolygon polygon;
    QPolygon polygon2;
    QPen bleu(Qt::blue,2);
    painter.setPen(bleu);
    // echelle des abscisses
    for (double t=1.25;t<10;t+=1.25){
        painter.drawLine(coo((-5+t),-0.125), coo((-5+t),0.125));
    }
    // echelle des ordonnées
    for (double t=1.25;t<10;t+=1.25){
        painter.drawLine(coo((-0.125),-5+t), coo((0.125),-5+t));
    }
    // droite des abscisses
    painter.drawLine(coo(-5,0), coo(5,0));
    // droite des ordonnées
    painter.drawLine(coo(0,5), coo(0,-5));
    // sinusoïdale
    for (double x=-5;x<=5;x+=0.001){
        double y = (amplitude/10)*(sin(x/(frequence/10)));
        y += offset;
        polygon<<coo(x,y);
    }
    QPen rouge(Qt::red,2);
    painter.setPen(rouge);
    painter.drawPolyline(polygon);
    // sinusoïdale
    for (double x=-5;x<=5;x+=0.001){
        double y = (amplitude2/10)*(sin((x+dephasage)/(frequence2/10)));
        y += offset;
        polygon2<<coo(x,y);
    }
    QPen black(Qt::black,2);
    painter.setPen(black);
    painter.drawPolyline(polygon2);
}

void MaFeuille::frequenceChanged(int f)
{
    frequence = f;
    repaint();
}

void MaFeuille::frequence2Changed(int f)
{
    frequence2 = f;
    repaint();
}

void MaFeuille::amplitudeChanged(int a)
{
    amplitude = a;
    repaint();
}

void MaFeuille::amplitude2Changed(int a)
{
    amplitude2 = a;
    repaint();
}

void MaFeuille::offsetChanged(int off)
{
    offset = off;
    repaint();
}

void MaFeuille::dephasageChanged(int deph)
{
    dephasage = deph;
    repaint();
}

