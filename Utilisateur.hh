#pragma once
#include <string>
#include <iostream>

class Utilisateur{
public:
  Utilisateur();
  Utilisateur(std::string nom,  std::string prenom, int recherche):_nom(nom),_prenom(prenom),_recherche(recherche){};
  Utilisateur(const Utilisateur &u):_nom(u._nom),_prenom(u._prenom),_recherche(u._recherche){};
  int get_recherche() const {return _recherche;}
  
private:
  std::string _nom;
  std::string _prenom;
  int _recherche;
};