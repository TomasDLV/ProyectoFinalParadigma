/*
 * Producto.h
 *
 *  Created on: 22 nov. 2023
 *      Author: Luciano
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_
#include <iostream>
using namespace std;

class Producto {
	static int autonumerico;
	int codigo;
	string nombre;
	string descripcion;
	float precio;

public:
	Producto(string nombre,string descripcion,float precio);
	float GetPrecio(){return precio;};
	int GetCodigo(){return codigo;};
	void MostrarProducto();
	virtual ~Producto();
};

#endif /* PRODUCTO_H_ */
