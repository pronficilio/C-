// problem: https://omegaup.com/arena/problem/Vaca-fatigada/

#include <bits/stdc++.h>

using namespace std;
int arr[1002];
int memo[1002][1002];
int N,M;
int f(int pos,int factor){
    if(factor>M){
        return INT_MIN;
    }
    if(pos>N+1){
        return INT_MIN;
    }
    if(pos==(N+1) && factor>0){
        return INT_MIN;
    }
    if(pos==(N+1)){
        return 0;
    }
    if(memo[pos][factor]!=0){
        return memo[pos][factor];
    }
    int c=0;
    int d=0;
    int Total=0;
    c=f(pos+1,factor+1)+arr[pos];
    int aumento=factor;
    if(aumento==0){
        aumento=1;
    }
    d=f(pos+aumento,0);
    Total=max(c,d);
    memo[pos][factor]=Total;
    return Total;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }
    cout<<f(1,0)<<"\n";
    return 0;
}