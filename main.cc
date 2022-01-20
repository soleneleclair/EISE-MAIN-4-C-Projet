#include <stdio.h>
#include <iostream>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Utilisateur.hh"
#include "Eau.hh"
#include "Gourde.hh"
#include "Bouteille.hh"
#include "protection_hygienique.hh"
#include "lavable.hh"
#include "cup.hh"
#include "jetable.hh"


int main()
{

  Utilisateur user;
  user.presentation();
  std::cout << "---------------------------------------------" << std::endl;

  affichage();
	if (user.get_recherche()==2)
	{
		Eau water(user);
		Gourde gourde(water);
		gourde.print();
		std::cout << "---------------------------------------------" << std::endl;
		Bouteille bottle(water);
		bottle.print();
		//~water();
	}
  else
  {
    Protection protec(user);
    Lavable lav1(protec);
    lav1.calcul_prix();
    lav1.print();
    Cup cup1(protec);
    cup1.calcul_prix();
    cup1.print();

  }  std::cout << "---------------------------------------------" << std::endl;
    //protec.print_protec();

	return 0;
}
