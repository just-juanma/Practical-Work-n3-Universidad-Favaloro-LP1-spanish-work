#include "cDonante.h"

// cDonante implementacion

cDonante::cDonante(string _nombre, string _sexo, string _telefono) :
			       cPaciente(_nombre, _sexo, _telefono, false) {
	this->muerte = NULL;
	this->listaOrgano = NULL;
	this->ablacion = NULL;
}

cDonante::~cDonante() { }

string cDonante::to_string() {
	stringstream stc;
	stc << "Perfil del Donador:" << endl;
	stc << "Nombre: " << this->nombre << endl;
	stc << "Sexo: " << this->sexo << endl;
	stc << "Telefono: " << this->telefono << endl;
	stc << "Listado de organos:" << endl << this->listaOrgano->to_string() << endl;
	return stc.str();
}


cOrgano* cDonante::iniciarAblacion(cOrgano* receptor, cFecha* fecha)
{


}