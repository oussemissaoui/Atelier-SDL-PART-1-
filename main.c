#include <SDL/SDL.h>//inclure SDL.h  pour permettre au programme d'être portable sur tous les systèmes.
#include <SDL/SDL_image.h>//Pour manipuler des images ayants des types autre que bmp
#include <SDL/SDL_mixer.h>//Pour manipuler de l’audio.
#include <SDL/SDL_ttf.h>//Pour manipuler des textes

int main ( int argc, char** argv )
{
TTF_Init();
SDL_Surface *ecran;//Déclaration d'une variable pointeure sur surface:  pour l'écran,
SDL_Surface *image;//Déclaration d'une variable pointeure sur surface: pour l'image 
SDL_Surface *texte;  //Déclaration des variables pointeurs sur surfaces:  pour le texte
//Déclaration des variables de type entier pour la boucle de jeu 
int quitter = 1;
//Déclaration d'un compteur pour la mise à jour aprés un événement
//..................
//Déclaration des positions d'affichage : une pour l'image et une pour le texte
SDL_Rect posecranimg;
SDL_Rect postexte;
//Déclaration du police
TTF_Font *police;

//Déclaration de la couleur
SDL_Color noire;
//Déclaration de l'événment 
SDL_Event event;
//Déclaration d'une chaine de caractère
char message[100] =  "We will Never forget, we will Never stop sharing";
//Déclaration d'une variable pointeur sur l'audio pour le son continue
Mix_Music *musique;

//Initialisation des sous systhème de SDL vidéo, son et texte
SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO) ;

Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
 

	/* initialisation de SDL_Video */
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Echec d'initialisation de SDL : %s\n", SDL_GetError());
		return 1;
	
	}
	
	else
	printf("Bonjour le monde, SDL est initialisé avec succès.\n");
	/* creation d'une fenetre avec une zone d'affichage de 600*430 pixels et qui pemet d'afficher des image couleur*/
	ecran = SDL_SetVideoMode(600, 430,  32,SDL_HWSURFACE | SDL_DOUBLEBUF);
	if ( ecran == NULL )
	{
		fprintf(stderr, "Echec de creation de la fenetre de 300*300: %s.\n", SDL_GetError());
		return 1;
	}
	
	//téléchargement de l'image palestine.jpg
	image = IMG_Load("palestine.jpg");
		if (image == NULL) {
			fprintf(stderr, "Echec de telechargement de image: %s.\n", SDL_GetError());
			return 1;
		}
	//Position de l'image palestine.jpg
	posecranimg.x = 0;
	posecranimg.y = 0;
	posecranimg.w = ecran->w;
	posecranimg.h = ecran->h;	
	//position du texte
	postexte.x=10;
	postexte.y=300;
       // couleur du texte noire
        noire.r=0;
		noire.g=0;
		noire.b=0;
	//téléchargement du police
        police = TTF_OpenFont("arial.ttf",24);
        //Télécharger la musique
	musique = Mix_LoadMUS("palestine.mp3");
	//Lancer la musique avant la boucle du jeu
      Mix_PlayMusic(musique,-1);
      
	  texte = TTF_RenderText_Blended(police,message,noire);
      /* instructions f et g du workshop */

	while(quitter) 
	{
	// Activité 2 du workshop  Afficher l'image palestine.jpg
	//..................
	//Lecture de l'événement	
	SDL_BlitSurface(image,NULL,ecran,&posecranimg);
	
	SDL_Flip(ecran);

	SDL_PollEvent(&event); 
	// Selon le type de l'événement
	switch (event.type)
         { 
        // exit if the window is closed
		case SDL_QUIT: quitter = 0;
        	break;
        //Lecture d'un événement par clavier
		case SDL_MOUSEBUTTONDOWN : 
			SDL_BlitSurface(texte,NULL,ecran,&postexte);
			SDL_Flip(ecran);
			break;
		case SDL_KEYDOWN:

				if(event.key.keysym.sym == SDLK_ESCAPE){
					quitter=0;
				}
			break;
        		
       //Si on clique sur le bouton echap
           		
        	break;
        //lecture d'un événement clique bouton souris
         	
                		
           	
	 	break;
	 }
	//if(..........)
                {	//écriture du texte We Will NEVER forget \n We will NEVER stop sharing
		//..................
                //Affichage du texte 
               //..................
       		}
          //Refraichir l'écran
	//..................

	}

	TTF_CloseFont(police);
	SDL_FreeSurface(image);
		//Fermeture des sous-systèmes audio et texte, libération de la mémoire des ressources images, texte et son.
	TTF_Quit();
	SDL_Quit();
	return 0;
}

