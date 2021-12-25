#include "gourde.hh"
#include <iostream>
#include <string>

Gourde::Gourde()
{
  int nb_annees = 10;
  resultat = new str::float*[nb_annees];
  _prix_achat = 20;
  _duree_de_vie = 3;
}

void Gourde::calcul()
{
  int nb_annees = 10;
  for(std::size_t i = 0; i < nb_annees; i++)
  {
    if (i%_duree_de_vie)
      resultat[i] = _litre_j*365.25*i*0.003 + _prix_achat;
    else
      resultat[i] = _litre_j*365.25*i*0.003;
  }
}
