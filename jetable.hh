#pragma once
#include <string>
#include <iostream>
#include "protection_hygienique.hh"
class Jetable : public Protection
{
  public :
    Jetable();
    void print() const;
  private:
    int _prixuni;
    //int _qtecycle; deja dans protection
    double _qtetemps;
    double _prixcycle;
    double _prixan;
};
