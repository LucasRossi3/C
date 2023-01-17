/*
	Programa de construção e impressão de uma arvore binaria ordenada.
	É o mesmo programa existente em 66_ED-Arvores.pdf
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
	if (r != NULL)
	{
		printf("<");
		ImprimeArvore(r->esq,0);
		printf("%d", r->valor);
		ImprimeArvore(r->dir,0);
		printf(">");
	}
	else
		printf("< >");
}

int ContaFolhas(TNo *r)
{
	if(r == NULL)
		return 0;
	
	if (((r->esq) == 0 && (r->dir) == 0) == 1)
		return 1 + (ContaFolhas(r->esq) + ContaFolhas(r->dir));
	else
		return (ContaFolhas(r->esq) + ContaFolhas(r->dir));
}

void Apagar(TNo *r)
{
        if(r == NULL)
		    return;
        Apagar(r->esq); 
        Apagar(r->dir);
        free(r);
}

int Maior(TNo *r)
{
    int m;
    
        if(r == NULL)
		    return 0;
		if(r->dir == NULL)
		{
		     m = r->valor;
		}
        else
        {
            return Maior(r->dir);
        }
        
        
        return m;
}

int Menor(TNo *r)
{
    int m;
    
        if(r == NULL)
		    return 0;
		if(r->esq == NULL)
		{
		     m = r->valor;
		}
        else
        {
            return Menor(r->esq);
        }
        
        return m;
}

int altura(TNo *r)
{
    int esq;
    int dir;
    if(r == NULL)
       return 0;
    else
    {
        esq = altura(r->esq);
        dir = altura(r->dir);
        if(esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}

int Pesquisa(TNo *r, int valor)
{
    if(r == NULL)
       return 0;
    else
    {
        if(valor == r->valor)
        {
            return 1;
        }
        else 
        {
            return Pesquisa(r->dir, valor);
            return Pesquisa(r->esq, valor);
        }
    }
}
