// Let Catch provide main():
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Utilisateur.hh"
#include "Eau.hh"
#include "Gourde.hh"
#include "Bouteille.hh"

#include <iostream>
#include <fstream>
#include <sstream>

TEST_CASE("1: Utilisateur")
{
  Utilisateur user1("Braunstein","Cécile",2);
  Utilisateur user2(user1);
  REQUIRE(user1.get_nom() == "Braunstein");
  REQUIRE(user1.get_prenom() == user2.get_prenom());
  REQUIRE(user2.get_recherche() == 2);
}

TEST_CASE("2: Eau")
{
  Utilisateur user1("Braunstein","Cécile",2);
  Eau eau1(user1,1,"type1");
  Eau eau2(eau1);
  Eau eau3("Braunstein","Cécile",2,1,"type1");
  REQUIRE(eau1.get_nom() == eau3.get_nom());
  REQUIRE(eau1.get_prenom() == eau3.get_prenom());
}

TEST_CASE("3: Gourde")
{
  
}
