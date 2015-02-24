#include "Listas.h"

int main(){
	Listas<char> l;
	l.ponDr('b');
	l.Cons('a');
	l.Cons('c');
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
	l.mostrarLista();
	cin.get();
	return 0;
}