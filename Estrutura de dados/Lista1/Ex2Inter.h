/*
	Exercício 2 - Lista 1
	
	Realizado por:
	Nome Aluno 1: Lucas José Marcondes Rossi    RA: 0030482121023
	Nome Aluno 2: Guilherme Kohler Campos Salla RA: 0030482121004
*/

#define TRUE	1
#define FALSE	0
#define VALORMAX 50

typedef struct regLista
{	char cidade[30];
	int populacao;
	float territorio, PIB, IDH;
} TItem;

typedef struct
{	
    TItem listacidades[VALORMAX];
    int inicio, final;
} TLista;

void ImprimeLista(TLista *, char *, int);
void InicializaLista(TLista *);
int IncluiItem(TLista *, char *, int, float, float, float);
int ExcluiItem(TLista *, float);