/*
 * Cadete.h
 *
 *  Created on: 22 nov. 2023
 *      Author: josei
 */

#ifndef CADETE_H_
#define CADETE_H_
#include "Usuario.h"
#include "Fecha.h"
#include "Pedido.h"
#include <vector>

class Cadete : Usuario{
	int idCadete;
	static int autonumerico;
	vector<Pedido *> pedidosDesignados;
public:
	Cadete(string correo, string nombre, string contrasenia);
	void CambiarEstado();
	void ListarInfo();
	void AgregarPedidoDesignado(Pedido * pedido);
	void RetirarPedido(int IdPedidoUnico);
	void EntregarPedido(int IdPedidoUnico);
	int GetId();
	~Cadete();
};

#endif /* CADETE_H_ */
