/*
 * Apresenta a soma dos n valores interios positivos 
 * Esse código usa um só ciclo de CPU
 * O(1)*/
#include<stdio.h>
int main(){
    int n, soma=0;
    printf("Informe o valor n: ");
    scanf("%d", &n);
    // i não é declarado no começo do programa pq só vai ser usado aqui, se fosse usado mais vezes, seria declarado no inicio por questões de desempenho;
    soma = (n * (n+1))/2;
    printf("A soma dos %d valores inteiros positivos é %d \n", n, soma);
    return 0;
}
