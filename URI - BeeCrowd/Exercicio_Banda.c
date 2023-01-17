#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(void)
{
	int C, X, Y, soma;
	
	scanf("%d", &C);
	
	while(C > 0)
	{
		scanf("%d %d", &X, &Y);
		soma = X + Y;
		
		if(soma <= -1 && soma >= 11)
		printf(" \n");
			else
			{
				if (soma == 0)
					printf("PROXYCITY\n");
				else if (soma == 1)
					printf("P.Y.N.G.\n");
				else if (soma == 2)
					printf("DNSUEY!\n");
				else if (soma == 3)
					printf("SERVERS\n");
				else if (soma == 4)
					printf("HOST!\n");
				else if (soma == 5)
					printf("CRIPTONIZE\n");
				else if (soma == 6)
					printf("OFFLINE DAY\n");
				else if (soma == 7)
					printf("SALT\n");
				else if (soma == 8)
					printf("ANSWER!\n");
				else if (soma == 9)
					printf("RAR?\n");
				else if (soma == 10)
					printf("WIFI ANTENNAS\n");	
			}
		
		C = C - 1;
	}


	return 0;
}