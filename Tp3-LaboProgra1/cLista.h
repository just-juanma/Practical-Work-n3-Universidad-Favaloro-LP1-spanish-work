#ifndef _CLISTA_H
#define _CLISTA_H
#include "gbl.h"

template <typename T>

class cLista 
{
    friend class cCentroSalud;
    friend class cVehiculo;
    friend class cINCUCAI;
    friend class cDonante;
    public: 
    
        #pragma region Constructor_Destructor

        /// <summary>
        /// Constructor parametrizado por defecto
        /// </summary>
        /// <param name="size">Tamanio de la lista, macro MAX por defecto</param>
        /// <param name="_checkEliminar">: La lista se puede eliminar (true), false en caso contrario</param>
        inline cLista(sh size = MAX, bool _checkEliminar = false) {
            this->cantActual = 0;
            this->checkEliminar = _checkEliminar;
            try {
                this->lista = new T * [size];
                if (!this->lista)
                    throw(bad_alloc());
            }
            catch (exception& e) {
                cout << e.what() << endl;
            }
            this->cantTotal = size;
            for (ush i = 0; i < this->cantTotal; i++)
                this->lista[i] = NULL;
        }

        /// <summary>
        /// Destructor por defecto
        /// </summary>
        inline ~cLista() {
            try {
                if (this->checkEliminar) {
                    for (ush i = 0; i < cantActual; i++)
                        if (this->lista[i])
                            delete this->lista[i];
                }
                else
                    throw exception("Error: No se puede destruir la lista si no se le da el permiso para eliminarlo");
            }
            catch (exception& e) {
                cout << e.what() << endl;
            }
            delete[] this->lista;

        }

        #pragma endregion

        #pragma region Metodos
        
        inline ush buscar(T* elemento) {
            for (ush i = 0; i < this->cantActual; i++) 
                if (elemento && elemento == this->lista[i]) 
                    return i;
            return -1;
        }

        /// <summary>
        /// Concatena a un solo string los atributos pertinentes
        /// </summary>
        /// <returns>String concatenado</returns>
        inline string to_string() {
            stringstream stc;
            stc << "Checkeo de eliminar (true / si) (false / no): " << this->checkEliminar << endl;
            stc << "Cantidad total de elementos: " << this->cantActual << endl;
            stc << "Cantidad actual de elementos: " << this->cantTotal << endl;
            for (ush i = 0; i < this->cantActual; i++) {
                stc << "Elemento [" << i << "]" << endl << lista[i]->to_string() << endl;
            }
            return stc.str();
        }
        
        /// <summary>
        /// Aagrega un elemento a la lista
        /// </summary>
        /// <param name="elemento">: Elemento a agregar</param>
        /// <returns>True en caso de poder agregarlo, false en caso contrario</returns>
        inline void agregar(T* elemento) {
	        if (this->cantActual > this->cantTotal)
	        	throw exception("La cantidad actual de la lista es mayor a la cantidad total");
	        else if (!elemento)
	        	throw exception("El elemento que se intenta agregar no existe");
	        else if (lista[this->cantActual])
	        	throw exception("La posicion del elemento que se intenta ocupar ya esta ocupada");
	        this->lista[this->cantActual++] = elemento;
               return;
        }
    
        /// <summary>
        /// Quita un elemento de la lista
        /// </summary>
        /// <param name="elemento">: Elemento a quitar</param>
        /// <returns>True en caso de poder quitarlo, false en caso contrario</returns>
        inline T* quitar(T* elemento) {
            for (ush i = 0; i < this->cantActual; i++)
                if (lista[i] && this->lista[i] == elemento) {
                    T* aux = this->lista[i];
                    this->lista[i] = NULL;
                    ordenar();
                    return aux;
                }
            throw exception("No se pudo quitar el elemento ingresado");
        }
        
        #pragma endregion

        #pragma region Sobrecarga

        void operator+(T* elemento) {
           agregar(elemento);
        }

        T* operator-(T* elemento) {
            T* aa = quitar(elemento);
            this->cantActual--;
            return (aa);
        }

        T* operator[](sh i) {
            if (i >= 0 && i < cantActual)
                return this->lista[i];
            throw exception("Se esta intentando acceder a un elemento imposible de acceder");
        }

        friend ostream& operator << (ostream& out, T* elemento) {
            return out << to_string() << endl;
        }

        #pragma endregion

    protected: 

        #pragma region Funciones_Auxiliares

        inline void ordenar() {
            for (ush i = 0; i < this->cantActual; i++)
                for (ush j = i; j < this->cantActual - 1; j++)
                    if (!this->lista[i])
                        swap(this->lista[j], this->lista[j + 1]);
        }

        #pragma endregion

        #pragma region Atributos

        T** lista;
        ush cantActual;
        sh cantTotal;
        bool checkEliminar;

        #pragma endregion

};

#endif // _CLISTA_H

    