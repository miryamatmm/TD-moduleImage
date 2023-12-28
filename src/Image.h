/**
 * @file        Image.h
 * @brief       La déclaration de la classe Image
 * @author      les power rangers mariam aleyno et mimi
 * @date        2023
 * @copyright   les oukhtys
 */

#ifndef _IMAGE
#define _IMAGE

#include "Pixel.h"
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

class Image{

 private :

   Pixel * tab;  // le tableau 1D de pixel 
   unsigned int dimx, dimy;  // les dimensions de l'image 

   /**
   * @brief Les variables dont nous aurons besoin pour inclure SDL2 au module 
  */

   SDL_Surface * m_surface; // surface = aire de la fenêtre 
   SDL_Texture * m_texture; // texture de ce qu'il y a à l'intérieur de ma surface 
   SDL_Window * m_window; // fenetre de taille_x et taille_y 
   SDL_Renderer * m_renderer; // l'image afficher sur la fenêtre 

 public :

    /**
    * @brief Constructeur par défaut de la classe: initialise dimx et dimy à 0, ce constructer n'alloue pas de pixels.
    * @see Image::Image ()
    */
   Image ();

    /**
    * @brief Constructeur de la classe: initialise dimx et dimy (après vérification) puis alloue le tableau de pixel dans le tas (image noire)
    * @param [in] dimensionX nouvelle valeur de dimx
    * @param [in] dimensionY nouvelle valeur de dimy
    * @see Image::Image (int dimensionX, int dimensionY)
    */
   Image (int dimensionX, int dimensionY);

   /**
    * @brief Destructeur de la classe: déallocation de la mémoire du tableau de pixels et mise à jour des champs dimx et dimy à 0
    * @see Image::~Image ()
    */
   ~Image ();

   /**
    * @brief Accesseur : récupère le pixel original de coordonnées (x,y) en vérifiant leur validité, la formule pour passer d'un tab 2D à un tab 1D est tab[y*dimx+x]
    * @param [in] x
    * @param [in] y
    * @see Pixel& Image::getPix (int x,int y) const
    * @retval Pixel (tableau 1D)
    */
   Pixel& getPix (int x,int y) const;

   /**
    * @brief Mutateur : modifie le pixel de coordonnées (x,y)
    * @param [in] x coordonnée x du pixel à modifier
    * @param [in] y coordonnée y du pixel à modifier
    * @param [in] couleur en r g b du pixel à modifier
    * @see void Image::setPix(int x, int y, const Pixel& couleur)
    */
   void setPix (int x,int y, const Pixel& couleur);

    /**
    * @brief Dessine un rectangle plein de la couleur dans l'image (en utilisant setPix, indices en paramètre compris) 
    * @param [in] Xmin coordonnées xmin du rectangle
    * @param [in] Ymin coordonnées ymin du rectangle
    * @param [in] Xmax coordonnées xmax du rectangle
    * @param [in] Ymax coordonnées ymin du rectangle
    * @param [in] couleur couleur de fond du rectangle
    * @see void Image::dessinerRectangle (unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax, const Pixel& couleur)
    */
   void dessinerRectangle (unsigned int Xmin,unsigned int Ymin,unsigned int Xmax,unsigned int Ymax, const Pixel& couleur);

  /**
    * @brief Efface l'image en la remplissant de la couleur en paramètre (en appelant dessinerRectangle avec le bon rectangle)
    * @param [in] couleur 
    * @see void Image::effacer(const Pixel& couleur)
    */
   void effacer (const Pixel& couleur);

  /**
    * @brief Effectue une série de tests vérifiant que le module fonctionne et que les données membres de l'objet sont conformes
    * @param none
    * @see void Image::testRegression() const
    */
   void testRegression() const;

  /**
    * @brief Sauvegarde l'image en parametres
    * @param [in] filename nom du fichier
    * @see void Image::sauver(const string & filename) const
    */
   void sauver(const string & filename) const ;

  /**
    * @brief Ouvre, lit et modifie l'image en parametre
    * @param [in] filename fichier
    * @see void Image::ouvrir(const string & filename)
    */
   void ouvrir(const string & filename);

  /** 
    * @brief Affiche tous les pixels de l'image sur la console
    * @param none
    * @see void Image::afficherConsole()
    */
   void afficherConsole();

  /**
   * @brief Affiche l'image dans une fenetre SDL2
   * @param none
   * @see void Image::afficher()
  */
   void afficher ();

  /** 
    * @brief Initialisation des données à afficher
    * @param none
    * @see void Image::afficherInit()
    */
   void afficherInit();

  /** 
    * @brief Affichage de la fenêtre sdl
    * @param none
    * @see void Image::afficherBoucle()
    */
   void afficherBoucle ();

  /** 
    * @brief Destruction des données à afficher
    * @param none
    * @see void Image::afficherDetruit()
    */
   void afficherDetruit();

  /** 
    * @brief permet d'ouvrir, de lire et de modifier l'image en paramètre avec sdl
    * @param [in] filename
    * @param [in] m_renderer
    * @see void Image::ouvrir_SDL (const char* filename, SDL_Renderer * m_renderer)
    */
   void ouvrir_SDL (const char* filename, SDL_Renderer * m_renderer);

  /**
   * @brief dessiner l'image en paramètre aux coordonées (x,y) de largeur w et de hauteur h
   * @param [in] m_renderer
   * @param x coordonnée x du renderer
   * @param y coordonnée y de renderer
   * @param w largeur de l'image
   * @param h hauteur de l'image
   * @see void Image::draw (SDL_Renderer * m_renderer, int x, int y, int w, int h)
  */
   void dessiner (SDL_Renderer * m_renderer, int x, int y, int w, int h);

};

/**
 @mainpage Bienvenue bienvenue, joyeux hunger games
 @section Introduction
 Nous vous présentons notre travail acharné réalisé ce dernier mois, notre petit chef d'oeuvre.
 Il vous suffira de suivre les instructions données dans le readme, amusez vous bien (3 main !!!).
 N'hésitez pas à laisser une bonne note de préférence 5/5 (c'est mérité). 
 Bonne journée !
 @section Auteures
 Les power rangers se sont réunis pour créer ce magnifique module image, en espérant qu'il vous plaira.
*/

#endif