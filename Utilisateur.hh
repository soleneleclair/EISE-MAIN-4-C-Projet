#pragma once
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>


class Utilisateur{
public:
  Utilisateur();
  Utilisateur(std::string nom,  std::string prenom, int recherche):_nom(nom),_prenom(prenom),_recherche(recherche){};
  Utilisateur(const Utilisateur &u):_nom(u._nom),_prenom(u._prenom),_recherche(u._recherche){};

  //getters
  std::string get_nom() const {return _nom;}
  std::string get_prenom() const {return _prenom;}
  int get_recherche() const {return _recherche;}

  void presentation();
  //void presentation_SDL(SDL_Renderer *renderer,SDL_Surface *surface,SDL_Texture *Message, TTF_Font *font);

private:

  std::string _nom;
  std::string _prenom;
  int _recherche;
};

void affichage();
void SDL_accueil(SDL_Renderer *renderer,SDL_Texture *Message,SDL_Surface  *surface_titre, TTF_Font *font);
