#include "gbl.h"
#include "cFecha.h"

// cFecha implementacion

cFecha::cFecha(string _fecha) {
	this->horaAblacion = NULL;
	this->horaTransplante = NULL;
	this->horaEspera = NULL;
	this->otraFecha = &_fecha;
}

cFecha::~cFecha() { }