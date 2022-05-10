#include "cLista.h"

// implementacion cLista

template <typename T>
cLista<T>::cLista(sh size, bool _checkEliminar) {
	this->cantActual = 0;
	this->checkEliminar = _checkEliminar;
	this->lista = new T * [size];
	if (!this->lista)
		throw(bad_alloc());
	this->cantTotal = size;
	for (ush i = 0; i < this->cantTotal; i++) 
		this->lista[i] = NULL;
}

template <typename T>
cLista<T>::~cLista() {
	if (this->checkEliminar) {
		for (ush i = 0; i < cantActual; i++)
			if (this->lista[i])
				delete this->lista[i];
	} else
		throw exception("Error: No se puede destruir la lista si no se le da el permiso para eliminarlo");
	delete[] this->lista;
	
}

template <typename T>
bool cLista<T>::agregar(T* elemento) {
	try {
		if (this->cantActual > this->cantTotal)
			throw exception("La cantidad actual de la lista es mayor a la cantidad total");
		else if (!elemento)
			throw exception("El elemento que se intenta agregar no existe");
		else if (lista[this->cantActual])
			throw exception("La posicion del elemento que se intenta ocupar ya esta ocupada");
		this->listaPasajero[this->cantActual++] = elemento;
		return true;
	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
		return false;
	}
}

template <typename T>
T* cLista<T>::quitar(T* elemento) {
	for (ush i = 0; i < this->cantActual; i++) 
		if (lista[i] && this->lista[i] == elemento) {
			T* aux = this->lista[i];
			this->lista[i] = NULL;
			ordenar();
			return aux;
		}
	return NULL;
}

template <typename T>
void cLista<T>::ordenar() {
	for (ush i = 0; i < this->cantActual; i++)
		for (ush j = i; j < this->cantActual - 1; j++)
			if (!this->lista[i])
				swap(this->lista[j], this->lista[j + 1]);
}

template <typename T>
string cLista<T>::to_string() {
	stringstream stc;
	stc << "Checkeo de eliminar (true / si) (false / no): " << this->checkEliminar << endl;
	stc << "Cantidad total de elementos: " << this->cantActual << endl;
	stc << "Cantidad actual de elementos: " << this->cantTotal << endl;
	for (ush i = 0; i < this->cantActual; i++) {
		stc << "Elemento [" << i << "]" << endl << lista[i]->to_string() << endl;
	}
}

//template <typename T>
//ostream& operator << (ostream& out, T* elemento) {
//	out << elemento->to_string();
//	return out;
//}