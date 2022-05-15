#include "cHelicoptero.h"

// cHelicoptero implementacion

cHelicoptero::cHelicoptero(string _nombre) : cVehiculo(_nombre) { }

cHelicoptero::~cHelicoptero() { }

string cHelicoptero::to_string() {
	stringstream stc;
	stc << "taca-taca-taca" << endl;
	stc << "El helicoptero llego al destino" << endl;
	return stc.str();
}
