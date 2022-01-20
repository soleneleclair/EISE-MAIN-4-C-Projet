#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "protection_hygienique.hh"

class Jetable : public Protection
{
  public :
    //Constructeur
    Jetable(const Protection &p);
    //Cup(const Cup &c): Protection(c),_duree(c._duree), _prixuni(c._prixuni), _prixan(c._prixan), _prixcycle(c._prixcycle), res(c.res){};

    //Destructeur
    /*~Jetable(){
        delete[] res_an;
        delete[] res_cycle;
    }*/

    //Fonction
    void calcul_prix();
    virtual void print() const;

    //Getter
    float get_resultat_an(int i){return res_an[i];}

private:

    //int _qtecycle; techniquement deja dans protection
    //float _duree = 24/_nbsprotjour ; // duree en heure
    float _prixuni = 0.25; //prix moyen d'une serviette hygienique
    float _prixcycle = (_prixuni*_nbsprotjour)*5;// si on estime qu'un cycle dure 5 jours
    float _prixan = _prixcycle * nb_cycle;
    std::vector<float> res_an = std::vector<float> (nb_annees);
    std::vector<float> res_cycle = std::vector<float> (nb_cycle);
    //float * res_an;
    //float * res_cycle;
};
