#pragma once
#include <string>
#include <iostream>
#include "protection_hygienique.hh"
class Lavable : public Protection
{
  public :
    //Constructeur
    Lavable(const Protection &p);
    //Cup(const Cup &c): Protection(c),_duree(c._duree), _prixuni(c._prixuni), _prixan(c._prixan), _prixcycle(c._prixcycle), res(c.res){};
    
    //Destructeur
    ~Lavable(){
        delete[] res_an;
        delete[] res_cycle;
    }
    
    //Fonction
    void calcul_prix();
    void print() const;
  
    //Getter
    float get_resultat_an(int i){return res_an[i];}

private:
    
    //int _qtecycle; techniquement deja dans protection
    int _duree = 5 ; // duree en année
    int _prixuni = 60; //prix moyen pour 6 serviette lavable
    float _prixan = _prixuni/_duree;
    float _prixcycle = _prixan/nb_cycle;// si on estime qu'un cycle dure 5 jours
    
    float * res_an;
    float * res_cycle;
};
