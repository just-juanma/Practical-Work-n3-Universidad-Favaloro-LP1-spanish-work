#pragma once
#include "cVehiculo.h"
class cAvion : public cVehiculo{
    string to_string() {
        stringstream stc;
        stc << "IUIUIU:" << endl;
        stc << "llego al destino:" << endl;
        return stc.str();
    }
};

