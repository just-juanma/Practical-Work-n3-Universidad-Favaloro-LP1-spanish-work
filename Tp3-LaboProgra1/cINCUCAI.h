#ifndef _CINCUCAI_H
#define _CINCUCAI_H
#include "gbl.h"
#include "cLista.h"
#include "cReceptor.h"
#include "cDonante.h"
#include "cCentroSalud.h"

class cINCUCAI {

    public:

        #pragma region Constructor_Destructor

        /// <summary>
        /// Constructor por defecto
        /// </summary>
        cINCUCAI();

        ~cINCUCAI();

        #pragma endregion

        #pragma region Metodos

        void setCentros(cLista<cCentroSalud>* lista) {
            this->listaCentros = lista;
        }

        void agregarPaciente(cPaciente* paciente);
        void recibirPaciente(cPaciente* paciente);
        void ingresarPaciente(cPaciente* paciente);

        /// <summary>
        /// Mediante este metodo se le transplanta el organo solicitado a un receptor especifico
        /// </summary>
        /// <param name="_organo">Organo a transpsportar y transplantar</param>
        /// <param name="_receptor">Quien lo va a recibir</param>
        void Protocolo_de_Transporte_y_Transplantes(cOrgano* _organo, cReceptor* _receptor);
        /// <summary>
        /// Devuelve la lista de organos ya removidos del donante con la hora de la ablacion seteada
        /// </summary>
        /// <param name="_dontante"></param>
        /// <returns></returns>
        cLista<cOrgano>* Ablacion(cDonante* _dontante);
    private: 

        // void ordenarPrioridad();

        #pragma endregion

        #pragma region Atributos

        bool match;
        cLista<cDonante>* listaDonantes;
        cLista<cReceptor>* listaReceptores;
        cLista<cCentroSalud>* listaCentros;

        #pragma endregion

};

#endif _CINCUCAI_H