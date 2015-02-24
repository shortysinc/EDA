#include "TablaHash.h"
#include "ListinTelefonico.h"
#include <string>
using namespace std;
int main(){

	ListinTelefonico l;
	l.darAlta(50123513,l.setCliente("Federico",686764978,"Calle Valmojado"));
	l.darAlta(50123514,l.setCliente("Yesua",686764978,"Calle Valmojado"));
	cout<<l.consulta(50123513).movil<<endl;
	cout<<l.consulta(50123513).direccion<<endl;
	cout<<l.consulta(50123513).nombre<<endl;
	cout<<l.consulta(50123514).movil<<endl;
	cout<<l.consulta(50123514).direccion<<endl;
	cout<<l.consulta(50123514).nombre<<endl;
	l.darAlta(50123513,l.setCliente("Yes",213,"Aqui al lado"));
	cout<<l.consulta(50123513).movil<<endl;
	cout<<l.consulta(50123513).direccion<<endl;
	cout<<l.consulta(50123513).nombre<<endl;
	cout<<l.consulta(50123514).movil<<endl;
	cout<<l.consulta(50123514).direccion<<endl;
	cout<<l.consulta(50123514).nombre<<endl;
	cin.get();
	return 0;
}