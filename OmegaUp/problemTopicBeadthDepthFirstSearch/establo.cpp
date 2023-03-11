// problem: https://omegaup.com/arena/problem/De-regreso-al-establo/

#include <iostream>

using namespace std;

int R, C, K;

char tablero[10][10];
char visitado[10][10];
int contador;

/*
  la idea es hacer una busqueda exaustiva cuando vamos bajando 
  marcamos los visitados para no volver a tomar un camnino que ya tomamos
  pero cuando regresamos debemos ir marcando como no visitados cada que hagamos
  la vuelta atras (backtraking) o mejor dicho  cuando se regrese en la pila 
  de la recursividad
*/
void cuenta(int r, int c, int pasos){
	if (r<1 || r>R || c<1 || c> C){
        return;        // si no esta en los limites del mapa se regresa
    }
    if(tablero[r][c]== 'T'){
        return;      // si es una pared
    }
	if (visitado[r][c]){
        return;        // si ya lo visito se regresa
    }

	
	if (pasos>K){
        return;       // si ha dado mas pasos termina y busca otro camino
    }
    if (r==R  && c==1 ){
        contador++;     // si llega a esquina inferior izquierda lo cuenta y se regresa
        return;
    }


    visitado[r][c]=1;           // marca como visitado el nodo
    cuenta(r-1, c, pasos+1);    //BUSCA ARRIBA
    cuenta(r+1, c, pasos+1);    //BUSCA ABAJO
	cuenta(r, c-1, pasos+1);    //BUSCA DERECHA
    cuenta(r, c+1, pasos+1);    //BUSCA IZQUIERDA
    // si no encuentra camino regresa y desmarca el camino para poder buscar otra opcion
    visitado[r][c]=0;
}

void leer(){
    int i, j;
    cin >> R >> C >> K;
    for(i=1; i<= R; i++){
        for(j=1;j<=C;j++){
            cin >> tablero[i][j];
        }
    }
}
int main()
{

    leer();
    cuenta(1, C, 1);    // inicia primer renglon ultima columna (esquina superior derecha)
    cout << contador << endl;
    return 0;
}