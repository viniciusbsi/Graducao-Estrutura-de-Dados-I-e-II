
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void remove_elemento(int* v, int i, int n){
	int final = n;
	while(i < final-1){
		v[i+1] = v[i+2];
		i++;
	}
	v[final-1] = 0;
	return;
}

void ordena_vetor_crescente(int n, int* v){
	printf("na funcao\n");
	int fim, i;
	int qtd_comparacoes = 0;
	int qtd_trocas = 0;
	for(fim=n-1; fim>0;fim--){
		int houve_troca = 0;
		for(i=0;i<fim;i++){ /* Não precisaria ter a chave aqui, pois mesmo que tenha mais de uma linha o IF é considerado uma coisa só*/
			if(v[i]>v[i+1]){
				qtd_trocas++;
				int temp = v[i];
				v[i] = v[i+1];
				v[i+1] = temp;
				houve_troca = 1; /* se percorreu todo o vetor que houve troca, deve-se percorrer novamente para verificar se tem mais trocas para fazer*/
			}
			if(v[i] == v[i+1])
				remove_elemento(v, i, n);
			qtd_comparacoes++;
		}
		printf("comparacoes: %d\n", qtd_comparacoes);
		printf("trocas: %d\n", qtd_trocas);
		if(houve_troca == 0) return; /* se percorreu todo o vetor e não houve troca, então o vetor está ordenado; Uma função void pode usar a palavra "return" sem nada, 
		esse "return" serve para parar a função*/
	}
}

void ordena_vetor_descrescente(int n, int* v){
	int fim, i;
	int qtd_comparacoes = 0;
	int qtd_trocas = 0;
	for(fim=n-1; fim>0;fim--){
		int houve_troca = 0;
		for(i=0;i<fim;i++){ /* Não precisaria ter a chave aqui, pois mesmo que tenha mais de uma linha o IF é considerado uma coisa só*/
			printf("no for");
			if(v[i]<v[i+1]){
				qtd_trocas++; //quando houver troca de elementos, deve somar
				int temp = v[i];
				v[i] = v[i+1];
				v[i+1] = temp;
				houve_troca = 1; /* se percorreu todo o vetor que houve troca, deve-se percorrer novamente para verificar se tem mais trocas para fazer*/
			}
			if(v[i] == v[i+1])
				remove_elemento(v, i, n);
			qtd_comparacoes++; //conta as comparações feitas 
		}
		if(houve_troca == 0) return; /* se percorreu todo o vetor e não houve troca, então o vetor está ordenado; Uma função void pode usar a palavra "return" sem nada, 
		esse "return" serve para parar a função*/
	}
	printf("comparacoes: %d\n", qtd_comparacoes);
	printf("trocas: %d\n", qtd_trocas);
}

int main(){
	printf("Vetor crescente \n");
	
	//int cinquenta[50] = {50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	//int cem[100] = {100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	
	//Vetor de 50 elementos
	//time_t t_inicial, t_final;
	//t_inicial = time( NULL );
	//ordena_vetor_crescente(50, cinquenta); 
	//for(int i = 0; i<50; i++){
		//printf("%d, ", cinquenta[i]);
	//}
	//t_final = time( NULL );
	//printf("Tempo 50 = %f \n", difftime(t_final, t_inicial));

	//Vetor de 100 elementos
	//t_inicial = time( NULL );
	//ordena_vetor_crescente(100, cem); 
	//for(int i = 0; i<100; i++){
		//printf("%d, ", cem[i]);
	//}
	//t_final = time( NULL );
	//printf("Tempo 100 = %f \n", difftime(t_final, t_inicial));
	
	//Vetor para testar qtd de comparações e trocas
	//int x[5] = {1, 2, 4, 3, 5};
	//ordena_vetor_crescente(5, x);
	
	int x[5] = {2,3,3,5,4};
	ordena_vetor_crescente(5,x);
	for(int i = 0; i<5; i++){
		printf("%d, ", x[i]);
	}
}
