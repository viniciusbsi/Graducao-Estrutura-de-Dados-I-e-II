#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento{
    int valor;
    struct elemento *p_prox;
}Elemento;

typedef struct{
    Elemento *p_inicio;
}Fila;


typedef struct no{
	int vertice;
	struct no *prox;
}no_t;

typedef struct grafo{
	int num_vertice;
	no_t *VETOR_list_adj;
}grafo_t;

Fila* inicializar(){
    Fila* minhaFila;
    minhaFila = (Fila*) malloc(sizeof(minhaFila));
    minhaFila->p_inicio = NULL;
    return minhaFila;
}

Elemento* criarElemento(int val){
    Elemento* novoElemento;
    novoElemento = (Elemento*) malloc (sizeof(Elemento));
    novoElemento->valor = val;
    novoElemento->p_prox = NULL;
    return novoElemento;
}

void enfileirar(Fila* fila, int  val){
    Elemento* novoElemento = criarElemento(val);
    if(fila->p_inicio == NULL){
        fila->p_inicio = novoElemento;
        novoElemento->p_prox = NULL;
    }
    else{
        Elemento *p_aux = fila->p_inicio;
        while(p_aux->p_prox != NULL){
            p_aux = p_aux->p_prox;
        }
        novoElemento->p_prox = NULL;
        p_aux->p_prox = novoElemento;
    }
}

int desenfileirar(Fila *fila){
    Elemento *elemento = fila->p_inicio;
    if(fila->p_inicio != NULL){
        fila->p_inicio = fila->p_inicio->p_prox;
    }
    return elemento->valor;
}

int verifica_fila_vazia(Fila *fila){
    if(fila->p_inicio == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

grafo_t *criaGRAFO(int n){
	int i, valor;
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
		grafo->VETOR_list_adj[i].vertice = i;
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
	printf("\n");
}

void busca_em_largura(grafo_t *grafo, int numVertice, int destino){
	/*
	Cores:
	0 = branco = não visitado
	1 = cinza = sendo visitado
	2 = preto = já visitado
	Distância:
	-1 = infinito
	*/
	printf("Tabela de busca em largura para o nó de índice %d\n", numVertice);
	int cor[5];
	int distancia[5];
	int pi[5];
	for (int i = 0; i < 5; i++){
		cor[i] = 0;
		distancia[i] = -1;
		pi[i] = -1;
	}
	cor[numVertice] = 1;
	distancia[numVertice] = 0;
	pi[numVertice] = -1;
	Fila* Q;

	Q = inicializar(Q);
	enfileirar(Q, numVertice);
	int fila_vazia = verifica_fila_vazia(Q); 
	while (fila_vazia == 0){
		int u = desenfileirar(Q);
		no_t *Elemento = grafo->VETOR_list_adj[u].prox;
		while(Elemento){
			if(cor[Elemento->vertice] == 0){
				cor[Elemento->vertice] = 1;
				distancia[Elemento->vertice] = distancia[u] + 1;
				pi[Elemento->vertice] = u;
				enfileirar(Q, Elemento->vertice);
			}
			Elemento = Elemento->prox;
		}
		cor[u] = 2;
		fila_vazia = verifica_fila_vazia(Q);
	}

	printf("      %2d  %2d  %2d  %2d  %2d \n", 0, 1, 2, 3, 4);

	printf("Cor : ");
	for (int i = 0; i < 5; i++){
		printf("|%d| ",cor[i]);
	}
	printf("\nDis : ");
	for (int i = 0; i < 5; i++){
		printf("|%d| ",distancia[i]);
	}
	printf("\nPi  : ");
	for (int i = 0; i < 5; i++){
		printf("|%d| ",pi[i]);
	}
	printf("\n");

	int distancia_vertices = distancia[destino];

	printf("Caminho saindo do vértice %d até o vértice %d \n", numVertice, destino);
	int caminho_vetor[5];

	int caminho = pi[destino];
	int i = 0;
	caminho_vetor[i] = destino;
	i++;
	while(caminho != numVertice){
		caminho_vetor[i] = caminho;
		caminho = pi[caminho];
		i++;
	}
	printf("Caminho final \n");	 
	for(int j = i; j != -1; j--){
		printf("%d -- ", caminho_vetor[j]);	
	}

}


int main(){
	int valor;
	grafo_t *dir_grafo = criaGRAFO(5);
	addARESTA(dir_grafo, 0, 1);
	addARESTA(dir_grafo, 1, 0);
	addARESTA(dir_grafo, 1, 2);
	addARESTA(dir_grafo, 1, 4);
	addARESTA(dir_grafo, 2, 3);
	addARESTA(dir_grafo, 3, 0);
	addARESTA(dir_grafo, 3, 4);
	addARESTA(dir_grafo, 4, 1);
	printf("\n Grafo Direcionado - Digrafo");
	mostraGRAFO(dir_grafo);
	busca_em_largura(dir_grafo, 0, 3);
	return 0;	
}
