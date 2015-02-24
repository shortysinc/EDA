#pragma once
#include <iostream>
using namespace std;
#include "TablaHash.h"
class ListinTelefonico {
	private:
		unsigned int DNI;
		struct Cliente {
		std::string nombre;
		unsigned int movil;
		std::string direccion;
		} c;//Cliente cliente;
		TablaHash<unsigned int,Cliente> t;
		static const unsigned int size=10;
	public:
		ListinTelefonico() : t(size){};
		void darAlta(unsigned int DNI,Cliente c){
			t.inserta(DNI,c);
		};
		void darBaja(unsigned int DNI){
			t.borra(DNI);
		};
		Cliente consulta(unsigned int DNI){
			return t.consulta(DNI); 
		};
		Cliente setCliente(std::string n,unsigned int m,std::string d){
			c.nombre=n;
			c.movil=m;
			c.direccion=d;
			return c;
		}
	};