 #include "Utilisateur.hh"
#include <string>
#include <iostream>


Utilisateur::Utilisateur()
{
	std::cout << "Nom ?" << std::endl;
	std::cin >> _nom;
  std::cout << "Prénom ?" << std::endl;
	std::cin >> _prenom;
  std::cout << "Type 1 : projection hygiénique, Type 2 : gourde" << std::endl;
  std::cin >> _recherche;
}

void Utilisateur::presentation()
{
	std::cout << "\t \t Voici la personne étudiée : " << '\n';
	std::cout << "Nom : " << _nom << std::endl;
  std::cout << "Prénom : " << _prenom << std::endl;
	std::cout << "La recherche est de type : " << _recherche << std::endl;
}
