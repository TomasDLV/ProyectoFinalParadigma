/*
 * Cliente.cpp
 *
 *  Created on: 22 nov. 2023
 *      Author: josei
 */

#include "Cliente.h"
int Cliente::autonumerico = 0;

Cliente::Cliente(string correo, string nombre, string contrasenia, string calle, int numero, int latitud, int longitud, string descripcion):Usuario(correo,nombre,contrasenia,new Fecha()) {
	autonumerico++;
	this->idCliente = autonumerico;
	pedidosCreados = 0;
	Direccion* newDireccion = new Direccion(calle, numero, latitud, longitud, descripcion);
	this->direccion = newDireccion;

}

void Cliente::ListarInfo() {
	cout<<"  *Cliente*"<<endl;
	cout<<"->IdCliente:"<<idCliente<<endl; //AUTO NUMERICO
	Usuario::ListarInfo();
	direccion->ListarDireccion();
	cout<<""<<endl;
}
void Cliente::CrearPedido(Negocio * negocio,Cadete * cadeteEncargado,string comentario){
	pedidosCreados +=1;
	Pedido * pedido = new Pedido(pedidosCreados,cadeteEncargado,negocio);
	pedidos.push_back(pedido);
	 cout << "Pedido creado por el cliente " << GetNombre() << " con ID único: " << pedido->GetId() << endl;
}
void Cliente::AgregarProductos(int idPedidoUnico, vector<Producto*> productos,vector<int> cantidades,Direccion * direcNegocio,Direccion * direcCliente){
	int cantProductos = productos.size();
	Pedido * pedidoEncontrado;
	for(Pedido * p : pedidos){
		if(p->GetId()== idPedidoUnico){
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
int Cliente::GetId(){
	return idCliente;
}
void Cliente::CancelarPedido(int idPedidoLocal){
	for(Pedido* p : pedidos){
		if (p->GetIdPedidoLocal() == idPedidoLocal){
	    	if (p->GetEstado() == "EnPreparacion"){
	        	EliminarPedido(idPedidoLocal);
	         	cout << "Pedido con ID local: " << idPedidoLocal << " cancelado con éxito." << endl;
	        	return;
	        } else {
	         	cout << "No se puede cancelar el pedido con ID local: " << idPedidoLocal << ". No está en estado 'EnPreparacion'." << endl;
	            return;
	            }
	    }
	}
	cout << "Pedido con ID local: " << idPedidoLocal << " no encontrado para cancelar." << endl;
}
void Cliente::EliminarPedido(int id){
	auto iter = pedidos.begin();
	    while (iter != pedidos.end()) {
	        if ((*iter)->GetIdPedidoLocal() == id) {
	            delete *iter; // Liberar memoria del pedido
	            iter = pedidos.erase(iter); // Eliminar el puntero al pedido de la lista
	            return;
	        } else {
	            ++iter;
	        }
	    }
	    cout << "Pedido no encontrado o no se puede cancelar." << endl;
}
Direccion * Cliente::GetDireccion(){
	return direccion;
}
Pedido * Cliente::GetPedidoPorId(int idPedido){
	for(Pedido * p : pedidos){
		if(idPedido == p->GetIdPedidoLocal()){
			return p;
		}
	}
	return nullptr;
}
Cliente::~Cliente() {
    for (Pedido* pedido : pedidos) {
        delete pedido;
    }
    pedidos.clear();
    delete direccion;
}


