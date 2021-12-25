#pragma once
#include <string>
#include <iostream>
#include "protection_hygienique.hh"
class Cup : public Protection
{
  public :
    Cup();
    void print() const;
  private:
    int _prixuni;
    //int _qtecycle; techniquement deja dans protection
    double _qtetemps;
    double _prixcycle;
    double _prixan;
};
