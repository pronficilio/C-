// problem: https://omegaup.com/arena/problem/Penthouse/

#include <stdio.h>

#define MOD 987654321


int main()
{
	int n;
	unsigned int resp = 1;
	unsigned int maxim=1;
	scanf("%d", &n);
	for(int i=1; i<n; i++)
	{
		resp = resp * 2 + maxim;
		resp %= MOD;
		maxim *= 2;
		maxim %= MOD;
	}
	resp *= 2;
	resp %= MOD;
	printf("%u\n", resp);
	return 0;
}