// problem: https://omegaup.com/arena/problem/Canicas-repetidas/

#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie
using namespace std;

int E[100002];
int R[100002];

int N,M;
int nN,nM;
int iguales;

void maps(){
    int ant=-1;
    for(int i=1;i<=N;i++){
        if(E[i]!=ant){
            nN++;
            E[nN]=E[i];
            ant=E[i];
        }
    }
    ant=-1;
    for(int i=1;i<=M;i++){
        if(R[i]!=ant){
            nM++;
            R[nM]=R[i];
            ant=R[i];
        }
    }
}

void cuenta(){
    int p1=1,p2=1;
    while(p1<=nN){
        while(R[p2]<E[p1]&&p2<=nM)
            p2++;
        if(R[p2]==E[p1]&&p2<=nM){
            cout<<R[p2]<<" ";
            iguales++;
        }
        p1++;
    }
    if(iguales==0)
        cout<<"-1\n";
    else
        cout<<"\n";
}

int main(){
    cin>>N>>M;
    for(int i=1;i<=N;i++)
        cin>>E[i];
    sort(E+1,E+N+1);
    for(int i=1;i<=M;i++)
        cin>>R[i];
    sort(R+1,R+M+1);
    maps();
    cuenta();
    return 0;
}