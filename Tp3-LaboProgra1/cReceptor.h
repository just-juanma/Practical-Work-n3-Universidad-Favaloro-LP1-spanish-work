#ifndef _CRECEPTOR_H
#define _CRECEPTOR_H
#include "gbl.h"
#include "cPaciente.h"
#include "cOrgano.h"
#include "cVehiculo.h"

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
        cReceptor(string _nombre = "", string _sexo = "", string _telefono = "", string _patologia = "",
                  cFecha* _nacimiento = NULL, cFecha* _fechaListaEnEspera = NULL, eTipoSangre _tipo = tipoDesconocido, bool _EoI = false);

        /// <summary>
        /// Destructor por defecto
        /// </summary>
        ~cReceptor();
    
        #pragma endregion

        #pragma region Metodos

        /// <summary>
        /// Setea el organo que necesita el receptor
        /// </summary>
        /// <param name="organo">: Organo a settear</param>
        void setOrganoNecesitado(cOrgano* organo) {
            if (!this->organoNecesario && organo) 
                this->organoNecesario = organo;
            else
                throw exception("No se puede asignar el organo necesitado al receptor");
            
        }

        /// <summary>
        /// Obtiene el organo necesitado
        /// </summary>
        /// <returns>Organo necesitado</returns>
        cOrgano* getOrganoNecesitado() { 
            if(this->organoNecesario)
                return this->organoNecesario;
            throw exception("No fue asignado ningun organo previamente al receptor");
        }

        eTipoSangre getTipoSangre()const {
                return this->tipoSangre;
        }

        ePrioridad getPrioridad()const {
            return this->prioridad;
        }

        /// <summary>
        /// Setea la prioridad del receptor
        /// </summary>
        /// <param name="_prioridad">: prioridad nueva del receptor</param>
        void setPrioridad(ePrioridad _prioridad) {
             this->prioridad = _prioridad;
        }

        /// <summary>
        /// Concatena a un solo string los atributos pertinentes
        /// </summary>
        /// <returns>String concatenado</returns>
        string to_string();

        /// <summary>
        /// Cambia el estado del paciente
        /// </summary>
        /// <param name="_estado"></param>
        void switchEstabilidad() {
            if (this->EoI == true) {
                this->EoI = false;
            }
            else {
                this->EoI = true;
            }
        }

        bool inicarTransplante(cOrgano* _organotransportado) {
            time_t local;
            if (difftime(time(&local), _organotransportado->getFechaAblacion()->getFechaAblacion()) / 3600 <= 20) {
                this->organoNecesario = _organotransportado;
                float azar = rand() % 2;
                if (azar > (1 / 2)) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else
                throw exception("Se excedieron las 20 horas desde la ablacion");
        }

        #pragma endregion

    private: 

        #pragma region Atributos
    
        string patologia;
        cOrgano* organoNecesario;
        cFecha* fechaListaEnEspera;
        ePrioridad prioridad;
        bool EoI;

        #pragma endregion

};

#endif // _CRECEPTOR_H