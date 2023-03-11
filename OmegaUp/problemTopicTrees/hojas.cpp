// problem: https://omegaup.com/arena/problem/Orden-de-las-hojas/

#include <stdio.h>

struct arbol
{
    int kien;
    int izq;
    int der;
};

arbol bin[1002];
int N, num[1002] = {0}, ini=1;

void meter(int x, int padre)
{
    if(x>bin[padre].kien)
    {
        if(bin[padre].der)
            meter(x, bin[padre].der);
        else
        {
            bin[padre].der = ini;
            bin[ini++].kien = x;
            return;
        }
    }
    else
    {
        if(bin[padre].izq)
            meter(x, bin[padre].izq);
        else
        {
            bin[padre].izq = ini;
            bin[ini++].kien = x;
        }
    }
}

void imprime(int x)
{
    printf("%d ", bin[x].kien);
    if(bin[x].izq)
        imprime(bin[x].izq);
    if(bin[x].der)
        imprime(bin[x].der);
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &num[i]);
    bin[0].kien = num[--N];
    for(int i=N-1; i>=0; i--)
        meter(num[i], 0);
    imprime(0);
    return 0;
}
