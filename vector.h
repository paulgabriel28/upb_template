#ifndef _VECTOR_
#define _VECTOR_

#include <iostream>
using namespace std;

template <typename T>
class vector
{   
    int dim;
    T* buf;
    
    public:
        vector();
        vector(const int &, const T*);
        vector(const vector&);
        vector & operator=(const vector &);
        ~vector();
        T& operator[](int i);
        int getDim();

        friend ostream & operator << (ostream & dev,  vector & v) {
            dev << "Vector: " <<endl;
            dev << "Nr Elem: " << v.dim << endl;
            if (v.buf!=NULL)
            for(int i = 0; i < v.dim; i++) {
                dev << v.buf[i]; //am nevoie de op<< pt T
                if(i < v.dim-1)
                    dev << "; ";
                else
                    dev << "." << endl;
            }

            dev<<endl;
            return dev;
        }


    T* copyBuf();
    void sortare();
    void addElem(const int &, const T &);
    void removeElem(const int &);
};

#endif