/**SUMA**/
#include <stdio.h>

int N;
int tree[100002], valores[100002];

int inline BitMenor(int x)
{
    return (x) & (-x);
}

int acumulado(int idx)
{
    int suma = 0;
    while(idx)
    {
        suma += tree[idx];
        idx -= BitMenor(idx);
    }
    return suma;
}

void actualiza(int idx, int dif)
{
    while(idx <= N)
    {
        tree[idx] -= dif;
        idx += BitMenor(idx);
    }
}

int main()
{
    char temp;
    int a, b;
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &valores[i]);
        actualiza(i, -valores[i]);
    }
    while(1)
    {
        scanf(" %c", &temp);
        switch(temp)
        {
            case 'A':
            {
                scanf("%d %d", &a, &b);
                actualiza(a, valores[a]-b);
                break;
            }
            case 'C':
            {
                scanf("%d %d", &a, &b);
                a = acumulado(a);
                b = acumulado(b);
                printf("%d\n", b-a);
                break;
            }
            default:
                return 0;
        }
    }
}


/***
/// Cuando no se cambian datos (suma en un rango)
#include <stdio.h>

10
5 6 8 9 1 2 0 5 6 8
4
1 8
3 5
2 5
3 7

36
18
24
20

int N, preguntas;
int num[100002][2];

int main()
{
    int a, b;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &num[i][0]);
    num[0][1] = num[0][0];
    for(int i=1; i<N; i++)
        num[i][1] = num[i][0] + num[i-1][1];
    scanf("%d", &preguntas);
    for(int i=0; i<preguntas; i++)
    {
        int respuesta = 0;
        scanf("%d %d", &a, &b);
        if(a > b)
        {
            int z = a;
            a = b;
            b = z;
        }
        respuesta = num[b-1][1];
        respuesta -= num[a-2][1];
        printf("%d\n", respuesta);
    }
    return 0;
}
***/
