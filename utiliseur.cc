#pragma once
#include "utilisateur.hh"
#include <string>
#include <iostream>

utilisateur::utilisateur()
{
	std::cout << "Nom ?" << std::endl;
	std::cin >> _nom;
  std::cout << "Prénom ?" << std::endl;
	std::cin >> _prenom;
  std::cout << "Type 1 : projection hygiénique Type 2 : gourde" << std::endl;
  std::cin >> _type;
}
