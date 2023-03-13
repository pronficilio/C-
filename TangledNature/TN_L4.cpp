#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

const int PotL = 17, NumGenes = 4, MaxMatJ = 15;
int MatrizJ[20][20];
int SHist[50002], GSpace[20], monti[20];
int TotalInd, tfinal, Time, corrida = -1, lim, c, fin;
float pkill, pmut, Mu, teta;
char nombre[20];

void borrar(int dato, int mont[])
{
    int j, aux, padre = -1;
    for(int i=1; i<=fin; i++)
        if(dato == mont[i])
        {
            padre = i;
            break;
        }
    if(padre == -1)
        return;
    aux = mont[fin--];
    while(padre <= fin/2)
    {
        j = padre + padre;
        if(j < fin && mont[j+1] < mont[j])
            j++;
        if(aux < mont[j])
            break;
        mont[padre] = mont[j];
        padre = j;
    }
    mont[padre] = aux;
}

void meter(int dato, int mont[])
{
    int aux = ++fin;
    while(mont[aux/2] > dato)
    {
        mont[aux] = mont[aux/2];
        aux /= 2;
    }
    mont[aux] = dato;
}

int construc() // para no repetir los archivos guardados
{
    FILE *archivo;
    int N = 0;
    archivo = fopen("Constructor.tmp", "r");
    fscanf(archivo, "%d", &N);
    fclose(archivo);
    archivo = fopen("Constructor.tmp", "w");
    fprintf(archivo, "%d\n", N+1);
    fclose(archivo);
    return N % 10;
}

void guardar_generacion(int GS[])
{
    static int contador = -1;
    FILE *output;
    if(contador == -1) // inicializa el nombre del super archivo
    {
        contador = 0;
        lim = 0;
        while(nombre[lim] != '\0')
            lim++;
        nombre[lim] = '0' + corrida;
		nombre[++lim] = ':';
        nombre[++lim] = '0';
		lim++;
    }
    if(contador % 100000 == 0) // "optimiza" el guardado de datos
    {
        int aux = 0;
        aux = (contador / 100000) % 10;
		if(contador % 1000000 == 0)
			nombre[lim-1] = '0' + (contador / 1000000);
        nombre[lim] = aux + '0';
    }
    output = fopen(nombre, "a");
    /*fprintf(output, "GI-%d\n", contador);
    for(int i=1; i<=fin; i++)
        fprintf(output, "%d\t%d\n", monti[i], GS[monti[i]]);
    fprintf(output, "GF\n\n");*/
    fprintf(output, "%d\t%d\n", contador, TotalInd);
    fclose(output);
    contador++;
}

float random2() // genera un numero random entre 0 y 1
{
    float aux;
    int temp = rand();
    aux = (float) temp / RAND_MAX;
    return aux;
}

int sacar(int ind, int pos) // saca el bit en la posicion "pos" de un numero ind
{
    ind >>= pos;
    return (ind & 1);
}

void bigbang(int SH[], int GS[]) /// lee archivo de entrada
{
    FILE *input, *matrizJ;
    // ini nos dice cuantos tipos de individuos al inicio hay
    // indica navega en el arreglo y evita dobles calculos
    int ini, indica = 1, cAux;
    char lectura[2][20];
    input = fopen("lectura", "r");
    matrizJ = fopen("MatrizJ4", "a");//"a");
    // nombre.mdo nombre.pal nombre.pa.guardar
    fscanf(input, "%s %s %s", &lectura[0][0], &lectura[1][0], &nombre[0]);
    fclose(input);
    // mundo
    input = fopen(lectura[0], "r");
    fscanf(input, "%d", &tfinal);
    fscanf(input, "%f", &pkill);
    fscanf(input, "%f", &pmut);
    fscanf(input, "%f", &Mu);
    fscanf(input, "%d", &c);
    fscanf(input, "%f", &teta);
    fclose(input);
    cAux = (c * 2) + 1;
    for(int i=0; i<MaxMatJ; i++)
        for(int j=0; j<MaxMatJ; j++)
            while(MatrizJ[i][j] == 0)
                MatrizJ[i][j] = (rand() % cAux) - c;
    for(int i=0; i<MaxMatJ; i++){
        for(int j=0; j<MaxMatJ; j++){
            if(!(random2() < teta))
                MatrizJ[i][j] = MatrizJ[j][i] = 0;
            fprintf(matrizJ, "%d ", MatrizJ[i][j]);
        }
        fprintf(matrizJ, "\n");
    }
    fclose(matrizJ);
    exit(0);
    for(int i=1; i<=MaxMatJ; i++)
        for(int j=1; j<=MaxMatJ; j++)
            fscanf(matrizJ, "%d", &MatrizJ[i][j]);
    fclose(matrizJ);
    // individuos iniciales
    input = fopen(lectura[1], "r");
    fscanf(input, "%d", &ini);
    for(short i=0; i<ini; i++)
    {
        int cuantos, gen = 0;
        fscanf(input, "%d", &cuantos);
        for(short j=0; j<NumGenes; j++)
        {
            int valor;
            fscanf(input, "%d", &valor);
            // se recorren todos los bits a la izquierda
            gen <<= 1;
            // como valor puede ser 1 o 0, solo se le suma y queda acomodado
            gen += valor;
        }
        // ahora gen contiene un numero clave para el tipo de individuo
        // es cuestion de copiar ese numero clave "cuantos" veces
        meter(gen, monti);
        for(short j=0; j<cuantos; j++)
        {
            SH[indica] = gen;
            GS[gen]++;
            indica++;
        }
    }
    TotalInd = indica - 1;
    corrida = construc();
    fclose(input);
}

short Jde(int Sa, int Sb) // regresa el valor de MatrizJ[linaje(Sa)][linaje(Sb)]
{
    short i, j;
    i = Sa;
    j = Sb;
    if(Sa == Sb)
        return 0;
    return MatrizJ[i][j];
}

int prodSpin(int a, int b) // regresa resultado de una formula extrania
{
    return ((2 * a) - 1) * ((2 * b) - 1);
}

float H(int alfa, int SH[], int GS[]) // realiza formulas, solo regresa resultado.
{
    int Ndet;
    double parcial = 0.0;

    Ndet = TotalInd;
    for(int i=1; i<=fin; i++)
    {
        double parcial1 = 0.0;
        int beta = monti[i];
        for(short i=0; i<NumGenes; i++)
            parcial1 += (Jde(SH[alfa], beta) * prodSpin(sacar(SH[alfa], i), sacar(beta, i)));
        parcial += (parcial1 * GS[beta]);
    }
    parcial = ((double) parcial / Ndet) - (Mu * Ndet);

    return (float) parcial;
}

float poff(int a, int SH[], int GS[]) // realiza formulas, solo regresa resultado.
{
    float HdeSyT = H(a, SH, GS), aux;
    aux = exp(HdeSyT)/(1+exp(HdeSyT));
    return aux;
}

void reproduce(int SH[], int GS[]) /// reproduce los vivos
{
    int i = 1, donde, auxxx;
    double prob, promedio = 0.0;
    donde = TotalInd + 1;
    while(i <= TotalInd)
    {
        //auxxx = (rand() % TotalInd) + 1;
        prob = poff(i, SH, GS);
        if(donde == 50000)
            exit(-1);
        if(random2() < prob)
            SH[donde++] = SH[i];
        i++;
    }
    SH[donde] = -1; // tope
}

void mutate(int SH[], int GS[])
{
    int tope = TotalInd + 1;
    while(SH[tope] != -1)
    {
        for(short j=0; j<NumGenes; j++)
        {
            if(random2() < pmut)
            {
                if(sacar(SH[tope], j) == 0)
                    SH[tope] += (1 << j);
                else
                    SH[tope] -= (1 << j);
            }
        }
        if(GS[SH[tope]] == 0)
            meter(SH[tope], monti);
        GS[SH[tope++]]++;
    }
    SH[tope] = 0; // quita el tope
    TotalInd = tope - 1; // actualiza
}

void anhilate(int SH[], int GS[]) /// mata a lo loco
{
    int tope = 1;
    for(int i=1; i<=TotalInd; i++)
    {
        if(random2() < pkill || SH[i] == 0) // si le toca morir
        {
            GS[SH[i]]--; // donde G es la cubeta
            if(GS[SH[i]] == 0)
                borrar(SH[i], monti);
            SH[i] = 0;
        }
        else // sino le toca morir, esta vivo
            SH[tope++] = SH[i];
    }
    TotalInd = tope - 1;
}

void coevolve(int SH[], int GS[]) // manda llamar anhilate, reproduce y mutate
{
    anhilate(SH, GS);
    reproduce(SH, GS);
    mutate(SH, GS);
}

int main()
{
    srand((unsigned)time(0)); // semilla para el rand()
    int timeStep = 0;
    Time = 1;
    monti[0] = -1;

    bigbang(SHist, GSpace);
	do
	{
        timeStep = (float) TotalInd / pkill;
        guardar_generacion(GSpace);
        for(int _ts=0; _ts<timeStep; _ts++)
	        coevolve(SHist, GSpace);        
	    Time++;
	}
	while(Time < tfinal && TotalInd != 0);
	guardar_generacion(GSpace);

    return 0;
}
