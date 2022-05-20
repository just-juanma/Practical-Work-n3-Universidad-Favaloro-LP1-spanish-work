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

	// fechas receptores
	cFecha* rNacimiento1 = new cFecha("19/09/2001");
	cFecha* fechaEnEspera1 = new cFecha("1605/2022");

	cFecha* rNacimiento2 = new cFecha("13/02/1997");
	cFecha* fechaEnEspera2 = new cFecha("1602/2022");

	// organos receptores
	cOrgano* rCorazon1 = new cOrgano(corazon);
	cOrgano* rHuesos1 = new cOrgano(huesos);

	// receptores
	cReceptor* receptor1 = new cReceptor("Tomas", "Indefinido", "1147853254", "Arritmia", rNacimiento1, fechaEnEspera1, AB, true);
	cReceptor* receptor2 = new cReceptor("Jorge", "Masculino", "1102047823", "Cancer de hueso", rNacimiento2, fechaEnEspera2, O, true);

	try {
		// organos necesitados
		receptor1->setOrganoNecesitado(rCorazon1);
		receptor2->setOrganoNecesitado(rHuesos1);

		// prioridades
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

	// fechas donantes
	cFecha* dNacimiento1 = new cFecha("09/01/1981");
	cFecha* dNacimiento2 = new cFecha("24/04/2000");
	cFecha* muerte1 = new cFecha("04/05/2022");
	cFecha* muerte2 = new cFecha("07/03/2022");

	// donantes
	cDonante* donante1 = new cDonante("Estefania", "Femenino", "1147520124", dNacimiento1, AB);
	cDonante* donante2 = new cDonante("Pepe", "Masculino", "1132548796", dNacimiento2, O);

	// lista de organos
	cLista<cOrgano>* organo1 = new cLista<cOrgano>(2, true);
	cLista<cOrgano>* organo2 = new cLista<cOrgano>(1, true);

	try {
		// fechas de muerte
		donante1->setFechaMuerte(muerte1);
		donante2->setFechaMuerte(muerte2);

		// inicializacion listas
		*organo1 + dCorazon1;
		*organo1 + dPiel1;
		*organo2 + dHuesos2;

		// implementacion listas
		donante1->setLista(organo1);
		donante2->setLista(organo2);
	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
	}

	// lista paciente
	cLista<cPaciente>* paciente = new cLista<cPaciente>(4, true);

	try {
		// inicializacion listas
		*paciente + receptor1;
		*paciente + receptor2;
		*paciente + donante1;
		*paciente + donante2;
	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
	}

	// centros
	cCentroSalud* centro1 = new cCentroSalud("Unidad Sanitaria Temperley Oeste", "General Paz 1405", "Lomas de Zamora", "Buenos Aires", "1154785202");
	cCentroSalud* centro2 = new cCentroSalud("Unidad Sanitaria Villa Itati II", "Falucho 1146", "Quilmes", "Buenos Aires", "1187541474");

	try {
		// seteo de centros
		donante1->asociarCentro(centro1);
		donante2->asociarCentro(centro2);
		
		receptor1->asociarCentro(centro2);
		receptor2->asociarCentro(centro1);

	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
	}
		
	// vehiculos
	cAmbulancia* ambulancia1 = new cAmbulancia("Vehiculo de Asistencia Medica y Enfermeria");
	cAmbulancia* ambulancia2 = new cAmbulancia("Ambulancia Colectiva");
	cHelicoptero* helicoptero1 = new cHelicoptero("H145");
	cHelicoptero* helicoptero2 = new cHelicoptero("EC-145");
	cAvion* avion1 = new cAvion("C340");
	cAvion* avion2 = new cAvion("C414");
	cAvion* avion3 = new cAvion("C421");

	// lista vehiculo
	cLista<cVehiculo>* vehiculo1 = new cLista<cVehiculo>(4, true);
	cLista<cVehiculo>* vehiculo2 = new cLista<cVehiculo>(3, true);

	try {
		// inicializacion listas
		*vehiculo1 + ambulancia1;
		*vehiculo1 + helicoptero1;
		*vehiculo1 + avion1;
		*vehiculo1 + avion2;

		*vehiculo2 + ambulancia2;
		*vehiculo2 + helicoptero2;
		*vehiculo2 + avion3;

		// seteo de listas en los centros
		centro1->setListaVehiculo(vehiculo1);
		centro2->setListaVehiculo(vehiculo2);
		
	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
	}

	// INCUCAI
	cINCUCAI* INCUCAI = new cINCUCAI();
	
	// lista centro
	cLista<cCentroSalud>* centro = new cLista<cCentroSalud>(2, true);

	try {
		// inicializacion listas
		*centro + centro1;
		*centro + centro2;
		
		INCUCAI->setCentros(centro);
	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
	}

	//Trabajo de matches
	INCUCAI->ingresarPaciente(donante1);
	INCUCAI->ingresarPaciente(donante2); 
	INCUCAI->ingresarPaciente(receptor1); 

	int a = 2;

	/*try {
		INCUCAI->informeFinDeMes();
	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
	}*/

	//delete paciente;

	delete dCorazon1; delete dPiel1; delete dHuesos2;
	delete rCorazon1; delete rHuesos1;
	
	delete rNacimiento1; delete fechaEnEspera1;
	delete rNacimiento2; delete fechaEnEspera2;
	delete dNacimiento1; delete dNacimiento2;
	delete muerte1; delete muerte2;

	delete centro;
	delete vehiculo1; delete vehiculo2;

	delete INCUCAI;
}