#include<stdio.h>
#include<stdlib.h>
#define tam 20

int main(){
	//o asterisco informa que o vetor vai ser um ponteiro para um endereço de memória do tipo inteira 
	int vetor[tam];

	for(int i=0; i<tam; vetor[i++]=i);
	for(int i=0; i<tam; i++){
		printf("\nPos %d: valor %d", i, vetor[i]);
	}
	printf("\nTamanho de um INT: %li\n", sizeof(int));
	printf("End de memória do ponteiro vetor: %p\n", vetor);
	printf("End de memória para onde ele está apontando: %p é o mesmo que o end para onde ele está apontando \n", vetor);
	printf("End de memória vetor na posição [0]: %p\n", &vetor[0]);
	printf("End de memória vetor na posição [2]: %p\n", &vetor[2]);
	printf("End de memória vetor na posição [4]: %p\n", &vetor[4]);
}
