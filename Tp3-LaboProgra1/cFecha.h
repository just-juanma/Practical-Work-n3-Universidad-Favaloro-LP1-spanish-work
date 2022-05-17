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

        void setFechaAblacion(time_t fecha) {
            ablacion = fecha;
        }

        string getFecha() const {
            return *fecha;
        }

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
    
        #pragma region Atributos
        
        string* fecha;

        time_t ablacion;
 
        #pragma endregion

};

#endif // _CFECHA_H