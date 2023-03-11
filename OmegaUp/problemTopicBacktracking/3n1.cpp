// problem: https://omegaup.com/arena/problem/El-problema-de-3n1/

#include <bits/stdc++.h>

using namespace std;
int arre[1000002];
int a,b,mayor,aux;

int calc(long long int n) {
    if(n==1) {
        return 1;
    }
    if(n<=999999) {
        if(arre[n]!=0) {
            return arre[n];
        }
    }
    int cont=0;
    if(n%2==0) {
        cont=calc(n/2)+1;
        if(n<=999999) {
            arre[n]=cont;
        }
        return cont;
    } else {
        cont=calc((n*3)+1)+1;
        if(n<=999999) {
            arre[n]=cont;
        }
        return cont;
    }
}

void res() {
    arre[1]=1;
    cin >> a >> b;
    while(a<=b) {
        if(arre[a]!=0) {
            aux=arre[a];
        } else {
            aux=calc(a);
        }
        if(aux>mayor) {
            mayor=aux;
        }
        a++;
    }
    cout << mayor;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    res();
    return 0;
}