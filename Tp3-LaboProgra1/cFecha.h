#ifndef _CFECHA_H
#define _CFECHA_H
#include "gbl.h"

class cFecha {
    public:

        #pragma region Constructor_Destructor
        
        /// <summary>
        /// Constructor por defecto
        /// </summary>
        cFecha(string _fecha = "");
        
        /// <summary>
        /// Destructor por defecto
        /// </summary>        
        ~cFecha();

        #pragma endregion

        #pragma region Metodos

        void setFechaActual(time_t _fecha) {
            *fecha = ctime(&_fecha);
        }

        string getFecha() const {
            return *fecha;
        }

        #pragma endregion

    private: 
    
        #pragma region Atributos
        
        string* fecha;

        #pragma endregion

};

#endif // _CFECHA_H