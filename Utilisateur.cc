 #include "Utilisateur.hh"
#include <string>
#include <iostream>


Utilisateur::Utilisateur() // constructeur
{
	std::cout << "Nom ?" << std::endl;
	std::cin >> _nom;
  std::cout << "Prénom ?" << std::endl;
	std::cin >> _prenom;
  //std::cout << "Type 1 : projection hygiénique, Type 2 : gourde" << std::endl;
  //std::cin >> _recherche;
}

void Utilisateur::presentation() // on affiche la personne défini par utilisateur
{
	std::cout << "\n \t \t Voici la personne étudiée : " << '\n';
	std::cout << "Nom : " << _nom << std::endl;
  std::cout << "Prénom : " << _prenom << std::endl;
	if (_recherche == 1)
		std::cout << "La recherche porte sur les protections hygiéniques. " << _recherche << std::endl << std::endl;
	else
		std::cout << "La recherche porte sur les gourdes. " << std::endl << std::endl;

}
