#include "gbl.h"
#include "cFecha.h"

// cFecha implementacion

cFecha::cFecha(string _fecha) {
	*this->fecha = _fecha; //this->fecha = &_fecha; porque no esto?
}

cFecha::~cFecha() { }