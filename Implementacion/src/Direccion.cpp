/*
 * Direccion.cpp
 *
 *  Created on: 17 nov. 2023
 *      Author: cuent
 */

#include "Direccion.h"

Direccion::Direccion(string calle, int numero, int latitud, int longitud, string descripcion) {
	Coordenada* newCordenada = new Coordenada(longitud, latitud);
	this->calle = calle;
	this->numero = numero;
	this->coordenada = newCordenada;
	this->descripcion = descripcion;
}

Direccion::~Direccion() {
	delete coordenada;
}

string Direccion::GetCalle(){
	return calle;
}

int Direccion::GetNumero(){
	return numero;
}
Coordenada* Direccion::GetCoordenada(){
	return coordenada;
}
string Direccion::GetDescripcion(){
	return descripcion;
}


void Direccion::ListarDireccion(){
	cout<<"*Direccion*"<<endl;
	cout<<"->Calle: "<< calle<<"\n";
	cout<<"->Numero: "<< numero<<"\n";
	this->coordenada->listarInformacion();
	cout<<"->Descripcion: "<< descripcion<<endl;
}
