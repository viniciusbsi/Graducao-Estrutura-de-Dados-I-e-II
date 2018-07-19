#include <stdio.h>
#include <stdlib.h>
#include <time.h>
# include "insertsort.c"
#include "bubblesort.c"
#include "selectsort.c"
#include "quicksort.c"
#include "shellsort.c"
#include "prototipacoes.h" 

int main(){
	//Compara valor de trocas e comparações entre as função insert e bubblesort
	int v[9] = {5,3,8,2,9,1,11,0,4};
	int x[9] = {5,3,8,2,9,1,11,0,4};
	int y[9] = {5,3,8,2,9,1,11,0,4};
	int z[9] = {5,3,8,2,9,1,11,0,4};
	int a[9] = {5,3,8,2,9,1,11,0,4};

	printf("Função de Ordenação Bubblesort");
	ordena_vetor_crescente(9,v);
	for(int i = 0; i<9; i++){
		printf("%d, ", v[i]);
	}
	
	printf("\n\nFunção de Ordenação Insertsort");
	insertsort(9,x);
	for(int i = 0; i<9; i++){
		printf("%d, ", x[i]);
	}
	
	printf("\n\nFunção de Ordenação SelectSort");
	selectsortcrescente(9,y);
	for(int i = 0; i<9; i++){
		printf("%d, ", y[i]);
	}
	
	printf("\n\nFunção de Ordenação SelectSort Descrescente");
	selectsortdecrescente(9,z);
	for(int i = 0; i<9; i++){
		printf("%d, ", z[i]);
	}
	
	
	printf("\n\nFunção de Ordenação ShellSort\n");
	shellsort(a,9);
	for(int i = 0; i<9; i++){
		printf("%d, ", a[i]);
	}
	
	printf("\n\nFunção de Ordenação Quicksort\n");
	int q[9] = {5,3,8,2,9,1,11,0,4};
	int inicio = 0;
	int fim = 9;
	quicksort(q, inicio, fim);
	for(int i = 0; i<9; i++){
		printf("%d, ", q[i]);
	}
}
