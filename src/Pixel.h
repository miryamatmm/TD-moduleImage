/**
 * @file        Pixel.h
 * @brief       La déclaration de la classe Pixel
 * @author      les power rangers mariam aleyno et mimi
 * @date        2023
 * @copyright   les oukhtys
 */


#ifndef _PIXEL
#define _PIXEL

class Pixel
{
    private:
        unsigned char r; // la composante rouge du pixel (compris entre 0 et 255)
        unsigned char g; // la composante vert du pixel (compris entre 0 et 255)
        unsigned char b; // la composante bleue du pixel (compris entre 0 et 255)
    public :

    /**
    * @brief Constructeur par défaut de la classe: initialise le pixel à la couleur noire
    * @param none
    * @see Pixel::Pixel ()
    */
    Pixel ();

    /**
    * @brief Constructeur de la classe: initialise r,g,b avec les paramètres
    * @param [in]  nr  nouvelle valeur pour le rouge
    * @param [in] ng  nouvelle valeur pour le vert
    * @param [in]  nb  nouvelle valeur pour le bleu
    * @see Pixel::Pixel (unsigned char nr, unsigned char ng, unsigned char nb)
    */
    Pixel (unsigned char nr, unsigned char ng, unsigned char nb);

    /**
    * @brief Accesseur : récupère la composante rouge du pixel
    * @param none
    * @see unsigned char Pixel::getRouge () const
    * @retval unsigned char la composante rouge du pixel
    */
    unsigned char getRouge () const;

    /**
    * @brief Accesseur : récupère la composante verte du pixel
    * @param none
    * @see unsigned char Pixel::getVert () const
    * @retval unsigned char la composante verte du pixel
    */
    unsigned char getVert () const;

    /**
    * @brief Accesseur : récupère la composante bleue du pixel
    * @param none
    * @see unsigned char Pixel::getBleu () const
    * @retval unsigned char la composante bleue du pixel
    */
    unsigned char getBleu () const ;

    /**
    * @brief Mutateur : modifie la composante rouge du pixel
    * @param [in] nr nouvelle valeur pour le rouge
    * @see void Pixel::setRouge (unsigned char nr)
    */
    void setRouge (unsigned char nr);

    /**
    * @brief Mutateur : modifie la composante verte du pixel
    * @param [in] ng nouvelle valeur pour le vert
    * @see void Pixel::setVert (unsigned char ng)
    */
    void setVert (unsigned char ng);

    /**
    * @brief Mutateur : modifie la composante bleue du pixel
    * @param [in] nb nouvelle valeur pour le bleu
    * @see void Pixel::setBleu (unsigned char nb)
    */
    void setBleu (unsigned char nb);

};

#endif