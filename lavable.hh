#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "protection_hygienique.hh"
class Lavable : public Protection
{
  public :
  // déclaration des vecteurs résultats
    std::vector<float> res_an = std::vector<float> (nb_annees);
    std::vector<float> res_cycle = std::vector<float> (nb_cycle);

    //Constructeur
    Lavable(const Protection &p);

    //Fonction
    void calcul_prix();
    virtual void print();

    //Getter
    float get_resultat_an(int i){return res_an[i];}

private:

    int _duree = 5 ; // duree de vie moyenne d'une serviette lavable en année
    int _prixuni = 70; //prix moyen pour 7 serviettes lavables 5minimum requis pour un cycle)
    float _prixan = _prixuni/_duree;
    float _prixcycle = _prixan/nb_cycle;// si on estime qu'un cycle dure 5 jours
};
