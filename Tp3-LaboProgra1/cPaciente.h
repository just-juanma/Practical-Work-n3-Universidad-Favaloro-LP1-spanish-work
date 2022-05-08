#ifndef _CPACIENTE_H
#define _CPACIENTE_H
#include "gbl.h"

class cPaciente 
{

    public: 
        #pragma region Constructor_Destructor
        
        /// <summary>
        /// Constructor por defecto parametrizado
        /// </summary>
        /// <param name="nombre">: Nombre del paciente</param>
        /// <param name="sexo">: Sexo del paciente</param>
        /// <param name="telefono">: Telefono del paciente</param>
        /// <param name="RoD">: Receptor (true), Donante (false)</param>
        cPaciente(string _nombre = "", string _sexo = "", string _telefono = "", bool _RoD = false);

        /// <summary>
        /// Destructor por defecto
        /// </summary>
        ~cPaciente();
    
        #pragma endregion

        virtual string getTelefono() const = 0;
            
        

        //virtual bool asociarCentro(cCentro _centro) = 0; falta el centro
          
    protected: 
        #pragma region Atributos
        
        const string nombre;
        const string sexo;
        const string telefono;
        bool RoD;
    
        #pragma endregion
};

#endif // _CPACIENTE_H