#ifndef _CLISTA_H
#define _CLISTA_H
#include "gbl.h"

template <typename T>

class cLista 
{

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
        
        #pragma region metodos

        /// <summary>
        /// Aagrega un elemento a la lista
        /// </summary>
        /// <param name="elemento">: Elemento a agregar</param>
        /// <returns>True en caso de poder agregarlo, false en caso contrario</returns>
        void agregar(T* elemento);

        /// <summary>
        /// Aagrega un elemento a la lista
        /// </summary>
        /// <param name="elemento">: Elemento a agregar</param>
        /// <returns>True en caso de poder agregarlo, false en caso contrario</returns>
        template <typename cPaciente>
        void agregar(cPaciente* elemento);
        
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
        cLista* operator+(T& elemento);

        /// <summary>
        /// Sobrecarga del operador - para quitar elementos a la lista
        /// </summary>
        /// <param name="elemento">: Elemento a quitar</param>
        /// <returns>Lista nueva con el elemento quitado</returns>
        cLista* operator-(T& elemento);
        
        /// <summary>
        /// Accede a la i-nesima posicion de la lista y la devuelve
        /// </summary>
        /// <param name="i">: i-esima posicion a la que se busca acceder</param>
        /// <returns></returns>
        cLista* operator[](sh i);
        
        #pragma endregion

    protected: 

        template <typename cPaciente>
        bool isValidPaciente(cPaciente* posiblePaciente) const {
            for (ush i = 0; i < cantActual; i++)
                if (posiblePaciente->getTelefono == lista[i]->getTelefono)
                    return false;
            return true;
        }

        void ordenar();

        #pragma region atributos

        T** lista;
        ush cantActual;
        sh cantTotal;
        bool checkEliminar;

        #pragma endregion

};

#endif // _CLISTA_H

        template <typename T>
        /// <summary>
        /// Sobrecarga el operador << para impresion de las listas
        /// </summary>
        /// <param name="out">: Flujo de salida</param>
        /// <param name="_vuelo">: Impresion del vuelo indicado</param>
        /// <returns>Nuevo flujo de salida</returns>
        ostream& operator << (ostream& out, T* elemento);