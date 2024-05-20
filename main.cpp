#include "vector.h"
#include "vector.cpp"
#include "complex.h"
#include "pereche.h"

#include "Angajat.h"

#include <iostream>
#include <string>
using namespace std;

int main(){
    // MARK: Complex
    complex *b=new complex[2];
    b[0]=complex(1,2);
    b[1]=complex(2,2);
    vector<complex> v(2,b);
    cout<<v;

    complex add(0,3);
    v.addElem(0, add);
    cout << "\naddElem:\n";
    cout << v;

    v.removeElem(1);
    cout << "\nremoveElem poz = 1\n";
    cout << v;

    // MARK: string
    string *s = new string[2];
    s[0] = "paul";
    s[1] = "gabriel";
    vector<string> vS(2, s);
    cout << vS;
    string addStr = "andrei";
    vS.addElem(1, addStr);
    cout << vS;

    // MARK: int
    int *in = new int[2];
    in[0] = 21;
    in[1] = 12;
    vector<int> vIn(2, in);
    cout << vIn;
    int addIn = 10;
    vIn.addElem(2, addIn);
    cout << vIn;

    // MARK: Dictionar
    pereche<string, string> *dict = new pereche<string, string>[3];
    dict[0] = pereche<string, string>("albastru", "blue");
    dict[1] = pereche<string, string>("rosu", "red");
    dict[2] = pereche<string, string>("portocaliu", "orange");

    vector<pereche<string, string>> dictionar(3, dict);
    dictionar.sortare();
    cout << dictionar;

    // MARK: Angajati
    Angajat *a = new Angajat[3];
    a[0] = Angajat("paul", "gabriel", "5040", 1);
    a[1] = Angajat("melvin", "alex", "5050", 0);
    a[2] = Angajat("mihail", "stefan", "3010", 0);

    vector<Angajat> angajati(3, a);
    angajati.sortare();
    cout << angajati;

    return 0;
}
