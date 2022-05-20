#include "cOrgano.h"

// cOrgano implementacion

cOrgano::cOrgano(eOrgano _organo) {
	this->organo = _organo;
	this->ablacion = NULL;
}

cOrgano::~cOrgano() { }

string cOrgano::to_string() {
	stringstream stc;
	switch (organo) {
	case 0:
		stc << "Desconocido" << endl;
		break;
	case 1:
		stc << "Corazon" << endl;
		break;
	case 2:
		stc << "Higado" << endl;
		break;
	case 3:
		stc << "Pancreas" << endl;
		break;
	case 4:
		stc << "Huesos" << endl;
		break;
	case 5:
		stc << "Rinion" << endl;
		break;
	case 6:
		stc << "Pulmones" << endl;
		break;
	case 7:
		stc << "Intestino" << endl;
		break;
	case 8:
		stc << "Piel" << endl;
		break;
	case 9:
		stc << "Cornea" << endl;
		break;
	}
	return stc.str();
}