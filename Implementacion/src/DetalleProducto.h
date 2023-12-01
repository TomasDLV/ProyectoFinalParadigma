/*
 * DetalleProducto.h
 *
 *  Created on: 22 nov. 2023
 *      Author: tomas
 */

#ifndef DETALLEPRODUCTO_H_
#define DETALLEPRODUCTO_H_
#include <iostream>
using namespace std;
#include "Producto.h"

class DetalleProducto {
	int cantidad;
	float precio;
	Producto * producto;
public:
	DetalleProducto();
	DetalleProducto(Producto * producto,int cantidad);
	float GetPrecio();
	virtual ~DetalleProducto();
};

#endif /* DETALLEPRODUCTO_H_ */
