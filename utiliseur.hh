#pragma once
#include <string>
#include <iostream>
#include "protection_hygienique.hh"

class Utilisateur:{
  Utilisateur();

private:
  std::string _nom;
  std::string _prenom;
  int _recherche;
};
