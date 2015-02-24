#pragma once
#include <iostream>
using namespace std;
template <class T>
class Mont {
	struct Monticulo {
		T* cpd;
		int ult;
		Monticulo() : cpd(new T[N]),ult(-1) {}
	};
private:
	Monticulo* m;
	int numElems;
	int size;
public:
	enum {N=10};
	Mont() : m(new Monticulo()),numElems(0),size(N) {}
	~Mont() {delete []m->cpd;}
	void addElem(T elem);
	void ampliarVD();
	T getMin();
	bool esMontVacio();
	void removeElem();
	void flotar(T V[],int i);
	void hundir(T V[],int i,int j);
};

template <class T>
void Mont<T>::ampliarVD(){
	T* viejo = m->cpd;
	size=size*2; //size *= 2
	m->cpd=new T[size];
	for (int i = 0; i < numElems; ++i)
		m->cpd[i] = viejo[i];
	delete []viejo;
}
template <class T>
void Mont<T>::addElem(T elem){
	if (m->ult == size) ampliarVD();
	m->ult=m->ult+1;
	m->cpd[m->ult]=elem;
	numElems++;
	flotar(m->cpd,m->ult);
}
template <class T>
T Mont<T>::getMin(){
	if (!esMontVacio()) return m->cpd[0];
}
template <class T>
bool Mont<T>::esMontVacio(){
	return m->ult==-1;
}
template <class T>
void Mont<T>::removeElem(){
	if (!esMontVacio()){
		m->cpd[0]=m->cpd[m->ult];
		m->ult=m->ult-1;
		numElems--;
		hundir(m->cpd,0,m->ult);
	}
}
template <class T>
void Mont<T>::flotar(T V[],int i){
	int j=i;
	while ((j!=0)&&(m->cpd[j]<m->cpd[j/2])){
		T aux=m->cpd[j/2];
		m->cpd[j/2]=m->cpd[j];
		m->cpd[j]=aux;
		j=j/2;
	}
}
template <class T>
void Mont<T>::hundir(T V[],int i,int j){
	bool fin=false;
	int a=i;
	int b;
	while ((2*a<=j)&&(!fin)){
		if ((2*a+1<=j)&&(m->cpd[2*a+1]<m->cpd[2*a])) b=2*a+1;
		else b=2*a;
		if (m->cpd[b]<m->cpd[a]){
			T aux=m->cpd[b];
			m->cpd[b]=m->cpd[a];
			m->cpd[a]=aux;
			a=b;
		}
		else fin=true;
	}
}
