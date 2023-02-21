//
//  Pixel.hpp
//  TD
//
//  Created by Youri Novikov on 26/01/2021.
//

#ifndef Pixel_hpp
#define Pixel_hpp

#include <stdio.h>
#include <iostream>


class Pixel
{
private:
    unsigned char r, g, b; // Déclaration de variables rouge, vert et bleu
    
public:
    Pixel(); // Constructeur avec des valeurs par défaut
    Pixel(unsigned char nr, unsigned char ng, unsigned char nb); // Constructeur avec de valeurs données
    unsigned char getRouge() const; // Return de pixel Rouge
    unsigned char getVert() const; // Return de pixel Vert
    unsigned char getBleu() const; // Return de pixel Rouge
    void setRouge(unsigned char nr); // Changement de pixel Rouge
    void setVert(unsigned char ng); // Changement de pixel Vert
    void setBleu(unsigned char nb); // Changement de pixel Bleu

};

#endif /* Pixel_hpp */


