#ifndef _CAMBULANCIA_H
#define _CAMBULANCIA_H
#include "gbl.h"
#include "cVehiculo.h"

class cAmbulancia : public cVehiculo {

    public:

        #pragma region Constructor_Destructor

        /// <summary>
        /// Constructor por defecto parametrizado
        /// </summary>
        /// <param name="_nombre">: Nombre de la ambulancia</param>
        cAmbulancia(string _nombre);

        /// <summary>
        /// Destructor por defecto
        /// </summary>
        ~cAmbulancia();

        #pragma endregion

        #pragma region Metodos

        /// <summary>
        /// Concatena a un solo string los atributos pertinentes
        /// </summary>
        /// <returns>String concatenado</returns>
        string to_string();

        #pragma endregion
};

#endif // _CAMBULANCIA_H