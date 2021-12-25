#pragma once
#include <string>
#include <iostream>
#include "eau.hh"

class Gourde : public Eau
{
  public :
    Gourde();

  private:
    int _duree_de_vie;
    std::float _prix_achat;
    std::float * resultat;
    void calcul();
};
