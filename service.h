

#ifndef SERVICE_H
#define SERVICE_H

#include "repo.h"

class Service {
private:
    Repo repo;
public:
    Service() {
        repo = Repo();
    }

    Service(const Repo &rep) {
        repo = rep;
    }

    Repo getall() {
        return repo;
    }

    int prod_size() {
        return repo.getsize_produse();
    }

    Produs getprod(int i) {
        return repo.getprodus(i);
    }

    void add_produs(const Produs &prod) {
        repo.add_produs(prod);
    }

    void add_moneda(int value) {
        repo.add_moneda(value);
    }

    int plata(int option, int suma) {
        Produs p = repo.getprodus(option);
        if (suma <= 0 or suma < p.getPret())
            return 0;
        if (suma == p.getPret()) {
            for (int i = 0; i < repo.getsize_monezi(); ++i) {
                if (suma == repo.getmoneda(i)) {
                    repo.decrease(i);
                    repo.delete_produs(option);
                    return 1;
                }
            }
            for (int i = 0; i < repo.getsize_monezi(); ++i) {
                int c = suma / repo.getmoneda(i);
                if (c != 0) {
                    suma = suma - min(c, repo.getapa_moneda(i)) * repo.getmoneda(i);
                    repo.setap_moneda(i, repo.getapa_moneda(i) - min(c, repo.getapa_moneda(i)));
                }
            }
            if (suma == 0) {
                repo.delete_produs(option);
                return 1;
            }
        else return 9999;
        }
        vector<int> v;
        v.reserve(repo.getsize_monezi());
        for (int i = 0; i < repo.getsize_monezi(); ++i)
            v.push_back(0);

        if (suma > p.getPret()) {
            int rest = suma - p.getPret();
            int crest = rest;
            for (int i = 0; i < repo.getsize_monezi(); ++i) {
                if (rest == repo.getmoneda(i)) {
                    repo.decrease(i);
                    repo.delete_produs(option);
                    return rest;
                }
            }
            for (int i = 0; i < repo.getsize_monezi() && crest != 0; ++i) {
                int c = crest / repo.getmoneda(i);
                if (c != 0) {
                    crest = crest - min(c, repo.getapa_moneda(repo.getmoneda(i))) * repo.getmoneda(i);
                    v[i] = min(c, repo.getapa_moneda(repo.getmoneda(i)));
                }
            }
            if (crest == 0) {
                for (int i = 0; i < repo.getsize_monezi(); ++i) {
                    repo.setap_moneda(i, repo.getapa_moneda(repo.getmoneda(i)) - v[i]);
                }
                repo.delete_produs(option);
                return rest;
            }
        }
        return 0;
    }

};

#endif
