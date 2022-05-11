#include "cINCUCAI.h"

// cINCUCAI implementacion

cINCUCAI::cINCUCAI(bool _match) {
	this->match = _match;
}

cINCUCAI::~cINCUCAI() {

	// no tengo algo que eliminar

}

void cINCUCAI::Protocolo_de_Transporte_y_Transplantes(cDonante* donante, cReceptor* receptor,cVehiculo* vehiculo) {
	int pos = this->listaReceptores->buscar(receptor);
	if (donante->asignarVehiculo(vehiculo) == true) {
		donante->iniciarAblacion(receptor); //Se le pasa quien va ser receptor para asi saber que organo pasarle
		donante->inciarTransporte(); //imprime en pantalla el iuiu iuiu - Taca taca - fiuuuuum
		if (receptor->inicarTranspoante(donante) == true) { //ademas se ve si el transplante fue exitoso
			this->listaReceptores->quitar(receptor);
		}
		else {
			receptor->serPrioridad("la mas alta"); //setea el 
			receptor->cambiarEstado();//setea el estado a inestable
		}
	}
}