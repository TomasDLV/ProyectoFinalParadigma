/*
 * Negocio.h
 *
 *  Created on: 22 nov. 2023
 *      Author: Luciano
 */

#ifndef NEGOCIO_H_
#define NEGOCIO_H_
#include <iostream>
using namespace std;
#include <vector>
#include "Producto.h"
#include "Direccion.h"
#include "Pedido.h"
#include <vector>


class Negocio {
	static int autonumerico;
	int codigo;
	string nombre;
	vector<Producto*> productos;
	Direccion * direccion;
	vector<Pedido*> pedidos;

public:
	Negocio();
	Negocio(string nombre,string calle, int numero, int latitud, int longitud, string descripcion);
	void AgregarProducto(Producto* producto);
	void QuitarProducto(Producto* producto);
	Direccion * GetDireccion();
	void MostrarProductos();
	void AgregarPedido(Pedido * pedido);
	void QuitarPedido(Pedido *pedido);
	virtual ~Negocio();
};

#endif /* NEGOCIO_H_ */
