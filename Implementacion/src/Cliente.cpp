/*
 * Cliente.cpp
 *
 *  Created on: 22 nov. 2023
 *      Author: josei
 */

#include "Cliente.h"
int Cliente::autonumerico = 0;

Cliente::Cliente(string correo, string nombre, string contrasenia, Fecha * fechaRegistro, string calle, int numero, int latitud, int longitud, string descripcion):Usuario(correo,nombre,contrasenia,fechaRegistro) {
	autonumerico++;
	this->idCliente = autonumerico;
	pedidosCreados = 0;
	Direccion* newDireccion = new Direccion(calle, numero, latitud, longitud, descripcion);
	this->direccion = newDireccion;
}

void Cliente::ListarInfo() {
	cout<<"  *Cliente*"<<endl;
	cout<<"->Codigo:"<<idCliente<<endl; //AUTO NUMERICO
	Usuario::ListarInfo();
	direccion->ListarDireccion();
	cout<<""<<endl;
}
void Cliente::CrearPedido(Negocio * negocio,Cadete * cadeteEncargado,string comentario){
	Pedido * pedido = new Pedido(pedidosCreados++,cadeteEncargado,negocio);
	pedidos.push_back(pedido);
}
void Cliente::AgregarProductos(int idPedidoUnico, vector<Producto*> productos,vector<int> cantidades,Direccion * direcNegocio,Direccion * direcCliente){
	int cantProductos = productos.size();
	Pedido * pedidoEncontrado;
	for(Pedido * p : pedidos){
		if(p->GetIdPedidoUnico()== idPedidoUnico){
			 pedidoEncontrado = p;
		}
	}
	for (int i = 0; i < cantProductos; ++i) {
	        pedidoEncontrado->AgregarProducto(productos[i],cantidades[i]);
	}
	pedidoEncontrado->CalcularMontoTotal(direcCliente,direcNegocio);
}
void Cliente::EnviarPedidoANegocio(Pedido * pedido,Negocio * negocio){
	negocio->AgregarPedido(pedido);
}
Cliente::~Cliente() {
	// TODO Auto-generated destructor stub
}

