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

	// lista paciente
	cLista<cPaciente>* paciente = new cLista<cPaciente>(4, true);


	// fechas receptores
	cFecha* rNacimiento1 = new cFecha("19/09/2001");
	cFecha* fechaEnEspera1 = new cFecha("1605/2022");

	cFecha* nacimiento2 = new cFecha("13/02/1997");
	cFecha* fechaEnEspera2 = new cFecha("1602/2022");

	// organos receptores
	cOrgano* rCorazon1 = new cOrgano(corazon);
	cOrgano* rHuesos1 = new cOrgano(huesos);

	// receptores
	cReceptor* receptor1 = new cReceptor("Tomas", "Indefinido", "1147853254", "Arritmia", rNacimiento1, fechaEnEspera1, AB, true);
	cReceptor* receptor2 = new cReceptor("Jorge", "Masculino", "1102047823", "Cancer de hueso", nacimiento2, fechaEnEspera2, O, true);

	try {
		receptor1->setOrganoNecesitado(rCorazon1);
		receptor2->setOrganoNecesitado(rHuesos1);

		receptor1->setPrioridad(media);
		receptor2->setPrioridad(maxima);
	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
	}

	// organos donantes
	cOrgano* dCorazon1 = new cOrgano(corazon);
	cOrgano* dPiel1 = new cOrgano(piel);
	cOrgano* dHuesos2 = new cOrgano(huesos);

	// lista organos 
	cLista<cOrgano>* organo1 = new cLista<cOrgano>(2, true);
	cLista<cOrgano>* organo2 = new cLista<cOrgano>(1, true);

	// inicializacion lista organos
	*organo1 + dCorazon1;
	*organo1 + dPiel1;
	*organo2 + dHuesos2;

	// fecha donantes
	cFecha* dNacimiento1 = new cFecha("09/01/1981");
	cFecha* dNacimiento2 = new cFecha("24/04/2000");
	cFecha* muerte1 = new cFecha("04/05/2022");
	cFecha* muerte2 = new cFecha("07/03/2022");

	// donantes
	cDonante* donante1 = new cDonante("Estefania", "Femenino", "1147520124", dNacimiento1, AB);
	cDonante* donante2 = new cDonante("Pepe", "Masculino", "1132548796", dNacimiento2, O);

	try {
		donante1->setFechaMuerte(muerte1);
		donante2->setFechaMuerte(muerte2);

		donante1->setLista(organo1);
		donante2->setLista(organo2);
	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
	}

	// generacion de lista paciente
	try {
		*paciente + receptor1;
		*paciente + receptor2;
		*paciente + donante1;
		*paciente + donante2;
	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
	}
	 


	// lista vehiculos 
	cLista<cVehiculo>* vehiculo1 = new cLista<cVehiculo>(3, true);
	cLista<cVehiculo>* vehiculo2 = new cLista<cVehiculo>(2, true);
	







	string nombrecntro = "estambulian";
	string dire = "Av livertador 2124";
	string partido = "indefinido";
	string provincia = "caba";

		//cCentroSalud* centro1 = new cCentroSalud(nombrecntro, dire, partido, provincia, tel);
	//	receptor1->asociarcentro(centro1);
	
		delete paciente;
		delete organo1; delete organo2;
		delete vehiculo1; delete vehiculo2;
		delete rNacimiento1; delete fechaEnEspera1;
		delete nacimiento2; delete fechaEnEspera2;
		delete rCorazon1; delete rHuesos1;
		delete receptor1; delete receptor2;
}