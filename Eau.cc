#include "Eau.hh"
#include <iostream>
#include <string>

Eau::Eau()
{
	std::cout << "Combien buvez vous d'eau par jour ?" << std::endl;
	std::cin >> _litre_j;
  _type = 2;
}

void Eau::print() const
{
	std::cout << "Vous buvez "  << _litre_j <<" litres d'eau par jours";
  std::cout << "\nLe type " << _type << std::endl;
}
