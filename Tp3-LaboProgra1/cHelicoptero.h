#pragma once
#include "cVehiculo.h"
class cHelicoptero : public cVehiculo {
    string to_string() {
        stringstream stc;
        stc << "TACA TACA TACA:"<< endl;
        stc << "llego al destino:" << endl;
        return stc.str();
    }
};

