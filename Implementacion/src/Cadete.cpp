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
        if(p->GetId() == IdPedidoUnico){
            p->SetEstado("EnCamino");
            cout << "Pedido con ID único: " << IdPedidoUnico << " retirado por el cadete '" << nombre << "'." << endl;
            return;
        }
    }
    cout << "Pedido con ID único: " << IdPedidoUnico << " no asignado al cadete '" << nombre << "'." << endl;
}
void Cadete::EntregarPedido(int IdPedidoUnico){
    for(Pedido* p : pedidosDesignados){
        if(p->GetId() == IdPedidoUnico){
            p->SetEstado("Entregado");
            cout << "Pedido con ID único: " << IdPedidoUnico << " entregado por el cadete '" << nombre << "'." << endl;
            return;
        }
    }
    cout << "Pedido con ID único: " << IdPedidoUnico << " no asignado al cadete '" << nombre << "'." << endl;
}
void Cadete::AgregarPedidoDesignado(Pedido * pedido){
    pedidosDesignados.push_back(pedido);
    cout << "Pedido con ID: " << pedido->GetId() << " asignado al cadete '" << nombre << "' con éxito." << endl;
}
