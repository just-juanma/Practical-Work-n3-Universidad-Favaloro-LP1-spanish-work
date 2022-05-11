#ifndef _CLISTA_H
#define _CLISTA_H
#include "gbl.h"

template <typename T>

class cLista 
{
    friend class cCentroSalud;
    public: 
    
        #pragma region Constructor_Destructor

        /// <summary>
        /// Constructor parametrizado por defecto
        /// </summary>
        /// <param name="size">Tamanio de la lista, macro MAX por defecto</param>
        /// <param name="_checkEliminar">: La lista se puede eliminar (true), false en caso contrario</param>
        cLista(sh size = MAX, bool _checkEliminar = false);

        /// <summary>
        /// Destructor por defecto
        /// </summary>
        ~cLista();

        #pragma endregion
        
        #pragma region Metodos

        /// <summary>
        /// Aagrega un elemento a la lista
        /// </summary>
        /// <param name="elemento">: Elemento a agregar</param>
        /// <returns>True en caso de poder agregarlo, false en caso contrario</returns>
        bool agregar(T* elemento);
    
        /// <summary>
        /// Quita un elemento de la lista
        /// </summary>
        /// <param name="elemento">: Elemento a quitar</param>
        /// <returns>True en caso de poder quitarlo, false en caso contrario</returns>
        T* quitar(T* elemento);
        
        #pragma endregion

        #pragma region Sobrecarga

        /// <summary>
        /// Sobrecarga del operador + para agregar elementos a la lista
        /// </summary>
        /// <param name="elemento">: Elemento a agregar</param>
        /// <returns>Lista nueva con el elemento agregado</returns>
        cLista* operator+(T& elemento) {
            if (agregar(&elemento))
                return this;
        }

        /// <summary>
        /// Sobrecarga del operador - para quitar elementos a la lista
        /// </summary>
        /// <param name="elemento">: Elemento a quitar</param>
        /// <returns>Lista nueva con el elemento quitado</returns>
        cLista* operator-(T& elemento) {
            if (quitar(&elemento))
                return this;
        }
        
        /// <summary>
        /// Accede a la i-nesima posicion de la lista y la devuelve
        /// </summary>
        /// <param name="i">: i-esima posicion a la que se busca acceder</param>
        /// <returns></returns>
        cLista* operator[](sh i) {
            if (i >= 0 && i < cantActual)
                return this->lista[i];
            throw exception("Se esta intentando acceder a un elemento imposible de acceder");
        }

        int buscar(T* elemento) {
            for (int i = 0; i < this->cantActual; i++) {
                if (T & elemento == this->lista[i]) {
                    i;
                }
            }

        }

        /// <summary>
        /// Concatena a un solo string los atributos pertinentes
        /// </summary>
        /// <returns>String concatenado</returns>
        string to_string();

        #pragma endregion

    protected: 

        #pragma region Funciones_Auxiliares

        void ordenar();

        #pragma endregion

        #pragma region Atributos

        T** lista;
        ush cantActual;
        sh cantTotal;
        bool checkEliminar;

        #pragma endregion

};

#endif // _CLISTA_H

        #pragma region Ostream

        //template <typename T>
        /// <summary>
        /// Sobrecarga el operador << para impresion de las listas
        /// </summary>
        /// <param name="out">: Flujo de salida</param>
        /// <param name="_vuelo">: Impresion del vuelo indicado</param>
        /// <returns>Nuevo flujo de salida</returns>
        //ostream& operator << (ostream& out, T* elemento);

        #pragma endregion