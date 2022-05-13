#include "cPaciente.h"

 // cPaciente implementacion

cPaciente::cPaciente(string _nombre, string _sexo, string _telefono, cFecha* _nacimiento, eTipoSangre _tipo, bool _RoD) : 
                     nombre(_nombre), sexo(_sexo), telefono(_telefono) {
    this->RoD = _RoD;
    this->nacimiento = _nacimiento;
    this->tipoSange = _tipo;
    this->centroSalud = NULL;

}

cPaciente::~cPaciente() {

    // no tengo algo que eliminar

}