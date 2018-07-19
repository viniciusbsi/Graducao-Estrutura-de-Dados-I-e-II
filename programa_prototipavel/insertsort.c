#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prototipacoes.h"

void insertsort(int tamanho, int* v){
	int i,j,pivo, qtd_trocas, qtd_comparacoes;
	qtd_trocas = 0;
	qtd_comparacoes = 0;
	for (i = 0; i < tamanho; i++){
		pivo = v[i];
		j = i-1;
		while (j>=0 && v[j]>pivo){
			qtd_trocas++;
			v[j+1] = v[j];
			j--;
		}
		v[j+1]=pivo;
		qtd_comparacoes++;
	}
	printf("\ncomparacoes insert: %d", qtd_comparacoes);
	printf("\ntrocas insert: %d\n", qtd_trocas);
}

