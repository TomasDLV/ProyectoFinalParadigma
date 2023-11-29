/*
 * Usuario.h
 *
 *  Created on: 22 nov. 2023
 *      Author: josei
 */

#ifndef USUARIO_H_
#define USUARIO_H_

#include <iostream>
using namespace std;

#include "Fecha.h"
class Usuario {
private:
	string correo;
	string nombre;
	string contrasenia;
	Fecha fechaRegistro;
public:
	Usuario(string correo, string nombre, string contrasenia, Fecha fechaRegistro);
	void ListarInfo();
	~Usuario();
};

#endif /* USUARIO_H_ */
