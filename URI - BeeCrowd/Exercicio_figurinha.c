#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(void)
{
	typedef struct {int ric, vic;} TRac;

	int casos, Simpli;
	TRac qtde;
	int mdc(int, int);
	
	scanf("%d", &casos);
	
	while(casos > 0)
	{
		scanf("%d %d", &qtde.ric, &qtde.vic);
		
	Simpli = mdc(qtde.ric, qtde.vic); 
	
	printf("%d\n", Simpli.ric);
		
		casos = casos - 1;
	}

	return 0;
}



int mdc(int m, int n)
{	if (m < 0) m = -m;
	if (n < 0) n = -n;

	if (m % n == 0)
		return n;
	else
		return mdc(n, m % n);
}