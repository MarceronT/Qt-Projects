#include "degene.h"


int DeGene::getValeur() const
{
    return m_valeur;
}

void DeGene::setValeur(int valeur)
{
    m_valeur = valeur;
}

DeGene::DeGene(int valeur)
{
    m_valeur = valeur;
}

DeGene::DeGene(DeGene &dg)
{
    m_valeur = dg.m_valeur;
}
