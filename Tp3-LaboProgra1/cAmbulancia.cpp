#include "cAmbulancia.h"

// cAmbulancia implementacion

cAmbulancia::cAmbulancia(string _nombre) : cVehiculo(_nombre) { }

cAmbulancia::~cAmbulancia() { }

string cAmbulancia::to_string() {
	stringstream stc;
	stc << "iuiuiuiuiu" << endl;
	stc << "La ambulancia llego al destino" << endl;
	return stc.str();
}
