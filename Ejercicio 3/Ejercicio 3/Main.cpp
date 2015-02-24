#include "ColasVD.h"

int main(){
	ColasVD<char> c;
	c.ponDetras('a');
	c.ponDetras('b');
	c.ponDetras('c');
	c.quitaPrim();
	c.ponDetras('b');
	c.quitaPrim();
	c.mostrarCola();
	cout<<c.primero()<<" ";
	cin.get();
	return 0;
}