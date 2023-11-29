/*
 * Pedido.h
 *
 *  Created on: 22 nov. 2023
 *      Author: tomas
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#include "Fecha.h"


#include "Direccion.h"
#include "Usuario.h"
#include "Cadete.h"
#include "Cliente.h"
#include "Negocio.h"
#include "Producto.h"
#include "DetalleProducto.h"






#ifndef PEDIDO_H_
#define PEDIDO_H_

class Pedido {
	static int autonumerico;
	int idPedido;
	int idPedidoUnico;
	float precio;
	string comentario;
	Fecha fecha;
	string estado;
	Negocio negocio;
	vector<DetalleProducto *> detallesProductos;
	float CalcularDistancia(Direccion * direc1,Direccion * direct2);

public:
	Pedido();
	Pedido(int IdPedido);
	virtual ~Pedido();
	float CalcularMontoTotal(Direccion * direcCliente,Direccion * direcNegocio);
	void AgregarProducto(Producto * producto, int cantidad);
	int GetIdPedidoUnico();
};

#endif /* PEDIDO_H_ */
