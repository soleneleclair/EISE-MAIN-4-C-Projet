#pragma once
#include <string>
#include <iostream>
#include "Eau.hh"

class Gourde : public Eau
{
  public :
    Gourde(const Eau &e);
    Gourde(const Gourde &g):Eau(g),_duree_de_vie(g._duree_de_vie),_prix_achat(g._prix_achat),resultat(g.resultat){};
    //Gourde(std::size_t litre_j,std::string type,int duree_de_vie,float prix_achat);

    ~Gourde(){delete[] resultat;} // Destructeur

    void calcul();
    void print(); //Affichage du prix chaque année

    //Getter
    float get_resultat_annee(int i){return resultat[i];}

  private:
    int _duree_de_vie = 3; //durée de vie moyenne d'une gourde en inox
    float _prix_achat = 20; //Prix moyen d'une gourde en inox
    float * resultat; //variation des dépenses en fonction
};
