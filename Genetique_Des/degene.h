#ifndef DEGENE_H
#define DEGENE_H


class DeGene
{
private:
    int m_valeur;

public:
    DeGene(int valeur);
    DeGene(DeGene &dg);
    int getValeur() const;
    void setValeur(int valeur);
};

#endif // DEGENE_H
