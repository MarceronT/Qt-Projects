#include "deevolutionaryprocess.h"
#include "parameters.h"

DeIndividual *DeEvolutionaryProcess::selection()
{
    int totalRanks = Parameters::individualsNb*(Parameters::individualsNb+1)/2;
    int rand = Parameters::randomGenerator->get(totalRanks);
    int indIndex = 0;
    int nbParts = Parameters::individualsNb;
    int totalParts = 0;

    while (totalParts<rand) {
        indIndex++;
        totalParts+=nbParts;
        nbParts--;
    }
    std::sort(population.begin(), population.end(), DeIndividual::lessFitnessThan);
    return population.at(indIndex);
}

void DeEvolutionaryProcess::survival(QList<DeIndividual *> &newGeneration)
{
    population = newGeneration;
}

DeEvolutionaryProcess::DeEvolutionaryProcess()
{
    Parameters::print("Generation individus", 0);
    for (int i=0; i<Parameters::individualsNb; i++){
        DeIndividual *indiv=new DeIndividual();
        population.append(indiv);
    }
}

void DeEvolutionaryProcess::run()
{
    bestFitness = Parameters::minFitness + 1;
    DeIndividual *bestInd;
    while(generationNb<Parameters::generationsMaxNb && bestFitness>Parameters::minFitness) {
        Parameters::print("Evaluation Individus", 0);
        for (int i=0; i<population.size(); i++){
            DeIndividual *ind=population.at(i);
            ind->evaluate();
        }
        //Meilleur individu
        std::sort(population.begin(), population.end(), DeIndividual::lessFitnessThan);
        bestInd=population.at(0);
        bestFitness = bestInd->getFitness();
        //création d'une nouvelle génération + stockage alpha
        QList<DeIndividual *> newGeneration;
        newGeneration.append(bestInd);
        for (int i=0; i<Parameters::individualsNb-1; i++){
            DeIndividual *father = selection();
            DeIndividual *indiv = new DeIndividual(father);
            newGeneration.append(indiv);
        }
        survival(newGeneration);
        generationNb++;
    }
}
