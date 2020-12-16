#include "monwidgetprincipal.h"
#include "monlcdslider.h"
#include <QVBoxLayout>
#include<mafeuille.h>
#include<QPushButton>
#include<QApplication>

MonWidgetPrincipal::MonWidgetPrincipal(QWidget *parent)
    : QWidget(parent)
{
    // créer les différents widgets de l'application
    MaFeuille *mf=new MaFeuille();
    MonLCDSlider *lcdRayon=new MonLCDSlider("Rayon Cercle",2,0,100);
    MonLCDSlider *lcdCote=new MonLCDSlider("Côté carré",2,0,100);
    QPushButton *qpb=new QPushButton("Quitter");

    // agencer les widgets dans un layout
    QVBoxLayout *qvb=new QVBoxLayout();
    qvb->addWidget(mf);
    qvb->addWidget(lcdCote);
    qvb->addWidget(lcdRayon);
    qvb->addWidget(qpb);
    setLayout(qvb);

    // connecter les signaux aux récepteurs
    connect(lcdRayon, SIGNAL(valueChanged(int)), mf, SLOT(rayon_Changed(int)));
    connect(lcdCote, SIGNAL(valueChanged(int)), mf, SLOT(cote_Changed(int)));
    connect(qpb,SIGNAL(clicked()),qApp,SLOT(quit()));
    emit lcdRayon->valueChanged(50);
    emit lcdCote->valueChanged(50);
}

MonWidgetPrincipal::~MonWidgetPrincipal()
{
}

