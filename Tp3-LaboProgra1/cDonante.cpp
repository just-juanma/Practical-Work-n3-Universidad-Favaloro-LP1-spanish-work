#include "cDonante.h"

// cDonante implementacion

cDonante::cDonante(string _nombre, string _sexo, string _telefono) : 
			       cPaciente(_nombre, _sexo, _telefono, false) {
	this->listaOrgano = NULL;
}

cDonante::~cDonante() { }

string cDonante::to_string() {
	stringstream stc;
	stc << "Perfil del Donador:" << endl;
	stc << "Nombre: " << this->nombre << endl;
	stc << "Sexo: " << this->sexo << endl;
	stc << "Telefono: " << this->telefono << endl;
	//stc << "Listado de organos:" << endl << this->listaOrgano->to_string() << endl;
}

bool cDonante::asignarVehiculo(cVehiculo* vehiculo) {
	//continuar con la asginacion de vehiculo
}