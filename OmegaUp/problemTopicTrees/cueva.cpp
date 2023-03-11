// problem: https://omegaup.com/arena/problem/Cueva-de-bessie/

#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie
using namespace std;

int pila[5002];
int padres[5002];

int pos;
int tope;
int P,Ns,T;
int N,B1,B2;

int main(){
    cin>>P>>Ns>>T;
    for(int i=1;i<=Ns;i++){
        cin>>N>>B1>>B2;
        padres[B1]=padres[B2]=N;
    }
    pos=T;
    while(pos!=0){
        tope++;
        pila[tope]=pos;
        pos=padres[pos];
    }
    cout<<tope<<"\n";
    while(tope>0){
        cout<<pila[tope]<<"\n";
        tope--;
    }
    return 0;
}