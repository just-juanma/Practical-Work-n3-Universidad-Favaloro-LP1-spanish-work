#include "cINCUCAI.h"

// cINCUCAI implementacion

cINCUCAI::cINCUCAI() {
	this->match = false;
	this->listaDonantes = NULL;
	this->listaReceptores = NULL;
	this->listaCentros = NULL;
}

cINCUCAI::~cINCUCAI() {

	// no tengo algo que eliminar

}

//
//void cINCUCAI::Protocolo_de_Transporte_y_Transplantes(cDonante* _donante, cReceptor* _receptor) {
//	
//	int pos = this->listaReceptores->buscar(_receptor);
//	cVehiculo* vehic= _donante->getCentro()->gettipovehiculo(_receptor->getCentro());
//	cVehiculo* _vehiculo;
//	if (vehic == avion) {
//		cAvion* _avion = new cAvion;
//		_vehiculo = _avion;
//	}
//	else if (vehic == helicoptero) {
//		cHelicoptero* _Helicoptero = new cHelicoptero;
//		_vehiculo = _Helicoptero;
//	}
//	else {
//		cAmbulancia* _Ambulancia = new cAmbulancia;
//		_vehiculo = _Ambulancia;
//	}
//	if (_donante->asignarVehiculo(_vehiculo) == true) {
//		_donante->iniciarAblacion(_receptor->getOrganoNecesitado()); //Se le pasa quien va ser receptor para asi saber que organo pasarle
//		_donante->inciarTransporte(); //imprime en pantalla el iuiu iuiu - Taca taca - fiuuuuum
//		if (_receptor->inicarTranspoante(_donante) == true) { //ademas se ve si el transplante fue exitoso
//			this->listaReceptores->quitar(_receptor);
//		}
//		else {
//			_receptor->serPrioridad("la mas alta"); //setea el 
//			_receptor->cambiarEstado();//setea el estado a inestable
//		}
//	}
//}
