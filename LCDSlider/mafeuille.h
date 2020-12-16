#ifndef MAFEUILLE_H
#define MAFEUILLE_H

#include <QWidget>

class MaFeuille : public QWidget
{
    Q_OBJECT
private:
    int m_rayon;
    int m_cote;
public:
    explicit MaFeuille(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
signals:

public slots:
    void rayon_Changed(int r);
    void cote_Changed(int c);
};

#endif // MAFEUILLE_H
