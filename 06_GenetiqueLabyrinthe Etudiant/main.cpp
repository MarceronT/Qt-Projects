#include "../shared/qstd.h"
using namespace qstd;
#include "parameters.h"
#include "evolutionaryprocess.h"

int main()
{
    cout<<QObject::tr("Génétique Labyrinthe")<<endl;
    // initialisation paramètres spécifiques au labyrinthe
    Parameters::crossoverRate = 0.6;
    Parameters::mutationRate = 0.1;
    Parameters::mutationAddRate = 0.2;
    Parameters::mutationDeleteRate = 0.1;
    Parameters::minFitness = 0;
    EvolutionaryProcess geneticAlgoMaze;
    geneticAlgoMaze.run();
}
