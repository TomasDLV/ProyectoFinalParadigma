/*
 * DetalleProducto.cpp
 *
 *  Created on: 22 nov. 2023
 *      Author: tomas
 */

#include "DetalleProducto.h"

DetalleProducto::DetalleProducto() {
	precio = 0;
	cantidad = 0;
	producto = nullptr;
}
DetalleProducto::DetalleProducto(Producto * producto,int cantidad){
	this->producto = producto;
	this->cantidad = cantidad;
	this->precio = producto->GetPrecio() * cantidad;
}
DetalleProducto::~DetalleProducto() {
	// TODO Auto-generated destructor stub
}
float DetalleProducto::GetPrecio(){
	return precio;
}
