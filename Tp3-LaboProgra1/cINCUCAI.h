#ifndef _CINCUCAI_H
#define _CINCUCAI_H
#include "gbl.h"
#include "cLista.h"
#include "cReceptor.h"
#include "cDonante.h"
#include "cCentroSalud.h"

class cINCUCAI {

    public:

        #pragma region Constructor_Destructor

        /// <summary>
        /// Constructor por defecto
        /// </summary>
        cINCUCAI();
     
        ~cINCUCAI();

        #pragma endregion

        #pragma region Metodos

        /// <summary>
        /// Setea la lista de centros
        /// </summary>
        /// <param name="lista">: Lista a setear</param>
        void setCentros(cLista<cCentroSalud>* lista) {
            if(lista && !listaCentros)
                this->listaCentros = lista; return;
            throw exception("No se pudo iniciar la lista de centros");
        }

        /// <summary>
        /// La funcion propone 
        ///     1. Castear segun sea el tipo de paciente y agregar a la lista pertinente
        ///     2. Verificar que no se repita mediante el unico ID a considerar: el numero de telefono
        /// </summary>
        /// <param name="paciente">: Paciente a analizar</param>
        void agregarPaciente(cPaciente* paciente);


        /// <summary>
        /// Llama a la funcion "ingresarPaciente"
        /// </summary>
        /// <param name="paciente">: Paciente a recibir, bienvenido!</param>
        void recibirPaciente(cPaciente* paciente);

        /// <summary>
        /// Proceso del match pedido por el tp se encuentra en esta funcion
        /// </summary>
        cLista<cPaciente>* ingresarPaciente(cPaciente* paciente);

        /// <summary>
        /// Mediante este metodo se le transplanta el organo solicitado a un receptor especifico
        /// </summary>
        /// <param name="_organo">Organo a transpsportar y transplantar</param>
        /// <param name="_receptor">Quien lo va a recibir</param>
        void protocoloDeTransporteYTrasplante(cOrgano* _organo, cReceptor* _receptor, cCentroSalud* centro_salud);

        /// <summary>
        /// Devuelve la lista de organos ya removidos del donante con la hora de la ablacion seteada
        /// </summary>
        /// <param name="_donante">: Recibe el donante al que se le llamara la ablacion  </param>
        /// <param name="tipoOrgano">: Organo a quitar</param>
        /// <returns>Organo obtenido en la ablacion</returns>
        cOrgano* Ablacion(cDonante* _donante, eOrgano tipoOrgano);

        /// <summary>
        /// Busca en la lista de receptores segun el organo 
        /// </summary>
        /// <param name="organo">: Organo a filtrar</param>
        /// <returns>Listado de receptores que necesitan el organo</returns>
        cLista<cReceptor>* buscarPorOrgano(cOrgano* organo) {
            cLista<cReceptor>* receptores = new cLista<cReceptor>(this->listaReceptores->cantActual, false);
            for (ush i = 0; i < this->listaReceptores->cantActual; i++) 
                if (organo->getTipoOrgano() == this->listaReceptores->lista[i]->getOrganoNecesitado()->getTipoOrgano())
                    *receptores + this->listaReceptores->lista[i];
            return receptores;
        }

        /// <summary>
        /// Busca en la lista de receptores segun el centro
        /// </summary>
        /// <param name="organo">: Centro a filtrar</param>
        /// <returns>Listado de receptores que se encuentran en el mismo centro</returns>
        cLista<cReceptor>* buscarPorCentro(cCentroSalud* centro) {
            cLista<cReceptor>* receptores = new cLista<cReceptor>(this->listaReceptores->cantActual, false);
            for (ush i = 0; i < this->listaReceptores->cantActual; i++) 
                if (centro == this->listaReceptores->lista[i]->getCentro()) 
                    *receptores + this->listaReceptores->lista[i];
            return receptores;
        }
        
        /// <summary>
        /// Busca el receptor en la lista de receptores
        /// </summary>
        /// <param name="receptor">: Receptor a buscar</param>
        void imprimirReceptor(cReceptor* receptor) {
            for (ush i = 0; i < this->listaReceptores->cantActual; i++) 
                if (receptor == this->listaReceptores->lista[i]) {
                    cout << "Prioridad de " << receptor->getNombre() << ": " << receptor->getPrioridad();
                    return;
                }
             throw exception("No se encontro al receptor");
        }
        
        /// <summary>
        /// Calcula en la hora local si es fin de mes. De ser asi, recorre las donaciones de todos los centros. 
        /// En caso de que coincida la provincia, acumulo la cantidad de donaciones, luego imprimo su total
        /// IMPORTANTE: a partir del dia 28 de cada mes ya se considera fin de mes
        /// </summary>
        void informeFinDeMes() {
            ush suma = 0;
            time_t local;
            struct tm nuevoMes;
            time(&local);
            nuevoMes = *localtime(&local);
            nuevoMes.tm_mday = 28;
            if (difftime(local, mktime(&nuevoMes)) >= 0) {
                for (ush i = 0; i < listaCentros->cantActual - 1; i++) {
                    suma += listaCentros->lista[i]->getCantDonProv();
                    for (ush j = i + 1; j < listaCentros->cantActual; j++)
                        if (listaCentros->lista[i]->getProvincia() == listaCentros->lista[j]->getProvincia())
                            suma += listaCentros->lista[i]->getCantDonProv();
                    cout << "Cantidad de donaciones en " << listaCentros->lista[i]->getNombre() << "es: " << suma;
                    suma = 0;
                }
            }
            else
                throw exception("Aun no es fin de mes");
        }

        /// <summary>
        /// Setea las listas de donantes y receptores
        /// </summary>
        /// <param name="lista1">: Lista a setear de donantes</param>
        /// <param name="lista2">: Lista a setear de receptores</param>
        void setListas(cLista<cDonante>* lista1, cLista<cReceptor>* lista2) {
            listaDonantes = lista1;
            listaReceptores = lista2;
        }

        /// <summary>
        /// Imprime las listas pedidas
        /// </summary>
        void imprimir() {
            cout << listaDonantes->to_string() << endl;
            cout << listaReceptores->to_string() << endl;
            cout << listaCentros->to_string() << endl;
        }

    private: 

        #pragma endregion

        #pragma region Atributos

        cLista<cDonante>* listaDonantes;
        cLista<cReceptor>* listaReceptores;
        cLista<cCentroSalud>* listaCentros;

        #pragma endregion

};

#endif _CINCUCAI_H