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
    char palavra [30];
    struct regLista *prox;
	struct regLista *ant;
} TItem;

typedef struct
{	TItem *inicio, *final;
} TLista;

void ImprimeLista(TLista *, char *);
void InicializaLista(TLista *);
int IncluiItem(TLista *, char *);
void ExcluiItem(TLista *, TLista *);
void ListaUniao(TLista *, TLista *, TLista *);
void ExcluiItemDiferentes(TLista *, TLista *);

int main(void)
{
	TLista lista, lista2, Uniao, Intersecao, listateste, listadiferenca1, lista3;
	char palavra [30];
	InicializaLista(&lista);
	InicializaLista(&lista2);
	InicializaLista(&Intersecao);
	InicializaLista(&Uniao);
	InicializaLista(&listateste);
	InicializaLista(&listadiferenca1);
	InicializaLista(&lista3);
	
	while (TRUE)
	{	
		printf("Informe a palavra para lista 1:\n");
		scanf("%s", palavra);
		
		if (strcmp(palavra,"*") == FALSE)
			break;
			
		if (IncluiItem(&lista, palavra) == FALSE)
		{	
			puts("Memoria insuficiente para esta operacao\n");
			return 2;
		}
		
		if (IncluiItem(&listadiferenca1, palavra) == FALSE)
		{	
			puts("Memoria insuficiente para esta operacao\n");
			return 2;
		}
		
		if (IncluiItem(&lista3, palavra) == FALSE)
		{	
			puts("Memoria insuficiente para esta operacao\n");
			return 2;
		}
	}
	    ImprimeLista(&lista, "Conteudo da lista 1:");
	    
	while (TRUE)
	{	
		printf("Informe a palavra para lista 2:\n");
		scanf("%s", palavra);
		
		if (strcmp(palavra,"*") == FALSE)
			break;
			
		if (IncluiItem(&lista2, palavra) == FALSE)
		{	
			puts("Memoria insuficiente para esta operacao\n");
			return 2;
		}
		
		if (IncluiItem(&listateste, palavra) == FALSE)
		{	
			puts("Memoria insuficiente para esta operacao\n");
			return 2;
		}
		
		if (IncluiItem(&Intersecao, palavra) == FALSE)
		{	
			puts("Memoria insuficiente para esta operacao\n");
			return 2;
		}
	}
	    
		ImprimeLista(&lista2, "Conteudo da lista 2:");
		
		(ExcluiItem(&lista, &lista2));
		
		ListaUniao(&lista, &lista2, &Uniao);
		
		ImprimeLista(&Uniao, "Conteudo da lista 3:");
		
		(ExcluiItemDiferentes(&lista3, &Intersecao));
		
		ImprimeLista(&Intersecao, "Conteudo da lista Intersecao");
		
		(ExcluiItem(&listateste, &listadiferenca1));
		
		ImprimeLista(&listadiferenca1, "Conteudo da lista Diferenca da Lista1 - Lista2:");
		
		(ExcluiItem(&lista, &listateste));
		
		ImprimeLista(&listateste, "Conteudo da lista Diferenca da Lista2 - Lista1:");
		
	
	return 0;
}

void InicializaLista(TLista *lista)
{	/* inicializa o conjunto de descritores da lista */
	lista->inicio = NULL;
	lista->final = NULL;
}

int IncluiItem(TLista *lista, char *palavra)
{	TItem *aux;

	/* criando uma variável struct regLista dinamicamente */
	aux = (TItem *) malloc(sizeof(TItem));
	if (aux == NULL)
		return FALSE;
		
	/* preenchendo os campos da variável criada dinamicamente */
	strcpy(aux->palavra, palavra);
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
		    printf("%s\n", aux->palavra);
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
		    if(strcmp(aux2->palavra, aux->palavra) == FALSE)
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

void ListaUniao(TLista *lista, TLista *lista2, TLista *Uniao)
{
    TItem *aux, *aux2;
    aux = lista->inicio;
	aux2 = lista2->inicio;
	
	if (aux == NULL || aux2 == NULL)
	{
		printf("lista 1 ou lista 2 nao podem ser vazias");
	}
	else
	{
	    while(aux != NULL)
	    {
	        IncluiItem(Uniao, aux->palavra);
            aux = aux->prox;
	    }
	    while(aux2 != NULL)
	    {
	        IncluiItem(Uniao, aux2->palavra);
            aux2 = aux2->prox;
	    }
	}
		
}

void ExcluiItemDiferentes(TLista *lista, TLista *lista2)
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
		    if(strcmp(aux2->palavra, aux->palavra) == TRUE)
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




                    