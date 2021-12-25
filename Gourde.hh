#pragma once
#include <string>
#include <iostream>
#include "Eau.hh"

class Gourde : public Eau
{
  public :
    Gourde();
    void calcul(Eau &e);

  private:
    int _duree_de_vie;
    float _prix_achat;
    float * resultat; //variation des dépenses en fonction
};
