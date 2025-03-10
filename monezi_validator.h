
#ifndef MONEZI_VALIDATOR_H
#define MONEZI_VALIDATOR_H
#include <stdexcept>
#include "monezi.h"
#include "domain_exception.h"
using namespace std;

class Monezi_Validator{
public:
    static void moneda_valid(Monezi & moneda){
        int cnt=0;
        vector<int> v={500,200,100,50,20,10,5,1};
        for (int i = 0; i < moneda.cap(); ++i) {
            for (int j = 0; j < v.size(); ++j) {
                if(moneda.getvalue(i)==v[j])
                  cnt++;

            }
        }
        if(cnt!=moneda.cap())
            throw Domain_Exception("Exista bancnote inexistente!");
        for (int i = 0; i < moneda.cap(); ++i) {
            if(moneda.getap(i)<0)
                throw Domain_Exception("Nr de aparitii inexistent!");
        }
    }
};
#endif

