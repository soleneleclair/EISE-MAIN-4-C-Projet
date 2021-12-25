#pragma once
#include <string>
#include <iostream>
#include "Utilisateur.hh"

class Eau : public Utilisateur
{
  public :
    std::size_t _litre_j;

    Eau();
    Eau(std::size_t litre_j,std::string type):_litre_j(litre_j),_type(type){};
    Eau(const Eau &e):_litre_j(e._litre_j),_type(e._type){};
    
    void print() const;
  private:
    std::string _type;
};
