#ifndef _CVEHICULO_H
#define _CVEHICULO_H
#include "gbl.h"

class cVehiculo {
	public: 
		#pragma region Constructor_Destructor

		cVehiculo(eVehiculo _vehiculo = sinVehiculo);

		~cVehiculo();

		#pragma endregion

		#pragma region Metodos

        /// <summary>
        /// Concatena a un solo string los atributos pertinentes
        /// </summary>
        /// <returns>String concatenado</returns>
        string to_string();

        /// <summary>
        /// Imprime to_string()
        /// </summary>
        void imprimir() {
            cout << to_string() << endl;
        }

		#pragma endregion

	private:
		eVehiculo vehiculo;
};

#endif // _CVEHICULO_H