/*
 * App.h
 *
 *  Created on: 30 nov. 2023
 *      Author: tomas
 */

#ifndef APP_H_
#define APP_H_
#include <iostream>
using namespace std;


#include <cstdlib>
#include <ctime>
#include "Usuario.h"
#include "Cadete.h"
#include "Cliente.h"
#include "Negocio.h"
#include "Usuario.h"
#include "Producto.h"
#include <vector>


class App {

	vector <Negocio *> negocios;
	vector <Cliente *> clientes;
	vector <Cadete *> cadetes;
	Cadete * ElegirCadeteRandom();
	template <typename X>
	    X * BuscarElementoEnLista(int id, std::vector<X*> lista) {
	        for (X* e : lista) {
	            if (id == e->GetId()) {
	                return e;
	            }
	        }
	        return nullptr; // O manejar el caso si el elemento no se encuentra
	    }
public:

	App();

	void CrearCadete(string correo, string nombre, string contrasenia);
	void CrearCliente(string correo, string nombre, string contrasenia,string calle, int numero, int latitud, int longitud, string descripcion);
	void CrearNegocio(string nombre,string calle, int numero, int latitud, int longitud, string descripcion);

	//Funciones que puede realizar un Cliente:
	void ClienteCancelarPedido(int idCliente,int idPedido);
	void ClienteCrearPedido(int idCliente,int idNegocio,vector<Producto*>productos,vector<int>cantidades,string comentario);
	void ClienteAgregarProducto(int idCliente,int idPedidoLocal,Producto * producto, int cantidad);
	//Funciones que puede realizar un Negocio:
	void NegocioAceptarPedido(int idPedido, int idNegocio);
	void NegocioRechazarPedido(int idPedido, int idNegocio);
	void NegocioAgregarProducto(Producto * producto, int idNegocio);
	void NegocioQuitarProducto(Producto * producto, int idNegocio);

	//Funciones que puede realizar un Cadete:
	void CadeteRetirarPedido(int idPedido,int idCadete);
	void CadeteEntregarPedido(int idPedido,int idCadete);

	virtual ~App();
};

#endif /* APP_H_ */
