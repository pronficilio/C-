#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct s1
{
    double Ui;
    int kien;
    int indica;
    long long int KK;
};

struct ura
{
    int indic;
    int Ci;
    int who;
    bool muerto;
};

s1 U[500002], monti[500002];
ura C[500002];
long long int W;
int N, fin;

int funtion(const void *a, const void *b)
{
    return ( ( ( (ura *) a) -> Ci) - ( ( (ura *) b) -> Ci) );
}

void meter(s1 dato)
{
    int aux;
    fin++;
    aux = fin;
    while(monti[aux/2].KK < dato.KK)
    {
        monti[aux] = monti[aux/2];
        aux /= 2;
    }
    monti[aux] = dato;
}

s1 sacar()
{
    s1 aux = monti[1], dato = monti[fin];
    int j, pos = 1;
    fin--;
    while(pos <= fin/2)
    {
        j = pos + pos;
        if(j < fin && monti[j].KK < monti[j+1].KK)
            j++;
        if(dato.KK >= monti[j].KK)
            break;
        monti[pos] = monti[j];
        pos = j;
    }
    monti[pos] = dato;
    return aux;
}

int main()
{
    long long int x, Con_Cuanto = LONG_LONG_MAX, CEROS = 1000000;
    double U_CON_ESTA, Sal_min;
    int donde = 0, contratados = 0, acm = 0, aki = 0, dond;
    monti[0].Ui = 20002;
    monti[0].KK = LONG_LONG_MAX;
    for(int i=0; i<5; i++)
        CEROS *= 10;
    scanf("%d %lld", &N, &W);
    for(int i=0; i<N; i++)
    {
        double b;
        scanf("%lf %lf", &Sal_min, &b);
        C[i].Ci = b;
        U[i].indica = i+1;
        U[i].Ui = (double) Sal_min / b;
        U[i].KK = U[i].Ui * CEROS;
        C[i].who = i;
        C[i].indic = i+1;
    }
    qsort(C, N, sizeof(C[0]), funtion);
    for(int i=0; i<N; i++)
    {
        U[C[i].who].kien = i;
        meter(U[C[i].who]);
    }
    for(int i=0; i<N; i++)
    {
        s1 U_actual = sacar();
        double actual = U_actual.Ui;
        x = W / actual;
        for(; donde<N; donde++)
        {
            if(C[donde].muerto)
                continue;
            acm += C[donde].Ci; // calificaciones acumuladas
            if(x < acm) // sobrepasa presupuesto
            {
                acm -= C[donde].Ci;
                break;
            }
            aki++;
        }
        if(aki >= contratados)
        {
            x = acm * actual;
            if(Con_Cuanto > x || aki > contratados)
            {
                contratados = aki;
                Con_Cuanto = x;
                dond = i;
                U_CON_ESTA = actual;
            }
        }
        C[U_actual.kien].muerto = true;
        if(U_actual.kien < donde)
        {
            aki--;
            acm -= C[U_actual.kien].Ci;
        }
    }
    printf("%d\n", contratados);
    acm = 0;
    for(int i=0; i<N; i++)
        meter(U[i]);
    for(int i=0; i<dond; i++)
    {
        s1 UU = sacar();
        C[UU.kien].muerto = false;
    }
    for(int i=0; i<N; i++)
    {
        if(contratados == 0)
            break;
        if(C[i].muerto)
        {
            printf("%d\n", C[i].indic);
            contratados--;
        }
    }
    return 0;
}
