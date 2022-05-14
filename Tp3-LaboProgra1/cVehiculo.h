#ifndef _CVEHICULO_H
#define _CVEHICULO_H
#include "gbl.h"

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
        /// Concatena a un solo string los atributos pertinentes
        /// </summary>
        /// <returns>: String concatenado</returns>
        virtual string to_string() = 0;
       
        /// <summary>
        /// Imprime to_string()
        /// </summary>
        virtual void imprimir() = 0;

		virtual bool getLoO() = 0;

		virtual cOrgano* getOrgano() = 0;

		virtual void setOrgano(cOrgano* organo) = 0;

		#pragma endregion

    protected:

        #pragma region Atributos

        const string nombre;
		bool LoO;
		cOrgano* organoEnTransporte;
        #pragma endregion
};

#endif // _CVEHICULO_H