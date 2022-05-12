#include "gbl.h"
#include "cFecha.h"

// cFecha implementacion

cFecha::cFecha(time_t _fecha) {
	this->fecha = &_fecha;
}

cFecha::~cFecha() { }