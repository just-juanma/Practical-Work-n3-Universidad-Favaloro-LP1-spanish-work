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
        cPaciente(string _nombre = "", string _sexo = "", string _telefono = "", 
                  cFecha* _nacimiento = NULL, eTipoSangre _tipo = tipoDesconocido, bool _RoD = false);

        /// <summary>
        /// Destructor por defecto
        /// </summary>
        ~cPaciente();
    
        #pragma endregion
         
        #pragma region Metodos

       /// <summary>
       /// metodo abstracto: recibe un centro, y lo asigna en las clases hijas
       /// </summary>
       /// <param name="_centro"></param>
       /// <returns></returns>
        virtual void asociarCentro(cCentroSalud* _centro) = 0;
        
        virtual cCentroSalud* getCentro() = 0;

        /// <summary>
        /// Metodo abstracto: Concatena a un solo string los atributos pertinentes en las clases hijas
        /// </summary>
        /// <returns>: String concatenado</returns>
        virtual string to_string() = 0;

        /// <summary>
        /// Metodo abstracto: Imprime to_string() definido en las clases hijas
        /// </summary>
        virtual void imprimir() = 0;
        
        
        #pragma endregion

    protected: 

        #pragma region Atributos
        
        const string nombre;
        const string sexo;
        const string telefono;
        cFecha* nacimiento;
        cCentroSalud* centroSalud;
        eTipoSangre tipoSangre;
        bool RoD;
    
        #pragma endregion       
};

#endif // _CPACIENTE_H