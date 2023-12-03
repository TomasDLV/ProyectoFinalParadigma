/*
 * Cliente.h
 *
 *  Created on: 22 nov. 2023
 *      Author: josei
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "Usuario.h"
#include "Cadete.h"
#include "Producto.h"
#include "Pedido.h"
#include "Negocio.h"
#include "Direccion.h"
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
	Cliente(string correo, string nombre, string contrasenia,string calle, int numero, int latitud, int longitud, string descripcion);
	~Cliente();

	void ListarInfo();
	void CrearPedido(Negocio * negocio,Cadete * cadeteEncargado,string comentario);
	void AgregarProductos(int idPedidoUnico, vector<Producto*> productos,vector<int> cantidades,Direccion * direcNegocio,Direccion * direcCliente);
	void EnviarPedidoANegocio(Pedido * pedido , Negocio * negocio);
	void CancelarPedido(int idPedidoLocal);
	Direccion * GetDireccion();
	void EliminarPedido(int id);
	int GetId();
	int GetPedidosCreados(){return pedidosCreados;};
	Pedido * GetPedidoPorId(int idPedidoLocal);

};

#endif /* CLIENTE_H_ */
