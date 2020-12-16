#ifndef PLANETE_H
#define PLANETE_H
#include <QString>

class Planete
{
private:
    QString m_nom;
    int m_diametre;
    double m_distance;
public:
    Planete(QString nom, int diametre, double distance);
    QString toString();
    double distanceEntre(const Planete &p) const;
    double getDistance() const;
};
#endif // PLANETE_H
