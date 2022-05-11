#include "cReceptor.h"

// cReceptor implementacion

cReceptor::cReceptor(string _nombre, string _sexo, string _telefono, string _patologia) :
	cPaciente(_nombre, _sexo, _telefono, false) {
	this->patologia = _patologia;
	this->organoNecesario = NULL;
	this->fechaListaEnEspera = NULL;
}

cReceptor::~cReceptor() { }

string cReceptor::to_string() {
	stringstream stc;
	stc << "Perfil del Receptor:" << endl;
	stc << "Nombre: " << this->nombre << endl;
	stc << "Sexo: " << this->sexo << endl;
	stc << "Telefono: " << this->telefono << endl;
	stc << "Patologia: " << this->patologia << endl;
	return stc.str();
}