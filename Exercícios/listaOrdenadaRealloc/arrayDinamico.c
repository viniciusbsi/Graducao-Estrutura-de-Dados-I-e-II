#include "arrayDinamico.h"
#include <stdlib.h>
#include <stdio.h>

array* inicializar() {
	array* novoArray;
	novoArray = (array*) malloc(sizeof(array));
	novoArray->capacidade = 5;
	novoArray->quantidade = 0;
	novoArray->elementos = (vetor*) malloc(sizeof(vetor) * 5);
	return novoArray;	
}

void inserir(array* vetor, int codigo, float valor) {
	int pos = vetor->quantidade;
	if(vetor->quantidade < vetor->capacidade){
		while ( (vetor->elementos[pos-1].codigo > codigo) && (pos > 0) )
			vetor->elementos[pos] = vetor->elementos[--pos];
		vetor->elementos[pos].codigo = codigo;
		vetor->elementos[pos].valor = valor;
		vetor->quantidade++;
		printf("\n%d - %d\n", vetor->capacidade, vetor->quantidade);
	}
	else{
		printf("----Realocando espaço de memória----");
		realocar(vetor, 10);
	}
}

int buscaSequencial(array* vetor, int codigo) {
	int pos = 0;
   	while (pos < vetor->quantidade && vetor->elementos[pos].codigo < codigo) 
   		++pos;
   	return (vetor->elementos[pos].codigo == codigo)?pos:-1;
}

int buscaBinaria (array* vetor, int codigo) { 
   int p1 = -1, p2 = vetor->quantidade;
   while (p1 < p2-1) {  
      int meio = (p1 + p2)/2;
      if (vetor->elementos[meio].codigo < codigo) p1 = meio;
      else p2 = meio; 
   }
   return (vetor->elementos[p2].codigo == codigo)?p2:-1;
}

void removeElemento(array* vetor, int codigo){
	int i = 0;
    int controle = 0;
	while(i <= vetor->quantidade){
		if(codigo == vetor->elementos[i].codigo || controle == 1){
            vetor->elementos[i].codigo = vetor->elementos[i+1].codigo;
            vetor->elementos[i].valor = vetor->elementos[i+1].valor;
            controle = 1;
		}
        i++;
	}
    vetor->quantidade--;
    printf("Nova quantidade %d\n", vetor->quantidade);
}

vetor* realocar(array* estrutura, int quantidade){
	estrutura->elementos = (vetor*) realloc(estrutura->elementos, sizeof(vetor) * quantidade);
	estrutura->capacidade = estrutura->capacidade + quantidade;
    return(estrutura->elementos);
}
