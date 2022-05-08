#include "gbl.h"
int main() {
	try {
		// [...]
	}
	catch (exception& e) {
		cout << "Error:" << e.what() << endl << "Finalizando programa";
		return 0;
	}
}