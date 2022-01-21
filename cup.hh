#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "protection_hygienique.hh"
class Cup : public Protection
{
  public :
    //declaration des vecteurs qui contiennent les resultats
    std::vector<float> res_an = std::vector<float> (nb_annees);
    std::vector<float> res_cycle = std::vector<float> (nb_cycle);

    //Constructeur
    Cup(const Protection &p);
    Cup(const Cup &c): Protection(c),_duree(c._duree), _prixuni(c._prixuni), _prixan(c._prixan), _prixcycle(c._prixcycle), res_an(c.res_an),res_cycle(c.res_cycle){};


    //Fonction
    void calcul_prix();
    virtual   void print();

    //Getter
    float get_resultat_an(int i){return res_an[i];} // retourne le vecteru contenant les resulats sur 10ans

private:

    int _duree = 10 ; // duree en année -- une cup dure 10 ans
    int _prixuni = 20; // prix par cup
    float _prixan = _prixuni/_duree;
    float _prixcycle = _prixan/nb_cycle;

};
