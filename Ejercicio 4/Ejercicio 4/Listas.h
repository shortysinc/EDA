#pragma once
#include <iostream>
using namespace std;
template <class T>
class Listas {
	struct Nodo {
		T _elem;
		Nodo* _ant;
		Nodo* _sig;
		Nodo(const T& elem, Nodo* ant, Nodo* sig) : _elem(elem), _ant(ant), _sig(sig) {}
	};
private:
	Nodo* prim;
	Nodo* ult;
	int numElems;
	void libera();	
public:
	Listas() : prim(NULL), ult(NULL), numElems(0) {}
	~Listas() {
		libera();
		prim = NULL;
		ult = NULL;
	}
	void insertaPrim(T elem);
	void insertaUlt(T elem);
	void borraPrim();
	void borraUlt();
	void Cons(const T elem);//Inserta un elemento al principi y suma 1 al nº de elementos
	void ponDr(const T elem);//inserta al final de la lista y auma 1 al nº d elementos
	T primero();
	T ultimo();
	void resto(); //Borra el primero y resta 1 al nº de elementos
	void inicio();//Borra el ultinmo y resta 1 al nº de elementos
	bool esListaVacia();
	int numElem();
	T elem(int idx);
	void mostrarLista();
	//Ejercicio 4
	bool estaElem(T elem,int& i);
	int posElem(T elem,int& i);
	int repeticiones(T elem);
	void eliminarElem(T elem);
	bool listasIguales(Listas<T>& l1,Listas<T>& l2);
};

//Añade en la cabcera de la Lista
template <class T>
void Listas<T>::insertaPrim(T elem){
	Nodo* aux=new Nodo(elem,NULL,NULL);
	if (esListaVacia()){
		prim=ult=aux;
	}
	else {
		prim->_ant=aux;
		aux->_sig=prim;
		prim=aux;
	}
}
template <class T>
void Listas<T>::Cons(const T elem){
	insertaPrim(elem);
	numElems++;
}
//Añade en la parte final de la lista
template <class T>
void Listas<T>::insertaUlt(T elem){
	Nodo* aux=new Nodo(elem,NULL,NULL);
	if (esListaVacia()){
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
void Listas<T>::ponDr(const T elem){
	insertaUlt(elem);
	numElems++;
}
//Devuelve el primero de la lista
template <class T>
T Listas<T>::primero(){
	if (!esListaVacia()) return prim->_elem;
}
//Devuelve el ultimo de la lista
template <class T>
T Listas<T>::ultimo(){
	if (!esListaVacia()) return ult->_elem;
}
//Quitar el primero de la lista
template <class T>
void Listas<T>::borraPrim(){
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
void Listas<T>::resto(){
	borraPrim();
	numElems--;
}
//Quita el ultimo elemento de la lista
template <class T>
void Listas<T>::borraUlt(){
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
void Listas<T>::inicio(){
	borraUlt();
	numElems--;
}
template <class T>
bool Listas<T>::esListaVacia(){
	return numElems==0 ;
}
template <class T>
int Listas<T>::numElem(){
	return numElems;
}
//Devuelve el elemento i-esimo de la lista
template <class T>
T Listas<T>::elem(int idx){
	if (idx <= numElems){
		Nodo* aux = prim;
		for (int i = 1; i < idx; ++i)
			aux = aux->_sig;
		return aux->_elem;
	}
}
template <class T>
void Listas<T>::mostrarLista(){
	Nodo* aux=prim;
	while (aux!=NULL) {
		cout<<aux->_elem<<" ";
		aux=aux->_sig;
	}
}
template <class T>
void Listas<T>::libera(){
	numElems=0;
	while (prim != NULL) {
		Nodo *aux = prim;
		prim = prim->_sig;
		delete aux;
	}
}
//Ejercicio 4
template <class T>
bool Listas<T>::estaElem(T elem,int& i){
	Nodo* aux=prim;
	i=1;
	while (aux!=NULL) 
		if (aux->_elem==elem) return true;
		else {
			aux=aux->_sig;
			i++;
		}
	return false;
}
template <class T>
int Listas<T>::posElem(T elem,int& i){
	if (estaElem(elem,i)) return i;
	else return 0;
}
template <class T>
int Listas<T>::repeticiones(T elem){
	Nodo* aux=prim;
	int j=0;
	while (aux!=NULL) {
		if (aux->_elem==elem) j++;
		aux=aux->_sig;
	}
	return j;
}
template <class T>
void Listas<T>::eliminarElem(T elem){
	Nodo* aux=prim;
	while (aux!=NULL) {
		if (aux->_elem==elem){
			if (aux->_ant!=NULL && aux->_sig!=NULL){
				aux->_ant->_sig=aux->_sig;
				aux->_sig->_ant=aux->_ant;
				Nodo* aux1=aux;
				aux=aux->_sig;
				delete aux1;
			}
			else if (aux->_ant==NULL){
				resto();
			}
			else if (aux->_sig==NULL){
				inicio();
			}
			numElems--;
		}
		else aux=aux->_sig;
	}
}
template <class T>
bool Listas<T>::listasIguales(Listas<T>& l1,Listas<T>& l2){
	int i=1;
	while (l1.elem(i) == l2.elem(i))
		i++;
	if ((i-1)==numElems) return true;
	return false;
}
