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
	// no tengo algo que eliminar
}

template <typename T>
void cLista<T>::agregar(T* elemento) {
	if (this->cantActual > this->cantTotal)
		throw exception("La cantidad actual de la lista es mayor a la cantidad total");
	else if (!elemento)
		throw exception("El elemento que se intenta agregar no existe");
	else if (lista[this->cantActual])
		throw exception("La posicion del elemento que se intenta ocupar ya esta ocupada");
	this->listaPasajero[this->cantActual++] = elemento;
}

template <typename cPaciente>
void cLista<cPaciente>::agregar(cPaciente* elemento) {
	if (this->cantActual > this->cantTotal)
		throw exception("La cantidad actual de la lista es mayor a la cantidad total");
	else if (!isValidPaciente(elemento))
		throw exception("El paciente que se intenta agregar a la lista ya existe");
	else if (!elemento)
		throw exception("El paciente que se intenta agregar no existe");
	else if (lista[this->cantActual])
		throw exception("La posicion del paciente que se intenta ocupar ya esta ocupada");
	this->listaPasajero[this->cantActual++] = elemento;
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
	throw exception("El elemento que se intenta quitar no existe");
}

template <typename T>
void cLista<T>::ordenar() {
	for (ush i = 0; i < this->cantActual; i++)
		for (ush j = i; j < this->cantActual - 1; j++)
			if (!this->lista[i])
				swap(this->lista[j], this->lista[j + 1]);
}

template <typename T>
ostream& operator << (ostream& out, T* elemento) {
	out << elemento->to_string();
	return out;
}