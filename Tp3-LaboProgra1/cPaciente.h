#ifndef _CPACIENTE_H
#define _CPACIENTE_H
#include "gbl.h"
#include "cCentroSalud.h"

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

        /// <summary>
        /// Metodo abstracto: summary en correspondientes clases hijas
        /// </summary>
        /// <param name="_centro"></param>
        /// <returns></returns>
        bool asociarCentro(cCentroSalud* _centro) { this->CentroDeSalud = _centro; }
        
        virtual string to_string() = 0;

        virtual void imprimir() = 0;
        
        #pragma endregion


        cCentroSalud* getCentro() { return this->CentroDeSalud; }
    protected: 
        #pragma region metodos

        #pragma region Atributos
        
        const string nombre;
        const string sexo;
        const string telefono;
        bool RoD;
    
        #pragma endregion
    private:   
        cCentroSalud* CentroDeSalud;
};

#endif // _CPACIENTE_H