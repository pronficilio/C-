// problem: https://omegaup.com/arena/problem/OIEG2013SSA/

#include <iostream>

#define PASOS 1
#define VALOR 0

using namespace std;

int A, B, N;

int calc[2][100002];
int actual, fin = 0;
bool visitados[10001];

void meter(int x, int p){
    calc[VALOR][fin] = x;
    calc[PASOS][fin] = p;
    fin++;
}

void marcaVisitado(int x){
    visitados[x] = true;
}
bool estaVisitado(int x){
    return visitados[x] == true;
}


void amplitud(){
    meter(1, 0);
    marcaVisitado(1);
    while(actual < fin){
        int nodoActual = calc[VALOR][actual];
        int pasosActual = calc[PASOS][actual];
        actual++;
        /// generar movimientos validos
        int multiplicA = nodoActual * A;
        if(multiplicA > 9999){
            multiplicA = 1;
        }
        int divide = nodoActual / B;
        /// Pregunta... ya llegaste a la respuesta?
        if(multiplicA == N || divide == N){
            /// necesitamos saber con cuantos pasos llegue aqui
            cout << pasosActual + 1;
            break;
        }
        if(!estaVisitado(multiplicA)){
            meter(multiplicA, pasosActual + 1);
            marcaVisitado(multiplicA);
        }
        if(!estaVisitado(divide)){
            meter(divide, pasosActual + 1);
            marcaVisitado(divide);
        }
    }
}

int main()
{
    cin >> A >> B >> N;
    amplitud();
    return 0;
}