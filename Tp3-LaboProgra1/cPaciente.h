#ifndef _CPACIENTE_H
#define _CPACIENTE_H
#include "gbl.h"
#include "cCentroSalud.h"
#include "cFecha.h"

class cPaciente 
{

    public: 
        #pragma region Constructor_Destructor
        
        /// <summary>
        /// Constructor parametrizado por defecto
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
         
        #pragma region Metodos

       // bool asociarCentro(cCentroSalud* _centro) { this->CentroDeSalud = _centro; }
        
        /// <summary>
        /// Metodo abstracto: Concatena a un solo string los atributos pertinentes en las clases hijas
        /// </summary>
        /// <returns>: String concatenado</returns>
        virtual string to_string() = 0;

        /// <summary>
        /// Metodo abstracto: Imprime to_string() definido en las clases hijas
        /// </summary>
        virtual void imprimir() = 0;
        
      //  cCentroSalud* getCentro() { return this->CentroDeSalud; }
        
        #pragma endregion

    protected: 

        #pragma region Atributos
        
        const string nombre;
        const string sexo;
        const string telefono;
        cFecha* nacimiento;
        eTipoSangre tipoSange;
        bool RoD;
        cCentroSalud* CentroDeSalud;
    
        #pragma endregion       
};

#endif // _CPACIENTE_H