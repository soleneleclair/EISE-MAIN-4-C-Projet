#include "protection_hygienique.hh"
#include <iostream>
#include <string>

Protection::Protection()
{
  std::cout << "Quel est votre age" << std::endl;
  std::cin >> _age;
	std::cout << "Notez votre flux de 0 à 5 (0 = très léger ; 5 = très abondant)" << std::endl;
	std::cin >> _flux;
  std::cout << "Combien de serviettes hygiéniques utilisez vous par jour" << std::endl;
  std::cin >> _nbservjour;
}
