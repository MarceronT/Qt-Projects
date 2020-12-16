#ifndef COMPLEXE_H
#define COMPLEXE_H
#include <QString>

class complexe
{
private:
    double m_reel;
    double m_imaginaire;
public:
    complexe(double r=0,double i=0);
    complexe carre() const;
    QString toString();
    complexe ajoute(const complexe& z) const;
    double module() const;
    bool diverge() const;

};

#endif // COMPLEXE_H
