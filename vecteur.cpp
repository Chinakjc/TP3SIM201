#include "vecteur.hpp"
#include <cmath>
#include <cstdlib>

// fichier vecteur.cpp à compléter

// utilitaire de messages d'erreur
void stop(const char * msg)
{
    cout << "ERREUR classe vecteur, " << msg;
    exit(-1);
}

void test_dim(int d1, int d2, const char * org)
{
    if (d1==d2)  return;
    cout << org << " (" << d1 << "," << d2 << ") dimensions incompatibles";
    exit(-1);
}

// constructeurs-destructeurs
vecteur::vecteur(int d, double v0) // dim et val constante
{
    init(d);
    for (int i=0;i<dim_;i++) val_[i]=v0;
}

vecteur::vecteur(const vecteur & v) // constructeur par copie
{
    init(v.dim_);
    for (int i=0;i<dim_;i++) val_[i]=v[i];
}

vecteur::~vecteur() {clear();}

// outils de construction et de destruction
vecteur vecteur::init(int d) // initialisation avec allocation dynamique
{
    if (d<=0) stop("init() : dimension <=0");
    dim_=d;
    val_ = new double[d];
}

void vecteur::clear()    // désallocation
{
    if (val_!=0) delete [] val_;
    dim_=0;
}

vecteur &vecteur::operator=(const vecteur &vec) {
    dim_ = vec.dim_;
    clear();
    init(dim_);
    for (int i=0;i<dim_;i++) val_[i]=vec.val_[i];
}

double vecteur::operator[](int i) {
    if(i>=dim_)
        throw "error of dimension !";
    return * (val_ + i);
}

double vecteur::operator[](int i) const {
    if(i>=dim_)
        throw "error of dimension !";
    return * (val_ + i);
}

double vecteur::operator()(int i) const {
    return operator[](i-1);
}


double vecteur::operator()(int i) {
    return operator[](i-1);
}

vecteur vecteur::operator()(int i, int j) {
    if((i>dim_)||(j>dim_))
        throw "error of dimension !";
    if(j<=i)
        return init(0);
    vecteur res = init(j-i);
    for(int k = 0; k< j-i; k++){
        *(res.val_ + k) = *(val_ + k + i);
    }
    return res;
}

vecteur &vecteur::operator+=(vecteur &vec) {
    if(dim_!=vec.dim_)
        throw "error of dimension !";
    for(int i=0;i<dim_;i++){
        *(val_ + i) += *(vec.val_+ i);
    }
}

vecteur &vecteur::operator+=(double x) {
    for(int i=0;i<dim_;i++){
        *(val_ + i) += x;
    }
}

vecteur &vecteur::operator-=(vecteur &vec) {
    if(dim_!=vec.dim_)
        throw "error of dimension !";
    for(int i=0;i<dim_;i++){
        *(val_ + i) -= *(vec.val_+ i);
    }
}

vecteur &vecteur::operator-=(double x) {
    operator+=(-x);
}

vecteur &vecteur::operator*=(double x) {
    for(int i=0;i<dim_;i++){
        *(val_ + i) *= x;
    }
}

vecteur &vecteur::operator/=(double x) {
    if(x==0)
        throw "division by zero error !";
    for(int i=0;i<dim_;i++){
        *(val_ + i) /= x;
    }
}

vecteur vecteur::operator*(double x) {
    vecteur res = init(dim_);
    for(int i = 0; i< dim_;i++){
        *(res.val_ + i) = *(val_ + i) * x;
    }
    return res;
}

vecteur vecteur::operator/(double x) {
    if(x==0)
        throw "division by zero error !";
    vecteur res = init(dim_);
    for(int i = 0; i< dim_;i++){
        *(res.val_ + i) = *(val_ + i) * x;
    }
    return res;
}

vecteur vecteur::operator*(vecteur &vec) {
    if(dim_!=vec.dim_)
        throw "error of dimension !";
    vecteur res = init(dim_);
    for(int i = 0; i< dim_;i++){
        *(res.val_ + i) = *(val_ + i) * *(vec.val_ + i);
    }
    return res;
}

vecteur vecteur::operator/(vecteur &vec) {
    if(dim_!=vec.dim_)
        throw "error of dimension !";
    vecteur res = init(dim_);
    for(int i = 0; i< dim_;i++){
        double y = *(vec.val_ + i);
        if(y==0)
            throw "division by zero error !";
        *(res.val_ + i) = *(val_ + i) * y;
    }
    return res;
}



vecteur operator+(vecteur &u) {
    return u*1;
}

vecteur operator-(vecteur &u) {
    return u*(-1);
}

bool operator == (vecteur & u, vecteur & v){
    if(&u == &v)
        return true;
    if(u.dim()!=v.dim())
        return false;
    for(int k = 0; k< u.dim(); k++){
        if(u[k]!=v[k])
            return false;
    }
    return true;
}















