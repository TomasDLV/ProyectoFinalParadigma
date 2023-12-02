/*
 * Producto.cpp
 *
 *  Created on: 22 nov. 2023
 *      Author: Luciano
 */

#include "Producto.h"

int Producto::autonumerico = 0;

Producto::Producto(string nombre,string descripcion,float precio) {
	autonumerico++;
	this->idProducto = autonumerico;
	this->descripcion = descripcion;
	this->precio = precio;
}

void Producto::MostrarProducto(){
	std::cout << "Código: " << idProducto << std::endl;
	std::cout << "Nombre: " << nombre << std::endl;
	std::cout << "Descripción: " << descripcion << std::endl;
	std::cout << "Precio: $" << precio << std::endl;
}

Producto::~Producto() {
	// TODO Auto-generated destructor stub
}

