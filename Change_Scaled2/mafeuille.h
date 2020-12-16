#ifndef MAFEUILLE_H
#define MAFEUILLE_H

#include <QWidget>

class MaFeuille : public QWidget
{
    Q_OBJECT
private:
    int m_taille_unite=40;
    int m_largeur=800;
    int m_hauteur=
public:
    explicit MaFeuille(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // MAFEUILLE_H
