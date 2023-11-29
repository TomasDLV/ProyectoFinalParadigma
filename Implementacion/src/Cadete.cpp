/*
 * Cadete.cpp
 *
 *  Created on: 22 nov. 2023
 *      Author: josei
 */

#include "Cadete.h"

Cadete::Cadete(string correo, string nombre, string contrasenia, Fecha fechaRegistro):Usuario(correo,nombre,contrasenia,fechaRegistro) {
	// TODO Auto-generated constructor stub
}

void Cadete::CambiarEstado() {

}

void Cadete::ListarInfo() {
	cout<<"  *Cadete*"<<endl;
	Usuario::ListarInfo();
	cout<<""<<endl;
}


Cadete::~Cadete() {
	// TODO Auto-generated destructor stub
}

