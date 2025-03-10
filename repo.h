

#ifndef REPO_H
#define REPO_H

#include <vector>
#include "produs.h"
#include "monezi.h"
#include <iostream>

using namespace std;

class Repo {
protected:
    vector<Produs> p;
    Monezi m;
public:
    Repo() {
        p = {};
        m = Monezi();
    }

    Repo(const vector<Produs> &P, const Monezi &M) : p(P), m(M) {}

    void add_produs(const Produs &prod) {
        p.push_back(prod);
    }

    void add_produse(const vector<Produs>& P){
        p.reserve(P.size());
        p=P;
    }

    void add_monezi(const Monezi &moneda) {
        m = moneda;
    }

    int getsize_produse() {
        return p.size();
    }

    int getsize_monezi() {
        return m.cap();
    }

    int summax() {
        int suma;
        for (int i = 0; i < m.cap(); ++i) {
            suma = suma + m.getvalue(i) * m.getap(m.getvalue(i));
        }
        return suma;
    }

    Produs getprodus(int i) {
        return p[i];
    }

    void add_moneda(int moneda) {
        m.add_moneda(moneda);
    }

    int getmoneda(int i) {
        return m.getvalue(i);
    }

    int getapa_moneda(int i) {
        return m.getap(i);
    }

    void setap_moneda(int i, int value) {
        m.set_ap(i, value);
    }

    void decrease(int i) {
        m.decrease_moneda(i);
    }

    vector<Produs> getprodue() {
        return p;
    }

    void delete_produs(int i) {
        p.erase(p.begin() + i, p.end() - (p.size() - i) + 1);
    }

    Monezi getmonezi() {
        return m;
    }

    friend ostream &operator<<(ostream &os, const Repo &repo) {
        for (int i = 0; i < repo.p.size(); ++i) {
            os << "Produs: " << repo.p[i] << endl;
        }
        os << "Monezi: " <<endl << repo.m;
        return os;
    }
};

#endif

