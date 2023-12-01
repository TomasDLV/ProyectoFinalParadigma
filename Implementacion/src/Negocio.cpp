/*
 * Negocio.cpp
 *
 *  Created on: 22 nov. 2023
 *      Author: Luciano
 */

#include "Negocio.h"

int Negocio::autonumerico = 0;
Negocio::Negocio(){
	direccion = nullptr;
	codigo = -1;
}

Negocio::Negocio(string nombre,string calle, int numero, int latitud, int longitud, string descripcion) {
	autonumerico++;
	Direccion *direccion = new Direccion(calle,numero,latitud,longitud,descripcion);
	this->nombre = nombre;
	this->codigo = autonumerico;
	this->direccion = direccion;
}

void Negocio::AgregarProducto(Producto* producto) {
    productos.push_back(producto);
    cout << "Producto agregado con éxito." << endl;
}

void Negocio::QuitarProducto(Producto* producto){
	if (productos.empty()) {
		cout << "No hay productos para quitar." << endl;
		return;
	}
	 // Buscar el producto en el vector
	for (auto it = productos.begin(); it != productos.end(); ++it) {
		if ((*it)->GetCodigo() == producto->GetCodigo()) {
			// Eliminar el producto encontrado del vector (sin liberar memoria)
			it = productos.erase(it);
			cout << "Producto quitado con éxito." << endl;
			return; // Salir del bucle una vez que se ha eliminado el producto
		}
	}

	// Si llegamos aquí, el producto no se encontró en el vector
	cout << "Producto no encontrado en el negocio." << endl;
}

void Negocio::MostrarProductos() {
    if (productos.empty()) {
        cout << "No hay productos para mostrar." << endl;
        return;
    }

    cout << "Productos disponibles en el negocio:" << endl;
    for (Producto* p : productos) {
        p->MostrarProducto();
        cout << "-----------------------------" << endl;
    }
}
Direccion * Negocio::GetDireccion(){
	return direccion;
}


void Negocio::AgregarPedido(Pedido * pedido){
	pedidos.push_back(pedido);
	cout << "Pedido agregado con Exito." << endl;
}
void Negocio::QuitarPedido(Pedido *pedido){
	if (pedidos.empty()) {
			cout << "No hay pedidos para quitar." << endl;
			return;
	}
	 // Buscar el pedido en el vector
	for (auto it = pedidos.begin(); it != pedidos.end(); ++it) {
		if ((*it)->GetIdPedidoUnico() == pedido->GetIdPedidoUnico()) {
			// Eliminar el pedido encontrado del vector (sin liberar memoria)
			it = pedidos.erase(it);
			cout << "Pedido quitado con Exito." << endl;
			return; // Salir del bucle una vez que se ha eliminado el pedido
		}
	}

	// Si llegamos aqua, el pedido no se encuentra en el vector
	cout << "Pedido no encontrado en el negocio." << endl;
}

Negocio::~Negocio() {
	delete direccion;
}
