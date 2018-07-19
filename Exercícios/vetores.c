#include<stdio.h>
#define TAM 100

int main(){
    
    int vetor[TAM], qtd, i;
    
    
    do {
        printf("Informe a quantidade de elementos: ");
        scanf("%d", &qtd);
    } while(qtd >= TAM);
    
    for (i=0; i<qtd; i++) {
        printf("Valor %d: ", i);
        scanf("%d", &vetor[i]);
    } 
    
    printf("Mostrando os valores lidos de trás pra frente\n");
    for (i=qtd-1; i>=0; i--) {
        printf("%d ", vetor[i]);
    }
    
    /*Se o vetor tiver 100 posições e mandar alterar o valor da posição 500 ele vai apresentar o que estiver dentro dela, o C não trata isso;*/
    
    printf("\nPosição 90: %d - %p", vetor[90], &vetor[90]);
    vetor[90] = 100;
       
    printf("\nPosição 112 %d - %p", vetor[112], &vetor[112]);
    vetor[112] = 42;
       
    printf("\n\n\nPosição 90: %d - %p", vetor[90], &vetor[90]);
    printf("\nPosição 112: %d - %p", vetor[112], &vetor[112]);
    
    printf("\nQTD %p\n", &qtd);
    printf("I %p\n", &i);
           
    printf("\n");   
    
}
    
