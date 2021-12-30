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
  for(std::size_t i = 0; i < nb_annees; i++) //variation dans les années (0 = la premiere année d'utilisation)
  {
    resultat[i] = _litre_j*365.25*eau_robinet; // prix de l'eau du robinet pour une année
    if (i != 0)
      resultat[i] = resultat[i] + resultat[i-1]; // On additionne avec l'année précédente

    if (i%_duree_de_vie == 0) //Il faut renouveler la bouteille
      resultat[i] = _prix_achat + resultat[i]; // on ajoute au prix de l'eau à l'année le prix d'achat d'une bouteille
  }
}

void Gourde::print(){
  for(std::size_t i = 0; i < nb_annees; i++)
    std::cout << "L'année " << i << "il a dépensé : " << resultat[i] << " € \n";
}
