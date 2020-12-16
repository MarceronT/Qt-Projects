#include "evolutionaryprocess.h"
#include "parameters.h"

static QString txt;

MazeIndividual *EvolutionaryProcess::selection()
{
    int totalRanks = Parameters::individualsNb*(Parameters::individualsNb+1)/2;
        int rand=Parameters::randomGenerator->get(totalRanks);
        int indIndex = 0;
        int nbParts = Parameters::individualsNb;
        int totalParts = 0;

        while(totalParts<rand) {
            indIndex++;
            totalParts+=nbParts;
            nbParts--;
        }
        std::sort(population.begin(), population.end(), MazeIndividual::lessFitnessThan);
        return population.at(indIndex);
}

void EvolutionaryProcess::survival(QList<MazeIndividual *> &newGeneration)
{
    population = newGeneration;
}

EvolutionaryProcess::EvolutionaryProcess()
{
    Maze::init(Maze::Maze1);
    for(int i=0;i<Parameters::individualsNb;i++) {
        MazeIndividual *indiv=new MazeIndividual();
        population.append(indiv);
    }
}

void EvolutionaryProcess::run()
{
    bestFitness = Parameters::minFitness +1;
    int nbLoop=0;
    MazeIndividual *bestInd;
    while(generationNb<Parameters::generationsMaxNb && bestFitness>Parameters::minFitness) {
        for(int i=0;i<population.size();i++) {
            MazeIndividual *ind=population.at(i);
            ind->evaluate();
        }
        std::sort(population.begin(), population.end(), MazeIndividual::lessFitnessThan);
        bestInd=population.at(0);
        bestFitness = bestInd->getFitness();
        // sélection et reproduction
        QList<MazeIndividual *> newGeneration;
        newGeneration.append(bestInd);
        for(int i=0; i<Parameters::individualsNb-1; i++) {
            // 1 ou 2 parents ?
            if(Parameters::randomGenerator->getFloat()<Parameters::crossoverRate) {
                // père ET mère
                MazeIndividual *father = selection();
                MazeIndividual *mother = selection();
                MazeIndividual *indiv = new MazeIndividual(father, mother);
                newGeneration.append(indiv);
            }
            else {
                MazeIndividual *father=selection();
                MazeIndividual *indiv = new MazeIndividual(father);
                newGeneration.append(indiv);
            }
        }
        survival(newGeneration);
        generationNb++;
        /*if(nbLoop==1)
            exit(0);*/
        nbLoop++;
    }
    txt.sprintf("\nGeneration %d : Le meilleur est %s !",generationNb, bestInd->toString().toStdString().c_str());
    Parameters::print(txt, 0);
}
