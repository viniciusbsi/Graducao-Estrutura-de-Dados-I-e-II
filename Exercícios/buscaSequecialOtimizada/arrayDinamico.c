#include "arrayDinamico.h"
#include <stdlib.h>
#include <stdio.h>


array* inicializar() {
	array* novoArray;
    novoArray = (array*) malloc(sizeof(array));
	novoArray->capacidade = 10;
	novoArray->quantidade = 0;
	novoArray->elementos = (vetor*) malloc(sizeof(vetor) * 10);
	return novoArray;	
}

Inteiros* inicializarInteiros() {
	Inteiros* novoArray;
    novoArray = (Inteiros*) malloc(sizeof(Inteiros));
	novoArray->capacidade = 10;
	novoArray->quantidade = 0;
	novoArray->elementos = (vetorInteiros*) malloc(sizeof(vetorInteiros) * 10);
	return novoArray;	
}

void inserir(array* vetor, int codigo, float valor) {
	int pos = vetor->quantidade;
	while ( (vetor->elementos[pos-1].codigo > codigo) && (pos > 0) )
		vetor->elementos[pos] = vetor->elementos[--pos];
	vetor->elementos[pos].codigo = codigo;
	vetor->elementos[pos].valor = valor;
	vetor->quantidade++;
}

void inserirValores(Inteiros* array, int valor){
    array->elementos[array->quantidade].valor = valor;
    array->quantidade++;
}

int buscaSequencial(Inteiros* vetorInteiros, int valor){
    int i, posicao;
    posicao = -1;
    i = 0;
    while(i <= vetorInteiros->quantidade){
        if(vetorInteiros->elementos[i].valor == valor){
            posicao = i;
        }
        i++;
    }
    return posicao;
}

int buscaOtimizada(array* vetor, int codigo){
    int p1 = -1, p2 = vetor->quantidade;
    while(p1 < p2-1){
        int meio = (p1 + p2)/2;
        if (vetor->elementos[meio].codigo < codigo){
            p1 = meio;
        }
        else{
            p2 = meio;
        }
    }
    if(vetor->elementos[p2].codigo == codigo){
        return p2;
    } 
    else{
        return -1;
    }
}
