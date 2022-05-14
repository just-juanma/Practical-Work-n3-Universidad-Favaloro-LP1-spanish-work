#include "cReceptor.h"

// cReceptor implementacion

cReceptor::cReceptor(string _nombre, string _sexo, string _telefono, string _patologia, 
					 cFecha* _nacimiento, cFecha* _fechaListaEnEspera, eTipoSangre _tipo, bool _EoI) :
					 cPaciente(_nombre, _sexo, _telefono, _nacimiento, _tipo, true) {
	this->patologia = _patologia;
	this->organoNecesario = NULL;
	this->fechaListaEnEspera = _fechaListaEnEspera;
	this->prioridad = sinPrioridad;
	this->EoI = _EoI;
}

cReceptor::~cReceptor() { }

string cReceptor::to_string() {
	stringstream stc;
	stc << "Perfil del Receptor:" << endl;
	stc << "Nombre: " << this->nombre << endl;
	stc << "Sexo: " << this->sexo << endl;
	stc << "Telefono: " << this->telefono << endl;
	stc << "Fecha de nacimiento: " << this->nacimiento->getFecha() << endl;
	if(fechaListaEnEspera)
		stc << "Fecha de inscripcion en lista de espera: " << this->fechaListaEnEspera->getFecha() << endl;
	stc << "Patologia: " << this->patologia << endl;
	if (organoNecesario)
		stc << "Organo necesario: " << this->organoNecesario->to_string() << endl;
	stc << "Prioridad: " << this->prioridad << endl;
	stc << "Estable o inestable: " << this->EoI << endl;
	return stc.str();
}