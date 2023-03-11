// problem: https://omegaup.com/arena/problem/Eudoxus/

#include <iostream>

using namespace std;

long long int X[70];
long long int Y[70];
int n;

int main()
{
    X[0] = 1;
    Y[0] = 0;
    cin >> n;
    for(int i=1; i<=n; i++){
        Y[i] = X[i-1] + Y[i-1];
        X[i] = Y[i] + Y[i-1];
    }
    cout << X[n] << " " << Y[n] << endl;
    return 0;
}
