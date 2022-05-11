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

string cCentroSalud::to_string() {
    stringstream stc;
    stc << "Nombre: " << this->nombre << endl;
    stc << "Direccion: " << this->direccion << endl;
    stc << "Partido: " << this->partido << endl;
    stc << "Provincia: " << this->provincia << endl;
    stc << "Telefono: " << this->telefono << endl;
    //stc << "Listado de vehiculos:" << endl << this->listaVehiculo->to_string() << endl;
    return stc.str();
}
