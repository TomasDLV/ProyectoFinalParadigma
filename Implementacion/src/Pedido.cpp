/*
 * Pedido.cpp
 *
 *  Created on: 22 nov. 2023
 *      Author: tomas
 */
#include <iostream>
using namespace std;

#include "Pedido.h"
#include "Negocio.h"

int Pedido::autonumerico = 0;

Pedido::Pedido(int IdPedido,Cadete * cadeteEncargado,Negocio * negocioEncargado){
	autonumerico++;
	idPedido = IdPedido++;
	idPedidoUnico = autonumerico;
	cadete = cadeteEncargado;
	precio = 0;
	fecha = new Fecha();
	estado = "Pendiente de Aceptacion";
	negocio = negocioEncargado;
}

Pedido::~Pedido() {
	// TODO Auto-generated destructor stub
}
void Pedido::AgregarProducto(Producto * producto, int cantidad){
	DetalleProducto * detalleProducto = new DetalleProducto(producto,cantidad);
	detallesProductos.push_back(detalleProducto);

}
float Pedido::CalcularDistancia(Direccion *direc1, Direccion *direc2) {

	Coordenada* coordenada1 = direc1->GetCoordenada();
	Coordenada* coordenada2 = direc2->GetCoordenada();

	int latitud1 = coordenada1->GetLatitud();
	int longitud1 = coordenada1->GetLongitud();
	int latitud2 = coordenada2->GetLatitud();
	int longitud2 = coordenada2->GetLongitud();

	// Calcular la distancia usando la fórmula de distancia euclidiana entre dos puntos en un plano
	float distancia = sqrt(pow(latitud1 - latitud2, 2) + pow(longitud1 - longitud2, 2));
	return distancia;
}
float Pedido::CalcularMontoTotal(Direccion * direcCliente,Direccion * direcNegocio){
	precio = 0;
	for ( DetalleProducto * d : detallesProductos){
		precio += d->GetPrecio();
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
void Pedido::SetEstado(string estado){
	this->estado= estado;
}
string Pedido::GetEstado(){
	return estado;
}
int Pedido::GetIdPedidoUnico(){
	return idPedidoUnico;
}

