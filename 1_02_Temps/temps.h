#ifndef TEMPS_H
#define TEMPS_H
#include <QString>

class Temps
{
private:
    int h, m, s;
public:
    Temps(int nh, int nm, int ns);
    int totalSecondes();
    void ajouteSecondes(int ns);
    int getH() const;
    void setH(int value);
    int getM() const;
    void setM(int value);
    int getS() const;
    void setS(int value);
    QString toString();
};

#endif // TEMPS_H
