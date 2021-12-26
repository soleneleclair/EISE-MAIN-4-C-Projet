#pragma once
#include <string>
#include <iostream>
#include "Eau.hh"

class Bouteille : public Eau
{
  public :
    Bouteille(const Eau &e);
    //Bouteille(const Gourde &g):Eau(g),_duree_de_vie(g._duree_de_vie),_prix_achat(g._prix_achat),resultat(g.resultat){};
    //Gourde(std::size_t litre_j,std::string type,int duree_de_vie,float prix_achat);
    void calcul();
    void print_resultat();

  private:
    float * resultat_mineral; //variation des dépenses d'eau de minéral en fonction
    float * resultat_source; //variation des dépenses d'eau de source en fonction
};
