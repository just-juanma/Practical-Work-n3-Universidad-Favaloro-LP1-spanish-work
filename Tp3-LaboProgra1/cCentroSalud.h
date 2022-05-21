#ifndef _CCENTROSALUD_H
#define _CCENTROSALUD_H
#include "gbl.h"
#include "cLista.h"
#include "cVehiculo.h"
#include "cAmbulancia.h"
#include "cHelicoptero.h"
#include "cAvion.h"

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
        void setListaVehiculo(cLista<cVehiculo>* _listaVehiculo) {
            if (!_listaVehiculo)
                throw exception("No se puede pasar como parametro una lista de vehiculos vacia");
            else if (this->listaVehiculo)
                throw exception("La lista de vehiculos ya fue inicializada anteriormente");
            this->listaVehiculo = _listaVehiculo;
        }
        
        /// <summary>
        /// Obtiene la provincia del centro
        /// </summary>
        /// <returns>Provincia del centro</returns>
        string getProvincia() const {
            return this->provincia;
        }

        /// <summary>
        /// Obtiene la cantidad de donaciones en la provincia del centro
        /// </summary>
        /// <returns>Cantidad de donaciones en la provincia</returns>
        ush getCantDonProv() const {
            return this->cantDonProv;
        }

        /// <summary>
        /// Obtiene el nombre del centro
        /// </summary>
        /// <returns>Nombre del centro</returns>
        string getNombre() const {
            return this->nombre;
        }

        /// <summary>
        /// Recibe el centro del receptor y lo compara 
        /// </summary>
        /// <param name="centroReceptor">: Centro de salud del receptor</param>
        /// <returns>El vehiculo necesario para el translado, NULL en caso contrario</returns>
        cVehiculo* getTipoVehiculo(cCentroSalud* centroReceptor);

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

        ush cantDonProv;
        const string nombre;
        const string direccion;
        const string partido;
        const string provincia;
        const string telefono;
        cLista<cVehiculo>* listaVehiculo;

        #pragma endregion

};

#endif // _CCENTROSALUD_H