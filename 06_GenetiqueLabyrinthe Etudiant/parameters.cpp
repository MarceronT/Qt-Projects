#include "parameters.h"
#include "../shared/qstd.h"
using namespace qstd;

int Parameters::individualsNb = 5;
int Parameters::generationsMaxNb = 50;
int Parameters::initialGenesNb = 10;
int Parameters::minFitness = 0;

double Parameters::mutationRate = 0.1;
double Parameters::mutationAddRate = 0.2;
double Parameters::mutationDeleteRate = 0.1;
double Parameters::crossoverRate = 0.6;
// TODO : modifier la graine
MyRandom *Parameters::randomGenerator=new MyRandom();

int Parameters::debug = 1;

void Parameters::print(QString txt, int d)
{
    if(d<debug)
        cout<<txt<<endl;
}
