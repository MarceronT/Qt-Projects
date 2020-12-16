#include "parameters.h"
#include <QString>
#include "qstd.h"
using namespace qstd;

int Parameters::individualsNb = 50;
int Parameters::generationsMaxNb = 20;
int Parameters::initialGenesNb = 0;
int Parameters::minFitness = 15;

double Parameters::mutationRate = 0.5;
double Parameters::mutationAddRate = 0.2;
double Parameters::mutationDeleteRate = 0.1;
double Parameters::crossoverRate = 0.6;
int Parameters::nbDes=15;

// TODO : modifier la graine
MyRandom *Parameters::randomGenerator=new MyRandom();

int Parameters::debug = 1;

void Parameters::print(QString txt, int d)
{
    if(d<debug)
        cout<<txt<<endl;
}
