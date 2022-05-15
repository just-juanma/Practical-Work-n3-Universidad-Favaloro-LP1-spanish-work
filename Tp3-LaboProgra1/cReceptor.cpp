#include "cReceptor.h"

// cReceptor implementacion

cReceptor::cReceptor(string _nombre, string _sexo, string _telefono, string _patologia,cOrgano* _organoNecesario) :
	cPaciente(_nombre, _sexo, _telefono, false) {
	this->patologia = _patologia;
	this->organoNecesario = _organoNecesario;

}

cReceptor::~cReceptor() { }

bool cReceptor::inicarTranspoante(cOrgano* _organotransportado)
{
	this->organoNecesario = _organotransportado; 
	float azar = rand()%1;
	if (azar > (1 / 2)) {
		return true;
	}
	else {
		return false;
	}
}

string cReceptor::to_string() {
	stringstream stc;
	stc << "Perfil del Receptor:" << endl;
	stc << "Nombre: " << this->nombre << endl;
	stc << "Sexo: " << this->sexo << endl;
	stc << "Telefono: " << this->telefono << endl;
	stc << "Patologia: " << this->patologia << endl;
	return stc.str();
}