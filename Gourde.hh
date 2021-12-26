#pragma once
#include <string>
#include <iostream>
#include "Eau.hh"

class Gourde : public Eau
{
  public :
    //Gourde();
    Gourde(const Gourde &g):Eau(g),_duree_de_vie(g._duree_de_vie),_prix_achat(g._prix_achat),resultat(g.resultat){};
    //Gourde(std::size_t litre_j,std::string type,int duree_de_vie,float prix_achat);
    void calcul(Eau &e);
    void print_resultat();

  private:
    int _duree_de_vie;
    float _prix_achat;
    float * resultat; //variation des dépenses en fonction
};
