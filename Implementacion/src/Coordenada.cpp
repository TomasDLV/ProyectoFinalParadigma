/*
 * Coordenada.cpp
 *
 *  Created on: 17 nov. 2023
 *      Author: cuent
 */

#include "Coordenada.h"


Coordenada::Coordenada(int latitud, int longitud) {
	this->latitud = latitud;
	this->longitud = longitud;

}

Coordenada::~Coordenada() {
	// TODO Auto-generated destructor stub
}

int Coordenada::getLatitud(){
	return latitud;
}
int Coordenada::getLongitud(){
	return longitud;
}

void Coordenada::listarInformacion(){
	cout<<"->Latitud: "<<latitud<<endl;
	cout<<"->Longitud: "<<longitud<<endl;
}
