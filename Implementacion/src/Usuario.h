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
protected:
	string correo;
	string nombre;
	string contrasenia;
private:

	Fecha * fechaRegistro;
public:
	Usuario(string Correo, string Nombre, string Contrasenia,Fecha * fechaRegistro);
	void ListarInfo();
	string GetNombre(){return nombre;};
	~Usuario();
};

#endif /* USUARIO_H_ */
