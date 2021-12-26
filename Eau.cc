#include "Eau.hh"
#include <iostream>
#include <string>

Eau::Eau():Utilisateur()
{
	std::cout << "Combien buvez vous d'eau par jour ?" << std::endl;
	std::cin >> _litre_j;
	_type = "type2";
}

Eau::Eau(const Utilisateur &u):Utilisateur(u)
{
	std::cout << "Combien buvez vous d'eau par jour ?" << std::endl;
	std::cin >> _litre_j;
	_type = "type2";
}

Eau::Eau(std::string nom, std::string prenom, int recherche):Utilisateur(nom,prenom,recherche)
{
	std::cout << "Combien buvez vous d'eau par jour ?" << std::endl;
	std::cin >> _litre_j;
	_type = "type2";
}

void Eau::print_eau() const
{
	std::cout << "Vous buvez "  << _litre_j <<" litres d'eau par jours";
  std::cout << "\nLe type " << _type << std::endl;
}

// void Eau::fill() const
// {
// 	std::cout << "Combien buvez vous d'eau par jour ?" << std::endl;
// 	std::cin >> _litre_j;
// }
