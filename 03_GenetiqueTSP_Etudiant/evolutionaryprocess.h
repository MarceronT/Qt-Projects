#ifndef EVOLUTIONARYPROCESS_H
#define EVOLUTIONARYPROCESS_H

#include <QList>
#include "tspindividual.h"

class EvolutionaryProcess
{
private:
    QList<TSPIndividual *> population;
    int generationNb = 0;
    int generationNb2 = 0;
    double bestFitness;
    double worstFitness;

    /*! \brief selection : choix d'un père avec "roue biaisée" pour la génération suivante
     */
    TSPIndividual *selection();
    TSPIndividual *selection_bis();
    /*! \brief survival : remplacement de l'ancienne génération par la nouvelle
     */
    void survival(QList<TSPIndividual *> &newGeneration);
    void survival_bis(QList<TSPIndividual *> &newGeneration_bis);
public:
    EvolutionaryProcess();
    void run();
};

#endif // EVOLUTIONARYPROCESS_H
