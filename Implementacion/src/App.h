/*
 * App.h
 *
 *  Created on: 30 nov. 2023
 *      Author: tomas
 */

#ifndef APP_H_
#define APP_H_
#include <iostream>
using namespace std;

#include <vector>
#include <random>
#include "Usuario.h"
#include "Cadete.h"
#include "Cliente.h"
#include "Negocio.h"
#include "Usuario.h"
#include "Producto.h"


class App {
	vector <Negocio *> negocios;
	vector <Cliente *> clientes;
	vector <Cadete *> cadetes;
	Cadete * ElegirCadeteRandom();
public:

	App();
	//void CrearCadete();
	//void CrearCliente();
	//void CrearNegocio();
	void CrearPedido(int idCliente,int idNegocio,vector<Producto*>productos,vector<int>cantidades,string comentario);
	//void CancelarPedido(int idCliente,int idPedido);
	//void CambiarEstado(int idNegocio,int idPedidoUnico)

	virtual ~App();
};

#endif /* APP_H_ */
