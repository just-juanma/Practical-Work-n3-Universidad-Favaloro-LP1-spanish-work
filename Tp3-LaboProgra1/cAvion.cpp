#include "cAvion.h"

// cAvion implementacion

cAvion::cAvion(string _nombre) : cVehiculo(_nombre) { }

cAvion::~cAvion() { }

string cAvion::to_string() {
        stringstream stc;
        stc << "IUIUIU:" << endl;
        stc << "llego al destino:" << endl;
        return stc.str();
}