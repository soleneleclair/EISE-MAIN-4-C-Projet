#include "Eau.hh"
#include <iostream>
#include <string>

Eau::Eau():Utilisateur()
{
	std::cout << "Combien buvez vous de litres d'eau par jour ?" << std::endl;
	std::cin >> _litre_j;
}

Eau::Eau(const Utilisateur &u):Utilisateur(u)
{
	std::cout << "Combien buvez vous de litres d'eau par jour ?" << std::endl;
	std::cin >> _litre_j;
}

Eau::Eau(std::string nom, std::string prenom, int recherche):Utilisateur(nom,prenom,recherche)
{
	std::cout << "Combien buvez vous de litres d'eau par jour ?" << std::endl;
	std::cin >> _litre_j;
}

void Eau::print() const
{
	std::cout << "Vous buvez "  << _litre_j <<" litres d'eau par jours";
}

// void Eau::fill() const
// {
// 	std::cout << "Combien buvez vous d'eau par jour ?" << std::endl;
// 	std::cin >> _litre_j;
// }
