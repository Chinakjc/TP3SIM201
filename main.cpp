#include "vecteur.hpp"

int main ()
{
    // constructeurs
    vecteur v1(5);
    cout << "v1=" << v1 << endl;
    vecteur v2(5,4.);
    cout << "v2=" << v2 << endl;
    vecteur v3=v2;
    cout << "v3=" << v3 << endl;
    v3=3.;
    cout << "v3=" << v3 << endl;
    //acces
    for (int i=1;i<=v3.dim(); i++) v3(i)*=i;
    cout << "v3=" << v3 << endl;
    cout << "v3(3,5)=" << v3(3,5) << endl;
    // op algébriques
    vecteur w=2*v1+v2/4-v3;
    // écriture
    cout << "w = 2*v1+v2/4-v3 = " << w << endl;
    //concaténation
    cout << "(v2,v3)=" << (v2,v3) << endl;
    // comparaison
    cout << "v2==v2? : " << (v2==v2? "true":"false") << endl;
    cout << "v1!=v2? : " << (v1!=v2? "true":"false") << endl;
    // produit/division composante à composante
    cout << "w*~w=" <<  w*~w  << endl;
    cout << "w/~w=" <<  w/~w  << endl;
    return 0;
}

/* sortie du code :
v1=(0,0,0,0,0)
v2=(4,4,4,4,4)
v3=(4,4,4,4,4)
v3=(3,3,3,3,3)
v3=(3,6,9,12,15)
v3(3,5)=(9,12,15)
w = 2*v1+v2/4-v3 = (-2,-5,-8,-11,-14)
(v2,v3)=(4,4,4,4,4,3,6,9,12,15)
v2==v2? : true
v1!=v2? : true
w*~w=(4,25,64,121,196)
w/~w=(1,1,1,1,1)
*/
