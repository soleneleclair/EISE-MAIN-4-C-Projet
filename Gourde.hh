#pragma once
#include <string>
#include <iostream>
#include "Eau.hh"

class Gourde : public Eau
{
  public :
  float * resultat; //variation des dépenses en fonction

  //Constructeur
  Gourde(const Eau &e);

  //Destructeur
  ~Gourde(){delete[] resultat;}

  //Fonctions
  void calcul();
  virtual void print(); //Affichage du prix chaque année

  //Getter
  float get_resultat_annee(int i){return resultat[i];}

  private:
    int _duree_de_vie = 3; //durée de vie moyenne d'une gourde en inox
    float _prix_achat = 20; //Prix moyen d'une gourde en inox
};
