#ifndef _CVEHICULO_H
#define _CVEHICULO_H
#include "gbl.h"
#include "cOrgano.h"


// clase abstracta

class cVehiculo {

	public: 

		#pragma region Constructor_Destructor

		/// <summary>
		/// Constructor por defecto parametrizado
		/// </summary>
		/// <param name="_nombre">: Nombre del vehiculo</param>
		cVehiculo(string _nombre = "");

		/// <summary>
		/// Destructor por defecto
		/// </summary>
		~cVehiculo();

		#pragma endregion

		#pragma region Metodos

        /// <summary>
        /// Obtiene si el vehiculo esta libre u ocupado
        /// </summary>
        /// <returns>Estado del vehiculo</returns>
        bool getLuO() const {
            return this->LuO;
        }

        void setLuO(bool estado) {
            this->LuO = estado;
        }

        /// <summary>
        /// Obtiene el organo que transporta el vehiculo
        /// </summary>
        /// <returns>Organo que transporta el vehiculo</returns>
        cOrgano* getOrgano(){
            if (organoEnTransporte) {
                cOrgano* organoaux = this->organoEnTransporte; 
                this->organoEnTransporte = NULL;
                return organoaux;
            }
            throw exception("El organo que se intenta obtener no existe");
        }

        /// <summary>
        /// Setea el organo que transporta el vehiculo
        /// </summary>
        void setOrgano(cOrgano* _organo) {
            if (!this->organoEnTransporte)
                this->organoEnTransporte = _organo;
            else
                throw exception("No se pudo asignar el organo");

        }

        /// <summary>
        /// Metodo abstacto: Concatena a un solo string los atributos pertinentes
		/// de la clase hija
        /// </summary>
        /// <returns>: String concatenado</returns>
        virtual string to_string() = 0;
       
        /// <summary>
        /// Imprime to_string() de la clase hija
        /// </summary>
        void imprimir() {
            cout << to_string() << endl;
        }

        void inciarTransporte() {
            imprimir();
            this->LuO = false;
        }

		#pragma endregion

    protected:

        #pragma region Atributos

        const string nombre;
		bool LuO;
		cOrgano* organoEnTransporte;

        #pragma endregion
};

#endif // _CVEHICULO_H