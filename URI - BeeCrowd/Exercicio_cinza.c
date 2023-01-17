#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	char tipo[5];
	int T, R, G, B, nummenor, nummaior;
	int P = 0;
	
	
	scanf("%d", &T);
	
	for(int i = 0; i < T; i++)
	{
		scanf("%s", tipo);
		scanf("%d %d %d", &R, &G, &B);
		
		if(strcmp(tipo, "min")==0)
		{
			if(R < B)
			{
				nummenor = R;
				if(nummenor > G)
					nummenor = G;
			}
			else if (B > G) 
				nummenor = G;
			else
				nummenor = B;
			
			P = nummenor;
			printf("Caso #%d: %.d\n", i+1, P);
			P=0;
		}
		else if(strcmp(tipo, "mean")==0)
		{
			P = (R + G + B)/3;
			printf("Caso #%d: %.d\n", i+1, P);
			P=0;
		}
		else if(strcmp(tipo, "eye")==0)
		{
			P = 0.3*R + 0.59*G + 0.11*B;
			printf("Caso #%d: %.d\n", i+1, P);
			P=0;
		}
		else if(strcmp(tipo, "max")==0)
		{
			if(R > B)
			{
				nummaior = R;
				if(nummaior < G)
					nummaior = G;
			}
			else if (B < G) 
				nummaior = G;
			else
				nummaior = B;
			P = nummaior;
			printf("Caso #%d: %.d\n", i+1, P);
			P=0;
		}
	}
	    
		return 0;
	}