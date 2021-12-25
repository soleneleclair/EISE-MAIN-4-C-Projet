#pragma once
#include <string>
#include <iostream>
#include "protection_hygienique.hh"
class Lavable : public Protection
{
  public :
    Lavable();
    void print() const;
  private:
    int _prixuni;
    //int _qtecycle; _nbservjour
    std::string _qtetemps;
    double _prixcycle;
    double _prixan;
};
