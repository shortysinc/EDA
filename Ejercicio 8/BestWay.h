
struct Casilla {
		int fila;
		int columna;
	};
const int N = 10;

void ShortestWay(bool camino[N][N], Casilla solucion[],
				 int k,  int n, 
				 bool marcas[N][N], Casilla solucionMejor[], 
				 int coste,int &costeMejor, 
				 Casilla llegada);
bool esSolucion(Casilla pos,int n, Casilla pos2);//pos2 = final
bool esValida(bool camino[N][N], Casilla pos, int n, bool marcas[N][N]);
Casilla sigDireccion(int dir, Casilla pos);
void copiarSolucion(Casilla solucion[],Casilla solucionMejor[]);
void InicializarCamino(bool camino[N][N],int N);
