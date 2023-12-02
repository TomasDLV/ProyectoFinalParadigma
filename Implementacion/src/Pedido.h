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
#include "Usuario.h"
#include "Cliente.h"
#include "Producto.h"
#include "Direccion.h"
#include "Negocio.h"
#include "DetalleProducto.h"

#ifndef PEDIDO_H_
#define PEDIDO_H_
class Negocio;
class Cadete;

class Pedido {
	static int autonumerico;
	int idPedido;
	int idPedidoUnico;
	float precio;
	string comentario;
	Fecha * fecha;
	string estado;
	Negocio * negocio;
	Cadete * cadete;
	vector<DetalleProducto *> detallesProductos;
	float CalcularDistancia(Direccion * direc1,Direccion * direct2);

public:
	Pedido(int IdPedido,Cadete * cadeteEncargado,Negocio * negocioEncargado);
	virtual ~Pedido();
	float CalcularMontoTotal(Direccion * direcCliente,Direccion * direcNegocio);
	void AgregarProducto(Producto * producto, int cantidad);
	void SetEstado(string estado);
	string GetEstado();
	int GetIdPedidoUnico();
	int GetId();
	int GetIdPedido();
};

#endif /* PEDIDO_H_ */
