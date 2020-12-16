#include "signal.h"
#include "monlcdslider.h"
#include "mafeuille.h"
#include<QPushButton>
#include<QApplication>
#include <QVBoxLayout>

signal::signal(QWidget *parent)
    : QWidget(parent)
{
    int f0=5, a0=10, o0=0;
    // créer les différents widgets de l'application
    MaFeuille *mf=new MaFeuille();
    MonLCDSlider *frequence=new MonLCDSlider("Fréquence",2,0,50,f0);
    MonLCDSlider *amplitude=new MonLCDSlider("Amplitude",2,0,50,a0);
    MonLCDSlider *offSet=new MonLCDSlider("OffSet",2,-10,10,o0);
    MonLCDSlider *dephasage=new MonLCDSlider("Déphasage",2,0,50,0);
    QPushButton *qpb=new QPushButton("Quitter");

    // agencer les widgets dans un layout
    QVBoxLayout *qvb=new QVBoxLayout();
    qvb->addWidget(mf);
    qvb->addWidget(frequence);
    qvb->addWidget(amplitude);
    qvb->addWidget(offSet);
    qvb->addWidget(dephasage);
    qvb->addWidget(qpb);
    setLayout(qvb);

    // connecter les signaux aux récepteurs
    connect(frequence, SIGNAL(valueChanged(int)), mf, SLOT(frequenceChanged(int)));
    connect(frequence, SIGNAL(valueChanged(int)), mf, SLOT(frequence2Changed(int)));
    connect(amplitude,SIGNAL(valueChanged(int)),mf,SLOT(amplitudeChanged(int)));
    connect(amplitude,SIGNAL(valueChanged(int)),mf,SLOT(amplitude2Changed(int)));
    connect(offSet,SIGNAL(valueChanged(int)),mf,SLOT(offsetChanged(int)));
    connect(dephasage,SIGNAL(valueChanged(int)),mf,SLOT(dephasageChanged(int)));
    connect(qpb,SIGNAL(clicked()),qApp,SLOT(quit()));
    emit frequence->valueChanged(f0);
    emit amplitude->valueChanged(a0);
    emit offSet->valueChanged(o0);
}

signal::~signal()
{
}

