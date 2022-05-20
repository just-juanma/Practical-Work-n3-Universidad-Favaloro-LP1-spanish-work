#include "cINCUCAI.h"

// cINCUCAI implementacion

cINCUCAI::cINCUCAI() {
	this->match = false;
	this->listaDonantes = new cLista<cDonante>(MAX,true);
	this->listaReceptores = new cLista<cReceptor>(MAX, true);
	this->listaCentros = NULL;
}

cINCUCAI::~cINCUCAI() {
	delete this->listaDonantes;
	delete this->listaReceptores;
}

void cINCUCAI::recibirPaciente(cPaciente* paciente)
{
	ingresarPaciente(paciente);
}

cPaciente* cINCUCAI::ingresarPaciente(cPaciente* paciente) {

	agregarPaciente(paciente);

	cDonante* sujeto = dynamic_cast<cDonante*>(paciente); //casteo al paciente para saber qué es
	bool agregados = false;
	if (sujeto == NULL)
	{
		cReceptor* sujeto = dynamic_cast<cReceptor*>(paciente);
		
		for (ush i = 0; i < this->listaDonantes->cantActual; i++)
		{
			agregados = false;
			for (ush j = 0; j < this->listaDonantes->lista[i]->listaOrgano->cantActual; j++)
			{
				if (agregados == true) {
					break;
				}
				if (( *listaDonantes->lista[i] == *sujeto)==true) {
					cOrgano* lista_organos = Ablacion(listaDonantes->lista[i], sujeto->getOrganoNecesitado()->getTipoOrgano());
					cCentroSalud* centro_salud = listaDonantes->lista[i]->getCentro();
					Protocolo_de_Transporte_y_Transplantes(lista_organos, sujeto, centro_salud);
					agregados = true;
					return *listaReceptores - sujeto;
					}
			}
			if (agregados == true) {
				break;
			}
		}
		
	}
	if (sujeto != NULL) {
		for (ush i = 0; i < sujeto->listaOrgano->cantActual; i++) //este for recorre la lista de organos del donante
		{
			agregados = false;
			for (ush j = 0; j < this->listaReceptores->cantActual; j++) //estos subfor recorren la lista de posibles receptores
			{
				if (agregados == true) {
					break;
				}
				if (this->listaReceptores->lista[j]->getPrioridad() == maxima && //recorro solo los de maxima prioridad
					(*sujeto == *listaReceptores->lista[j]) == true) { //filtro por tipo de sangre, repito esto para media y minima
					cOrgano* lista_organos = Ablacion(sujeto, sujeto->listaOrgano->lista[j]->getTipoOrgano());
					cCentroSalud* centro_salud = sujeto->getCentro();
					Protocolo_de_Transporte_y_Transplantes(lista_organos, listaReceptores->lista[j], centro_salud);
					this->listaReceptores->cantActual--;
					agregados = true;
					cPaciente* aux = *listaReceptores - listaReceptores->lista[j];
					return aux;
					break;
				}

			}
			if (agregados == true) {
				break;
			}

			if (agregados != true)
			{
				for (ush j = 0; j < this->listaReceptores->cantActual; j++) //estos subfor recorren la lista de posibles receptores
				{
					if (agregados == true) {
						break;
					}
						if (this->listaReceptores->lista[j]->getPrioridad() == media && //recorro solo los de maxima prioridad
							(*sujeto == *listaReceptores->lista[j]) == true) { //filtro por tipo de sangre, repito esto para media y minima
							cOrgano* lista_organos = Ablacion(sujeto, sujeto->listaOrgano->lista[j]->getTipoOrgano());
							cCentroSalud* centro_salud = sujeto->getCentro();
							Protocolo_de_Transporte_y_Transplantes(lista_organos, listaReceptores->lista[j], centro_salud);
							agregados = true;
							return *listaReceptores - listaReceptores->lista[j];
							break;
						}
					}
					if (agregados == true) {
						break;
					}

					if (agregados != true)
					{
						for (ush j = 0; j < this->listaReceptores->cantActual; j++) //estos subfor recorren la lista de posibles receptores
						{
							if (agregados == true) {
								break;
							}
							if (this->listaReceptores->lista[j]->getPrioridad() == minima && //recorro solo los de maxima prioridad
								(*sujeto == *listaReceptores->lista[j]) == true) { //filtro por tipo de sangre, repito esto para media y minima
								cOrgano* lista_organos = Ablacion(sujeto, sujeto->listaOrgano->lista[j]->getTipoOrgano());
								cCentroSalud* centro_salud = sujeto->getCentro();
								Protocolo_de_Transporte_y_Transplantes(lista_organos, listaReceptores->lista[j], centro_salud);
								agregados = true;
								return *listaReceptores - listaReceptores->lista[j];
								break;
							}
						}
						if (agregados == true) {
							break;
						}
					}

				}
			}
		}
	}

void cINCUCAI::agregarPaciente(cPaciente* paciente)
{
	ush agregados = 0;
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

	if (sujeto != NULL) {
		for (ush i = 0; i < listaDonantes->cantActual; i++)
		{
			if (sujeto->getTelefono() == listaDonantes->lista[i]->getTelefono()) {
				agregados++;
			}
		}
		if (agregados == 0) *listaDonantes + sujeto;
		else throw exception("Donante ya existente");
	}
}

void cINCUCAI::Protocolo_de_Transporte_y_Transplantes(cOrgano* _organo, cReceptor* _receptor, cCentroSalud* centro_salud) {
	if (!_organo || !_receptor || !centro_salud) {
		throw exception("Error en el protocolo de transporte con el receptor, centro de salud u organo");
	}
	int pos = this->listaReceptores->buscar(_receptor);
	cVehiculo* _vehiculo = _receptor->getCentro()->getTipoVehiculo(centro_salud);
	if (_vehiculo) {
		_vehiculo->setOrgano(_organo); //Se le pasa el organo necesitado, para ser transportado 
		_vehiculo->inciarTransporte(); //imprime en pantalla el iuiu iuiu - Taca taca - fiuuuuum
		_vehiculo->setLuO(true);
		if (_receptor->inicarTransplante(_vehiculo->getOrgano())==true) { //ademas se ve si el transplante fue exitoso
			*this->listaReceptores - _receptor;
		}
		else {
			_receptor->setPrioridad(maxima); //setea el 
			_receptor->SwitchEstabilidad();//cambia el estado
		}
	}
}

cOrgano* cINCUCAI::Ablacion(cDonante* _donante, eOrgano tipoOrgano) {
	if (!_donante) throw "Donante invalido";
	return _donante->iniciarAblacion(tipoOrgano);
}





