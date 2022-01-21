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
#define W 800
#define H 600

#define X_MIN -1.0
#define X_MAX 10.0

#define Y_MIN -1.0
#define Y_MAX 1500.0

#define X_COEFF W / (X_MAX - X_MIN)
#define Y_COEFF H / (Y_MAX - Y_MIN)

#define PAS 1000

int affichage_eau(Utilisateur &user);
void print_eau(SDL_Renderer *renderer,Gourde &gourde,Bouteille &bouteille);
int affichage_protect(Utilisateur &user);
void print_protec(SDL_Renderer *renderer,Lavable &lavable, Jetable &jetable, Cup &cup);
void draw_axis(SDL_Renderer *renderer);
void set_window_color(SDL_Renderer *renderer, SDL_Color color);
void wait(void);

SDL_Color couleurBlanche = {250,250,250};
SDL_Color noir = {0, 0, 0};

void affichage(Utilisateur &user);



int main()
{
  Utilisateur user1;

  affichage(user1);
  //affichage_protect(user1);
  Utilisateur user;

  user.presentation();
  std::cout << "---------------------------------------------" << std::endl;

	if (user.get_recherche()==2)
	{
		Eau water(user);
		Gourde gourde(water);
		gourde.print();
		Bouteille bottle(water);
		bottle.print();
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

  }

	return 0;
}

void affichage(Utilisateur &user)
{
  int mx,my;
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();
	SDL_StartTextInput();
  SDL_Window* window  = SDL_CreateWindow("There is no planet B",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1000,700,SDL_WINDOW_SHOWN);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
  int quit = 0;
  SDL_Surface *graphique, *surface_titre, *surface_choix, *surface_choix_prote;
  SDL_Surface *surface_question;
	SDL_Texture *texture_graphique, *Message, *Message2, *texture_choix, *texture_protection;
  SDL_Color fond = {112,223,200, 50};

	TTF_Font *police = TTF_OpenFont("Roboto-Medium.ttf", 65);
  if(police == 0)
    std::cout << "/* Error : police */" << '\n';

  graphique = IMG_Load("planetB.jpg");
  texture_graphique = SDL_CreateTextureFromSurface(renderer,graphique);

  surface_choix = IMG_Load("Images/bouteille.jpg");
	texture_choix = SDL_CreateTextureFromSurface(renderer,surface_choix);
  surface_choix_prote = IMG_Load("Images/protection.jpg");
  texture_protection = SDL_CreateTextureFromSurface(renderer,surface_choix_prote);

  surface_titre = TTF_RenderText_Solid(police, "There is no planet B", noir);
  Message = SDL_CreateTextureFromSurface(renderer, surface_titre); //converti la surface en texture
  surface_question = TTF_RenderText_Solid(police, "Que voulez-vous etudier ?", noir);
  Message2 = SDL_CreateTextureFromSurface(renderer, surface_question); //converti la surface en texture

  while (!quit)
  {
    SDL_Event event;
    if (SDL_PollEvent(&event))
  	{
    	switch (event.type)
    	{
      		case SDL_QUIT:
          		quit = 1;
          		break;
          case  SDL_MOUSEBUTTONDOWN:
      				SDL_GetMouseState( &mx, &my );
  				    break;
      }
    }
		/* Etape 2: METTRE A JOUR l'ETAT DE L'APPLICATION GRAPHIQUE */

		SDL_Rect gourde_rect = {250,400,150,150};
		SDL_Rect protection_rect = {600,400,150,150};
		if ((mx>=gourde_rect.x) && (mx<=(gourde_rect.x+gourde_rect.w)) && (my>=gourde_rect.y) && (my<=(gourde_rect.y+gourde_rect.h))){
      affichage_eau(user);
      quit =1;
    }
		if ((mx>=protection_rect.x) && (mx<=(protection_rect.x+protection_rect.w)) && (my>=protection_rect.y) && (my<=(protection_rect.y+protection_rect.h))){
      affichage_protect(user);
      quit =1;
    }

    /* Etape 3 : REDESSINER */

    SDL_SetRenderDrawColor(renderer, fond.r, fond.g, fond.b, fond.a);
  	SDL_Rect rect = {0, 0, 1024, 768};
  	SDL_RenderFillRect(renderer, &rect);

    SDL_Rect image_rect = { 350, 50, 300, 190 };
    SDL_RenderCopy(renderer, texture_graphique, NULL, &image_rect);

		SDL_RenderCopy(renderer, texture_choix, NULL, &gourde_rect);
    SDL_RenderCopy(renderer, texture_protection, NULL, &protection_rect);

    SDL_Rect Titre_rect = { 280, 255,440,80 };
    SDL_RenderCopy(renderer, Message, NULL, &Titre_rect);

    SDL_Rect Question_rect = { 380, 330,250,30 };
    SDL_RenderCopy(renderer, Message2, NULL, &Question_rect);
    SDL_RenderPresent(renderer);

  }
	SDL_DestroyTexture(Message);
	SDL_DestroyTexture(Message2);
	SDL_DestroyTexture(texture_graphique);
	SDL_DestroyTexture(texture_protection);
	SDL_DestroyTexture(texture_choix);
	SDL_FreeSurface(surface_titre);
	SDL_FreeSurface(surface_choix);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  TTF_Quit();
}



//----------------------------------------------------- AFFICHAGE -----------------------------------------------
// affichage des graphes de la classe Eau sur 10 ANS

int affichage_eau(Utilisateur &user){

// Intialisation des variables
  Eau water(user);
  Gourde gourde(water);
  Bouteille bottle(water);

// Calcul des résultats
  gourde.calcul();
  bottle.calcul_prix();

// création de la fenêtre SDL
  int statut = EXIT_FAILURE;
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
      fprintf(stderr, "Erreur SDL_Init : %s.", SDL_GetError());
  else
  {
      SDL_Window *window2 = SDL_CreateWindow("Prix de l'eau en fonction des années et du moyen de consommation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                            W, H, SDL_WINDOW_SHOWN);
      if(!window2)
          fprintf(stderr, "Erreur SDL_CreateWindow : %s.", SDL_GetError());
      else
      {
          SDL_Renderer *renderer2 = SDL_CreateRenderer(window2, -1, SDL_RENDERER_ACCELERATED);
          if(!renderer2)
              fprintf(stderr, "Erreur SDL_CreateRenderer : %s.", SDL_GetError());
          else // si on a pas d'erreur d'ouverture de fenetre et de renderer on affiche nos courbes
          {
              print_eau(renderer2,gourde,bottle);

              statut = EXIT_SUCCESS;
              SDL_DestroyRenderer(renderer2);// destruction des attributs
          }
          SDL_DestroyWindow(window2);// destruction des attributs
      }
      SDL_Quit();// Quitter SDL
  }
  return statut;
}

// dessin des courbes sur le renderer
void print_eau(SDL_Renderer *renderer,Gourde &gourde,Bouteille &bouteille){

  SDL_Color blanc = {255, 255, 255, 255}, rouge = {255, 0, 0, 255},  bleu = {0, 0, 255, 255}, vert = {0, 128, 0, 255} ;
  set_window_color(renderer, blanc); // on definit le fond de la fenetre comme blanc

  SDL_SetRenderDrawColor(renderer, noir.r, noir.g, noir.b, noir.a);
  draw_axis(renderer);// on dessine les axes en noir

  SDL_Surface *surface_legende = IMG_Load("Images/legende_eau.png");
  SDL_Texture *texture_legende;
  texture_legende = SDL_CreateTextureFromSurface(renderer,surface_legende);

  SDL_Rect image_rect = { 350, 50, 200, 100 };
  SDL_RenderCopy(renderer, texture_legende, NULL, &image_rect);
  for(std::size_t i = 0; i < gourde.nb_annees-1; i++){ // on utilise une boucle pour parcourir les resultas, les afficher et les relier entre eux
    // affichage de la gourde en rouge
    SDL_SetRenderDrawColor(renderer, rouge.r, rouge.g, rouge.b, rouge.a);
    SDL_RenderDrawLine(renderer,(i-X_MIN)*X_COEFF,H-(gourde.resultat[i]-Y_MIN)*Y_COEFF,(i+1-X_MIN)*X_COEFF,H-(gourde.resultat[i]-Y_MIN)*Y_COEFF);
    // affichage de l'eau minerale en vert
    SDL_SetRenderDrawColor(renderer, vert.r, vert.g, vert.b, vert.a);
    SDL_RenderDrawLine(renderer,(i-X_MIN)*X_COEFF,H-(bouteille.resultat["mineral"][i]-Y_MIN)*Y_COEFF,(i+1-X_MIN)*X_COEFF,H-(bouteille.resultat["mineral"][i+1]-Y_MIN)*Y_COEFF);
    // affichage de l'eau de source en bleu
    SDL_SetRenderDrawColor(renderer, bleu.r, bleu.g, bleu.b, bleu.a);
    SDL_RenderDrawLine(renderer,(i-X_MIN)*X_COEFF,H-(bouteille.resultat["source"][i]-Y_MIN)*Y_COEFF,(i+1-X_MIN)*X_COEFF,H-(bouteille.resultat["source"][i+1]-Y_MIN)*Y_COEFF);

  }
  SDL_RenderPresent(renderer);
  SDL_DestroyTexture(texture_legende);
  SDL_FreeSurface(surface_legende);
  wait();// sert à garder la fenetre ouverte
}


// affichage des graphes de la classe Protection sur 10 ANS
int affichage_protect(Utilisateur &user){
// même principe qu'affichage_eau
  Protection protect(user);
  Lavable lav(protect);
  Jetable jet(protect);
  Cup cup(protect);

  lav.calcul_prix();
  jet.calcul_prix();
  cup.calcul_prix();

  int statut = EXIT_FAILURE;
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
      fprintf(stderr, "Erreur SDL_Init : %s.", SDL_GetError());
  else
  {
      SDL_Window *window = SDL_CreateWindow("Prix des protections hygiéniques en fonction des années et du moyen de consommation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                            W, H, SDL_WINDOW_SHOWN);
      if(!window)
          fprintf(stderr, "Erreur SDL_CreateWindow : %s.", SDL_GetError());
      else
      {
          SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

          if(!renderer)
              fprintf(stderr, "Erreur SDL_CreateRenderer : %s.", SDL_GetError());
          else
          {
              print_protec(renderer,lav,jet,cup);
              statut = EXIT_SUCCESS;
              SDL_DestroyRenderer(renderer);
          }
          SDL_DestroyRenderer(renderer);
          SDL_DestroyWindow(window);
      }
      SDL_Quit();
  }
  return statut;

}

// dessin des courbes pour les serviettes lavables, jetables et la coupe menstruelle
void print_protec(SDL_Renderer *renderer, Lavable &lavable, Jetable &jetable, Cup &cup){

  // même principe que print_eau
    SDL_Color blanc = {255, 255, 255, 255}, rouge = {255, 0, 0, 255},  bleu = {0, 0, 255, 255}, vert = {0, 128, 0, 255} ;
    set_window_color(renderer, blanc);
    SDL_SetRenderDrawColor(renderer, noir.r, noir.g, noir.b, noir.a);
    draw_axis(renderer);
    SDL_Surface *surface_legende = IMG_Load("Images/legende_protec.png");
    SDL_Texture *texture_legende;
    texture_legende = SDL_CreateTextureFromSurface(renderer,surface_legende);

    SDL_Rect image_rect = { 350, 50, 200, 100 };
    SDL_RenderCopy(renderer, texture_legende, NULL, &image_rect);
    for(std::size_t i = 0; i < jetable.nb_annees-1; i++){
      // on affiche les valeurs des serviettes jetables en rouge
      SDL_SetRenderDrawColor(renderer, rouge.r, rouge.g, rouge.b, rouge.a);
      SDL_RenderDrawLine(renderer,(i-X_MIN)*X_COEFF,H-(jetable.res_an[i]-Y_MIN)*Y_COEFF,(i+1-X_MIN)*X_COEFF,H-(jetable.res_an[i+1]-Y_MIN)*Y_COEFF);
      // les serviettes lavables en vert
      SDL_SetRenderDrawColor(renderer, vert.r, vert.g, vert.b, vert.a);
      SDL_RenderDrawLine(renderer,(i-X_MIN)*X_COEFF,H-(lavable.res_an[i]-Y_MIN)*Y_COEFF,(i+1-X_MIN)*X_COEFF,H-(lavable.res_an[i+1]-Y_MIN)*Y_COEFF);
      // et la coupe menstruelle en bleu
      SDL_SetRenderDrawColor(renderer, bleu.r, bleu.g, bleu.b, bleu.a);
      SDL_RenderDrawLine(renderer,(i-X_MIN)*X_COEFF,H-(cup.res_an[i]-Y_MIN)*Y_COEFF,(i+1-X_MIN)*X_COEFF,H-(cup.res_an[i+1]-Y_MIN)*Y_COEFF);
    }
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(texture_legende);
    SDL_FreeSurface(surface_legende);
    wait();

}

// determine la couleur de fond de la fenêtre
void set_window_color(SDL_Renderer *renderer, SDL_Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer);
}

// boucle infini qui permet de garder la fenetre ouverte
void wait()
{
    SDL_Event e;
    while(SDL_WaitEvent(&e) && e.type != SDL_QUIT);
}

// dessin des axes x et y
void draw_axis(SDL_Renderer *renderer)
{
  TTF_Font *police = TTF_OpenFont("Roboto-Medium.ttf", 65);
  SDL_Surface *surface_legend = TTF_RenderText_Solid(police, "Prix (euros)", noir);
  SDL_Texture *legend = SDL_CreateTextureFromSurface(renderer, surface_legend); //converti la surface en texture
  SDL_Rect rect_leg = { 10, 50, 60, 15 };
  SDL_RenderCopy(renderer, legend, NULL, &rect_leg);
  SDL_RenderDrawLine(renderer, -X_MIN * X_COEFF, 0, -X_MIN * X_COEFF, H);
  SDL_RenderDrawLine(renderer, 0, Y_MAX * Y_COEFF, W, Y_MAX * Y_COEFF);
  SDL_DestroyTexture(legend);
  SDL_FreeSurface(surface_legend);
}
