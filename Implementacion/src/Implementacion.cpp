//============================================================================
// Name        : Implementacion.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "App.h"
#include "Producto.h"
#include "Fecha.h"


int main() {
	App app;
    // Crear clientes
    app.CrearCliente("cliente2@gmail.com", "Cliente2", "456", "Calle 123", 456, 100, 50, "Cerca de un parque");
    app.CrearCliente("cliente3@gmail.com", "Cliente3", "789", "Avenida Central", 789, 150, 30, "Zona residencial");
	app.CrearCliente("tomas@gmail.com", "Tomas", "123","siempreViva",123,200,20,"Frente a una plaza");

    // Crear negocios
    app.CrearNegocio("Parrilla Martín", "San Martín", 555, 200, 70, "Centro");
    app.CrearNegocio("Tienda de ropa Ana", "Rivadavia", 888, 300, 40, "Local comercial");
	app.CrearNegocio("Pizzeria Mauro","Laprida",321,123,20,"Lavalle");
	//Crear cadetes
	app.CrearCadete("Cadete1@gmail.com","Emilia","123123");
	app.CrearCadete("Cadete2@gmail.com","Carlos","123123");
	app.CrearCadete("Cadete3@gmail.com","Bruno","123123");
	app.CrearCadete("Cadete4@gmail.com","Juan","123123");

// Crear 10 productos
	Producto* producto1 = new Producto("Producto 1", "Descripción del Producto 1", 10.5);
	Producto* producto2 = new Producto("Producto 2", "Descripción del Producto 2", 15.75);
	Producto* producto3 = new Producto("Producto 3", "Descripción del Producto 3", 20.0);
	Producto* producto4 = new Producto("Producto 4", "Descripción del Producto 4", 8.0);
	Producto* producto5 = new Producto("Producto 5", "Descripción del Producto 5", 12.99);
	Producto* producto6 = new Producto("Producto 6", "Descripción del Producto 6", 18.25);
	Producto* producto7 = new Producto("Producto 7", "Descripción del Producto 7", 22.5);
	Producto* producto8 = new Producto("Producto 8", "Descripción del Producto 8", 14.0);
	Producto* producto9 = new Producto("Producto 9", "Descripción del Producto 9", 9.5);
	Producto* producto10 = new Producto("Producto 10", "Descripción del Producto 10", 25.0);

	app.NegocioAgregarProducto(producto1,1);
	app.NegocioAgregarProducto(producto2,1);
	app.NegocioAgregarProducto(producto3,1);
	app.NegocioAgregarProducto(producto4,1);
	app.NegocioAgregarProducto(producto5,1);
	app.NegocioAgregarProducto(producto6,1);

	app.NegocioAgregarProducto(producto7,2);
	app.NegocioAgregarProducto(producto8,2);
	app.NegocioAgregarProducto(producto9,2);
	app.NegocioAgregarProducto(producto10,2);
	app.NegocioAgregarProducto(producto5,2);
	app.NegocioAgregarProducto(producto6,2);

//PRIMERA COMPRA Al NEGOCIO 2::
//Creo un vector de pedidos y otro de cantidades que seran recibidos por la interfaz
	vector<Producto*> listaProduc1;
	listaProduc1.push_back(producto7);
	listaProduc1.push_back(producto8);
	listaProduc1.push_back(producto6);
	vector<int> listaCant1;
	listaCant1.push_back(2);
	listaCant1.push_back(5);
	listaCant1.push_back(3);

//Cliente Crea el pedido  PEDIDOUNICO N°1
	app.ClienteCrearPedido(1,2,listaProduc1,listaCant1,"Sin Comentario");

//Negocio ACEPTAPEDIDO:
	app.NegocioAceptarPedido(1,2);

//Cadete retiraPedido Le pongo a todos por que nose a que cadete le tocó
	app.CadeteRetirarPedido(1,1);
	app.CadeteRetirarPedido(1,2);
	app.CadeteRetirarPedido(1,3);



    delete producto1;
    delete producto2;
    delete producto3;
    delete producto4;
    delete producto5;
    delete producto6;
    delete producto7;
    delete producto8;
    delete producto9;
    delete producto10;
    return 0;
}
