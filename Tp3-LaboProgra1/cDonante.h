#ifndef _CDONANTE_H
#define _CDONANTE_H
#include "gbl.h"
#include "cLista.h"
#include "cOrgano.h"
#include "cPaciente.h"
#include "cFecha.h"

class cDonante: public cPaciente
{
    friend class cINCUCAI;

    public:

        #pragma region Constructor_Destructor
        
        /// <summary>
        /// Constructor parametrizado por defecto
        /// </summary>
        /// <param name="_nombre">: Nombre del donante</param>
        /// <param name="_sexo">: Sexo del donante</param>
        /// <param name="_telefono">: Telefono del donante</param>
        cDonante(string _nombre = "", string _sexo = "", string _telefono = "",
                 cFecha* _nacimiento = NULL, eTipoSangre _tipo = tipoDesconocido);

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
            if (lista && !listaOrgano)
                 this->listaOrgano = lista;
            else
                throw exception("No se pudo asignar la lista de organos al donante");
        }

        /// <summary>
        /// Setea la fecha de muerte del donante
        /// </summary>
        /// <param name="_muerte">: Fecha de muerte del donante</param>
        void setFechaMuerte(cFecha* _muerte) {
            if (_muerte && !muerte) 
                this->muerte = _muerte;  
            else
                throw exception("No se pudo asignar la fecha de muerte al donante");
        }

        /// <summary>
        /// Asocia el centro al donante
        /// </summary>
        /// <param name="_centro">: Centro a asociar</param>
        void asociarCentro(cCentroSalud* _centro) {
            if (_centro && !centroSalud) 
                this->centroSalud = _centro;   
            throw exception("No se pudo asignar el centro al donante");
        }

        /// <summary>
        /// Obtiene el centro del donante
        /// </summary>
        /// <returns>Centro del donante</returns>
        cCentroSalud* getCentro() { 
            if(centroSalud)
                return this->centroSalud;
            throw exception("No se pudo obtener el centro del donante");
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

        /// <summary>
        /// el centro procede a realizar la ablación del órgano que necesita el receptor. En
        /// la ablación se setea la fecha y horario de ablación del órgano y se quita el órgano removido
        /// de la lista de órganos del paciente donante
        /// </summary>
        /// <param name="_receptor"></param>
        cOrgano* iniciarAblacion(cOrgano* _receptor) {
            time_t temp;
            ablacion->setFechaAblacion(time(&temp));
            cOrgano* organoQuitado = *listaOrgano - _receptor;
            return organoQuitado;
        }

        #pragma endregion   

    private:

        #pragma region Atributos

        cLista<cOrgano>* listaOrgano;
        cFecha* muerte;
        cFecha* ablacion;
        cVehiculo* vehiculo;

        #pragma endregion

};

#endif // _CDONANTE_H