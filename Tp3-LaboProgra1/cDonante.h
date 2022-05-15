#ifndef _CDONANTE_H
#define _CDONANTE_H
#include "gbl.h"
#include "cLista.h"
#include "cOrgano.h"
#include "cPaciente.h"
#include "cFecha.h"
class cDonante: public cPaciente
{
    public:

        #pragma region Constructor_Destructor
        
        /// <summary>
        /// Constructor parametrizado por defecto
        /// </summary>
        /// <param name="_nombre">: Nombre del donante</param>
        /// <param name="_sexo">: Sexo del donante</param>
        /// <param name="_telefono">: Telefono del donante</param>
        cDonante(string _nombre = "", string _sexo = "", string _telefono = "");

        /// <summary>
        /// Destructor por defecto
        /// </summary>
        ~cDonante();

        #pragma endregion

        #pragma region Metodos

        /// <summary>
        /// Setea la lista de organos
        /// </summary>
        /// <param name="lista">: Lista a setear</param>
        /// <returns>True en caso de seteaerla, false en caso contrario</returns>
        bool setLista(cLista<cOrgano>* lista) {
            try {
                if (!lista)
                    throw exception("No se puede pasar como parametro una lista de organos vacia");
                else if (listaOrgano)
                    throw exception("La lista de organos ya fue inicializada anteriormente");
                this->listaOrgano = lista;
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

        bool asignarVehiculo(cVehiculo* vehiculo);

        cOrgano* iniciarAblacion(cOrgano* _receptor);
        #pragma endregion   
    private:

        #pragma region Atributos

        cLista<cOrgano>* listaOrgano;

        #pragma endregion

};

#endif // _CDONANTE_H