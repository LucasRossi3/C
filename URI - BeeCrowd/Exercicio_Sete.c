#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int casos = 0, potencia;
	double resultado;
	int cont;
	scanf("%d", &casos);
	for(cont = 0; cont < casos; cont ++ )
	{
		scanf("%d", &potencia);
		
		if(potencia % 4 == 0)
			resultado = 1;
		else if(potencia % 4 == 1)
			resultado = 7;
		else if (potencia % 4 == 2)
		    resultado = 9;
		else if (potencia % 4 == 3)
		    resultado = 3;
			
		printf("%.lf\n", resultado);
		
	}
	return 0;
}

