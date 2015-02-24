#include "PilaLE.h"

int main(){
	PilaLE<char> p;
	char SecCaracteres[15]={'a','(','{','(','[',']',')','}','(','(','[',']',')',')',')'};
	if (p.equilibrado(SecCaracteres)) cout<<"true";
	else cout<<"false";
	cin.get();
	return 0;
}