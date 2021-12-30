#include <stdio.h>
#include <iostream>
#include <map>

#include "Utilisateur.hh"
#include "Eau.hh"
#include "Gourde.hh"
#include "Bouteille.hh"

int main()
{
  // std::cout << "---------------------------------------------" << std::endl;

  // gourde1.print_resultat();
  // gourde1.calcul(pg);
  // gourde1.print_resultat();
  //
  // Eau eau11("Braunstein","Cécile",2);
  // eau11.presentation();
  // eau11.print_eau();

  // std::cout << "---------------------------------------------" << std::endl;
  //
  // Eau eau12;
  // eau12.presentation();
  // eau12.print_eau();
  //eau12.calcul();


  Utilisateur user("LEclair","Solène",2);
  Eau eau8(user);
  eau8.print();
  Gourde gourde1(eau8);
  gourde1.calcul();

  Bouteille bottle1(eau8);
  std::cout << "---------------------------------------------" << std::endl;
  bottle1.print();

  // if (user.get_recherche() == 2)
  // {
  //   Gourde gourde1(1,"miniral",3,20);
  // }

  Utilisateur user1("Braunstein","Cécile",2);
  Eau eau1(user1,1,"type1");
  Gourde gourde2(eau1);
  gourde2.calcul();
  gourde2.print();
	return 0;
}
