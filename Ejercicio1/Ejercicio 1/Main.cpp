#include "PilaLE.h"

int main()
{
	PilaLE<char> p;
	p.apilar('b');
	p.desapilar();
	p.apilar('c');
	p.apilar('a');
	p.apilar('a');
	p.apilar('a');
	p.apilar('b');
	p.apilar('c');
	p.desapilar();
	cout<<"Pila: ";
	p.mostrarLista();
	cout<<endl;
	cout<<"Cima de la Pila: "<<p.cima()<<" "<<endl;
	cin.get();
	return 0;
}