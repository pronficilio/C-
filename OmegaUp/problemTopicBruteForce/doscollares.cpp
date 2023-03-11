// problem: https://omegaup.com/arena/problem/Dos-collares/

#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
int i, respuesta, temporal;
int acum, maximo, actual, arriba, abajo;
vector <int> collar1;
vector <int> collar2;

void leer(){
    cin >> N >> M >> K;
    i = 0;
    while(i < N){
        cin >> temporal;
        collar1.push_back(temporal);
        i = i + 1;
    }
    i = 0;
    while(i < N){
        cin >> temporal;
        collar2.push_back(temporal);
        i = i + 1;
    }
}

void duplicaVectores(){
    i = 0;
    while(i < N){
        collar1.push_back(collar1[i]);
        collar2.push_back(collar2[i]);
        i = i + 1;
    }
}

int maximoCollar(int tama, vector <int> collar){
    i = 0;
    acum = 0;
    while(i < tama){
        acum = acum + collar[i];
        i = i + 1;
    }
    maximo = acum;
    i = 0;
    while(i < N){
        acum = acum - collar[i] + collar[i+tama];
        if(acum > maximo){
            maximo = acum;
        }
        i = i + 1;
    }
    return maximo;
}

void calculaRespuesta(){
    arriba = K;
    abajo = M - K;
    while(abajo >= K){
        actual = maximoCollar(arriba, collar1);
        actual = actual + maximoCollar(abajo, collar2);

        /*cout << arriba << " -> " << actual << endl;
        cout << abajo << " -> " << temp << endl;
        cout << endl;*/

        if(actual > respuesta){
            respuesta = actual;
        }
        arriba = arriba + 1;
        abajo = abajo - 1;
    }
    cout << respuesta << endl;
}

int main(){
    leer();
    duplicaVectores();
    calculaRespuesta();
    return 0;
}
