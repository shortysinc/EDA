#pragma once
#include <iostream>
using namespace std;
template <class C,class V>
class TablaHash {
	struct Nodo {
		C clave;
		V valor;
		Nodo* sig;//liasta de pacientes
		Nodo(const C cl, const V va) : clave(cl), valor(va), sig(NULL) {};
		Nodo(const C cl, const V va, Nodo* s) : clave(cl), valor(va), sig(s) {};
	};
private:
	Nodo **listin;
	unsigned int size;
	unsigned int numElems;
public:
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
	const C& clave() const {
		if (act != NULL)	return act->clave;
	}
	const V& valor() const {
		if (act != NULL)	return act->valor;
	}
	bool operator==(const Iterador &other) const {
		return act == other.act;
	}
	bool operator!=(const Iterador &other) const {
		return !(this->operator==(other));
	}
	private:
		friend class TablaHash;
		Iterador(const TablaHash* tabla, Nodo* act, unsigned int ind) : tabla(tabla), act(act), ind(ind) { }
		Nodo* act; 
		unsigned int ind; 
		const TablaHash* tabla; 
	};
	TablaHash(unsigned int tam) : listin(new Nodo*[tam]),size(tam),numElems(0) {
		for (unsigned int i=0; i<size; ++i) 
			listin[i] = NULL;
	}
	~TablaHash(){
		libera();
	}
	void libera();
	void liberaNodos(Nodo* n);
	void buscaNodo(C clave, Nodo* &act, Nodo* &ant);
	Nodo* buscaNodo(C clave, Nodo* &prim){
		Nodo *act = prim;
		Nodo *ant = NULL;
		buscaNodo(clave, act, ant);
		return act;
	}
	void inserta(C cl, V va);
	void borra(C cl);
	bool esta(C cl);
	V consulta(C cl);
	bool esVacia();
	void ampliaTH();
	Iterador principio(){
		unsigned int ind = 0;
		Nodo* act = listin[ind];
		while ((act == NULL) && (ind < size - 1)) {
			++ind;
			act = listin[ind];
		}
		return Iterador(this, act, ind);
	}
	Iterador final(){
			return Iterador(this, NULL, size);
	}
	unsigned int hash(C cl);
}; 
template <class C,class V>
void TablaHash<C,V>::libera(){
	for (unsigned int i=0; i<size; i++) 
		liberaNodos(listin[i]);
	if (listin != NULL) {
		delete[] listin;
		listin = NULL;
	}
}
template <class C,class V>
void TablaHash<C,V>::liberaNodos(Nodo* n){
	while (n!=NULL){
		Nodo* aux=n;
		n=n->sig;
		delete aux;
	}
}
template <class C,class V>
void TablaHash<C,V>::buscaNodo(C cl, Nodo* &act, Nodo* &ant){
	ant = NULL;
	bool encontrado = false;
	while ((act != NULL) && !encontrado) {
		if (act->clave == cl)
			encontrado = true;
		else {
			ant = act;
			act = act->sig;
		}
	}
}
template <class C,class V>
void TablaHash<C,V>::inserta(C cl, V va) {
	if (numElems == size-2)
		ampliaTH();
	unsigned int ind = hash(cl) % size;
	Nodo *nodo = buscaNodo(cl,listin[ind]);
	if (nodo != NULL) 
		nodo->valor = va;
	else {
		listin[ind] = new Nodo(cl, va, listin[ind]);
		numElems++;
	}
}
template <class C,class V>
void TablaHash<C,V>::borra(C cl) {
	unsigned int ind = hash(cl) % size;
	Nodo *act = listin[ind];
	Nodo *ant = NULL;
	buscaNodo(cl, act, ant);
	if (act != NULL) {
		if (ant != NULL)
			ant->sig = act->sig;
		else 
			listin[ind] = act->sig;
		delete act;
		numElems--;
	}
}
template <class C,class V>
bool TablaHash<C,V>::esta(C cl) {
	unsigned int ind = hash(cl) % size;
	Nodo *nodo = buscaNodo(cl, listin[ind]);
	return nodo != NULL;
}
template <class C,class V>
V TablaHash<C,V>::consulta(C cl) {
	unsigned int ind = hash(cl) % size;
	Nodo *nodo = buscaNodo(cl, listin[ind]);
	if (nodo != NULL)
		return nodo->valor;
//	else return NULL;
}
template <class C,class V>
bool TablaHash<C,V>::esVacia() {
	return numElems == 0;
}
template <class C,class V>
void TablaHash<C,V>::ampliaTH(){
	Nodo **antiguoListin = listin;
	unsigned int tamAnt = size;
	size *= 2;
	listin = new Nodo*[size];
	for (unsigned int i=0; i<size; ++i)
		listin[i] = NULL;
	for (unsigned int i=0; i<tamAnt; ++i) {
		Nodo *nodo = antiguoListin[i];
		while (nodo != NULL) {
			Nodo *aux = nodo;
			nodo = nodo->sig;
			unsigned int ind = hash(aux->clave) % size;
			aux->sig = listin[ind];
			listin[ind] = aux;
		}
	}
	delete[] antiguoListin;
}
template <class C,class V>
unsigned int TablaHash<C,V>::hash(C cl){
	return hash1(cl);
}
unsigned int hash1(unsigned int cl){
	return cl;
}
unsigned int hash1(std::string cl){
	return cl.length();
}

