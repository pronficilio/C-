#include <iostream>

using namespace std;

int inicio,fin,tope;
int flechitas[1002];
int datos[1002];

bool listavacia(){
    return inicio==0;
}

void vaciar(){
    inicio=fin=tope=0;
}

void meter(int x){
    flechitas[fin]=++tope;
    fin=tope;
    if(listavacia())
        inicio=tope;
    datos[tope]=x;
}
void eliminarI(int x){
    if(x==inicio){
        inicio=flechitas[x];
        if(inicio == -1)
            vaciar();
    }else{
        int i=inicio;
        while(flechitas[flechitas[i]]!=x){
            i=flechitas[i];
        }
        flechitas[i]=flechitas[x];
        if(x==fin){
            fin=i;
        }
    }
}

void eliminarV(int x){
    int i=inicio;
    if(datos[i]==x){
        inicio=flechitas[i];
        if(inicio==-1)
            vaciar();
        return;
    }
    while(datos[flechitas[i]]!=x)
        i=flechitas[i];
    flechitas[i]=flechitas[flechitas[i]];
    if(flechitas[i]==-1){
        fin=i;
    }
}

void optimizar(){
    int i, aux;
    i = 1;
    while(i == flechitas[i-1]){
        i++;
    }
    aux = flechitas[i-1]; /// el primer valor despues de todas las casillas seguidas que vamos a recorrer
    do{
        datos[i] = datos[aux];
        flechitas[i-1] = i;
        i++;
        aux = flechitas[aux];
    }while(flechitas[aux] != -1);
    flechitas[i-1] = -1;
}

int main()
{
    vaciar();
    cout << "Hello world!" << endl;
    return 0;
}
