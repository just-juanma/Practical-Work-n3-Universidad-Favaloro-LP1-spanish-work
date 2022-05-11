#ifndef _CRECEPTOR_H
#define _CRECEPTOR_H
#include "gbl.h"
#include "cPaciente.h"

class cReceptor : public cPaciente 
{
    public: 

        #pragma region Constructor_Destructor
        
        /// <summary>
        /// Constructor parametrizado por defecto
        /// </summary>
        /// <param name="_nombre": Nombre del receptor></param>
        /// <param name="_sexo">: Sexo del receptor</param>
        /// <param name="_telefono">: Telefono del receptor</param>
        /// <param name="_patologia">: Patologia del receptor</param>
        cReceptor(string _nombre = "", string _sexo = "", string _telefono = "", string _patologia = "");

        /// <summary>
        /// Destructor por defecto
        /// </summary>
        ~cReceptor();
    
        #pragma endregion

        #pragma region Metodos

        void setOrganoNecesitado(cOrgano* organo) {
            this->organoNecesario = organo;
        }

        cOrgano* getOrganoNecesitado()const { 
            return this->organoNecesario;
        }

        /// <summary>
        /// Concatena a un solo string los atributos pertinentes
        /// </summary>
        /// <returns>String concatenado</returns>
        string to_string();

        /// <summary>
        /// Imprime to_string()
        /// </summary>
        void imprimir() {
            cout << to_string() << endl;
        }

        #pragma endregion

    private: 

        #pragma region Atributos
    
        string patologia;
        cOrgano* organoNecesario;
        cFecha* fechaListaEnEspera;

        #pragma endregion

};

#endif // _CRECEPTOR_H