

#ifndef PRODUS_H
#define PRODUS_H
#include <iostream>
using namespace std;
class Produs{
private:
    string cod;
    string nume;
    int pret;
public:
    Produs() {
        this->cod= nullptr;
        this->nume= nullptr;
        this->pret=0;
    }

    Produs(const string &cod, const string &nume, int pret) : cod(cod), nume(nume), pret(pret) {}

    virtual ~Produs() {}

    const string &getCod() const {
        return cod;
    }

    const string &getNume() const {
        return nume;
    }

    int getPret() const {
        return pret;
    }

    void setCod(const string &cod) {
        Produs::cod = cod;
    }

    void setNume(const string &nume) {
        Produs::nume = nume;
    }

    void setPret(int pret) {
        Produs::pret = pret;
    }

    bool operator==(const Produs &rhs) const {
        return cod == rhs.cod &&
               nume == rhs.nume &&
               pret == rhs.pret;
    }

    bool operator!=(const Produs &rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const Produs &rhs) const {
        if (cod < rhs.cod)
            return true;
        if (rhs.cod < cod)
            return false;
        if (nume < rhs.nume)
            return true;
        if (rhs.nume < nume)
            return false;
        return pret < rhs.pret;
    }

    bool operator>(const Produs &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Produs &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Produs &rhs) const {
        return !(*this < rhs);
    }

    Produs operator=(const Produs &p){
        this->cod=p.getCod();
        this->nume=p.getNume();
        this->pret=p.getPret();
        return *this;
    }

    friend ostream &operator<<(ostream &os, const Produs &produs) {
        os << "cod: " << produs.cod << " nume: " << produs.nume << " pret: " << produs.pret;
        return os;
    }

};

#endif
