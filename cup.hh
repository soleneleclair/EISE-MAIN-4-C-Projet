#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "protection_hygienique.hh"
class Cup : public Protection
{
  public :
    //Constructeur
    Cup(const Protection &p);
    //Cup(const Cup &c): Protection(c),_duree(c._duree), _prixuni(c._prixuni), _prixan(c._prixan), _prixcycle(c._prixcycle), res(c.res){};
    
    //Destructeur
    /*~Cup(){
        delete[] res_an;
        delete[] res_cycle;
    }*/
    
    //Fonction
    void calcul_prix();
    void print() const;
  
    //Getter
    float get_resultat_an(int i){return res_an[i];}

private:
    
    //int _qtecycle; techniquement deja dans protection
    int _duree = 10 ; // duree en année
    int _prixuni = 20; //prix par cup
    float _prixan = _prixuni/_duree;
    float _prixcycle = _prixan/nb_cycle;
    std::vector<float> res_an = std::vector<float> (nb_annees);
    std::vector<float> res_cycle = std::vector<float> (nb_cycle);
//    float * res_an;
//    float * res_cycle;
};
