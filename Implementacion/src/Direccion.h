/*
 * Direccion.h
 *
 *  Created on: 17 nov. 2023
 *      Author: cuent
 */

#ifndef DIRECCION_H_
#define DIRECCION_H_

#include "Coordenada.h"


class Direccion {
	string calle;
	int numero;
	Coordenada *coordenada;
	string descripcion;

public:
	Direccion(string calle, int numero, int latitud, int longitud, string descripcion);
	virtual ~Direccion();
	string getCalle();
	int getNumero();
	Coordenada* getCoordenada();
	string getDescripcion();
	void ListarDireccion();
};


#endif /* DIRECCION_H_ */
