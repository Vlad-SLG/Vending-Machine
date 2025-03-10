
#ifndef REPO_FILE_H
#define REPO_FILE_H

#include "repo.h"
#include <fstream>
#include <iostream>

using namespace std;

class Repo_File : public Repo {
private:
    string file_int;
    string file_out;
public:
    Repo_File() : Repo() {}

    Repo_File(const string &fin, const string &fout) : file_int(fin), file_out(fout) {}

    int file_prodsize() {
        ifstream f(file_int);
        string cod, nume;
        int pret;
        while (f >> cod >> nume >> pret) {
            Produs p(cod, nume, pret);
            add_produs(p);
        }
        f.close();
        return Repo::getsize_produse();

    }

    int file_monezisize() {
        ifstream f(file_int);
        vector<int> v1;
        vector<int> v2;
        int x, y;
        while (f >> x >> y) {
            v1.push_back(x);
            v2.push_back(y);
        }
        Monezi m(v1, v2);
        add_monezi(m);
        f.close();
        return Repo::getsize_monezi();

    }

    int suma_monezi(){
        int suma;
        ifstream f(file_int);
        int x,y;
        while(f>>x>>y)
            suma=suma+x*y;
        return suma;
    }

    void ad_produs(const vector<Produs> &p) {
        Repo::add_produse(p);
        save_produse();
    }
    void ad_moneda(const Monezi &m) {
        Repo::add_monezi(m);
        save_monezi();
    }
    void remove_produs(int i){
        delete_produs(i);
        save_produse();
    }

    void load_monezi() {
        ifstream f(file_int);
        vector<int> v1;
        vector<int> v2;
        int x, y;
        while (f >> x >> y) {
            v1.push_back(x);
            v2.push_back(y);
        }
        Monezi m(v1, v2);
        ad_moneda(m);
        f.close();
    }


    void load_produse() {
        ifstream f(file_int);
        vector<Produs> P;
        string cod, nume;
        int pret;
        while (f >> cod >> nume >> pret) {
            Produs p(cod, nume, pret);
            P.push_back(p);
        }
        ad_produs(P);
        f.close();
    }

    void save_produse() {
        ofstream g(file_out);
        for (int i = 0; i < p.size(); ++i) {
            g << "Produs:" << p[i] << endl;
        }
        g.close();
    }

    void save_monezi() {
        ofstream g(file_out);
        g << m;
        g.close();
    }

};

#endif

