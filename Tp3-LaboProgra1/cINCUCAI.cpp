#include "cINCUCAI.h"

// cINCUCAI implementacion

cINCUCAI::cINCUCAI() {
	this->match = false;
	this->listaDonantes = NULL;
	this->listaReceptores = NULL;
	this->listaCentros = NULL;
}

cINCUCAI::~cINCUCAI() { }

void cINCUCAI::recibirPaciente(cPaciente* paciente)
{
	ingresarPaciente(paciente);
}

void cINCUCAI::ingresarPaciente(cPaciente* paciente) {

	agregarPaciente(paciente);

	cDonante* sujeto = dynamic_cast<cDonante*>(paciente); //casteo al paciente para saber qué es
	if (sujeto == NULL)
	{
		cReceptor* sujeto = dynamic_cast<cReceptor*>(paciente);
		for (ush i = 0; i < this->listaDonantes->cantActual; i++)
		{
			for (ush j = 0; j < this->listaDonantes->lista[j]->listaOrgano->cantActual; j++)
			{
				if (sujeto->getOrganoNecesitado() == listaDonantes->lista[j]->listaOrgano->lista[j] &&
					sujeto->getTipoSangre() == listaDonantes->lista[j]->tipoSangre)
					Protocolo_de_Transporte_y_Transplantes(listaDonantes->lista[j]->listaOrgano->lista[j], sujeto);
			}
		}
		
	}

	bool agregado;

	for (ush i = 0; i < sujeto->listaOrgano->cantActual; i++) //este for recorre la lista de organos del donante
	{
		agregado=false;
		for (ush j = 0; j < this->listaReceptores->cantActual; j++) //estos subfor recorren la lista de posibles receptores
		{
			if (this->listaReceptores->lista[j]->getPrioridad() == maxima && //recorro solo los de maxima prioridad
				this->listaReceptores->lista[j]->getOrganoNecesitado() == sujeto->listaOrgano->lista[i] &&  //filtro por organo necesitado
				this->listaReceptores->lista[j]->getTipoSangre() == sujeto->tipoSangre) { //filtro por tipo de sangre, repito esto para media y minima
				Protocolo_de_Transporte_y_Transplantes(sujeto->listaOrgano->lista[i], listaReceptores->lista[j]);
				agregado=true;
				break;
			}
		}


		if (agregado != true)
		{
			for (ush j = 0; j < this->listaReceptores->cantActual; j++) //estos subfor recorren la lista de posibles receptores
			{
				if (this->listaReceptores->lista[j]->getPrioridad() == media && //recorro solo los de maxima prioridad
					this->listaReceptores->lista[j]->getOrganoNecesitado() == sujeto->listaOrgano->lista[i] &&  //filtro por organo necesitado
					this->listaReceptores->lista[j]->getTipoSangre() == sujeto->tipoSangre){ //filtro por tipo de sangre, repito esto para media y minima
					Protocolo_de_Transporte_y_Transplantes(sujeto->listaOrgano->lista[i], listaReceptores->lista[j]);
					agregado = true;
					break;
				}
			}
		}


		if (agregado != true)
		{
			for (ush j = 0; j < this->listaReceptores->cantActual; j++) //estos subfor recorren la lista de posibles receptores
			{
				if (this->listaReceptores->lista[j]->getPrioridad() == minima && //recorro solo los de maxima prioridad
					this->listaReceptores->lista[j]->getOrganoNecesitado() == sujeto->listaOrgano->lista[i] &&  //filtro por organo necesitado
					this->listaReceptores->lista[j]->getTipoSangre() == sujeto->tipoSangre) { //filtro por tipo de sangre, repito esto para media y minima
					Protocolo_de_Transporte_y_Transplantes(sujeto->listaOrgano->lista[i], listaReceptores->lista[j]);
					agregado = true;
					break;
				}
			}
		}

	}
}

void cINCUCAI::Protocolo_de_Transporte_y_Transplantes(cOrgano* _organo, cReceptor* _receptor) {
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

void cINCUCAI::agregarPaciente(cPaciente* paciente)
{
	ush agregados=0;
	cDonante* sujeto = dynamic_cast<cDonante*>(paciente); //casteo al paciente para saber qué es
	if (sujeto == NULL) { 
		cReceptor* sujeto = dynamic_cast<cReceptor*>(paciente);
		for (ush i = 0; i < listaReceptores->cantActual; i++)
		{
			if (sujeto->getTelefono() == listaReceptores->lista[i]->getTelefono()) {
				agregados++;
			}
		}
		if (agregados == 0) *listaReceptores + sujeto;
		else throw exception("Receptor ya existente");
	}



	for (ush i = 0; i < listaDonantes->cantActual; i++)
	{
		if (sujeto->getTelefono() == listaDonantes->lista[i]->getTelefono()) {
			agregados++;
		}
	}
	if (agregados == 0) *listaDonantes + sujeto;
	else throw exception("Donante ya existente");
	
}



