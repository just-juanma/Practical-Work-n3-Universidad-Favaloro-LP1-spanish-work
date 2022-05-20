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
                  cFecha* _nacimiento = NULL, eTipoSangre _tipo = tipoDesconocido);

        /// <summary>
        /// Destructor por defecto
        /// </summary>
        ~cPaciente();
    
        #pragma endregion
         
        #pragma region Metodos

        /// <summary>
        /// Asocia el centro al paciente hijo
        /// </summary>
        /// <param name="_centro">: Centro a asociar</param>
        void asociarCentro(cCentroSalud* _centro) {
            if (_centro && !centroSalud)
                this->centroSalud = _centro;
            else 
                throw exception("No se pudo asignar el centro al donante");
        }
        
        string getNombre() {
            return this->nombre;
        }

        /// <summary>
        /// Obtiene el centro del paciente hijo
        /// </summary>
        /// <returns>Centro del donante</returns>
        cCentroSalud* getCentro() {
            if (centroSalud)
                return this->centroSalud;
            else
                throw exception("No se pudo obtener el centro del donante");
        }

        string getTelefono() {
            return this->telefono;
        }

        /// <summary>
        /// Metodo abstracto: Concatena a un solo string los atributos pertinentes en las clases hijas
        /// </summary>
        /// <returns>: String concatenado</returns>
        virtual string to_string() = 0;

        /// <summary>
        /// Imprime to_string() de la clase hija
        /// </summary>
        void imprimir() {
            cout << to_string() << endl;
        }

        #pragma endregion

    protected: 

        #pragma region Atributos
        
        const string nombre;
        const string sexo;
        const string telefono;
        cFecha* nacimiento;
        cCentroSalud* centroSalud;
        eTipoSangre tipoSangre; 
    
        #pragma endregion       
};

#endif // _CPACIENTE_H