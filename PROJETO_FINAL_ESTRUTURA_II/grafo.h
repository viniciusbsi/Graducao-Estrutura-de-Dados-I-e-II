#include <stdio.h>
#include <stdlib.h>



typedef struct no{
	int vertice;
	struct no* prox;
}no_t;

typedef struct grafo{
	int num_vertices;
	no_t* vetor_list_adj;
	int **matriz_peso;
}grafo_t;

grafo_t* criaGrafo(int);
void addAresta(grafo_t*, int, int, int);
no_t* criaNO(int);
void mostraGrafo(grafo_t*);
int** criaMatriz(int, int, int);
void dijkstra(grafo_t*, int, int*, int*);
void insere_arco_grafo(grafo_t *, int , int , int );
void mostraGRAFO(grafo_t *);

//~ void busca_dijkstra(grafo_t*, int, int*, int*);
//~ void mostraMenorCaminho(grafo_t*);


