// problem: https://omegaup.com/arena/problem/Subsecmoncre/

#include <iostream>
using namespace std;
int numeros[1002];
int maximo[1002];
int N;
int secMax;
void lee()
{
  int i;
  cin >> N;
  /* El primer elemento de numeros sirve para iniciar */
  /* la busqueda de profundidad */
  numeros[0]=-1;
  for(i=1;i<=N;i++){
	  cin >> numeros[i];
  }
 }

int  buscar(int j)
{
	int i, k;
	int max=0;
	for(i=j+1;i<=N;i++){
		 if (numeros[i] > numeros[j]){
			 //con memorizacion pregunto si ya lo calcule para ahorrame el recalculo
			 if (maximo[i]==0){
				 k=1+buscar(i);
			 }else{
				k=1+maximo[i];
			 }
			 if (k>max){
				 max=k;
			 }
		 }
	}
	/*memorizo el maximo para que no vuelva a ser calculado*/
	maximo[j]=max;
    return (maximo[j]);
 }


int main()
{
	 lee();
	 secMax=buscar(0);
	 /*escribe solucion*/
	 cout << secMax << endl;
	 return 0;
}