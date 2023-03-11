#include <stdio.h>
#include <limits.h>

const int inf = (INT_MAX/2)-1;
int tabla[1002][1002];
int N, A;

int main()
{
    int aux, x1, x2;
    scanf("%d %d", &N, &A);
    for(int i=0; i<1001; i++)
        for(int j=0; j<1001; j++)
            tabla[i][j] = inf;
    for(int i=0; i<A; i++)
    {
        scanf("%d %d", &x1, &x2);
        scanf("%d", &tabla[x1][x2]);
        tabla[x2][x1] = tabla[x1][x2];
    }
    for(int k=1; k<=N; k++)
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
            {
                aux = tabla[i][k] + tabla[k][j];
                if(aux < tabla[i][j])
                    tabla[i][j] = aux;
            }
    return 0;
}
