#ifndef _COMPLEX_
#define _COMPLEX_

#include <iostream>
using namespace std;

class complex
{ 
    double re,im;

    public: 
    complex(double r=0,double i=0):re(r),im(i) {}

    friend ostream& operator<<(ostream &d,complex x){
        d<<x.re<<","<<x.im<<"i";
        return d;
    }
    
    bool operator>(const complex& elem) {
        return ((re < elem.re) ? 1 : 0);
    }
};

#endif