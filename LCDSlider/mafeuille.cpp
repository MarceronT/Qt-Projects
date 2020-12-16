#include "mafeuille.h"
#include<QPainter>

MaFeuille::MaFeuille(QWidget *parent) : QWidget(parent)
{
    setFixedSize(800,800);
}

void MaFeuille::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    QPen rose(QColor(144,155,200),2);
    QPen rouge(QColor(14,87,234),2);

    // carré rose
    p.setPen(rose);
    p.drawRect(10,10,m_cote,m_cote);

    // rond rouge
    p.setPen(rouge);
    p.drawEllipse(150,10,m_rayon*2, m_rayon*2);
}

void MaFeuille::rayon_Changed(int r)
{
    m_rayon=r;
    repaint();
}

void MaFeuille::cote_Changed(int c)
{
    m_cote=c;
    repaint();
}
