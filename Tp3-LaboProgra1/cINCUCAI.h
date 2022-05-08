/**
 * Project Untitled
 */


#ifndef _CINCUCAI_H
#define _CINCUCAI_H

class cINCUCAI {
public: 
    
void cINCUCAI();
    
/**
 * @param cPaciente
 */
void recibirPaciente(void cPaciente);
    
/**
 * @param cLista
 */
cLista buscar(void cLista);
    
void pedirVehiculo();
protected: 
    
void cINCUCAI();
private: 
    bool match;
    
void ordenarPrioridad();
};

#endif //_CINCUCAI_H