/*
	Exercício 3 - Lista 1
	
	Realizado por:
	Nome Aluno 1: Lucas José Marcondes Rossi    RA: 0030482121023
	Nome Aluno 2: Guilherme Kohler Campos Salla RA: 0030482121004
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE	1
#define FALSE	0

typedef struct regLista
{
    int valor;
    struct regLista *prox;
	struct regLista *ant;
} TItem;

typedef struct
{	TItem *inicio, *final;
} TLista;

void ImprimeLista(TLista *, char *);
void InicializaLista(TLista *);
int IncluiItem(TLista *, int);
void ExcluiItem(TLista *, TLista *);

int main(void)
{
	TLista lista, lista2;
	int valor;
	InicializaLista(&lista);
	InicializaLista(&lista2);
	
	while (TRUE)
	{	
	    printf("Informe um número para a lista 1:\n");
		scanf("%d", &valor);
		
		if (valor == -999)
            break;
	    
		if (IncluiItem(&lista, valor) == FALSE)
		{	puts("Memoria insuficiente para esta operacao");
			return 2;
		}
		
	}
	
	while (TRUE)
	{	
	    printf("Informe um número para a lista 2:\n");
		scanf("%d", &valor);
		
		if (valor == -999)
            break;
	    
		if (IncluiItem(&lista2, valor) == FALSE)
		{	puts("Memoria insuficiente para esta operacao");
			return 2;
		}
		
	}
	
	ImprimeLista(&lista, "Conteudo da lista 1:");
	ImprimeLista(&lista2, "Conteudo da lista 2:");
	
	(ExcluiItem(&lista, &lista2));
			
	ImprimeLista(&lista, "Conteudo da lista 1:");
	ImprimeLista(&lista2, "Novo conteudo da lista 2:");
		
	
	
	return 0;
}

void InicializaLista(TLista *lista)
{	/* inicializa o conjunto de descritores da lista */
	lista->inicio = NULL;
	lista->final = NULL;
}

int IncluiItem(TLista *lista, int valor)
{	TItem *aux;

	/* criando uma variável struct regLista dinamicamente */
	aux = (TItem *) malloc(sizeof(TItem));
	if (aux == NULL)
		return FALSE;
		
	/* preenchendo os campos da variável criada dinamicamente */
	aux->valor= valor;
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

void ImprimeLista(TLista *lista, char * cabec)
{	/* imprimindo os valores da lista */
	TItem *aux;
	
	if (lista->inicio == NULL)
		puts("Lista vazia");
	else
	{	printf("\n\n\n%s\n", cabec);
		aux = lista->inicio;
		
		while (aux != NULL)
		{
		    printf("%d\n", aux->valor);
		        aux = aux->prox;
		}
	}
}

void ExcluiItem(TLista *lista, TLista *lista2)
{	TItem *aux, *aux2, *apagar;
    
    
	/* Procurando o item a ser excluido */
	aux = lista->inicio;
	aux2 = lista2->inicio;
	apagar = aux2;
	
	if (aux == NULL || aux2 == NULL)
	{
		printf("lista 1 ou lista 2 nao podem ser vazias");
	}
	else
	{
	while (aux != NULL)
	{	
	    aux2 = lista2->inicio;
	    while (aux2 != NULL)
	    {
		    if(aux2->valor == aux->valor)
		    {
		        apagar = aux2;
		        if(aux2->ant == NULL) // primeiro valor
		        {
		            if(aux2->prox == NULL) // primeiro e ultimo valor
		            {
		                lista2->final = NULL;
		                lista2->inicio = NULL;
		                aux2 = NULL;
		            }
		            else // primeiro valor mas nao é o ultimo
		            {
		                lista2->inicio = aux2->prox;
		                aux2->prox->ant = NULL;
		                aux2 = aux2->prox;
		            }
		        
		        }
		        else // pode ser prox ou o último
		        {
		            if(aux2->prox == NULL)
		            {
		                aux2->ant->prox = NULL;
		                lista2->final = aux2->ant;
		            }
		            else // no meio 
		            {
		                aux2->ant->prox = aux2->prox; 
		                aux2->prox->ant = aux2->ant;
		            } 
		            aux2 = aux2->ant;
		        }
		            free(apagar);
		    }
		        aux2 = aux2->prox;
	    }
	    aux = aux->prox;
	}
	}
}
                    