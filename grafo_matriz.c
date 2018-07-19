#include "stdio.h"
#include "stdlib.h"

typedef struct digraph$
{
	int numVertice;
	int **matriz_adj;
}tipo_digrafo;

int **criaMatriz(int total_linha, int total_coluna, int valor){
	int linha, coluna;
	int **matriz = (int **)malloc(total_coluna * sizeof(int *)); // não entendi
	/*
	int *vet = (int *)malloc(n * sifeof(int)) - siginifica int vet[n], que é um vetor de inteiro
	int **mat = (int **)malloc(n * sizeof(int *)) - | * | * | * | * | * |, no qual cada posição aponta para um 
	vetor de inteiro. Isso é, armazena um vetor de ponteiro para inteiros 
	*/
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


tipo_digrafo *criaDigrafo(int num_vertice){
	tipo_digrafo *G = malloc(sizeof(tipo_digrafo));
	G->numVertice = num_vertice;
	G->matriz_adj = criaMatriz(num_vertice, num_vertice, 0);
	return G;
}

void insere_arco_digrafo (tipo_digrafo *digrafo, int origem, int
 destino){
	if (origem != destino && digrafo->matriz_adj[origem][destino] == 0){
		printf("\n Inserindo o elemento [%d][%d]\n", origem, destino);
		digrafo->matriz_adj[origem][destino] = 1;
	}
}

void mostra_digrafo(tipo_digrafo *digrafo){
	int origem, destino;
	printf("\nMATRIZ DE ADJACENCIA DO DIGRAFO\n");
	printf("     %2d  %2d  %2d  %2d  %2d \n", 0, 1, 2, 3, 4);
	printf("\n");
	for (int origem = 0; origem < digrafo->numVertice; origem++){
		printf("%2d ", origem);
		for (destino = 0; destino < digrafo->numVertice; destino++){
			printf("  %2d", digrafo->matriz_adj[origem][destino]);
		}
		printf(" \n");
	}
}

void remove_arco_digrafo(tipo_digrafo *digrafo, int origem, int destino){
	if (digrafo->matriz_adj[origem][destino] == 1){
		printf("\n Removendo o elemento [%d][%d]\n", origem, destino);
		digrafo->matriz_adj[origem][destino] = 0;
	}
}

void insere_arco_grafo(tipo_digrafo *digrafo, int origem, int destino){
	insere_arco_digrafo(digrafo, origem, destino);
	insere_arco_digrafo(digrafo, destino, origem);
}

void remove_arco_grafo(tipo_digrafo *digrafo, int origem, int destino){
	remove_arco_digrafo(digrafo, origem, destino);
	remove_arco_digrafo(digrafo, destino, origem);
}

int main(){
	tipo_digrafo *digrafo = criaDigrafo(5);
	mostra_digrafo(digrafo);
	insere_arco_grafo(digrafo, 2, 3);
	mostra_digrafo(digrafo);
	/*insere_arco_digrafo(digrafo, 0, 4);
	mostra_digrafo(digrafo);
	insere_arco_digrafo(digrafo, 1, 2);
	mostra_digrafo(digrafo);
	insere_arco_digrafo(digrafo, 2, 3);
	mostra_digrafo(digrafo);
	insere_arco_digrafo(digrafo, 3, 0);
	mostra_digrafo(digrafo);
	insere_arco_digrafo(digrafo, 3, 4);

	mostra_digrafo(digrafo);
	*/

	remove_arco_grafo(digrafo, 2, 3);
	//remove_arco_digrafo(digrafo, 2, 3);
	
	mostra_digrafo(digrafo);
	return 0;


}