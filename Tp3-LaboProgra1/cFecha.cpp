#include "gbl.h"
#include "cFecha.h"

// cFecha implementacion

cFecha::cFecha(time_t _horaAblacion) {
	this->horaAblacion = &_horaAblacion;
	this->horaTransplante = NULL;
}

cFecha::~cFecha() { }