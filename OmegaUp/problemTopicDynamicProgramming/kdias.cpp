// problem: https://omegaup.com/arena/problem/K-dias/

#include <bits/stdc++.h>
#define noNodos 208
#define noDias 1008
using namespace std;
struct graph{
    int sig;
    int nodo;
    int costo;
};
graph conexion[noDias];
int ult[noDias];
int ini[noDias];
int tope=0;
void conecta(int a,int b,int c){
    conexion[++tope].nodo=b;
    conexion[tope].costo=c;
    conexion[ult[a]].sig=tope;
    if(ult[a]==0){
        ini[a]=tope;
    }
    ult[a]=tope;
}
int N,objetivo,M;
int memo[noNodos][2];
/*int f(int nodo,int dia){
    if(dia==0){
        if(nodo==objetivo){
            return 0;
        }
        return INT_MAX;
    }
    if(memo[nodo][dia]!=-1){
        return memo[nodo][dia];
    }
    memo[nodo][dia]=INT_MAX;
    int i=ini[nodo];
    while(conexion[i].nodo!=0){
        int aux=f(conexion[i].nodo,dia-1);
        if(aux!=INT_MAX){
            aux += conexion[i].costo;
        }
        memo[nodo][dia]=min(memo[nodo][dia],aux);
        i=conexion[i].sig;
    }
    return memo[nodo][dia];
}*/
int K;
void DP(){
    for(int nodo=0;nodo<=N;nodo++){
        memo[nodo][0]=INT_MAX;
    }
    memo[objetivo][0]=0;
    for(int dia=1;dia<=K;dia++){
        bool ant=1,sig=0;
        if(dia & 1){
            ant=0;
            sig=1;
        }
        for(int nodo=N;nodo>=1;nodo--){
            memo[nodo][sig]=INT_MAX;
            int i=ini[nodo];
            while(conexion[i].nodo!=0){
                int aux=memo[conexion[i].nodo][ant];
                if(aux!=INT_MAX){
                    aux += conexion[i].costo;
                }
                memo[nodo][sig]=min(memo[nodo][sig],aux);
                i=conexion[i].sig;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int x,y,prize;
    cin>>N>>objetivo>>K>>M;
    ///inicializa
    /*for(int i=0;i<=N;i++){
        for(int j=0;j<=K;j++){
            memo[i][j]=-1;
        }
    }*/
    ///fin inicializa
    for(int i=1;i<=M;i++){
        cin>>x>>y>>prize;
        conecta(x,y,prize);
    }
    //cout<<f(1,K)<<"\n";
    DP();
    cout<<memo[1][K & 1]<<"\n";
}