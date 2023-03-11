// problem: https://omegaup.com/arena/problem/Charcos-de-lodo/

#include <iostream>

using namespace std;

int movtos[4][2]= { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};


int cf,rf, N;

int mapa[1020][1020];

int ajuste=505;

struct punto{
    int ren;
    int col;
};

punto cola[1000500];
int cIni, cFin;

void meter(punto dato){
    cFin++;
    cola[cFin]=dato;
}
punto  sacar(){
    cIni++;
    return cola[cIni];
}
bool colaVacia(){
     return cIni==cFin;
}


void leer(){
    int r,c;
    cin >> cf >> rf>>N;
    for(int i =1; i<=N;i++){
        cin >> c >> r;
        mapa[c+ajuste][r+ajuste]=1;
    }
    cf=cf+ajuste;
    rf=rf+ajuste;
}
void busqueda(){
    bool encontro;
    punto inicio, actual, nuevo;
    mapa[ajuste][ajuste]=1;
    inicio.col=ajuste;
    inicio.ren=ajuste;
    meter(inicio);
    while(!colaVacia()){
        actual=sacar();
        if (actual.col == cf && actual.ren == rf){
            cout << mapa[actual.col][actual.ren]-1<<endl;
            encontro=true;
            break;
        }
        // creo los nuevos nodos
        for(int i=0; i<4;i++){
            nuevo.col=actual.col+movtos[i][0];
            nuevo.ren=actual.ren+movtos[i][1];
            if (nuevo.col>=0 && nuevo.col <=1020 &&
                nuevo.ren>=0 && nuevo.ren <=1020) {
                if (mapa[nuevo.col][nuevo.ren]==0){
                    mapa[nuevo.col][nuevo.ren]=mapa[actual.col][actual.ren]+1; // visitados
                    meter(nuevo);
                }
            }
        }

    }
    if (!encontro){
       cout << -1<< endl; // esta de mas porque siempre hay solucion
    }

}
int main()
{
    leer();
    busqueda();

    return 0;
}