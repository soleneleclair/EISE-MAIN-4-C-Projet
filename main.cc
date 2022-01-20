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
  affichage();

  std::cout << "---------------------------------------------" << std::endl;


	Utilisateur user;
	user.presentation();
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

  std::cout << "---------------------------------------------" << std::endl;


	return 0;
}
