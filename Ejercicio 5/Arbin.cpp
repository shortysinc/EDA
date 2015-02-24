#include "stdafx.h"
#include "Arbin.h"
using namespace std;

Arbin<int> creaNodos(){
   //Nodo Vacio
	Arbin<int> nodovacio= *new Arbin<int>();

	Arbin<int> nodoDrI= *new Arbin<int>(nodovacio,4,nodovacio);
	Arbin<int> nodoDrI2= *new Arbin<int>(nodovacio,6,nodovacio);
	
	//Nodo izquierdo
	Arbin<int> nodoIz= *new Arbin<int>(nodovacio,2,nodoDrI);
    Arbin<int> nodoIz2= *new Arbin<int>(nodovacio,5,nodoDrI2);

    //Nodo derecho
	Arbin<int> nodoDr= *new Arbin<int>(nodoIz2,3,nodovacio);

	Arbin<int> raiz = *new Arbin<int>( nodoIz,1,nodoDr );

	//para probar si es Hoja o no
	//Arbin<int> raiz = *new Arbin<int>( nodovacio,1,nodovacio);

	/*          1
	        /        \
	      I2          D3
         /   \        / \
	<vacio>   D4     I5    <vacio>
	              /    \
	          <vacio>   D6
	
	*/

	return raiz;
}

template <class T>
void mostrarVacio(const Arbin<T> &nodo){
	if(nodo.esVacio())
		cout<<"<vacio>"<<endl;
	 
	else{
		cout<<nodo.raiz()<<endl;
		if(!(nodo.hijoIz().esVacio() && nodo.hijoDr().esVacio())){ //condicion binaria
			printf("I");
			mostrarVacio(nodo.hijoIz());
			printf("D");
			mostrarVacio(nodo.hijoDr());
		}
	}
}

template <class T>
void muestraArbol(const Arbin<T> &nodo){
	if(nodo.hijoIz().esVacio() && nodo.hijoDr().esVacio()){
		cout<<nodo.raiz()<<endl; 
	}else{
		mostrarVacio(nodo);
	}
}

 

int main()
{
	Arbin<int> arbol = creaNodos();
	muestraArbol(arbol);
	cout<<".................."<<endl;
	arbol.frontera();
	
	//muestraArbol(arbol.espejo());
   
	//Hojas->vertices con 0 hijos, en mi ejemplo D4 y D6
	//cout<<arbol.numHojas()<<endl;

	//maximo de niveles de todos los nodos, en mi ejemplo hasta D6-> 4 niveles
	//cout<<arbol.talla()<<endl;
	
	//numero de nodos
	//cout<<arbol.numNodos()<<endl;
   
	//esHoja? 0-> NO ,1->SI
	//cout<<arbol.esHoja()<<endl;
     
 

	cin.get();
	return 0;
}

