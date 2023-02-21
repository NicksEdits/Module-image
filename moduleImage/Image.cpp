//
//  Image.cpp
//  TD
//
//  Created by Youri Novikov on 26/01/2021.
//

#include "Image.hpp"
using namespace std;

Image::Image()
{
    dimx = 0;
    dimy = 0;
    tab = NULL;
}

Image::Image(unsigned int dimensionX, unsigned int dimensionY)
{
    dimx = dimensionX;
    dimy = dimensionY;
    tab = new Pixel[dimx*dimy];
}

Image::~Image()
{
    delete []tab;
    dimx = 0;
    dimy = 0;
}

Pixel & Image::getPix(unsigned int x,unsigned int y)
{
    assert(dimx >= x && dimy >= y);
    return tab[y*dimx+x];
}

void Image::setPix(unsigned int x,unsigned int y, Pixel couleur)
{
    assert(dimx >= x && dimy >= y);
    tab[y*dimx+x].setRouge(couleur.getRouge());
    tab[y*dimx+x].setVert(couleur.getVert());
    tab[y*dimx+x].setBleu(couleur.getBleu());
}

void Image::dessinerRectangle(unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax, Pixel couleur)
{
    assert(dimx >= Xmax && dimy >= Ymax);
    assert(Xmax > Xmin && Ymax > Ymin);
    for (unsigned int x = Xmin; x < Xmax; ++x)
    {
        for (unsigned int y = Ymin; y < Ymax; ++y) setPix(x, y, couleur);
    }
}

void Image::effacer(Pixel couleur)
{
    this->dessinerRectangle(0, 0, dimx, dimy, couleur);
}

void Image::testRegression()
{
    
    assert(dimx >= 2 && dimy >= 2);
    // test 1
    assert(this->getPix(1,1).getRouge() == 0);
    // test 2
    Pixel test(1,1,1);
    this->setPix(1, 1, test);
    assert(this->getPix(1,1).getRouge() == 1);
    // test 3
    this->dessinerRectangle(0, 0, 2, 2, test);
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 2; y++)
        {
            test = this->getPix(x,y);
            assert(test.getRouge() == 1);
        }
    }
    // test 4
    test.setRouge(2);
    test.setBleu(2);
    test.setVert(2);
    this->effacer(test);
    assert(tab[0].getRouge() == 2);
}


void Image::sauver(const string & filename)
{
    ofstream fichier (filename.c_str());
    assert(fichier.is_open());
    fichier << "P3" << endl;
    fichier << dimx << " " << dimy << endl;
    fichier << "255" << endl;
    for (unsigned int y = 0; y < dimy; ++y)
    {
        for (unsigned int x = 0; x < dimx; ++x)
        {
            Pixel pix = getPix(x,y);
            fichier << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
    }
       
    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}

void Image::ouvrir(const string & filename)
{
    ifstream fichier (filename.c_str());
    assert(fichier.is_open());
    unsigned int r,g,b;
    string mot;
    dimx = dimy = 0;
    fichier >> mot >> dimx >> dimy >> mot;
    assert(dimx > 0 && dimy > 0);
    if (tab != NULL) delete [] tab;
    tab = new Pixel [dimx*dimy];
    for(unsigned int y=0; y < dimy; ++y)
    {
        for(unsigned int x=0; x < dimx; ++x)
        {
            fichier >> r >> g >> b;
            Pixel pix(r,g,b);
            setPix(x,y,pix);
        }
    }
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}

void Image::afficherConsole(){
    cout << dimx << " " << dimy << endl;
    for (unsigned int y=0; y < dimy; ++y)
    {
        for (unsigned int x=0; x < dimx; ++x)
        {
            Pixel pix = this->getPix(x,y);
            cout << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
        cout << endl;
    }
}
