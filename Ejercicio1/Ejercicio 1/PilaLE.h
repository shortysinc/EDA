#pragma once
#include <iostream>
using namespace std;
template <class T>
class PilaLE {
	struct Nodo {
		T _elem;
		Nodo* _ant;
		Nodo* _sig;
		Nodo(const T& elem, Nodo* ant, Nodo* sig) : _elem(elem), _ant(ant), _sig(sig) {}
	};
	private:
		Nodo* prim;
		Nodo* ult;
		void libera();
	
	public:
		PilaLE();
		~PilaLE();
		void borraUlt();
		void borraPrim();
		void insertaUlt(T elem);
		void insertaPrim(T elem);
		void apilar(T elem);
		void desapilar();
		T cima();
		bool esPilaVacia();
		void mostrarLista();
};

template <class T>
PilaLE<T>::PilaLE(){
		prim=NULL;
		ult=NULL;
}
template <class T>
PilaLE<T>::~PilaLE(){
	libera();
}
template <class T>
void PilaLE<T>::borraUlt(){
	if (ult!=prim){
		ult=ult->_ant;
		delete (ult->_sig);
		ult->_sig=NULL;
	}
	else {
		delete ult;
		ult=prim=NULL;
	}
}
template <class T>
void PilaLE<T>::borraPrim(){
	if(prim!=ult){
		prim=prim->_sig;
		delete(prim->_ant);
		prim->_ant=NULL;
	}
	else {
		delete prim;
		prim=ult=NULL;
	}
}
template <class T>
void PilaLE<T>::insertaUlt(T elem){
	Nodo* aux=new Nodo(elem,NULL,NULL);
	if (esPilaVacia()){
		ult=aux;
		prim=aux;
	}
	else {
		ult->_sig=aux;
		aux->_ant=ult;
		ult=aux;
	}
}
template <class T>
void PilaLE<T>::insertaPrim(T elem){
	Nodo* aux=new Nodo(elem,NULL,NULL);
	if (esPilaVacia){
		prim=ult=aux;
	}
	else {
		prim->_ant=aux;
		aux->_sig=prim;
		prim=aux;
	}
}
template <class T>
void PilaLE<T>::libera(){
	while (prim != NULL) {
		Nodo *aux = prim;
		prim = prim->_sig;
		delete aux;
	}
}
template <class T>
void PilaLE<T>::mostrarLista(){
	Nodo* aux=prim;
	while (aux!=NULL) {
		cout<<aux->_elem<<" ";
		aux=aux->_sig;
	}
}
template <class T>
void PilaLE<T>::apilar(T elem){
	insertaUlt(elem);
}
template <class T>
void PilaLE<T>::desapilar(){
	borraUlt();
}
template <class T>
T PilaLE<T>::cima(){
	if (!esPilaVacia()) return ult->_elem;
}
template <class T>
bool PilaLE<T>::esPilaVacia(){
	return prim==NULL;
}