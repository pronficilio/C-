// problem: https://omegaup.com/arena/problem/Fibomod/

#include <iostream>

using namespace std;

int main(){
    int A, B, C, aux;
    int i = 2;
    cin >> A >> B >> C;
    if(A == 0){
        cout << "0" << endl;
        return 0;
    }
    if(B == 0){
        cout << "1" << endl;
        return 0;
    }
    while(i < 5000000){
        aux = (A + B) % C;
        if(aux == 0){
            cout << i << endl;
            break;
        }
        A = B;
        B = aux;
        i++;
    }
    if(i == 5000000)
        cout << "-1" << endl;

    return 0;
}
