#pragma once
#include <string>
#include <iostream>
#include "utilisateur.hh"

class Eau : public Utilisateur
{
  public :
    Eau();
    void print() const;
  private:
    std::size_t _litre_j;
    std::string _type;
};
