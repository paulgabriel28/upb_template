#include <assert.h>
#include "vector.h"
using namespace std;

// MARK: Constrctori
template <typename T>
vector<T>::vector() {
    dim=0;
    buf=NULL;
}

template <typename T>
vector<T>::vector(const int &d, const T* b){
    dim=d;
    if (b==NULL) buf = NULL;
    else{
        buf=new T[dim]; //constr fara param in T
        for (int i=0;i<dim;i++)
        buf[i]=b[i]; //op= in T
    }
}

template <typename T>
vector<T>::vector(const vector<T>& v){
    dim=v.dim;
    if (v.buf==NULL) buf=NULL;
    else{
        buf=new T[dim]; //constr fara param in T
        for (int i=0;i<dim;i++)
            buf[i]=v.buf[i]; //op= in T
    }
}

template <typename T>
vector<T>::~vector(){
    delete [] buf; //destr in T
}

// MARK: operator=
template <typename T>
vector<T>&  vector<T>::operator=(const vector &v){
    dim=v.dim;
    if (buf!=NULL) delete [] buf; //destr in T
    if (v.buf==NULL) buf=NULL;
    else {
        buf=new T[dim]; //constr fara param in T
        for (int i=0;i<dim;i++)
            buf[i]=v.buf[i]; //op= in T
    }
    return *this;
}

// MARK: operator[]
template <typename T>
T& vector<T>::operator[](int i){
    assert ((i>-1 && i<dim));
    return buf[i];  //constr de copiere in T
}

// MARK: getDim
template <typename T>
int vector<T>::getDim(){
    return dim;
}


// MARK: Sortare
template <typename T>
void vector<T>::sortare() {
    for(int i = 0; i < dim; i++) {
        for(int j = 0; j < dim; j++) {
            if(!(buf[i] > buf[j])) {
                swap(buf[i], buf[j]);
            }
        }
    }
}

// MARK: addElem
template <typename T>
void vector<T>::addElem(const int &poz, const T &elem) {
    T* temp = copyBuf();

    delete [] buf;
    buf = nullptr;

    dim++;
    buf = new T[dim];

    for (int i = 0; i < dim; i++) {
        if (i == poz) {
            buf[i] = elem;
        } else {
            buf[i] = temp[i - (i > poz ? 1 : 0)];
        }
    }

    delete [] temp;
}

// MARK: removeElem
template <typename T>
void vector<T>::removeElem(const int &poz) {
    T* temp = nullptr;
    temp = copyBuf();

    delete [] buf;

    int tempPoz = 0;
    dim--;
    buf = new T[dim];

    for (int i = 0; i < dim + 1; i++) {
        if (i != poz) {
            buf[tempPoz++] = temp[i];
        }
    }

    delete [] temp;
}

// MARK: copyBuf
template <typename T>
T* vector<T>::copyBuf() {
    T *temp = new T[dim];
    
    for(int i = 0; i < dim; i++) {
        temp[i] = buf[i];
    }

    return temp;
}