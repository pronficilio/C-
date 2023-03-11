// camino minimo de un lugar a todos los demas
#include <stdio.h>
#include <limits.h>

/*****
    numero de nodos, numero de aristas
    siguientes lineas sera quien con quien se une y su costo
    IN
    7 9
    1 4 5
    1 5 2
    2 3 1
    2 7 3
    3 4 8
    3 5 2
    4 7 1
    4 6 3
    5 6 4

    OUT

*****/

struct s1
{
    int costo;
    int adonde;
};

struct s2
{
    s1 nodo[1002];
    int tam;
};

s2 padre[1002];
int N, ind = 1;
int tabla[1002][3] = {0}; // 0 -> papa
                          // 1 -> costo
void lee()                // 2 -> visitado
{
    int a1, a2, costo, A;
    scanf("%d %d", &N, &A);
    for(int i=1; i<=A; i++)
    {
        scanf("%d %d %d", &a1, &a2, &costo);
        padre[a1].nodo[padre[a1].tam].costo = costo;
        padre[a1].nodo[padre[a1].tam++].adonde = a2;
        padre[a2].nodo[padre[a2].tam].costo = costo;
        padre[a2].nodo[padre[a2].tam++].adonde = a1;
    }
}

void hijos(int papa)
{
    int hijo, costo;
    tabla[papa][2] = 1;
    for(int i=0; i<padre[papa].tam; i++)
    {
        hijo = padre[papa].nodo[i].adonde;
        costo = padre[papa].nodo[i].costo + tabla[papa][1];
        if(!tabla[hijo][2] && tabla[hijo][1] > costo)
        {
            tabla[hijo][1] = costo;
            tabla[hijo][0] = papa;
        }
    }
}

void men()
{
    int menor = INT_MAX;
    for(int i=1; i<=N; i++)
        if(tabla[i][1]<menor && !tabla[i][2])
        {
            menor = tabla[i][1];
            ind = i;
        }
}

void imprime(int ke)
{
    if(ke-1)
        imprime(tabla[ke][0]);
    printf("%d ", ke);
}

int main()
{
    lee();
    //llena
    for(int i=1; i<=N; i++)
        tabla[i][1] = INT_MAX;
    tabla[1][0] = 1;
    tabla[1][1] = 0;
    tabla[1][2] = 1;
    for(int i=0; i<N; i++)
    {
        hijos(ind);
        men();
    }
    // imprime
    {
        int res = 0;
        for(int i=2; i<=N; i++)
        {

            imprime(tabla[i][0]);
            printf("%d ", i);
            printf("%d\n", tabla[i][1]);
        }
        printf("%d\n", res);
    }
    return 0;
}
