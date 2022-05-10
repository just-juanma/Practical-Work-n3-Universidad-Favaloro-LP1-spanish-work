#ifndef _CFECHA_H
#define _CFECHA_H
#include "gbl.h"

class cFecha {
    public:

        #pragma region Constructor_Destructor
        
        cFecha(time_t _local);
        
        ~cFecha();
        
        #pragma endregion

    private: 
    
        #pragma region Atributos
        
        time_t local;   

        #pragma endregion

};

#endif // _CFECHA_H