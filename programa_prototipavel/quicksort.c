#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <time.h>
#include "prototipacoes.h"
#include "particiona.c"

void quicksort(int vet[], int inicio, int fim){ //não precisa usar "*" na inicialização da função, pq todo vetor já um ponteiro para um espaço na memória. 
	//mesmo que seja void, todas as alterações vão ser feitas no main, pq o vet é um ponteiro no vetor;
	int pivo;
	if (inicio < fim){
		pivo = particiona(vet, inicio, fim);
		quicksort(vet, inicio, pivo);
		quicksort(vet, pivo+1, fim);
	}
	else{
		return;
	}
	
}
