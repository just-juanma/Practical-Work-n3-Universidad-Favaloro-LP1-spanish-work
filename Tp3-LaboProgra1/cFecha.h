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

        /// <summary>
        /// Setea la fecha actual y la guarda en formato STRING (a diferencia de la ablacion)
        /// </summary>
        /// <param name="_fecha">: Fecha actual, donde se convierte en string (char* realmente, pero no causa problemas)</param>
        void setFechaActual(time_t _fecha) {
            if (fecha) 
                *fecha = ctime(&_fecha);
            throw exception("La fecha actual ya fue inicializada anteriormente");
        }

        /// <summary>
        /// Setea la fecha de ablacion en formato de hora actual
        /// </summary>
        /// <param name="fecha">: Hora local</param>
        void setFechaAblacion(time_t fecha) {
            this->ablacion = fecha;
        }

        /// <summary>
        /// Obtiene la fecha de ablacion
        /// </summary>
        /// <returns>Hora en la que se realizo la ablacion (previamente al momento de realizar el trasplante)</returns>
        time_t getFechaAblacion() const {
            return this->ablacion;
        }

        /// <summary>
        /// Obtiene la fecha en formato de string
        /// </summary>
        /// <returns>Fecha en formato string</returns>
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

        /*
        
            Disponemos de dos tipos de fechas:
        
            string* fecha la usamos cuando queremos guardar lo que pasamos nostros manualmente desde el main (ya sea fecha de muerte o nacimiento, por ejemplo)

            time_t ablacion contiene el valor numerico del tiempo en el que inicio la propia ablacion

        
        */
        
        string* fecha;

        time_t ablacion;
 
        #pragma endregion

};

#endif // _CFECHA_H