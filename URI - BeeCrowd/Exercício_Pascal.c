#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(void)
{
	int N, D;
	int resultado = 0;
	int i, j;
	char palavra[4];
	int yes, no;
	yes = 0;
	no = 0;
	
	scanf("%d %d", &N, &D);
	int X [D][N];
	int vetor [D];
	
	while(N != 0 && D != 0)
	{
		for(i = 0; i < D; i ++)
		{
			for(j = 0; j < N; j ++)
			{
				scanf("%d", &X[i][j]);
			}
			    
		}
		    strcpy(palavra, "");
		    for(i = 0; i < D; i ++)
		{
		    resultado = 0;
		    
			for(j = 0; j < N; j ++)
			{
		        resultado += X[i][j];
			}
			    vetor[i] = resultado;
			    
			if(vetor[i] == N)
			{
				yes = 1;
			}
			else if(vetor[i] != N)
			{
				no = 0;
			}
		}
	    if(yes == 1)
	    {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
        yes = 0;     
		        
		scanf("%d %d", &N, &D);
	}
	
	return 0;
}