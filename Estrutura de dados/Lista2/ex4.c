/*
	Exercício 4 - Lista 2
	
	Realizado por:
	Nome Aluno 1: Lucas José Marcondes Rossi    RA: 0030482121023
	Nome Aluno 2: Guilherme Kohler Campos Salla RA: 0030482121004
*/
#include <stdio.h>
#include <stdlib.h>

struct regNo
{ 	struct regNo *esq;
	int valor;
	struct regNo *dir;
};
typedef struct regNo TNo;

TNo *AchaPai(TNo *, int);
void ImprimeArvore(TNo *, int);
int info(TNo *, TNo *);

int main(void)
{	TNo *raiz = NULL, *aux, *pai, *raiz2 = NULL, *aux2,*pai2;
	int numero, M, N, B, valor, C, numero2;

	while (1)
	{	printf("\nInforme o valor:\n");
		scanf("%d", &numero);

		if (numero < 0) 
			break;
			
		aux = (TNo *) malloc(sizeof(TNo));
		aux->valor = numero;
		aux->dir = NULL;
		aux->esq = NULL;

		/* Fazendo o encadeamento do novo noh */
		pai = AchaPai(raiz, numero);
		if (pai == NULL)
			raiz = aux;
		else
			if (numero <= pai->valor)
				pai->esq = aux;
			else
				pai->dir = aux;
	}
	
	while (1)
	{	printf("\nInforme o valor 2:\n");
		scanf("%d", &numero);

		if (numero < 0) 
			break;
			
		aux2 = (TNo *) malloc(sizeof(TNo));
		aux2->valor = numero;
		aux2->dir = NULL;
		aux2->esq = NULL;

		/* Fazendo o encadeamento do novo noh */
		pai2 = AchaPai(raiz2, numero);
		if (pai2 == NULL)
			raiz2 = aux2;
		else
			if (numero <= pai2->valor)
				pai2->esq = aux2;
			else
				pai2->dir = aux2;
	}
	
	ImprimeArvore(raiz, 0);
	ImprimeArvore(raiz2, 0);
	
	if(info(raiz, raiz2) == 1)
	    printf("As arvores sao equivalentes");
	else 
	    printf("As arvores nao sao equivalentes");
	    
}

TNo *AchaPai(TNo *r, int n)
{	if (r == NULL)
		return NULL;
	else
		if (n <= r->valor)
		/* n é descendente do lado esquerdo de r */
			if (r->esq == NULL)
				return r;
			else
				return AchaPai(r->esq, n);
		else
		/* n é descendente do lado direito de r */
			if (r->dir == NULL)
				return r;
			else
				return AchaPai(r->dir, n);
}

void ImprimeArvore(TNo *r, int n)
{
	int c;
	if (r != NULL)
	{
		for(c=0; c<n; c++) 
			printf("\t");
		printf("%d\n", r->valor);
		ImprimeArvore(r->esq, n+1);
		ImprimeArvore(r->dir, n+1);
	}
}

int info(TNo *r, TNo *r2)
{
    if(r == NULL && r2 == NULL)
       return 1;
    else
    {
    if(r != NULL && r2 != NULL)
        return (r->valor == r2->valor && info(r->esq, r2->esq) && info(r->dir, r2->dir));
    else 
        return 0;
    }
}
