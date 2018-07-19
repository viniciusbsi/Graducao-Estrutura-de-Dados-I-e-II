/*
 * Apresenta a soma dos n valores interios positivos 
 * O(n) onde n é a quantidade de vezes que o "for" é executado  */
#include<stdio.h>
int main(){
    int n, soma=0;
    printf("Informe o valor n: ");
    scanf("%d", &n);
    // i não é declarado no começo do programa pq só vai ser usado aqui, se fosse usado mais vezes, seria declarado no inicio por questões de desempenho;
    for (int i=0; i<=n; i++){
            soma+=i;
    }
    printf("A soma dos %d valores inteiros positivos é %d \n", n, soma);
}
