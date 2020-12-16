#ifndef DEEVOLUTIONARYPROCESS_H
#define DEEVOLUTIONARYPROCESS_H

#include <QList>
#include "deindividual.h"

class DeEvolutionaryProcess
{
private:
    QList<DeIndividual *> population;
    int generationNb = 0;
    int bestFitness;
    DeIndividual *selection();
    void survival(QList<DeIndividual *> &newGeneration);

public:
    DeEvolutionaryProcess();
    void run();
};

#endif // DEEVOLUTIONARYPROCESS_H
