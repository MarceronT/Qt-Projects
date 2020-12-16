#include "../shared/qstd.h"
using namespace qstd;
#include "humain.h"
#include "permanent.h"
#include "temporaire.h"

int main()
{
    cout<<"Projet Salaries (Heritage)."<<endl;
    cout<<endl<<"Test Humain :"<<endl;
    Humain lui("Ryan","Gosling",Masculin);
    Humain elle("Natalie","Portman",Feminin);
    cout<<lui.toString()<<endl;
    cout<<elle.toString()<<endl;

    cout<<endl<<"Test Permanent :"<<endl;
    Permanent p("Arnold","Swhartzy",Masculin,10000);
    cout<<p.toString()<<endl;

    cout<<endl<<"Test Temporaire :"<<endl;
    Temporaire t("Muhumed","Ali",Masculin,7,400);
    cout<<t.toString()<<endl;
}
