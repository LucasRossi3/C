/*
	Exercício 2 - Lista 1
	
	Realizado por:
	Nome Aluno 1: Lucas José Marcondes Rossi    RA: 0030482121023
	Nome Aluno 2: Guilherme Kohler Campos Salla RA: 0030482121004
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ex2Inter.h"

int main(void)
{
	TLista lista;
	char cidade[30];
	int populacao;
	float territorio, PIB, IDH;
	int numero;
	InicializaLista(&lista);
	
	while (TRUE)
	{	
	    printf("Informe a cidade:\n");
		scanf("%s", cidade);
		
		if (strcmp(cidade, "FIM")==0)
            break;
	    printf("Informe a populacao, o territorio, o PIB e o IDH:\n");
		scanf(" %d %f %f %f", &populacao, &territorio, &PIB, &IDH);
		
            
		if (IncluiItem(&lista, cidade, populacao, territorio, PIB, IDH) == FALSE)
		{	puts("Memoria insuficiente para esta operacao");
			return 2;
		}
		
	}
		ImprimeLista(&lista, "Conteudo da lista:", TRUE);
		ImprimeLista(&lista, "Conteudo da lista:", FALSE);
		
		while (TRUE)
	{	printf("Informe o valor de IDH a excluir: ");
		scanf("%d", &numero);
	
		if (numero < 0)
			break;
		
		if (ExcluiItem(&lista, numero) == FALSE)
			puts("Valor nao encontrado");
		else
		    {
			    ImprimeLista(&lista, "Novo conteudo da lista:", TRUE);
			    ImprimeLista(&lista, "Conteudo da lista:", FALSE);
		    }
	}
	
	return 0;
}






