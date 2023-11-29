/*
 * Cliente.h
 *
 *  Created on: 22 nov. 2023
 *      Author: josei
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "Usuario.h"
#include "Negocio.h"
#include "Direccion.h"
#include "Pedido.h"
#include "Producto.h"
#include "DetalleProducto.h"
#include <vector>

class Cliente : Usuario {
protected:
	Direccion * direccion;
private:
	int idCliente;
	int pedidosCreados;
	static int autonumerico;
	vector <Pedido *> pedidos;
public:
	Cliente(string correo, string nombre, string contrasenia, Fecha fechaRegistro,string calle, int numero, int latitud, int longitud, string descripcion);
	void ListarInfo();
	~Cliente();
	void CrearPedido(Negocio * negocio,string comentario);
	void AgregarProductos(int idPedidoUnico, vector<Producto*> productos,vector<int> cantidades,Direccion * direcNegocio,Direccion * direcCliente);
	void EnviarPedido
	void CancelarPedido();

};

#endif /* CLIENTE_H_ */
