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
		//*listaReceptores + *sujeto;
	}
	else {
		//cLista<cReceptor>* listaPrioridad = new cLista<cReceptor>[listaReceptores->cantActual];
		for (ush i = 0; i < sujeto->listaOrgano->cantActual; i++)
		{
			ush agregados = 0;
			for (ush j = 0; j < this->listaReceptores->cantActual; j++)
			{
				if (listaReceptores->lista[j]->getPrioridad() == maxima &&
					listaReceptores->lista[j]->getOrganoNecesitado() == sujeto->listaOrgano->lista[i] &&
					listaReceptores->lista[j]->getTipoSangre() == sujeto->tipoSangre) {
					agregados++;
					//*listaPrioridad + *listaReceptores->lista[j];
				}
			}

			if (agregados != 0) {
				this->match = true;
				//return listaPrioridad->lista[0];
			}
		}
	}
	return NULL;
}

void cINCUCAI::Protocolo_de_Transporte_y_Transplantes(cDonante *_donante, cReceptor *_receptor){
	if (!_donante || !_receptor) {
		throw "Error en el protocolo de transporte con algun paciente";
	}
	int pos = this->listaReceptores->buscar(_receptor);
	cVehiculo* _vehiculo = _receptor->getCentro()->getTipoVehiculo(_receptor->getCentro());
	if (_vehiculo) {
		//_donante->iniciarAblacion(_receptor->getOrganoNecesitado()); //Se le pasa el organo necesitado, puede ser el centro o 
		_vehiculo->inciarTransporte(); //imprime en pantalla el iuiu iuiu - Taca taca - fiuuuuum
		if (_receptor->inicarTranspoante(_vehiculo->getOrgano())==true) { //ademas se ve si el transplante fue exitoso
			//*this->listaReceptores - *_receptor;
		}
		else {
			_receptor->setPrioridad(maxima); //setea el 
			_receptor->SwitchEstabilidad();//cambia el estado
		}
	}
}
	





