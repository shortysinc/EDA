#include "Mont.h"

int main(){
	Mont<int> m;
	m.addElem(2);
	m.addElem(1);
	m.addElem(3);
	m.addElem(-5);
	cout<<m.getMin()<<endl;
	m.removeElem();
	cout<<m.getMin()<<endl;
	/*
	l.mostrarLista();
	cout<<endl<<l.numElem();
	cout<<endl<<l.elem(3)<<endl;
	int i=0;
	if (l.estaElem('a',i)) cout<<"true"<<endl;
	if (!l.estaElem('d',i)) cout<<"false"<<endl;
	cout<<l.posElem('a',i)<<endl;
	cout<<l.repeticiones('a')<<endl;
	cout<<l.repeticiones('d')<<endl;
	l.eliminarElem('a');
	l.mostrarLista();
	Listas<char> l1 = l;
	if (l.listasIguales(l1,l)) cout<<endl<<"true"<<endl;
	else cout<<"false";
	cout<<l.primero()<<endl;
	cout<<l.ultimo()<<endl;
	l.inicio();
	l.resto();
	l.mostrarLista();*/
	cin.get();
	return 0;
}