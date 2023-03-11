#include <iostream>
#include <limits.h>
//limits sirve para el INT_MAX

using namespace std;

int monti[100002] = {INT_MAX};

int limite;

void meter(int dato)
{
    int hijo;
    limite++;
    monti[limite] = dato;
    hijo = limite;
    while(monti[hijo / 2] < monti[hijo])
    {
        int aux;
        aux = monti[hijo];
        monti[hijo] = monti[hijo / 2];
        monti[hijo / 2] = aux;
        hijo = hijo / 2;
    }
}

int sacar()
{
    int padre=1;
    int valor=monti[1];//vamos a guardar el primer valor
    monti[1]=monti[limite];
    limite--;
    int hijo=padre*2;
    while(hijo<=limite)
    {//con esto aseguramos que tiene almenos 1 hijo
        if(monti[hijo+1] > monti[hijo] && (hijo+1) <= limite)
        {//encuentra al hijo mayor si este esta a la derecha
            hijo++;
        }
        if(monti[hijo]<=monti[padre])
        {//rompe el ciclo porque ya no se tiene que bajar
            break;
        }
        int aux=monti[hijo];
        monti[hijo]=monti[padre];
        monti[padre]=aux;

        padre=hijo;
        hijo=padre*2;
    }
    return valor;
}

int main()
{
    int n,dato;
    cin>>n;
    for(int i=1;i<=n;i++)
    {//lee los datos
        cin>>dato;
        meter(dato);
    }
    for(int i=1;i<=n;i++)
    {//saca los datos
        dato=sacar();
        monti[limite+1]=dato;
    }

    for(int i=1;i<=n;i++)
    {//imprime los datos
        cout<<monti[i]<<" ";
    }

    cout<<endl;
    return 0;
}
