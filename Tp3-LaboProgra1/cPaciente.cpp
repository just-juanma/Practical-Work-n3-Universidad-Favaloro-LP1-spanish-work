#include "cPaciente.h"

 // cPaciente implementacion

cPaciente::cPaciente(string _nombre, string _sexo, string _telefono, cFecha* _nacimiento, eTipoSangre _tipo, bool _RoD) : 
                     nombre(_nombre), sexo(_sexo), telefono(_telefono) {
    this->RoD = _RoD;
    this->nacimiento = _nacimiento;
    this->tipoSangre = _tipo;
    this->centroSalud = NULL;

}

cPaciente::~cPaciente() { }
