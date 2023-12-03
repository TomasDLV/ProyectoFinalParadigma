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
	idNegocio = -1;
}

Negocio::Negocio(string nombre,string calle, int numero, int latitud, int longitud, string descripcion) {
	autonumerico++;
	Direccion *direccion = new Direccion(calle,numero,latitud,longitud,descripcion);
	this->nombre = nombre;
	this->idNegocio = autonumerico;
	this->direccion = direccion;
}
Negocio::~Negocio() {
	delete direccion;
}

void Negocio::AgregarProducto(Producto* producto) {
    productos.push_back(producto);
    cout << "Producto agregado con éxito." << endl;
    cout << "Producto '" << producto->GetNombre() << "' agregado al negocio '" << nombre << "' con éxito." << endl;
}

void Negocio::QuitarProducto(Producto* producto){
    if (productos.empty()) {
        cout << "No hay productos para quitar en el negocio '" << nombre << "'." << endl;
        return;
    }
	 // Buscar el producto en el vector
	for (auto it = productos.begin(); it != productos.end(); ++it) {
		if ((*it)->GetIdProducto() == producto->GetIdProducto()) {
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
		if ((*it)->GetId() == pedido->GetId()) {
			// Eliminar el pedido encontrado del vector (sin liberar memoria)
			it = pedidos.erase(it);
			cout << "Pedido quitado con Exito." << endl;
			return; // Salir del bucle una vez que se ha eliminado el pedido
		}
	}

	// Si llegamos aqua, el pedido no se encuentra en el vector
	cout << "Pedido no encontrado en el negocio." << endl;
}
int Negocio::GetId(){
	return idNegocio;
}

void Negocio::AceptarPedido(int idPedido){
    for(Pedido * p : pedidos){
        if(p->GetId() == idPedido){
            p->SetEstado("EnPreparacion");
            cout << "Pedido con ID: " << idPedido << " en el negocio '" << nombre << "' aceptado y en preparación." << endl;
            return;
        }
    }
    cout << "Pedido con ID: " << idPedido << " no encontrado en el negocio '" << nombre << "'." << endl;
}
void Negocio::RechazarPedido(int idPedidoUnico){
    for(Pedido * p : pedidos){
        if(p->GetId() == idPedidoUnico){
            p->SetEstado("Rechazado");
            QuitarPedido(p);
            cout << "Pedido con ID único: " << idPedidoUnico << " en el negocio '" << nombre << "' rechazado y quitado del listado." << endl;
            return;
        }
    }
    cout << "Pedido con ID único: " << idPedidoUnico << " no encontrado en el negocio '" << nombre << "'." << endl;
}
