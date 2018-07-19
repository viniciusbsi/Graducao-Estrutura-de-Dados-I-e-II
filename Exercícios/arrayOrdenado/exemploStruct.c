#include<stdio.h>
#include<stdlib.h>

typedef struct ponto{
    int x;
    int y;
}ponto;

int main(){
    //com o '*', posicao vira um ponteiro
    //aqui é criado uma posição que é um ponteiro que vai apontar para um ponto
    ponto *posicao;
    
    //posicao tem um endereço de memória para um espaço de memória que cabe um ponto (armazena um x e y)
    posicao = (ponto*) malloc(sizeof(ponto));
    
    printf("Informe X e Y: ");
    scanf("%d", &posicao->x);
    scanf("%d", &posicao->y);
    printf("\nVocê informou x=%d e y=%d\n", posicao->x, posicao->y);
    //Ponteiro em C só é acessado com flecha
    
}
