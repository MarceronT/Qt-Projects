#include "monlcdslider.h"
#include <QSlider>
#include <QLCDNumber>
#include <QHBoxLayout>
#include <QApplication>
#include <QLabel>


MonLCDSlider::MonLCDSlider(QString label, uint nbLcd, int min, int max, int valDep, QWidget *parent) : QWidget(parent)
{
    QLabel *ql=new QLabel(label);
    QSlider *qs=new QSlider(Qt::Horizontal);
    qs->setRange(min,max);
    if(valDep==-1)
        valDep=(min+max)/2;
    qs->setValue(valDep);
    QLCDNumber *qlcd=new QLCDNumber(3);
    // layout
    QHBoxLayout *qhbox=new QHBoxLayout;
    qhbox->addWidget(ql);
    qhbox->addWidget(qs);
    qhbox->addWidget(qlcd);
    setLayout(qhbox);
    // Connecter le signal du QSlider -> Slot du QLCD
    connect(qs, SIGNAL(valueChanged(int)), qlcd, SLOT(display(int)));
    // synchronisation du curseur avec l'afficheur au démarrage
    emit qs->valueChanged(valDep);
    // Connecter le signal du QSlider comme signal général
    connect(qs, SIGNAL(valueChanged(int)),this,SIGNAL(valueChanged(int)));
}
