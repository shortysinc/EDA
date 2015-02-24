#include "BestWay.h"
#include <cstdlib>
using namespace std;

//k empieza en 1
void ShortestWay(bool camino[N][N], Casilla solucion[],
				 int k, int n, 
				 bool marcas[N][N], Casilla solucionMejor[],
				 int coste,int &costeMejor,
				 Casilla llegada){
	for(int dir = 0; dir < 4; dir++){
		solucion[k] = sigDireccion(dir, solucion[k-1]);
		coste++;
		if (esValida(camino, solucion[k], n, marcas)){
			if(esSolucion(solucion[k],n,llegada)){
				if (coste  < costeMejor){
					costeMejor=coste;
					copiarSolucion(solucion,solucionMejor);
				}
			}
			else{
				marcas[solucion[k].fila][solucion[k].columna]=true;
				ShortestWay(camino, solucion, k + 1, 
				n, marcas, solucionMejor, coste, costeMejor, llegada);
				marcas[solucion[k].fila][solucion[k].columna]=false;
			}
		}
		coste--;
	}
}
bool esSolucion(Casilla pos,int n, Casilla pos2) {
	return (pos.fila==pos2.fila)&&(pos.columna==pos2.columna);
	//pos2 = posicion final
}
void copiarSolucion(Casilla solucion[],Casilla solucionMejor[]){
	for (int i=0; i<N*N; i++){
		solucionMejor[i].fila=solucion[i].fila;
		solucionMejor[i].columna=solucion[i].columna;
	}
}
bool esValida(bool camino[N][N], Casilla pos, int n, bool marcas[N][N]) {
	return pos.fila >= 0 && pos.columna >= 0 && pos.fila < n &&
	pos.columna < n && !camino[pos.fila][pos.columna] 
	&& !marcas[pos.fila][pos.columna];
}
Casilla sigDireccion(int dir, Casilla pos){
	switch (dir) {
		case 0: ++ pos.columna;
		break;
		case 1: ++ pos.fila;
		break;
		case 2: -- pos.columna;
		break;
		case 3: -- pos.fila;
		break;
		default:
		break;
	}
	return pos;
}
void InicializarCamino(bool camino[N][N],int N){
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++){
			int b=rand() % 2;
			if (b==1) camino[i][j]=true;
			else camino[i][j]=false;
		}
	/*for (int i=0;i<N;i++)
		for (int j=0;j<N;j++){
			camino[i][j]=false;
		}
	camino[0][2]=true;
	camino[1][4]=true;*/
}
