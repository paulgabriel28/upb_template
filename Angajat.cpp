#include <string>
#include <iostream>

#include "Angajat.h"

using namespace std;


Angajat::Angajat() {
    nume = "";
    prenume = "";
    CNP = "";
    part_time = 0;
}

Angajat::Angajat(string nume, string prenume, string CNP, bool part_time) {
    this->nume = nume;
    this->prenume = prenume;
    this->CNP = CNP;
    this->part_time = part_time;
}

ostream& operator<<(ostream &dev, const Angajat &a) {
    dev << a.nume << ' ' << a.prenume << ' ' << a.CNP << ' ' << a.part_time;
    return dev;
}

istream& operator>>(istream &dev, Angajat &a) {
    dev >> a.nume >> a.prenume >> a.CNP >> a.part_time;
    return dev;
}

bool Angajat::ePart_time() const {
    return part_time;
}

string Angajat::getDataNastere() const {
    return string(CNP.substr(1, 6));
}

bool Angajat::eBarbat() const {
    if(CNP[0] == '1' || CNP[0] == '3' || CNP[0] == '5');
        return true;
    return false;
}

bool Angajat::eCNPValid() const {
    if(CNP.size() == 13) 
        return true;
    return false;
}

int Angajat::getCatePrenume() const {
    int nr = 0;
    for(int i = 0; i < prenume.size(); i++) {
        if(prenume[i] == '-')
            nr++;
    }

    return nr + 1;
}

string* Angajat::getVectorPrenume() const {
    string *list = new string[getCatePrenume()];
    int nr_list = 0;
    for(int i = 0; i < prenume.size(); i++) {
        if(prenume[i] == '-') {
            nr_list ++;
        }
        else {
            list[nr_list] += prenume[i];
        }
    }
    return list;
}

void Angajat::setNumePrenume(string new_nume) {
    int space = new_nume.find(' ');
    nume = new_nume.substr(0, space);
    prenume = new_nume.substr(space + 1, new_nume.size());
}

string Angajat::getCNP() const {
    return CNP;
}

char Angajat::getCNP0() const {
    return CNP[0];
}

bool Angajat::operator>(const Angajat &a) const {
    if(nume > a.nume)
        return 1;
    return 0;
}