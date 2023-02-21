//
//  Pixel.cpp
//  TD
//
//  Created by Youri Novikov on 26/01/2021.
//

#include "Pixel.hpp"
using namespace std;

Pixel::Pixel() // Constructeur avec des valeurs par défaut
{
    r = 0;
    g = 0;
    b = 0;
}

Pixel::Pixel(unsigned char nr, unsigned char ng, unsigned char nb) // Constructeur avec de valeurs données
{
    r = nr;
    g = ng;
    b = nb;
}


unsigned char Pixel::getRouge() const // Return de pixel Rouge
{
    return r;
}

unsigned char Pixel::getVert() const // Return de pixel Vert
{
    return g;
}

unsigned char Pixel::getBleu() const // Return de pixel Rouge
{
    return b;
}

void Pixel::setRouge(unsigned char nr) // Changement de pixel Rouge
{
    r = nr;
}

void Pixel::setVert(unsigned char ng) // Changement de pixel Vert
{
    g = ng;
}

void Pixel::setBleu(unsigned char nb) // Changement de pixel Bleu
{
    b = nb;
}

