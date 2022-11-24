//
// Created by kjc on 2022/11/24.
//

#ifndef TP3_VECTEUR_HPP
#define TP3_VECTEUR_HPP


#include <iostream>
using namespace std;

// fichier d'entête vecteur.hpp à compléter

void stop(const char * msg);                     // message d'arrêt
void test_dim(int d1, int d2, const char * org); // test dimension

// classe vecteur de réels double précision
class vecteur
{
private :
    int dim_;          // dimension du vecteur
    double * val_;     // tableaux de valeurs
public:
    vecteur(int d=0, double v0=0); // dim et val constante
    vecteur(const vecteur & v);    // constructeur par copie
    ~vecteur();
    //tools
    vecteur init(int d);              // allocation
    void clear();                  // désallocation
    int dim() const {return dim_;} // accès dimension

    vecteur& operator = (const vecteur & vec);
    double operator [] (int i) const;
    double operator [] (int i);
    double operator () (int i) const;
    double operator () (int i);

    vecteur operator () (int i, int j);
    vecteur& operator += (vecteur& vec);
    vecteur& operator += (const double x);
    vecteur& operator -= (vecteur& vec);
    vecteur& operator -= (const double x);

    vecteur& operator *= (const double x);
    vecteur& operator /= (const double x);
    vecteur operator * (const double x);
    vecteur operator / (const double x);
    vecteur operator * (vecteur& vec);
    vecteur operator / (vecteur& vec);


};

vecteur operator +(vecteur& u);
vecteur operator -(vecteur& u);

bool operator == (vecteur & u, vecteur & v);
bool operator != (vecteur & u, vecteur & v);

ostream & operator << (ostream & os, const vecteur & vec);
istream & operator >> (istream & is, vecteur & res);

vecteur operator*(double x, const vecteur& vect);

#endif