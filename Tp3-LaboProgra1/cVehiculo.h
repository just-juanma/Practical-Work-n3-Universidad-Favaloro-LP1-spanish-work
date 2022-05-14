#ifndef _CVEHICULO_H
#define _CVEHICULO_H
#include "gbl.h"

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
		/// Metodo abstracto: Obtiene el estado del vehiculo 
		/// (Libre u Ocupado) de las clases hijas
		/// </summary>
		/// <returns>Estado del vehiculo</returns>
		virtual bool getLuO() = 0;

		/// <summary>
		/// Metodo abstracto: Obtiene el organo del vehiculo
		/// de la clase hija
		/// </summary>
		/// <returns></returns>
		virtual cOrgano* getOrgano() = 0;

		/// <summary>
		/// Metodo abstracto: Setea el organo del vehiculo
		/// de la clase hija
		/// </summary>
		/// <param name="organo"></param>
		virtual void setOrgano(cOrgano* organo) = 0;

        /// <summary>
        /// Metodo abstacto: Concatena a un solo string los atributos pertinentes
		/// de la clase hija
        /// </summary>
        /// <returns>: String concatenado</returns>
        virtual string to_string() = 0;
       
        /// <summary>
        /// Metodo abstracto: Imprime to_string() de la clase hija
        /// </summary>
        virtual void imprimir() = 0;

		#pragma endregion

    protected:

        #pragma region Atributos

        const string nombre;
		bool LuO;
		cOrgano* organoEnTransporte;

        #pragma endregion
};

#endif // _CVEHICULO_H