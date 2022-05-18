#include "cINCUCAI.h"

// cINCUCAI implementacion

cINCUCAI::cINCUCAI() {
	this->match = false;
	this->listaDonantes = NULL;
	this->listaReceptores = NULL;
	this->listaCentros = NULL;
}

cINCUCAI::~cINCUCAI() { }
/*
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
	}*/

void cINCUCAI::Protocolo_de_Transporte_y_Transplantes(cOrgano *_organo, cReceptor *_receptor){
	if (!_organo || !_receptor) {
		throw "Error en el protocolo de transporte con algun paciente";
	}
	int pos = this->listaReceptores->buscar(_receptor);
	cVehiculo* _vehiculo = _receptor->getCentro()->getTipoVehiculo(_receptor->getCentro());
	if (_vehiculo) {
		_vehiculo->setOrgano(_organo); //Se le pasa el organo necesitado, para ser transportado 
		_vehiculo->inciarTransporte(); //imprime en pantalla el iuiu iuiu - Taca taca - fiuuuuum
		if (_receptor->inicarTransplante(_vehiculo->getOrgano())==true) { //ademas se ve si el transplante fue exitoso
			*this->listaReceptores - _receptor;
		}
		else {
			_receptor->setPrioridad(maxima); //setea el 
			_receptor->SwitchEstabilidad();//cambia el estado
		}
	}
}

cLista<cOrgano>* cINCUCAI::Ablacion(cDonante* _dontante) {
	if (!_dontante) throw "Donante invalido";
	return _dontante->iniciarAblacion();
}





