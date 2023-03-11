// problem: https://omegaup.com/arena/problem/Cubote/

#include <iostream>

using namespace std;

int cubo[8]; // a0, b1, c2, d3, e4, f5,
int i, j, temp, menorT = 200000, menorD, menorU, mayor;
long long int ans, n, x, y;

void determinarT()
{
	for(i=0; i<6; i+=5)
	{
        for(j=1; j<6; j+=3)
		{
			temp = cubo[i] + cubo[j] + cubo[2];
			if(temp<menorT)
				menorT = temp;
			temp = (temp - cubo[2]) + cubo[3];
			if(temp<menorT)
				menorT = temp;
		}
    }
}

void determinarD()
{
	temp = menorD - cubo[2] + cubo[3];
	if(temp<menorD)
		menorD = temp;
	temp = temp - cubo[1] + cubo [4];
	if(temp<menorD)
		menorD = temp;
	temp = temp - cubo[3] + cubo[2];
	if(temp<menorD)
		menorD = temp;
	for(i=0; i<6; i+=5)
	{
        for(j=1; j<5; j++)
        {
            temp = cubo[i] + cubo[j];
            if(temp<menorD)
                menorD = temp;
        }
    }
}

long long int plataforma()
{
	x = ( 4 * menorT ) + ( ( (n-2) * 4 ) * menorD ) + ( ( (n-2) * (n-2) ) * menorU );
	return x;
}

long long int pisos()
{
	y = ( 4 * menorD ) + ( 4 * ( (n-2) * menorU ) );
	return y;
}

void formula()
{
	for(i=0; i<6; i++)
		if(cubo[i]<menorU)
			menorU = cubo[i];
	determinarT();
	determinarD();
	ans = plataforma() + ( (n-1) * pisos() );
	//ans = (4 * menorT) + (4 * (n-2) * menorD) + ( (n-1) * ( (4 * menorD) + ( (n-2) * menorU) ) );
}

void leer()
{
	cin >> n;
	for(i=0; i<6; i++)
		cin >> cubo[i];
	menorD = cubo[1] + cubo [2];
	menorU = cubo[0];
}

void CincoLados()
{
	mayor = cubo[0];
	for(i=0; i<6; i++)
	{
		ans += cubo[i];
		if(cubo[i]>mayor)
			mayor = cubo[i];
	}
	ans -= mayor;
}

int main()
{
	leer();
	switch(n)
	{
		case 1:
		{
			CincoLados();
			break;
		}
		default:
		{
			formula();
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
