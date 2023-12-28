/**
 * @file        mainExemple.cpp
 * @brief       Programme principal faisant appel aux fonctions ouvrir et sauver qui va générer et remplir de pixels 2 images
 * @author      les power rangers mariam aleyno et mimi
 * @date        2023
 * @copyright   les oukhtys
 */

#include "Image.h"
 
int main() {
 
    Pixel rouge (120, 15, 10);
    Pixel vert (20, 202, 15);
    Pixel bleu (4, 58, 218);
 
    Image image1 (64,48);
    image1.effacer(bleu);
    image1.dessinerRectangle(5, 20, 30, 40, rouge);
    image1.setPix(51,4,vert);
    image1.setPix(20,30,vert);
    image1.sauver("./data/image1.ppm");
 
    Image image2;
    image2.ouvrir("./data/image1.ppm");
    image2.dessinerRectangle(29, 10, 48, 15, rouge);
    image2.dessinerRectangle(25, 24, 40, 45, vert);
    image2.sauver("./data/image2.ppm");
 
    return 0;
}