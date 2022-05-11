#ifndef _CVEHICULO_H
#define _CVEHICULO_H
#include "gbl.h"

class cVehiculo {
	public: 
		#pragma region Constructor_Destructor

		cVehiculo();

		~cVehiculo();

		#pragma endregion

		#pragma region Metodos

        /// <summary>
        /// Concatena a un solo string los atributos pertinentes
        /// </summary>
        /// <returns>String concatenado</returns>
       

        /// <summary>
        /// Imprime to_string()
        /// </summary>
        void imprimir() {
            cout << to_string() << endl;
        }

    protected:
        virtual string to_string() = 0;

		#pragma endregion


};

#endif // _CVEHICULO_H