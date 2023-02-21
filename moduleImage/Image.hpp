//
//  Image.hpp
//  TD
//
//  Created by Youri Novikov on 26/01/2021.
//


#ifndef Image_hpp
#define Image_hpp

#include "Pixel.hpp"
#include <iostream>
#include <stdio.h>
#include <cassert>
#include <fstream>

using namespace std;

class Image
{
private:
    Pixel * tab; // Définition du tableau de pointeur sur Pixel
    unsigned int dimx, dimy; // Définition de dimension X et Y
public:
    Image(); // Constructeur par défaut
    Image(unsigned int dimensionX, unsigned int dimensionY); // Constructeur avec les valeurs données
    ~Image(); // Destructeur
    Pixel & getPix(unsigned int x,unsigned int y); // Return Pixel demandé
    void setPix(unsigned int x,unsigned int y, Pixel couleur); // Changement de couleur de Pixel demandé
    void dessinerRectangle(unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax, Pixel couleur); // Dessine un rectangle de couleur donnée sur l'emplacement donné
    void effacer(Pixel couleur); // Remplacement du tableau de Pixel par couleur donné
    void testRegression(); // Test de toutes les fonctions
    void sauver(const string & filename); // Création du fichier
    void ouvrir(const string & filename); // Copie du fichier existant
    void afficherConsole(); // Affichage du tableau de Pixel
};

#endif /* Image_hpp */
