#ifndef _CCENTROSALUD_H
#define _CCENTROSALUD_H
#include "gbl.h"
#include "cLista.h"

class cCentroSalud 
{
    public: 

        #pragma region Constructor_Destructor

        /// <summary>
        /// Constructor por defecto parametrizado
        /// </summary>
        /// <param name="_nombre">: Nombre de contacto</param>
        /// <param name="_direccion">: Direccion de contacto</param>
        /// <param name="_partido">: Partido de la direccion</param>
        /// <param name="_provincia">: Provincia para determinar lejania entre centros</param>
        /// <param name="_telefono">: Telefono de contacto</param>
        cCentroSalud(string _nombre = "", string _direccion = "", string _partido = "", string _provincia = "", string _telefono = "");

        /// <summary>
        /// Destructor por defecto
        /// </summary>
        ~cCentroSalud();

        #pragma endregion

        #pragma region metodos

        /// <summary>
        /// Recibe la lista de vehiculos y la asigna
        /// </summary>
        /// <param name="_vehiculo">Vehiculo a agregar</param>
        /// <returns>True en caso de poder asignarlo, false en caso contrario</returns>
        void setListaVehiculo(cLista<eVehiculo>* _listaVehiculo) {
            if (!_listaVehiculo)
                throw exception("No se puede pasar como parametro una lista de vehiculos vacia");
            else if (listaVehiculo) 
                throw exception("La lista de vehiculos ya fue inicializada anteriormente");
            listaVehiculo = _listaVehiculo;
        }
        
        #pragma endregion

    private: 

        #pragma region atributos

        const string nombre;
        const string direccion;
        const string partido;
        const string provincia;
        const string telefono;
        
        cLista<eVehiculo>* listaVehiculo;

        #pragma endregion

};

#endif // _CCENTROSALUD_H