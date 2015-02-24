#include "BestWay.h"
#include <iostream>
using namespace std;

int main(){
	//const int N = 5;
	int Coste=0;
	int CosteMejor=100;
	bool Camino[N][N];
	InicializarCamino(Camino,N);
	bool Marcas[N][N];
	for(int i = 0; i < N; i ++)
		for(int j = 0; j < N; j ++)
			Marcas[i][j] = false;
	Casilla Solucion[N*N];
	Casilla SolucionMejor[N*N];
	Solucion[0].fila = 0;
	Solucion[0].columna = 5;
	Casilla Llegada;
	Llegada.fila=2;
	Llegada.columna=8;
	ShortestWay(Camino,Solucion,1,N,Marcas,SolucionMejor,Coste,
	CosteMejor,Llegada);
	cout<<CosteMejor<<endl;
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++)
			if (Camino[i][j]==true) cout << '1';
			else cout << '0' ;
		cout << endl;
	}	
	for (int i=0; i<CosteMejor+1; i++){
		cout<<'(' ;
		cout<< SolucionMejor[i].fila ;
		cout<< ',' ;
		cout<< SolucionMejor[i].columna ;
		cout<< ')'; 
	}
	cin.get();
	return 0;
}
