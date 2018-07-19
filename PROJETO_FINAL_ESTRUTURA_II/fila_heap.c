#include "fila_heap.h"

Fila* inicializarFila(int tamanho){
	Fila* minhaFila;
	minhaFila = (Fila*) malloc(sizeof(Fila));
	minhaFila->vetor = (Elemento*) malloc(tamanho * sizeof(Elemento));
	minhaFila->quantidade = 0;
	minhaFila->capacidade = tamanho;
	return minhaFila;
}

void enfileirar(Fila* fila, int valor, int ordem){
	Elemento elemento = criarElementoFila(valor, ordem);
	if(fila->quantidade < 1){
        fila->vetor[0] = elemento;
    }
    else if(fila->quantidade < fila->capacidade){
    	fila->vetor[fila->quantidade] = elemento;
    }
    fila->quantidade ++;
    heap(fila);
}

int desenfileirar(Fila* fila){
	Elemento elemento = fila->vetor[0];
	fila->vetor[0].ordem = fila->vetor[fila->quantidade-1].ordem + 1;
    heap(fila);
    fila->quantidade--;
    return elemento.valor;
}

Elemento criarElementoFila(int val, int ordem){
    Elemento novoElemento;
    novoElemento.valor = val;
    novoElemento.ordem = ordem;
    return novoElemento;
}

void heap(Fila* fila){
	int i;
	Elemento aux;
	for (i=(fila->quantidade-1)/2; i>=0; i--)
		criaheap(fila, i, fila->quantidade-1);
	for (i=fila->quantidade-1;i>=1;i--){
		aux=fila->vetor[0];
		fila->vetor[0]=fila->vetor[i];
		fila->vetor[i]=aux;
		criaheap(fila,0,i-1);
	}
}

void criaheap(Fila* fila, int inicio, int final){
	Elemento aux = fila->vetor[inicio];
	int filho = inicio * 2 + 1;
	while (filho <= final){
		if (filho < final && fila->vetor[filho].ordem < fila->vetor[filho + 1].ordem)
			filho += 1;
		if (aux.ordem < fila->vetor[filho].ordem){
			fila->vetor[inicio] = fila->vetor[filho];
			inicio = filho;
			filho = 2 * inicio + 1;
		}else
			filho = final + 1;
	}
	fila->vetor[inicio] = aux;
}

void mostrarProximo(Fila* fila){
    for(int i = 0; i < fila->quantidade; i++){
		printf("%d", fila->vetor[i].valor);
	}
}
