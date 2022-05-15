#include "cVehiculo.h"

// cVehiculo implementacion


cVehiculo::cVehiculo(string _nombre) : nombre(_nombre) { 
	this->LuO = false;
}


cVehiculo::~cVehiculo() { }

void cVehiculo::imprimir() {
	cout << to_string() << endl;
}
