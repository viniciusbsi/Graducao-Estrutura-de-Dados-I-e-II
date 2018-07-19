#include "grafo.h"
#include "fila_heap.h"

int **criaMatriz(int total_linha, int total_coluna, int valor){
	int linha, coluna;
	int **matriz = (int **)malloc(total_coluna * sizeof(int *));
	for (linha = 0; linha < total_linha; linha++){
		matriz[linha] = (int *)malloc(total_coluna * sizeof(int)); 
	}
	for (linha = 0; linha < total_linha; linha++){
		for (coluna = 0; coluna < total_coluna; coluna++){
			matriz[linha][coluna] = valor;  
		}
	}
	return matriz;
}

grafo_t* criaGrafo(int n){
	int i;
	grafo_t* grafo = (grafo_t*)malloc(sizeof(grafo_t));
	grafo->num_vertices = n;
	grafo->vetor_list_adj = (no_t*)malloc(n * sizeof(no_t));
	for(i = 0; i<n; i++){
		grafo->vetor_list_adj[i].prox = NULL;
		grafo->vetor_list_adj[i].vertice = i;
	}
	grafo->matriz_peso = criaMatriz(n, n, 0);
	return grafo;
}

no_t* criaNO(int x){
	no_t* novoNO = (no_t*)malloc(sizeof(no_t));
	novoNO->vertice = x;
	novoNO->prox = NULL;
	return novoNO;
}

void insere_arco_grafo(grafo_t *grafo, int origem, int destino, int custo){
	if (origem != destino && grafo->matriz_peso[origem][destino] == 0){
		no_t* novoNO = criaNO(origem);
		novoNO->prox = grafo->vetor_list_adj[origem].prox;
		grafo->vetor_list_adj[origem].prox = novoNO;
		grafo->matriz_peso[origem][destino] = custo;
	}
}

void percorrer(Fila* fila){
	if (fila->quantidade < 1)
		printf("Fila vazia...\n");
	else{
		for(int i=0; i < fila->quantidade; i++){
			printf("Nó: %d\t P: %d\n", fila->vetor[i].valor, fila->vetor[i].ordem);
		}
		printf("\n");
	}
}

void mostraGRAFO(grafo_t *grafo){
	int i;
	for (i = 0; i < grafo->num_vertices; i++){
		printf("\nElemento: %d", grafo->vetor_list_adj[i].vertice);
		no_t *Elemento = &grafo->vetor_list_adj[i];
		printf(" - %d", Elemento->vertice);
		while(Elemento->prox){
			printf(" - %d", Elemento->prox->vertice);
			Elemento = Elemento->prox;
		}
	}
}

void mostra_digrafo(grafo_t *digrafo){
	int origem, destino;
	printf("\nMATRIZ DE ADJACENCIA DO DIGRAFO\n");
	printf("     %2d  %2d  %2d  %2d  %2d \n", 0, 1, 2, 3, 4);
	printf("\n");
	for (int origem = 0; origem < digrafo->num_vertices; origem++){
		printf("%2d ", origem);
		for (destino = 0; destino < digrafo->num_vertices; destino++){
			printf("  %2d", digrafo->matriz_peso[origem][destino]);
		}
		printf(" \n");
	}
}

void dijkstra(grafo_t *grafo, int origem, int* pred, int* custo){
	//~ for (int i = 0; i < grafo->num_vertices; ++i){
		//~ printf("lista adj %p\n", grafo->vetor_list_adj[i].prox);
		//~ custo[i] = 1000000;
	//~ }
	for (int i = 0; i < grafo->num_vertices; ++i){
		pred[i] = -1;
		custo[i] = 1000000;
	}
	custo[origem] = 0;
	Fila* fila = inicializarFila(grafo->num_vertices);
	for (int i = 0; i < grafo->num_vertices; ++i){
		enfileirar(fila, grafo->vetor_list_adj[i].vertice, custo[i]);
	}
	//~ percorrer(fila);
	//~ printf("Custo\n");
	//~ for(int i = 0; i < 5; i++){
		//~ printf("%d \t", custo[i]);
	//~ }
	
	//~ mostra_digrafo(grafo);
	while(fila->quantidade > 1){
		int u = desenfileirar(fila);
		no_t *temp = &grafo->vetor_list_adj[u];
		while(temp->prox){
			printf("custo temp : %d \t custo U: %d \n", custo[temp->vertice], custo[u]);
			if((custo[temp->vertice]) > (custo[u] + grafo->matriz_peso[u][temp->vertice])){
				printf("no if");
				custo[temp->vertice] = custo[u] + grafo->matriz_peso[u][temp->vertice];
				pred[temp->vertice] = u;
			}
			temp = temp->prox;
		}
	}
	//~ printf("Custo\n");
	//~ for(int i = 0; i < 5; i++){
		//~ printf("%d \t", custo[i]);
	//~ }
	//~ printf("\nPred\n");
	//~ for(int i = 0; i < 5; i++){
		//~ printf("%d \t", pred[i]);
	//~ }
	//~ mostraGRAFO(grafo);
}



