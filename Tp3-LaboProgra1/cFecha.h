#ifndef _CFECHA_H
#define _CFECHA_H
#include "gbl.h"

class cFecha {
    public:

        #pragma region Constructor_Destructor
        
        /// <summary>
        /// Constructor por defecto
        /// </summary>
        cFecha(time_t _fecha = 0);
        
        /// <summary>
        /// Destructor por defecto
        /// </summary>        
        ~cFecha();

        #pragma endregion

        #pragma region Metodos

        void setFecha(time_t _fecha) {
            fecha = &_fecha;
        }

        #pragma endregion

    private: 
    
        #pragma region Atributos
        
        time_t* fecha

        #pragma endregion

};

#endif // _CFECHA_H