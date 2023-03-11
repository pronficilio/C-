// problem: https://omegaup.com/arena/problem/Ancho-de-un-arbol/

#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int dato;
    int num;
    struct nodo *der;
    struct nodo *izq;
};

void insertar(struct nodo *actual,int dato,int izq,int der){
    if(actual!=NULL){
        if(actual->dato!=dato){
            insertar(actual->izq,dato,izq,der);
            insertar(actual->der,dato,izq,der);
        }else{
            if(izq!=-1){
                struct nodo *aux=(struct nodo*)malloc(sizeof(struct nodo));
                aux->dato=izq;
                aux->izq=aux->der=NULL;

                actual->izq=aux;
            }
            if(der!=-1){
                struct nodo *aux2=(struct nodo*)malloc(sizeof(struct nodo));
                aux2->dato=der;
                aux2->izq=aux2->der=NULL;

                actual->der=aux2;
            }
        }
    }
}

void orden(struct nodo *actual,int *num){
    if(actual!=NULL){
        orden(actual->izq,num);
        actual->num=*num;
        (*num)=(*num)+1;
        orden(actual->der,num);
    }
}

void recorrido1(struct nodo *actual,int arre[2][1001], int nivel){
    if(actual!=NULL){
        if(arre[0][nivel]==0){
            arre[0][nivel]=actual->num;
        }
        recorrido1(actual->izq,arre,nivel+1);
        recorrido1(actual->der,arre,nivel+1);
    }
}
void recorrido2(struct nodo *actual,int arre[2][1001], int nivel){
    if(actual!=NULL){
        if(arre[1][nivel]==0){
            arre[1][nivel]=actual->num;
        }
        recorrido2(actual->der,arre,nivel+1);
        recorrido2(actual->izq,arre,nivel+1);
    }
}

void libera(struct nodo *actual){
    if(actual!=NULL){
        libera(actual->izq);
        libera(actual->der);
        free(actual);
    }
}


int main()
{
    struct nodo *raiz=malloc(sizeof(raiz));
    struct nodo *aux,*aux2;
    int n,i,dato,izq,der,num=1,anchos[2][1001];

    raiz->dato=1;
    raiz->der=raiz->izq=NULL;
    aux=raiz;

    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d %d",&dato,&izq,&der);
        if(izq!=-1||der!=-1){
            insertar(raiz,dato,izq,der);
            raiz=aux;
        }
    }
    orden(raiz,&num);
    raiz=aux;

    for(i=1;i<=1000;i++){
        anchos[0][i]=anchos[1][i]=0;
    }

    aux2=raiz->der;
    raiz->der=NULL;
    recorrido1(raiz,anchos,1);
    raiz=aux;
    raiz->der=aux2;

    aux2=raiz->izq;
    raiz->izq=NULL;
    recorrido2(raiz,anchos,1);
    raiz=aux;
    raiz->izq=aux2;

    libera(raiz);

    int nivel=1,anchomax=1;
    for(i=1;i<=1000;i++){
        if(anchos[0][i]!=0&&anchos[1][i]!=0){
            if((anchos[1][i]-anchos[0][i]+1)>anchomax){
                anchomax=anchos[1][i]-anchos[0][i]+1;
                nivel=i;
            }
        }
    }
    printf("%d %d\n",nivel,anchomax);
    return 0;
}