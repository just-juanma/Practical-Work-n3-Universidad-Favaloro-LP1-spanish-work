#include "cCentroSalud.h"

// implementacion cCentroSalud

cCentroSalud::cCentroSalud(string _nombre, string _direccion, string _partido, string _provincia, string _telefono) :
                           nombre(_nombre), direccion(_direccion), partido(_partido), provincia(_provincia), telefono(_telefono)
{
    this->listaVehiculo = NULL;
    this->cantDonProv = 0;
}

cCentroSalud::~cCentroSalud() { }

cVehiculo* cCentroSalud::getTipoVehiculo(cCentroSalud* centroReceptor) {
    // si es la misma provincia
    if (centroReceptor->provincia == this->provincia) {
        cantDonProv++;
        // si es el mismo partido
        if (centroReceptor->partido == this->partido) {
            for (ush i = 0; i < listaVehiculo->cantActual; i++) {
                // verifico que este libre para usar y que exista el puntero
                if (listaVehiculo->lista[i]->getLuO() == true && listaVehiculo->lista[i]) {
                    // trato de conseguir la ambulancia
                    cAmbulancia* ambulancia = dynamic_cast<cAmbulancia*>(listaVehiculo->lista[i]);
                    // si consigo el casteo, retorno la ambulancia
                    if (ambulancia) {
                        ambulancia->setLuO(false);
                        return ambulancia;
                    }
                        
                }
            }
        }
        // si es otro partido
        else {
            //busco al primer helicopetro que encuentre
            for (ush i = 0; i < listaVehiculo->cantActual; i++) {
                // verifico que este libre para usar y que exista el puntero
                if (listaVehiculo->lista[i]->getLuO() == true && listaVehiculo[0].lista[i]) {
                    // trato de conseguir el helicoptero
                    cHelicoptero* helicoptero = dynamic_cast<cHelicoptero*>(listaVehiculo[0].lista[i]);
                    // si consigo el casteo, retorno el helicoptero
                    if (helicoptero) {
                        helicoptero->setLuO(false);
                        return helicoptero;
                    }
                }
            }
        }

    }
    // si es otra provincia
    else {
        //busco al primer avion que encuentre
        for (ush i = 0; i < listaVehiculo->cantActual; i++) {
            // verifico que este libre para usar y que exista el puntero
            if (listaVehiculo->lista[i]->getLuO() == true && listaVehiculo->lista[i]) {
                // trato de conseguir el avion
                cAvion* avion = dynamic_cast<cAvion*>(listaVehiculo->lista[i]);
                // si consigo el casteo, retorno el avion
                if (avion) {
                    avion->setLuO(false);
                    return avion;
                    }

            }
        }
    }
    // si no encontro el vehiculo necesario, no hay vehiculos
    return NULL;
}


string cCentroSalud::to_string() {
    stringstream stc;
    stc << "Nombre: " << this->nombre << endl;
    stc << "Direccion: " << this->direccion << endl;
    stc << "Partido: " << this->partido << endl;
    stc << "Provincia: " << this->provincia << endl;
    stc << "Telefono: " << this->telefono << endl;
    if(listaVehiculo)
        stc << "Listado de vehiculos:" << endl << this->listaVehiculo->to_string() << endl;
    return stc.str();
}