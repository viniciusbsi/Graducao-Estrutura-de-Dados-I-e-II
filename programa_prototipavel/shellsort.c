#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prototipacoes.h"


void shellsort(int vet[], int qtd){
	int i,j,h = 1;
	int qtd_trocas, qtd_comparacoes;
	qtd_trocas = 0;
	qtd_comparacoes = 0;
	int aux;
	do{h = h*3 + 1;}while(h < qtd);
	do{
		h = (h - 1) / 3;
		for(i = h; i < qtd; i ++){
			aux = vet[i];
			j = i;
			qtd_comparacoes++;
			//efetua as comparações entre os elementos com distância h
			while(vet[j - h] > aux){
				vet[j] = vet[j - h];
				j -= h;
				qtd_trocas++;
				if(j < h){
					break;
				}
			}
			vet[j] = aux;
		}
	}while(h > 0);
	printf("\ncomparacoes shell: %d", qtd_comparacoes);
	printf("\ntrocas shell: %d\n", qtd_trocas);
}
