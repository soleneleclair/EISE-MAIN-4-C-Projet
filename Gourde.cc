#include "Gourde.hh"
#include <iostream>
#include <string>
float eau_robinet = 0.003;

// Gourde::Gourde():Eau()
// {
//   resultat = new float [nb_annees];
//   for(std::size_t i = 0; i < nb_annees; i++)
//     resultat[i] = 0;
//   _prix_achat = 20; //Prix moyen d'une gourde en inox
//   _duree_de_vie = 3;
// }

// Gourde::Gourde(std::size_t litre_j,std::string type,int duree_de_vie,float prix_achat):Eau(litre_j,type),_duree_de_vie(duree_de_vie),_prix_achat(prix_achat)
// {
//   resultat = new float [nb_annees];
//   for(std::size_t i = 0; i < nb_annees; i++)
//      resultat[i] = 0;
// }

Gourde::Gourde(const Eau &e):Eau(e)
{
  resultat = new float [nb_annees];
  for(std::size_t i = 0; i < nb_annees; i++)
     resultat[i] = 0;

}


void Gourde::calcul()
{
  std::cout << "litre : " << _litre_j  << '\n';
  for(std::size_t i = 0; i < nb_annees; i++)
  {
    resultat[i] = _litre_j*365.25*eau_robinet;
    if (i != 0)
      resultat[i] = resultat[i] + resultat[i-1];

    if (i%_duree_de_vie == 0) //Il faut renouveler la bouteille
      resultat[i] = _prix_achat + resultat[i];

    std::cout << "année : " << i << " --> "<<resultat[i] << std::endl;
  }
}

void Gourde::print_resultat(){
  for(std::size_t i = 0; i < nb_annees; i++)
    std::cout << "L'année " << i << "il a dépensé : " << resultat[i] << '\n';
}
