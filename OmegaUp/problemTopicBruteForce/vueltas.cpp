// problem: https://omegaup.com/arena/problem/L-OMI2010-Vueltas/

#include <bits/stdc++.h>

using namespace std;
int n,m,k,v,h;
char letra;
int arr[1002][1002];
void leer(){
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>letra;
        if(letra=='H'){
            h++;
        }else{
            v++;
        }
    }
    h=h%2;
    v=v%2;
}
void Normal(){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
}
void Doble(){
    for(int i=m;i>=1;i--){
        for(int j=n;j>=1;j--){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
}
void Vertical(){
    for(int i=m;i>=1;i--){
        for(int j=1;j<=n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
}
void Horizontal(){
    for(int i=1;i<=m;i++){
        for(int j=n;j>=1;j--){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    leer();
    if(h==1 and v==1){
        Doble();
    }else if(h==1){
        Horizontal();
    }else if(v==1){
        Vertical();
    }else{
        Normal();
    }
    return 0;
}