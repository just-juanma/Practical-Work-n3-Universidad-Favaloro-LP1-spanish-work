#include "cPaciente.h"

 // cPaciente implementacion


cPaciente::cPaciente(string _nombre, string _sexo, string _telefono, bool _RoD) : nombre(_nombre), sexo(_sexo), telefono(_telefono) {
    this->RoD = _RoD;
}

cPaciente::~cPaciente() {

    // no tengo algo que eliminar

}