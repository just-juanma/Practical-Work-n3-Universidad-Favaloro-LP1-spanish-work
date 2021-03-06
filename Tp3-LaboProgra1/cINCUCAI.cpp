#include "cINCUCAI.h"

// cINCUCAI implementacion

cINCUCAI::cINCUCAI() {
	this->listaDonantes = NULL;
	this->listaReceptores = NULL;
	this->listaCentros = NULL;
}

cINCUCAI::~cINCUCAI() { }

void cINCUCAI::recibirPaciente(cPaciente* paciente)
{
	ingresarPaciente(paciente);
}

cLista<cPaciente>* cINCUCAI::ingresarPaciente(cPaciente* paciente) {

	agregarPaciente(paciente);

	cDonante* sujeto = dynamic_cast<cDonante*>(paciente); //casteo al paciente para saber qu? es
	bool agregados = false;
	if (sujeto == NULL)
	{

		cReceptor* sujeto = dynamic_cast<cReceptor*>(paciente);
		cLista<cPaciente>* listaReceptoresAux = new cLista<cPaciente>(1, true);
		for (ush i = 0; i < this->listaDonantes->cantActual; i++)
		{
			agregados = false;
			for (ush j = 0; j < this->listaDonantes->lista[i]->listaOrgano->cantActual; j++)
			{
				if (agregados == true) {
					break;
				}
				if (( *listaDonantes->lista[i] == *sujeto) == true) {
					cOrgano* lista_organos = Ablacion(listaDonantes->lista[i], sujeto->getOrganoNecesitado()->getTipoOrgano());
					cCentroSalud* centro_salud = listaDonantes->lista[i]->getCentro();
					protocoloDeTransporteYTrasplante(lista_organos, sujeto, centro_salud);
					agregados = true;
					listaReceptoresAux->lista[0] = *listaReceptores - sujeto;
					return listaReceptoresAux;
					}
			}
			if (agregados == true) {
				break;
			}
		}
		
	}
	if (sujeto != NULL) {
		cLista<cPaciente>* listaReceptoresAux = new cLista<cPaciente>(sujeto->listaOrgano->cantActual, true);
		ush n = sujeto->listaOrgano->cantActual;
		ush cantAgregados = 0;
		for (ush i = 0; i < n; i++) //este for recorre la lista de organos del donante
		{
			agregados = false;
			for (ush j = 0; j < this->listaReceptores->cantActual; j++) //estos subfor recorren la lista de posibles receptores
			{
				if (agregados == true) {
					break;
				}
				if (this->listaReceptores->lista[j]->getPrioridad() == maxima && //recorro solo los de maxima prioridad
					(*sujeto == *listaReceptores->lista[j]) == true) { //filtro por tipo de sangre, repito esto para media y minima
					cantAgregados++;
					cOrgano* lista_organos = Ablacion(sujeto, sujeto->listaOrgano->lista[j]->getTipoOrgano());
					cCentroSalud* centro_salud = sujeto->getCentro();
					protocoloDeTransporteYTrasplante(lista_organos, listaReceptores->lista[j], centro_salud);
					agregados = true;
					listaReceptoresAux->lista[cantAgregados - 1] = *listaReceptores - listaReceptores->lista[j];
					break;
				}

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
							cantAgregados++;
							cOrgano* lista_organos = Ablacion(sujeto, sujeto->listaOrgano->lista[j]->getTipoOrgano());
							cCentroSalud* centro_salud = sujeto->getCentro();
							protocoloDeTransporteYTrasplante(lista_organos, listaReceptores->lista[j], centro_salud);
							agregados = true;
							if (listaReceptores->lista[j])
								listaReceptoresAux->lista[cantAgregados - 1] = *listaReceptores - listaReceptores->lista[j];
							break;
						}
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
								cantAgregados++;
								cOrgano* lista_organos = Ablacion(sujeto, sujeto->listaOrgano->lista[j]->getTipoOrgano());
								cCentroSalud* centro_salud = sujeto->getCentro();
								protocoloDeTransporteYTrasplante(lista_organos, listaReceptores->lista[j], centro_salud);
								agregados = true;
								if(listaReceptores->lista[j])
									listaReceptoresAux->lista[cantAgregados - 1] = *listaReceptores - listaReceptores->lista[j];
								break;
							}
						}
					}
				}
			}
			return listaReceptoresAux;
		}
	}

void cINCUCAI::agregarPaciente(cPaciente* paciente)
{
	ush agregados = 0;
	cDonante* sujeto = dynamic_cast<cDonante*>(paciente); //casteo al paciente para saber qu? es
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

void cINCUCAI::protocoloDeTransporteYTrasplante(cOrgano* _organo, cReceptor* _receptor, cCentroSalud* centro_salud) {
	if (!_organo || !_receptor || !centro_salud) {
		throw exception("Error en el protocolo de transporte con el receptor, centro de salud u organo");
	}
	int pos = this->listaReceptores->buscar(_receptor);
	cVehiculo* _vehiculo = _receptor->getCentro()->getTipoVehiculo(centro_salud);
	if (_vehiculo) {
		_vehiculo->setOrgano(_organo); //Se le pasa el organo necesitado, para ser transportado 
		_vehiculo->inciarTransporte(); //imprime en pantalla el iuiu iuiu - Taca taca - fiuuuuum
		_vehiculo->setLuO(true);
		if (_receptor->inicarTransplante(_vehiculo->getOrgano())==false) { //ademas se ve si el transplante fue exitoso
			_receptor->setPrioridad(maxima); //setea el 
			_receptor->switchEstabilidad();//cambia el estado
		}
	}
}

cOrgano* cINCUCAI::Ablacion(cDonante* _donante, eOrgano tipoOrgano) {
	if (!_donante) throw "Donante invalido";
	return _donante->iniciarAblacion(tipoOrgano);
}





