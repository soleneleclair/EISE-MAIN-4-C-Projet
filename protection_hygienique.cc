#include "protection_hygienique.hh"
#include <iostream>
#include <string>

Protection::Protection():Utilisateur()
{
  std::cout << "Quel est votre age" << std::endl;
  std::cin >> _age;
	std::cout << "Notez votre flux de 0 à 5 (0 = très léger ; 5 = très abondant)" << std::endl;
	std::cin >> _flux;
  std::cout << "Combien de protections hygiéniques (serviettes ou tampon) utilisez vous par jour" << std::endl;
  std::cin >> _nbsprotjour;
}

Protection::Protection(const Utilisateur &u):Utilisateur(u)
{
  std::cout << "Quel est votre age" << std::endl;
  std::cin >> _age;
    std::cout << "Notez votre flux de 0 à 5 (0 = très léger ; 5 = très abondant)" << std::endl;
    std::cin >> _flux;
  std::cout << "Combien de protections hygiéniques (serviettes ou tampon) utilisez vous par jour" << std::endl;
  std::cin >> _nbsprotjour;
}

Protection::Protection(std::string nom, std::string prenom, int recherche):Utilisateur(nom,prenom,recherche)
{
  std::cout << "Quel est votre age" << std::endl;
  std::cin >> _age;
    std::cout << "Notez votre flux de 0 à 5 (0 = très léger ; 5 = très abondant)" << std::endl;
    std::cin >> _flux;
    std::cout << "Combien de protections hygiéniques (serviettes ou tampon) utilisez vous par jour" << std::endl;
    std::cin >> _nbsprotjour;
}


void Protection::print_protec() const
{
    std::cout << "Vous avez "  << _age <<" ans.";
  std::cout << "\nEt vous utilisez " << _nbsprotjour <<" protections par jour." << std::endl;
}
