/// Algoritmo de Ballman Ford que encuentra camino minimo en un grafo con costos negativos
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/***********

    dado una cantidad N de nodos (1 <= N <= 1000) y una cantidad A de aristas (1 <= A <= 10000)
    calcula el camino minimo entre el nodo 1 y el nodo N. De no tener camino minimo (o sea con
    un ciclo en el grafo) imprimir -1

    ENTRADA:
    linea 1:
        N y A
    linea 2..A+1:
        a b Cab         donde 'a' es el origen y 'b' el destino con un costo de 'Cab'
    SALIDA:
    linea 1:
        un numero K que es el costo minimo de viajar del nodo 1 al N
    linea 2:
        reconstruccion del camino tomado desde 1 hasta N

EJEMPLO 1 DE ENTRADA:

9 9
1 2 1
4 7 1
1 3 2
2 7 1
4 8 1
8 6 1
6 9 1
5 9 -2
3 5 5

EJEMPLO 1 DE SALIDA:

5
1 - 3 - 5 - 9

EJEMPLO 2 DE ENTRADA:

19 31
1 4 2
1 5 3
1 2 -2
1 8 11
2 5 10
2 6 30
2 3 -8
3 6 25
3 8 21
3 7 22
4 5 -5
5 6 3
6 8 10
7 8 3
8 9 -5
9 10 1
9 13 50
9 11 3
10 11 3
10 14 2
10 12 10
11 13 10
12 13 5
12 14 -10
13 15 -15
14 11 -1
15 16 10
15 17 10
16 18 -10
17 18 -11
18 19 11

EJEMPLO 2 DE SALIDA:

10
1 - 4 - 5 - 6 - 8 - 9 - 10 - 12 - 14 - 11 - 13 - 15 - 17 - 18 - 19

EJEMPLO 3 DE ENTRADA:

6 7
1 2 1
2 3 -1
2 4 5
3 4 -2
4 5 -3
5 2 -2
4 6 -5

EJEMPLO 3 DE SALIDA:

-1

***********/

struct ura
{
    int a;
    int b;
    int Cab;
};

struct table
{
    int kien; // esta variable es utilizada unicamente para el debug
    int padre;
    int costo;
};

ura arista[10002];
table tabla[1002];
const int infinito = INT_MAX/2; // para no desbordar variable
int N, A;

int funtion(const void *X, const void *Y)
{
    return ( ((ura *) X) -> Cab - ((ura *) Y) -> Cab );
}

bool HombreCampana()
{
    int OrigenActual, DestinoActual, CostoDeCamino, Costo_de_viaje_anterior, Costo_de_viaje_nuevo;
    for(int j=1; j<N; j++)
    {
        for(int i=0; i<A; i++)
        {
            OrigenActual = arista[i].a;
            DestinoActual = arista[i].b;
            CostoDeCamino = arista[i].Cab;
            Costo_de_viaje_anterior = tabla[DestinoActual].costo;
            Costo_de_viaje_nuevo = tabla[OrigenActual].costo + CostoDeCamino;
            if(Costo_de_viaje_nuevo < Costo_de_viaje_anterior)
            {
                tabla[DestinoActual].costo = Costo_de_viaje_nuevo;
                tabla[DestinoActual].padre = OrigenActual;
            }
        }
    }
    /// de acuerdo con este algoritmo, en la ultima pasada (o sea esta) si se cambia algun valor
    /// entonces el camino se cicla
    for(int i=0; i<A; i++)
    {
        OrigenActual = arista[i].a;
        DestinoActual = arista[i].b;
        CostoDeCamino = arista[i].Cab;
        Costo_de_viaje_anterior = tabla[DestinoActual].costo;
        Costo_de_viaje_nuevo = tabla[OrigenActual].costo + CostoDeCamino;
        if(Costo_de_viaje_nuevo < Costo_de_viaje_anterior)
        {
            printf("-1\n");
            return true;
        }
    }
    return false;
}

void imprimir(int donde)
{
    if(tabla[donde].padre != 0)
        imprimir(tabla[donde].padre);
    printf("%d - ", donde);
}

int main()
{
    scanf("%d %d", &N, &A);
    for(int i=0; i<A; i++)
        scanf("%d %d %d", &arista[i].a, &arista[i].b, &arista[i].Cab);
    for(int i=1; i<=N; i++)
    {
        tabla[i].costo = infinito;
        tabla[i].kien = i;
    }
    tabla[1].costo = 0;
    qsort(arista, A, sizeof(arista[0]), funtion);
    if(HombreCampana()) /// regresa verdadero si se cicla
        return 0;
    printf("%d\n", tabla[N].costo);
    imprimir(tabla[N].padre);
    printf("%d\n", N);
    return 0;
}
