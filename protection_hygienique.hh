#pragma once
#include <string>
#include <iostream>
#include "Utilisateur.hh"


class Protection : public Utilisateur
{
  public :
    std::size_t nb_annees = 10;
    std::size_t nb_cycle = 13;// valeurs utilisése par les trois classes filles pour le calcul des résultats
    std::size_t _nbsprotjour; // nb de protections utilisées par jour

    Protection(); // constructeur par défaut
    Protection(const Utilisateur &u);
    Protection(const Utilisateur &u,std::size_t _nbsprotjour, std::size_t _age):Utilisateur(u),_nbsprotjour(_nbsprotjour){};
    Protection(std::string _nom, std::string _prenom, int _recherche);
    Protection(const Protection &p):Utilisateur(p),_nbsprotjour(p._nbsprotjour),_age(p._age){};

    //Fonction
    virtual void print() const;

    //Getter
    std::size_t get_protec(){return _nbsprotjour;}

    private :
    std::size_t _age;
};
