#include "cINCUCAI.h"

// cINCUCAI implementacion

cINCUCAI::cINCUCAI() {
	this->match = false;
	this->listaDonantes = NULL;
	this->listaReceptores = NULL;
	this->listaCentros = NULL;
}

cINCUCAI::~cINCUCAI() { }

cLista<cPaciente*>* cINCUCAI::ingresarPaciente(cPaciente* paciente) {
	//cAvion* avion = dynamic_cast<cAvion*>(listaVehiculo[0].lista[i]);
	cDonante* sujeto = dynamic_cast<cDonante*>(paciente); //casteo al paciente para saber qué es
	if (sujeto == NULL)
	{
		cReceptor* sujeto = dynamic_cast<cReceptor*>(paciente);
		*listaReceptores + *sujeto; // si es un receptor lo meto al final de la lista de receptores

		cLista<cReceptor>* listaPrioridad = new cLista<cReceptor>[1]; //lista creda con la maxima cantidad posible de receptores, uno por cada donante.
		ush agregados = 0; //indice paralelo

		for (ush i = 0; i < sujeto->listaOrgano->cantActual; i++)
		{
			listaPrioridad[i] = NULL;
		}


		for (ush i = 0; i < sujeto->listaOrgano->cantActual; i++) //este for recorre la lista de organos del donante
		{
			*listaDonantes + *sujeto;
			for (ush j = 0; j < this->listaReceptores->cantActual; j++) //estos subfor recorren la lista de posibles receptores
			{
				if (listaReceptores->lista[j]->getPrioridad() == maxima && //recorro solo los de maxima prioridad
					listaReceptores->lista[j]->getOrganoNecesitado() == sujeto->listaOrgano->lista[i] &&  //filtro por organo necesitado
					listaReceptores->lista[j]->getTipoSangre() == sujeto->tipoSangre) { //filtro por tipo de sangre, repito esto para media y minima
					agregados++;
					*listaPrioridad + *listaReceptores->lista[j]; //de coincidir, lo agrego a una sublista y avanzo al siguiente organo
					break;
				}
			}
	}
	else { //si es donante voy a comenzar a entregar un receptor por cada organo.
		cLista<cReceptor>* listaPrioridad = new cLista<cReceptor>[sujeto->listaOrgano->cantActual]; //lista creda con la maxima cantidad posible de receptores, uno por cada donante.
		ush agregados = 0; //indice paralelo

		for (ush i = 0; i < sujeto->listaOrgano->cantActual; i++)
		{
			listaPrioridad[i] = NULL;
		}


		for (ush i = 0; i < sujeto->listaOrgano->cantActual; i++) //este for recorre la lista de organos del donante
		{
			for (ush j = 0; j < this->listaReceptores->cantActual; j++) //estos subfor recorren la lista de posibles receptores
			{
				if (listaReceptores->lista[j]->getPrioridad() == maxima && //recorro solo los de maxima prioridad
					listaReceptores->lista[j]->getOrganoNecesitado() == sujeto->listaOrgano->lista[i] &&  //filtro por organo necesitado
					listaReceptores->lista[j]->getTipoSangre() == sujeto->tipoSangre) { //filtro por tipo de sangre, repito esto para media y minima
					agregados++;
					*listaPrioridad + *listaReceptores->lista[j]; //de coincidir, lo agrego a una sublista y avanzo al siguiente organo
					break;
				}
			}

			//if (agregados != 0) { //si no se agrego ninguno avanza hacia la siguiente prioridad
			//	this->match = true;
			//	return listaPrioridad->lista[0];
			//}

			for (ush j = 0; j < this->listaReceptores->cantActual; j++)
			{
				if (listaReceptores->lista[j]->getPrioridad() == media &&
					listaReceptores->lista[j]->getOrganoNecesitado() == sujeto->listaOrgano->lista[i] &&
					listaReceptores->lista[j]->getTipoSangre() == sujeto->tipoSangre) {
					agregados++;
					*listaPrioridad + *listaReceptores->lista[j];
					break;
				}
			}

			//if (agregados != 0) {
			//	this->match = true;
			//	return listaPrioridad->lista[0];
			//}

			for (ush j = 0; j < this->listaReceptores->cantActual; j++)
			{
				if (listaReceptores->lista[j]->getPrioridad() == minima &&
					listaReceptores->lista[j]->getOrganoNecesitado() == sujeto->listaOrgano->lista[i] &&
					listaReceptores->lista[j]->getTipoSangre() == sujeto->tipoSangre) {
					agregados++;
					*listaPrioridad + *listaReceptores->lista[j];
					break;
				}
			}

			//if (agregados != 0) {
			//	this->match = true;
			//	return listaPrioridad->lista[0];
			//}
			//else if (agregados == 0) return NULL;
		}
		//return listaPrioridad*;
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
