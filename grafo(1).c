#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int vertice;
	struct no *prox;
}no_t;

typedef struct grafo{
	int num_vertice;
	no_t *VETOR_list_adj;
}grafo_t;

grafo_t *criaGRAFO(int n){
	int i;
	grafo_t *grafo = (grafo_t*)malloc(sizeof(grafo_t));
	if (!grafo){
		printf("Erro no malloc do grafo");
		exit(EXIT_FAILURE);
	}
	grafo->num_vertice = n;
	
	grafo->VETOR_list_adj = (no_t*)malloc(n * sizeof(no_t));
	if (!grafo->VETOR_list_adj){
		printf("Erro no malloc do vetor");
		exit(EXIT_FAILURE);
	}
	
	for(i = 0; i < n; i++){
		grafo->VETOR_list_adj[i].prox = NULL;
	}
	
	return grafo;
}

no_t *criaNO(int v){
	no_t *novoNO = (no_t*)malloc(sizeof(no_t));
	if (!novoNO){
		printf("Erro no malloc do novo nó");
		exit(EXIT_FAILURE);
	}
	novoNO->vertice = v;
	novoNO->prox = NULL;
	return novoNO;
}

void addARESTA(grafo_t *grafo, int origem, int destino){
	no_t *novoNO = criaNO(destino);
	novoNO->prox = grafo->VETOR_list_adj[origem].prox;
	grafo->VETOR_list_adj[origem].prox = novoNO;
}

void destroiGRAFO(int origem, int destino, grafo_t* grafo){
	if (grafo -> VETOR_list_adj){
		no_t *Elemento = grafo->VETOR_list_adj[origem].prox;
		no_t *temp = Elemento->prox;
		no_t *aux = Elemento;
		while(temp){
			if (temp->vertice == destino){
			aux->prox = temp->prox;
			free(temp);
			break;
			}
			else{
				temp = temp->prox;
				aux = aux->prox;    
			}
		}
	}
	else{
		printf("O grafo não consta na memória");
	}
}

void mostraGRAFO(grafo_t *grafo){
	int i;
	for (i = 0; i < grafo->num_vertice; i++){
		printf("\nElemento: %d", grafo->VETOR_list_adj[i].vertice);
		no_t *Elemento = grafo->VETOR_list_adj[i].prox;
		printf(" - %d", Elemento->vertice);
		while(Elemento->prox){
			printf(" - %d", Elemento->prox->vertice);
			Elemento = Elemento->prox;
		}
	}
}


int main(){
	grafo_t *dir_grafo = criaGRAFO(5);
	addARESTA(dir_grafo, 0, 1);
	addARESTA(dir_grafo, 0, 4);
	addARESTA(dir_grafo, 1, 2);
	addARESTA(dir_grafo, 1, 3);
	addARESTA(dir_grafo, 1, 4);
	addARESTA(dir_grafo, 2, 3);
	addARESTA(dir_grafo, 3, 4);
	printf("\n Grafo Direcionado - Digrafo");
	mostraGRAFO(dir_grafo);
	destroiGRAFO(1, 2, dir_grafo);
	return 0;	
}
