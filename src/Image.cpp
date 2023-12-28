/**
 * @file        Image.cpp
 * @brief       L'implémentation de la classe Image
 * @author      les power rangers mariam aleyno et mimi
 * @date        2023
 * @copyright   les oukhtys
 */

#include <iostream>
#include <cassert>
#include <fstream>
#include "Image.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;


    Image::Image (){
        dimx=0;
        dimy=0;
        tab= nullptr;
        m_surface = nullptr; 
        m_texture = nullptr; 
    }

    Image::Image (int dimensionX, int dimensionY){
        assert((dimensionX>0) && (dimensionY>0));
        dimx=dimensionX;
        dimy=dimensionY;
        tab= new Pixel[dimx*dimy];
    }

   Image::~Image (){
       if (tab != nullptr) {
            delete [] tab ;
            tab = nullptr ;
        }
       dimx=0;
       dimy=0;
   }

   Pixel& Image::getPix (int x, int y)const{
       return tab[y*dimx+x];
   }

   void Image::setPix (int x, int y, const Pixel &couleur){
        tab[y*dimx+x]=couleur;
   }

   void Image::dessinerRectangle (unsigned int Xmin,unsigned int Ymin,unsigned int Xmax,unsigned int Ymax, const Pixel &couleur){
       for(unsigned int i=Xmin; i<=Xmax; i++){
           for(unsigned int j=Ymin; j<=Ymax; j++){
               setPix(i, j, couleur);
           }
       }
   }

   void Image::effacer (const Pixel &couleur){
       dessinerRectangle(0, 0, dimx-1, dimy-1, couleur);
   }

   
   void Image::testRegression () const {
        Image Im;

        //test du constructeur par défaut
        assert((Im.dimx==0)&&(Im.dimy==0));
        assert(Im.tab == NULL);

        unsigned int dimensionX = 100;
        unsigned int dimensionY = 100;

        //test du constructeur par copie
        Image Im2(dimensionX, dimensionY);
        assert((Im2.dimx==dimensionX)&&(Im2.dimy==dimensionY));

        //test de la fonction getPix
        for(unsigned int i=0; i<Im2.dimx; i++){
            for(unsigned int j=0; j<Im2.dimy; j++){
                assert(Im2.getPix(i,j).getRouge() == 0);
                assert(Im2.getPix(i,j).getBleu() == 0);
                assert(Im2.getPix(i,j).getVert() == 0);
            }
        }

        unsigned int x = 6;
        unsigned int y = 70;
        Pixel couleur(241, 101, 40);


        //test de la procédure setPix
        Im2.setPix(x,y,couleur);
        assert(couleur.getRouge() == Im2.getPix(x, y).getRouge());
        assert(couleur.getBleu() == Im2.getPix(x, y).getBleu());
        assert(couleur.getVert() == Im2.getPix(x, y).getVert());


        unsigned int Xmin = 10;
        unsigned int Xmax = 50;
        unsigned int Ymin = 12;
        unsigned int Ymax = 55;

        //test de la procédure dessinerRectangle
        Im2.dessinerRectangle(Xmin, Ymin, Xmax, Ymax, couleur);
        for(unsigned int i= Xmin; i<Xmax; i++){
           for(unsigned int j=Ymin; j<Ymax; j++){
            assert(couleur.getRouge() == Im2.getPix(i,j).getRouge());
            assert(couleur.getBleu() == Im2.getPix(i,j).getBleu());
            assert(couleur.getVert() == Im2.getPix(i,j).getVert());
           }
       }

        //test de la procédure effacer
       Im2.effacer(couleur);
        for(unsigned int i= 0; i<Im2.dimx; i++){
           for(unsigned int j=0; j<Im2.dimy; j++){
                assert(couleur.getRouge() == Im2.getPix(i,j).getRouge());
                assert(couleur.getBleu() == Im2.getPix(i,j).getBleu());
                assert(couleur.getVert() == Im2.getPix(i,j).getVert());
           }
       }
   }




void Image::sauver(const string & filename) const {
    ofstream fichier (filename.c_str());
    assert(fichier.is_open());
    fichier << "P3" << endl;
    fichier << dimx << " " << dimy << endl;
    fichier << "255" << endl;
    for(unsigned int y=0; y<dimy; ++y)
        for(unsigned int x=0; x<dimx; ++x) {
            Pixel& pix = getPix(x,y);
            fichier << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}

void Image::ouvrir(const string & filename) {
    ifstream fichier (filename.c_str());
    assert(fichier.is_open());
	char r,g,b;
	string mot;
	dimx = dimy = 0;
	fichier >> mot >> dimx >> dimy >> mot;
	assert(dimx > 0 && dimy > 0);
	if (tab != NULL) delete [] tab;
	tab = new Pixel [dimx*dimy];
    for(unsigned int y=0; y<dimy; ++y)
        for(unsigned int x=0; x<dimx; ++x) {
            fichier >> r >> g >> b;
            getPix(x,y).setRouge(r);
            getPix(x,y).setVert(g);
            getPix(x,y).setBleu(b);
        }
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}

void Image::ouvrir_SDL (const char* filename, SDL_Renderer * m_renderer) {
    m_surface = IMG_Load(filename);
    if (m_surface == nullptr) {
        string nfn = string("../") + filename;
        cout << "Erreur : chargement de "<< filename <<". Essai "<<nfn<<endl;
        m_surface = IMG_Load(nfn.c_str());
        if (m_surface == nullptr) {
            nfn = string("../") + nfn;
            m_surface = IMG_Load(nfn.c_str());
        }
    }
    if (m_surface == nullptr) {
        cout<<"Erreur : chargement de "<< filename <<endl;
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(m_surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(m_surface);
    m_surface = surfaceCorrectPixelFormat;

    m_texture = SDL_CreateTextureFromSurface(m_renderer,surfaceCorrectPixelFormat);
    if (m_texture == nullptr) {
        cout << "Erreur: probleme de creation de la texture de "<< filename<< endl;
        exit(1);
    }
    cout << "Lecture de l'image (SDL) " << filename << " ... OK\n";
}


void Image::afficherConsole(){
    cout << dimx << " " << dimy << endl;
    for(unsigned int y=0; y<dimy; ++y) {
        for(unsigned int x=0; x<dimx; ++x) {
            Pixel& pix = getPix(x,y);
            cout << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
        cout << endl;
    }
}

void Image::afficherInit(){

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "Erreur lors de l'initialisation de la SDL_image" << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    int taille_x = 200; //var x pr créer la fenetre
    int taille_y = 200; //var y pr créer la fenetre

    //création de la fenêtre

    m_window = SDL_CreateWindow("baby_yoda", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, taille_x, taille_y, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (m_window == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; SDL_Quit(); exit(1);
    }

    m_renderer = SDL_CreateRenderer(m_window,-1,SDL_RENDERER_ACCELERATED);

    //images

    sauver("./data/image_afficher.ppm");
    ouvrir_SDL("./data/image_afficher.ppm",m_renderer);
}

void Image::dessiner (SDL_Renderer * m_renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?m_surface->w:w;
    r.h = (h<0)?m_surface->h:h;

    ok = SDL_RenderCopy(m_renderer,m_texture,nullptr,&r);
    assert(ok == 0);
}

void Image::afficherDetruit(){
    remove("./data/image_afficher.ppm");

    SDL_FreeSurface(m_surface);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();

    m_surface = nullptr;
    m_texture = nullptr;
}

void Image::afficherBoucle(){
    
    SDL_Event events; //pr détecter n'importe quel évènements 
	bool quit = false; // au début on veut pas quitter

    float zoom = 0;

    while(!quit){
         while (SDL_PollEvent(&events)) {
			if (events.type == SDL_QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
			else if (events.type == SDL_KEYDOWN) {              // Si une touche est enfoncee
                switch (events.key.keysym.scancode)
                {
                case SDL_SCANCODE_G: //lorsque l'utilisateur appuie sur T
                    zoom = zoom - 50;
                    break;

                case SDL_SCANCODE_T: //lorsque l'utilisateur appuie sur G
                    zoom = zoom + 50;
                    break;

                case SDL_SCANCODE_Q:
                    quit = true;
                    break;

                case SDL_SCANCODE_ESCAPE:
                    quit = true;
                    break;
                
                default:
                    break;
                }
		}
    }

   SDL_SetRenderDrawColor(m_renderer,128,128,128,128); // fond gris
   SDL_RenderClear(m_renderer);

    dessiner(m_renderer,0-(zoom/2),0-(zoom/2),200+zoom,200+zoom); //update le zoom

    SDL_RenderPresent(m_renderer);

}

}

void Image::afficher (){
    afficherInit();
    afficherBoucle();
    afficherDetruit();
}



