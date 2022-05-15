#ifndef _CHELICOPTERO_H
#define _CHELICOPTERO_H
#include "gbl.h"
#include "cVehiculo.h"

class cHelicoptero : public cVehiculo {

    public:

        #pragma region Constructor_Destructor

        /// <summary>
        /// Constructor por defecto parametrizado
        /// </summary>
        /// <param name="_nombre">: Nombre del helicoptero</param>
        cHelicoptero(string _nombre);

        ~cHelicoptero();

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
};

#endif // _CHELICOPTERO_H