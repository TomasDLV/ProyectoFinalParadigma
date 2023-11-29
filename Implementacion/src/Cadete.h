/*
 * Cadete.h
 *
 *  Created on: 22 nov. 2023
 *      Author: josei
 */

#ifndef CADETE_H_
#define CADETE_H_
#include "Usuario.h"

class Cadete : Usuario{
public:
	Cadete(string correo, string nombre, string contrasenia, Fecha fechaRegistro);
	void CambiarEstado();
	void ListarInfo();
	~Cadete();
};

#endif /* CADETE_H_ */
