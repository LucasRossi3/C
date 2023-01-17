/*
	Arquivo de Interface Exercício 1 - Lista 1
	
	Realizado por:
	Nome Aluno 1: Lucas José Marcondes Rossi    RA: 0030482121023
	Nome Aluno 2: Guilherme Kohler Campos Salla RA: 0030482121004
*/

#define TRUE	1
#define FALSE	0

typedef struct regLista
{	char cidade[30];
	int populacao;
	float territorio, PIB, IDH;
	struct regLista *prox;
	struct regLista *ant;
} TItem;

typedef struct
{	TItem *inicio, *final;
} TLista;

void ImprimeLista(TLista *, char *, int);
void InicializaLista(TLista *);
int IncluiItem(TLista *, char *, int, float, float, float);
int ExcluiItem(TLista *, float);