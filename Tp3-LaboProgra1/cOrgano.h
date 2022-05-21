#ifndef _CORGANO_H
#define _CORGANO_H
#include "cLista.h"
#include "cFecha.h"

class cOrgano {
    public: 
        #pragma region Constructor_Destructor
        
        /// <summary>
        /// Constructor parametrizado por defecto
        /// </summary>
        /// <param name="_organo">: Organo a donar / recibir</param>
        cOrgano(eOrgano _organo = organoDesconocido);

        ~cOrgano();

        #pragma endregion

        #pragma region Metodos

        /// <summary>
        /// Setea la fecha de ablacion
        /// </summary>
        /// <param name="_fecha">: Fecha a setear</param>
        void setFechaAblacionOrgano(cFecha* _fecha) {
            this->ablacion = _fecha;
        }

        /// <summary>
        /// Obtiene la fecha de Ablacion
        /// </summary>
        /// <returns>Fecha obtenida</returns>
        cFecha* getFechaAblacion() const {
            return this->ablacion;
        }
        eOrgano getTipoOrgano() {
            return this->organo;
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
        
        eOrgano organo;
        cFecha* ablacion;
        #pragma endregion
};

#endif // _CORGANO_H