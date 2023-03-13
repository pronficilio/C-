#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int PotL, NumGenes, MaxMatJ;
int MatrizJ[5002][5002];

float random2() // genera un numero random entre 0 y 1
{
    float aux;
    int temp = rand();
    aux = (float) temp / RAND_MAX;
    return aux;
}

void bigbang() /// lee archivo de entrada
{
    FILE *matrizJ;
    char nombrecito[] = "MatrizJx";
    int cAux;
    scanf("%d", &NumGenes);
    MaxMatJ = PotL = 1 << NumGenes;
    PotL++;
    MaxMatJ--;
    nombrecito[7] = NumGenes + '0';

    matrizJ = fopen(nombrecito, "a");//"a");
    
    cAux = (100 * 2) + 1;
    for(int i=0; i<MaxMatJ; i++)
        for(int j=0; j<MaxMatJ; j++)
            while(MatrizJ[i][j] == 0)
                MatrizJ[i][j] = (rand() % cAux) - 100;
    for(int i=0; i<MaxMatJ; i++){
        MatrizJ[i][i] = 0;
        for(int j=i+1; j<MaxMatJ; j++)
            if(!(random2() < 0.25))
                MatrizJ[i][j] = MatrizJ[j][i] = 0;                  
        for(int j=0; j<MaxMatJ; j++)
            fprintf(matrizJ, "%d ", MatrizJ[i][j]);
        fprintf(matrizJ, "\n");
    }
    fclose(matrizJ);
}

int main()
{
    srand((unsigned)time(0)); // semilla para el rand()
    bigbang();
    return 0;
}
