#pragma once
#include <string>
#include <iostream>
#include "Utilisateur.hh"

class Eau : public Utilisateur
{
  public :
    // Valeur globale (utilisée dans les 2 classes filles pour la création des résultats)
    std::size_t nb_annees = 10;


    //Constructeurs
    Eau(); //Constructeur par défault
    Eau(const Utilisateur &u);
    Eau(const Utilisateur &u, float litre_j,std::string type):Utilisateur(u),_litre_j(litre_j){};
    Eau(std::string nom, std::string prenom, int recherche);
    Eau(std::string nom, std::string prenom, int recherche,float litre_j):Utilisateur(nom,prenom,recherche),_litre_j(litre_j){};
    Eau(const Eau &e):Utilisateur(e),_litre_j(e._litre_j){}; //Constructeur par copie

    //Fonction
    virtual void print() const; //Affichage

    //Getter
    float get_litre(){return _litre_j;}

  private:
    //Attribut privé
    float _litre_j; //Nombre de litre bu par l'utilisateur en une journée
};
