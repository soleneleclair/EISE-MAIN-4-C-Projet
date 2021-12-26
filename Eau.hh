#pragma once
#include <string>
#include <iostream>
#include "Utilisateur.hh"

class Eau : public Utilisateur
{
  public :
    std::size_t _litre_j;
    Eau();
    Eau(const Utilisateur &u);
    Eau(const Utilisateur &u, std::size_t litre_j,std::string type):Utilisateur(u),_litre_j(litre_j),_type(type){};
    Eau(std::string nom, std::string prenom, int recherche);
    Eau(std::string nom, std::string prenom, int recherche,std::size_t litre_j,std::string type):Utilisateur(nom,prenom,recherche),_litre_j(litre_j),_type(type){};
    Eau(const Eau &e):Utilisateur(e),_litre_j(e._litre_j),_type(e._type){};

    void print_eau() const;
    //void fill() const;

  private:
    std::string _type;
};
