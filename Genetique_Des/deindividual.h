#ifndef DEINDIVIDUAL_H
#define DEINDIVIDUAL_H
#include <QList>
#include "degene.h"

class DeIndividual
{
private:
    int m_fitness=-1;

public:
    QList<DeGene *> m_genome;
    // à la première génération
    DeIndividual();
    // on génère un individu à partir d'un autre
    DeIndividual (DeIndividual *father);
    void mutate();
    QString toString();
    int evaluate();
    static bool lessFitnessThan(DeIndividual *di1, DeIndividual *di2);
    int getFitness() const;
    void setFitness(int fitness);
};

#endif // DEINDIVIDUAL_H
