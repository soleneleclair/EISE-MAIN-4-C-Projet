#pragma once
#include <string>
#include <iostream>
#include "Utilisateur.hh"

class Eau : public Utilisateur
{
  public :
    // Valeur globale (utilisée dans les 2 classes filles pour la création des résultats)
    std::size_t nb_annees = 10;

    //Attribut public

    //Constructeurs
    Eau(); //Constructeur par défault
    Eau(const Utilisateur &u);
    Eau(const Utilisateur &u, std::size_t litre_j,std::string type):Utilisateur(u),_litre_j(litre_j),_type(type){};
    Eau(std::string nom, std::string prenom, int recherche);
    Eau(std::string nom, std::string prenom, int recherche,std::size_t litre_j,std::string type):Utilisateur(nom,prenom,recherche),_litre_j(litre_j),_type(type){};
    Eau(const Eau &e):Utilisateur(e),_litre_j(e._litre_j),_type(e._type){}; //Constructeur par copie

    //Fonction
    virtual void print() const; //Affichage

    //Getter
    std::size_t get_litre(){return _litre_j;}

  private:
    std::size_t _litre_j; //Nombre de litre bu par l'utilisateur en une journée
    std::string _type;
};
