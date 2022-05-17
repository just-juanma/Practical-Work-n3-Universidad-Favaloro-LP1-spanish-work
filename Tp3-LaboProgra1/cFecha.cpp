#include "cFecha.h"

// cFecha implementacion

cFecha::cFecha(string _fecha) {
	this->fecha = &_fecha; 
	this->ablacion = 0;
}

cFecha::~cFecha() { }

string cFecha::to_string() {
	stringstream stc;
	stc << "Fecha: " << this->fecha;
	return stc.str();
}