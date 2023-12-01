/*
 * Cadete.cpp
 *
 *  Created on: 22 nov. 2023
 *      Author: josei
 */

#include "Cadete.h"

Cadete::Cadete(string Correo, string Nombre, string Contrasenia, Fecha * FechaRegistro):Usuario(Correo,Nombre,Contrasenia,FechaRegistro) {
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

