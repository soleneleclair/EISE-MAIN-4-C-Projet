#include "eau.hh"
#include <iostream>
#include <string>

eau::eau()
{
	std::cout << "Combien buvez vous d'eau par jour ?" << std::endl;
	std::cin >> _litre_j;
  std::cout << "De quel type ?" << std::endl;
	std::cin >> _type;
}

void eau::print() const
{
	std::cout << "Vous buvez "  << _litre_j <<" litres d'eau par jours";
  std::cout << ", du type " << _type << std::endl;
}
