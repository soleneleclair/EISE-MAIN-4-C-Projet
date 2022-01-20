#include "Bouteille.hh"
#include <iostream>
#include <string>
float eau_minerale = 0.4;
float eau_source = 0.2;
float CO2_bouteille = 0.393;//0,393 Kg CO2/l de liquide

Bouteille::Bouteille(const Eau &e):Eau(e) //Initialisation des variables du dictionnaire à zéro.
{
  //Création et initialisation des 3 cases du dictionnaire
  resultat["mineral"] = new float [nb_annees];
  resultat["source"] = new float [nb_annees];
  resultat["CO2"] = new float [nb_annees];
  for(std::size_t i = 0; i < nb_annees; i++)
  {
    resultat["mineral"][i] = 0;
    resultat["source"][i] = 0;
    resultat["CO2"][i] = 0;
  }
}

Bouteille::~Bouteille()
{
  delete [] resultat["source"];
  delete [] resultat["mineral"];
  delete [] resultat["CO2"];
}

void Bouteille::calcul_prix() //Fonction qui calcul l'argent dépensé en utilisant des bouteilles à usage unique
{
  for(std::size_t i = 0; i < nb_annees; i++) //variation dans les années (0 = la premiere année d'utilisation)
  {
    resultat["source"][i] = get_litre()*365.25*eau_source; //calcul du prix des bouteilles d'eau de source pour une année en fonction des litres d'eau bu par l'utilisateur
    resultat["mineral"][i] = get_litre()*365.25*eau_minerale;
    if (i != 0){
      resultat["source"][i] += resultat["source"][i-1];//On additionne avec le précedent pour avoir le prix en fonction des années
      resultat["mineral"][i] += resultat["mineral"][i-1];
    }
  }
}

void Bouteille::conso_CO2()
{
  for(std::size_t i = 0; i < nb_annees; i++) // on varie par années
  {
    resultat["CO2"][i] = get_litre()*365.25*CO2_bouteille; //Calcul de la consommation de CO2 d'une bouteille en plastique
    if (i != 0)
      resultat["CO2"][i] = resultat["CO2"][i] + resultat["CO2"][i-1]; //conso en fonction des années
  }
}

//Affichage
void Bouteille::print() {
  conso_CO2();
  calcul_prix();
  std::cout << "\t \t Résultat minéral : " << '\n';
  for(std::size_t i = 0; i < nb_annees; i++)
    std::cout << "L'année " << i << ", il a dépensé : " << resultat["mineral"][i] << " €\n";
  std::cout << "\t \t Résultat source : " << '\n';
  for(std::size_t i = 0; i < nb_annees; i++)
    std::cout << "L'année " << i << ", il a dépensé : " << resultat["source"][i] << " €\n";
  std::cout << "\t \t Une bouteille plastique consomme comme C02 : " << '\n';
  for(std::size_t i = 0; i < nb_annees; i++)
    std::cout << "L'année " << i << " : " << resultat["CO2"][i] << " kg\n";
}
