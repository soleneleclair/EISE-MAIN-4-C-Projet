#include "Bouteille.hh"
#include <iostream>
#include <string>
float eau_minerale = 0.4;
float eau_source = 0.2;

Bouteille::Bouteille(const Eau &e):Eau(e)
{
  resultat_mineral = new float [nb_annees];
  resultat_source = new float [nb_annees];
  for(std::size_t i = 0; i < nb_annees; i++)
  {
    resultat_mineral[i] = 0;
    resultat_source[i] = 0;
  }
}

void Bouteille::calcul()
{
  std::cout << "litre : " << _litre_j  << '\n';
  for(std::size_t i = 0; i < nb_annees; i++)
  {
    resultat_source[i] = _litre_j*365.25*eau_source;
    resultat_mineral[i] = _litre_j*365.25*eau_minerale;
    if (i != 0){
      resultat_mineral[i] += resultat_mineral[i-1];
      resultat_source[i] += resultat_source[i-1];
    }
  }
}

void Bouteille::print_resultat(){
  std::cout << "\t \t Résultat minéral : " << '\n';
  for(std::size_t i = 0; i < nb_annees; i++)
    std::cout << "L'année " << i << ", il a dépensé : " << resultat_mineral[i] << '\n';
  std::cout << "\t \t Résultat source : " << '\n';
  for(std::size_t i = 0; i < nb_annees; i++)
    std::cout << "L'année " << i << ", il a dépensé : " << resultat_source[i] << '\n';
}
