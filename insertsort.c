#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertsort(int tamanho, int* v){
    int i,j,pivo;
	for (i = 1; i < tamanho; i++){
		pivo = v[i];
		j = i-1;
		while (j>0 && v[j]>pivo){
		  v[j+1] = v[j];
		  j--;
		}
		v[j+1]=pivo;
	}
}

int main(){
	int v[9] = {5,3,8,2,9,1,11,0,4};
	insertsort(9,v);
	for(int i = 0; i<9; i++){
		printf("%d, ", v[i]);
	}
}
