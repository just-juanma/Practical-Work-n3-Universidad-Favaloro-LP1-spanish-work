#include "cVehiculo.h"

// cVehiculo implementacion


cVehiculo::cVehiculo(eVehiculo _vehiculo) {
	this->vehiculo = _vehiculo;
}

cVehiculo::~cVehiculo() { 

	// no tengo algo que eliminar

}

string cVehiculo::to_string() {
	stringstream stc;
	switch (vehiculo) {
	case 0:
		stc << "Sin vehiculo" << endl;
		break;
	case 1:
		stc << "Ambulancia" << endl;
		break;
	case 2:
		stc << "Helicoptero" << endl;
		break;
	case 3:
		stc << "Avion" << endl;
		break;
	}
	return stc.str();
}
