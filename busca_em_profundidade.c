#include <stdio.h>
#include <stdlib.h>
#define BRANCO 0  
#define CINZA 1  
#define PRETO 2
int tempo;

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
	
	for(i = 0; i <= n; i++){
		grafo->VETOR_list_adj[i].prox = NULL;
		printf("Informe um valor entre 0 e 4 para inserir no vetor de adjacência: ");
		scanf("%d", &valor);
        grafo->VETOR_list_adj[i].vertice = valor;
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


void mostraGRAFO(grafo_t *grafo){
	int i;
	for (i = 0; i <= grafo->num_vertice; i++){
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

int veririca_cruzada(grafo_t* grafo, int u, int v, int* pi){
	int x, pai;
	for(pai = pi[v]; pai != -1; pai = pi[pai]){
		if(pi[pai] == u){
			return 1;
		}
	}
	return 0;
}

void DSF_VISIT(grafo_t* grafo, int u, int* f, int* cor, int* pi, int* distancia){
	cor[u] = CINZA;
	tempo++;
	distancia[u] = tempo;
	no_t* adj_u;
	adj_u = grafo->VETOR_list_adj[u].prox;
	while (adj_u != NULL){
		if(cor[adj_u->vertice] == BRANCO){
			printf("A aresta %d->%d é uma ARESTA DE ÁRVORE\n", u, adj_u->vertice);
			pi[adj_u->vertice] = u;
			DSF_VISIT(grafo, adj_u->vertice, f, cor, pi, distancia);
		}
		else if(cor[adj_u->vertice] == CINZA){
			printf("A aresta %d->%d é uma ARESTA DE RETORNO\n", u, adj_u->vertice);
		}
		else{
			if(veririca_cruzada(grafo, u, adj_u->vertice, pi)==1){
				printf("A aresta %d->%d é uma ARESTA DIRETA\n", u, adj_u->vertice);
			}
			else{
				printf("A aresta %d->%d é uma ARESTA CRUZADA\n", u, adj_u->vertice);
			}
		}
		adj_u = adj_u->prox;
	}
	cor[u] = PRETO;
	tempo++;
	f[u] = tempo;
}


void busca_em_profundidade(grafo_t *grafo){
	printf("Tabela de busca em profundidade \n");
	int cor[grafo->num_vertice];
	int distancia[grafo->num_vertice];
	int pi[grafo->num_vertice];
	int f[grafo->num_vertice];
	int i, tempo;
	tempo = 0;

	for (i = 0; i < grafo->num_vertice; i++){
		cor[i] = BRANCO;
		distancia[i] = -1;
		pi[i] = -1;
		f[i] = -1;
	}
	for(i = 0; i < grafo->num_vertice; i++){
		if (cor[i] == BRANCO){
			DSF_VISIT(grafo, i, f, cor, pi, distancia);
		}
	}

	printf("      %2d  %2d  %2d  %2d  %2d  %2d \n", 0, 1, 2, 3, 4, 5);
	printf("Cor : ");
	for (int i = 0; i <= 5; i++){
		printf("|%d| ",cor[i]);
	}
	printf("\nDis : ");
	for (int i = 0; i <= 5; i++){
		printf("|%d| ",distancia[i]);
	}
	printf("\nPi  : ");
	for (int i = 0; i <= 5; i++){
		printf("|%d| ",pi[i]);
	}
	printf("\nF  : ");
	for (int i = 0; i <= 5; i++){
		printf("|%d| ",f[i]);
	}
	printf("\n");
}

int main(){
	int valor;
	grafo_t *dir_grafo = criaGRAFO(5);
	addARESTA(dir_grafo, 0, 1);
	addARESTA(dir_grafo, 0, 2);
	addARESTA(dir_grafo, 1, 2);
	addARESTA(dir_grafo, 2, 3);
	addARESTA(dir_grafo, 3, 1);
	addARESTA(dir_grafo, 4, 3);
	addARESTA(dir_grafo, 4, 5);
	addARESTA(dir_grafo, 5, 5);
	printf("\n Grafo Direcionado - Digrafo");
	mostraGRAFO(dir_grafo);
	busca_em_profundidade(dir_grafo);
	return 0;	
}
