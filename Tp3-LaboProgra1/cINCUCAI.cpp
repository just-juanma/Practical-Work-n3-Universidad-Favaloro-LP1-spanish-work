#include "cINCUCAI.h"

// cINCUCAI implementacion

cINCUCAI::cINCUCAI() {
	this->match = false;
	this->listaDonantes = NULL;
	this->listaReceptores = NULL;
	this->listaCentros = NULL;
}

cINCUCAI::~cINCUCAI() { }

cPaciente* cINCUCAI::ingresarPaciente(cPaciente* paciente) {
	//cAvion* avion = dynamic_cast<cAvion*>(listaVehiculo[0].lista[i]);
	cDonante* sujeto = dynamic_cast<cDonante*>(paciente);
	if (sujeto == NULL)
	{
		cReceptor* sujeto = dynamic_cast<cReceptor*>(paciente);
		*listaReceptores + *sujeto;
	}
	else {
		cLista<cReceptor>* listaPrioridad = new cLista<cReceptor>[listaReceptores->cantActual];
		for (ush i = 0; i < sujeto->listaOrgano->cantActual; i++)
		{
			ush agregados = 0;
			for (ush j = 0; j < this->listaReceptores->cantActual; j++)
			{
				if (listaReceptores->lista[j]->getPrioridad() == maxima &&
					listaReceptores->lista[j]->getOrganoNecesitado() == sujeto->listaOrgano->lista[i] && 
					listaReceptores->lista[j]->getTipoSangre() == sujeto->tipoSangre) {
					agregados++;
					listaPrioridad->lista[agregados]= listaReceptores->lista[j];
				}
			}

			if (agregados != 0) {
				this->match = true;
				return listaPrioridad->lista[0];
			}

			for (ush j = 0; j < this->listaReceptores->cantActual; j++)
			{
				if (listaReceptores->lista[j]->getPrioridad() == media &&
					listaReceptores->lista[j]->getOrganoNecesitado() == sujeto->listaOrgano->lista[i] &&
					listaReceptores->lista[j]->getTipoSangre() == sujeto->tipoSangre) {
					agregados++;
					listaPrioridad->lista[agregados] = listaReceptores->lista[j];
				}
			}

			if (agregados != 0) {
				this->match = true;
				return listaPrioridad->lista[0];
			}

			for (ush j = 0; j < this->listaReceptores->cantActual; j++)
			{
				if (listaReceptores->lista[j]->getPrioridad() == minima &&
					listaReceptores->lista[j]->getOrganoNecesitado() == sujeto->listaOrgano->lista[i] &&
					listaReceptores->lista[j]->getTipoSangre() == sujeto->tipoSangre) {
					agregados++;
					listaPrioridad->lista[agregados] = listaReceptores->lista[j];
				}
			}

			if (agregados != 0) {
				this->match = true;
				return listaPrioridad->lista[0];
			}

			else if (agregados == 0) return NULL;

		}
	}
}






//
//void cINCUCAI::Protocolo_de_Transporte_y_Transplante(cDonante* _donante, cReceptor* _receptor) {
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
