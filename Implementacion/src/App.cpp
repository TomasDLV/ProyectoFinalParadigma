/*
 * App.cpp
 *
 *  Created on: 30 nov. 2023
 *      Author: tomas
 */

#include "App.h"


App::App() {
	// TODO Auto-generated constructor stub

}

App::~App() {
    // Liberar memoria de objetos almacenados en el vector de Negocios
    for (Negocio* negocio : negocios) {
        delete negocio;
    }
    // Limpiar el vector de Negocios después de liberar la memoria de los objetos
    negocios.clear();

    // Liberar memoria de objetos almacenados en el vector de Clientes
    for (Cliente* cliente : clientes) {
        delete cliente;
    }
    clientes.clear();

    // Liberar memoria de objetos almacenados en el vector de Cadetes
    for (Cadete* cadete : cadetes) {
        delete cadete;
    }
    cadetes.clear();
}


void App::ClienteCrearPedido(int idCliente,int idNegocio,vector<Producto*>productos,vector<int>cantidades,string comentario){
		Cliente * clienteEncontrado = BuscarElementoEnLista(idCliente, clientes);
		Negocio * negocioEncontrado = BuscarElementoEnLista(idNegocio, negocios);
		Cadete * cadeteDesignado = ElegirCadeteRandom();
		clienteEncontrado->CrearPedido(negocioEncontrado,cadeteDesignado,comentario);
		Pedido * pedidoCreado = clienteEncontrado->GetPedidoPorId(clienteEncontrado->GetPedidosCreados());
		clienteEncontrado->AgregarProductos(pedidoCreado->GetId(),productos,cantidades,negocioEncontrado->GetDireccion(),clienteEncontrado->GetDireccion());
		cadeteDesignado->AgregarPedidoDesignado(pedidoCreado);
		negocioEncontrado->AgregarPedido(pedidoCreado);
}
void App::ClienteCancelarPedido(int idCliente,int idPedido){
	for (Cliente* c : clientes) {
		if (c->GetId() == idCliente){
			c->EliminarPedido(idPedido);
		}
	}
}
void App::CrearNegocio(string nombre,string calle, int numero, int latitud, int longitud, string descripcion){
	Negocio *nuevo = new Negocio(nombre,calle,numero,latitud,longitud,descripcion);
	negocios.push_back(nuevo);
	cout << "Negocio creado exitosamente." << endl;
	cout << "Nombre: " << nombre << ", ID: " << nuevo->GetId() << endl;

}
Cadete * App::ElegirCadeteRandom(){
	srand(static_cast<unsigned int>(time(nullptr)));
	int random = rand() % cadetes.size();
	return BuscarElementoEnLista(random,cadetes);
}
//Funciones que puede realizar un Cliente:

void App::CrearCadete(string correo, string nombre, string contrasenia){
	Cadete *nuevo = new Cadete(correo,nombre,contrasenia);
	cadetes.push_back(nuevo);
    cout << "Cadete creado exitosamente." << endl;
    cout << "Nombre: " << nombre << ", Correo: " << correo << ", ID: " << nuevo->GetId() << endl;

}

void App::CrearCliente(string correo, string nombre, string contrasenia,string calle, int numero, int latitud, int longitud, string descripcion){
	Cliente *nuevo = new Cliente(correo,nombre,contrasenia,calle,numero,latitud,longitud,descripcion);
	clientes.push_back(nuevo);
	cout << "Cliente creado exitosamente." << endl;
	cout << "Nombre: " << nombre << ", Correo: " << correo << ", ID: " << nuevo->GetId() << endl;
}

//Funciones que puede realizar un Negocio:

void App::NegocioAceptarPedido(int idPedido, int idNegocio){
	Negocio * negocioEncontrado = BuscarElementoEnLista(idNegocio, negocios);
	negocioEncontrado->AceptarPedido(idPedido);
}
void App::NegocioRechazarPedido(int idPedido, int idNegocio){
	Negocio * negocioEncontrado = BuscarElementoEnLista(idNegocio, negocios);
	negocioEncontrado->RechazarPedido(idPedido);
}
void App::NegocioAgregarProducto(Producto * producto, int idNegocio){
	Negocio * negocioEncontrado = BuscarElementoEnLista(idNegocio, negocios);
	negocioEncontrado->AgregarProducto(producto);

}
void App::NegocioQuitarProducto(Producto * producto, int idNegocio){
	Negocio * negocioEncontrado = BuscarElementoEnLista(idNegocio, negocios);
	negocioEncontrado->QuitarProducto(producto);
}

//Funciones que puede realizar un Cadete:

void App::CadeteEntregarPedido(int idPedido,int idCadete){
	Cadete * cadeteEncontrado = BuscarElementoEnLista(idCadete, cadetes);
	cadeteEncontrado->EntregarPedido(idPedido);
}
void App::CadeteRetirarPedido(int idPedido,int idCadete){
	Cadete * cadeteEncontrado = BuscarElementoEnLista(idCadete, cadetes);
	cadeteEncontrado->RetirarPedido(idPedido);
}
void App::ClienteAgregarProducto(int idCliente,int idPedidoLocal,Producto * producto, int cantidad){
	Cliente * clienteEncontrado = BuscarElementoEnLista(idCliente,clientes);
	Pedido * pedidoEncontrado = clienteEncontrado->GetPedidoPorId(idPedidoLocal);
	if(pedidoEncontrado->GetEstado()== "EnPreparacion" || pedidoEncontrado->GetEstado()== "PendienteDeAceptacion" ){
		pedidoEncontrado->AgregarProducto(producto,cantidad);
		return;
	}
}
