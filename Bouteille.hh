#pragma once
#include <string>
#include <iostream>
#include <map>
#include "Eau.hh"

class Bouteille : public Eau
{
  public :
    //Constructeurs
    Bouteille(const Eau &e);
    Bouteille(const Bouteille &g):Eau(g),resultat(g.resultat){};
    ~Bouteille();// Destructeur

    //Getter
    float get_resultat_annee(int i, std::string type){return resultat[type][i];}

    //Fonctions
    void calcul_prix();//Fonction qui calcul l'argent dépensé en utilisant des bouteilles à usage unique
    void conso_CO2();
    virtual void print(); //Affichage


    std::map<std::string, float* > resultat;
    //dictionnaire représentant les variation des dépenses d'eau minéral, d'eau de source et la conso de CO2 au cours des années
};
