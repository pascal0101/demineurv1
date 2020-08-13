#ifndef PLATEAU_H
#define PLATEAU_H

#include <QMainWindow>
#include "case.h"
#include "parametre.h"
#include "plateau.h"

#include <QtGui>
#include <QGridLayout>
#include <QLCDNumber>
#include <ctime>


class Plateau : public QMainWindow
{
    Q_OBJECT

public:
    Plateau(QWidget *parent = nullptr);
    ~Plateau();



    int nbBombesTotal() const;
    int nbBombes(int x, int y) const;
    int nbFlags() const;
    int nbRestant() const;

    bool win() const;

    QString texteHTML(int nombre) const;


public slots:
    void devoiler(int x, int y);
    void reveler(int x = -1, int y = -1);

    void initialiser(int nombre = 0, int x = -1, int y = -1);
    void nouvellePartie();

    void actualliserCompteur();

    void changerParametres();
    //void openSon();

    void informations();

    void gagne();
    void perd(int x = -1, int y = -1);


signals:
    void winner();
    void loser(int x, int y);

private:
    int bombes;
    int hauteur;
    int largeur;

    bool debut;

    QWidget *zoneCentrale;
    QGridLayout *layoutGrille;

    QVector<QVector<Case*> > grille;

    QLCDNumber *compteurReste;
    QPushButton *recommencer;
    QAction *tropFlagsMsg;
};
#endif // PLATEAU_H
