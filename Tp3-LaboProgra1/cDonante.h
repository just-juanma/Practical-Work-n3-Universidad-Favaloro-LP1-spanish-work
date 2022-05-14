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
        cDonante(string _nombre = "", string _sexo = "", string _telefono = "",
                 cFecha* _nacimiento = NULL, eTipoSangre _tipo = sinTipo);

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
        void setLista(cLista<cOrgano>* lista) {
            if (!lista && listaOrgano)
                 this->listaOrgano = lista;
            throw exception("No se pudo asignar la lista de organos al donante");
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

        void setFechaMuerte(cFecha* _muerte) {
            if (!_muerte && muerte) 
                this->muerte = _muerte;  
            throw exception("No se pudo asignar la fecha de muerte al donante");
        }

        void asosciarCentro(cCentroSalud* _centro) {
            if (!_centro && centroSalud) 
                this->centroSalud = _centro;   
            throw exception("No se pudo asignar el centro al donante");
        }

        void deasociarCentro() {
            if (!centroSalud) {
                this->centroSalud = NULL;
            }
            throw exception("No se pudo desasignar el centro al donante");
        }

        cCentroSalud* getCentro() const  { 
            if(centroSalud)
                return this->centroSalud;
            throw exception("No se pudo obtener el centro del donante");
        }

        // adri, si necesitas esto: descomentalo e implementalo
        /* bool asignarVehiculo(cVehiculo* vehiculo);

         cOrgano* iniciarAblacion(cOrgano* receptor, cFecha* fecha);*/

        #pragma endregion   

    private:

        #pragma region Atributos

        cLista<cOrgano>* listaOrgano;
        cFecha* muerte;
        cFecha* ablacion;

        #pragma endregion

};

#endif // _CDONANTE_H