#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "protection_hygienique.hh"

class Jetable : public Protection
{
  public :
  // déclaration des vecteurs résultats
    std::vector<float> res_an = std::vector<float> (nb_annees);
    std::vector<float> res_cycle = std::vector<float> (nb_cycle);

    //Constructeur
    Jetable(const Protection &p);

    //Fonction
    void calcul_prix();
    virtual void print();

    //Getter
    float get_resultat_an(int i){return res_an[i];}

private:

    float _prixuni = 0.25; //prix moyen d'une serviette hygienique
    int _nb_jour_cycle = 5; // le cycle moyen dure 5 jours
    float _prixcycle = (_prixuni*_nbsprotjour)*_nb_jour_cycle;// si on estime qu'un cycle dure 5 jours
    float _prixan = _prixcycle * nb_cycle;

};
