#include "parametre.h"
#include <QWidget>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QLabel>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QMessageBox>
#include <QGroupBox>
#include <QPushButton>



Parametre::Parametre(QWidget *parent, int *bhauteur, int *blargeur, int *bbombes, bool *bchangement) : QDialog(parent), hauteur(bhauteur), largeur(blargeur), bombes(bbombes), changement(bchangement)
{
    QVBoxLayout *layoutPrincipale = new QVBoxLayout(this);

        QGroupBox *dimensions = new QGroupBox("Dimensions de la grille");
        dimensions->setToolTip("Entrez les dimmensions que vous voulez appliquer a votre map");
        QGridLayout *layoutDimensions = new QGridLayout;
        dimensions->setLayout(layoutDimensions);

            QLabel *texteHauteur = new QLabel("Entrez le nombre de cases dans la hauteur");
            layoutDimensions->addWidget(texteHauteur, 0, 0);

            champHauteur = new QSpinBox;
            champHauteur->setMinimum(5);
            champHauteur->setValue(*hauteur);
            layoutDimensions->addWidget(champHauteur, 0, 1);


            QLabel *texteLargeur = new QLabel("Entrez le nombre de cases dans la largeur");
            layoutDimensions->addWidget(texteLargeur, 1, 0);

            champLargeur = new QSpinBox;
            champLargeur->setMinimum(5);
            champLargeur->setValue(*largeur);
            layoutDimensions->addWidget(champLargeur, 1, 1);

        layoutPrincipale->addWidget(dimensions);


        QHBoxLayout *layoutBombes = new QHBoxLayout;

            QLabel *texteBombes = new QLabel("Entrez le nombre de bombes a deminer");
            layoutBombes->addWidget(texteBombes);

            champBombes = new QSpinBox;
            champBombes->setToolTip("Entrez le nombre de bombes qui serons cree au debut de la partie");
            actualiserChampBombes();
            champBombes->setValue(*bombes);
            connect(champHauteur, SIGNAL(valueChanged(int)), this, SLOT(actualiserChampBombes()));
            connect(champLargeur, SIGNAL(valueChanged(int)), this, SLOT(actualiserChampBombes()));
            layoutBombes->addWidget(champBombes);

        layoutPrincipale->addLayout(layoutBombes);


        QPushButton *bouttonOk = new QPushButton("&Valider");
        bouttonOk->setToolTip("Valider les choix et fermer cette fenetre");
        layoutPrincipale->addWidget(bouttonOk);
        connect(bouttonOk, SIGNAL(pressed()), this, SLOT(valider()));
        connect(bouttonOk, SIGNAL(pressed()), this, SLOT(close()));


    setWindowTitle("Parametre de partie");

}

void Parametre::valider(){

    *hauteur = champHauteur->value();
    *largeur = champLargeur->value();
    *bombes = champBombes->value();
    *changement = true;
}

void Parametre::actualiserChampBombes(){
    champBombes->setMinimum(((champLargeur->value()*champHauteur->value()))/20);
    champBombes->setMaximum(((champLargeur->value()*champHauteur->value()))/2);
}
