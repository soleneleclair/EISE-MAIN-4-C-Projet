#include <stdio.h>
#include <iostream>
#include "Utilisateur.hh"
#include "Eau.hh"
#include "Gourde.hh"

int main()
{
  // pg.print();

  //std::cout << test1.get_recherche() << std::endl;
  // Utilisateur user1("Braunstein","Cécile",2);
  // Utilisateur user2(user1);
  //
  // std::cout << user1.get_recherche() << std::endl;

  // Gourde gourde1(1,"miniral",3,20);
  // gourde1.presentation();
  std::cout << "---------------------------------------------" << std::endl;
  Eau eau1("Braunstein","Cécile",2,0,"minéral");
  Eau eau2(eau1);
  eau1.print_eau();
  eau1.presentation();
  eau2.print_eau();
  std::cout << "---------------------------------------------" << std::endl;
  //

  // gourde1.print_resultat();
  // gourde1.calcul(pg);
  // gourde1.print_resultat();

  Eau eau11("Braunstein","Cécile",2);
  eau11.presentation();
  eau11.print_eau();

  // std::cout << "---------------------------------------------" << std::endl;
  //
  // Eau eau12;
  // eau12.presentation();
  // eau12.print_eau();
  //eau12.calcul();

  std::cout << "---------------------------------------------" << std::endl;

  Utilisateur user;
  Eau eau8(user);
  // if (user.get_recherche() == 2)
  // {
  //   Gourde gourde1(1,"miniral",3,20);
  // }
	return 0;
}
