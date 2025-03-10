
#ifndef MONEZI_H
#define MONEZI_H

#include <iostream>
#include <vector>

using namespace std;

class Monezi {
private:
    vector<int> v1;
    vector<int> v2;
public:
    Monezi() {
        v1 = {};
        v2 = {};
    }

    Monezi(vector<int> x, vector<int> y) : v1(x), v2(y) {}

    int getap(int value) {
        for (int i = 0; i < v1.size(); ++i)
            if (v1[i] == value)
                return v2[i];
        return 0;
    }

    int getvalue(int key) {
        return v1[key];
    }

    void decrease_moneda(int i) {
        v2[i]--;
    }

    void set_ap(int i, int value) {
        v2[i] = value;
    }

    int cap() {
        return v1.size();
    }

    void add_moneda(int moneda) {
        for (int i = 0; i < v1.size(); ++i) {
            if (v1[i] == moneda) {
                v2[i]++;
                return;
            }
        }
        v1.push_back(moneda);
        v2.push_back(1);
    }

    friend ostream &operator<<(ostream &os, const Monezi &monezi) {
        for (int i = 0; i < monezi.v1.size(); ++i) {
            os << monezi.v1[i] << ":" << monezi.v2[i] << endl;
        }
        return os;
    }

};

#endif
