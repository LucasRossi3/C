/*
	Arquivo .c Implementação Exercício 1 - Lista 1
	
	Realizado por:
	Nome Aluno 1: Lucas José Marcondes Rossi    RA: 0030482121023
	Nome Aluno 2: Guilherme Kohler Campos Salla RA: 0030482121004
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ex1Inter.h"

void InicializaLista(TLista *lista)
{	/* inicializa o conjunto de descritores da lista */
	lista->inicio = NULL;
	lista->final = NULL;
}

int IncluiItem(TLista *lista, char * cidade, int populacao, float territorio, float PIB, float IDH)
{	TItem *aux;

	/* criando uma variável struct regLista dinamicamente */
	aux = (TItem *) malloc(sizeof(TItem));
	if (aux == NULL)
		return FALSE;
		
	/* preenchendo os campos da variável criada dinamicamente */
	strcpy(aux->cidade, cidade);
	aux->populacao = populacao;
	aux->territorio = territorio;
	aux->PIB = PIB;
	aux->IDH= IDH;
	aux->prox = NULL;

	/* fazendo o encadeamento do novo nó da lista */
	if (lista->inicio == NULL)
	{
	    aux->ant=NULL;
		lista->inicio = aux;
		lista->final = aux;
	}
	else
	{
	    aux->ant=lista->final;
		lista->final->prox = aux;
		lista->final = aux;
	}

	
	return TRUE;
}


void ImprimeLista(TLista *lista, char * cabec, int maneira)
{	/* imprimindo os valores da lista */
	TItem *aux;
	
	if (lista->inicio == NULL)
		puts("Lista vazia");
	else
	{	printf("\n\n\n%s\n", cabec);
		if (maneira == TRUE)
		    aux = lista->inicio;
		else 
		    aux = lista->final;
		while (aux != NULL)
		{	printf("%s\n", aux->cidade);
		    printf("%d\n", aux->populacao);
		    printf("%f\n", aux->territorio);
		    printf("%f\n", aux->PIB);
			printf("%f\n", aux->IDH);
			printf("----------------------\n");
			
			if (maneira == TRUE)
		        aux = aux->prox;
		    else 
		        aux = aux->ant;
		}
	}
}

int ExcluiItem(TLista *lista, float valor)
{	TItem *aux, *ant, *apagar;
    
    int controle = FALSE;
	/* Procurando o item a ser excluido */
	ant = NULL;
	aux = lista->inicio;
	while (aux != NULL)
	{	
		if(aux->IDH >= valor)
		{
		    apagar = aux;
		    if(aux->ant == NULL) // primeiro valor
		    {
		        if(aux->prox == NULL) // primeiro e ultimo valor
		        {
		            lista->final = NULL;
		            lista->inicio = NULL;
		            aux = NULL;
		        }
		        else // primeiro valor mas nao é o ultimo
		        {
		            lista->inicio = aux->prox;
		            aux->prox->ant = NULL;
		            aux = aux->prox;
		        }
		        
		    }
		    else // pode ser prox ou o último
		    {
		           if(aux->prox == NULL)
		        {
		            aux->ant->prox = NULL;
		            lista->final = aux->ant;
		        }
		        else // no meio 
		        {
		            aux->ant->prox = aux->prox; 
		            aux->prox->ant = aux->ant;
		        } 
		        aux = aux->ant;
		    }
		    
		    free(apagar);
		 	controle = TRUE;
		    
		}
		else
		    aux = aux->prox;
	}
		
	return controle;
}