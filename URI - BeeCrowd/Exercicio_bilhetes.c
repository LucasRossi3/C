#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int x;

int main(void)
{
	
	int N, M;
	int dupli = 0;
	int cont = 0;
	int bilhetes[M];
	
	
	scanf("%d %d", &N, &M);
	while(N != 0 && M != 0)
	{
	while(cont < M)
	{
	    scanf("%d", &bilhetes[cont]);
	    //printf("%d", bilhetes[cont]);
	    cont ++;
	}
	
		if(N < M)
		{
			dupli = M - N;
			printf("%d\n", dupli);
			
		}
		else if (N == M)
		{
		    for(cont = 0;cont < M; cont++) 
		    {
		        for( x = cont + 1; x < M; x++)
			    if (bilhetes[cont] == bilhetes[x])
			    {
			        dupli = dupli + 1;
			    }
			
		    }
		    printf("%d\n", dupli);
		}
		scanf("%d %d", &N, &M);
	}
	return 0;
}
