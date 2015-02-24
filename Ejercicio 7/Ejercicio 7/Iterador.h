#pragma once
#include <iostream>
//#include "TablaHash.h"
using namespace std;
class Iterador {
public:
	void avanza() {
		if (act != NULL){
			act = act->sig;
			while ((act == NULL) && (ind < tabla->size - 1)) {
				++ind;
				act = tabla->listin[ind];
			}
		}
	}
//const C& clave() const {
//	if (act != NULL)	return act->clave;
//}
//const V& valor() const {
//	if (act != NULL)	return act->valor;
//}
//bool operator==(const Iterador &other) const {
//return act == other.act;
//}
//bool operator!=(const Iterador &other) const {
//return !(this->operator==(other));
//}
private:
friend class TablaHash;
Iterador(const TablaHash* tabla, Nodo* act, unsigned int ind) : tabla(tabla), act(act), ind(ind) { }
Nodo* act; 
unsigned int ind; 
const TablaHash* tabla; 
};