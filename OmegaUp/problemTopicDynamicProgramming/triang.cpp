// problem: https://omegaup.com/arena/problem/Numeros-triangulares/

#include <bits/stdc++.h>

using namespace std;

int memo[10002][202];
int triangulares[202];
int N;

int f(int k, int maxi){
    //cout << k << " " << maxi << "\n";
    if(k < 0)
        return 0;
    if(k <= 1 || maxi == 1)
        return 1;
    if(memo[k][maxi] != 0)
        return memo[k][maxi];
    int total = 0;
    for(int i=maxi; i>0; i--){
        total += f(k-triangulares[i], i);
        total %= 1019;
    }
    memo[k][maxi] = total;
    return total;
}

int main(){
    int j = 0;
    cin >> N;
    while(triangulares[j] <= N){
        j++;
        triangulares[j] = triangulares[j-1] + j;
    }
    //cout << triangulares[j-1];
    cout << f(N, j-1);
    return 0;
}
