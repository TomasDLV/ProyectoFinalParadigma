/*
 * Coordenada.h
 *
 *  Created on: 17 nov. 2023
 *      Author: cuent
 */

#ifndef COORDENADA_H_
#define COORDENADA_H_
#include <iostream>
using namespace std;

class Coordenada {
	int latitud;
	int longitud;
public:
	Coordenada(int latitud, int longitud);
	virtual ~Coordenada();
	int GetLatitud();
	int GetLongitud();
	void listarInformacion();
};

#endif /* COORDENADA_H_ */
