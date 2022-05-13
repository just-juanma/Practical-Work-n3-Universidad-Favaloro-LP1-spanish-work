#ifndef _CCENTROSALUD_H
#define _CCENTROSALUD_H
#include "gbl.h"
#include "cLista.h"
#include "cVehiculo.h"
#include "cDonante.h"
#include "cFecha.h"

class cCentroSalud 
{
    public: 
        #pragma region Constructor_Destructor

        /// <summary>
        /// Constructor parametrizado por defecto
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

        #pragma region Metodos

        /// <summary>
        /// Recibe la lista de vehiculos y la asigna
        /// </summary>
        /// <param name="_vehiculo">Vehiculo a agregar</param>
        /// <returns>True en caso de poder asignarlo, false en caso contrario</returns>
        bool setListaVehiculo(cLista<cVehiculo>* _listaVehiculo) {
            try {
                if (!_listaVehiculo)
                    throw exception("No se puede pasar como parametro una lista de vehiculos vacia");
                else if (listaVehiculo) 
                    throw exception("La lista de vehiculos ya fue inicializada anteriormente");
                listaVehiculo = _listaVehiculo;
                return true;
            }
            catch (exception& e) {
                cout << "Error: " << e.what() << endl;
                return false;
            }
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

        //cOrgano* iniciarAblacion(cOrgano* receptor, cFecha* fecha); No puedo iniciar la ablacion si no tengo match

        #pragma endregion

    private: 

        #pragma region Atributos

        const string nombre;
        const string direccion;
        const string partido;
        const string provincia;
        const string telefono;
        cLista<cVehiculo>* listaVehiculo;
        cFecha* ablacion;

        #pragma endregion

};

#endif // _CCENTROSALUD_H