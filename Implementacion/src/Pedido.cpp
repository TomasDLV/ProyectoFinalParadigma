/*
 * Pedido.cpp
 *
 *  Created on: 22 nov. 2023
 *      Author: tomas
 */
#include <iostream>
using namespace std;

#include "Pedido.h"
int Pedido::autonumerico = 0;
Pedido::Pedido() {
	autonumerico++;
	idPedido = 0;
	idPedidoUnico = autonumerico;
	precio = 0;
	fecha = new Fecha();
	estado = "Pendiente de Aceptacion";

}
Pedido::Pedido(int IdPedido){
	autonumerico++;
	idPedido = IdPedido++;
	idPedidoUnico = autonumerico;
	precio = 0;
	fecha = new Fecha();
	estado = "Pendiente de Aceptacion";

}

Pedido::~Pedido() {
	// TODO Auto-generated destructor stub
}
void Pedido::AgregarProducto(Producto * producto, int cantidad){
	DetalleProducto * detalleProducto = new DetalleProducto(producto,cantidad);
	detallesProductos.push_back(detalleProducto);

}
float Pedido::CalcularDistancia(Direccion *direc1, Direccion *direc2) {
    // Acceder a las coordenadas de los objetos de tipo Direccion y calcular la distancia
    float distancia = sqrt(
        pow((direc1->getCoordenada()->latitud - direc2->getCoordenada()->latitud), 2) +
        pow((direc1->getCoordenada()->longitud - direc2->getCoordenada()->longitud), 2)
    );
    return distancia;
}
float Pedido::CalcularMontoTotal(Direccion * direcCliente,Direccion * direcNegocio){
	precio = 0;
	for ( DetalleProducto * d : detallesProductos){
		precio += d->precio;
	}
	float distancia;
	distancia = CalcularDistancia(direcCliente,direcNegocio);
	if(distancia < 1000){
		precio += 500;
	}else{
		distancia = (distancia/1000)*500;
		precio += distancia;
	}
	precio *= 1.05;
	return precio;
}
int Pedido::GetIdPedidoUnico(){
	return idPedidoUnico;
}

