
#ifndef PRODUS_VALIDATOR_H
#define PRODUS_VALIDATOR_H
#include <stdexcept>
#include "produs.h"
#include "domain_exception.h"
using namespace std;

class Produs_Validator{
public:
    static void validate(const Produs& produs){
        if(produs.getCod()<"0")
            throw Domain_Exception("Codul nu este valid!");
        if(produs.getPret()<0)
            throw Domain_Exception("Pretul este incorect!");
    }
};
#endif

