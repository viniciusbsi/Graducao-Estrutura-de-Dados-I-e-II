#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prototipacoes.h"

void selectsortcrescente(int tamanho, int* v){
	int i, j, aux, min, qtd_trocas, qtd_comparacoes;
	qtd_trocas = 0;
	qtd_comparacoes = 0;
	for (i = 0; i < tamanho-1; i++){
		min = i; 
		for(j=i+1;j<tamanho;j++){ //percorre o vetor procurando o menor elemento 
			if(v[min]>v[j]){ // a cada elemento, verifica se o minimo já conhecido é maior que o elemento, se sim, o elemento tornas-se o mínimo
				min = j; // quando encontra o menor elemento, atribui a essa variavel
				qtd_trocas++;
			}
		}
		aux = v[i]; 
		v[i] = v[min];
		v[min] = aux;
		qtd_comparacoes++;
	}
	printf("\ncomparacoes insert: %d", qtd_comparacoes);
	printf("\ntrocas insert: %d\n", qtd_trocas);
	return;
}

void selectsortdecrescente(int tamanho, int* v){
	int i, j, aux, max, qtd_trocas, qtd_comparacoes;
	qtd_trocas = 0;
	qtd_comparacoes = 0;
	for (i = 0; i < tamanho-1; i++){
		max = i;
		for(j=i+1;j<tamanho;j++){
			if(v[max]<v[j]){
				max = j;
				qtd_trocas++;
			}
		}
		aux = v[i];
		v[i] = v[max];
		v[max] = aux;
		qtd_comparacoes++;
	}
	printf("\ncomparacoes insert: %d", qtd_comparacoes);
	printf("\ntrocas insert: %d\n", qtd_trocas);
	return;
}

