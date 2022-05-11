#define _CRT_SECURE_NO_WARNINGS
#include "gbl.h"
#include "cFecha.h"
#include "cPaciente.h"
#include "cAmbulancia.h"
#include "cAvion.h"
#include "cCentroSalud.h"
#include "cDonante.h"
#include "cHelicoptero.h"
#include "cINCUCAI.h"
#include "cLista.h"
#include "cOrgano.h"
#include "cReceptor.h"
#include "cVehiculo.h"


int main() {
	try {
		cPaciente* paciente1;
		cDonante* donante1 = new cDonante("Pepe", "Masculino", "1154789562");

		paciente1 = donante1;


























		

	}
	catch (exception& e) {
		cout << "Error:" << e.what() << endl << "Finalizando programa";
		return 0;
	}
}