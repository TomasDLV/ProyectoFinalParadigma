/*
 * Cadete.cpp
 *
 *  Created on: 22 nov. 2023
 *      Author: josei
 */

#include "Cadete.h"

int Cadete::autonumerico = 0;
Cadete::Cadete(string Correo, string Nombre, string Contrasenia):Usuario(Correo,Nombre,Contrasenia,new Fecha()) {
	autonumerico++;
	idCadete = autonumerico;

}

void Cadete::CambiarEstado() {

}

void Cadete::ListarInfo() {
	cout<<"  *Cadete*"<<endl;
	Usuario::ListarInfo();
	cout<<""<<endl;
}


Cadete::~Cadete() {
	// TODO Auto-generated destructor stub
}
int Cadete::GetId(){
	return idCadete;
}
void Cadete::RetirarPedido(int IdPedidoUnico){
	for(Pedido* p : pedidosDesignados){
		if(p->GetIdPedidoUnico()== IdPedidoUnico){
			p->SetEstado("EnCamino");
			return;
		}
	}
}
void Cadete::EntregarPedido(int IdPedidoUnico){
	for(Pedido* p : pedidosDesignados){
			if(p->GetIdPedidoUnico()== IdPedidoUnico){
				p->SetEstado("Entregado");
				return;
			}
		}
}
void Cadete::AgregarPedidoDesignado(Pedido * pedido){
	pedidosDesignados.push_back(pedido);
}
