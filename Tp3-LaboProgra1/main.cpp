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
	cFecha* fechaEnEspera1 = new cFecha("16/05/2022");

	cFecha* rNacimiento2 = new cFecha("13/02/1997");
	cFecha* fechaEnEspera2 = new cFecha("16/02/2022");

	cFecha* rNacimiento3 = new cFecha("30/12/2000");
	cFecha* fechaEnEspera3 = new cFecha("4/08/2022");

	cFecha* rNacimiento4 = new cFecha("20/03/1996");
	cFecha* fechaEnEspera4 = new cFecha("6/010/2022");

	// organos receptores
	cOrgano* rCorazon1 = new cOrgano(corazon);
	cOrgano* rHuesos2 = new cOrgano(huesos);
	cOrgano* rPiel3 = new cOrgano(piel);
	cOrgano* rRinion4 = new cOrgano(rinion);

	// receptores
	cReceptor* receptor1 = new cReceptor("Tomas", "Indefinido", "1147853254", "Arritmia", rNacimiento1, fechaEnEspera1, AB, true);
	cReceptor* receptor2 = new cReceptor("Jorge", "Masculino", "1102047823", "Cancer de hueso", rNacimiento2, fechaEnEspera2, O, true);
	cReceptor* receptor3 = new cReceptor("Juan", "Indefinido", "1138295648", "Quemadura", rNacimiento3, fechaEnEspera3, A, true);
	cReceptor* receptor4 = new cReceptor("Tomas", "Indefinido", "1147853254", "Insuficiencia Renal", rNacimiento4, fechaEnEspera4, B, true);
	try {
		// organos necesitados
		receptor1->setOrganoNecesitado(rCorazon1);
		receptor2->setOrganoNecesitado(rHuesos2);
		receptor3->setOrganoNecesitado(rPiel3);
		receptor4->setOrganoNecesitado(rRinion4);

		// prioridades
		receptor1->setPrioridad(media);
		receptor2->setPrioridad(maxima);
		receptor3->setPrioridad(media);
		receptor4->setPrioridad(minima);
	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
	}

	// organos donantes
	cOrgano* dCorazon1 = new cOrgano(corazon);
	cOrgano* dPiel1 = new cOrgano(piel);
	cOrgano* dHuesos2 = new cOrgano(huesos);
	cOrgano* dPiel3 = new cOrgano(piel);
	cOrgano* dRinion3 = new cOrgano(rinion);
	cOrgano* dCornea4 = new cOrgano(cornea);

	// fechas donantes
	cFecha* dNacimiento1 = new cFecha("09/01/1981");
	cFecha* dNacimiento2 = new cFecha("24/07/1955");
	cFecha* dNacimiento3 = new cFecha("09/01/1981");
	cFecha* dNacimiento4 = new cFecha("24/04/1970");
	cFecha* muerte1 = new cFecha("04/05/2022");
	cFecha* muerte2 = new cFecha("07/03/2022");
	cFecha* muerte3 = new cFecha("06/05/2022");
	cFecha* muerte4 = new cFecha("08/03/2022");

	// donantes
	cDonante* donante1 = new cDonante("Estefania", "Femenino", "1147520124", dNacimiento1, AB);
	cDonante* donante2 = new cDonante("Pepe", "Masculino", "1144556677", dNacimiento2, O);
	cDonante* donante3 = new cDonante("Jose", "Masculino", "1147520124", dNacimiento3, A);
	cDonante* donante4 = new cDonante("Gladys", "Femenino", "1155446622", dNacimiento4, O);

	// lista de organos
	cLista<cOrgano>* organo1 = new cLista<cOrgano>(2, true);
	cLista<cOrgano>* organo2 = new cLista<cOrgano>(1, true);
	cLista<cOrgano>* organo3 = new cLista<cOrgano>(2, true);
	cLista<cOrgano>* organo4 = new cLista<cOrgano>(1, true);

	try {
		// fechas de muerte
		donante1->setFechaMuerte(muerte1);
		donante2->setFechaMuerte(muerte2);
		donante3->setFechaMuerte(muerte3);
		donante4->setFechaMuerte(muerte4);

		// inicializacion listas
		*organo1 + dCorazon1;
		*organo1 + dPiel1;
		*organo2 + dHuesos2;
		*organo3 + dRinion3;
		*organo3 + dPiel3;
		*organo4 + dCornea4;

		// implementacion listas
		donante1->setLista(organo1);
		donante2->setLista(organo2);
		donante3->setLista(organo3);
		donante4->setLista(organo4);
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
		donante3->asociarCentro(centro1);
		donante4->asociarCentro(centro2);

		receptor1->asociarCentro(centro2);
		receptor2->asociarCentro(centro1);
		receptor3->asociarCentro(centro2);
		receptor4->asociarCentro(centro1);

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
	cLista<cReceptor>* listaDefaultR = new cLista<cReceptor>(MAX, true);
	cLista<cDonante>* listaDefaultD = new cLista<cDonante>(MAX, true);
	*listaDefaultD + donante1;
	*listaDefaultD + donante2;
	*listaDefaultD + donante3;
	*listaDefaultD + donante4;
	INCUCAI->setListas(listaDefaultD, listaDefaultR);

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
	try {
		INCUCAI->ingresarPaciente(receptor1);
		INCUCAI->ingresarPaciente(receptor2);
		cPaciente* pacietne =INCUCAI->ingresarPaciente(receptor3);
		INCUCAI->ingresarPaciente(receptor4);
		
	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
	}

	
	int a = 2;

	/*try {
		INCUCAI->informeFinDeMes();
	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
	}*/

	//delete paciente;

	delete dCorazon1; delete dPiel1; delete dHuesos2;
	delete rCorazon1; delete rHuesos2;
	
	delete rNacimiento1; delete fechaEnEspera1;
	delete rNacimiento2; delete fechaEnEspera2;
	delete dNacimiento1; delete dNacimiento2;
	delete muerte1; delete muerte2;

	delete centro;
	delete vehiculo1; delete vehiculo2;

	delete INCUCAI;
}