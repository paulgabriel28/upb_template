#pragma once

#include <string>
#include <iostream>

using namespace std;

class Angajat{
    string nume;
    string prenume; //daca are 2 sau mai multe prenume, acestea sunt legate cu -: Ana-Maria
    string CNP;
    bool part_time; //true daca e part_time, false altfel

public:
    //constructor fara parametri
    Angajat();
    
    //constructor cu parametri
    Angajat(string, string, string, bool);
    
    //supradefinirea operatorului de extragere
    //atributele sunt afisate pe aceeasi linie, cu spatii intre ele, la final se trece la linie noua
    friend ostream& operator<<(ostream &, const Angajat & );
    
    /*supradefinirea operatorului de insertie; valorile pentru atribute sunt citite considerand ca au spatiu intre ele*/
    friend istream& operator>>(istream &, Angajat & );
    
    //returneaza valoarea atributului part_time
    bool ePart_time()const;
    
    //returneaza data de nastere din CNP ca string, in formatul din CNP: aallzz
    string getDataNastere() const;
    
     //returneaza true daca prima cifra din CNP este 1, 3, sau 5
    bool eBarbat() const;
    
    /*testeaza daca true daca CNP-ul are exact 13 caractere si returneaza true daca aceasta e lungimea stringului si false altfel*/
    bool eCNPValid() const;
    
    //returneaza numarul de prenume ale persoanei
    int getCatePrenume() const;
    
    //returneaza un vector care contine prenumele - sub forma de vector de stringuri
    string* getVectorPrenume()const;
    
    //returneaza un string in care se gasesc concatenate numele si prenumele: Popescu Marin-Ion
    string getNumeComplet()const;
    
    /*se primeste ca parametru un string care contine numele si prenumele separate prin spatiu: : Popescu Marin-Ion; sunt extrase numele si respectiv prenumele din acest string si folosite sa modifice numele si prenumele unei persoane*/
    void setNumePrenume(string);

    // returneaza CNP
    string getCNP() const;

    // returneaza secolul
    char getCNP0() const;

    // operator=
    Angajat& operator=(const Angajat &) = default;

    // MARK: operator> [15.05.2024]
    bool operator>(const Angajat &) const;
};

