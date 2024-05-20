#ifndef _PERECHE_
#define _PERECHE_

#include <iostream>
using namespace std;

template <typename X, typename Y>
class pereche {
    X elem1;
    Y elem2;
    
    public:
        pereche() = default;

        pereche(const X &e1, const Y &e2) {
            elem1=e1;
            elem2=e2; 
        }

        friend ostream& operator<<(ostream &d,const pereche &x) {
            d<<x.elem1<<" si " << x.elem2;
            return d; 
        }

        bool operator>(const pereche& elem) {
            return ((elem1 > elem.elem1) ? 1 : 0);
        }
};

#endif