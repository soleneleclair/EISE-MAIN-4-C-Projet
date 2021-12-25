#include "Gourde.hh"
#include <iostream>
#include <string>
float eau_robinet = 0.003;
std::size_t nb_annees = 10;

Gourde::Gourde()
{
  resultat = new float [nb_annees];
  for(std::size_t i = 0; i < nb_annees; i++)
    resultat[i] = 0;
  _prix_achat = 20; //Prix moyen d'une gourde en inox
  _duree_de_vie = 3;
}

void Gourde::calcul(Eau &e)
{

  for(std::size_t i = 0; i < nb_annees; i++)
  {
    if (i%_duree_de_vie == 0) //Il faut renouveler la bouteille
      resultat[i] = e._litre_j*365.25*eau_robinet + _prix_achat + resultat[i];
    else
      resultat[i] = e._litre_j*365.25*eau_robinet + resultat[i];

    std::cout << i << "/* message */" << resultat[i] << std::endl;
  }
}
