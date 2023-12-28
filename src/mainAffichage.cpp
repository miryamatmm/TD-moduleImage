/**
 * @file        mainAffichage.cpp
 * @brief       Programme principal affichant une fenêtre SDL rempli d'une image 
 * @author      les power rangers mariam aleyno et mimi
 * @date        2023
 * @copyright   les oukhtys
 */

#include "Image.h"
 
int main (int argc, char** argv) {
 
   Image image (11,11);
 
   Pixel gris (226, 226, 226);
   Pixel vert (1, 130, 0);
   Pixel noir (0, 0, 0);
   Pixel beigeC (210, 188, 154);
   Pixel beigeF (168, 105, 8);
   Pixel marron (102, 65, 8);
 
   image.effacer(gris);
   image.dessinerRectangle(3,0,7,10,vert);
   image.dessinerRectangle(0,1,10,1,vert);
   image.setPix(2,2,vert);
   image.setPix(8,2,vert);
   image.setPix(3,2,gris);
   image.setPix(7,2,gris);
   image.setPix(4,2,noir);
   image.setPix(6,2,noir);
   image.dessinerRectangle(1,5,9,6,vert);
   image.setPix(5,10,gris);
   image.dessinerRectangle(9,7,9,10,marron);
   image.dessinerRectangle(2,5,8,6,beigeC);
   image.dessinerRectangle(3,7,7,9,beigeC);
   image.dessinerRectangle(4,5,6,6,beigeF);
   image.setPix(5,7,beigeF);
 
   image.afficher();
 
   return 0;
}