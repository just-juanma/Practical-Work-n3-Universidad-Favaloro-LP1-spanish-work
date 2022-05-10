#ifndef _CINCUCAI_H
#define _CINCUCAI_H
#include "gbl.h"

class cINCUCAI {

    public:

        #pragma region Constructor_Destructor
    
        cINCUCAI(bool _match = false);

        ~cINCUCAI();

        #pragma endregion

        #pragma region Metodos

        //void recibirPaciente(void cPaciente);

        //cLista buscar(void cLista);
    
        // void pedirVehiculo();


    private: 

        // void ordenarPrioridad();

        #pragma endregion

        #pragma region Atributos

        bool match;

        #pragma endregion

};

#endif //_CINCUCAI_H