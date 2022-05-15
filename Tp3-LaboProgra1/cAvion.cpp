#include "cAvion.h"

// cAvion implementacion

cAvion::cAvion(string _nombre) : cVehiculo(_nombre) { }

cAvion::~cAvion() { }

string cAvion::to_string() {
        stringstream stc;
        stc << "zhooooooom" << endl;
        stc << "El avion llego al destino" << endl;
        return stc.str();
}