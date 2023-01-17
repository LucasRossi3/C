/*
	Exercício 5 - Lista 2
	
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
int ContaNos(TNo *);
int SomaNos(TNo *);
int ContaPares(TNo *);
int ContaFolhas(TNo *);
void Apagar(TNo *);
int Maior(TNo *);
int Menor(TNo *);
int altura(TNo *);
int Pesquisa(TNo *, int);

int main(void)
{	TNo *raiz = NULL, *aux, *pai;
	int numero, M, N, B, valor, C;

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
	
	
	ImprimeArvore(raiz, 0);
	Apagar(raiz);
	
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


void Apagar(TNo *r)
{
        if(r == NULL)
		    return;
        Apagar(r->esq); 
        Apagar(r->dir);
        free(r);
}


