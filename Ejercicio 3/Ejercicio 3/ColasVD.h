#pragma once
#include <iostream>
using namespace std;
template <class T>
class ColasVD {
private:
	T* VD;
	int size;
	int prim,ult;
public:
	enum {TAM_INICIAL=10};
	ColasVD() : VD(new T[TAM_INICIAL]),size(TAM_INICIAL),prim(0),ult(0) {}
	~ColasVD() {delete []VD;}
	void siguiente(int& i);
	void ampliarVD();
	void ponDetras(T elem);
	void quitaPrim();
	T primero();
	bool esColaVacia();
	void mostrarCola();
};

template <class T>
void ColasVD<T>::siguiente(int& i){
	i=(i+1)%size;
}
template <class T>
void ColasVD<T>::ampliarVD(){
	T* viejo = VD;
	size=size*2; //size *= 2
	VD=new T[size];
	int numElems=(size-prim+ult)%size;
	for (int i = 0; i < numElems; ++i)
		VD[i] = viejo[i];
	delete []viejo;
}
template <class T>
void ColasVD<T>::ponDetras(T elem){
	VD[ult]=elem;
	int aux=ult;
	siguiente(aux);
	if (aux==prim)
		ampliarVD();
	ult=(ult+1)%size;
}
template <class T>
void ColasVD<T>::quitaPrim(){
	if (!esColaVacia())
		siguiente(prim);
}
template <class T>
T ColasVD<T>::primero(){
	if (!esColaVacia()) return VD[prim];
}
template <class T>
bool ColasVD<T>::esColaVacia(){
	return (size-prim+ult)%10==0;
}
template <class T>
void ColasVD<T>::mostrarCola(){
	int aux=0;
	int numElems=(size-prim+ult)%size;
	while (aux<numElems){
		cout<<VD[prim+aux]<<" ";
		aux++;
	}
}

