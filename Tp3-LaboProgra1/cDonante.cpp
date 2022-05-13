#include "cDonante.h"

// cDonante implementacion

cDonante::cDonante(string _nombre, string _sexo, string _telefono, cFecha* _nacimiento, eTipoSangre _tipo) :
			       cPaciente(_nombre, _sexo, _telefono, _nacimiento, _tipo, false) {
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
	stc << "Fecha de nacimiento: " << this->nacimiento->getFecha();
	if (muerte)
		stc << "Fecha de muerte: " << this->muerte->getFecha();
	if (ablacion)
		stc << "Fecha de ablacion: " << this->ablacion->getFecha();
	if(listaOrgano)
		stc << "Listado de organos:" << endl << this->listaOrgano->to_string() << endl;
	return stc.str();
}
