#pragma once
#include <string>
#include <iostream>
#include "utilisateur.hh"
class Protection : public Utilisateur
{
  public :
    protection();
    void print() const;
  private:
    int _flux; //de 0 à 5
    int _age;
    int _nbservjour;
};
