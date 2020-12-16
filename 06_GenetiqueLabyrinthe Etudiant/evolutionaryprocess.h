#ifndef EVOLUTIONARYPROCESS_H
#define EVOLUTIONARYPROCESS_H

#include <QList>
#include "mazeindividual.h"

class EvolutionaryProcess
{
private:
    QList<MazeIndividual *> population;
    int generationNb=0;
    double bestFitness;
    MazeIndividual *selection();
    void survival(QList<MazeIndividual *> &newGeneration);
public:
    EvolutionaryProcess();
    void run();
};

#endif // EVOLUTIONARYPROCESS_H
