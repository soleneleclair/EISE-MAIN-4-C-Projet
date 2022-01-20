// Let Catch provide main():
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Utilisateur.hh"
#include "Eau.hh"
#include "Gourde.hh"
#include "Bouteille.hh"
#include "protection_hygienique.hh"
#include "jetable.hh"
#include "lavable.hh"
#include "cup.hh"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

TEST_CASE("1:Utilisateur")
{
  Utilisateur user1("Braunstein","Cécile",2);
  Utilisateur user2(user1);
  REQUIRE(user1.get_nom() == "Braunstein");
  REQUIRE(user1.get_prenom() == user2.get_prenom());
  REQUIRE(user2.get_recherche() == 2);
}

TEST_CASE("2:Eau")
{
  Utilisateur user1("Braunstein","Cécile",2);
  Eau eau1(user1,1,"type1");
  Eau eau2(eau1);
  Eau eau3("Braunstein","Cécile",2,1);
  REQUIRE(eau1.get_nom() == "Braunstein");
  REQUIRE(eau2.get_litre() == eau3.get_litre());
  REQUIRE(eau3.get_litre() == 1);
}

TEST_CASE("3:Gourde")
{
  Eau eau("Braunstein","Cécile",2,1);
  Gourde Gourde1(eau);
  REQUIRE(Gourde1.get_resultat_annee(1) == 0);
  REQUIRE(Gourde1.get_nom() == "Braunstein");
}

TEST_CASE("4:Bouteille")
{
  Eau eau("Braunstein","Cécile",2,1);
  Bouteille Bottle(eau);
  REQUIRE(Bottle.get_resultat_annee(0,"CO2") == 0);
  REQUIRE(Bottle.get_litre()==1);
  Bottle.conso_CO2();
  REQUIRE(Bottle.get_resultat_annee(1,"CO2") == float(287.08652));
}

TEST_CASE("5:Protection")
{
    Utilisateur user1("Braunstein","Cécile",1);
    Protection protec1(user1,3,21);
    Protection protec2(protec1);
    REQUIRE(protec1.get_nom() == "Braunstein");

    REQUIRE(protec1.get_nom() == protec2.get_nom());
    REQUIRE(protec1.get_prenom() == protec2.get_prenom());
    REQUIRE(protec1.get_protec() == 3);
}

TEST_CASE("6:Jetable")
{
    Utilisateur user1("Braunstein","Cécile",1);
    Protection protec1(user1,3,21);
    Jetable jet1(protec1);

    REQUIRE(jet1.get_nom() == protec1.get_nom());
    REQUIRE(jet1.get_prenom() == protec1.get_prenom());

}
TEST_CASE("7: Lavable")
{
    Utilisateur user1("Braunstein","Cécile",1);
    Protection protec1(user1,3,21);
    Lavable lav1(protec1);

    REQUIRE(lav1.get_nom() == protec1.get_nom());
    REQUIRE(lav1.get_prenom() == protec1.get_prenom());
}
TEST_CASE("8: Cup")
{
    Utilisateur user1("Braunstein","Cécile",1);
    Protection protec1(user1,3,21);
    Cup cup1(protec1);

    REQUIRE(cup1.get_nom() == protec1.get_nom());
    REQUIRE(cup1.get_prenom() == protec1.get_prenom());
}
