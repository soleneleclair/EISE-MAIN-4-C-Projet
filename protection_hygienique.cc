#include "protection_hygienique.hh"
#include <iostream>
#include <string>

Protection::Protection():Utilisateur()
{
  std::cout << "Combien de protections hygiéniques (serviettes ou tampon) utilisez vous par jour" << std::endl;
  std::cin >> _nbsprotjour;
}

Protection::Protection(const Utilisateur &u):Utilisateur(u)
{
  std::cout << "Combien de protections hygiéniques (serviettes ou tampon) utilisez vous par jour" << std::endl;
  std::cin >> _nbsprotjour;
}

Protection::Protection(std::string nom, std::string prenom, int recherche):Utilisateur(nom,prenom,recherche)
{
    std::cout << "Combien de protections hygiéniques (serviettes ou tampon) utilisez vous par jour" << std::endl;
    std::cin >> _nbsprotjour;
}


void Protection::print()
{
  std::cout << "Vous utilisez " << _nbsprotjour <<" protections par jour." << std::endl;
}
