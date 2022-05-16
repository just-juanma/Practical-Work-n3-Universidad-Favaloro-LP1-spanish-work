#include "gbl.h"
#include "cFecha.h"
//#include "cPaciente.h"
//#include "cAmbulancia.h"
//#include "cAvion.h"
//#include "cHelicoptero.h"
#include "cINCUCAI.h"
#include "cCentroSalud.h"
#include "cDonante.h"
#include "cReceptor.h"
#include "cLista.h"
#include "cOrgano.h"
#include "cVehiculo.h"


int main() {
	cFecha* nacimiento = new cFecha("19/09/2001");
	cFecha* fecha_en_espera = new cFecha("1605/2022");
	//cLista<cReceptor>*receptor(4,true) = new cLista<cReceptor>;
	string nombre = "tomas";
	string sexo = "indefinido";
	string tel = "1234567";
	string patologia= "trombocitopenia";
	cReceptor* receptor1 = new cReceptor(nombre,sexo,tel,patologia,nacimiento,fecha_en_espera,AB,true);
	string nombrecntro = "estambulian";
	string dire = "Av livertador 2124";
	string partido= "indefinido";
	string provincia = "caba";
	
	cCentroSalud* centro1 = new cCentroSalud(nombrecntro, dire, partido, provincia, tel);
	receptor1->asociarcentro(centro1);
}