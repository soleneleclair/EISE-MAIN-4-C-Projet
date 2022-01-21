#pragma once
#include <string>
#include <iostream>
#include "Utilisateur.hh"


class Protection : public Utilisateur
{
  public :

  // valeurs utilisées par les trois classes filles pour le calcul des résultats
    std::size_t nb_annees = 10; // on étudie nos résultats sur 10 ans
    std::size_t nb_cycle = 13;// 1 femme a en moyenne 13 cycles/an
    std::size_t _nbsprotjour; // nb de protections utilisées par jour

    // Constructeurs
    Protection();
    Protection(const Utilisateur &u);
    Protection(const Utilisateur &u,std::size_t _nbsprotjour, std::size_t _age):Utilisateur(u),_nbsprotjour(_nbsprotjour){};
    Protection(std::string _nom, std::string _prenom, int _recherche);
    Protection(const Protection &p):Utilisateur(p),_nbsprotjour(p._nbsprotjour){};

    //Fonction
    virtual void print();

    //Getter
    std::size_t get_protec(){return _nbsprotjour;}

};
