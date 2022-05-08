#include "cCentroSalud.h"

// implementacion cCentroSalud

cCentroSalud::cCentroSalud(string _nombre, string _direccion, string _partido, string _provincia, string _telefono) :
                           nombre(_nombre), direccion(_direccion), partido(_partido), provincia(_provincia), telefono(_telefono)
{
    this->listaVehiculo = NULL;
}

cCentroSalud::~cCentroSalud() {

    // no tengo algo que elminar

}

