#define _CRT_SECURE_NO_WARNINGS
#include "gbl.h"
#include "cFecha.h"


int main() {
	try {

		// declaro las variables time_t
		time_t hora1;
		time_t hora2;

		// seteo hora de ablacion
		cFecha* fecha = new cFecha(time(&hora1));

		// seteo hora de operacion
		fecha->setHoraTransplante(time(&hora2));
		
		// obtengo horas transcurridas
		cout << "Las horas tanscurridas desde " << ctime(&hora1) << " hasta " << ctime(&hora2) << " es de " << fecha->getDiffHour();


	}
	catch (exception& e) {
		cout << "Error:" << e.what() << endl << "Finalizando programa";
		return 0;
	}
}