/*
 * Usuario.cpp
 *
 *  Created on: 22 nov. 2023
 *      Author: josei
 */

#include "Usuario.h"

Usuario::Usuario(string correo, string nombre, string contrasenia,Fecha * fechaRegistro) {
	this->correo = correo;
	this->nombre = nombre;
	this->contrasenia =  contrasenia;
	this->fechaRegistro = fechaRegistro;
}

void Usuario::ListarInfo() {
	cout<<"->Nombre: "<<nombre<<endl;
	cout<<"->Contrasña: "<<contrasenia<<endl;
	cout<<"->Correo: "<<correo<<endl;
	cout<<"->Fecha de registro: "<<fechaRegistro->getDia()<<"/"<<fechaRegistro->getMes()<<"/"<<fechaRegistro->getAnio()<<endl;
}

Usuario::~Usuario() {
	delete fechaRegistro;
}

