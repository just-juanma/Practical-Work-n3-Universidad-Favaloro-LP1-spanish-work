#include "cPaciente.h"

 // cPaciente implementacion

cPaciente::cPaciente(string _nombre, string _sexo, string _telefono, cFecha* _nacimiento, eTipoSangre _tipo) : 
                     nombre(_nombre), sexo(_sexo), telefono(_telefono) {
    this->nacimiento = _nacimiento;
    this->tipoSangre = _tipo;
    this->centroSalud = NULL;

}

cPaciente::~cPaciente() { }
