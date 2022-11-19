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

void InicializaLista(TLista *lista)
{	/* inicializa o conjunto de descritores da lista */
	lista->inicio = 0;
	lista->final = 0;
}

int IncluiItem(TLista *lista, char * cidade, int populacao, float territorio, float PIB, float IDH)
{	TItem aux;

    if (lista->final == VALORMAX)
        return FALSE;
        
    
        
	/* preenchendo os campos da variável */
	strcpy(aux.cidade, cidade);
	aux.populacao = populacao;
	aux.territorio = territorio;
	aux.PIB = PIB;
	aux.IDH= IDH;

	lista->listacidades[lista->final] = aux;
	lista->final = lista->final + 1;

	
	return TRUE;
}

void ImprimeLista(TLista *lista, char *cabec, int maneira)
{	/* imprimindo os valores da lista */
	int cont = 0;

	if (lista->final == 0)
		puts("Lista vazia");
	else
	{	
	    if (maneira == TRUE)
	    {
	        printf("\n\n\n%s\n", cabec);
		    cont = 0;
		    while (cont != lista->final)
		    {	
		        printf("%s\n", lista->listacidades[cont].cidade);
		        printf("%d\n", lista->listacidades[cont].populacao);
		        printf("%f\n", lista->listacidades[cont].territorio);
		        printf("%f\n", lista->listacidades[cont].PIB);
			    printf("%f\n", lista->listacidades[cont].IDH);
			    
			    cont = cont + 1;
		    }
	    }
	    else
	    {
	        printf("\n\n\n%s\n", cabec);
		    cont = lista->final-1;
		    while (cont >= lista->inicio)
		    {	
		        printf("%s\n", lista->listacidades[cont].cidade);
		        printf("%d\n", lista->listacidades[cont].populacao);
		        printf("%f\n", lista->listacidades[cont].territorio);
		        printf("%f\n", lista->listacidades[cont].PIB);
			    printf("%f\n", lista->listacidades[cont].IDH);
			    
			    cont = cont - 1;
		    }
	    }
	}
}

int ExcluiItem(TLista *lista, float valor)
{	int cont, cont2, controle = FALSE;
    
    cont = 0;
    
    while (cont-1 < lista->final)
    {
        
        if(lista->listacidades[cont].IDH >= valor)
        {
            cont2 = cont;
            while(cont2 < lista->final) // Colocar os itens da frente para trás
            {
                lista->listacidades[cont2] = lista->listacidades[cont2 + 1];
                cont2 ++;
            }
                
                lista->final = lista->final-1;
                controle = TRUE;
                cont = cont -1;
        }
        cont += 1;
    }
		
	return controle;
}