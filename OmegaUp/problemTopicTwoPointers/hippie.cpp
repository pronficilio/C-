// problem: https://omegaup.com/arena/problem/Las-cuentas-del-hippie/

#include <iostream>

using namespace std;

int N[120000], n, c, desperdicio, desMinimo, negras, i, f;

void leer()
{
    cin >> c;
    cin >> n;
    for(i=0; i<n; i++)
        cin >> N[i];
    for(i=0; i<n; i++)
        N[n+i] = N[i];
}

void AvNegras()
{
    while(negras<c)
    {
        f++;
        if(N[f] == 1)
            desperdicio++;
        if(!N[f])
            negras++;
    }
}

void inicio()
{
    i=0;
    while(N[i])
        i++;
    negras = 1;
    f = i;
    AvNegras();
    desMinimo = desperdicio;
}

void AvBlancas()
{
    negras--;
    i++;
    while(N[i])
    {
        if(N[i] == 1)
            desperdicio--;
        i++;
    }
}

void barre()
{
    while (i<=n)
    {
        AvBlancas();
        AvNegras();
        if(desperdicio<desMinimo)
            desMinimo = desperdicio;
    }
}

int main()
{
    leer();
    inicio();
    barre();
    cout << desMinimo << endl;
    return 0;
}
