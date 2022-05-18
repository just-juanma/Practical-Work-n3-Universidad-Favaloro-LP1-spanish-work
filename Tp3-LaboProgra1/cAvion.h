#ifndef _CAVION_H
#define _CAVION_H
#include "gbl.h"
#include "cVehiculo.h"

class cAvion : public cVehiculo {

    public:

        #pragma region Constructor_Destructor

        /// <summary>
        /// Constructor por defecto parametrizado
        /// </summary>
        /// <param name="_nombre": Nombre del avion></param>
        cAvion(string _nombre);

        /// <summary>
        /// Destructor por defecto
        /// </summary>
        ~cAvion();
            
        #pragma endregion

        #pragma region Metodos
        
        /// <summary>
        /// Concatena a un solo string los atributos pertinentes
        /// </summary>
        /// <returns>String concatenado</returns>
        string to_string();

        #pragma endregion
};

#endif // _CAVION_H