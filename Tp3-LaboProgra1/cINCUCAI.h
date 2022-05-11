#ifndef _CINCUCAI_H
#define _CINCUCAI_H
#include "gbl.h"
#include "cLista.h"
#include "cReceptor.h"
#include "cDonante.h"
#include "cAvion.h"
#include "cHelicoptero.h"
#include "cAmbulancia.h"

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

        //void recibirPaciente(void cPaciente);

        //cLista buscar(void cLista);
    
        // void pedirVehiculo();

        void Protocolo_de_Transporte_y_Transplantes(cDonante* donante, cReceptor* receptor);
    private: 

        // void ordenarPrioridad();

        #pragma endregion

        #pragma region Atributos

        bool match;
        cLista<cDonante>* listaDonantes;
        cLista<cReceptor>* listaReceptores;
        #pragma endregion

};

#endif //_CINCUCAI_H