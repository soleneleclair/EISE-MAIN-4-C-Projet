 #include "Utilisateur.hh"
#include <string>
#include <iostream>
SDL_Color couleurBlanche = {250,250,250};
SDL_Color noir = {0, 0, 0};

Utilisateur::Utilisateur()
{
	std::cout << "Nom ?" << std::endl;
	std::cin >> _nom;
  std::cout << "Prénom ?" << std::endl;
	std::cin >> _prenom;
  std::cout << "Type 1 : projection hygiénique, Type 2 : gourde" << std::endl;
  std::cin >> _recherche;
}

void Utilisateur::presentation()
{
	std::cout << "\t \t Voici la personne étudiée : " << '\n';
	std::cout << "Nom : " << _nom << std::endl;
  std::cout << "Prénom : " << _prenom << std::endl;
	if (_recherche == 1)
		std::cout << "La recherche porte sur les protections hygiéniques. " << _recherche << std::endl;
	else
		std::cout << "La recherche porte sur les gourdes. " << std::endl;

}

// void Utilisateur::presentation_SDL(SDL_Renderer *renderer,SDL_Surface *surface_titre, SDL_Texture *Message, TTF_Font *police)
// {
// 	surface_titre = TTF_RenderText_Solid(police, _nom.c_str(), noir);
// 	Message = SDL_CreateTextureFromSurface(renderer, surface_titre);
// 	SDL_Rect Titre_rect = { 500, 230,100,50 };
// 	SDL_RenderCopy(renderer, Message, NULL, &Titre_rect);
//
// 	// surface_titre = TTF_RenderText_Solid(police, _prenom.c_str(), noir);
// 	// Message = SDL_CreateTextureFromSurface(renderer, surface_titre);
// 	// SDL_Rect prenom_rect = { 200, 230,100,50 };
// 	// SDL_RenderCopy(renderer, Message, NULL, &prenom_rect);
// }

// void SDL_accueil(SDL_Renderer *renderer,SDL_Texture *Message,SDL_Surface *surface_titre, TTF_Font *font)
// {
// 	SDL_Color noir = {0, 0, 0};
// 	surface_titre = TTF_RenderText_Solid(font, "bleu", noir);
//   Message = SDL_CreateTextureFromSurface(renderer, surface_titre);
// 	SDL_Rect Titre_rect = { 500, 30,300,80 };
// 	SDL_RenderCopy(renderer, Message, NULL, &Titre_rect);
// }

void affichage()
{
	Utilisateur user("Leclair","Solene",2);
	//char *text;
	SDL_Color noir = {0, 0, 0};
  int mx,my;
	int goGourde = 0;
	int goProtec = 0;
	//int nom_enabled=1;
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();
	SDL_StartTextInput();
  SDL_Window* window  = SDL_CreateWindow("There is no planet B",SDL_WINDOWPOS_UNDEFINED,
                                                                  SDL_WINDOWPOS_UNDEFINED,
                                                                  1000,
                                                                  700,
                                                                  SDL_WINDOW_SHOWN);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
  int quit = 0;
  SDL_Event event;
  SDL_Surface *graphique, *surface_titre, *surface_choix;
  SDL_Surface *surface_input;
	SDL_Texture *texture_graphique, *Message, *Message2, *texture_choix, *texture_protection, *Message3;
  SDL_Color fond = {112,223,200, 50};
	//SDL_Color fond = {181,203,168, 100};

	TTF_Font *police = TTF_OpenFont("Roboto-Medium.ttf", 65);
  if(police == 0)
    std::cout << "/* Error : police */" << '\n';

  graphique = IMG_Load("planetB.jpg");
  texture_graphique = SDL_CreateTextureFromSurface(renderer,graphique);

  surface_choix = IMG_Load("plan9.bmp");
	texture_choix = SDL_CreateTextureFromSurface(renderer,surface_choix);
  texture_protection = SDL_CreateTextureFromSurface(renderer,surface_choix);

  surface_titre = TTF_RenderText_Solid(police, "There is no planet B", noir);
  Message = SDL_CreateTextureFromSurface(renderer, surface_titre); //converti la surface en texture
  Message2 = SDL_CreateTextureFromSurface(renderer, surface_titre); //converti la surface en texture

  while (!quit)
  {
    if (SDL_PollEvent(&event))
  	{
  		//printf("un event\n");
    	switch (event.type)
    	{
        		case SDL_QUIT:
            		quit = 1;
            		break;
            case  SDL_MOUSEBUTTONDOWN:
        				SDL_GetMouseState( &mx, &my );
        				//printf("mx=%d my=%d\n",mx,my);
    				    break;
						/*case SDL_TEXTINPUT:
                // Add new text onto the end of our text
								strcat(text, event.text.text);
								//if (nom_enabled == 1){
								printf("%s\n",text);
								surface_input = TTF_RenderText_Solid(police, text, noir);
								//}
                break;*/

      }
    }
		/* Etape 2: METTRE A JOUR l'ETAT DE L'APPLICATION GRAPHIQUE */

		SDL_Rect gourde_rect = {250,300,150,150};
		SDL_Rect protection_rect = {600,300,150,150};
		if ((mx>=gourde_rect.x) && (mx<=(gourde_rect.x+gourde_rect.w)) && (my>=gourde_rect.y) && (my<=(gourde_rect.y+gourde_rect.h)))
			goGourde=1;
		else
			goGourde=0;

		if ((mx>=protection_rect.x) && (mx<=(protection_rect.x+protection_rect.w)) && (my>=protection_rect.y) && (my<=(protection_rect.y+protection_rect.h)))
				goProtec=1;
		else
				goProtec=0;

	/*	SDL_Rect valide_rect = { 670, 250, 65, 45 };
		if ((mx>=valide_rect.x) && (mx<=(valide_rect.x+valide_rect.w)) && (my>=valide_rect.y) && (my<=(valide_rect.y+valide_rect.h)))
				nom_enabled=0;
		else
				nom_enabled=1;*/

    /* Etape 3 : REDESSINER */

    SDL_SetRenderDrawColor(renderer, fond.r, fond.g, fond.b, fond.a);
  	SDL_Rect rect = {0, 0, 1024, 768};
  	SDL_RenderFillRect(renderer, &rect);

    SDL_Rect image_rect = { 370, 150, 250, 165 };
    SDL_RenderCopy(renderer, texture_graphique, NULL, &image_rect);

		SDL_RenderCopy(renderer, texture_choix, NULL, &gourde_rect);
    SDL_RenderCopy(renderer, texture_protection, NULL, &protection_rect);

    SDL_Rect Titre_rect = { 300, 50,400,80 };
    SDL_RenderCopy(renderer, Message, NULL, &Titre_rect);

    // Message3 = SDL_CreateTextureFromSurface(renderer, surface_input); //converti la surface en texture
		// SDL_Rect input_rect = { 350, 130,100,30 };
		// SDL_RenderCopy(renderer, Message3, NULL, &input_rect);
		//user.presentation_SDL(renderer,surface_titre, Message_user,police);

		if (goGourde==1 || goProtec == 1)
		{

      SDL_SetRenderDrawColor(renderer, fond.r, fond.g, fond.b, fond.a);
      SDL_RenderFillRect(renderer, &rect);

      if (goProtec == 1)
  		{
        SDL_Rect Titre_rect = { 300, 50,400,50 };
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        surface_input = TTF_RenderText_Solid(police, "Protection hygienique", noir);
        Message3 = SDL_CreateTextureFromSurface(renderer, surface_input);
        SDL_RenderCopy(renderer, Message3, NULL, &Titre_rect);

  		}
      else{
        SDL_Rect Titre_rect = { 450, 50,100,50 };
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        surface_input = TTF_RenderText_Solid(police, "Eau", noir);
        Message3 = SDL_CreateTextureFromSurface(renderer, surface_input);
        SDL_RenderCopy(renderer, Message3, NULL, &Titre_rect);
      }
    }

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
