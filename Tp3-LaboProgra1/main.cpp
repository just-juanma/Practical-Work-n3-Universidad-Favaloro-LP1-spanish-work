#include "gbl.h"
#include "cFecha.h"
#include "cPaciente.h"
#include "cAmbulancia.h"
#include "cAvion.h"
#include "cHelicoptero.h"
#include "cINCUCAI.h"
#include "cCentroSalud.h"
#include "cDonante.h"
#include "cReceptor.h"
#include "cLista.h"
#include "cOrgano.h"
#include "cVehiculo.h"


int main() {

	//// lista paciente
	//cLista<cPaciente>* paciente = new cLista<cPaciente>(4, true);

	//// lista organos 
	//cLista<cOrgano>* organo1 = new cLista<cOrgano>(2, true);
	//cLista<cOrgano>* organo2 = new cLista<cOrgano>(1, true);

	//// lista vehiculos 
	//cLista<cVehiculo>* vehiculo1 = new cLista<cVehiculo>(3, true);
	//cLista<cVehiculo>* vehiculo2 = new cLista<cVehiculo>(2, true);

	//// fechas receptores
	//cFecha* nacimiento1 = new cFecha("19/09/2001");
	//cFecha* fechaEnEspera1 = new cFecha("1605/2022");

	//cFecha* nacimiento2 = new cFecha("13/02/1997");
	//cFecha* fechaEnEspera2 = new cFecha("1602/2022");

	//// organos receptores
	//cOrgano* corazon1 = new cOrgano(corazon);
	//cOrgano* huesos1 = new cOrgano(huesos);

	//// receptores
	//cReceptor* receptor1 = new cReceptor("Tomas", "Indefinido", "1147853254", "Arritmia", nacimiento1, fechaEnEspera1, AB, true);
	//cReceptor* receptor2 = new cReceptor("Jorgelin", "Masculino", "1102047823", "Cancer de hueso", nacimiento2, fechaEnEspera2, O, true);

	//receptor1->setOrganoNecesitado(corazon1);
	//receptor2->setOrganoNecesitado(huesos1);

	//receptor1->setPrioridad(media);
	//receptor2->setPrioridad(maxima);
	//// donantes
	//cDonante* donante1 = new cDonante

	//// generacion de lista paciente
	//try {
	//	*paciente + receptor1;
	//	*paciente + receptor2;
	//}
	//catch (exception& e) {
	//	cout << "Error: " << e.what() << endl;
	//}





	//string nombrecntro = "estambulian";
	//string dire = "Av livertador 2124";
	//string partido = "indefinido";
	//string provincia = "caba";

	//	cCentroSalud* centro1 = new cCentroSalud(nombrecntro, dire, partido, provincia, tel);
	//	receptor1->asociarcentro(centro1);
	//
	//	delete paciente;
	//	delete organo1; delete organo2;
	//	delete vehiculo1; delete vehiculo2;
	//	delete nacimiento1; delete fechaEnEspera1;
	//	delete nacimiento2; delete fechaEnEspera2;
	//	delete corazon1; delete huesos1;
	//	delete receptor1; delete receptor2;
}