#ifndef TEMPORAIRE_H
#define TEMPORAIRE_H
#include "humain.h"

class Temporaire : public Humain
{
private:
    double m_tx_hor;
    double m_nb_heure;
public:
    Temporaire(QString p, QString n, Sexe s, double tx, double nb);
    double salaire();
    QString getClassName();
    QString toString();
};

#endif // TEMPORAIRE_H
